# 🟢 Exercise 00: Start with a few functions

## 📝 Objective
Implement the function templates `swap`, `min`, and `max`. These functions can be called with any type of argument, provided the two arguments share the same type and support all necessary comparison operators. If `min` or `max` evaluate two equal values, they must return the second parameter. All templates must be defined directly in the header files.

## 💡 The Logic

This exercise introduces the syntax and mechanics of C++ Function Templates, allowing you to write a single generic logic block that the compiler adapts to any data type.

1. **Header-Only Implementation:** 
   Templates are not actual functions; they are blueprints. Because the compiler needs to see the full blueprint to generate the specific type instances at compile-time, function templates must be defined entirely within the header file (`whatever.hpp`) rather than a `.cpp` file.
2. **References and Memory Efficiency:** 
   To ensure the functions work optimally with complex objects (like large strings or classes), `swap` takes arguments by reference (`T&`) to actively modify the original variables. `min` and `max` take arguments by constant reference (`T const &`) to prevent expensive deep copies, and return a constant reference back to the caller.
3. **Ternary Operator & The Equality Rule:** 
   The requirements state that if the values are equal, the second one must be returned. By using the ternary operator `x < y ? x : y`, if `x` and `y` are equal, the condition evaluates to `false`, naturally defaulting to `y` (the second parameter).
4. **Implicit Requirements (Operator Overloading):** 
   While the templates accept *any* type, the operations inside them (`<`, `>`, `=`) dictate the requirements. In `main.cpp`, a custom `Test` class is instantiated to prove this. For the compiler to successfully generate a `min(Test, Test)` function, the `Test` class must explicitly overload its comparison operators.

## 🛠️ Step-by-Step Solution

1. **The Code:**
   *Check out the source files here:*
   - **[`inc/whatever.hpp`](inc/whatever.hpp)**
   - **[`src/main.cpp`](src/main.cpp)**
   - **[`Makefile`](Makefile)**

2. **Testing Generic Capabilities:**
   Compile the program and observe the mandatory string and integer tests, followed by the custom class tests verifying the equality rule.
   ```bash
   make
   
   ./whatever
   
   # Output Analysis:
   # 1. Mandatory Tests: The swap, min, and max templates successfully compile and execute for both standard integers and std::string objects, producing the exact output required by the subject.
   # 2. Custom Complex Type: A custom Test<T> class is passed into the generic functions, proving that as long as the operators are overloaded, the templates function flawlessly.
   # 3. Equality Edge Case: To definitively prove that the second argument is returned when two values are equal, the program compares the memory addresses of the inputs and the output.
   ```
