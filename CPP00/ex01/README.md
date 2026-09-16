# 🟢 Exercise 01: My Awesome PhoneBook

## 📝 Objective
Write a program that behaves like an 80s crappy awesome phonebook software. You must implement two classes (`PhoneBook` and `Contact`) to store up to 8 contacts. If the user attempts to add a 9th contact, the program must replace the oldest one. The program accepts three commands: `ADD`, `SEARCH`, and `EXIT`. Importantly, dynamic allocation (`new`) is strictly forbidden.

## 💡 The Logic

This exercise introduces proper Object-Oriented encapsulation, state management, and robust stream manipulation (handling formatting and EOFs).

1. **Class Encapsulation:** The data is split into two logical entities. The `Contact` class acts as a data container, holding private attributes for the required fields (first name, last name, nickname, phone number, darkest secret) and handling its own validation. The `PhoneBook` class acts as the application controller, managing the main CLI loop and storing exactly 8 `Contact` instances.
2. **The Circular Buffer:** Because dynamic allocation is forbidden, we cannot use dynamically resizing vectors or arrays. The `PhoneBook` initializes a fixed `Contact _contacts[8]` array. A tracking variable (`_currentIndex`) increments sequentially. When it hits the limit, a modulo operation (`_currentIndex = (_currentIndex + 1) % _maxContacts`) loops it back to index `0`, effortlessly overwriting the oldest contact.
3. **Pointer-to-Member-Functions:** To avoid massive blocks of repetitive `if/else` logic when prompting for 5 different contact fields, the code uses an elegant C++ paradigm: pointer-to-member functions (`bool (Contact::*setter)(std::string const &)`). This allows `_promptField` to dynamically bind user input to the correct setter method inside the `Contact` class.
4. **Stream Formatting & Truncation:** The `SEARCH` command requires data to be displayed in a 4-column grid. Each column must be 10 characters wide, separated by a pipe `|`, and right-aligned. If text exceeds 10 characters, it must be truncated and end with a dot `.`. This is achieved using `std::setw(10)` from the `<iomanip>` library, combined with `std::string::substr`.
5. **Robust Input Handling:** A common C++ pitfall is `Ctrl+D` (EOF). If `std::getline(std::cin, input)` encounters an EOF, the input stream breaks, which can cause an infinite loop. The program proactively catches `std::cin.eof()` and securely exits. Furthermore, all fields are trimmed of whitespaces and validated to ensure no field is left entirely empty.

## 🛠️ Step-by-Step Solution

1. **The Code:**
   *Check out the source files here:*
   - **[`inc/Contact.hpp`](inc/Contact.hpp)** / **[`src/Contact.cpp`](src/Contact.cpp)**
   - **[`inc/PhoneBook.hpp`](inc/PhoneBook.hpp)** / **[`src/PhoneBook.cpp`](src/PhoneBook.cpp)**
   - **[`inc/utils.hpp`](inc/utils.hpp)** / **[`src/utils.cpp`](src/utils.cpp)**
   - **[`src/main.cpp`](src/main.cpp)**
   - **[`Makefile`](Makefile)**

2. **Testing Edge Cases:**
   Compile the program and test its structural integrity against common invalid inputs:
   ```bash
   make
   ./phoneBook
   
   # Test 1: Empty Fields
   # Run the ADD command and try pressing ENTER without typing anything, or just type spaces. 
   # The program should continuously prompt you until a valid string is entered.
   
   # Test 2: The Circular Buffer (The 9th Contact)
   # Run the ADD command 9 times in a row.
   # Run SEARCH. Index 0 should now display the 9th contact you entered, proving the oldest was overwritten.
   
   # Test 3: Truncation Validation
   # ADD a contact with a first name longer than 10 characters (e.g., "Christopher").
   # Run SEARCH. The grid should display "Christoph." exactly 10 characters wide.
   
   # Test 4: SEARCH Menu Errors
   # Run SEARCH and input invalid indices:
   # - "8" (Out of range)
   # - "-1" (Invalid)
   # - "abc" (Not a number)
   # - Leave blank and press ENTER.
   # The program should gracefully handle all and return to the main menu.
   
   # Test 5: The EOF Trap
   # While the program is prompting you for a command (or inside the ADD prompt), press Ctrl+D.
   # The program should instantly detect the broken stream, print a warning, and exit cleanly.
   ```
