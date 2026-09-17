# 🟢 Exercise 06: Harl filter

## 📝 Objective
Create a program named `harlFilter` that takes a log level as a parameter. It must filter what Harl says, displaying all messages from the requested level and above. The core requirement is that you must use a `switch` statement to handle the routing.

## 💡 The Logic

This exercise expands on the previous one by introducing severity hierarchies. It forces you to learn the mechanics of the C++ `switch` statement and how to exploit its default "fall-through" behavior.

1. **The String/Switch Limitation:** In C++98, a `switch` statement can *only* evaluate integral types (like `int` or `char`). You cannot pass a `std::string` directly into a `switch`. 
2. **String-to-Integer Mapping:** To solve the limitation above, the `Harl` class uses a private helper method (`getLevelIndex()`). It compares the string input against an array of valid levels and returns an integer index (`0` for DEBUG, `1` for INFO, etc., and `-1` for unknown). This integer is what actually gets passed into the `switch`.
3. **Intentional Fall-Through:** Typically, every `case` in a switch statement ends with the `break` keyword to stop execution. However, if you omit `break`, the program will "fall through" and execute the code in the next `case` automatically. By stacking the cases from least severe (0: DEBUG) to most severe (3: ERROR), calling "INFO" (1) executes the info message, then falls through to execute warning, and finally falls through to execute error.
4. **The Default Catch-All:** If the provided string doesn't match any known level (index `-1`), the `switch` statement falls to the `default` case, which prints the fallback Black Hole complaint.

## 🛠️ Step-by-Step Solution

1. **The Code:**
   *Check out the source files here:*
   - **[`inc/Harl.hpp`](inc/Harl.hpp)** / **[`src/Harl.cpp`](src/Harl.cpp)**
   - **[`src/main.cpp`](src/main.cpp)**
   - **[`Makefile`](Makefile)**

2. **Testing the Cascade Filter:**
   Compile the program and observe how the intentional fall-through logic creates a cascading output.
   ```bash
   make
   
   # Test 1: High Severity (Only prints Warning and Error)
   ./harlFilter "WARNING"
   
   # Test 2: Low Severity (Prints everything: Debug, Info, Warning, Error)
   ./harlFilter "DEBUG"
   
   # Test 3: Unknown string (Hits the default case)
   ./harlFilter "I am not sure how tired I am today..."
   
   # Test 4: Missing Arguments
   ./harlFilter
   # Expected: Safely catches the argc error and returns EXIT_FAILURE.
   ```
