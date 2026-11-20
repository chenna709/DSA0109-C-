#include <chrono>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
using namespace std;

struct Time {
    int h, m, s;
    Time(int hh = 0, int mm = 0, int ss = 0) : h(hh), m(mm), s(ss) { normalize(); }

    void normalize() {
        int total = h * 3600 + m * 60 + s;
        if (total < 0) total = 0;
        h = total / 3600; m = (total / 60) % 60; s = total % 60;
    }
    Time& operator++() { ++s; normalize(); return *this; } // prefix
    Time operator++(int) { Time old = *this; ++(*this); return old; } // postfix
    bool operator==(const Time& t) const { return h == t.h && m == t.m && s == t.s; }
    bool operator<(const Time& t) const {
        return h * 3600 + m * 60 + s < t.h * 3600 + t.m * 60 + t.s;
    }
    friend ostream& operator<<(ostream& out, const Time& t) {
        return out << t.h << ':' << (t.m < 10 ? "0" : "") << t.m
                   << ':' << (t.s < 10 ? "0" : "") << t.s;
    }
};

class Playlist {
    vector<string> tracks;
public:
    Playlist(initializer_list<string> names) : tracks(names) {}
    string& operator[](int i) {
        if (i < 0 || i >= static_cast<int>(tracks.size()))
            throw out_of_range("playlist index out of range");
        return tracks[static_cast<size_t>(i)];
    }
    const string& operator[](int i) const {
        if (i < 0 || i >= static_cast<int>(tracks.size()))
            throw out_of_range("playlist index out of range");
        return tracks[static_cast<size_t>(i)];
    }
    int size() const { return static_cast<int>(tracks.size()); }
};

int main() {
    Time t(0, 59, 59);
    Time a = t++;
    Time b = ++t;
    cout << "a=" << a << " b=" << b << " t=" << t << '\n';

    Time rollover(0, 59, 59);
    ++rollover;
    cout << "Rollover: " << rollover << '\n';

    Playlist playlist{"Track One", "Track Two", "Track Three"};
    cout << "Now playing: " << playlist[0] << '\n';
    const Playlist& readOnly = playlist;
    cout << "Next track: " << readOnly[1] << '\n';
    for (int index : {-1, 3}) {
        try { cout << playlist[index] << '\n'; }
        catch (const out_of_range& e) { cout << "Range error: " << e.what() << '\n'; }
    }

    // A simple timing loop; compare builds made with -O0 and -O2.
    volatile int sink = 0;
    constexpr int N = 10000000;
    auto start = chrono::steady_clock::now();
    Time prefix;
    for (int i = 0; i < N; ++i) { ++prefix; sink += prefix.s; }
    auto middle = chrono::steady_clock::now();
    Time postfix;
    for (int i = 0; i < N; ++i) { postfix++; sink += postfix.s; }
    auto finish = chrono::steady_clock::now();
    cout << "Prefix ns: " << chrono::duration_cast<chrono::nanoseconds>(middle-start).count()
         << ", postfix ns: " << chrono::duration_cast<chrono::nanoseconds>(finish-middle).count()
         << " (machine-dependent; sink=" << sink << ")\n";
}
