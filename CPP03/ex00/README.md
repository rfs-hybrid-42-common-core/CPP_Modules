# 🟢 Exercise 00: Aaaaand... OPEN!

## 📝 Objective
Implement a base class named `ClapTrap` that adheres strictly to the Orthodox Canonical Form. It must contain private attributes for Name, Hit Points (10), Energy Points (10), and Attack Damage (0). You must also implement three member functions—`attack`, `takeDamage`, and `beRepaired`—that modify these attributes while printing descriptive trace messages.

## 💡 The Logic

This exercise serves as the foundational **Base Class** for the rest of the inheritance module. It emphasizes encapsulation and state-dependent logic.

1. **Encapsulation:** 
   All attributes (`_name`, `_hp`, `_energy`, `_dps`) are strictly `private`. External code cannot manually set a ClapTrap's health to 100 or its energy to -5. State modifications can only occur through controlled, public member functions (`takeDamage`, `beRepaired`).
2. **Defensive State Management:** 
   The core logic of this exercise revolves around conditional checks. 
   - A `ClapTrap` cannot `attack()` or `beRepaired()` if it has 0 Energy Points. 
   - A `ClapTrap` cannot perform *any* action if it has 0 Hit Points (it is dead).
   - Every action that consumes energy must proactively check `if (getHp() > 0 && getEnergy() > 0)` before executing, decrementing the energy pool only if the check passes.
3. **Orthodox Canonical Form (OCF):** 
   Just like in CPP 02, the class must safely handle its own copying and instantiation. The Copy Constructor and Copy Assignment Operator ensure that all stats (HP, Energy, DPS) are perfectly replicated when creating a clone.
4. **Thematic Lifecycle Tracking:** 
   Every constructor and destructor prints a specific message to track the exact moment the object is allocated and deallocated in memory. (This implementation uses thematic Borderlands-inspired quotes for flavor).

## 🛠️ Step-by-Step Solution

1. **The Code:**
   *Check out the source files here:*
   - **[`inc/ClapTrap.hpp`](inc/ClapTrap.hpp)** / **[`src/ClapTrap.cpp`](src/ClapTrap.cpp)**
   - **[`src/main.cpp`](src/main.cpp)**
   - **[`Makefile`](Makefile)**

2. **Testing State Management:**
   Compile the program and observe how the object reacts to running out of resources.
   ```bash
   make
   
   ./clapTrap
   
   # Output Analysis:
   # 1. Energy Depletion: The VaultHunter successfully attacks 10 times, but the 11th attempt is safely blocked and outputs an exhaustion message.
   # 2. OCF Compliance: The 'troy' and 'calypso' objects successfully copy the modified stats from 'tyreen' and execute their own attacks.
   # 3. Health Depletion (Death): 'Maliwan' takes fatal damage. Subsequent attempts to attack, repair, or take more damage are blocked by the 'dead' state.
   # 4. Destructors: The stack automatically cleans up all instantiated ClapTraps in reverse order, firing their destruction messages.
   ```
