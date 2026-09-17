# 🟢 Exercise 03: BSP

## 📝 Objective
Implement a `Point` class that represents a 2D coordinate using the `Fixed` class from the previous exercise. Using this class, implement a function `bsp` (Binary Space Partitioning) that determines if a given point is strictly inside a triangle formed by three other points.

## 💡 The Logic

This exercise bridges the gap between low-level memory architecture (OCF) and practical geometric algorithms, fully utilizing the operator overloads built in Exercise 02.

1. **Const Attributes & OCF Quirks:** 
   The `Point` class requires `x` and `y` to be `const Fixed` attributes. In C++, `const` members must be initialized immediately at the moment of creation, making Member Initializer Lists mandatory in the constructors (e.g., `Point::Point(...) : x(Fixed(n1)), y(Fixed(n2))`). Furthermore, because they are `const`, they cannot be reassigned. This creates a quirk in the Orthodox Canonical Form: the Copy Assignment Operator `operator=` must be declared to satisfy the OCF compiler requirements, but it effectively does nothing because the coordinates cannot be overwritten.
2. **The Cross Product Algorithm (BSP):** 
   To determine if Point $P$ is inside the triangle formed by $A$, $B$, and $C$, the program calculates the 2D cross product for each edge relative to the point. The mathematical formula used for edge $AB$ is:
   $$ CP = (B_x - A_x)(P_y - A_y) - (B_y - A_y)(P_x - A_x) $$
   Because you overloaded all arithmetic operators (`-`, `*`) in the `Fixed` class, this complex formula can be written seamlessly in C++ exactly as it appears in algebra.
3. **Strict Boundaries:** 
   The subject requires the point to be *strictly* inside the triangle.
   - If any cross product equals exactly 0, the point lies directly on an edge or a vertex. The function instantly returns `false`.
   - If the point is strictly inside, all three cross products will share the exact same sign (all positive or all negative, depending on the vertex winding order). If there is a mix of positive and negative results, the point is outside.

## 🛠️ Step-by-Step Solution

1. **The Code:**
   *Check out the source files here:*
   - **[`inc/Fixed.hpp`](inc/Fixed.hpp)** / **[`src/Fixed.cpp`](src/Fixed.cpp)**
   - **[`inc/Point.hpp`](inc/Point.hpp)** / **[`src/Point.cpp`](src/Point.cpp)**
   - **[`src/bsp.cpp`](src/bsp.cpp)**
   - **[`src/main.cpp`](src/main.cpp)**
   - **[`Makefile`](Makefile)**

2. **Testing the Algorithm:**
   The `main.cpp` executes a comprehensive suite of boolean tests. Compile and run the program to evaluate the logic against integers, floating-point epsilons, and strict edges.
   ```bash
   make
   
   ./bsp
   
   # Output Analysis:
   # 1. Integer Tests: Verifies standard inside/outside coordinates.
   # 2. Floating-Point Tests: Uses fractional coordinates to prove the Fixed class maintains mathematical precision during multiplication/subtraction.
   # 3. Edge Tests: Proves that points exactly on Vertex A, B, C, or directly on the line segments between them properly return 'false'.
   ```
