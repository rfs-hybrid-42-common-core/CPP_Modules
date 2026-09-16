# 🟢 Exercise 02: The Job Of Your Dreams

## 📝 Objective
Reconstruct a missing `Account.cpp` implementation file that was "deleted by mistake". You are provided with the header file (`Account.hpp`), the main test file (`tests.cpp`), and a reference log file (`19920104_091532.log`). Your goal is to write the C++ implementation so that your program's output perfectly matches the provided log file, with the exception of the timestamps. 

## 💡 The Logic

This exercise is a puzzle designed to teach you about shared class states, object lifecycles, and standard library time functions.

1. **Static Class Members:** Notice that `Account.hpp` defines attributes like `static int _nbAccounts;`. Unlike regular attributes (which belong to a specific instance, like a single bank account), *static* attributes belong to the class itself. They are shared across all instances. We use them here to track the global state of the bank (total accounts, total money, total transactions). These must be initialized at the very top of `Account.cpp` outside of any constructor.
2. **Static Member Functions:** Functions like `displayAccountsInfos()` are also static. They do not operate on a specific object instance, meaning they don't have a `this` pointer and can only access other static variables.
3. **Initialization Lists:** When a new `Account` is instantiated, the constructor uses an initialization list (e.g., `Account::Account(void) : _accountIndex(_nbAccounts), _amount(0)...`) to immediately assign the current global account count to the instance's unique index, before incrementing the global count.
4. **Timestamps (`<ctime>`):** To match the `[YYYYMMDD_HHMMSS]` format in the logs, the private `_displayTimestamp()` function utilizes the C standard library. It fetches the raw time with `std::time()`, converts it to local time via `std::localtime()`, and formats the output string using `std::strftime()`.
5. **The Destructor Lifecycle:** When `tests.cpp` finishes executing, the vector holding the accounts goes out of scope. This automatically triggers the `~Account(void)` destructor for every single instance, deducting their balances from the global total and printing the `;closed` log. (Note: Destructors may be called in reverse order depending on your compiler/OS, which is completely normal).

## 🛠️ Step-by-Step Solution

1. **The Code:**
   *Check out the source files here. Note that only `Account.cpp` and `Makefile` were created from scratch; the rest were provided by the subject.*
   - **[`assets/19920104_091532.log`](assets/19920104_091532.log)** *(Provided Reference)*
   - **[`inc/Account.hpp`](inc/Account.hpp)** *(Provided)* / **[`src/Account.cpp`](src/Account.cpp)** *(Implemented)*
   - **[`src/tests.cpp`](src/tests.cpp)** *(Provided)*
   - **[`Makefile`](Makefile)** *(Implemented)*

2. **Testing Edge Cases & Log Comparison:**
   Because the timestamps in your program will reflect the current real-world time, a direct `diff` with the 1992 log file will fail. You can use the `cut` command to strip the first 18 characters (the timestamp) from both outputs to verify your logic is mathematically flawless:
   
   ```bash
   make
   
   # 1. Generate your program's output and save it to a file
   ./jobOfYourDreams > my_output.log
   
   # 2. Use 'cut' to strip the timestamps (characters 1-18) from both files and compare
   diff <(cut -c 19- my_output.log) <(cut -c 19- assets/19920104_091532.log)
   
   # If the diff command outputs nothing, your implementation is 100% correct!
   ```
