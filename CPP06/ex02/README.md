# 🟢 Exercise 02: Identify real type

## 📝 Objective
Implement a polymorphic base class (`Base`) and three empty derived classes (`A`, `B`, and `C`). Create a function that randomly instantiates one of the derived classes and returns it as a `Base` pointer. You must then implement two identification functions—one taking a pointer, and one taking a reference—that successfully deduce the true derived type of the object at runtime without using the `<typeinfo>` header.

## 💡 The Logic

This exercise is a direct demonstration of **Run-Time Type Information (RTTI)** and the behavioral differences when using **`dynamic_cast`** on pointers versus references.

1. **Polymorphism is Mandatory:** 
   In C++, `dynamic_cast` only works on polymorphic classes. If the `Base` class does not have at least one virtual function, the compiler will not generate the Virtual Table (vtable) required to track the object's true identity at runtime. By simply declaring a `virtual ~Base(void);` destructor, the class becomes polymorphic, unlocking RTTI.
2. **Pointer Identification (`Base*`):** 
   When you use `dynamic_cast<A*>(p)` on a pointer, C++ checks the vtable. If the object is genuinely of type `A`, the cast succeeds and returns a valid pointer. If it is *not* type `A`, the cast fails safely and returns `NULL`. The logic here relies on simple `if/else` checks against `NULL`.
3. **Reference Identification (`Base&`):** 
   References in C++ are structurally guaranteed to point to a valid object—they cannot be `NULL`. Therefore, if `dynamic_cast<A&>(p)` fails, C++ has no `NULL` state to fall back on. Instead, it throws a `std::bad_cast` exception. Because the `<typeinfo>` header (which defines `std::bad_cast`) is typically forbidden in this exercise, the code polymorphically catches the standard `std::exception` in a series of `try/catch` blocks to silently pass over failed casts until the correct type is found.

## 🛠️ Step-by-Step Solution

1. **The Code:**
   *Check out the source files here:*
   - **[`inc/Base.hpp`](inc/Base.hpp)** / **[`src/Base.cpp`](src/Base.cpp)**
   - **[`inc/A.hpp`](inc/A.hpp)**
   - **[`inc/B.hpp`](inc/B.hpp)**
   - **[`inc/C.hpp`](inc/C.hpp)**
   - **[`src/main.cpp`](src/main.cpp)**
   - **[`Makefile`](Makefile)**

2. **Testing RTTI and Dynamic Casting:**
   Compile the program and observe the runtime type identification.
   ```bash
   make
   
   ./identify
   
   # Output Analysis:
   # 1. Random Generation: The program generates 5 random derived classes (e.g., A, C, B, A, C).
   # 2. Pointer Identification: The first identify() function uses if/else dynamic casting to correctly print the type without crashing.
   # 3. Reference Identification: The second identify() function uses try/catch blocks to intercept the thrown exceptions until it finds the matching reference type.
   # 4. Raw Base Fallback: The final test explicitly feeds a raw Base object into the functions. All specific dynamic_casts fail, safely defaulting to the "Unknown" fallback state.
   ```
