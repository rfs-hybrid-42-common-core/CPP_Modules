*This project has been created as part of the 42 curriculum by maaugust.*

<div align="center">
  <img src="https://raw.githubusercontent.com/rfs-hybrid/42-Common-Core/main/assets/covers/cover-cpp08.png" alt="CPP 08 Cover" width="100%" />
</div>

<div align="center">
  <h1>💻 CPP 08: Templated containers, iterators, algorithms</h1>
  <p><i>The Standard Template Library (STL), container adapters, and generic algorithms.</i></p>
  <img src="https://img.shields.io/badge/Language-C++98-blue" alt="Language badge" />
  <img src="https://img.shields.io/badge/Grade-100%2F100-success" alt="Grade badge" />
  <br />
</div>

---

## 💡 Description
**CPP 08** unlocks the Standard Template Library (STL). Up until now, the curriculum has strictly forbidden the use of standard containers and algorithms to force a deep understanding of manual memory management. This module flips the script: it explicitly requires the use of STL containers, iterators, and `<algorithm>` headers wherever appropriate.

The exercises focus on navigating templated containers using iterators, applying generic algorithms to calculate data metrics, and exploiting inheritance to mutate restricted container adapters. As always, the codebase strictly complies with the **C++98 standard**.

---

## 🧠 Exercise Breakdown & Logic

*The following section explains the core concepts required to solve each exercise, focusing entirely on STL mechanics and iterator manipulation.*

### 🔹 STL Algorithms & Generic Searching
| Exercise | Concept & Logic |
| :--- | :--- |
| **[`ex00: Easy find`](ex00)** | **`std::find` & Iterators:** Searching through generic containers.<br><br>**Logic:** You must write a function template `easyfind` that accepts a container of integers `T` and an integer to find. The objective is to find the first occurrence of the integer within the container. Instead of writing a manual loop, the logic relies on standard STL algorithms (like `std::find`) combined with the container's iterators. If the occurrence is not found, the function must throw an exception. Associative containers do not need to be handled for this exercise. |

### 🔹 Containers & Range Iteration
| Exercise | Concept & Logic |
| :--- | :--- |
| **[`ex01: Span`](ex01)** | **Data Metrics & Iterator Ranges:** Calculating distances across large datasets.<br><br>**Logic:** Develop a `Span` class that stores a maximum of `N` integers, passed to the constructor as an `unsigned int`. You must implement an `addNumber()` method that throws an exception if the span is already full. The `shortestSpan()` and `longestSpan()` methods calculate the smallest and largest distances between the stored numbers, throwing exceptions if there are fewer than two elements available. To efficiently fill the span without making thousands of individual calls, you must also implement a function that adds multiple numbers in a single call using a range of iterators. |

### 🔹 Container Adapters & Inheritance
| Exercise | Concept & Logic |
| :--- | :--- |
| **[`ex02: Mutated abomination`](ex02)** | **Bypassing Adapter Restrictions:** Making a stack iterable.<br><br>**Logic:** The `std::stack` is a container adapter—it intentionally restricts access to only the top element and is explicitly NOT iterable. You must write a `MutantStack` class implemented in terms of a `std::stack` that repairs this by adding iterators. By inheriting from `std::stack`, your class gains access to the underlying protected container (usually a `std::deque`), allowing you to expose its `begin()` and `end()` iterators to the user while maintaining all original stack functionalities. |

---

## 🛠️ Instructions

### 🧪 Compilation & Execution
Each directory contains its own `Makefile` containing the standard rules (`all`, `clean`, `fclean`, `re`).

All programs are strictly compiled with the C++98 standard and standard error flags: 
`c++ -Wall -Wextra -Werror -std=c++98`

1. **Navigate to the specific exercise directory:**
   ```bash
   cd ex00
   ```

2. **Compile the program:**
   Use the provided `Makefile` to compile the source code into an executable.
   ```bash
   make
   ```

3. **Run the executable:**
   ```bash
   ./<executable_name>
   ```

4. **Clean up binary files:**
   ```bash
   make fclean
   ```

---

## 📚 Resources & References

