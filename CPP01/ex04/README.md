# 🟢 Exercise 04: Sed is for losers

## 📝 Objective
Create a program that takes three parameters: a filename, and two strings (`s1` and `s2`). It must read the file, replace every occurrence of `s1` with `s2`, and save the result into a new file named `<filename>.replace`. Using C file manipulation functions is strictly forbidden, as is the use of `std::string::replace`.

## 💡 The Logic

This exercise introduces the C++ `<fstream>` library and forces you to think carefully about string manipulation algorithms to avoid catastrophic memory or infinite loop bugs.

1. **File Streams (`<fstream>`):** To handle files in C++, we use stream objects. `std::ifstream` (Input File Stream) is used to read the original file, while `std::ofstream` (Output File Stream) is used to create and write to the `.replace` file.
2. **Buffer Reading (`<sstream>`):** Rather than reading the file line-by-line (which can break if `s1` spans across a newline in specific edge cases), the program uses `std::ostringstream` to read the entire file buffer into a single `std::string` in memory at once.
3. **The Infinite Loop Trap:** The most common mistake in this exercise is replacing `s1` with `s2` *in-place* within the string. If `s1` is "apple" and `s2` is "pineapple", an in-place replacement will endlessly find "apple" inside the newly inserted "pineapple", causing an infinite loop. 
4. **The `substr` Solution:** To bypass the infinite loop trap and the forbidden `replace` method, the `Replacer::replace` function iterates through the text using `std::string::find()`. It extracts the unmodified text *before* the match using `substr()`, writes it directly to the `outfile`, and then writes `s2` directly to the `outfile`. It repeats this process until `find()` returns `std::string::npos` (no match found).

## 🛠️ Step-by-Step Solution

1. **The Code:**
   *Check out the source files here:*
   - **[`inc/Replacer.hpp`](inc/Replacer.hpp)** / **[`src/Replacer.cpp`](src/Replacer.cpp)**
   - **[`src/main.cpp`](src/main.cpp)**
   - **[`Makefile`](Makefile)**

2. **Testing Edge Cases & Permissions:**
   Compile the program and run these specific tests to ensure your stream handlers and string parsers are robust:
   ```bash
   make
   
   # Test 1: Standard Replacement (Using the Makefile)
   ./replacer Makefile clean dirty
   # Check the newly created Makefile.replace file to see if "clean" became "dirty".
   
   # Test 2: Reverting the Replacement (Testing the infinite loop trap)
   ./replacer Makefile.replace dirty clean
   # Compare Makefile.replace.replace with the original Makefile. They should be identical!
   
   # Test 3: Empty Search String
   ./replacer Makefile "" "test"
   # Should cleanly exit with an error message: "No string to be replaced was found".
   
   # Test 4: File Permission Errors
   touch locked.txt
   chmod 000 locked.txt
   ./replacer locked.txt "a" "b"
   # std::ifstream should fail to open the file and safely output an error without segfaulting.
   
   # Clean up
   rm locked.txt Makefile.replace Makefile.replace.replace
   ```
