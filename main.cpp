#include <iostream>   // Standard input/output stream library (for input and output operations)
#include <string>     // Standard string library (for string data type) #include <cctype>   // Included the cctype library for character handling
#include <iomanip> 
#include <cctype>   // Included the iomanip library for formatting output
#include <fstream>
#include<algorithm>

using namespace std;

#define  MAXSTUDENTS  70 // Maximum number of students allowed in the system(70)
#define  SUBJECT 5       // Number of subjects (5)

// Class for tracking airtime
class airtime {
private:
    unsigned int hrs;  // Hours
    unsigned int mins; // Minutes
    unsigned int sec;  // Seconds
public:
    // Constructor for airtime class
    airtime(int hh = 0, int mm = 0, int ss = 0) :hrs(hh), mins(mm), sec(ss) {}

    // Function to set airtime values
    void setter1();

    // Function to get airtime values
    void getter1();
};
// Define a structure for Date
struct Date {
    int day;    // Day of the date
    int month;  // Month of the date
    int year;   // Year of the date
};

// Define a class for Student
class student {
private:
    int regNumber;      // Registration number of the student
    string name;        // Name of the student
    string fatherName;  // Father's name of the student
    int marks[SUBJECT]; // Marks in each subject (array)
    int totalMarks;     // Total marks obtained by the student
    Date dob;           // Date of birth of the student
    Date doa;           // Date of admission of the student
    float cgpa;         // Cumulative Grade Point Average (CGPA) of the student
    airtime IT;         //airtime objects to track incoming time
    airtime OT;         //airtime objects to track outgoing time
public:
    // Constructor for the student class
    student(int regno = 0, int totmarks = 0, int cgpa1 = 0, int marks1 = 0, int dob1 = 0, int doa1 = 0, int month1 = 0, int year1 = 0, int month2 = 0, int year2 = 0)
        : regNumber(regno), totalMarks(totmarks), cgpa(cgpa1), marks{ marks1 }, dob{ dob1, month1, year1 }, doa{ doa1, month2, year2 } {}

    // Function to set student details
    void setter();
    // Function to get student details
    void getter();
    // Function to return the registration number of the student
    int regnum(); 
    // Function for file saving
    void savetofile(student s[], int nn);
    // Function for file reading
    void readtofile();
};
void student::savetofile(student s[],int i){
    ofstream out;
    out.open("student_details.txt", ios::app);
    if (!out) {
        cout << "Unable to open file";
        exit(-1); // Exit if file opening fails
    }
    

    out<< s[i].regNumber<<" " ;
    out<< s[i].name<<" " ;
    out<< s[i].fatherName<<" " ;
    for (int j = 0; j < SUBJECT; j++) {
        out<< s[i].marks[j] <<" ";
    }
    out << s[i].totalMarks<<" ";
    out<<  s[i].cgpa << endl;
    out.close();
}
void student::readtofile() {
    ifstream in;
    in.open("student_details.txt", ios::in);
    if (!in) {
        cout << "Unable to open file";
        exit(-1); // Exit if file opening fails
    }

    while(in>>regNumber) {
        // in >> regNumber;
        in.ignore(); // Ignore the space after regNumber
        getline(in,name,' ');
        getline(in,fatherName,' ');
        for (int j = 0; j < SUBJECT; j++) {
            in >> marks[j];
        }
        in >> totalMarks;
        in >> cgpa;
        in.ignore(numeric_limits<streamsize>::max(), '\n');// Read newline character after cgpa
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
    }

    in.close();
}

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





// Function to create the student database
void  createDatabase(student s[], int nn) {
    
    if (nn > MAXSTUDENTS) {
        cout << "Error: Maximum capacity exceeded." << endl;
        cout << "You can enter data of first 70 students" << endl;
        nn = MAXSTUDENTS;
    }

    for (int i = 0; i < nn; i++) {
        cout << "Enter Student data:" << endl;
        s[i].setter();   
    }
}

// Function to append a student record
void appendRecord(student s[], int& num) {
    if (num == 70) {
        cout << "Database is full. Cannot add more students." << endl;
        return;
    }
    s[num].setter();
    ++num;
}
//Function to search record
int search(student s[], int numStudents) {
    int regNumber;
    int c = 1;
    cout << "Enter 4-digit Registration Number:" << endl;
    do {
        if (!(cin >> regNumber) || (regNumber <= 999 || regNumber >= 10000)) {
            cout << "Invalid input. Please enter a valid 4-digit number." << endl;
            cin.clear();
            while (cin.get() != '\n'); // Consume the entire line.
        }
        else {
            break; // Break the loop when regNumber is valid.
        }
    } while (true);
    for (int i = 0; i < numStudents; i++) {
        int reg = s[i].regnum();
        if (regNumber == reg) {
            cout << "Data found at " << c << endl;
            return c; // Stop searching once a match is found
        }
        else {
            c++;
        }
    }
    cout << "Record not found" << endl;
    return 0;
}