### General C++ Documentation
* **[cplusplus.com: STL Containers](https://cplusplus.com/reference/stl/)** - The definitive overview of Sequence Containers (`vector`, `list`, `deque`) and Container Adapters (`stack`, `queue`).
* **[cplusplus.com: <algorithm>](https://cplusplus.com/reference/algorithm/)** - Comprehensive reference for STL algorithms like `std::find`, `std::min_element`, and `std::sort`.
* **[Medium: C++ STL Containers Guide](https://medium.com/@avinashyadav16/c-stl-containers-f8bdb4b64768)** - A robust deep-dive into how data is stored under the hood.
* **[GeeksforGeeks: Containers in C++ STL](https://www.geeksforgeeks.org/cpp/containers-cpp-stl/)** - Detailed overview contrasting sequential, associative, and unordered containers.
* **[GeeksforGeeks: Iterators in C++](https://www.geeksforgeeks.org/iterators-c-stl/)** - A clear breakdown of how iterators bridge the gap between containers and algorithms.
* **[GeeksforGeeks: std::vector in C++](https://www.geeksforgeeks.org/cpp/vector-in-cpp-stl/)** - Covers dynamic arrays and contiguous memory blocks, crucial for building the `Span` class in `ex01`.
* **[GeeksforGeeks: std::deque in C++](https://www.geeksforgeeks.org/cpp/deque-cpp-stl/)** - Explains the double-ended queue, which is the default underlying container inside a standard stack.
* **[GeeksforGeeks: std::list in C++](https://www.geeksforgeeks.org/cpp/list-cpp-stl/)** - Detailed overview of doubly-linked lists.
* **[GeeksforGeeks: std::stack in C++](https://www.geeksforgeeks.org/cpp/stack-in-cpp-stl/)** - Crucial documentation explaining LIFO architecture and the adapter constraints bypassed in `ex02`.
* **[Medium: Vectors in C++, The Complete Guide](https://medium.com/@gayakk/vectors-in-c-the-complete-guide-88e7e184215b)** - A deep dive into vector manipulation, reallocation, and best practices.

### CodeLucky & Visual Tutorials
* **[C++ STL Algorithms: Sorting, Searching & More!](https://www.youtube.com/watch?v=CxSkCkcPP1w)** - Essential for `ex00` and `ex01`, illustrating how to correctly implement `std::find`, `std::sort`, and bounds searching.
* **[C++ STL Containers Explained for Beginners](https://www.youtube.com/watch?v=nx3Mpy1X-kk)** - A great foundational guide that breaks down the structural differences and performance constraints of vectors, lists, and deques.
* **[C++ STL for Beginners: Containers, Algorithms, and Iterators!](https://www.youtube.com/watch?v=9ubwYU8a8hg)** - A holistic overview showing how containers, iterators, and `<algorithm>` headers link together.
* **[C++ Iterators Explained: STL Containers & Traversal](https://www.youtube.com/watch?v=PVMpMRIfb-U)** - A critical guide to navigating iterator categories, accessing elements, and avoiding catastrophic iterator invalidation.
* **[C++ Vectors: Dynamic Arrays & STL Explained](https://www.youtube.com/watch?v=S7q4cdh7Mds)** - Highly relevant for `ex01`, demonstrating bulk data insertion using `insert` and iterator ranges.
* **[C++ Stacks: LIFO Data Structures Explained](https://www.youtube.com/watch?v=Fba0VA7G45Q)** - Breaks down the exact `std::stack` architecture and adapter limitations that you must mutate in `ex02`.
* **[C++ Exception Handling: Try, Catch, and Throw for Beginners!](https://www.youtube.com/watch?v=vP8ERWZEpGA)** - Highly relevant for `ex01`, illustrating how to throw and polymorphically catch exceptions like `std::out_of_range` or custom `Span::Exception`s when pushing datasets beyond maximum capacity.
* **[C++ Random Numbers: Modern Generation Techniques](https://www.youtube.com/watch?v=AKYcfRf-GNk)** - Bonus resource covering modern pseudo-random number generation, which is extremely useful for generating 10,000+ random numbers for your `Span` tests in `ex01`.

---

### 🤖 AI Usage Guidelines
* **Code:** No AI-generated code was used to solve these exercises. All generic templates, algorithm implementations, and container mutations were constructed manually to ensure strict compliance with C++98 STL rules.
* **Documentation:** AI tools were utilized to structure this `README.md`, extract the core logic for the distinct STL components, and translate the architectural requirements into an educational portfolio format.
