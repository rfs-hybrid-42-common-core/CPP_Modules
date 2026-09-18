*This project has been created as part of the 42 curriculum by maaugust.*

<div align="center">
  <img src="https://raw.githubusercontent.com/rfs-hybrid/42-Common-Core/main/assets/covers/cover-cpp07.png" alt="CPP 07 Cover" width="100%" />
</div>

<div align="center">
  <h1>💻 CPP 07: C++ Templates</h1>
  <p><i>Generic programming, function templates, class templates, and type-agnostic architecture.</i></p>
  <img src="https://img.shields.io/badge/Language-C++98-blue" alt="Language badge" />
  <img src="https://img.shields.io/badge/Grade-100%2F100-success" alt="Grade badge" />
  <br />
</div>

---

## 💡 Description
The **CPP 07** module introduces C++ templates. The primary goal of these modules is to transition from rigid, tightly-coupled data types to **Generic Programming**. 

Instead of writing separate functions or classes for `int`, `float`, and `std::string`, templates allow you to write a single, type-safe blueprint that the compiler dynamically resolves at compile time. This module requires building generic swapping functions, an array iterator capable of accepting function pointers, and a fully memory-managed, type-agnostic `Array` class. As always, the code complies strictly with the **C++98 standard**, and external containers like the STL `<vector>` remain forbidden.

---

## 🧠 Exercise Breakdown & Logic

*The following section explains the core concepts required to solve each exercise, focusing entirely on generic programming mechanics.*

### 🔹 Generic Functions & Iteration
| Exercise | Concept & Logic |
| :--- | :--- |
| **[`ex00: Start with a few functions`](ex00)** | **Function Templates:** Writing type-agnostic logic.<br><br>**Logic:** You must implement three function templates: `swap`, `min`, and `max`. The core requirement is that these functions can be called with any type of argument, provided both arguments share the same type and support all necessary comparison operators. These templates must be strictly defined in the header files. |
| **[`ex01: Iter`](ex01)** | **Template Iteration & Function Pointers:** Applying generic actions to generic arrays.<br><br>**Logic:** You must implement a function template `iter` that takes three parameters: the address of an array, its length, and a function to be called on every element. The logic challenges you to properly support both `const` and non-`const` elements when mapping the third parameter's function across the array. |

### 🔹 Generic Data Structures
| Exercise | Concept & Logic |
| :--- | :--- |
| **[`ex02: Array`](ex02)** | **Class Templates & Memory Management:** Building a generic, bounds-checked data structure.<br><br>**Logic:** You must develop a class template `Array` containing elements of an arbitrary type `T`. Because the compiler requires the full implementation to generate generic classes, the implementation is organized into a `.tpp` file. The class enforces strict memory management rules: you must use the `new[]` operator for allocation, preventive allocation is forbidden, and modifying a copied array must not affect the original. Finally, elements are accessed via the `operator[]`, which must actively throw a `std::exception` if the requested index is out of bounds. |

---

## 🛠️ Instructions

### 🧪 Compilation & Execution
Each directory contains its own `Makefile` containing the standard rules (`all`, `clean`, `fclean`, `re`).

All programs are strictly compiled with the C++98 standard and standard error flags: 
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
   ./<executable_name>
   ```

4. **Clean up binary files:**
   ```bash
   make fclean
   ```

---

## 📚 Resources & References

### General C++ Documentation
* **[cplusplus.com: Templates](https://cplusplus.com/doc/tutorial/templates/)** - The definitive standard guide covering both function templates and class templates.
* **[GeeksforGeeks: Templates in C++](https://www.geeksforgeeks.org/templates-cpp/)** - A clear, beginner-friendly breakdown of template syntax and instantiation.
* **[LearnCpp: Function Templates](https://www.learncpp.com/cpp-tutorial/function-templates/)** - Excellent resource for understanding how the compiler generates discrete functions from a single template blueprint, essential for `ex00` and `ex01`.
* **[LearnCpp: Class Templates](https://www.learncpp.com/cpp-tutorial/class-templates/)** - Detailed guide on managing memory and organizing header files for templated classes, critical for `ex02`.
* **[TutorialsPoint: C++ Templates](https://www.tutorialspoint.com/cplusplus/cpp_templates.htm)** - A straightforward, practical guide explaining both function and class templates alongside concrete code examples.

### CodeLucky & Visual Tutorials
* **[C++ Templates: Master Generic Programming for Beginners](https://www.youtube.com/watch?v=AELTWRGYUpY)** - A visual guide to decoupling logic from data types and building generic functions and classes, forming the core requirement of this entire module.
* **[C++ Operator Overloading: Beginner's Guide](https://www.youtube.com/watch?v=MWMPzNIzBSo)** - A crucial recap from previous modules, as the template functions in `ex00` enforce strict requirements on underlying operator support (like `>`, `<`, etc.).
* **[C++ Exception Handling: Try, Catch, and Throw for Beginners!](https://www.youtube.com/watch?v=vP8ERWZEpGA)** - Highly relevant for `ex02`, where accessing the `Array` class out of bounds must safely throw a `std::exception`.
* **[C++ Dynamic Memory Allocation (new & delete)](https://www.youtube.com/watch?v=qNDpTSE-mm4)** - Essential for the `Array` data structure in `ex02`, detailing exactly how to safely allocate and free contiguous arrays using `new[]` and `delete[]`.

---

### 🤖 AI Usage Guidelines
* **Code:** No AI-generated code was used to solve these exercises. All template blueprints, pointer iterations, and bounds-checked exception mechanisms were constructed manually to ensure strict compliance with C++98 generic programming rules.
* **Documentation:** AI tools were utilized to structure this `README.md`, extract the core logic for the distinct generic operators, and translate the strict architectural requirements into an educational portfolio format.
