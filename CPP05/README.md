*This project has been created as part of the 42 curriculum by maaugust.*

<div align="center">
  <img src="https://raw.githubusercontent.com/rfs-hybrid/42-Common-Core/main/assets/covers/cover-cpp05.png" alt="CPP 05 Cover" width="100%" />
</div>

<div align="center">
  <h1>💻 CPP 05: Repetition and Exceptions</h1>
  <p><i>Exception handling, nested exception classes, state validation, and the Factory design pattern.</i></p>
  <img src="https://img.shields.io/badge/Language-C++98-blue" alt="Language badge" />
  <img src="https://img.shields.io/badge/Grade-100%2F100-success" alt="Grade badge" />
  <br />
</div>

---

## 💡 Description
**CPP 05** introduces a fundamental shift in control flow: **Exception Handling**. 

Moving away from the C-style defensive programming of constantly checking return values (e.g., `if (func() == -1)`), this module explores the `try`, `catch`, and `throw` paradigm. It requires building robust object architectures that throw custom, nested exceptions whenever an invalid state is attempted. The latter half of the module builds upon the polymorphic interfaces from CPP 04, culminating in the implementation of the **Factory Design Pattern** to dynamically instantiate objects at runtime based on string inputs. As always, the code strictly adheres to the **C++98 standard**.

---

## 🧠 Exercise Breakdown & Logic

*The following section explains the core concepts required to solve each exercise, focusing entirely on exception safety and dynamic instantiation.*

### 🔹 Exceptions & State Validation
| Exercise | Concept & Logic |
| :--- | :--- |
| **[`ex00: Mommy, when I grow up, I want to be a bureaucrat!`](ex00)** | **Custom Exceptions:** Implementing classes that inherit from `std::exception`.<br><br>**Logic:** You create a `Bureaucrat` class with strict grade limits (1 to 150). The core logic involves nesting custom exception classes (`GradeTooHighException`, `GradeTooLowException`) inside the main class. If instantiation or increment/decrement operations push the grade out of bounds, the object safely `throws` the custom exception, halting the invalid state change. |
| **[`ex01: Form up, maggots!`](ex01)** | **Inter-Class Exceptions:** Handling exceptions passed between interacting objects.<br><br>**Logic:** Introduces a `Form` class with immutable grade requirements for signing. The logic focuses on cross-class validation: when a Bureaucrat attempts to sign a Form, the Form compares grades and throws an exception if the Bureaucrat is unqualified. The Bureaucrat must safely `catch` this exception and print a formatted rejection message. |

### 🔹 Abstract Execution & The Factory Pattern
| Exercise | Concept & Logic |
| :--- | :--- |
| **[`ex02: No, you need form 28B, not 28C...`](ex02)** | **The Template Method Pattern:** Executing abstract actions under strict state constraints.<br><br>**Logic:** The base `Form` is converted into an Abstract Base Class (`AForm`), branching into three concrete implementations (handling File I/O, randomness, and console output). It enforces the **Template Method Pattern**—the base class handles security checks (signatures and grade limits) before delegating the specific execution behavior to the derived classes. Attempting to bypass these rules throws specific state-violation exceptions. |
| **[`ex03: At least this beats coffee-making`](ex03)** | **The Factory Pattern:** Dynamically instantiating objects without complex `if/else` logic.<br><br>**Logic:** You must create an `Intern` class capable of generating any of the three concrete forms using only a string identifier. Since massive `if/else` or `switch` chains are explicitly forbidden, the logic requires implementing the **Factory Pattern**—often achieved by mapping strings to an array of pointers-to-member-functions to cleanly route the instantiation request. |

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
* **[cplusplus.com: Exceptions](https://cplusplus.com/doc/tutorial/exceptions/)** - The definitive standard guide on the syntax and mechanics of `try`, `catch`, and `throw`.
* **[GeeksforGeeks: Exception Handling in C++](https://www.geeksforgeeks.org/exception-handling-c/)** - A clear breakdown of how exceptions interrupt execution flow and safely unwind the stack.
* **[GeeksforGeeks: Factory Method Design Pattern](https://www.geeksforgeeks.org/system-design/factory-method-for-designing-pattern/)** - Essential reading for solving `ex03` cleanly without violating the forbidden `if/else` constraints.
* **[TutorialsPoint: C++ Exception Handling](https://www.tutorialspoint.com/cplusplus/cpp_exceptions_handling.htm)** - A straightforward, practical guide to throwing, catching, and creating custom standard exceptions.
* **[TutorialsPoint: C++ Factory Method](https://www.tutorialspoint.com/cplusplus/cpp_factory_method_design_pattern.htm)** - A step-by-step breakdown of how to structure the Factory pattern to dynamically instantiate objects based on input.
* **[Codecademy: Error Handling in C++ Cheatsheet](https://www.codecademy.com/learn/learn-advanced-c-plus-plus/modules/error-handling-in-c-plus-plus/cheatsheet)** - A quick, highly readable syntax reference for C++ `try`/`catch` blocks and exception inheritance.

### CodeLucky & Visual Tutorials
* **[C++ Exception Handling: Try, Catch, and Throw for Beginners!](https://www.youtube.com/watch?v=vP8ERWZEpGA)** - A visual guide to understanding how exceptions provide a safer alternative to C-style error checking.
* **[C++ Custom Exceptions: Inheriting from std::exception](https://www.youtube.com/watch?v=fq-ibN49bXI)** - Demonstrates exactly how to nest and override the `.what()` method for `ex00` and `ex01`.
* **[C++ Polymorphism: Virtual Functions & Runtime Method Selection](https://www.youtube.com/watch?v=K7l8T55fnXM)** - A crucial recap on dynamic dispatch and virtual functions, essential for handling the polymorphic form execution and the Factory Pattern generation in `ex02` and `ex03`.

---

### 🤖 AI Usage Guidelines
* **Code:** No AI-generated code was used to solve these exercises. All nested exception classes, polymorphic execution flows, and Factory Pattern arrays were built manually to guarantee a deep technical understanding of C++ error handling.
* **Documentation:** AI tools were utilized to structure this `README.md`, extract the core logic for custom exceptions and cross-class validation, and translate the architectural requirements into an educational portfolio format.
