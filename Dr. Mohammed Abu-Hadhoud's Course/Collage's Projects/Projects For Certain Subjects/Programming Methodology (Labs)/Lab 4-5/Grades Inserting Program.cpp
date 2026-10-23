#include <iostream>
using namespace std;

int main() {
    
    int SelectedCourseNumber;
    const float ProgrammingWorkWorth = 0.4, ProgrammingExamWorth = 0.6;
    const float MathematicsWorkWorth = 0.3, MathematicsExamWorth = 0.7;
    const float EnglishWorkWorth = 0.5, EnglishExamWorth = 0.5;
    float CourseworkMark, ExamMark;
    float TotalMark;

    /*
    I've changed the order of user input insertion
    to organize the code. Instead of listing the 
    courses first then entering marks, i did the
    opposite. I will left the code that is ordered
    like in the homework after the main() function.
    */

    cout << "Enter the coursework mark: ";
    cin >> CourseworkMark;

    cout << "Enter the exam mark: ";
    cin >> ExamMark;

    cout << endl;
    cout << "Select the course:\n\n";

    cout << "1- Programming.\n";
    cout << "2- Mathematics.\n";
    cout << "3- English.\n";

    cout << "\nChoice: ";
    cin >> SelectedCourseNumber;

    bool ValidCourseNumber = true;

    switch (SelectedCourseNumber)
    {
    case 1: // Programming is chosen.
        TotalMark = (CourseworkMark * ProgrammingWorkWorth) + (ExamMark * ProgrammingExamWorth);
        break;
    case 2: // Mathematics is chosen.
        TotalMark = (CourseworkMark * MathematicsWorkWorth) + (ExamMark * MathematicsExamWorth);
        break;
    case 3: // English is chosen.
        TotalMark = (CourseworkMark * EnglishWorkWorth) + (ExamMark * EnglishExamWorth);
        break;
    default: // Wrong course number.
        cout << "Invalid course type.\n";
        ValidCourseNumber = false;
    }

    if (ValidCourseNumber)
        cout << "Your final grade is " << TotalMark << endl;

    return 0;
}

/*
* if you insist, Doctor, this is the code
exactly as ordered in the homework. It will 
start from listing the courses to be brief:

    ...
    cout << "Select the course:\n\n";

    cout << "1- Programming.\n";
    cout << "2- Mathematics.\n";
    cout << "3- English.\n";

    cout << "\nChoice: ";
    cin >> SelectedCourseNumber;

    bool ValidCourseNumber = true;

    switch (SelectedCourseNumber)
    {
    case 1: // Programming is chosen.
        cout << "Enter the coursework mark: ";
        cin >> CourseworkMark;

        cout << "Enter the exam mark: ";
        cin >> ExamMark;

        TotalMark = (CourseworkMark * ProgrammingWorkWorth) + (ExamMark * ProgrammingExamWorth);
        break;
    case 2: // Mathematics is chosen.
        cout << "Enter the coursework mark: ";
        cin >> CourseworkMark;

        cout << "Enter the exam mark: ";
        cin >> ExamMark;

        TotalMark = (CourseworkMark * MathematicsWorkWorth) + (ExamMark * MathematicsExamWorth);
        break;
    case 3: // English is chosen.
        cout << "Enter the coursework mark: ";
        cin >> CourseworkMark;

        cout << "Enter the exam mark: ";
        cin >> ExamMark;

        TotalMark = (CourseworkMark * EnglishWorkWorth) + (ExamMark * EnglishExamWorth);
        break;
    default: // Wrong course number.
        cout << "Invalid course type.\n";
        ValidCourseNumber = false;
    }

    if (ValidCourseNumber)
        cout << "Your final grade is " << TotalMark << endl;

    return 0;
*/