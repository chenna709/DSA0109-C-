# Task 2 – From requirement to hierarchy

## Relationships
- `Student is-a Person`: public, single inheritance.
- `Staff is-a Person`: public, single inheritance.
- `TeachingAssistant is-a Student` and `is-a Staff`: public multiple inheritance.
- `ResearchScholar is-a Student`: public multilevel inheritance.

## Diamond problem
Virtual inheritance makes the shared `Person` base construct once.

Source: copied from [harshitha2942/dsa01-192473031-assignment4](https://github.com/harshitha2942/dsa01-192473031-assignment4).
