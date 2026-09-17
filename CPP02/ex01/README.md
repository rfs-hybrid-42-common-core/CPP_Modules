# 🟢 Exercise 01: Towards a more useful fixed-point number class

## 📝 Objective
Expand the `Fixed` class to accept and convert constant integers and floating-point numbers into fixed-point representations. You must also implement functions to convert the fixed-point value back to `int` and `float`, and overload the insertion operator (`<<`) to allow direct printing via standard output streams.

## 💡 The Logic

This exercise introduces the actual mathematical mechanics behind fixed-point numbers and your first true Operator Overload.

1. **Integer Conversions (Bit Shifting):** 
   To convert an integer to a fixed-point value, we shift its bits to the left by the number of fractional bits (`n << _bits`). Since `_bits` is 8, this effectively multiplies the integer by $2^8$ (256). To convert it back to a standard integer (`toInt()`), we simply shift the bits back to the right (`_n >> _bits`), which truncates the fractional part.
2. **Floating-Point Conversions (`roundf`):** 
   Floating-point numbers cannot be directly bit-shifted. Instead, to convert a `float` to fixed-point, we multiply the float by the scaling factor ($2^8$ or `1 << _bits`) and use the `roundf()` function from `<cmath>` to round the result to the nearest whole integer. To convert back (`toFloat()`), we divide the raw integer value by the scaling factor cast to a float (`_n / static_cast<float>(1 << _bits)`).
3. **Non-Member Operator Overloading (`<<`):** 
   If you try to type `std::cout << a;` where `a` is a custom `Fixed` object, the compiler throws an error because it doesn't know how to format your class. We fix this by overloading the `<<` operator. 
   - Because the left-hand operand is an `std::ostream` object (not our `Fixed` class), this overload must be defined as a **non-member function** outside of the class scope. 
   - The function takes the output stream and the `Fixed` object as parameters, passes the `.toFloat()` value into the stream, and crucially returns the stream reference (`std::ostream&`) so that multiple insertions can be chained together (e.g., `std::cout << a << b;`).

## 🛠️ Step-by-Step Solution

1. **The Code:**
   *Check out the source files here:*
   - **[`inc/Fixed.hpp`](inc/Fixed.hpp)** / **[`src/Fixed.cpp`](src/Fixed.cpp)**
   - **[`src/main.cpp`](src/main.cpp)**
   - **[`Makefile`](Makefile)**

2. **Testing the Conversions:**
   Compile the program and observe the output to verify that precision is maintained during conversions.
   ```bash
   make
   
   ./fixed
   
   # Output Analysis:
   # 1. The constructors correctly process ints and floats.
   # 2. When printed directly using '<<', the overloaded operator catches the object and prints its float representation (e.g., 1234.43, 42.4219).
   # 3. When toInt() is called, the fractional data is cleanly truncated (e.g., 42.4219 becomes 42).
   ```
