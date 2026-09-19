# 🟢 Exercise 00: Bitcoin Exchange

## 📝 Objective
Create a program that calculates the value of a specific amount of Bitcoin on a given date. The program must ingest a historical exchange rate database (`data.csv`) and evaluate a secondary user-provided input file containing dates and values. It must strictly validate calendar dates, enforce value limits, and gracefully handle formatting errors without crashing.

## 💡 The Logic

This exercise is a masterclass in **Associative Containers**, **File I/O (`<fstream>`)**, and **Algorithmic Searching**.

1. **`std::map` & Chronological Sorting:** 
   Because dates in the `YYYY-MM-DD` format naturally sort chronologically via standard string comparison (e.g., `"2012-01-11"` > `"2011-01-03"`), `std::map<std::string, double>` is the perfect container. Implemented under the hood as a Red-Black Tree, the `std::map` automatically sorts the historical database upon insertion, guaranteeing ordered data without ever calling `std::sort`.
2. **$O(\log N)$ Approximation (`lower_bound`):** 
   The program must find the exact exchange rate for a given date, or the closest *preceding* date if an exact match isn't available. Instead of iterating through the entire database ( $O(N)$ ), the program uses `_database.lower_bound(date)`. This algorithm executes a highly optimized binary search ( $O(\log N)$ ) to find the nearest chronological match, stepping back one node (`--it`) if the exact date is missing.
3. **Robust Parsing (`std::ifstream` & `std::istringstream`):** 
   C-style string manipulation is entirely bypassed in favor of C++ stream extraction. The parser dynamically isolates tokens using `std::getline` with custom delimiters (`','` for the database, `'|'` for the input). It also leverages `iss.fail()` and `iss.eof()` to detect trailing garbage characters that silent parsers (like `atof`) would dangerously ignore.
4. **Strict Calendar Validation:** 
   Before querying the map, dates undergo strict validation. The program structurally maps the hyphens and mathematically verifies month boundaries, 30-day months, and dynamically calculates Gregorian leap years to validate February bounds.
5. **The "Soft-Fail" Loop & Polymorphism:** 
   When parsing the user's input file, encountering a bad date or negative value should *not* crash the program. The execution is wrapped in a "soft-fail" `while` loop: it attempts to process a line, and if a custom exception (e.g., `TooLargeValueException`, `InvalidDateException`) is thrown, it is caught polymorphically via the base `BitcoinExchange::Exception`. The loop prints the exact error to `stderr` and seamlessly continues to the next line.

## 🛠️ Step-by-Step Solution

1. **The Code:**
   *Check out the source files here:*
   - **[`assets/data.csv`](assets/data.csv)**
   - **[`assets/input.txt`](assets/input.txt)**
   - **[`inc/BitcoinExchange.hpp`](inc/BitcoinExchange.hpp)** / **[`src/BitcoinExchange.cpp`](src/BitcoinExchange.cpp)**
   - **[`src/main.cpp`](src/main.cpp)**
   - **[`Makefile`](Makefile)**

3. **Testing the Exchange Calculator:**
   Compile the program and provide the input file to observe the date approximations and error-handling loop.
   *(Note: Ensure `data.csv` is located in your execution directory as targeted by the program).*
   ```bash
   make
   
   ./btc assets/input.txt
   
   # Output Analysis:
   # 1. Exact Match: 2012-01-11 easily finds its exact map key and calculates the multiplier.
   # 2. Approximation: 2011-01-09 does not exist in the database. lower_bound steps back to 2011-01-07 to apply the 0.32 rate.
   # 3. Calendar Errors: 2001-42-42 is intercepted by the mathematical date validator and throws an InvalidDateException.
   # 4. Limit Errors: 2147483648 is intercepted by the value validator and throws a TooLargeValueException.
   # 5. Soft-Fail Execution: Despite the errors, the program never crashes. It prints the respective std::cerr messages and continues evaluating the rest of the file.
   ```
