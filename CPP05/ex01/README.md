# 🟢 Exercise 01: Form up, maggots!

## 📝 Objective
Introduce a `Form` class with strict, immutable grade requirements for signing and executing. Update the `Bureaucrat` class to interact with these forms. The core objective is to demonstrate **Inter-Class Exception Handling**, where one object enforces state rules by throwing exceptions, and another object attempts actions by safely catching those exceptions.

## 💡 The Logic

This exercise expands exception handling beyond internal state validation and introduces cross-class interactions driven by strict access contracts.

1. **Inter-Class Exception Handling:** 
   The `Form` class dictates the rules. When `Form::beSigned(Bureaucrat)` is called, the form compares its required signature grade against the bureaucrat's current grade. If the bureaucrat is underqualified (their grade integer is mathematically higher than the required grade), the *Form* throws a `Form::GradeTooLowException`. 
2. **Graceful Rejection (`try/catch` delegation):** 
   The `Bureaucrat` class now features a `signForm(Form&)` method. Instead of manually checking grades before attempting to sign, the Bureaucrat blindly attempts the action within a `try` block (`form.beSigned(*this)`). If the Form rejects the attempt and throws an error, the Bureaucrat safely `catches` the `Form::Exception` and formats the error message (`<Bureaucrat> couldn't sign <Form> because <Exception>`).
3. **Immutable Architecture & OCF Quirks:** 
   The `Form` class is highly restrictive. Its name, grade to sign, and grade to execute are all strictly `const`. This drastically impacts the Orthodox Canonical Form. A Copy Assignment Operator (`operator=`) cannot modify `const` attributes after instantiation. Therefore, the `Form`'s assignment operator is structurally limited to *only* copying the mutable `_isSigned` boolean, leaving the core identity of the target form intact.
4. **Redundant State Protection:** 
   A custom `AlreadySignedException` is implemented to prevent redundant operations, enforcing strict bureaucratic procedure if a valid bureaucrat tries to sign an already completed form.

## 🛠️ Step-by-Step Solution

1. **The Code:**
   *Check out the source files here:*
   - **[`inc/Bureaucrat.hpp`](inc/Bureaucrat.hpp)** / **[`src/Bureaucrat.cpp`](src/Bureaucrat.cpp)**
   - **[`inc/Form.hpp`](inc/Form.hpp)** / **[`src/Form.cpp`](src/Form.cpp)**
   - **[`src/main.cpp`](src/main.cpp)**
   - **[`Makefile`](Makefile)**

2. **Testing Cross-Class Validation:**
   Compile the program and observe the interaction between the objects and their strict grade boundaries.
   ```bash
   make
   
   ./regularForm
   
   # Output Analysis:
   # 1. Form OCF constraints: During the Copy Assignment test, a Blank Form is assigned the values of a Signed Tax Form. Because the identity/grades are const, only the signature status (`_isSigned`) is transferred.
   # 2. Form Exceptions: Attempting to instantiate a Form with invalid grade boundaries (e.g., 0 or 151) safely throws the nested Form-specific exceptions.
   # 3. Inter-Class Rejection: The Intern (Grade 150) attempts to sign a Contract (Requires Grade 20). The Form throws GradeTooLowException, which the Bureaucrat catches and prints as a formal rejection.
   # 4. Redundant States: The Boss (Grade 1) successfully signs the Contract. A secondary attempt safely throws the AlreadySignedException.
   ```
