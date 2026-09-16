# 🟢 Exercise 00: BraiiiiiiinnnzzzZ

## 📝 Objective
Implement a `Zombie` class with a private string attribute for its name and a member function to announce itself. You must write two helper functions—one that creates a Zombie on the heap, and one that creates a Zombie on the stack. The destructors must print a specific debugging message so the exact moment of destruction can be tracked.

## 💡 The Logic

This exercise is designed to teach the fundamental differences between **Stack** memory (automatic allocation) and **Heap** memory (dynamic allocation) in C++. 

1. **Stack Allocation (`randomChump`):** When you declare a variable normally (e.g., `Zombie zombie(name);`), it is allocated on the stack. The stack is incredibly fast but strictly bound to scope. As soon as the `randomChump` function finishes executing, the stack frame is popped, and the `Zombie` destructor is automatically called. 
2. **Heap Allocation (`newZombie`):** To create an object that survives after the function that created it ends, you must allocate it dynamically on the heap using the `new` keyword (e.g., `new Zombie(name)`). This returns a pointer to the object. However, it is now your absolute responsibility to manually call `delete` on that pointer when you are done; otherwise, you will cause a memory leak.
3. **Defensive Programming:** Dynamic allocation is not guaranteed to succeed (e.g., the system could run out of memory). In `main.cpp`, the heap allocation is wrapped in a `try/catch(std::bad_alloc)` block. If `new` fails, it throws an exception instead of returning a `NULL` pointer, which is standard C++ practice.

## 🛠️ Step-by-Step Solution

1. **The Code:**
   *Check out the source files here:*
   - **[`inc/Zombie.hpp`](inc/Zombie.hpp)** / **[`src/Zombie.cpp`](src/Zombie.cpp)**
   - **[`src/newZombie.cpp`](src/newZombie.cpp)**
   - **[`src/randomChump.cpp`](src/randomChump.cpp)**
   - **[`src/main.cpp`](src/main.cpp)**
   - **[`Makefile`](Makefile)**

2. **Testing Lifecycle & Memory Leaks:**
   Compile the program and observe the exact order of the creation and destruction messages.
   ```bash
   make
   ./zombie
   
   # Output Analysis:
   # 1. The unnamed "Zombie" (Stack) is created, announces itself, and dies immediately after randomChump() ends.
   # 2. "Stack" (Stack) is created, announces itself, and dies immediately after randomChump() ends.
   # 3. "Heap" (Heap) is created and announces itself. It DOES NOT die immediately. It only dies when 'delete heap;' is explicitly called in main.
   ```

3. **Verifying Memory:**
   C++ handles memory leaks exactly like C. Run Valgrind to ensure your `delete` call properly cleaned up the heap allocation:
   ```bash
   valgrind --leak-check=full ./zombie
   # Expected: All heap blocks were freed -- no leaks are possible.
   ```
