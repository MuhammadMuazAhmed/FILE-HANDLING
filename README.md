# Student Record Management System in C++

This repository presents a **Student Record Management System** implemented in C++. The project allows managing academic records of students, including personal details, subject marks, CGPA, entry/exit times, and file-based data persistence.

---

## About the Code

This C++ program simulates a small-scale academic database system. It offers functionality to:

- Create a new student database
- Append, update, and delete records
- Search student records by registration number
- Save records to and load records from a text file
- Display formatted student details including marks and CGPA
- Validate inputs and ensure robust error handling

It uses **OOP principles**, **structures**, and **file I/O**, along with formatting utilities to maintain data integrity and user experience.

---

## How It Works

1. The `student` class stores personal and academic data for each student, including marks, CGPA, and entry/exit time.
2. The `airtime` class tracks student arrival and departure using hours, minutes, and seconds.
3. The `Date` struct is used to manage birth and admission dates.
4. All student records are stored in a fixed-size array, and basic operations are performed using menu-based user interaction.
5. Data is saved to or read from `student_details.txt` using standard C++ file handling.

---

## Class Breakdown

| Class/Struct   | Description                                                  |
|----------------|--------------------------------------------------------------|
| `student`      | Manages all student details, including CGPA, marks, and time |
| `airtime`      | Tracks entry and exit time using hours, minutes, seconds     |
| `Date`         | Struct to handle date of birth and admission                 |

---
## UML Diagram

```plaintext
         +--------------------+
         |      Date          |
         +--------------------+
         | - day: int         |
         | - month: int       |
         | - year: int        |
         +--------------------+

         +--------------------+
         |     airtime        |
         +--------------------+
         | - hrs: int         |
         | - mins: int        |
         | - sec: int         |
         +--------------------+
         | +setter1()         |
         | +getter1()         |
         +--------------------+

         +---------------------------------------------------+
         |                    student                        |
         +---------------------------------------------------+
         | - regNumber: int                                  |
         | - name: string                                    |
         | - fatherName: string                              |
         | - marks[5]: int                                   |
         | - totalMarks: int                                 |
         | - dob: Date                                       |
         | - doa: Date                                       |
         | - cgpa: float                                     |
         | - IT: airtime                                     |
         | - OT: airtime                                     |
         +---------------------------------------------------+
         | +setter()                                         |
         | +getter()                                         |
         | +regnum(): int                                    |
         | +savetofile(student[], int)                       |
         | +readtofile()                                     |
         +---------------------------------------------------+
```
## Menu Options

Create Database

Append Record

Search Record

Update Record

Delete Record

Display Record

Save to File

Read from File

Exit

---

## Sample Code

Here’s an example usage from the main menu:

```cpp
student s[MAXSTUDENTS];
int n = 0;

// Create initial database
createDatabase(s, n);

// Append a new student
appendRecord(s, n);

// Save all records to file
for(int i = 0; i < n; i++) {
    s[i].savetofile(s, i);
}

// Load and display records from file
s->readtofile();
```
## File Storage Format
Data is stored in student_details.txt in a space-separated format:

1001 Alice John 78 85 90 88 92 433 3.5

1002 Bob Smith 70 65 80 72 76 363 2.8

Each line includes:

[RegNo] [Name] [FatherName] [Marks x5] [Total] [CGPA]

## Input Validation Highlights
Registration number must be a 4-digit number

Names must contain only alphabets, spaces, or periods

Marks must be between 0 and 100

CGPA must be between 0.0 and 4.0

Entry/Exit time must be valid in 24-hour format

DOB and DOA must be logically consistent
