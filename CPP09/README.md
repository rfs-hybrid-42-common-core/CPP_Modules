*This project has been created as part of the 42 curriculum by maaugust.*

<div align="center">
  <img src="https://raw.githubusercontent.com/rfs-hybrid/42-Common-Core/main/assets/covers/cover-cpp09.png" alt="CPP 09 Cover" width="100%" />
</div>

<div align="center">
  <h1>💻 CPP 09: STL in Practice</h1>
  <p><i>Real-world data processing, Reverse Polish Notation, and the Ford-Johnson algorithm.</i></p>
  <img src="https://img.shields.io/badge/Language-C++98-blue" alt="Language badge" />
  <img src="https://img.shields.io/badge/Grade-100%2F100-success" alt="Grade badge" />
  <br />
</div>

---

## 💡 Description
**CPP 09** is the final boss of the C++ curriculum. It tests your ability to select and apply the optimal Standard Template Library (STL) containers and algorithms to solve complex, real-world data processing and algorithmic challenges. 

Each exercise mandates the use of specific, distinct STL containers to demonstrate a deep understanding of their unique performance characteristics, time complexities, and memory architectures. The module spans parsing historical financial data, evaluating mathematical expressions via stack operations, and implementing one of the most highly optimized sorting algorithms in computer science. As always, the codebase strictly complies with the **C++98 standard**.

---

## 🧠 Exercise Breakdown & Logic

*The following section explains the core concepts required to solve each exercise, focusing entirely on STL container selection and algorithmic logic.*

### 🔹 Financial Data Parsing & Search Trees
| Exercise | Concept & Logic |
| :--- | :--- |
| **[`ex00: Bitcoin Exchange`](ex00)** | **`std::map`:** Relational data mapping and bound searching.<br><br>**Logic:** You must write a program that calculates the value of a certain amount of Bitcoin on a given date. It ingests a CSV database of historical exchange rates and evaluates a secondary input file of dates and values. Because dates inherently form a chronological, sortable hierarchy, a `std::map` (usually implemented as a Red-Black Tree) is the perfect container. It naturally sorts the string-based dates as keys and allows for logarithmic $O(\log N)$ lookups using `std::map::lower_bound` to find the closest preceding date when an exact match isn't available. |

### 🔹 Mathematical Evaluation & Container Adapters
| Exercise | Concept & Logic |
| :--- | :--- |
| **[`ex01: Reverse Polish Notation`](ex01)** | **`std::stack` (backed by `std::list`):** LIFO sequence processing.<br><br>**Logic:** Evaluates mathematical expressions formatted in Reverse Polish Notation (RPN). A stack is the universally accepted data structure for RPN: numbers are pushed onto the top, and when an operator (`+`, `-`, `*`, `/`) is encountered, the top two numbers are popped, evaluated, and the result is pushed back. To demonstrate the flexibility of STL container adapters, the `std::stack`'s default underlying container (`std::deque`) was explicitly replaced with a `std::list`, proving that adapters can safely wrap any sequence container that supports `push_back` and `pop_back`. |

