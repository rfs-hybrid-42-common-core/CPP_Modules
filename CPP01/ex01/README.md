# 🟢 Exercise 01: Moar brainz!

## 📝 Objective
Write a function `zombieHorde` that allocates an array of `N` Zombie objects in a single allocation. It must initialize each zombie with a name and return a pointer to the first zombie in the array. Finally, you must ensure all zombies are destroyed without memory leaks.

## 💡 The Logic

This exercise expands on dynamic memory by introducing **Array Allocation**. It forces you to understand the relationship between arrays, default constructors, and specific `delete` operators.

1. **Array Allocation (`new[]`):** To allocate a contiguous block of memory for multiple objects, C++ uses the `new[]` operator (e.g., `new Zombie[N]`). 
2. **The Default Constructor Constraint:** When you use `new[]` to allocate an array of objects in C++98, you *cannot* pass parameters to their constructors. The compiler will automatically call the **Default Constructor** (`Zombie(void)`) for every single object in the array. Because of this, the zombies are created without names. We must iterate through the newly created array and use a setter method (`setName()`) to initialize their data post-allocation.
3. **C++98 String Conversions:** To make the horde recognizable, the program appends a number to each zombie's name (e.g., "Heap 1", "Heap 2"). Because `std::to_string()` is forbidden (it's a C++11 feature), the code uses `std::stringstream` from the `<sstream>` library to safely convert integers into strings.
4. **Array Deallocation (`delete[]`):** This is the most critical lesson of the exercise. If you allocate memory using `new[]`, you **must** free it using `delete[]`. Using standard `delete` on an array is undefined behavior and will cause a memory leak, as it will only call the destructor for the very first object in the array.
5. **Defensive Programming:** The `main` function rigorously tests edge cases, such as passing a negative `N` value. It uses `try/catch` blocks to capture `std::bad_alloc` exceptions if the system fails to allocate a massive horde.

## 🛠️ Step-by-Step Solution

1. **The Code:**
   *Check out the source files here:*
   - **[`inc/Zombie.hpp`](inc/Zombie.hpp)** / **[`src/Zombie.cpp`](src/Zombie.cpp)**
   - **[`src/zombieHorde.cpp`](src/zombieHorde.cpp)**
   - **[`src/main.cpp`](src/main.cpp)**
   - **[`Makefile`](Makefile)**

2. **Testing Allocations & Edge Cases:**
   Compile the program and observe how the horde is generated and safely destroyed.
   ```bash
   make
   ./horde
   
   # Output Analysis:
   # 1. Tests an empty base string (creates "Zombie 1", "Zombie 2", etc.).
   # 2. Tests N = -10 (Gracefully fails and returns NULL, avoiding segfaults).
   # 3. Tests N = 10 (Creates "Heap 1" through "Heap 10", announces them, and destroys them).
   ```

3. **Verifying Array Memory:**
   Run Valgrind to ensure your `delete[]` call successfully wiped the entire array.
   ```bash
   valgrind --leak-check=full ./horde
   # Expected: All heap blocks were freed -- no leaks are possible.
   ```
