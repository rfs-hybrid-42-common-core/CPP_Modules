# 🟢 Exercise 02: PmergeMe

## 📝 Objective
Implement the Ford-Johnson Merge-Insert sort algorithm to organize a sequence of positive integers. The algorithm must be executed using at least two different STL sequence containers (`std::vector` and `std::deque`), and the program must benchmark and display the microsecond execution time of both structures. The sequence must be rigorously validated to ensure no negative numbers, hardware overflows, or duplicate values exist before sorting begins.

## 💡 The Logic

This exercise tackles one of the most complex sorting algorithms in computer science, requiring advanced iterator manipulation, mathematical boundary generation, and precise STL container benchmarking.

1. **The Ford-Johnson Algorithm (Merge-Insert Sort):** 
   This algorithm is designed to minimize the total number of comparisons. It achieves this in two distinct phases:
   - **Recursive Pairing (Merge):** The sequence is grouped into pairs (memory chunks). The "winners" (the larger elements) of each pair are pushed to a `mainChain`, and the "losers" are placed in a `pendChain`. This pairing happens recursively until the base elements are fully chunked and evaluated.
   - **Binary Search Insertion:** The remaining elements in the `pendChain` are inserted into the sorted `mainChain` using `std::lower_bound` logic.
2. **The Jacobsthal Sequence:** 
   To strictly adhere to Donald Knuth's optimal comparison budget, the elements from the `pendChain` cannot be inserted linearly. Instead, they are inserted in specific batches dictated by the Jacobsthal sequence (3, 5, 11, 21, etc.). This dynamically restricts the binary search space to powers of two (`(1 << batch_k) - 1`), mathematically guaranteeing the absolute minimum number of comparisons in the worst-case scenario.
3. **Template Architecture & Memory Chunking:** 
   Instead of writing redundant logic for both containers, `_fordJohnsonMergeInsert` and `_jacobsthalInsert` are implemented as templates inside `PmergeMe.tpp`. The algorithm uses a sophisticated `chunk_size` multiplier and `std::swap_ranges` to sort adjacent memory blocks in place. This allows the exact same code to seamlessly process both a contiguous `std::vector` and a fragmented `std::deque`.
4. **Duplicate Verification (`std::set`):** 
   During the parsing phase, a `std::set` is temporarily instantiated. Because sets inherently reject duplicate values and organize data via a binary search tree, attempting to insert every parsed token into the set acts as a highly efficient $O(N \log N)$ uniqueness filter before the heavy sorting begins.
5. **CPU Benchmarking (`<ctime>`):** 
   To measure execution times accurately across different hardware, the program utilizes the `clock()` function. This measures raw CPU cycles rather than real-world wall time, neutralizing arbitrary OS scheduling delays.

## 🛠️ Step-by-Step Solution

1. **The Code:**
   *Check out the source files here:*
   - **[`inc/PmergeMe.hpp`](inc/PmergeMe.hpp)** / **[`inc/PmergeMe.tpp`](inc/PmergeMe.tpp)** / **[`src/PmergeMe.cpp`](src/PmergeMe.cpp)**
   - **[`src/main.cpp`](src/main.cpp)**
   - **[`Makefile`](Makefile)**

2. **Testing the Merge-Insert Sort:**
   Compile the program and provide an unsorted sequence of positive integers to benchmark the STL containers.
   ```bash
   make
   
   ./PmergeMe 3 5 9 7 4
   
   # Output Analysis:
   # 1. Parsing & Validation: The sequence is stripped of formatting, checked for duplicates via std::set, and loaded into both the vector and deque.
   # 2. Before/After State: The raw sequence is printed, followed by the successfully sorted sequence.
   # 3. Execution Benchmarks: The program outputs the microsecond processing time (including data management overhead) for both std::deque and std::vector.
   # 4. Error Handling: Providing negatives, duplicates (e.g., "4 2 4"), or out-of-bounds integers safely triggers polymorphic custom exceptions without crashing.
   ```
