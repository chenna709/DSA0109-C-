# Task 05 – Write Correct Expressions with the Right Precedence

## Objective
Evaluate C++ operator precedence and associativity in fare calculations and general expressions.

## Fare Expressions
Peak-hour condition:

```cpp
(hour >= 8 && hour < 10) ||
(hour >= 17 && hour < 20)
```

Peak surcharge:

```cpp
fare = fare + fare * PEAK_SURCHARGE_PERCENT / 100;
```

A concession expression should apply the specified passenger discount using the appropriate integer-paise calculation.

## Predicted Output

```text
11 16
9 6 4
6 4
3 1 -3 -1
18
```

## Concepts
- Arithmetic and relational operators
- Logical `&&` and `||`
- Conditional operator `?:`
- Prefix and postfix increment
- Compound assignment
- Integer division and remainder

The peak expression includes 8:00 but excludes 10:00, and includes 17:00 but excludes 20:00. Parentheses make the intended grouping easy to understand.

`x++` returns the old value before incrementing, while `++x` increments before producing its value. Avoid expressions such as `i = i++`, which have undefined behaviour in modern C++.

For integer division, `10 / 3` gives 3 and `10 % 3` gives 1. Negative division truncates toward zero, so `-10 / 3` gives -3 and `-10 % 3` gives -1.

## Alternative Design
A 24-element Boolean lookup table can store whether each hour is a peak hour. Lookup is O(1), just like the logical expression, but requires space for 24 Boolean elements.

## Evidence
Include the pre-execution prediction, actual output, and an operator-by-operator explanation in the report.
