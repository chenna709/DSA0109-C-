# Task 03 – Choose Data Types and Check Type Compatibility

## Objective
Choose suitable C++ data types for fares, balances, times, zones, and journey counts.

## Data Type Selection

| Value | Recommended type | Reason |
|---|---|---|
| Fare and balance in paise | `long long` | Exact integer arithmetic and large totals |
| Zone number | `int` or `enum class Zone` | Represents a small set of zones |
| Hour | `int` | Represents values from 0 to 23 |
| Peak or weekend flag | `bool` | Represents true or false |
| Character | `char` | Stores a character |
| Journey count | `long long` | Supports large counts |
| Approximate measurements | `double` | Floating-point calculations when appropriate |

## Why Integer Paise?
One rupee equals 100 paise. Storing ₹10 as 1000 paise avoids binary floating-point representation errors during fare calculations.

## Type Compatibility
C++ may promote or convert values in mixed expressions. For example, an integer divided by an integer performs integer division, while converting one operand to `double` allows floating-point division.

## Range and Network Collection
Use `<climits>` to inspect limits such as `INT_MAX`. At 3,000,000 journeys, the count multiplied by a fare of ₹36.01 is ₹108,030,000, or 10,803,000,000 paise. This paise total exceeds the usual 32-bit signed `int` maximum of 2,147,483,647, so `long long` is appropriate.

## Complexity Analysis
An addition takes O(1) time for both integer and floating-point values. A typical `long long` and `double` each occupy 8 bytes on common systems, but their numeric behaviour differs.

## Evidence
Include `sizeof` and numeric-limit results from your own compiler, together with a precision or overflow comparison.
