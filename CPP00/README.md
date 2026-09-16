*This project has been created as part of the 42 curriculum by maaugust.*

<div align="center">
  <img src="https://raw.githubusercontent.com/rfs-hybrid/42-Common-Core/main/assets/covers/cover-cpp00.png" alt="CPP 00 Cover" width="100%" />
</div>

<div align="center">
  <h1>💻 CPP 00: Object-Oriented Basics</h1>
  <p><i>Introduction to C++, namespaces, classes, member functions, stdio streams, initialization lists, and static variables.</i></p>
  <img src="https://img.shields.io/badge/Language-C++98-blue" alt="Language badge" />
  <img src="https://img.shields.io/badge/Grade-100%2F100-success" alt="Grade badge" />
  <br />
</div>

---

## 💡 Description
**CPP 00** is the first module in the 42 C++ curriculum. It serves as the bridge between procedural C programming and the Object-Oriented Programming (OOP) paradigms of C++.

The primary goal of this project is to unlearn C habits (like `printf`, `malloc`, and `free`) and embrace C++ idioms. It introduces standard I/O streams (`std::cin`, `std::cout`), string classes, encapsulation via classes, access modifiers (`private`/`public`), and static members. To enforce foundational understanding, all code must strictly comply with the **C++98 standard**. (Note: No coding style or "Norminette" is enforced for C++ modules, prioritizing clean and readable code over strict formatting rules).

---

## 🧠 Exercise Breakdown & Logic

*The following section explains the core concepts required to solve each exercise, focusing on class architecture, state management, and stream formatting.*

### 🔹 C++ Fundamentals
| Exercise | Concept & Logic |
| :--- | :--- |
| **[`ex00: Megaphone`](ex00)** | **Standard I/O & Strings:** Creating a program that converts command-line arguments to uppercase and prints them, or outputs a default noise if no arguments are given.<br><br>**Logic:** A simple introduction to C++ output. Instead of `write` or `printf`, we use the `std::cout` stream and the insertion operator `<<`. Iterate through `argv`, convert characters using `std::toupper`, and print. |
| **[`ex01: My Awesome PhoneBook`](ex01)** | **Classes, Encapsulation & Formatting:** Building a command-line phonebook that can store up to 8 contacts, replacing the oldest one when full. It prompts for commands: `ADD`, `SEARCH`, `EXIT`.<br><br>**Logic:** Requires building two classes: `PhoneBook` and `Contact`. <br>• **State:** `PhoneBook` holds an array of exactly 8 `Contact` objects and tracks the current index. A modulo operator (`index % 8`) effortlessly handles the circular overwriting logic.<br>• **Input:** Uses `std::getline(std::cin, ...)` to safely read inputs and block empty fields.<br>• **Formatting:** Introduces `<iomanip>`. Uses `std::setw(10)` to set column width, and a helper function to truncate fields longer than 10 characters and append a dot (`.`). |
| **[`ex02: The Job Of Your Dreams`](ex02)** | **Static Members, Init Lists & Destructors:** Reconstructing a missing `Account.cpp` implementation file to perfectly match the provided `Account.hpp` header and a provided `tests.cpp` main file.<br><br>**Logic:** This exercise focuses on class lifecycle and shared state. <br>• **Static Variables:** Uses static attributes to track the total number of accounts and overall bank funds across *all* instances simultaneously.<br>• **Timestamps:** Uses `<ctime>` to generate the required log prefixes.<br>• **Lifecycle:** Proves understanding of constructors (initialization lists) and destructors by ensuring the exact sequence of creation/destruction logs match the expected output. |

---

## 🛠️ Instructions

### 🧪 Compilation & Execution
Every exercise in the C++ modules is a fully standalone program. Each directory contains its own `Makefile` containing at least the standard rules (`all`, `clean`, `fclean`, `re`).

All programs are strictly compiled with the C++98 standard and standard error flags: 
`c++ -Wall -Wextra -Werror -std=c++98`

1. **Navigate to the specific exercise directory:**
   ```bash
   cd ex01
   ```

2. **Compile the program:**
   Use the provided `Makefile` to compile the source code into an executable.
   ```bash
   make
   ```

