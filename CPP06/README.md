*This project has been created as part of the 42 curriculum by maaugust.*

<div align="center">
  <img src="https://raw.githubusercontent.com/rfs-hybrid/42-Common-Core/main/assets/covers/cover-cpp06.png" alt="CPP 06 Cover" width="100%" />
</div>

<div align="center">
  <h1>💻 CPP 06: C++ Casts</h1>
  <p><i>Static casts, dynamic casts, reinterpret casts, RTTI, and data serialization.</i></p>
  <img src="https://img.shields.io/badge/Language-C++98-blue" alt="Language badge" />
  <img src="https://img.shields.io/badge/Grade-100%2F100-success" alt="Grade badge" />
  <br />
</div>

---

## 💡 Description
The **CPP 06** module introduces C++ Type Casting. The primary goal of these modules is to introduce you to Object-Oriented Programming by transitioning away from C-style syntax. 

In C, casting is done via a single, blunt instrument: `(type)value`, which forcibly converts data without checking if the conversion is semantically valid or safe. C++ solves this by introducing specific, intention-revealing casting operators. This module requires parsing and converting scalar types, performing low-level memory serialization, and utilizing Run-Time Type Information (RTTI) to dynamically identify polymorphic objects. As always, the code strictly adheres to the **C++98 standard**.

---

## 🧠 Exercise Breakdown & Logic

*The following section explains the core concepts required to solve each exercise, focusing entirely on type safety and memory interpretation.*

### 🔹 Type Conversion & Memory Serialization
| Exercise | Concept & Logic |
| :--- | :--- |
| **[`ex00: Conversion of scalar types`](ex00)** | **`static_cast`:** Safe, compile-time scalar conversions.<br><br>**Logic:** You must write a purely static `ScalarConverter` class (hiding the Orthodox Canonical Form to prevent instantiation) containing a `convert` method that takes a string literal and outputs its value in `char`, `int`, `float`, and `double` formats. The core logic involves mathematically parsing the value and utilizing `static_cast` to safely convert it while strictly handling precision limits, overflows, and special pseudo-literals (e.g., `-inff`, `nan`). |
| **[`ex01: Serialization`](ex01)** | **`reinterpret_cast`:** Low-level memory bypass and data serialization.<br><br>**Logic:** Introduces a purely static `Serializer` class with methods to convert a pointer to a `Data` structure into the unsigned integer type `uintptr_t`, and to deserialize it back into a pointer. You must use `reinterpret_cast`, demonstrating how C++ can bypass standard type safety to explicitly reinterpret the raw bits of a memory address for binary serialization. |

### 🔹 Run-Time Type Information (RTTI)
| Exercise | Concept & Logic |
| :--- | :--- |
| **[`ex02: Identify real type`](ex02)** | **`dynamic_cast`:** Safe downcasting and polymorphic identification.<br><br>**Logic:** You must implement a `Base` class with a public virtual destructor and three empty classes (`A`, `B`, and `C`) that publicly inherit from it. Without using the `<typeinfo>` header, you must identify the true derived type at runtime using `dynamic_cast`. The logic contrasts pointer casting (which returns `NULL` on failure) against reference casting (which throws a `std::bad_cast` exception on failure), enforcing safe polymorphic downcasting. |

---

## 🛠️ Instructions

### 🧪 Compilation & Execution
Each directory contains its own `Makefile` containing the standard rules (`all`, `clean`, `fclean`, `re`).

All programs are strictly compiled with the C++98 standard and standard error flags. Note that `ex01` requires `<stdint.h>` for `uintptr_t` support: 
`c++ -Wall -Wextra -Werror -std=c++98`

1. **Navigate to the specific exercise directory:**
   ```bash
   cd ex00
   ```

2. **Compile the program:**
   Use the provided `Makefile` to compile the source code into an executable.
   ```bash
   make
   ```

3. **Run the executable:**
   ```bash
   ./<executable_name> <arguments>
   ```

4. **Clean up binary files:**
   ```bash
   make fclean
   ```

---

## 📚 Resources & References

### General C++ Documentation
* **[cplusplus.com: Type conversions](https://cplusplus.com/doc/tutorial/typecasting/)** - The definitive standard guide on the differences between standard C-style casts and the four explicit C++ casting operators.
* **[GeeksforGeeks: static_cast in C++](https://www.geeksforgeeks.org/static_cast-in-c-type-casting-operators/)** - A clear breakdown of compile-time casting and implicit conversions required for `ex00`.
* **[GeeksforGeeks: reinterpret_cast in C++](https://www.geeksforgeeks.org/reinterpret_cast-in-c-type-casting-operators/)** - Explains the raw, bit-level memory reinterpretation required for serialization in `ex01`.
* **[GeeksforGeeks: dynamic_cast in C++](https://www.geeksforgeeks.org/cpp/dynamic-_cast-in-cpp/)** - Crucial reading for `ex02`. Explains how RTTI is used to safely downcast polymorphic base pointers, and the difference between failing on a pointer vs. a reference.

### CodeLucky & Visual Tutorials
* **[C++ Type Conversion: Implicit vs Explicit Casting](https://www.youtube.com/watch?v=9QAC7CBvw4s)** - A conceptual breakdown of when to use which cast, and why C-style casting is discouraged in modern C++.
* **[C++ Data Types Explained for Beginners](https://www.youtube.com/watch?v=m6_WOnnk730)** - A comprehensive guide to the limits and behaviors of the scalar data types parsed in `ex00`.
* **[C++ Math Functions for Beginners: cmath Library](https://www.youtube.com/watch?v=-FhTS9gt2o0)** - Essential for handling mathematical limits, pseudo-literals (`nan`, `inf`), and parsing edge cases in `ex00`.
* **[C++ Output for Beginners: Mastering cout & Stream Formatting](https://www.youtube.com/watch?v=RxNkYJZTY0E)** - Useful for correctly formatting the exact `float` and `double` decimal outputs required by the `ex00` subject.
* **[C++ Random Numbers: Modern Generation Techniques](https://www.youtube.com/watch?v=AKYcfRf-GNk)** - Bonus resource covering modern pseudo-random number generation patterns in C++.

---

### 🤖 AI Usage Guidelines
* **Code:** No AI-generated code was used to solve these exercises. All parsing trees, memory reinterpretations, and polymorphic downcasting `try/catch` blocks were constructed manually to ensure strict compliance with C++98 typing rules.
* **Documentation:** AI tools were utilized to structure this `README.md`, extract the core logic for the distinct casting operators, and translate the strict architectural requirements into an educational portfolio format.