// Function to update student record by registration number
void updateRecord(student s[], int numStudents) {
    int regNumber;
    cout << "Enter 4-digit Registration Number:" << endl;
    do {
        if (!(cin >> regNumber) || (regNumber <= 999 || regNumber >= 10000)) {
            cout << "Invalid input. Please enter a valid 4-digit number." << endl;
            cin.clear();
            while (cin.get() != '\n'); // Consume the entire line.
        }
        else {
            break; // Break the loop when regNumber is valid.
        }
    } while (true);
    for (int i = 0; i < numStudents; i++) {
        int reg = s[i].regnum();
        if (reg== regNumber) {
            s[i].setter();
            return;
        }
    }cout << "Record not found for Registration Number: " << regNumber << endl;
}

// Function to display student results by registration number
void Display(student s[], int numStudents) {
    for (int i = 0; i < numStudents; i++)
    {
        cout << "Display of data:" << endl;
        s[i].getter();
    }
}
////Function to delete student record by registration number
void deleteRecord(student s[], int& numStudents) {
    int regNumber;
    cout << "Enter 4-digit Registration Number:" << endl;
    do {
        if (!(cin >> regNumber) || (regNumber <= 999 || regNumber >= 10000)) {
            cout << "Invalid input. Please enter a valid 4-digit number." << endl;
            cin.clear();
            while (cin.get() != '\n'); // Consume the entire line.
        }
        else {
            break; // Break the loop when regNumber is valid.
        }
    } while (true);
    for (int i = 0; i < numStudents; i++) {
        int reg = s[i].regnum();
        if ( reg== regNumber) {
            for (int j = i; j < numStudents - 1; j++) {
                s[j] = s[j + 1];
            }
            --numStudents;
            cout << "Record deleted successfully." << endl;
            return;
        }
    }
    cout << "Record not found for Registration Number: " << regNumber << endl;
}



//Start of main function
int main() {
    student s[MAXSTUDENTS];
    int n = 0;
    char ch;
    int choice;

    // Main menu loop
    do {
        cout << "Main Menu:" << endl;
        cout << "1. Create Database" << endl;
        cout << "2. Append Record" << endl;
        cout << "3. Search Record" << endl;
        cout << "4. Update Record" << endl;
        cout << "5. Delete Record" << endl;
        cout << "6. Display Record" << endl;
        cout << "7. savetofile" << endl;
        cout << "8. readtofile" << endl;
        cout << "9. Exit" << endl;
        cout << "Enter your choice: ";
            if (!(cin >> choice)) {
               cout << "Enter valid choice" << endl;
               cin.clear();
               while (cin.get()!='\n') {} // Consume the entire line.
               continue;
            }

        switch (choice) {
        case 1:
            if (n > 0) {
                cout << "You have already saved data in database" << endl;
                cout << "do you want to overwrite it?(y/n)";
                cin >> ch;
                if (ch == 'n' || ch == 'N') {
                    break;
                }
                else {
                    createDatabase(s, n);
                }
            }
            else {
                cout << "Enter number of students(MAX 70):" << endl;
                do {
                    if (!(cin >> n)) {
                        cout << "Enter valid number" << endl;
                        cin.clear();
                        while (cin.get() != '\n') {} // Consume the entire line.
                    }
                    else {
                        break;
                    }
                } while (true);
                createDatabase(s, n);
                break;
            }
        case 2:
            if (n == 0) {
                cout << "No Data Found. Please create a database first (Option 1)." << endl;
            }
            else {
                appendRecord(s, n);
            }
            break;
        case 3:
            if (n == 0) {
                cout << "No Data Found. Please create a database first (Option 1)." << endl;
            }
            else {
                search(s, n);
            }
            break;
        case 4:
            if (n == 0) {
                cout << "No Data Found. Please create a database first (Option 1)." << endl;
            }
            else {
                updateRecord(s, n);
            }
            break;
        case 5:
            if (n == 0) {
                cout << "No Data Found. Please create a database first (Option 1)." << endl;
            }
            else {
                deleteRecord(s, n);
            }
            break;
        case 6:
            if (n == 0) {
                cout << "No Data Found. Please create a database first (Option 1)." << endl;
            }
            else {
                Display(s, n);
            }
            break;
        case 7:
            // if (n == 0) {
            //     cout << "No Data Found. Please create a database first (Option 1)." << endl;
            // }
            // else {
                for(int i=0;i<n;i++){
                s[i].savetofile(s,i);
                }
            
            break;
         case 8:
            // if (n == 0) {
            //     cout << "No Data Found. Please create a database first (Option 1)." << endl;
            // }
            // else {
                // 
                s->readtofile();
                
            
            break;
        case 9:
            exit(1); // Exit the program
        default:
            cout << "Invalid Option" << endl;
       }
    } while (true);
    return 0;
}
