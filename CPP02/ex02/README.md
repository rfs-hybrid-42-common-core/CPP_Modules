# 🟢 Exercise 02: Now we're talking

## 📝 Objective
Expand the `Fixed` class to behave exactly like a native C++ numeric type (such as `int` or `float`). You must overload 6 comparison operators, 4 arithmetic operators, and 4 increment/decrement operators. Finally, you must implement static `min` and `max` member functions, properly overloaded to handle both constant and non-constant references.

## 💡 The Logic

This exercise is the ultimate showcase of **Ad-Hoc Polymorphism** in C++. It proves that you can redefine how the compiler interprets standard mathematical symbols depending on the object types surrounding them.

1. **Comparison Operators (`>`, `<`, `==`, etc.):** 
   Because both objects share the same scaling factor (8 fractional bits), comparing them is as simple as comparing their raw integer bits. 
2. **Arithmetic Operators (`+`, `-`, `*`, `/`):** 
   While addition and subtraction can technically be done on the raw bits directly, multiplication and division of fixed-point numbers at the bitwise level require complex shifting to prevent overflow and precision loss. The cleanest, safest C++ approach is to convert both operands to floats (`toFloat()`), perform the standard arithmetic, and return a *new* `Fixed` object constructed from that result.
3. **Pre vs. Post Increment (`++a` vs `a++`):** 
   - **Pre-increment (`++a`):** Modifies the object's raw bits by `1` (the smallest representable epsilon in this fixed-point format) and returns a reference to itself (`*this`).
   - **Post-increment (`a++`):** Modifies the object but must return the value it held *before* the modification. To tell the C++ compiler the difference between pre and post, the post-increment signature takes a dummy `int` parameter (`Fixed operator++(int)`). It creates a temporary copy of the object, increments the original, and returns the copy.
4. **Function Overloading (`min` / `max`):** 
   Polymorphism isn't just for operators. By implementing two versions of `min` and `max`—one that takes mutable references and one that takes `const` references—the compiler automatically routes the data to the correct function based on whether the variables passed in are constant or not.

## 🛠️ Step-by-Step Solution

1. **The Code:**
   *Check out the source files here:*
   - **[`inc/Fixed.hpp`](inc/Fixed.hpp)** / **[`src/Fixed.cpp`](src/Fixed.cpp)**
   - **[`src/main.cpp`](src/main.cpp)**
   - **[`Makefile`](Makefile)**

2. **Testing Ad-Hoc Polymorphism:**
   The `main.cpp` file contains a highly comprehensive test suite covering all overloaded operators. Compile and run to verify the math and logic.
   ```bash
   make
   
   ./fixed
   
   # Output Analysis:
   # 1. Subject Tests: Verifies epsilon incrementation (0.00390625) and basic multiplication.
   # 2. Arithmetic: Verifies floating-point conversions during +, -, *, and /.
   # 3. Comparison: Uses std::boolalpha to print exact true/false boolean evaluations.
   # 4. Decrement: Proves the temporary object logic of post-decrement vs pre-decrement.
   # 5. Min/Max: Proves the compiler successfully routes to the const or non-const overload based on the variable types.
   ```
