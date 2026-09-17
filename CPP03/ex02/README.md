# 🟢 Exercise 02: Repetitive work

## 📝 Objective
Create another derived class named `FragTrap` that inherits from `ClapTrap`. It must initialize with maximum stats (100 HP, 100 Energy, 30 DPS) and feature a unique special ability: `highFivesGuys(void)`. 

## 💡 The Logic

This exercise reinforces the single inheritance mechanics established in `ex01` and demonstrates how a single base class can serve as a foundation for multiple, wildly different derived classes.

1. **Sibling Classes:** 
   `FragTrap` and `ScavTrap` now act as sibling classes. They both inherit the protected attributes (`_name`, `_hp`, `_energy`, `_dps`) and public methods from `ClapTrap`, but they establish completely different default stats and distinct special abilities (`highFivesGuys()` vs `guardGate()`).
2. **Implicit Inheritance (Code Reuse):** 
   Unlike `ScavTrap`, `FragTrap` **does not** override the `attack()` method in its header file. When you call `loaderBot.attack()` in `main.cpp`, the compiler looks for an `attack` method inside `FragTrap`. Finding none, it automatically walks up the inheritance chain and executes `ClapTrap::attack()` instead. This perfectly demonstrates the DRY (Don't Repeat Yourself) principle of OOP: if the base logic works fine for the child class, you don't need to rewrite it.
3. **Consistent OCF & Chaining:** 
   The object lifecycle remains strictly enforced. The `ClapTrap` constructor fires before the `FragTrap` constructor, and the `FragTrap` destructor fires before the `ClapTrap` destructor. Furthermore, `FragTrap` delegates its copying logic directly to `ClapTrap::operator=` to maintain Orthodox Canonical Form safely.

## 🛠️ Step-by-Step Solution

1. **The Code:**
   *Check out the source files here:*
   - **[`inc/ClapTrap.hpp`](inc/ClapTrap.hpp)** / **[`src/ClapTrap.cpp`](src/ClapTrap.cpp)**
   - **[`inc/ScavTrap.hpp`](inc/ScavTrap.hpp)** / **[`src/ScavTrap.cpp`](src/ScavTrap.cpp)**
   - **[`inc/FragTrap.hpp`](inc/FragTrap.hpp)** / **[`src/FragTrap.cpp`](src/FragTrap.cpp)**
   - **[`src/main.cpp`](src/main.cpp)**
   - **[`Makefile`](Makefile)**

3. **Testing Sibling Inheritance:**
   Compile the program and observe how `FragTrap` interacts with the base class methods.
   ```bash
   make
   
   ./fragTrap
   
   # Output Analysis:
   # 1. Constructor Chaining: ClapTrap's creation message is immediately followed by FragTrap's "tornado of death" message.
   # 2. Implicit Inheritance: When Loader Bot attacks, the output says "ClapTrap Loader Bot attacks...", proving it fell back to the parent class's method because we didn't override it.
   # 3. Special Abilities: highFivesGuys() executes successfully (unless the robot is dead).
   # 4. Destructor Chaining: The derived class is destroyed first ("My robotic flesh!"), safely peeling back to the base class destructor.
   ```
