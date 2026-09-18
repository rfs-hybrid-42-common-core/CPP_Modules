# 🟢 Exercise 02: Mutated abomination

## 📝 Objective
The `std::stack` container is notoriously restrictive—it intentionally lacks iterators to enforce a strict LIFO (Last-In, First-Out) architecture. Your objective is to repair this injustice by developing a `MutantStack` class. It must be implemented in terms of a `std::stack`, retaining all of its original member functions (`push`, `pop`, `top`), while successfully exposing standard iterator capabilities. 

## 💡 The Logic

This exercise explores the internal architecture of **Container Adapters** and how inheritance can be utilized to expose protected members.

1. **Container Adapters:** 
   `std::stack` is not a standalone container like `std::vector` or `std::list`. It is an *adapter*. It takes an existing sequence container (by default, `std::deque`) and acts as a wrapper, hiding its iterators and restricting access to only the `top()` element.
2. **The Protected `c` Member:** 
   According to the C++ standard, a `std::stack` must store its underlying container in a protected member variable named `c`. Because it is `protected` rather than `private`, derived classes can access it.
3. **Inheritance & Exposure:** 
   By making `MutantStack` inherit publicly from `std::stack`, the class gains direct access to `this->c`. The `MutantStack` simply intercepts requests for `begin()` or `end()` and forwards them directly to the underlying container's `c.begin()` and `c.end()`. 
4. **Typedef Mapping:** 
   To ensure the exposed iterators behave seamlessly (allowing syntax like `MutantStack<int>::iterator`), the class uses `typedef` to map the underlying container's iterators (e.g., `std::deque<int>::iterator`) to the `MutantStack` namespace.
5. **Template Flexibility:** 
   Because the `MutantStack` mirrors the template parameters of `std::stack` (`template <typename T, typename Container = std::deque<T> >`), you can still swap out the underlying memory architecture (e.g., to a `std::vector`), and the iterators will automatically adapt without breaking.

## 🛠️ Step-by-Step Solution

1. **The Code:**
   *Check out the source files here:*
   - **[`inc/MutantStack.hpp`](inc/MutantStack.hpp)** / **[`inc/MutantStack.tpp`](inc/MutantStack.tpp)**
   - **[`src/main.cpp`](src/main.cpp)**
   - **[`Makefile`](Makefile)**

2. **Testing the Mutation:**
   Compile the program and observe how the `MutantStack` operates identically to a standard list while maintaining its stack properties.
   ```bash
   make
   
   ./mutantStack
   
   # Output Analysis:
   # 1. Subject Tests: The program first iterates through the MutantStack, then performs the exact same operations on a std::list. The outputs are perfectly identical, proving the mutation was successful.
   # 2. Advanced Iterators: Verifies that reverse_iterators (rbegin/rend) and const_iterators function flawlessly.
   # 3. OCF Compliance: A deep copy test confirms that assigning a MutantStack duplicates the underlying container without linking their memory addresses.
   # 4. Custom Containers: Instantiates a MutantStack backed by a std::vector instead of a std::deque, proving the template architecture remains fully generic and adaptable.
   ```
