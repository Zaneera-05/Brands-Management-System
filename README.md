# Brands-Management-System
<br># 🏷️ Brand Sales Management System (BMS)
> A console-based Brand Sales Management System built in **C++** as a semester project for the **Programming Fundamentals** course — **Fall 2024**, Riphah International University.
---
## 📋 Table of Contents
- [About the Project](#about-the-project)
- [Features](#features)
- [Screenshots](#screenshots)
- [System Architecture](#system-architecture)
- [Technical Details](#technical-details)
- [C++ Concepts & Language Features Used](#c-concepts--language-features-used)
- [Getting Started](#getting-started)
- [Default Login Credentials](#default-login-credentials)
- [Usage Guide](#usage-guide)
- [Project Structure](#project-structure)
- [Limitations & Future Scope](#limitations--future-scope)
- [Team Members](#team-members)
- [License](#license)
---
## 📖 About the Project
The **Brand Sales Management System** is a command-line application designed to manage the core operations of a brand's sales workflow. It provides a centralized interface for managing **Sales Records**, **Customer Information**, and **Discount Offers** — all protected behind a simple authentication system.
This project demonstrates the practical application of **Programming Fundamentals** concepts using C++ including structures, arrays, functions, control flow, and modular programming.
---
## ✨ Features
### 🔐 Authentication
- Username & password-based login system
- Access control — program exits on failed login
### 💰 Sales Management
| Operation | Description |
|-----------|-------------|
| **Add Sale** | Create a new sale record with automatic 15% tax calculation |
| **View Sales** | Display all existing sale records |
| **Search Sale** | Find a specific sale by its ID |
| **Update Sale** | Modify customer name and amount of an existing sale |
| **Delete Sale** | Remove a sale record from the system |
### 👥 Customer Management
| Operation | Description |
|-----------|-------------|
| **Add Customer** | Register a new customer with ID, name, and contact |
| **View Customers** | List all registered customers |
| **Search Customer** | Look up a customer by their ID |
| **Update Customer** | Edit customer name and contact information |
| **Delete Customer** | Remove a customer from the system |
### 🏷️ Discount Management
| Operation | Description |
|-----------|-------------|
| **Add Discount** | Create a new discount offer with description and percentage |
| **View Discounts** | Display all active discount offers |
| **Update Discount** | Modify discount description and percentage |
| **Delete Discount** | Remove a discount offer |
### 🎨 Colored Console Output
- Uses Windows Console API to render **color-coded text** for better readability
- Different colors for headings, prompts, success messages, and error messages
---
## 🏗️ System Architecture
```
┌──────────────────────────────────────────────────┐
│                   main()                         │
│              (Program Entry Point)               │
│                     │                            │
│              ┌──────┴──────┐                     │
│              │   login()   │                     │
│              └──────┬──────┘                     │
│                     │ (on success)               │
│         ┌───────────┼───────────┐                │
│         ▼           ▼           ▼                │
│  ┌─────────────┐ ┌──────────┐ ┌──────────────┐  │
│  │    Sales     │ │ Customer │ │   Discount   │  │
│  │  Management  │ │Management│ │  Management  │  │
│  ├─────────────┤ ├──────────┤ ├──────────────┤  │
│  │ addSale()   │ │addCust() │ │addDiscount() │  │
│  │ viewSales() │ │viewCust()│ │viewDiscounts│  │
│  │ searchSale()│ │searchC() │ │updateDisc()  │  │
│  │ updateSale()│ │updateC() │ │deleteDisc()  │  │
│  │ deleteSale()│ │deleteC() │ │              │  │
│  └─────────────┘ └──────────┘ └──────────────┘  │
│                                                  │
│  ┌──────────────────────────────────────────┐    │
│  │          Data Layer (Arrays)             │    │
│  │  Sales[100] │ Customers[100] │ Disc[100] │    │
│  └──────────────────────────────────────────┘    │
└──────────────────────────────────────────────────┘
```
---
## 🔧 Technical Details
| Attribute | Detail |
|-----------|--------|
| **Language** | C++ |
| **Standard** | C++11 or later |
| **Platform** | Windows (uses `<windows.h>`) |
| **IDE Compatibility** | Dev-C++, Code::Blocks, Visual Studio, MinGW g++ |
| **Lines of Code** | ~626 |
| **Source File** | `PF Project BMS Sytem.cpp` |
| **Data Storage** | In-memory (arrays with pre-loaded sample data) |
| **Max Records** | 100 per entity (Sales, Customers, Discounts) |
| **Tax Rate** | Fixed at 15% (applied automatically on sales) |
---
## 📚 C++ Concepts & Language Features Used
### 1. **Structures (`struct`)**
User-defined data types to model real-world entities:
```cpp
struct Sale {
    int saleID;
    string customerName;
    float amount;
    float tax;
    float totalAmount;
};
```
Three structures are used: `Sale`, `Customer`, and `Discount` — each encapsulating related data fields.
### 2. **Arrays (Static Arrays)**
Fixed-size arrays of structures for in-memory data storage:
```cpp
Sale sales[100];
Customer customers[100];
Discount discounts[100];
```
Arrays serve as a simple database, supporting up to 100 records per entity.
### 3. **Functions (Modular Programming)**
The program is decomposed into **14+ functions**, each responsible for a single operation:
- `addSale()`, `viewSales()`, `searchSale()`, `updateSale()`, `deleteSale()`
- `addCustomer()`, `viewCustomers()`, `searchCustomer()`, `updateCustomer()`, `deleteCustomer()`
- `addDiscount()`, `viewDiscounts()`, `updateDiscount()`, `deleteDiscount()`
- `login()`, `setColor()`
This demonstrates the **separation of concerns** principle.
### 4. **Control Structures**
- **`do-while` loop** — Main menu runs repeatedly until the user selects "Exit"
- **`switch-case`** — Menu-driven navigation with nested switch statements
- **`for` loops** — Iteration over arrays for viewing, searching, and deleting records
- **`if-else`** — Conditional logic for authentication and input validation
### 5. **Constants (`const`)**
Global constants for storing login credentials:
```cpp
const string Username = "Programmer";
const string Password = "123bms";
```
### 6. **Boolean Return Type (`bool`)**
The `login()` function returns `true` or `false` to control program access:
```cpp
bool login();
```
### 7. **String Handling**
- `<string>` library for `std::string` operations
- `<cstring>` for C-style string support
- `getline()` for reading full-line input (handles spaces in names)
- `cin.ignore()` to flush the input buffer when mixing `cin >>` and `getline()`
### 8. **Pass-by-Value & Global State**
- Global arrays and counters (`saleCount`, `customerCount`, `discountCount`) manage state
- Functions operate directly on global data — a procedural programming approach
### 9. **Array Element Shifting (Deletion Algorithm)**
Records are deleted by shifting subsequent elements left:
```cpp
for (int j = i; j < saleCount - 1; j++) {
    sales[j] = sales[j + 1];
}
saleCount--;
```
This is a classic **linear deletion** technique for array-based storage.
### 10. **Windows API — Console Text Coloring**
Uses `<windows.h>` for colored console output:
```cpp
void setColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}
```
| Color Code | Color | Usage |
|------------|-------|-------|
| 1 | Blue | Input prompts |
| 2 | Green | Success messages |
| 3 | Aqua | Sub-menu options |
| 4 | Red | Error messages |
| 5 | Purple | Section headers |
| 6 | Yellow | Data records |
| 7 | White | Default text |
| 9 | Light Blue | Login prompts |
### 11. **Automatic Tax Calculation**
Demonstrates arithmetic operations with computed fields:
```cpp
sales[saleCount].tax = sales[saleCount].amount * 0.15;       // 15% tax
sales[saleCount].totalAmount = sales[saleCount].amount + sales[saleCount].tax;
```
### 12. **Pre-loaded Sample Data (Array Initialization)**
Arrays are initialized with sample records using aggregate initialization:
```cpp
Sale sales[100] = {
    {1, "Sana Khan", 400, 60, 460},
    {2, "Hina Ali", 300, 45, 345},
    // ...
};
```
### 13. **`system()` Calls**
- `system("Cls")` — Clears the console screen between menu transitions for a cleaner UI experience
### 14. **Function Prototypes (Forward Declarations)**
All functions are declared before `main()` and defined after, following proper C++ program structure:
```cpp
void addSale();
void viewSales();
// ... other declarations
```
### 15. **Namespace Usage**
```cpp
using namespace std;
```
Brings the entire `std` namespace into scope, avoiding repetitive `std::` prefixes.
---
## 🚀 Getting Started
### Prerequisites
- A **C++ compiler** supporting C++11 or later (e.g., MinGW g++, MSVC)
- **Windows OS** (required for `<windows.h>` console coloring)
### Compilation & Execution
**Using g++ (MinGW):**
```bash
g++ -o BMS "PF Project BMS Sytem.cpp" -std=c++11
./BMS.exe
```
**Using Dev-C++ / Code::Blocks:**
1. Open the `.cpp` file in your IDE
2. Click **Compile & Run** (or press `F11`)
---
## 🔑 Default Login Credentials
| Field | Value |
|-------|-------|
| **Username** | `Programmer` |
| **Password** | `123bms` |
> ⚠️ Credentials are hardcoded as constants. Three failed attempts will not lock the account — a single failure exits the program.
---
## 📘 Usage Guide
1. **Launch** the application and enter the login credentials
2. **Main Menu** — Choose from:
   - `1` → Sales Management
   - `2` → Customer Management
   - `3` → Discount Management
   - `4` → Exit
3. **Sub-menus** — Each module offers Add, View, Search*, Update, and Delete operations
4. Follow on-screen prompts to enter data
> *Search is available for Sales and Customers only.
---
## 📁 Project Structure
```
Brand-Sales-Management-System/
│
├── PF Project BMS Sytem.cpp    # Main source code (single-file application)
├── Artifact 1 PF.png           # Project cover page / title page
└── README.md                   # Project documentation (this file)
```
---
## ⚠️ Limitations & Future Scope
### Current Limitations
- **No persistent storage** — All data is lost when the program closes (in-memory only)
- **No input validation** — Entering a string when an integer is expected may cause unexpected behavior
- **Windows-only** — Depends on `<windows.h>` for console colors
- **Hardcoded credentials** — Login credentials cannot be changed at runtime
- **No duplicate ID check** — Users can add records with duplicate IDs
### Future Improvements
- 📂 **File I/O** — Save and load data from `.txt` or `.csv` files for persistence
- 🔒 **Hashed passwords** — Implement secure credential storage
- 🛡️ **Input validation** — Add type-checking and boundary validation
- 🔍 **Search by name** — Allow searching customers/sales by name (partial match)
- 📊 **Sales analytics** — Generate reports with total revenue, top customers, etc.
- 🐧 **Cross-platform colors** — Use ANSI escape codes for Linux/macOS support
---
## 👥 Team Members
| Name | SAP ID | Program | Email |
|------|--------|---------|-------|
| **Zaneera Bint E Zahid** | **65326** | **BS SE** | **ZBZ201105@outlook.com** |
| Malaika | 63744 | BS SE | malaikaf887@gmail.com |
| Laiba Fatima | 64885 | BS SE | Laibafatima252005@gmail.com |

**Institution:** Riphah International University  
**Course:** Programming Fundamentals — Fall 2024
---
## 📄 License
This project is developed for academic purposes as part of the BS Software Engineering curriculum at Riphah International University. Feel free to use it as a learning reference.
---
