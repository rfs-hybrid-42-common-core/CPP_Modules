# 🟢 Exercise 02: No, you need form 28B, not 28C...

## 📝 Objective
Transform the generic `Form` into an Abstract Base Class named `AForm`. Then, create three concrete derived classes (`ShrubberyCreationForm`, `RobotomyRequestForm`, and `PresidentialPardonForm`), each with distinct grade requirements and unique execution behaviors. A form can only be executed if it is already signed and the executing bureaucrat has a sufficiently high grade.

## 💡 The Logic

This exercise marries the polymorphic architecture of CPP 04 with the exception handling of CPP 05, introducing a classic OOP design pattern to manage execution flow.

1. **The Template Method Pattern:** 
   The base `AForm` class possesses a public `execute(Bureaucrat const & executor)` method and a protected, pure virtual `executeAction() const = 0` method. When a bureaucrat attempts to execute a form, the base `execute()` method runs first. It acts as a security checkpoint: it checks if the form is signed and if the executor's grade is high enough. If either check fails, it throws a `NotSignedException` or a `GradeTooLowException`. If the checks pass, it dynamically calls the derived class's specific `executeAction()`. This pattern prevents you from having to rewrite the security checks in every single derived class.
2. **Concrete Implementations:** 
   Because `AForm` is an abstract class, you cannot instantiate it. Instead, you instantiate the concrete forms, each providing their own `executeAction()`:
   - **ShrubberyCreationForm:** Demonstrates File I/O (`<fstream>`) by generating a `<target>_shrubbery` file and writing ASCII trees into it. It includes its own custom `FileOpenException`.
   - **RobotomyRequestForm:** Demonstrates randomness (`std::rand()`) by having a 50% chance to succeed or fail.
   - **PresidentialPardonForm:** Demonstrates standard output execution.
3. **Delegated Execution (`try/catch`):** 
   Just like the signing process in `ex01`, the `Bureaucrat` class receives an `executeForm(AForm const & form)` method. The bureaucrat blindly attempts to trigger the form's execution within a `try` block. If the form's security checkpoint rejects them (or if the Shrubbery file fails to open), the bureaucrat `catches` the polymorphic `std::exception` and prints a formatted rejection message.

## 🛠️ Step-by-Step Solution

1. **The Code:**
   *Check out the source files here:*
   - **[`inc/Bureaucrat.hpp`](inc/Bureaucrat.hpp)** / **[`src/Bureaucrat.cpp`](src/Bureaucrat.cpp)**
   - **[`inc/AForm.hpp`](inc/AForm.hpp)** / **[`src/AForm.cpp`](src/AForm.cpp)**
   - **[`inc/ShrubberyCreationForm.hpp`](inc/ShrubberyCreationForm.hpp)** / **[`src/ShrubberyCreationForm.cpp`](src/ShrubberyCreationForm.cpp)**
   - **[`inc/RobotomyRequestForm.hpp`](inc/RobotomyRequestForm.hpp)** / **[`src/RobotomyRequestForm.cpp`](src/RobotomyRequestForm.cpp)**
   - **[`inc/PresidentialPardonForm.hpp`](inc/PresidentialPardonForm.hpp)** / **[`src/PresidentialPardonForm.cpp`](src/PresidentialPardonForm.cpp)**
   - **[`src/main.cpp`](src/main.cpp)**
   - **[`Makefile`](Makefile)**

2. **Testing Execution Constraints:**
   Compile the program and observe how the different forms enforce their unique constraints and behaviors.
   ```bash
   make
   
   ./multiForm
   
   # Output Analysis:
   # 1. Unsigned Execution Protection: A Senior bureaucrat attempts to execute a Shrubbery form but is rejected because the form hasn't been signed yet.
   # 2. Shrubbery I/O: Once successfully signed and executed, a 'Home_shrubbery' file is generated in the root directory containing ASCII trees.
   # 3. Probability: The Robotomy form is executed 4 times in a row, with the output varying between success and disaster based on std::rand().
   # 4. Strict Hierarchy: A mid-level Manager successfully signs the Presidential form but is rejected when attempting to execute it, requiring the Boss (Grade 1) to step in and successfully complete the action.
   ```
