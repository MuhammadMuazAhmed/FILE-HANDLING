#pragma once            // Preprocessor directive to ensure this header is included only once in a compilation
#include <cctype>
#include "Class_dec.h" // Included custom header file

// Function to check if a string contains only alphabetic characters, spaces, and periods
bool isNameValid(const string& s) {
    for (char ch : s) {
        if (!isalpha(ch) && ch != ' ' && ch != '.') {
            return false;
        }
    }
    return true;
}

// Function to return the registration number of the student
int student::regnum() {
    return regNumber;
}

// Function to set the airtime (hh, mm, ss)
void airtime::setter1() {
    do {
        cout << "Enter hours:";
        do {
            if (!(cin >> hrs)) {
                cout << "Invalid input. Please enter valid hrs." << endl;
                cin.clear();
                while (cin.get() != '\n'); // Consume the entire line.
            }
            else
                break;
        } while (true);
        cout << "Enter minutes:";
        do {
            if (!(cin >> mins)) {
                cout << "Invalid input. Please enter valid mins." << endl;
                cin.clear();
                while (cin.get() != '\n'); // Consume the entire line.
            }
            else
                break;
        } while (true);
        cout << "Enter seconds:";
        do {
            if (!(cin >> sec)) {
                cout << "Invalid input. Please enter valid sec." << endl;
                cin.clear();
                while (cin.get() != '\n'); // Consume the entire line.
            }
            else
                break;
        } while (true);
        if (hrs >= 0 && hrs <= 23 && mins >= 0 && mins <= 59 && sec >= 0 && sec <= 59) {
            break;
        }
        else {
            cout << "Enter correct time:" << endl;
        }
    } while (true);
}


// Function to display the airtime in hh:mm:ss format
void airtime::getter1() {
    cout << setfill('0') << setw(2) << hrs << ":" << setw(2) << mins << ":" << setw(2) << sec << endl;
}

// Function to set student details
void student::setter() {
    cout << "Enter 4-digit Registration Number:" << endl;
    do {
        if (!(cin >> regNumber) || (regNumber <= 999 || regNumber >=10000)) {
            cout << "Invalid input. Please enter a valid 4-digit number." << endl;
            cin.clear();
            while (cin.get() != '\n'); // Consume the entire line.
        }
        else {
            break; // Break the loop when regNumber is valid.
        }
    } while (true);
    cout << "Enter Name:" << endl;
    cin.ignore();
    do {
        getline(cin, name);
        if (isNameValid(name)) {
            break;
        }
        else {
            cout << "Invalid name. Please enter a valid name." << endl;
        }
    } while (true);

    cout << "Enter Father's Name:" << endl;
    do {
        getline(cin, fatherName);
        if (isNameValid(fatherName)) {
            break;
        }
        else {
            cout << "Invalid name. Please enter a valid name." << endl;
        }
    } while (true);

    for (int i = 0; i < SUBJECT; i++) {
        cout << "Enter subject marks (0-100) for Subject " << i + 1 << ":" << endl;
        do {  
            if (!(cin >> marks[i]) || (marks[i] < 0 || marks[i] > 100)) {
                cout << "Invalid input. Please enter valid marks (0-100)." << endl;
                cin.clear();
                while (cin.get() != '\n'); // Consume the entire line.
            }
            else {
                break; // Break the loop when marks are valid.
            }
        } while (true);
        totalMarks += marks[i];
    }

    do {
        cout << "Enter date of birth of student (dd/mm/yyyy):" << endl;
        do {
            
            if (!(cin >> dob.day >> dob.month >> dob.year) || dob.day < 0 || dob.day > 31 || dob.month < 0 && dob.month > 12 || dob.year < 2000 || dob.year > 2022) {
                 cout << "Enter a valid date." << endl;
                 cin.clear();
                 while (cin.get() != '\n');
            }
            else {
                break;
            }
        } while (true);

        cout << "Enter date of admission of student (dd/mm/yyyy):" << endl;
        do {
            if (!(cin >> doa.day >> doa.month >> doa.year) || doa.day < 0 || doa.day > 31 || doa.month < 0 || doa.month > 12 || doa.year < 2000 || doa.year > 2022) {
                cout << "Enter a valid date." << endl;
                cin.clear();
                while (cin.get() != '\n');
            }
            else {
                break;
            }
        } while (true);

        if (dob.year == doa.year) {
            cout << "Date of Birth and Date of Admission can't have the same year." << endl;
        }
        else if (dob.year > doa.year) {
            cout << "Date of Birth must be less than doa" << endl;
        }
        else {
            break;
        }
    } while (true);

    cout << "Enter CGPA (0.0-4.0):" << endl;
    do {
        
        if (!(cin >> cgpa) || cgpa < 0 || cgpa > 4.0) {
            cout << "Enter valid cgpa" << endl;
            cin.clear();
            while (cin.get() != '\n');
        }
        else {
            break;
        }
    } while (true);
    cout << "Enter Entry time:24hrs format" << endl;
    IT.setter1();
    cout << "Enter Exit time:24hrs format" << endl;
    OT.setter1();
}

// Function to display student details
void student::getter() {
    cout << "Student Results for Registration Number " << regNumber << ":" << endl;
    cout << "----------------------------------------------" << endl;
    cout << "Name:\t\t " << name << endl;
    cout << "Father's Name:\t" << fatherName << endl;
    cout << "Subject\t\tMarks" << endl;
    cout << "----------------------------------------------" << endl;
    for (int j = 0; j < SUBJECT; j++) {
        cout << "Subject " << j + 1 << ":\t" << marks[j] << endl;
    }
    cout << "----------------------------------------------" << endl;
    cout << "Total Marks:\t" << totalMarks << " out of 500" << endl;
    cout << "CGPA:\t\t" << cgpa << endl;
    cout << "----------------------------------------------" << endl;
    cout << " Entry time:24hrs format" << endl;
    IT.getter1();
    cout << " Exit time:24hrs format" << endl;
    OT.getter1();
}
