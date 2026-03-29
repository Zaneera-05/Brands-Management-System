<br># 🏷️ Brand Sales Management System (BMS)

> A console-based Brand Sales Management System built in **C++** as a semester project for the **Programming Fundamentals** course — **Fall 2024**, Riphah International University.

---

## 📋 Table of Contents

- [About the Project](#about-the-project)
- [Features](#features)
- [Screenshots](#screenshots)
- [System Architecture](#system-architecture)
- [Technical Details](#technical-details)
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
| **Zaneera Bint E Zahid** | **65326** | **BS SE** | **ZBZ@outlook.com** |
| Malaika | 63744 | BS SE | malaikaf887@gmail.com |
| Laiba Fatima | 64885 | BS SE | Laibafatima252005@gmail.com |


**Institution:** Riphah International University  
**Course:** Programming Fundamentals — Fall 2024

---

## 📄 License

This project is developed for academic purposes as part of the BS Software Engineering curriculum at Riphah International University. Feel free to use it as a learning reference.

---

<p align="center">
  <b>⭐ If you found this project helpful, give it a star on GitHub! ⭐</b>
</p>
