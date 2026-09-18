# 🟢 Exercise 03: At least this beats coffee-making

## 📝 Objective
Implement an `Intern` class whose sole purpose is to dynamically generate concrete form objects based on a string identifier. The core constraint of this exercise is strictly architectural: you are **forbidden** from using unreadable `if/elseif/else` chains to map the strings to the objects. 

## 💡 The Logic

This exercise introduces a variation of the **Factory Design Pattern**, combined with a **Dispatch Table**, to cleanly instantiate polymorphic objects at runtime.

1. **The Factory Pattern:** 
   The `Intern` acts as an object factory. The caller (in `main.cpp`) asks the intern to "make a robotomy request form." The caller does not need to know the specific class name or how the object is constructed; they only need to receive the polymorphic `AForm*` pointer back. This drastically reduces coupling in large systems.
2. **Pointers to Member Functions (The Dispatch Table):** 
   To avoid massive `if/else` chains when matching strings in C++98, we utilize an array of member function pointers. 
   - We define three private helper methods (e.g., `_makeShrubbery`) that simply return a `new` instance of their respective forms.
   - Inside `makeForm()`, we align two arrays: an array of valid strings (`{"shrubbery creation", ...}`) and a parallel array of function pointers (`{&Intern::_makeShrubbery, ...}`).
   - We loop through the string array. If a match is found, we use the corresponding index to execute the function pointer: `(this->*funcs[i])(target)`. This results in clean, scalable, and highly readable routing logic.
3. **Exception Handling:** 
   If the loop finishes without finding a matching string, the factory fails. Instead of returning a null pointer and relying on the caller to check it, the `Intern` throws a custom `FormNotFound` exception, maintaining the strict error-handling paradigm established in this module.
4. **Memory Ownership:** 
   The Factory Pattern dynamically allocates memory (`new`) but passes the pointer back to the caller. It is critical to understand that the `Intern` does *not* own this memory—the caller (`main.cpp`) assumes responsibility for calling `delete` on the returned `AForm*` pointers to prevent memory leaks.

## 🛠️ Step-by-Step Solution

1. **The Code:**
   *Check out the source files here:*
   - **[`inc/Bureaucrat.hpp`](inc/Bureaucrat.hpp)** /**[`src/Bureaucrat.cpp`](src/Bureaucrat.cpp)**
   - **[`inc/AForm.hpp`](inc/AForm.hpp)** /**[`src/AForm.cpp`](src/AForm.cpp)**
   - **[`inc/ShrubberyCreationForm.hpp`](inc/ShrubberyCreationForm.hpp)** / **[`src/ShrubberyCreationForm.cpp`](src/ShrubberyCreationForm.cpp)**
   - **[`inc/RobotomyRequestForm.hpp`](inc/RobotomyRequestForm.hpp)** / **[`src/RobotomyRequestForm.cpp`](src/RobotomyRequestForm.cpp)**
   - **[`inc/PresidentialPardonForm.hpp`](inc/PresidentialPardonForm.hpp)** / **[`src/PresidentialPardonForm.cpp`](src/PresidentialPardonForm.cpp)**
   - **[`inc/Intern.hpp`](inc/Intern.hpp)** / **[`src/Intern.cpp`](src/Intern.cpp)**
   - **[`src/main.cpp`](src/main.cpp)**
   - **[`Makefile`](Makefile)**

3. **Testing the Factory:**
   Compile the program and observe the dynamic instantiation and error handling at the end of the test suite.
   ```bash
   make
   
   ./intern
   
   # Output Analysis (Intern section):
   # 1. Successful Dispatch: The Intern successfully routes the strings "robotomy request", "shrubbery creation", and "presidential pardon" to their respective concrete constructors using the function pointer array.
   # 2. Exception Handling: When asked to create an unknown "coffee request" form, the Intern immediately throws the FormNotFound exception, which is caught and printed securely.
   # 3. Memory Cleanup: In the final section of main.cpp, the program safely deletes the generated AForm pointers, fulfilling the caller's memory ownership responsibilities.
   ```
