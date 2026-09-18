# 🟢 Exercise 01: I don’t want to set the world on fire

## 📝 Objective
Introduce a `Brain` class containing an array of 100 `std::string` ideas. Update the `Dog` and `Cat` classes to include a private `Brain*` attribute. This brain must be dynamically allocated upon creation and safely deleted upon destruction. Crucially, you must ensure that all copies made of these animals are **Deep Copies**, proving that modifying a cloned animal's brain does not affect the original.

## 💡 The Logic

This exercise bridges runtime polymorphism with dynamic memory management, highlighting the two most common causes of memory leaks and crashes in C++ inheritance.

1. **The Virtual Destructor Mandate:** 
   When you allocate a `Dog` but store it in an `Animal*` pointer, calling `delete` on that pointer creates a massive vulnerability. If `~Animal()` is not declared as `virtual`, the compiler uses static binding and only destroys the `Animal` portion of the object. The `Dog` destructor is ignored, and its dynamically allocated `Brain` leaks. By making `virtual ~Animal(void);`, we ensure dynamic binding forces the `Dog` destructor to execute first, safely deleting the brain before destroying the base object.
2. **Shallow vs. Deep Copies:** 
   By default, C++ performs a "Shallow Copy." If you copy `Cat A` into `Cat B`, the compiler simply copies the memory address of the `Brain*` pointer. Both cats now share the exact same brain. If one cat changes an idea, the other's changes as well. Worse, when they go out of scope, both destructors will try to `delete` the same memory address, causing a fatal "double-free" crash.
3. **Implementing Deep Copies:** 
   To fix this, we must update the Orthodox Canonical Form (Copy Constructor and Assignment Operator) for both `Dog` and `Cat`. Instead of copying the pointer address, a **Deep Copy** allocates a completely `new Brain()` and manually copies all 100 strings from the original brain into the new one. 
4. **Assignment Operator Safety:** 
   Inside the `operator=`, we must be extremely careful. Before deleting the old brain to make room for the new one, we first allocate the new brain into a temporary pointer. If the allocation fails (e.g., out of memory), the original object remains intact.

## 🛠️ Step-by-Step Solution

1. **The Code:**
   *Check out the source files here:*
   - **[`inc/Animal.hpp`](inc/Animal.hpp)** / **[`src/Animal.cpp`](src/Animal.cpp)**
   - **[`inc/Brain.hpp`](inc/Brain.hpp)** / **[`src/Brain.cpp`](src/Brain.cpp)**
   - **[`inc/Dog.hpp`](inc/Dog.hpp)** / **[`src/Dog.cpp`](src/Dog.cpp)**
   - **[`inc/Cat.hpp`](inc/Cat.hpp)** / **[`src/Cat.cpp`](src/Cat.cpp)**
   - **[`inc/WrongAnimal.hpp`](inc/WrongAnimal.hpp)** / **[`src/WrongAnimal.cpp`](src/WrongAnimal.cpp)**
   - **[`inc/WrongCat.hpp`](inc/WrongCat.hpp)** / **[`src/WrongCat.cpp`](src/WrongCat.cpp)**
   - **[`src/main.cpp`](src/main.cpp)**
   - **[`Makefile`](Makefile)**

3. **Testing Memory Safety:**
   Compile the program and observe the meticulous allocation, deep copying, and virtual destruction sequences.
   ```bash
   make
   
   ./animalIdeas
   
   # Output Analysis:
   # 1. Array Test: Half dogs and half cats are allocated into an array of Animal pointers. When deleted, the trace messages prove that the specific ~Dog() and ~Cat() destructors fire before the ~Animal() destructor, safely terminating brain activity.
   # 2. Deep Copy Test: A Dog is copied. We modify the copy's brain to "I want to sleep on the sofa instead." 
   # 3. Verification: The program prints the original Dog's idea, which remains exactly as it was ("I want to chase the postman"), proving the memory is entirely isolated.
   ```
