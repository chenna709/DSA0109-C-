# Task 02 – Tokens, Keywords, Identifiers and Constants

## Objective
Use C++ tokens and constants correctly so that fare revisions can be made in one place.

## Five Types of Tokens
- **Keywords:** `int`, `class`, `if`, `switch`, `return`
- **Identifiers:** `SmartCard`, `balance`, `fare`
- **Constants:** `1000`, `2000`, `3000`, `20`
- **Operators:** `+`, `-`, `*`, `/`, `==`
- **Punctuators:** `;`, `{}`, `()`, `[]`

## Constants
- `#define` creates a preprocessor macro and does not provide normal C++ type checking.
- `const` declares an object that cannot be modified through that name.
- `constexpr` allows values to be evaluated at compile time when the expression permits it.

`constexpr` is appropriate for fixed base fares and surcharge percentages because it supports type checking and compile-time evaluation.

## Zones
An `enum class` can represent Inner, Middle, and Outer zones. It is safer than an ordinary enumeration because its enumerators are scoped and do not implicitly convert to integers.

## Naming Conventions
Use meaningful names such as `BASE_PAISE`, `MIN_BALANCE_PAISE`, and `peakHour`. Use consistent naming and avoid unclear identifiers.

## Complexity Analysis
Replacing macros with typed constants generally does not change the running time or require meaningful extra storage for compile-time values. Typed constants and `enum class` provide better scope and type safety.

## Evidence
Include the code demonstrating tokens, constants, and zone declarations, together with the actual program output.
