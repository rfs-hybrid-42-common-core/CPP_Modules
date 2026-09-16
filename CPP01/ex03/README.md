# 🟢 Exercise 03: Unnecessary violence

## 📝 Objective
Implement a `Weapon` class alongside two human classes, `HumanA` and `HumanB`. Both humans have a name, a weapon, and an `attack()` method. The core constraint is that `HumanA` takes the `Weapon` in its constructor and is always armed, whereas `HumanB` does not take it in the constructor and may not always have a weapon.

## 💡 The Logic

This exercise bridges the gap between the memory concepts introduced in `ex02` and practical Object-Oriented class design. It directly asks you to evaluate when a class attribute should be a pointer versus a reference.

1. **References as Attributes (`HumanA`):** 
   Because `HumanA` is guaranteed to *always* be armed from the moment of its creation, its weapon attribute is implemented as a **Reference** (`Weapon& _weapon`). 
   - References cannot be `NULL`, ensuring `HumanA` will never crash by attempting to use a non-existent weapon.
   - *Crucial Rule:* C++ strictly requires references to be initialized at the exact moment of creation. Therefore, `HumanA`'s constructor **must** use a Member Initializer List (`HumanA::HumanA(...) : _name(name), _weapon(weapon)`) rather than assigning it inside the constructor's body.
   
2. **Pointers as Attributes (`HumanB`):**
   Because `HumanB` might not have a weapon immediately (and could theoretically drop it or switch it later), its weapon attribute is implemented as a **Pointer** (`Weapon* _weapon`).
   - Pointers can safely be initialized to `NULL` (representing the unarmed state).
   - We use a setter method (`setWeapon()`) to dynamically assign the address of a weapon to the pointer later on.
   - When calling `attack()`, we must defensively check if `_weapon == NULL` before dereferencing it to avoid segmentation faults (defaulting to "fists" in this implementation).

3. **Memory Aliasing:** 
   In `main.cpp`, you instantiate a `Weapon` and pass it to both humans. Because both `HumanA` and `HumanB` store the *address* of the weapon (via reference and pointer, respectively) rather than making a deep copy, calling `club.setType()` on the original object immediately alters the output of their subsequent `attack()` calls.

## 🛠️ Step-by-Step Solution

1. **The Code:**
   *Check out the source files here:*
   - **[`inc/Weapon.hpp`](inc/Weapon.hpp)** / **[`src/Weapon.cpp`](src/Weapon.cpp)**
   - **[`inc/HumanA.hpp`](inc/HumanA.hpp)** / **[`src/HumanA.cpp`](src/HumanA.cpp)**
   - **[`inc/HumanB.hpp`](inc/HumanB.hpp)** / **[`src/HumanB.cpp`](src/HumanB.cpp)**
   - **[`src/main.cpp`](src/main.cpp)**
   - **[`Makefile`](Makefile)**

2. **Testing the Implementation:**
   Compile the program and observe the output, paying close attention to how the weapon types change dynamically.
   ```bash
   make
   ./survival
   
   # Output Analysis:
   # 1. Bob (HumanA) attacks with a "crude spiked club".
   # 2. The club's type is changed externally.
   # 3. Bob's subsequent attack automatically reflects "some other type of club".
   # 4. Jim (HumanB) starts unarmed (defaults to fists internally or handles NULL gracefully), is equipped with the club, and perfectly mirrors the same aliasing behavior as Bob.
   ```
