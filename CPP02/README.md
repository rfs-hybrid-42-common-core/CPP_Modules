*This project has been created as part of the 42 curriculum by maaugust.*

<div align="center">
  <img src="https://raw.githubusercontent.com/rfs-hybrid/42-Common-Core/main/assets/covers/cover-cpp02.png" alt="CPP 02 Cover" width="100%" />
</div>

<div align="center">
  <h1>💻 CPP 02: Ad-Hoc Polymorphism</h1>
  <p><i>Ad-hoc polymorphism, operator overloading, and the Orthodox Canonical class form.</i></p>
  <img src="https://img.shields.io/badge/Language-C++98-blue" alt="Language badge" />
  <img src="https://img.shields.io/badge/Grade-100%2F100-success" alt="Grade badge" />
  <br />
</div>

---

## 💡 Description
**CPP 02** introduces the rigid architectural requirements that will govern the rest of the C++ curriculum: the **Orthodox Canonical Form**.

This module forces the implementation of safe, predictable class architectures by requiring explicit Default Constructors, Copy Constructors, Copy Assignment Operators, and Destructors for every single class. Conceptually, the module focuses on recreating **Fixed-Point Numbers** from scratch to bridge the gap between integer performance and floating-point precision. Finally, it extensively covers Ad-Hoc Polymorphism through **Operator Overloading**.

---

## 🧠 Exercise Breakdown & Logic

*The following section explains the core concepts required to solve each exercise, focusing on memory safety and mathematical operator overloads.*

### 🔹 Orthodox Canonical Form & Fixed-Point Math
| Exercise | Concept & Logic |
| :--- | :--- |
| **[`ex00: My First Class in Orthodox Canonical Form`](ex00)** | **The OCF Standard:** Creating a baseline Fixed-Point class adhering strictly to the Orthodox Canonical Form.<br><br>**Logic:** You must implement a default constructor, a copy constructor, a copy assignment operator, and a destructor. The class stores the raw value as an integer and uses a static constant integer (always 8) to define the number of fractional bits. This exercise proves that copying an object handles raw memory correctly. |
| **[`ex01: Towards a more useful fixed-point number class`](ex01)** | **Constructors & Stream Insertion:** Adding parameterized constructors and converting back to native scalar types.<br><br>**Logic:** Introduces constructors that accept `const int` and `const float`, using bitwise shifting and `roundf` to convert them into fixed-point representations. It also introduces the `<<` insertion operator overload, allowing the custom object to be printed directly via `std::cout`. |
| **[`ex02: Now we're talking`](ex02)** | **Operator Overloading & Polymorphism:** Implementing all mathematical/logical operators and function overloads to make the custom class behave like a native numeric type.<br><br>**Logic:** You must overload 6 comparison operators (`>`, `<`, `>=`, `<=`, `==`, `!=`), 4 arithmetic operators (`+`, `-`, `*`, `/`), and the 4 pre/post increment/decrement operators (`++`, `--`). It also introduces function overloading via static `min` and `max` methods. This is the true introduction to Ad-Hoc Polymorphism, allowing C++ to route operations to custom class methods depending on the object types involved. |

### 🔹 Advanced Algorithms
| Exercise | Concept & Logic |
| :--- | :--- |
| **[`ex03: BSP`](ex03)** | **Binary Space Partitioning:** Applying the newly created `Fixed` class to a geometric algorithm to verify if a point is inside a triangle.<br><br>**Logic:** You must create a `Point` class containing constant `Fixed` coordinates `x` and `y`, requiring the strict use of Member Initializer Lists for OCF compliance. The `bsp` function calculates the 2D cross products of the triangle's edges relative to the point to mathematically verify if it lies strictly inside the boundaries. |

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
* **[GeeksforGeeks: Orthodox Canonical Form (Rule of Three/Four)](https://www.geeksforgeeks.org/rule-of-three-in-cpp/)** - Understanding why the Copy Constructor, Assignment Operator, and Destructor are fundamentally linked to prevent memory corruption.
* **[cplusplus.com: Overloading Operators](https://cplusplus.com/doc/tutorial/templates/)** - A complete guide to the syntax required for overloading standard mathematical and logical operators in C++.
* **[Codecademy: Operator Overloading Cheatsheet](https://www.codecademy.com/learn/learn-advanced-c-plus-plus/modules/operator-overloading-in-c-plus-plus/cheatsheet)** - A quick and highly readable syntax reference for overloading arithmetic, relational, and stream operators.
* **[ChloeIsCoding: Fixed-Point Numbers & OCF](https://hackmd.io/@ChloeIsCoding/S1D-y80bll)** - An excellent, 42-specific breakdown of how to translate floating-point values into fixed-point bitwise representations while adhering to Orthodox Canonical Form.
* **[ChloeIsCoding: BSP Algorithm Explained](https://hackmd.io/@ChloeIsCoding/r19Mge-fll)** - A fantastic breakdown of the Binary Space Partitioning algorithm used for calculating if a 2D point lies within the boundaries of a triangle (essential for `ex03`).

### CodeLucky & Visual Tutorials
* **[C++ Constructors Explained: Default, Parameterized & Copy](https://www.youtube.com/watch?v=xSubxm9uFrA)** - A visual guide to understanding how constructors work, specifically detailing the Copy Constructor which is absolutely required for Orthodox Canonical Form.
* **[C++ Operator Overloading: Beginner's Guide](https://www.youtube.com/watch?v=MWMPzNIzBSo)** - A comprehensive video tutorial detailing the syntax for overloading mathematical (`+`, `-`), comparison (`==`, `<`), and stream insertion (`<<`) operators, which forms the core objective of `ex01` and `ex02`.

---

### 🤖 AI Usage Guidelines
* **Code:** No AI-generated code was used to solve these exercises. The Orthodox Canonical Class architecture, bitwise fixed-point conversion math, and BSP algorithm were developed manually to strictly adhere to the C++98 standard and curriculum rules.
* **Documentation:** AI tools were utilized to structure this `README.md`, extract the core logic for Operator Overloading, and translate the mathematical constraints into an educational portfolio format.
