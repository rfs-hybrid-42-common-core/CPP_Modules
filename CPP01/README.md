*This project has been created as part of the 42 curriculum by maaugust.*

<div align="center">
  <img src="https://raw.githubusercontent.com/rfs-hybrid/42-Common-Core/main/assets/covers/cover-cpp01.png" alt="CPP 01 Cover" width="100%" />
</div>

<div align="center">
  <h1>💻 CPP 01: Memory & References</h1>
  <p><i>Memory allocation, pointers to members, references, file streams, and switch statements.</i></p>
  <img src="https://img.shields.io/badge/Language-C++98-blue" alt="Language badge" />
  <img src="https://img.shields.io/badge/Grade-100%2F100-success" alt="Grade badge" />
  <br />
</div>

---

## 💡 Description
**CPP 01** dives into how C++ handles memory and memory addresses, formally leaving behind C's `malloc` and `free`. 

This module introduces the `new` and `delete` operators for dynamic allocation. It also introduces **References**—a safer, non-null alternative to standard pointers—and explores File I/O using the `<fstream>` library. Finally, it covers advanced function routing using pointers to member functions to avoid rigid `if/else` logic. As always, the code strictly adheres to the **C++98 standard**.

---

## 🧠 Exercise Breakdown & Logic

*The following section explains the core concepts required to solve each exercise, focusing entirely on memory architecture and class design.*

### 🔹 Memory & Allocations
| Exercise | Concept & Logic |
| :--- | :--- |
| **[`ex00: BraiiiiiiinnnzzzZ`](ex00)** | **Stack vs. Heap Allocation:** Demonstrating the difference in lifecycle between dynamically and automatically allocated objects.<br><br>**Logic:** You must write two functions. One allocates an object on the **heap** using the `new` keyword (returning a pointer that must be manually freed using `delete`). The other instantiates an object on the **stack** (which is automatically destroyed when it goes out of scope). |
| **[`ex01: Moar brainz!`](ex01)** | **Array Allocation:** Managing contiguous blocks of dynamically allocated objects.<br><br>**Logic:** Introduces `new[]` to allocate an array of objects in a single allocation. Crucially, it demonstrates that you must use the `delete[]` operator to cleanly destroy an array of objects and prevent memory leaks. |
| **[`ex02: HI THIS IS BRAIN`](ex02)** | **References:** Demystifying C++ references and comparing them directly to pointers.<br><br>**Logic:** A simple program that creates a string, a pointer to that string, and a reference (`&`) to that string. By printing the memory addresses and values of all three, it visually proves that a reference is essentially an implicit, constant pointer that perfectly aliases the original variable. |
| **[`ex03: Unnecessary violence`](ex03)** | **Pointers vs. References as Attributes:** Designing classes around the constraints of pointers and references.<br><br>**Logic:** Two classes share a dependency on a "Weapon" object. <br>• **Class A** always has the weapon upon creation, so it takes it as a **Reference** (ensuring it is never `NULL` and cannot be reassigned).<br>• **Class B** may not have a weapon immediately, so it takes it as a **Pointer** (which can be initialized to `NULL` and assigned later). |

