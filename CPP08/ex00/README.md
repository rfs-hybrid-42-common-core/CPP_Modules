# 🟢 Exercise 00: Easy find

## 📝 Objective
Write a function template `easyfind` that accepts a generic container of integers (`T`) and an integer value to find (`n`). The function must locate the first occurrence of the integer within the container and return an iterator pointing to it. If the occurrence is not found, the function must actively throw an exception.

## 💡 The Logic

This exercise forces the transition from manual, C-style array iterations to modern, optimized C++ **Algorithms** and **Iterators**.

1. **The `<algorithm>` Header:** 
   Instead of writing a manual `for` or `while` loop to traverse the container, the function leverages `std::find(container.begin(), container.end(), n)`. This standard library algorithm is highly optimized and abstracts away the underlying traversal mechanics, operating purely on iterators.
2. **Dependent Types (`typename`):** 
   When declaring the return type as `T::iterator`, the compiler does not inherently know if `iterator` is a static member variable of `T` or a nested type. The `typename` keyword must be explicitly prepended (`typename T::iterator`) to inform the compiler that it is dealing with a dependent data type.
3. **Const-Correctness:** 
   The template is overloaded to handle both mutable containers (returning a standard `iterator` that allows modification of the found element) and `const` containers (returning a strictly read-only `const_iterator`).
4. **Duck Typing & Implicit Casts:** 
   Because templates rely on duck typing, `easyfind` doesn't strictly check if the container is *actually* full of integers. As proven in the tests, if you pass a `std::vector<char>` and search for the integer `98`, C++ will implicitly cast the characters to integers during `std::find` comparisons, successfully returning the iterator for `'b'`.

## 🛠️ Step-by-Step Solution

1. **The Code:**
   *Check out the source files here:*
   - **[`inc/easyfind.hpp`](inc/easyfind.hpp)** / **[`inc/easyfind.tpp`](inc/easyfind.tpp)**
   - **[`src/main.cpp`](src/main.cpp)**
   - **[`Makefile`](Makefile)**

2. **Testing Generic Searches:**
   Compile the program and observe how the single `easyfind` template operates across vectors, lists, deques, and constant containers.
   ```bash
   make
   
   ./easyfind
   
   # Output Analysis:
   # 1. Sequence Containers: Successfully finds and mutates elements in std::vector, std::list, and std::deque.
   # 2. Exception Handling: Properly throws a std::runtime_error when the requested value is not found, avoiding iterator out-of-bounds crashes.
   # 3. Const-Correctness: Successfully deduces a std::vector const_iterator for read-only searching.
   # 4. Edge Cases: Handles empty containers (immediate exception) and duplicate values (returns the first occurrence).
   # 5. Implicit Casting: Searches a std::vector<char> for an int, successfully returning the ASCII equivalent.
   ```
