# Task 04 – Control Implicit Conversions

## Objective
Identify implicit conversions in C++ and explain their effects on program output.

## Concepts
- Integer division
- Integer-to-double conversion
- Character-to-integer promotion
- Integer-to-Boolean conversion
- Signed-to-unsigned conversion
- Narrowing conversions
- `static_cast`

## Predicted Output

```text
3 3.5
C 68
1 true
s >= u
```

## Explanation
1. `a / b` performs integer division, producing 3 before conversion to `double`. Explicitly converting `a` to `double` produces 3.5.
2. `'A' + 2` produces the character `C`. When `ch` is added to 1, the character is promoted to an integer, producing 68.
3. The integer 5 converts to `true`. Boolean output is initially `1`; `std::boolalpha` changes it to `true`.
4. The negative signed integer `-1` is converted to an unsigned value for comparison with `u`, so the comparison `s < u` is false.

## Safer Conversions
Use `static_cast` when a conversion should be explicit. Brace initialisation, such as `int x{3.7};`, rejects narrowing conversions at compile time.

## Complexity Analysis
Explicit casts generally do not change the algorithm's time or memory requirements. They make conversion intent clearer, while brace initialisation catches certain mistakes at compile time.

## Evidence
Include your prediction made before execution, the actual output screenshot, and explanations of all conversion points.
