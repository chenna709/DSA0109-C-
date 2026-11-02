# Task 10 – Compare Expectations with Execution

## Objective
Compare floating-point and integer-paise totals as the number of journeys increases.

## Experiment
The program repeatedly adds a fare of ₹36.01 for:
- 20,000 journeys
- 500,000 journeys
- 3,000,000 journeys

It compares repeated `double` additions with exact integer-paise totals.

## Reference Calculations

| Journeys | Exact total | Integer-paise total |
|---:|---:|---:|
| 20,000 | ₹720,200.00 | 72,020,000 paise |
| 500,000 | ₹18,005,000.00 | 1,800,500,000 paise |
| 3,000,000 | ₹108,030,000.00 | 10,803,000,000 paise |

Repeated floating-point addition can produce small differences from the exact total. Record the actual differences printed by your program.

## Integer Overflow
A typical 32-bit signed `int` has a maximum value of 2,147,483,647. The three-million-journey total in paise exceeds that limit, so `int` is unsuitable for the network-wide total.

## Complexity Analysis
Each addition is O(1). A typical `int` occupies 4 bytes, while `long long` and `double` commonly occupy 8 bytes. Integer overflow and floating-point precision loss are different problems and must be handled separately.

## Compiler Warnings
Record the actual warnings produced by `-Wall -Wextra`. Explain each warning that appears; do not report warnings that your compiler did not produce.

## Evidence
Include the executed output screenshot and a comparison of expected and observed totals.
