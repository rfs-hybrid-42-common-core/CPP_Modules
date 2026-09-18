# 🟢 Exercise 00: Conversion of scalar types

## 📝 Objective
Write a class `ScalarConverter` containing a single static method `convert` that takes a string representation of a C++ literal and outputs its value in `char`, `int`, `float`, and `double` formats. The conversion must be handled explicitly. If a conversion does not make sense or overflows, it must display a message informing the user that the type conversion is impossible. It must robustly handle mathematical overflows, non-displayable characters, and special pseudo-literals (e.g., `-inff`, `nan`).

## 💡 The Logic

This exercise transitions us away from the blind memory overwrites of C-style casting (`(int)value`) to the much safer, compile-time checked **`static_cast`** of modern C++. 

1. **Static Utility Architecture:** 
   The `ScalarConverter` is designed as a purely static utility class that must not be instantiable by users. To enforce this architecture, the Orthodox Canonical Form (constructors, copy constructors, assignment operators, and destructor) is entirely hidden inside the `private` scope. 
2. **Robust Parsing (`std::strtod`):** 
   C-style parsers like `atoi` or `atof` are unsafe because they silently fail or return `0` on invalid inputs. Instead, the program uses `std::strtod`, which maps mathematical overflows using `errno` (`ERANGE`) and provides an `endptr` to detect trailing garbage characters, ensuring the literal is strictly valid before any casting occurs.
3. **`static_cast` Navigation:** 
   Once the string is successfully identified and parsed into a baseline `double` (the most precise scalar type), the program utilizes `static_cast<char>()`, `static_cast<int>()`, and `static_cast<float>()` to navigate the type hierarchy. 
4. **Precision & Limits:** 
   A massive portion of scalar conversion involves boundary checking. The program leverages `<limits>` (`std::numeric_limits`) to check if the parsed `double` exceeds the maximum capacity of an `int` or `char`. If it does, the C++ cast is bypassed entirely, and an "impossible" flag is printed to prevent silent integer overflow errors.
5. **Pseudo-literals:** 
   Floating-point math includes special states for undefined or infinite numbers. The program explicitly intercepts `nan`, `inf`, `-inf`, and their `float` variants (`nanf`, `-inff`) to print them seamlessly across the `float` and `double` tiers while flagging `char` and `int` as mathematically impossible.

## 🛠️ Step-by-Step Solution

1. **The Code:**
   *Check out the source files here:*
   - **[`inc/ScalarConverter.hpp`](inc/ScalarConverter.hpp)** / **[`src/ScalarConverter.cpp`](src/ScalarConverter.cpp)**
   - **[`src/main.cpp`](src/main.cpp)**
   - **[`Makefile`](Makefile)**

2. **Testing Conversions:**
   Compile the program and observe how the specific scalar tiers behave across edge cases.
   ```bash
   make
   
   # Standard Integer Conversion
   ./scalarConverter 42
   # char: '*'
   # int: 42
   # float: 42.0f
   # double: 42.0
   
   # Boundary Overflow (Double is valid, Int/Char overflow)
   ./scalarConverter 5000000000
   # char: impossible
   # int: impossible
   # float: 5000000000.0f
   # double: 5000000000.0
   
   # Pseudo-literals
   ./scalarConverter nan
   # char: impossible
   # int: impossible
   # float: nanf
   # double: nan
   
   # Character Conversion
   ./scalarConverter "'a'"
   # char: 'a'
   # int: 97
   # float: 97.0f
   # double: 97.0
   ```