### 🔹 File Streams & Advanced Routing
| Exercise | Concept & Logic |
| :--- | :--- |
| **[`ex04: Sed is for losers`](ex04)** | **File I/O & String Manipulation:** Creating a program that reads a file, replaces every occurrence of string `s1` with `s2`, and outputs the result to a `.replace` file.<br><br>**Logic:** C file manipulation functions are completely forbidden. This requires using `std::ifstream` (input file stream) and `std::ofstream` (output file stream). Furthermore, `std::string::replace` is forbidden, requiring manual parsing using `std::string::find` and `std::string::erase`/`insert` (or building a new string via substrings). |
| **[`ex05: Harl 2.0`](ex05)** | **Pointers to Member Functions:** Calling specific class methods dynamically without using `if/else` or `switch` statements.<br><br>**Logic:** A class has four distinct logging methods (DEBUG, INFO, WARNING, ERROR). Instead of checking the input string with a chain of `if/else` conditions, you must create an array of *pointers to member functions*. The program finds the matching string index and directly invokes the corresponding function via the pointer. |
| **[`ex06: Harl filter`](ex06)** | **Switch Statements & Fall-through:** Filtering output based on severity levels.<br><br>**Logic:** Taking the previous logic a step further, this exercise introduces the `switch` statement. It utilizes intentional "fall-through" (omitting the `break` keyword) so that if a low severity level is selected, all higher severity levels execute consecutively. |

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
* **[cplusplus.com: Dynamic Memory](https://cplusplus.com/doc/tutorial/dynamic/)** - Explains the `new` and `delete` operators in C++.
* **[cplusplus.com: Pointers](https://cplusplus.com/doc/tutorial/pointers/)** - Detailed breakdown of memory addresses, pointers, and arrays.
* **[cplusplus.com: Input/Output with files](https://cplusplus.com/doc/tutorial/files/)** - Essential guide to using `<fstream>`, `std::ifstream`, and `std::ofstream` for `ex04`.
* **[GeeksforGeeks: Pointers vs References in C++](https://www.geeksforgeeks.org/pointers-vs-references-cpp/)** - A conceptual breakdown crucial for solving `ex03`.
* **[IBM: Pointers to Member Functions](https://www.ibm.com/docs/en/zos/2.4.0?topic=only-pointers-members-c)** - Technical documentation explaining the syntax needed for `ex05`.

### CodeLucky & Visual Tutorials
* **[C++ Dynamic Memory Allocation (new & delete)](https://www.youtube.com/watch?v=qNDpTSE-mm4)** - A great visual explanation of Stack vs. Heap memory, essential for `ex00` and `ex01`.
* **[C++ Destructors Explained for Beginners: Memory Management & Best Practices](https://www.youtube.com/watch?v=4RuqxImyaxA)** - A deep dive into destructors, perfectly accompanying dynamic memory allocation and crucial for preventing memory leaks in `ex00` and `ex01`.
* **[C++ References Explained for Beginners: Aliases, Parameters & Best Practices](https://www.youtube.com/watch?v=tDuHINp8STg)** - A deep dive into creating aliases, `const` reference safety, and how they behave in memory compared to pointers (crucial for `ex02` and `ex03`).
* **[C++ References vs Pointers](https://www.youtube.com/watch?v=vxyWUCHvmHg)** - Explains exactly how references work under the hood and when to use them over traditional pointers (`ex02` and `ex03`).
* **[C++ File I/O: Reading and Writing to Files](https://www.youtube.com/watch?v=hZXoOv39vRU)** - A step-by-step guide to `<fstream>` necessary for building the file replacer in `ex04`.
* **[C++ Strings Tutorial for Beginners: Master Text Manipulation](https://www.youtube.com/watch?v=ItfDCOqAaiQ)** - An excellent breakdown of the `std::string` class methods, particularly `.find()` and `.substr()`, which are critical for parsing and manipulating text safely.
* **[C++ Pointers Explained for Beginners: Memory Management & More!](https://www.youtube.com/watch?v=LIBDrsvKhBQ)** - A comprehensive pointer guide that specifically covers **Function Pointers**—a rarely used but mandatory concept for solving `ex05`.
* **[C++ Switch Statement Explained](https://www.youtube.com/watch?v=NK4kCXKmDGU)** - A clear guide to `switch` syntax and how "fall-through" logic works for `ex06`.

---

### 🤖 AI Usage Guidelines
* **Code:** No AI-generated code was used to solve these exercises. All memory allocations, stream manipulations, and pointer-to-member function arrays were built manually to guarantee a deep technical understanding of C++ memory architectures.
* **Documentation:** AI tools were utilized to structure this `README.md` and strip away the specific subject lore, translating the requirements into pure C++ concepts for an educational portfolio.
