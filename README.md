# Student Expense Tracker (C Language)
Project Name: Personal Expense Tracker
Batch: Batch 52
Team: Team 08

Team Members

Anurag Rana - 590032955

Ayush Kumar - 590043117

Tinku - 590042452

## 📌 Project Overview

The **Student Expense Tracker** is a menu-driven console application developed using the C programming language. It helps students manage and monitor their daily expenses, organize spending into different categories, and keep track of their monthly budget.

The program provides simple expense management features such as adding, viewing, editing, and deleting expenses, along with generating category-wise and monthly spending reports.

## ✨ Features

1. **Set Monthly Budget** – Set a budget for a particular month and year.
2. **Add Expense** – Record expenses with a description, month, year, category, and amount.
3. **View All Expenses** – Display all recorded expenses.
4. **Total Expenses** – Calculate the total amount spent.
5. **Category Report** – View spending in different categories and identify the highest spending category.
6. **Check Remaining Budget** – Calculate the remaining budget or show how much the budget has been exceeded.
7. **Monthly Report** – Generate a monthly spending report with category-wise totals.
8. **Edit Expense** – Modify the details of an existing expense.
9. **Delete Expense** – Remove an expense from the records.
10. **Exit** – Close the application.

## 📂 Expense Categories

The project includes four predefined expense categories:

- Food
- Travel
- Books
- Entertainment

## 🛠️ Technologies Used

- **Programming Language:** C
- **Compiler:** GCC
- **Editor:** Visual Studio Code
- **Header Files:** `stdio.h`, `string.h`

## 🧠 C Programming Concepts Used

This project demonstrates the practical implementation of:

- Variables and Data Types
- Arrays and Two-Dimensional Arrays
- Strings and String Handling
- Structures of Menu-Driven Programming using `do-while`
- `switch-case` Statements
- Conditional Statements (`if-else`)
- Loops (`for` and `do-while`)
- Functions from the String Library (`strcpy`)
- Input and Output Operations
- Basic Data Validation
- Array Traversal and Manipulation

## ▶️ How to Run the Project

### Step 1: Clone the Repository

```bash
git clone YOUR_REPOSITORY_URL
```

### Step 2: Open the Project Folder

```bash
cd YOUR_PROJECT_FOLDER
```

### Step 3: Compile the Program

```bash
gcc expense_tracker.c -o expense_tracker
```

### Step 4: Run the Program

**Windows:**

```bash
.\expense_tracker.exe
```

**Linux / macOS:**

```bash
./expense_tracker
```

## 📋 Main Menu

```text
===== STUDENT EXPENSE TRACKER =====

1. Set Monthly Budget
2. Add Expense
3. View All Expenses
4. Total Expenses
5. Category Report
6. Check Remaining Budget
7. Monthly Report
8. Edit Expense
9. Delete Expense
10. Exit

Enter choice:
```

## 📊 Example Usage

Suppose a student records the following expenses:

| Category | Amount |
|---|---:|
| Food | ₹2,000 |
| Travel | ₹1,000 |
| Books | ₹1,500 |
| Entertainment | ₹500 |
| **Total** | **₹5,000** |

If the monthly budget is ₹6,000:

- Total Expenses: ₹5,000
- Remaining Budget: ₹1,000

## ⚠️ Input Validation

The program checks several inputs to prevent invalid records:

- Month must be between 1 and 12.
- Year must be between 2000 and 2100.
- Expense amount must be greater than zero.
- Category must be selected from the four available categories.
- Expense storage is limited to 100 records.
- Invalid expense numbers are rejected during editing and deletion.

## 🔒 Current Limitations

- Expenses are stored in arrays during program execution.
- Data is not permanently saved in a file or database.
- All recorded expenses are lost when the program exits.
- Only one monthly budget can be configured at a time.
- The program supports four predefined expense categories.

## 🚀 Future Improvements

Possible improvements for future versions:

- File handling to save expenses permanently.
- Multiple monthly budget records.
- Custom expense categories.
- Password-based access.
- Graphical representation of expenses.
- Export monthly reports to text or CSV files.

## 👨‍💻 Author

**Developed as a C Programming Project**

This project was created to practice fundamental C programming concepts through a practical student expense management application.

---

## 🤖 AI Assistance Disclosure

AI tools were used as a supporting resource during the development of this project. AI assistance was primarily used for understanding C programming concepts, reviewing and improving the code, debugging errors, and preparing project documentation.

The final program was reviewed, tested, and understood by the team members. The project was developed for educational purposes as part of our C programming coursework.

⭐ If you find this project useful, consider giving the repository a star!
