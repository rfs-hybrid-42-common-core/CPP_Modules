# 🟢 Exercise 00: Megaphone

## 📝 Objective
Create a program that takes command-line arguments, converts all lowercase letters to uppercase, and prints the concatenated result to the standard output. If no arguments are provided, it must output a specific default feedback noise.

## 💡 The Logic

This exercise serves as an icebreaker to transition from procedural C to Object-Oriented C++. It forces you to abandon C-style functions like `printf` or `write` in favor of standard C++ I/O streams.

1. **Standard I/O Streams:** Instead of relying on file descriptors, we use `std::cout` and the insertion operator `<<` to direct characters to the standard output, ending the line with `std::endl`.
2. **String Objects:** Rather than manually managing `char *` arrays and looking for null terminators, we cast the `argv` elements directly into `std::string` objects. This allows us to use built-in C++ member functions like `.length()` to safely iterate over the text.
3. **Type Casting:** We iterate through the string and apply `std::toupper()` to capitalize the letters. Because `toupper` returns an `int`, we use C++'s `static_cast<char>(...)` to explicitly convert the integer back into a printable character, demonstrating early best practices in C++ type safety.

## 🛠️ Step-by-Step Solution

1. **The Code:**
   *Check out the source files here:*
   - **[`megaphone.cpp`](megaphone.cpp)**
   - **[`Makefile`](Makefile)**

2. **Testing Edge Cases:**
   Compile the program and compare your output directly against the subject's expected results:
   ```bash
   make
   
   # Test 1: Standard lowercase to uppercase conversion
   ./megaphone "shhhhh... I think the students are asleep..."
   # Expected: SHHHHH... I THINK THE STUDENTS ARE ASLEEP...
   
   # Test 2: Multiple arguments and special characters
   ./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
   # Expected: DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF.
   
   # Test 3: No arguments (Default fallback)
   ./megaphone
   # Expected: * LOUD AND UNBEARABLE FEEDBACK NOISE *
   ```
