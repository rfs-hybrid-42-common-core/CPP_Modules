# 🟢 Exercise 03: Now it's weird!

## 📝 Objective
Create a hybrid `DiamondTrap` class that inherits from *both* `ScavTrap` and `FragTrap`. It must combine their stats (FragTrap's HP and DPS, ScavTrap's Energy and Attack), implement its own unique `whoAmI()` ability, and correctly append a `_clap_name` suffix to the base class's name variable while keeping its own name intact. 

## 💡 The Logic

This exercise tackles one of the most notoriously complex features of C++: **Multiple Inheritance** and the **Diamond Problem**.

1. **The Diamond Problem:** 
   Because `DiamondTrap` inherits from `ScavTrap` and `FragTrap`, and *both* of those inherit from `ClapTrap`, a standard instantiation of `DiamondTrap` would actually create two entirely separate `ClapTrap` sub-objects in memory. If you asked for `getHp()`, the compiler would crash, not knowing *which* `ClapTrap` base to pull the HP from.
2. **Virtual Inheritance to the Rescue:** 
   To fix this, `ScavTrap` and `FragTrap` must inherit from `ClapTrap` virtually (`class ScavTrap : virtual public ClapTrap`). This keyword tells the compiler to ensure that only **one, shared** instance of `ClapTrap` is created at the very top of the hierarchy. 
   - *Crucial Rule:* Because the intermediate classes (`ScavTrap`/`FragTrap`) no longer own the base class, the most-derived class (`DiamondTrap`) is now strictly responsible for calling the `ClapTrap` constructor directly in its initialization list.
3. **Method Ambiguity (`using` keyword):**
   Even with a single shared base class, `DiamondTrap` still inherits two different versions of `attack()` (one overridden by ScavTrap, one inherited by FragTrap). To prevent the compiler from panicking over the ambiguity, we explicitly tell it which path to prioritize in the header file using the `using` keyword: `using ScavTrap::attack;`.
4. **Variable Shadowing (`-Wshadow`):** 
   `DiamondTrap` declares its own private `_name` attribute. This intentionally "shadows" (hides) the `_name` attribute sitting in the `ClapTrap` base class. When `whoAmI()` executes, calling `_name` prints the DiamondTrap's specific name, while calling `getName()` accesses the shared base class's name (which was assigned the `_clap_name` suffix during construction).
5. **Hybrid Initialization:** 
   Because the order of parent constructor execution can overwrite inherited variables unpredictably during multiple inheritance, the `DiamondTrap` constructor explicitly hardcodes its final stats (`_hp = 100; _energy = 50; _dps = 30;`) to guarantee the correct hybrid mix.

## 🛠️ Step-by-Step Solution

1. **The Code:**
   *Check out the source files here:*
   - **[`inc/ClapTrap.hpp`](inc/ClapTrap.hpp)** / **[`src/ClapTrap.cpp`](src/ClapTrap.cpp)**
   - **[`inc/ScavTrap.hpp`](inc/ScavTrap.hpp)** / **[`src/ScavTrap.cpp`](src/ScavTrap.cpp)**
   - **[`inc/FragTrap.hpp`](inc/FragTrap.hpp)** / **[`src/FragTrap.cpp`](src/FragTrap.cpp)**
   - **[`inc/DiamondTrap.hpp`](inc/DiamondTrap.hpp)** / **[`src/DiamondTrap.cpp`](src/DiamondTrap.cpp)**
   - **[`src/main.cpp`](src/main.cpp)**
   - **[`Makefile`](Makefile)**

3. **Testing Multiple Inheritance:**
   Compile the program with `-Wshadow` enabled and run the binary to verify the hybrid behaviors and virtual destruction chains.
   ```bash
   make
   
   ./diamondTrap
   
   # Output Analysis:
   # 1. Virtual Construction: Notice that ClapTrap is only created ONCE at the very beginning, followed by ScavTrap, FragTrap, and finally DiamondTrap. 
   # 2. Ambiguity Resolution: When attacking, the program successfully outputs the "ScavTrap" attack message, proving the 'using' keyword successfully routed the logic.
   # 3. Hybrid Abilities: DiamondTrap successfully executes guardGate() from ScavTrap, highFivesGuys() from FragTrap, and its own whoAmI().
   # 4. Shadowing: whoAmI() successfully prints both "ButtStallion" (local _name) and "ButtStallion_clap_name" (ClapTrap base _name).
   # 5. Virtual Destruction: The destructors fire in exact reverse order, and the shared ClapTrap base is safely destroyed exactly ONCE at the very end.
   ```
