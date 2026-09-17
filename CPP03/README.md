*This project has been created as part of the 42 curriculum by maaugust.*

<div align="center">
  <img src="https://raw.githubusercontent.com/rfs-hybrid/42-Common-Core/main/assets/covers/cover-cpp03.png" alt="CPP 03 Cover" width="100%" />
</div>

<div align="center">
  <h1>💻 CPP 03: Inheritance</h1>
  <p><i>Subtyping polymorphism, access modifiers, constructor chaining, and the diamond problem.</i></p>
  <img src="https://img.shields.io/badge/Language-C++98-blue" alt="Language badge" />
  <img src="https://img.shields.io/badge/Grade-100%2F100-success" alt="Grade badge" />
  <br />
</div>

---

## 💡 Description
**CPP 03** introduces the cornerstone of Object-Oriented Programming: **Inheritance**. 

This module demonstrates how to create hierarchical class relationships to share and override logic. It focuses heavily on access modifiers (`private` vs. `protected`), ensuring derived classes can access base data without breaking encapsulation. It also explores the precise lifecycle of inherited objects (constructor and destructor chaining) and climaxes with one of C++'s most notorious architectural quirks: Multiple Inheritance and the Diamond Problem. As always, the code strictly adheres to the **C++98 standard**.

---

## 🧠 Exercise Breakdown & Logic

*The following section explains the core concepts required to solve each exercise, focusing entirely on inheritance architecture and the object lifecycle.*

### 🔹 Base Classes & Single Inheritance
| Exercise | Concept & Logic |
| :--- | :--- |
| **[`ex00: Aaaaand... OPEN!`](ex00)** | **The Base Class:** Establishing the foundational class and testing internal state management.<br><br>**Logic:** You must build a `ClapTrap` class adhering to the Orthodox Canonical Form. It holds basic attributes (Hit points, Energy points, Attack damage) and actions (`attack`, `takeDamage`, `beRepaired`). The core logic involves defensive programming: an action cannot be performed if the object has no hit points or energy points left. |
| **[`ex01: Serena, my love!`](ex01)** | **Single Inheritance & Access Modifiers:** Inheriting from a base class and altering its behavior.<br><br>**Logic:** Introduces `ScavTrap`, a derived class that inherits from `ClapTrap`. To allow `ScavTrap` to set its own default stats during construction, `ClapTrap`'s attributes must be changed from `private` to `protected`. This exercise also proves **Constructor Chaining**: the Base constructor is always called before the Derived constructor, and destructors are called in exact reverse order. Lastly, it overrides the `attack()` function to provide unique output behavior. |
| **[`ex02: Repetitive work`](ex02)** | **Expanding Hierarchies:** Reinforcing single inheritance mechanics.<br><br>**Logic:** You create another derived class, `FragTrap`, with different default stats and a unique special capacity (`highFivesGuys()`). This serves to cement your understanding of polymorphism, object instantiation, and member function overriding before attempting the final boss. |

### 🔹 Multiple Inheritance & The Diamond Problem
| Exercise | Concept & Logic |
| :--- | :--- |
| **[`ex03: Now it's weird!`](ex03)** | **Multiple & Virtual Inheritance:** Handling overlapping inheritance paths and the "Diamond Problem".<br><br>**Logic:** You must create a `DiamondTrap` that inherits from *both* `ScavTrap` and `FragTrap`. Since both parents inherit from `ClapTrap`, `DiamondTrap` would normally contain two separate, ambiguous `ClapTrap` sub-objects in memory. To solve this, `ScavTrap` and `FragTrap` must use **Virtual Inheritance** (`virtual public ClapTrap`), ensuring only one shared `ClapTrap` instance exists. It also handles variable shadowing (`-Wshadow`), requiring explicit scope resolution (`ClapTrap::name`) to distinguish between variables. |

---

## 🛠️ Instructions

### 🧪 Compilation & Execution
Each directory contains its own `Makefile` containing the standard rules (`all`, `clean`, `fclean`, `re`).

All programs are strictly compiled with the C++98 standard and standard error flags. Note that `ex03` specifically requires the `-Wshadow` flag to track shadowed variables during multiple inheritance: 
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
* **[cplusplus.com: Friendship and inheritance](https://cplusplus.com/doc/tutorial/inheritance/)** - The definitive guide on C++ inheritance, explaining derived classes and constructor behaviors.
* **[GeeksforGeeks: Inheritance in C++](https://www.geeksforgeeks.org/cpp/inheritance-in-c/)** - A comprehensive overview of how inheritance works, covering the different modes, syntax, and types of inheritance in C++.
* **[GeeksforGeeks: Access Modifiers in C++](https://www.geeksforgeeks.org/access-modifiers-in-c/)** - A clear breakdown of the difference between `public`, `private`, and `protected` (absolutely essential for solving `ex01`).
* **[GeeksforGeeks: Multiple Inheritance & The Diamond Problem](https://www.geeksforgeeks.org/multiple-inheritance-in-c/)** - Crucial reading for `ex03` to understand how the compiler handles ambiguous base classes.
* **[Medium: Understanding Virtual Inheritance & The Diamond Problem](https://medium.com/@antilogatharv/understanding-virtual-inheritance-and-the-diamond-problem-in-c-da7c63d76723)** - A detailed breakdown of the exact memory duplication issue encountered in `ex03` and how the `virtual` keyword resolves it.

### CodeLucky & Visual Tutorials
* **[C++ Encapsulation Explained: Data Hiding & Access Control](https://www.youtube.com/watch?v=ApFc6j1Qv58)** - A beginner-friendly visual breakdown of how `protected` access modifiers work when building parent/child class architectures.
* **[C++ Inheritance: A Beginner's Guide to Hierarchical Class Relationships](https://www.youtube.com/watch?v=3KW8H-6v-TY)** - A comprehensive guide covering the exact concepts of this module: Base/Derived classes, overriding functions, Multiple Inheritance, and solving the Diamond Problem with virtual inheritance.

---

### 🤖 AI Usage Guidelines
* **Code:** No AI-generated code was used to solve these exercises. All inheritance structures, constructor chains, and virtual sub-objects were manually built to guarantee a deep technical understanding of C++ class memory layout.
* **Documentation:** AI tools were utilized to structure this `README.md` and translate the complex rules of multiple inheritance and the Diamond Problem into a clear educational portfolio format.
