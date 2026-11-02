# Task 08 – Read and Print Data Safely

## Objective
Design safe input and clear output for the metro gate program.

## Input Validation
The program should read zone, hour, balance, and other required values. If the user enters letters instead of a number, check `cin.fail()`, call `cin.clear()` to reset the stream state, and discard the invalid input using `cin.ignore()`.

## Output Formatting
Use `<iomanip>` tools such as `setw`, `setfill`, `fixed`, and `setprecision` to display money consistently.

## Alternative: getline and stoi
Using `std::getline()` reads an entire line, and `std::stoi()` converts the numeric text. Invalid conversions can be handled with `try`/`catch`. Processing a line of length L takes O(L) time and requires O(L) buffer space.

Direct formatted extraction with `cin >>` is convenient for simple input. Line-based input gives greater control over the complete input line, but requires explicit exception and validation handling.

## Evidence
Include actual screenshots demonstrating successful input, correctly formatted output, and recovery from invalid input where supported by the program.
