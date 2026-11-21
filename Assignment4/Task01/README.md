# Task 1 – Class design review

## Diagnosis of the supplied design
1. `name`, `id` and basic pay are duplicated.
2. Data members are public, so invalid values can be written without validation.
3. The same concepts use inconsistent names (`name`/`nm`, `id`/`code`).
4. `da` is declared but never used.
5. `0.42` is a magic number with no named policy.
6. Adding a staff type requires another unrelated class and more caller-side branching.
7. Different classes cannot be handled uniformly in one polymorphic loop.

## Repaired design
`Staff` is an abstract base class holding common identity. Each derived class overrides `pay()` and `role()`. Payroll stores owning `unique_ptr<Staff>` values and calls virtual functions.

```text
               Staff (abstract)
               /      |       \
        Professor  LabAssistant  GuestFaculty
```

Source: copied from [harshitha2942/dsa01-192473031-assignment4](https://github.com/harshitha2942/dsa01-192473031-assignment4).
