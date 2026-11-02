 Task 07 – From Procedural to Object-Oriented Programming

## Objective
Implement and compare procedural and object-oriented versions of the fare logic.

## Procedural Version
Uses separate variables and free functions to calculate fares, check balances, and deduct money.

## Object-Oriented Version
Uses a `SmartCard` class that keeps its balance private and provides methods such as `deduct()` and `canTravel()`.

## Encapsulation
A private balance prevents unrelated code from modifying the card balance directly. Validated methods ensure that a journey is rejected when the minimum required balance would not remain.

## Design Comparison
Both versions can perform a journey in O(1) time and use O(1) space per card. A public balance member would use similar time and memory, but any part of the program could modify it and break the balance rules.

When the minimum balance changes, a well-designed class can centralise the validation rule, reducing the number of places that require modification.

## Program Files
- `Task07.cpp` – procedural version
- `Task072.cpp` – object-oriented version

## Evidence
Include actual output screenshots for both versions and a comparison of their design and maintainability.
