# 🟢 Exercise 01: Serialization

## 📝 Objective
Implement a class `Serializer`, which will not be initializable by the user in any way. It must contain a static method `uintptr_t serialize(Data* ptr);` that takes a pointer and converts it to the unsigned integer type `uintptr_t`. It must also contain a static method `Data* deserialize(uintptr_t raw);` that takes an unsigned integer parameter and converts it to a pointer to `Data`. You must create a non-empty `Data` structure, use `serialize()` on its address, pass the return value to `deserialize()`, and ensure the return value compares equal to the original pointer.

## 💡 The Logic

This exercise explores bypassing C++'s standard type safety to directly manipulate memory addresses as raw numerical data using **`reinterpret_cast`**.

1. **The `reinterpret_cast` Operator:** 
   Standard casts (like `static_cast`) refuse to convert a pointer into an integer because they are fundamentally different types with no semantic relationship. `reinterpret_cast` bypasses this safety net. It explicitly tells the compiler to treat the sequence of bits representing the pointer as a raw integer, and vice versa. This is crucial for low-level tasks like network packet serialization, hardware memory mapping, or binary file writing.
2. **The `uintptr_t` Type:** 
   To safely store a memory address as an integer, you cannot just use a standard `int`, as a 64-bit memory address will overflow a 32-bit `int`. `uintptr_t` (from `<stdint.h>`) is an unsigned integer type specifically guaranteed to be large enough to hold a pointer on the executing architecture.
3. **Static Utility Architecture:** 
   Just like `ex00`, the `Serializer` class must not be initializable by the user in any way. The Orthodox Canonical Form (constructors, copy constructor, assignment operator, and destructor) is forced into the `private` scope, creating a purely static, state-free utility class.
4. **Data Integrity Verification:** 
   A `Data` structure is implemented containing a `char`, an `int`, a `float`, and a `std::string`. The goal is to prove that reinterpreting a pointer back and forth does not truncate, alter, or corrupt the underlying payload—even for complex, dynamically allocated objects like `std::string`.

## 🛠️ Step-by-Step Solution

1. **The Code:**
   *Check out the source files here:*
   - **[`inc/Data.hpp`](inc/Data.hpp)**
   - **[`inc/Serializer.hpp`](inc/Serializer.hpp)** / **[`src/Serializer.cpp`](src/Serializer.cpp)**
   - **[`src/main.cpp`](src/main.cpp)**
   - **[`Makefile`](Makefile)**

2. **Testing Serialization Integrity:**
   Compile the program and observe the hexadecimal and decimal breakdown of the memory address, followed by the rigorous integrity checks.
   ```bash
   make
   
   ./serializer
   
   # Output Analysis:
   # 1. Address Extraction: The program extracts the Data object's address (e.g., 0x7ffee211fa48).
   # 2. Serialization: reinterpret_cast successfully maps the pointer bits into a uintptr_t without compiler errors.
   # 3. Deserialization: The raw integer is cast back into a Data* pointer.
   # 4. Integrity Checks: The program verifies that the deserialized pointer is an exact match to the original address, and that the char, int, float, and string members survived the process unharmed.
   ```
