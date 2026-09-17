# 🟢 Exercise 00: My First Class in Orthodox Canonical Form

## 📝 Objective
Create a class representing a fixed-point number that strictly adheres to the Orthodox Canonical Form (OCF). It must contain a private integer to store the raw value, and a private static constant integer (set to `8`) representing the number of fractional bits. The class must publicly implement a default constructor, a copy constructor, a copy assignment operator, a destructor, and the getter/setter methods `getRawBits` and `setRawBits`.

## 💡 The Logic

This exercise is the foundation for all future C++ modules. It forces you to implement the "Rule of Three" (or Four, in C++98), ensuring that your object handles its own instantiation, copying, and destruction safely.

1. **Orthodox Canonical Form (OCF):** To be OCF compliant, a class **must** explicitly define four specific member functions:
   - **Default Constructor:** `Fixed(void);` (Initializes the fixed-point value to `0`).
   - **Copy Constructor:** `Fixed(Fixed const & other);` (Creates a brand new object as a clone of an existing one).
   - **Copy Assignment Operator:** `Fixed& operator=(Fixed const & other);` (Replaces the data of an *already existing* object with the data from another).
   - **Destructor:** `~Fixed(void);` (Cleans up the object when it goes out of scope).
2. **Copy Constructor Delegation:** Instead of rewriting the exact same logic for copying data in both the Copy Constructor and the Assignment Operator, the Copy Constructor simply delegates the work to the Assignment Operator (`*this = other;`). This ensures the code remains DRY (Don't Repeat Yourself).
3. **Self-Assignment Protection:** Inside the Copy Assignment Operator, you will notice the check `if (this != &other)`. While harmless for this specific class since it only copies an `int`, this is a mandatory C++ best practice. If a class manages dynamic memory (`new`/`delete`), an object assigning itself to itself (`a = a`) could accidentally delete its own memory before copying it, causing a fatal crash.
4. **Trace Messages:** Every OCF function includes a `std::cout` print statement. This is exclusively to prove to the evaluator that the compiler is calling the exact methods you expect, in the exact order you expect, during the object lifecycle.

## 🛠️ Step-by-Step Solution

1. **The Code:**
   *Check out the source files here:*
   - **[`inc/Fixed.hpp`](inc/Fixed.hpp)** / **[`src/Fixed.cpp`](src/Fixed.cpp)**
   - **[`src/main.cpp`](src/main.cpp)**
   - **[`Makefile`](Makefile)**

2. **Testing the Object Lifecycle:**
   Compile the program and observe the exact sequence of trace messages. They prove how C++ handles object creation and assignments behind the scenes.
   ```bash
   make
   
   ./fixed
   
   # Output Analysis:
   # 1. 'Fixed a' calls the Default Constructor.
   # 2. 'Fixed b(a)' calls the Copy Constructor, which then calls the Copy Assignment Operator.
   # 3. 'Fixed c' calls the Default Constructor.
   # 4. 'c = b' calls the Copy Assignment Operator directly.
   # 5. The program prints the raw bits (0, 0, 0).
   # 6. Objects c, b, and a go out of scope, calling the Destructor three times in reverse order.
   ```
