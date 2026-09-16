# 🟢 Exercise 05: Harl 2.0

## 📝 Objective
Create a `Harl` class with four private member functions: `debug`, `info`, `warning`, and `error`. You must implement a public `complain(std::string level)` method that calls the appropriate private function based on the passed string. The core constraint is that you **must use pointers to member functions**; a forest of `if/else` or `switch` statements is strictly forbidden.

## 💡 The Logic

This exercise introduces a powerful but rarely used C++ paradigm: **Pointers to Member Functions**. It allows for highly scalable code (like routing systems or state machines) where functions are treated as data that can be stored in arrays and invoked dynamically.

1. **Parallel Arrays:** Inside `complain()`, the program initializes two static arrays:
   - An array of `std::string` containing the target levels (`"DEBUG"`, `"INFO"`, etc.).
   - An array of pointers to member functions (`void (Harl::*funcs[4])(void)`).
2. **Assigning the Pointers:** To store the address of a member function, you must use the address-of operator and the class scope resolution: `&Harl::debug`.
3. **Invoking the Pointers:** Standard function pointers are invoked directly (e.g., `func()`). However, *member* functions require an object instance to execute (they need a hidden `this` pointer). To call the function stored in the array, you must explicitly bind it to the current object using the `->*` operator: `(this->*funcs[i])()`.
4. **Input Sanitization:** To make the class more robust against sloppy inputs (like `"  DEBUG  "`), the program includes a private helper method that trims leading and trailing whitespaces before matching the string against the parallel arrays.
5. **Custom 42 Themes:** The standard Harl complains about burgers. Your implementation replaces the generic complaints with thematic 42-school references (Norminette, 100/100 evaluations, Decibel Trackers, and TIGs), making the exercise much more entertaining!

## 🛠️ Step-by-Step Solution

1. **The Code:**
   *Check out the source files here:*
   - **[`inc/Harl.hpp`](inc/Harl.hpp)** / **[`src/Harl.cpp`](src/Harl.cpp)**
   - **[`src/main.cpp`](src/main.cpp)**
   - **[`Makefile`](Makefile)**

2. **Testing the Router:**
   Compile the program and observe how the dynamic routing bypasses traditional `if/else` checks:
   ```bash
   make
   
   # Run the executable
   ./harl
   
   # Output Analysis:
   # 1. "DEBUG" properly triggers the Norminette complaint.
   # 2. "  DEBUG  " is cleanly trimmed and also triggers the DEBUG complaint.
   # 3. "INFO", "WARNING", and "ERROR" properly trigger their respective functions.
   # 4. "UNKNOWN" safely falls through the loop and prints the default Black Hole message.
   ```
