*This project has been created as part of the 42 curriculum by maaugust.*

<div align="center">
  <img src="https://raw.githubusercontent.com/rfs-hybrid/42-Common-Core/main/assets/covers/cover-cpp-bonus.png" alt="MiniRT Cover" width="100%" />
</div>

<div align="center">
  <h1>🚀 C++ Modules (00 - 09)</h1>
  <p><i>A comprehensive journey through Object-Oriented Programming, transitioning from procedural C to advanced C++98 architectures.</i></p>
  <img src="https://img.shields.io/badge/Language-C++98-blue" />
  <img src="https://img.shields.io/badge/Grade-100%2F100-success" />
  <br />
</div>

---

## 💡 About This Repository

This repository acts as a centralized portfolio for my **42 C++ Modules** journey. It contains all 10 modules (00 through 09) organized into their respective directories. Each module is fully self-contained, complete with its own strict `Makefile`, source files, and specific conceptual documentation.

### 🛠️ How to Clone
To explore the modules and their source code, simply clone this repository:

```bash
git clone https://github.com/rfs-hybrid-42-common-core/CPP_Modules
cd CPP_Modules
```

---

## 🚀 Engineering Philosophy & Architecture

The 42 C++ curriculum is designed to rebuild a developer's mindset from the ground up, transitioning away from procedural C and fully adopting Object-Oriented Programming paradigms. To enforce a deep understanding of core mechanics, the entire curriculum is strictly restricted to the **C++98 standard**. Modern features (like `auto`, smart pointers, or C++11 standard libraries) are strictly forbidden.

While completing the core requirements is enough to pass, I treat every project in this portfolio as production-grade software engineered to achieve the maximum possible bonus score. 
* **Orthodox Canonical Form (OCF):** From Module 02 onward, every class is meticulously designed using OCF. This guarantees that every object implements a Default Constructor, Copy Constructor, Copy Assignment Operator, and Destructor, ensuring bulletproof memory management and deep-copy data safety.
* **Defensive Programming:** Memory leakage occurs in C++ just as it does in C. Every dynamic allocation (`new`/`delete`) is heavily protected, and every executable is proven 100% leak-free via rigorous `Valgrind` testing.
* **Standard Template Library (STL) Restrictions:** To force algorithmic comprehension, the use of the STL (Containers and Algorithms) is strictly forbidden until the final two modules. Every data structure and manipulation prior to Module 08 is built entirely from scratch.

---

## 🏆 Curriculum Progress & Conceptual Matrix

*The modules progressively increase in complexity, introducing new paradigms and architectural rules at each step.*

