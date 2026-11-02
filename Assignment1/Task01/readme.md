# Task 01 – Understand the Problem and Identify the Objects

## Objective
Analyse the Namma Metro Smart-Card Fare System using object-oriented concepts.

## Objects and Responsibilities
- **Passenger:** Represents the person travelling and may contain passenger category information for concessions.
- **SmartCard:** Stores the card balance and supports recharge, balance checking, and fare deduction.
- **Journey:** Represents a journey, including its zone and travel time.
- **Zone:** Represents Inner, Middle, or Outer and determines the applicable base fare.
- **FareTable:** Stores the base fares and provides fare information.

## Object-Oriented Principles
- **Encapsulation:** Keep the card balance private and modify it through validated methods.
- **Abstraction:** Expose operations such as `canTravel()` and `deduct()` without exposing internal calculations.
- **Inheritance:** Student and senior-citizen passenger types could inherit common passenger properties from a base class.
- **Polymorphism:** Different passenger categories could implement different concession calculations through a common interface.

## Procedural vs Object-Oriented Design
A procedural design uses variables and free functions for fare calculation and balance updates. An object-oriented design groups related data and behaviour into classes, improving organisation and maintainability.

## Journey Rules
- A valid journey must use a supported zone and valid travel time.
- The fare must be calculated using the applicable base fare and surcharge.
- The balance must not become negative.
- At least ₹50 must remain after the fare is deducted.
- Concessions must be applied according to the defined passenger rules.

## Complexity Analysis
For a fixed number of zones, fare calculation and card validation take O(1) time per journey. Card balance storage takes O(1) space in either procedural or object-oriented design. Changing a rule may require updates in several procedural functions, whereas a well-separated class design can localise the change.

## Evidence
Include the required object analysis, UML diagram, assumptions, and relevant source-code or execution evidence in the assignment report.
