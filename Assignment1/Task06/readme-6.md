# Task 06 – Design the Control Structures

## Objective
Implement fare computation and journey validation using appropriate C++ control structures.

## Pseudocode

```text
BEGIN
    READ zone, hour, balance
    VALIDATE zone and hour
    SELECT base fare using zone
    DETERMINE whether the hour is peak
    IF peak
        ADD 20 percent surcharge
    END IF
    IF balance minus fare is at least 5000 paise
        DEDUCT fare
        DISPLAY fare and remaining balance
    ELSE
        DISPLAY journey denied
    END IF
END
```

## Control Structures
- `switch` selects the base fare according to zone.
- `if-else` validates inputs and checks the remaining balance.
- `for` is appropriate when processing a known collection of journeys.
- A range-based `for` loop is suitable for iterating through an array of trips.
- A `while` loop is useful when journeys continue until a sentinel value or end-of-input.
- `continue` can skip an invalid journey, while `break` can exit a loop when required.
- A `switch` without a matching case executes `default`, if present.

## Completed Code
The completed program should use integer paise and apply the 20% surcharge with integer arithmetic.

## Expected Output

```text
Fare Rs 10.00 balance Rs 90
Fare Rs 36.00 balance Rs 54
Denied (low balance) balance Rs 54
```

## Boundary Testing
Test exactly 08:00, 10:00, 17:00, and 20:00. The first and third times are peak; the second and fourth are off-peak.

## Alternative Design
A fare array indexed by zone provides O(1) lookup. Adding a fourth zone requires extending the array and zone representation. A switch also takes O(1) for a fixed set of cases, but its branches must be updated when new zones are added.

## Evidence
Include the completed source code, pseudocode, and actual output screenshot.
