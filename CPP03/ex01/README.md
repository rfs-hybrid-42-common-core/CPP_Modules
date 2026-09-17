# 🟢 Exercise 01: Serena, my love!

## 📝 Objective
Create a derived class `ScavTrap` that inherits from the `ClapTrap` base class. It must use the base class's attributes but override their default values upon creation (100 HP, 50 Energy, 20 DPS). It must also override the `attack()` function to provide unique output, implement its own special `guardGate()` ability, and seamlessly integrate into the Orthodox Canonical Form.

## 💡 The Logic

This exercise is your true introduction to **Single Inheritance** and class hierarchies. It demonstrates how derived classes manage inherited data and execution flow.

1. **Access Modifiers (`protected`):** 
   In Exercise 00, `ClapTrap`'s attributes were `private`, meaning *only* `ClapTrap` could see them. To allow the new `ScavTrap` child class to modify its own inherited HP and Energy inside its constructor, we must change those attributes in `ClapTrap.hpp` from `private` to `protected`. `protected` members are accessible to derived classes, but remain strictly hidden from outside code (like `main.cpp`).
2. **Constructor & Destructor Chaining:** 
   When a derived object is created, C++ enforces a strict lifecycle order:
   - **Construction (Base to Derived):** The `ClapTrap` constructor is called *first* to build the foundation, followed immediately by the `ScavTrap` constructor to apply its specific overrides. Notice how `ScavTrap` passes the name up to the base class using the initialization list: `ScavTrap::ScavTrap(...) : ClapTrap(name)`.
   - **Destruction (Derived to Base):** When the object is destroyed, the stack peels away in reverse order. `ScavTrap` is destroyed first, followed by `ClapTrap`.
3. **Function Overriding:** 
   `ScavTrap` implements its own version of `attack()`. Because C++ knows the object is specifically a `ScavTrap`, it executes the child's overridden version of the function instead of the parent's generic one, allowing for specific output formatting.
4. **OCF in Derived Classes:** 
   To maintain Orthodox Canonical Form, a derived class must safely copy its parent's data. Inside `ScavTrap`'s Copy Assignment Operator, you explicitly call `ClapTrap::operator=(other)` before returning. This delegates the heavy lifting of copying shared attributes up to the base class, keeping your code DRY.

## 🛠️ Step-by-Step Solution

1. **The Code:**
   *Check out the source files here:*
   - **[`inc/ClapTrap.hpp`](inc/ClapTrap.hpp)** / **[`src/ClapTrap.cpp`](src/ClapTrap.cpp)**
   - **[`inc/ScavTrap.hpp`](inc/ScavTrap.hpp)** / **[`src/ScavTrap.cpp`](src/ScavTrap.cpp)**
   - **[`src/main.cpp`](src/main.cpp)**
   - **[`Makefile`](Makefile)**

2. **Testing Inheritance Lifecycles:**
   Compile the program and pay strict attention to the order in which the construction and destruction messages appear.
   ```bash
   make
   
   ./scavTrap
   
   # Output Analysis:
   # 1. Constructor Chaining: When 'Serena' is created, you see ClapTrap's "Ha ha ha! I LIVE!" followed immediately by ScavTrap's "Bow before your robot overlord!".
   # 2. Overriding: Serena's attack prints "ScavTrap Serena attacks..." instead of the generic ClapTrap attack string.
   # 3. Special Abilities: guardGate() executes successfully, proving the derived class has extended the base class's functionality.
   # 4. Destructor Chaining: When objects go out of scope, the ScavTrap's "I'm too pretty to die!" fires first, followed by ClapTrap's "annoying!" death message.
   ```
