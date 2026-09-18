# 🟢 Exercise 01: Iter

## 📝 Objective
Implement a function template `iter` that takes 3 parameters and returns nothing. The parameters must strictly be: the address of an array, the length of the array (passed as a `const` value), and a function that will be called on every element of the array. Your `iter` function template must work with any type of array, and the third parameter can be an instantiated function template. A core requirement is that you must carefully support both `const` and non-`const` elements.

## 💡 The Logic

This exercise expands generic programming from simple localized operations to traversing and manipulating entire data structures, emphasizing **const-correctness** and **function pointer deduction**.

1. **Generic Array Traversal:** 
   The `iter` function acts as a type-agnostic `forEach` loop. It takes a pointer to the start of an array (`T* addr`) and iterates through it, applying a given behavior to each index.
2. **Double Template Parameters (`typename T, typename F`):** 
   To gracefully handle the `const` and non-`const` requirement, the template does not hardcode the function pointer signature. By declaring the callable function as its own template type (`typename F`), the C++ compiler dynamically deduces the exact signature of the function passed in. This seamlessly allows `iter` to accept both mutating functions (e.g., `void (*)(T&)` ) and strictly read-only functions (e.g., `void (*)(T const &)`).
3. **Compile-Time Safety:** 
   If a programmer attempts to pass a mutation function (`incrementElement<int>`) alongside a `const` array, the compiler will catch the mismatch during template instantiation and throw a compile-time error, ensuring the architectural integrity of constant data.

## 🛠️ Step-by-Step Solution

1. **The Code:**
   *Check out the source files here:*
   - **[`inc/iter.hpp`](inc/iter.hpp)**
   - **[`src/main.cpp`](src/main.cpp)**
   - **[`Makefile`](Makefile)**

2. **Testing Generic Iteration:**
   Compile the program and observe how the single `iter` template maps different functions across different array types.
   ```bash
   make
   
   ./iter
   
   # Output Analysis:
   # 1. Non-Const Array: The iter function successfully maps a read-only print function, followed by a mutating increment function, and prints the modified array.
   # 2. Const Array: The template deduces the const array and successfully maps the generic print function. (Uncommenting the increment attempt in main.cpp proves that the compiler blocks illegal mutations).
   # 3. String Array: The iter template demonstrates its genericity by traversing an array of complex std::string objects.
   ```