### 🔹 Algorithmic Complexity & Sort Benchmarking
| Exercise | Concept & Logic |
| :--- | :--- |
| **[`ex02: PmergeMe`](ex02)** | **`std::vector`, `std::deque`, & `std::set`:** Ford-Johnson Algorithm (Merge-Insert Sort).<br><br>**Logic:** Implements the highly complex Ford-Johnson algorithm to sort a sequence of positive integers. The strict requirement is to process the dataset using at least two different sequence containers (`std::vector` and `std::deque`) and benchmark their microsecond execution times. The logic involves grouping elements into pairs, sorting the larger elements recursively, and using binary search to insert the smaller elements (Jacobsthal numbers dictate the insertion sequence to minimize comparisons). Additionally, a `std::set` was strategically utilized during the parsing phase to rigorously verify that no duplicate values exist in the input dataset before the sorting algorithm begins. |

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
   ./<executable_name> <arguments>
   ```

4. **Clean up binary files:**
   ```bash
   make fclean
   ```

---

## 📚 Resources & References

### General C++ Documentation
* **[cplusplus.com: STL Containers](https://cplusplus.com/reference/stl/)** - The definitive overview of the C++ standard library's structure.
* **[Medium: C++ STL Containers Guide](https://medium.com/@avinashyadav16/c-stl-containers-f8bdb4b64768)** - A robust deep-dive into how data is stored under the hood.
* **[GeeksforGeeks: Containers in C++ STL](https://www.geeksforgeeks.org/cpp/containers-cpp-stl/)** - Detailed overview contrasting sequential, associative, and unordered containers.
* **[GeeksforGeeks: Iterators in C++](https://www.geeksforgeeks.org/iterators-c-stl/)** - Fundamental guide on navigating generic data collections.
* **[GeeksforGeeks: std::map in C++](https://www.geeksforgeeks.org/cpp/map-associative-containers-the-c-standard-template-library-stl/)** - Explains the Red-Black tree associative properties required for `ex00`.
* **[GeeksforGeeks: std::stack in C++](https://www.geeksforgeeks.org/cpp/stack-in-cpp-stl/)** - Crucial LIFO documentation utilized for the RPN calculator in `ex01`.
* **[GeeksforGeeks: std::list in C++](https://www.geeksforgeeks.org/cpp/list-cpp-stl/)** - Details doubly-linked list mechanics, used as the underlying adapter base in `ex01`.
* **[GeeksforGeeks: std::vector in C++](https://www.geeksforgeeks.org/cpp/vector-in-cpp-stl/)** - Core sequential container documentation applied to the Ford-Johnson sort in `ex02`.
* **[GeeksforGeeks: std::deque in C++](https://www.geeksforgeeks.org/cpp/deque-cpp-stl/)** - Explains the double-ended queue mechanics used as the alternative benchmark in `ex02`.
* **[GeeksforGeeks: Deque vs Vector](https://www.geeksforgeeks.org/cpp/deque-vs-vector-in-c-stl/)** - Highly recommended reading for `ex02` to understand execution time disparities.
* **[GeeksforGeeks: std::set in C++](https://www.geeksforgeeks.org/cpp/set-in-cpp-stl/)** - Outlines the unique key requirement, utilized for duplicate filtering in `ex02`.

### Mathematical & Algorithmic Concepts
* **[Algomaster: Evaluate Reverse Polish Notation](https://algomaster.io/learn/dsa/evaluate-reverse-polish-notation)** - Step-by-step logic on how a stack processes postfix expressions (`ex01`).
* **[Medium: Postfix / RPN Notation](https://augustinejoseph.medium.com/postfix-notation-reverse-polish-notation-or-rpn-aa64edce1c51)** - Advanced RPN concepts bridging operators and operands (`ex01`).
* **[Dev.to: Step-by-Step Visualization of Ford-Johnson](https://dev.to/emuminov/human-explanation-and-step-by-step-visualisation-of-the-ford-johnson-algorithm-5g91)** - An indispensable visual guide to navigating Jacobsthal insertion sequences (`ex02`).
* **[Medium: Ford-Johnson Algorithm](https://medium.com/@mohammad.ali.ibrahim.525/ford-johnson-algorithm-merge-insertion-4b024f0c3d42)** - Deep dive into the merge-insert sort bounds and logic constraints (`ex02`).

### CodeLucky & Visual Tutorials
* **[C++ File I/O: Reading and Writing to Files](https://www.youtube.com/watch?v=hZXoOv39vRU)** - Essential for `ex00`, showing how to safely parse both the historical Bitcoin CSV file and the user input file.
* **[C++ Input for Beginners: cin, getline & Error Handling](https://www.youtube.com/watch?v=GN5fruH-P5Q)** - Useful for robust line-by-line parsing and string formatting in `ex00` and `ex01`.
* **[C++ Templates: Master Generic Programming for Beginners](https://www.youtube.com/watch?v=AELTWRGYUpY)** - Reminds us how the generic structure of the PmergeMe algorithm allows us to plug in vectors and deques identically.
* **[C++ STL for Beginners: Master Containers & Algorithms](https://www.youtube.com/watch?v=9ubwYU8a8hg)** - A holistic recap linking algorithms directly to our final containers.
* **[C++ STL Containers Explained for Beginners](https://www.youtube.com/watch?v=nx3Mpy1X-kk)** - Compares cache localities, crucial for analyzing the performance benchmarks required by `PmergeMe`.
* **[C++ Maps Tutorial: Associative Containers](https://www.youtube.com/watch?v=AZDR4M-W7Q4)** - Visually breaks down the binary search tree backend allowing chronological sorting for Bitcoin dates (`ex00`).
* **[C++ Vectors: Dynamic Arrays & STL Explained](https://www.youtube.com/watch?v=S7q4cdh7Mds)** - Focuses heavily on contiguous memory reallocations, crucial to understand for the `vector` implementation of the Ford-Johnson sort (`ex02`).
* **[C++ Deque: Double-Ended Queue Explained](https://www.youtube.com/watch?v=x4GbYif25ss)** - Breaks down the underlying architecture of a `deque` and why its fragmented memory might benchmark differently than a vector (`ex02`).
* **[C++ Sets: Ordered Unique Containers](https://www.youtube.com/watch?v=SekDK2GFOM4)** - Explains how to efficiently filter data using `std::set` logic, employed here for strict uniqueness checks.
* **[C++ Stacks: LIFO Data Structures Explained](https://www.youtube.com/watch?v=Fba0VA7G45Q)** - Demonstrates the explicit use of `std::stack` to parse mathematical RPN strings (`ex01`).
* **[C++ Iterators Explained: STL Containers & Traversal](https://www.youtube.com/watch?v=PVMpMRIfb-U)** - Demonstrates iterator invalidation risks during dynamic algorithmic manipulation.
* **[C++ Exception Handling: Try, Catch, and Throw for Beginners!](https://www.youtube.com/watch?v=vP8ERWZEpGA)** - Reviews robust data safety for out-of-bounds evaluation or missing Bitcoin mapping edge cases.

---

### 🤖 AI Usage Guidelines
* **Code:** No AI-generated code was used to solve these exercises. All parsing trees, RPN logic, and the Ford-Johnson sorting algorithm implementations were constructed manually to ensure strict compliance with C++98 STL rules and mathematical accuracy.
* **Documentation:** AI tools were utilized to structure this `README.md`, extract the core logic for the distinct STL containers chosen, and format the architectural requirements into an educational portfolio format.
