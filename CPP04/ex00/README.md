# 🟢 Exercise 00: Polymorphism

## 📝 Objective
Implement a base `Animal` class with a `makeSound()` method, and derived `Dog` and `Cat` classes that override this method. You must prove that calling `makeSound()` on a base `Animal` pointer pointing to a derived object executes the derived class's specific sound. To demonstrate the alternative, you must also create a `WrongAnimal` and `WrongCat` pair that fails to do this because they omit the `virtual` keyword.

## 💡 The Logic

This exercise is a direct demonstration of **Subtype Polymorphism** and the difference between compile-time (static) binding and runtime (dynamic) binding in C++.

1. **Dynamic Binding (`virtual` keyword):** 
   When you declare `virtual void makeSound() const;` in the `Animal` base class, you instruct the compiler to use **Dynamic Binding**. If you create a pointer `Animal* i = new Cat();` and call `i->makeSound()`, the program checks the object's hidden Virtual Table (vtable) at runtime. It sees that the underlying object is actually a `Cat` and correctly routes the call to `Cat::makeSound()`.
2. **Static Binding (The `Wrong` classes):** 
   In the `WrongAnimal` class, `makeSound()` is a standard, non-virtual method. When you declare `WrongAnimal* wrongI = new WrongCat();` and call `wrongI->makeSound()`, the compiler uses **Static Binding**. It only looks at the pointer's type (`WrongAnimal*`) during compilation and permanently wires the call to `WrongAnimal::makeSound()`. The fact that it is actually a `WrongCat` in memory is completely ignored.
3. **Virtual Destructors:** 
   Just like methods, destructors in base classes *must* be `virtual`. If you call `delete i;` on an `Animal*` pointer pointing to a `Cat`, the virtual destructor ensures that `~Cat()` is called first, followed by `~Animal()`. If the destructor is not virtual (as seen in the `WrongAnimal` class), deleting the base pointer will strictly destroy the base object, silently leaking the derived object's memory.
4. **Stack Allocation vs. Pointers:** 
   If an object is allocated normally on the stack (e.g., `WrongCat stackWrongCat;`), the compiler knows its exact type immediately. In this scenario, `stackWrongCat.makeSound()` will correctly output the cat's sound because no base-pointer abstraction is obscuring its identity.

## 🛠️ Step-by-Step Solution

1. **The Code:**
   *Check out the source files here:*
   - **[`inc/Animal.hpp`](inc/Animal.hpp)** / **[`src/Animal.cpp`](src/Animal.cpp)**
   - **[`inc/Dog.hpp`](inc/Dog.hpp)** / **[`src/Dog.cpp`](src/Dog.cpp)**
   - **[`inc/Cat.hpp`](inc/Cat.hpp)** / **[`src/Cat.cpp`](src/Cat.cpp)**
   - **[`inc/WrongAnimal.hpp`](inc/WrongAnimal.hpp)** / **[`src/WrongAnimal.cpp`](src/WrongAnimal.cpp)**
   - **[`inc/WrongCat.hpp`](inc/WrongCat.hpp)** / **[`src/WrongCat.cpp`](src/WrongCat.cpp)**
   - **[`src/main.cpp`](src/main.cpp)**
   - **[`Makefile`](Makefile)**

2. **Testing Polymorphism:**
   Compile the program and observe the differences between the `Animal` and `WrongAnimal` outputs.
   ```bash
   make
   
   ./polymorphicAnimal
   
   # Output Analysis:
   # 1. Dynamic Binding: 'i' and 'j' (Animal pointers) successfully output "Meow!" and "Woof!" because the virtual keyword routes the call dynamically.
   # 2. Static Binding: 'wrongI' (WrongAnimal pointer to a WrongCat) outputs the generic, otherworldly base screech because the lack of a virtual keyword forces the compiler to resolve the call based purely on the pointer type.
   # 3. Stack Allocation: Direct stack allocations correctly call their own methods, proving that static binding only causes issues when manipulating objects through abstracted base pointers.
   # 4. Virtual Destructors: The Animal pointer deletions cleanly trigger the derived destructors before the base destructors.
   ```
