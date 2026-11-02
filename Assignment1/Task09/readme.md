# Task 09 – Implement and Test the Fare Logic

## Objective
Test fare calculations, boundary conditions, invalid inputs, and journey totals.

## Required Test Cases
- Each zone during peak and off-peak hours
- Exactly 08:00, 10:00, 17:00, and 20:00
- A balance that leaves exactly ₹50
- Invalid zone
- Negative recharge
- Letters entered for the hour
- Five journeys with a manually calculated total

## Expected Five-Journey Total
For the journey sequence used in the earlier test program, the fares are ₹10, ₹24, ₹36, ₹10, and ₹24. The total is ₹104.

## Test Table
Record the expected and actual results from the executed program.

| Test | Expected result | Actual result |
|---|---|---|
| Zone 1 off-peak | ₹10 fare | Fill from execution |
| Zone 2 peak | ₹24 fare | Fill from execution |
| Zone 3 peak | ₹36 fare | Fill from execution |
| Exactly ₹50 remaining | Journey permitted | Fill from execution |
| Unknown zone | Reject input | Fill from execution |
| Invalid hour text | Handle invalid input | Fill from execution |

## Alternative Design
A table-driven test suite stores test inputs and expected results, then processes t tests in O(t) time. Its space depends on the number and size of stored test cases. Adding a boundary test becomes easier because a new test row can be added.

## Evidence
Include the actual test output screenshot and complete expected-versus-actual test table in the report.
