# Console-Based Library Management System

## Overview
This is a **console-based library management system** built in C++ that allows users and admins to manage books and users. The system supports the following functionalities:

- **Admin Features:**
  - Add books
  - View books
  - Search books
  - Add users
  - View users
  - Borrow/Return books

- **User Features:**
  - View books
  - Search books
  - Borrow/Return books

- **Persistent Data:** All books and users are saved in files (`books.txt` and `users.txt`) so data is preserved between program runs.

- **Roles:** Admin and User roles with separate menus.

---

## Installation

### Prerequisites
- **Windows:** MSYS2 or MinGW compiler installed  
- **Linux/Mac:** g++ compiler installed  

### Steps
1. **Clone the repository:**
```bash
git clone <YOUR_REPOSITORY_URL>
cd Library-Management-System
```

2. **Compile the project:**

```bash
g++ src/*.cpp -Iinclude -o library
```

3. **Run the program:**

```bash
./library   # or library.exe on Windows
```

4. **Data folder:**
   Ensure the `data` folder exists in the project root with empty files:

```
data/books.txt
data/users.txt
```

---

## Usage

1. Choose your role: **Admin** or **User**
2. Follow the menu options to perform actions
3. All changes are automatically saved

---

## Sample Data

* `books.txt` contains sample books with ID, title, author, category, and availability
* `users.txt` contains sample users with ID and name

---

## Future Enhancements

* Search books by category or partial name
* Display borrowed books per user
* Sorting books by title, author, or ID
* Password-protected Admin login
* Graphical interface using C++ GUI libraries (e.g., Qt)
* Export reports in CSV or PDF format

---

## Author

* Salma Fouad
* GitHub: [Your GitHub URL]
