# C++ Module 06 – Type Conversion & Casting

This module introduces **C++ type casting** and the concept of **serialization**. It focuses on safely converting between types, manipulating low-level representations, and using polymorphism to detect types at runtime — all without relying on advanced libraries.

---

## 🧠 What I Learned

* How to detect and convert between **scalar types** (`char`, `int`, `float`, `double`)
* The use of **explicit casting** (`static_cast`, `reinterpret_cast`, etc.)
* How to **serialize and deserialize pointers** using `uintptr_t`
* Polymorphism and how to **identify derived types** without `typeid`
* Best practices for handling edge cases and undefined behavior

---

## 📦 Exercise 00: Scalar Conversion

**Goal**: Implement a class `ScalarConverter` with a static method `convert(std::string literal)` that:

* Detects the literal type (char, int, float, or double)
* Converts it to the other three scalar types
* Displays all four converted forms

### Concepts Practiced

* **Static classes** and **static methods**
* **Explicit casting** (`static_cast`, `reinterpret_cast`)
* Safe handling of special float/double values like `nan`, `+inf`, `-inf`
* Error handling for overflow, non-displayable characters, and impossible conversions

### Example Output

```shell
./convert 42.0f
char: '*'
int: 42
float: 42.0f
double: 42.0
```

### Edge Cases

* If a value cannot be converted, print `impossible`.
* Non-displayable characters: print `Non displayable`.

---

## 📦 Exercise 01: Serialization

**Goal**: Create a class `Serializer` with two static methods:

```cpp
uintptr_t serialize(Data* ptr);
Data* deserialize(uintptr_t raw);
```

### Concepts Practiced

* **Pointer manipulation**
* Using `uintptr_t` to safely convert between pointer and integer
* Data integrity: making sure the deserialized pointer matches the original
* No use of STL or external libraries

### Why It Matters

Serialization is the foundation of storing or transmitting object data. This exercise shows how you can **encode a memory address into an integer**, transmit or store it, and decode it back.

---

## 📦 Exercise 02: Identify Real Type

**Goal**: Write a class hierarchy with a base class `Base` and three derived classes `A`, `B`, and `C`. Then implement two functions:

```cpp
void identify(Base* p);
void identify(Base& p);
```

These functions print whether the object is of type A, B, or C — **without using `typeid`**.

### Concepts Practiced

* **Polymorphism** and **virtual destructors**
* **Dynamic casting** with `dynamic_cast`
* **Runtime type identification (RTTI)** without `typeinfo`
* Handling exceptions with `try/catch` for reference-based casting

### Example Output

```shell
A
B
C
```

Each call to `generate()` returns a randomly created derived object.
