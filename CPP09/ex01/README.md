# 🟢 Exercise 01: Reverse Polish Notation

## 📝 Objective
Create a program named `RPN` that evaluates mathematical expressions written in Reverse Polish Notation. The calculator must process single-digit numbers and standard arithmetic operators (`+`, `-`, `*`, `/`). It must strictly enforce formatting rules, gracefully intercept mathematical impossibilities (like division by zero), and prevent hardware-level arithmetic overflows.

## 💡 The Logic

This exercise is a practical demonstration of **Container Adapters** and **LIFO (Last-In, First-Out)** data structures.

1. **LIFO Architecture (`std::stack`):** 
   A stack is the universally accepted data structure for evaluating postfix notation. The algorithm is incredibly streamlined: iterate through the string, push every number onto the top of the stack, and whenever an operator is encountered, pop the top two numbers, evaluate them, and push the result back onto the stack.
2. **Adapter Reassignment (`std::list`):** 
   `std::stack` is not a standalone container; it is an adapter that wraps an underlying sequence container. While the C++ default is `std::deque`, this exercise explicitly overrides the default memory architecture by declaring `std::stack<long, std::list<long> >`. This proves that an adapter can seamlessly wrap any container that supports `push_back` and `pop_back`, allowing you to completely change the underlying memory footprint (from contiguous arrays to doubly-linked nodes) without altering the stack's functional logic.
3. **Robust Pre-Computation Bounds Checking:** 
   Standard C++ math operations will silently overflow or underflow hardware limits, causing critical data corruption. The `RPN` class manually intercepts these edge cases. Before calculating a result, the code evaluates the top two operands against `std::numeric_limits<long>::max()` and `min()`. This catches notoriously silent crashes, such as the `INT_MIN / -1` trap.
4. **Token Isolation (`std::istringstream`):** 
   The string is safely tokenized using `std::istringstream`, inherently extracting valid operands and operators while bypassing contiguous whitespaces without requiring manual array indexing. 

## 🛠️ Step-by-Step Solution

1. **The Code:**
   *Check out the source files here:*
   - **[`inc/RPN.hpp`](inc/RPN.hpp)** / **[`src/RPN.cpp`](src/RPN.cpp)**
   - **[`src/main.cpp`](src/main.cpp)**
   - **[`Makefile`](Makefile)**

2. **Testing the Calculator:**
   Compile the program and provide the mathematical expression enclosed in quotes.
   ```bash
   make
   
   ./RPN "8 9 * 9 - 9 - 9 - 4 1 + *"
   
   # Output Analysis:
   # 1. Valid Expression: The program correctly evaluates the postfix notation string and outputs the final result (225).
   # 2. Invalid Input: Passing multi-digit numbers (e.g., "10 2 +") or forbidden characters safely throws an InvalidInputException.
   # 3. Incomplete Equations: If the string concludes but multiple numbers remain stranded on the stack, it throws a LackOfOperatorsException.
   # 4. Limit Protections: Dividing by zero or attempting calculations that breach standard long boundaries throw specific mathematical exceptions.
   ```
