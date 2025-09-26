# Student-Attendance-Management-System 📝

This project is a simple console-based application written in C that helps manage student attendance. It allows you to track attendance, display individual records, identify students with low attendance, and manage the student roster using dynamic memory allocation.

---

## ✨ Features

* **Manage Roster:** Add new students by name and roll number, or remove existing students from the class list.
* **Take Attendance:** Easily record attendance for all registered students over multiple days, marking each student as present or absent.
* **View Individual Records:** Display the complete attendance record for a specific student, including the total classes attended, total classes held, and their attendance percentage.
* **Identify Low Attendance:** Automatically generate a list of all students whose attendance is below a 75% threshold.
* **Menu-Driven Interface:** A simple and intuitive console menu to navigate through all the features of the application.

---

## 🛠️ Prerequisites

Before you begin, ensure you have a C compiler installed on your system.
* **GCC (GNU Compiler Collection):** You can verify your installation by running `gcc --version` in your terminal.

---

## ⚙️ Installation and Running

To get a local copy up and running, follow these simple steps.

1.  **Clone the repository:**
    ```sh
    git clone [https://github.com/prohansai/Student-Attendance-Management-System.git](https://github.com/prohansai/Student-Attendance-Management-System.git)
    ```
2.  **Navigate to the project directory:**
    ```sh
    cd Student-Attendance-Management-System
    ```
3.  **Compile the C code:**
    ```sh
    gcc main.c -o attendance_manager
    ```
4.  **Run the application:**
    ```sh
    ./attendance_manager
    ```

---
## 🚀 Usage

Once the program is running, you will be presented with a menu. Enter the number corresponding to the action you wish to perform:

1.  **Take Attendance:** Begin the process of marking students present or absent.
2.  **Display Attendance:** View the record of a specific student.
3.  **Display Low Attendance:** See the list of students with attendance below 75%.
4.  **Add a Student:** Add a new student to the roster.
5.  **Remove a Student:** Remove a student from the roster.
6.  **Exit:** Close the application.

---

## ⚙️ How It Works

* **Data Structure:** The system uses an array of structs to hold student data. Each struct contains the student's name, roll number, and their attendance records.

* **Dynamic Memory:** The program efficiently manages memory by using `malloc` and `realloc`. This allows the student roster to grow or shrink as students are added or removed, without a fixed size limit.

* **User Interaction:** The application is controlled through a simple, number-based menu in the console, making it easy to navigate between different functions like adding students, taking attendance, and viewing reports.

---

## 💡 Future Improvements

This project serves as a strong foundation. Future enhancements could include:

* **File I/O for Persistence:** Save the student roster and attendance data to a file (e.g., `.csv` or `.txt`) so that information is not lost when the program closes.
* **Data Export:** Add a feature to export attendance reports (e.g., low attendance list) to a file.
* **Improved User Interface:** Develop a more advanced command-line interface or a full graphical user interface (GUI) using a library like GTK.
* **Database Integration:** Store student and attendance data in a lightweight database like SQLite for more robust data management.