3. **Run the executable:**
   ```bash
   ./<executable_name>  # e.g., ./megaphone, ./phoneBook, or ./jobOfYourDreams
   ```

4. **Clean up binary files:**
   To remove the compiled object files and the executable, run:
   ```bash
   make fclean
   ```

---

## 📚 Resources & References

### General C++ Documentation
* **[W3Schools: C++ Tutorial](https://www.w3schools.com/cpp/)** - A beginner-friendly, interactive tutorial covering basic C++ syntax, operators, and early OOP concepts.
* **[TutorialsPoint: C++ Tutorial](https://www.tutorialspoint.com/cplusplus/index.htm)** - A highly structured text-based course covering C++ fundamentals from basic syntax to advanced OOP.
* **[cplusplus.com: Classes (I)](https://cplusplus.com/doc/tutorial/classes/)** - Deep dive into Object-Oriented Programming, access specifiers (`private`/`public`), and constructors. Essential for building the `Contact` and `PhoneBook` objects.
* **[cplusplus.com: Namespaces](https://cplusplus.com/doc/tutorial/namespaces/)** - Explains how to use and define namespaces (like `std::`) to prevent naming collisions.
* **[cplusplus.com: `<iomanip>` Reference](https://cplusplus.com/reference/iomanip/)** - Official documentation for stream manipulation tools (like `std::setw` and `std::right`) used heavily in `ex01` to format the PhoneBook table.
* **[GeeksforGeeks: Static Data Members in C++](https://www.geeksforgeeks.org/static-data-members-c/)** - Crucial for understanding how to share state (like total bank funds) across all instances simultaneously in `ex02`.
* **[GeeksforGeeks: Initializer List in C++](https://www.geeksforgeeks.org/when-do-we-use-initializer-list-in-c/)** - Explains the syntax and performance benefits of initializing variables before the constructor body executes.

### CodeLucky & Visual Tutorials
* **[A Beginner's Guide to Object-Oriented Programming](https://www.youtube.com/watch?v=dQlWBPGqy5A)** - A visual breakdown of what Object-Oriented Programming actually is and why it differs from procedural C.
* **[C++ Namespaces: Organize Code & Avoid Conflicts](https://www.youtube.com/watch?v=j0rCht42jx0)** - Explains how to properly use `std::` and custom namespaces to avoid naming collisions in your code.
* **[C++ Class Methods: A Beginner's Guide to Member Functions](https://www.youtube.com/watch?v=KO6kUE44tLk)** - A clear guide to defining and implementing functions inside of your C++ classes.
* **[C++ Constructors Explained](https://www.youtube.com/watch?v=xSubxm9uFrA)** - Covers default constructors, parameterized constructors, and the crucial initialization lists required for proper object instantiation.
* **[C++ Input for Beginners: cin, getline & Error Handling](https://www.youtube.com/watch?v=GN5fruH-P5Q)** - Demonstrates how to use `std::cin` and `std::getline` effectively to avoid the common input buffer issues present in `ex01`.
* **[C++ Output for Beginners: Mastering cout & Stream Formatting](https://www.youtube.com/watch?v=RxNkYJZTY0E)** - A guide to mastering `std::cout` and utilizing stream formatting tools like `<iomanip>`.
* **[C++ Strings Tutorial for Beginners: Master Text Manipulation](https://www.youtube.com/watch?v=ItfDCOqAaiQ)** - An excellent breakdown of the `std::string` class methods, particularly `.find()` and `.substr()`, which are critical for parsing and manipulating text safely.
* **[C++ Date and Time: Mastering the ctime Library](https://www.youtube.com/watch?v=0cM2F3jTd98)** - Breaks down the `<ctime>` library, which is absolutely essential for generating the timestamps in `ex02`.

---

### 🤖 AI Usage Guidelines
* **Code:** No AI-generated code was used to solve these exercises. All classes, member functions, and standard stream manipulations were built manually to strictly comply with the 42 C++ curriculum and fully understand manual object lifecycle management.
* **Documentation:** AI tools were utilized to structure this `README.md` and format the logic breakdowns to create a clean, accessible educational resource for fellow 42 students transitioning into Object-Oriented Programming.
