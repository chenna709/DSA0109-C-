# Task 4 – Pointers to derived classes: forensics

## Defects
1. `rate()` is non-virtual, so calling through `Account*` uses static binding.
2. `Account` has a non-virtual destructor.
3. Copying `SeniorAccount` into `Account` slices the derived object.

## Repair
Make polymorphic operations virtual, use `override`, provide a virtual destructor, and use owning pointers.

Source: copied from [harshitha2942/dsa01-192473031-assignment4](https://github.com/harshitha2942/dsa01-192473031-assignment4).
