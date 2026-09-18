# 🟢 Exercise 03: Interface & recap

## 📝 Objective
Implement a complex ecosystem utilizing pure abstract classes (Interfaces). You must build an `ICharacter` interface and an `IMateriaSource` interface, along with their concrete implementations. The system requires managing an inventory of dynamically allocated `AMateria` objects (like `Ice` and `Cure`), handling deep copies of pointer arrays, and strictly preventing memory leaks when unequipping items.

## 💡 The Logic

This exercise is the climax of the module, combining everything learned about abstract classes, dynamic binding, and Orthodox Canonical Form into a realistic Object-Oriented architecture.

1. **Interfaces in C++98:** 
   An interface is an architectural contract. `ICharacter` and `IMateriaSource` are pure interfaces because they contain *only* pure virtual functions (`= 0`) and have absolutely no member variables. Any class that inherits from them (like `Character`) is legally bound by the compiler to implement every single method defined in the interface. Note that interfaces must still have a virtual destructor to ensure derived classes are cleaned up correctly.
2. **The Prototype Pattern & Factories:** 
   How do you copy an object if you only have a pointer to its abstract base class (`AMateria*`) and don't know if it's actually `Ice` or `Cure`? You use the **Prototype Pattern**. The `AMateria` class defines a pure virtual `clone()` method. The derived `Ice` class implements it by returning `new Ice()`. The `MateriaSource` factory acts as a blueprint manager—it learns a Materia, stores it, and when asked to create a new one, simply calls the polymorphic `clone()` method.
3. **Deep Copying Arrays of Pointers:** 
   The `Character` class stores an array of four `AMateria*` pointers. A shallow copy would just copy the pointer addresses, causing two characters to share the exact same inventory (leading to a double-free crash). To perform a deep copy, the Copy Constructor and Assignment Operator must iterate through the inventory array and call `clone()` on every non-null pointer to generate entirely independent memory allocations.
4. **Exception Safety:** 
   The implementation includes advanced `try/catch` blocks inside the assignment operators. If cloning the third item in an inventory fails due to a memory allocation error (`std::bad_alloc`), the program safely destroys the first two items it just cloned before re-throwing the error. This guarantees "Strong Exception Safety"—the original object remains perfectly intact and no memory is leaked.
5. **Memory Leaks and "The Floor":** 
   The subject dictates that `unequip()` must *not* delete the Materia. If you simply set the inventory pointer to `NULL`, that memory is lost forever. To test this safely, `main.cpp` implements a "Floor" array that saves the pointer address immediately after unequipping, allowing the program to properly `delete` the dropped item at the end of execution.

## 🛠️ Step-by-Step Solution

1. **The Code:**
   *Check out the source files here:*
   - **[`inc/IMateriaSource.hpp`](inc/IMateriaSource.hpp)** / **[`inc/MateriaSource.hpp`](inc/MateriaSource.hpp)** / **[`src/MateriaSource.cpp`](src/MateriaSource.cpp)**
   - **[`inc/ICharacter.hpp`](inc/ICharacter.hpp)** / **[`inc/Character.hpp`](inc/Character.hpp)** / **[`src/Character.cpp`](src/Character.cpp)**
   - **[`inc/AMateria.hpp`](inc/AMateria.hpp)** / **[`src/AMateria.cpp`](src/AMateria.cpp)**
   - **[`inc/Ice.hpp`](inc/Ice.hpp)** / **[`src/Ice.cpp`](src/Ice.cpp)**
   - **[`inc/Cure.hpp`](inc/Cure.hpp)** / **[`src/Cure.cpp`](src/Cure.cpp)**
   - **[`src/main.cpp`](src/main.cpp)**
   - **[`Makefile`](Makefile)**

3. **Testing Interfaces and The Floor:**
   Compile the program and observe the stress tests.
   ```bash
   make
   
   ./materia
   
   # Output Analysis:
   # 1. Subject Test: Materias are successfully learned, cloned, equipped, and used polymorphically against "Bob".
   # 2. Limit Testing: Attempting to learn or equip a 5th materia is safely caught and blocked. Attempting to use an empty or out-of-bounds slot throws a safe error message rather than segfaulting.
   # 3. Deep Copy: The 'Original_Hero' is copied. The original uses a spell, proving the copy didn't steal or overlap the memory.
   # 4. The Floor: An item is unequipped. The pointer is saved to the floor array in main.cpp, and successfully deleted during final cleanup, proving zero leaks.
   ```
