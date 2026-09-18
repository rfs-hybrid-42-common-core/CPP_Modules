# 🟢 Exercise 00: Mommy, when I grow up, I want to be a bureaucrat!

## 📝 Objective
Create a `Bureaucrat` class featuring a constant name and a highly regulated grade ranging from 1 (highest) to 150 (lowest). Implement nested custom exception classes that inherit from `std::exception`. If a program attempts to instantiate a bureaucrat with an invalid grade—or modify an existing grade out of bounds—the class must safely throw an exception to prevent the invalid state.

## 💡 The Logic

This exercise introduces the `try`, `throw`, and `catch` control flow, demonstrating how to handle errors cleanly without crashing the program or relying on arbitrary return codes.

1. **State Validation (`throw`):** 
   A `Bureaucrat`'s grade operates in reverse: 1 is the CEO, 150 is the intern. Incrementing a grade subtracts from the integer; decrementing adds to it. Before any state change occurs (in the constructor or the `incrementGrade`/`decrementGrade` methods), the class checks the bounds. If an operation pushes the grade to 0 or 151, the program immediately halts execution of that block and `throws` a specific exception object.
2. **Nested Exception Classes:** 
   To maintain a clean global namespace, the exception classes (`GradeTooHighException` and `GradeTooLowException`) are declared *inside* the `Bureaucrat` class. They inherit from standard C++ `std::exception` and override the `what()` method to return a statically allocated error string. Because they inherit from a custom base `Bureaucrat::Exception`, they allow for grouped, polymorphic error handling.
3. **Graceful Error Handling (`try/catch`):** 
   In `main.cpp`, operations are wrapped in `try {}` blocks. If a `Bureaucrat` throws an error, the rest of the `try` block is skipped, and the program jumps directly to the `catch {}` block. By catching by reference (`catch (Bureaucrat::Exception const & e)`), we polymorphically catch any specific Bureaucrat error, print the `e.what()` message, and allow the program to continue running safely.
4. **Orthodox Canonical Form & Constants:** 
   Because `_name` is a `const` attribute, it can only be set during initialization (via the constructor's initializer list). The Copy Assignment Operator (`operator=`) acknowledges this limitation by only updating the `_grade` attribute of the target object, while printing a specific trace message if the attributes remain unchanged to protect against self-assignment.

## 🛠️ Step-by-Step Solution

1. **The Code:**
   *Check out the source files here:*
   - **[`inc/Bureaucrat.hpp`](inc/Bureaucrat.hpp)** / **[`src/Bureaucrat.cpp`](src/Bureaucrat.cpp)**
   - **[`src/main.cpp`](src/main.cpp)**
   - **[`Makefile`](Makefile)**

2. **Testing Exceptions & Bounds:**
   Compile the program and observe how the code safely navigates deliberate out-of-bounds errors.
   ```bash
   make
   
   ./bureaucrat
   
   # Output Analysis:
   # 1. Standard Execution: A Bureaucrat successfully initializes, increments, and decrements their grade within safe bounds.
   # 2. Constructor Exceptions: Attempting to create "Icarus" with grade 0 instantly throws a GradeTooHighException. The print statement following the instantiation is safely skipped.
   # 3. Modifier Exceptions: Attempting to increment a grade 1 Bureaucrat throws the same exception, intercepting the invalid state change.
   # 4. Canonical Form: Copy assignment updates the grade while explicitly ignoring the constant name.
   ```
