# 🟢 Exercise 01: Span

## 📝 Objective
Develop a `Span` class capable of storing a maximum of `N` integers. The class must provide a method to add a single number, as well as functions to calculate the `shortestSpan` and `longestSpan` (the minimum and maximum distances between any two numbers stored). Additionally, you must implement a templated member function to add a massive sequence of numbers in a single call using a range of iterators, safely throwing exceptions when capacity or logic bounds are violated.

## 💡 The Logic

This exercise forces the transition away from manual loops and raw arrays toward **STL Containers, Algorithms, and Iterator Ranges**. 

1. **Underlying Container (`std::vector`):** 
   The `Span` class encapsulates a `std::vector<int>`. In the parameterized constructor, `std::vector::reserve(N)` is strategically called. This pre-allocates the underlying memory for the maximum capacity, preventing expensive dynamic reallocations as the container fills up with thousands of elements.
2. **Template Member Functions (`addNumbers`):** 
   Instead of writing thousands of individual `addNumber()` calls, the class features a template method `addNumbers(Iterator begin, Iterator end)`. By templating the iterators, this function accepts ranges from *any* STL container (e.g., `std::list`, `std::deque`, or `std::vector`). It calculates the required space using `std::distance`, checks capacity, and performs a highly optimized bulk insertion using `_numbers.insert()`.
3. **STL Algorithms for Data Metrics:** 
   - **`longestSpan`:** Utilizes `std::min_element` and `std::max_element` from the `<algorithm>` header to find the lowest and highest values in linear $O(N)$ time without modifying the underlying vector.
   - **`shortestSpan`:** Creates a local copy of the vector and uses `std::sort` ($O(N \log N)$ time). It then iterates through the adjacent elements to find the absolute smallest gap. A hardware-level optimization is included to break the loop instantly if a span of `0` is found, as a span cannot be mathematically smaller than zero.
4. **Polymorphic Exception Handling:** 
   The class defines a base `Span::Exception` (inheriting from `std::exception`) and a derived `NoSpanFoundException`. This allows the caller to catch specific logical errors (like calculating spans on empty vectors) or generic standard errors (`std::out_of_range` on overflow) gracefully.

## 🛠️ Step-by-Step Solution

1. **The Code:**
   *Check out the source files here:*
   - **[`inc/Span.hpp`](inc/Span.hpp)** / **[`src/Span.cpp`](src/Span.cpp)**
   - **[`src/main.cpp`](src/main.cpp)**
   - **[`Makefile`](Makefile)**

2. **Testing STL Operations:**
   Compile the program and observe the execution of bulk iterations, custom exceptions, and the 15,000+ number stress tests.
   ```bash
   make
   
   ./span
   
   # Output Analysis:
   # 1. Subject Test: Correctly identifies the shortest span (2) and longest span (14) from the mandated example.
   # 2. Edge Cases: Properly throws custom exceptions when attempting to calculate spans with 0 or 1 elements, and throws std::out_of_range when exceeding capacity.
   # 3. Iterator Template: Successfully bulk-inserts elements from completely different containers (std::list and std::deque) into the internal vector.
   # 4. Stress Tests: Effortlessly ingests 15,000 random integers and calculates the span distances in fractions of a second, proving algorithmic efficiency.
   # 5. OCF Compliance: Confirms deep copying capabilities; altering an original Span does not corrupt the copied or assigned versions.
   ```
