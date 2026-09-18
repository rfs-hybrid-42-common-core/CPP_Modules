*This project has been created as part of the 42 curriculum by maaugust.*

<div align="center">
  <img src="https://raw.githubusercontent.com/rfs-hybrid/42-Common-Core/main/assets/covers/cover-cpp04.png" alt="CPP 04 Cover" width="100%" />
</div>

<div align="center">
  <h1>💻 CPP 04: Subtype Polymorphism</h1>
  <p><i>Runtime polymorphism, virtual functions, deep copies, abstract classes, and interfaces.</i></p>
  <img src="https://img.shields.io/badge/Language-C++98-blue" alt="Language badge" />
  <img src="https://img.shields.io/badge/Grade-100%2F100-success" alt="Grade badge" />
  <br />
</div>

---

## 💡 Description
**CPP 04** marks the transition from compile-time mechanics to **Runtime Polymorphism**. 

This module introduces the `virtual` keyword, demonstrating how C++ resolves method calls dynamically when using base class pointers to manipulate derived objects. It dives deeply into memory management, proving why **Virtual Destructors** are mandatory for inherited classes. It forces the implementation of **Deep Copies** to prevent memory corruption when objects manage dynamic memory (`new`). Finally, it introduces **Abstract Classes** and pure **Interfaces**, teaching the core structural patterns of modern Object-Oriented design. As always, the code strictly adheres to the **C++98 standard**.

---

## 🧠 Exercise Breakdown & Logic

*The following section explains the core concepts required to solve each exercise, focusing entirely on memory safety and virtual method dispatch.*

### 🔹 Virtual Functions & Deep Copies
| Exercise | Concept & Logic |
| :--- | :--- |
| **[`ex00: Polymorphism`](ex00)** | **Subtype Polymorphism:** Calling derived methods through a base class pointer.<br><br>**Logic:** You create a Base class (`Animal`) and Derived classes (`Dog`, `Cat`), all with a `makeSound()` method. By marking the base method as `virtual`, C++ uses dynamic binding to execute the correct derived method at runtime, even if the object is stored in an `Animal*` pointer. A secondary set of classes (`WrongAnimal`, `WrongCat`) deliberately omits the `virtual` keyword to prove that, without it, the compiler defaults to static binding (executing the base class method). |
| **[`ex01: I don’t want to set the world on fire`](ex01)** | **Deep Copies & Virtual Destructors:** Safely managing dynamically allocated attributes inside inherited classes.<br><br>**Logic:** The derived classes now allocate a private `Brain` object dynamically via `new`. <br>• **Virtual Destructors:** The base destructor *must* be virtual. Otherwise, calling `delete` on an `Animal*` pointer pointing to a `Dog` will only destroy the `Animal` portion, leaking the `Dog`'s dynamically allocated brain.<br>• **Deep Copies:** The Copy Constructor and Assignment Operator must allocate a *brand new* brain and copy the data over, rather than just copying the pointer address (a shallow copy), which would cause double-free crashes. |

### 🔹 Abstract Classes & Interfaces
| Exercise | Concept & Logic |
| :--- | :--- |
| **[`ex02: Abstract class`](ex02)** | **Pure Virtual Functions:** Preventing the instantiation of incomplete base classes.<br><br>**Logic:** A generic `Animal` shouldn't be instantiable (what sound does a generic animal make?). By adding `= 0` to the end of a virtual function (`virtual void makeSound() const = 0;`), it becomes a **Pure Virtual Function**. This immediately turns the class into an **Abstract Class**, meaning it cannot be instantiated directly and forces all derived classes to provide their own implementation of that function. |
| **[`ex03: Interface & recap`](ex03)** | **Interfaces & Prototype Pattern:** Establishing strict architectural contracts and factory generation.<br><br>**Logic:** In C++98, an "Interface" is simply an Abstract Class where *every* method is a pure virtual function. You must implement an ecosystem of interfaces and concrete classes, utilizing the **Prototype Pattern** (`clone()`) to generate items from a factory. This serves as the ultimate test of the module, requiring flawless deep copying of pointer arrays, strict interface adherence, and leak-free destruction (tracking "dropped" items). |

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
* **[cplusplus.com: Polymorphism](https://cplusplus.com/doc/tutorial/polymorphism/)** - The definitive guide on pointers to base classes, virtual functions, and abstract base classes.
* **[GeeksforGeeks: Polymorphism in C++](https://www.geeksforgeeks.org/cpp/cpp-polymorphism/)** - A clear breakdown of compile-time vs. runtime polymorphism.
* **[GeeksforGeeks: Pure Virtual Functions and Abstract Classes](https://www.geeksforgeeks.org/cpp/pure-virtual-functions-and-abstract-classes/)** - Explains the `= 0` syntax required for `ex02`.
* **[GeeksforGeeks: Virtual Destructor in C++](https://www.geeksforgeeks.org/virtual-destructor/)** - Essential reading for `ex01`. Explains exactly why deleting a derived class object using a base class pointer causes a memory leak if the destructor isn't virtual.
* **[GeeksforGeeks: Shallow Copy and Deep Copy in C++](https://www.geeksforgeeks.org/shallow-copy-and-deep-copy-in-c/)** - A visual breakdown of how memory behaves during copy operations, and why deep copies are required when dealing with dynamically allocated attributes.
* **[DevGenius: Interface vs Abstract Class](https://blog.devgenius.io/what-is-the-difference-between-interface-and-abstract-class-1b76277f2659)** - A conceptual overview of how to structure pure interfaces, necessary for setting up the contracts in `ex03`.

### CodeLucky & Visual Tutorials
* **[C++ Polymorphism: Virtual Functions & Runtime Method Selection](https://www.youtube.com/watch?v=K7l8T55fnXM)** - A clear visual guide explaining dynamic dispatch, v-tables, and the `virtual` keyword (`ex00`).
* **[C++ Abstraction: Abstract Classes & Pure Virtual Functions Explained!](https://www.youtube.com/watch?v=VhpzGXqxPGo)** - A conceptual guide to writing pure virtual functions (`= 0`) to enforce strict contracts in your class architecture (`ex02` and `ex03`).
* **[C++ Interfaces Explained](https://www.youtube.com/watch?v=xyevQt4w23w)** - Breaks down how to implement pure interfaces in C++ to fulfill the strict architectural requirements of `ex03`.

---

### 🤖 AI Usage Guidelines
* **Code:** No AI-generated code was used to solve these exercises. All virtual method dispatches, deep copy architectures, and interface implementations were developed manually to ensure a rigorous understanding of runtime memory safety.
* **Documentation:** AI tools were utilized to structure this `README.md`, extract the core logic for deep copying and virtual destructors, and translate the architectural requirements into an educational portfolio format.