| Module | Status | Core C++ Concepts Explored |
| :---: | :---: | :--- |
| [**CPP 00**](https://github.com/rfs-hybrid-42-common-core/CPP_Modules/tree/main/CPP00)<br>![CPP 00](https://raw.githubusercontent.com/rfs-hybrid/42-Common-Core/main/assets/badges/numbered_cpps/CPP00.png) | 🟢 Done<br>*(100%)* | **Basics:** Namespaces, Classes, Member Functions, Stdio Streams, Initialization Lists, Static & Const members. |
| [**CPP 01**](https://github.com/rfs-hybrid-42-common-core/CPP_Modules/tree/main/CPP01)<br>![CPP 01](https://raw.githubusercontent.com/rfs-hybrid/42-Common-Core/main/assets/badges/numbered_cpps/CPP01.png) | 🟢 Done<br>*(100%)* | **Memory:** Dynamic Allocation (`new`/`delete`), Pointers to Members, References, Switch Statements. |
| [**CPP 02**](https://github.com/rfs-hybrid-42-common-core/CPP_Modules/tree/main/CPP02)<br>![CPP 02](https://raw.githubusercontent.com/rfs-hybrid/42-Common-Core/main/assets/badges/numbered_cpps/CPP02.png) | 🟢 Done<br>*(100%)* | **Polymorphism:** Ad-hoc Polymorphism, Operator Overloading, Orthodox Canonical Class Form. |
| [**CPP 03**](https://github.com/rfs-hybrid-42-common-core/CPP_Modules/tree/main/CPP03)<br>![CPP 03](https://raw.githubusercontent.com/rfs-hybrid/42-Common-Core/main/assets/badges/numbered_cpps/CPP03.png) | 🟢 Done<br>*(100%)* | **Inheritance:** Class derivation, protected attributes, object construction/destruction chaining. |
| [**CPP 04**](https://github.com/rfs-hybrid-42-common-core/CPP_Modules/tree/main/CPP04)<br>![CPP 04](https://raw.githubusercontent.com/rfs-hybrid/42-Common-Core/main/assets/badges/numbered_cpps/CPP04.png) | 🟢 Done<br>*(100%)* | **Interfaces:** Subtype Polymorphism, Abstract Classes, Pure Virtual Functions, Deep vs. Shallow Copies. |
| [**CPP 05**](https://github.com/rfs-hybrid-42-common-core/CPP_Modules/tree/main/CPP05)<br>![CPP 05](https://raw.githubusercontent.com/rfs-hybrid/42-Common-Core/main/assets/badges/numbered_cpps/CPP05.png) | 🟢 Done<br>*(100%)* | **Exceptions:** Try/Catch blocks, custom Exception Classes, execution flow interruption. |
| [**CPP 06**](https://github.com/rfs-hybrid-42-common-core/CPP_Modules/tree/main/CPP06)<br>![CPP 06](https://raw.githubusercontent.com/rfs-hybrid/42-Common-Core/main/assets/badges/numbered_cpps/CPP06.png) | 🟢 Done<br>*(100%)* | **Casts:** Type conversion via `static_cast`, `dynamic_cast`, `reinterpret_cast`, and `const_cast`. |
| [**CPP 07**](https://github.com/rfs-hybrid-42-common-core/CPP_Modules/tree/main/CPP07)<br>![CPP 07](https://raw.githubusercontent.com/rfs-hybrid/42-Common-Core/main/assets/badges/numbered_cpps/CPP07.png) | 🟢 Done<br>*(100%)* | **Templates:** Function Templates, Class Templates, generic programming paradigms. |
| [**CPP 08**](https://github.com/rfs-hybrid-42-common-core/CPP_Modules/tree/main/CPP08)<br>![CPP 08](https://raw.githubusercontent.com/rfs-hybrid/42-Common-Core/main/assets/badges/numbered_cpps/CPP08.png) | 🟢 Done<br>*(100%)* | **Iterators:** Templated Containers, Iterators, and introductory Standard Template Library (STL) algorithms. |
| [**CPP 09**](https://github.com/rfs-hybrid-42-common-core/CPP_Modules/tree/main/CPP09)<br>![CPP 09](https://raw.githubusercontent.com/rfs-hybrid/42-Common-Core/main/assets/badges/numbered_cpps/CPP09.png) | 🟢 Done<br>*(100%)* | **Advanced STL:** Complex data processing, algorithm optimization (e.g., Ford-Johnson merge-insert sort), and multi-container state management. |

---

## 🤖 AI Usage & Transparency

In alignment with the pedagogical guidelines of the 42 curriculum, AI tools were utilized strictly as a learning accelerator and not to bypass problem-solving:

* **Concept Clarification:** AI was used to explain abstract Object-Oriented paradigms (such as Subtype Polymorphism and Virtual Tables) and to demystify complex C++98 casting restrictions.
* **Documentation & Formatting:** AI assisted in structuring this repository's markdown files to ensure they met all curriculum requirements while maintaining a clear, professional layout.
* **Zero Code Generation:** All C++ code, class architectures, memory management schemas, and algorithmic implementations were developed manually. No source code was generated by AI, ensuring complete technical comprehension and responsibility for the peer-evaluation defense.
