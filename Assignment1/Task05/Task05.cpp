
#include <iostream>

int main()
{
    int x = 5, y = 3;

    // 1. Operator precedence: multiplication before addition
    std::cout << x + y * 2 << ' ' << (x + y) * 2 << '\n';

    // 2. Post-increment and pre-increment
    int z = x++ + ++y;
    std::cout << z << ' ' << x << ' ' << y << '\n';

    // 3. Conditional operator and remainder
    std::cout << (x > y ? x : y) << ' '
              << x % 4 * 2 << '\n';

    // 4. Division and remainder with positive and negative numbers
    std::cout << 10 / 3 << ' '
              << 10 % 3 << ' '
              << -10 / 3 << ' '
              << -10 % 3 << '\n';

    // 5. Compound assignment and for loop
    int k = 0;

    for (int i = 0; i < 10; i += 3)
    {
        k += i;
    }

    std::cout << k << '\n';

    return 0;
}
