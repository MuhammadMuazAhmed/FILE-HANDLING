#include <iostream>   // Standard input/output stream library (for input and output operations)
#include <string>     // Standard string library (for string data type)
     // Included the cctype library for character handling
#include <iomanip>    // Included the iomanip library for formatting output
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
};


