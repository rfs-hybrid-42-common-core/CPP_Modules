# 🟢 Exercise 02: Abstract class

## 📝 Objective
Convert the generic `Animal` class from the previous exercises into an abstract base class named `AAnimal`. You must prevent the program from being able to instantiate a generic `AAnimal` directly by converting its `makeSound()` method into a pure virtual function.

## 💡 The Logic

This exercise introduces the concept of **Abstract Classes** and design contracts, shifting the base class from a usable object into a purely structural blueprint.

1. **The Conceptual Problem:** 
   In OOP, a base class often represents a broad concept rather than a concrete entity. A `Dog` barks, and a `Cat` meows, but what sound does a generic "Animal" make? Conceptually, a generic animal doesn't exist—it is merely a category. Therefore, allowing a programmer to instantiate an `Animal` directly (`Animal a;`) is a structural flaw.
2. **Pure Virtual Functions (`= 0`):** 
   To fix this, we change the method declaration in `AAnimal` to `virtual void makeSound(void) const = 0;`. The `= 0` syntax defines it as a **Pure Virtual Function**. This tells the C++ compiler two things:
   - The base class does not provide a default implementation for this method.
   - Any class that inherits from `AAnimal` *must* provide its own implementation of `makeSound()`. If a derived class fails to do so, it will also be flagged as abstract and cannot be instantiated.
3. **Abstract Classes:** 
   By definition in C++, any class containing at least one pure virtual function automatically becomes an **Abstract Class**. The compiler will strictly forbid you from instantiating it.
4. **Maintained Polymorphism & Memory Safety:** 
   Even though you cannot instantiate an `AAnimal` directly, you can (and must) still use `AAnimal*` pointers to point to derived `Dog` and `Cat` objects. Because of this, the deep copying logic and virtual destructors implemented in Exercise 01 remain completely intact and necessary.

## 🛠️ Step-by-Step Solution

1. **The Code:**
   *Check out the source files here:*
   - **[`inc/AAnimal.hpp`](inc/AAnimal.hpp)** / **[`src/AAnimal.cpp`](src/AAnimal.cpp)**
   - **[`inc/Brain.hpp`](inc/Brain.hpp)** / **[`src/Brain.cpp`](src/Brain.cpp)**
   - **[`inc/Dog.hpp`](inc/Dog.hpp)** / **[`src/Dog.cpp`](src/Dog.cpp)**
   - **[`inc/Cat.hpp`](inc/Cat.hpp)** / **[`src/Cat.cpp`](src/Cat.cpp)**
   - **[`inc/WrongAnimal.hpp`](inc/WrongAnimal.hpp)** / **[`src/WrongAnimal.cpp`](src/WrongAnimal.cpp)**
   - **[`inc/WrongCat.hpp`](inc/WrongCat.hpp)** / **[`src/WrongCat.cpp`](src/WrongCat.cpp)**
   - **[`src/main.cpp`](src/main.cpp)**
   - **[`Makefile`](Makefile)**

2. **Testing the Abstract Constraint:**
   Compile the program and observe the main function. The standard deep copy and array tests run identically to `ex01`, but Section 0 proves the abstract constraint.
   ```bash
   make
   
   ./abstractAnimal
   
   # Output Analysis:
   # 1. Abstract Protection: Inside main.cpp, the instantiation of a base AAnimal is deliberately commented out. If you uncomment `AAnimal testObject;`, the compiler will actively block the compilation with an error: "cannot declare variable 'testObject' to be of abstract type 'AAnimal'".
   # 2. Polymorphic Arrays & Deep Copies: The rest of the program functions perfectly, proving that AAnimal pointers can still safely manage and deeply clone dynamically allocated Dogs and Cats.
   ```
