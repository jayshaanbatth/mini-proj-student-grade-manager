#include <iostream>
#include <vector>

using namespace std;

void addGrade(vector<double>& grades, double grade);

void displayGrades(const vector<double>& grades);

double getAvg(const vector<double>& grades);

double getHighest(const vector<double>& grades);

int main() {

    int choice = -1;
    double grade = -1;
    vector<double> grades;


    do {
        // Title
        cout << "==== STUDENT GRADE MANAGER ====" << endl;
        
        // The instructions
        cout << "\n1. Add Grade\n2. Display Grades\n3. Calculate Avg.\n4. Find Highest Grade\n5. Exit\n" << endl;

        // Prompt to enter a choice
        cout << "Enter choice: ";
        cin >> choice;

        // Conditional based on choice (calls necessary functions)
        if (choice < 1 || choice > 5) {

            cout << "INVALID INPUT : TRY AGAIN\n" << endl;

        } else if (choice == 1) {

            cout << "Enter grade: ";
            cin >> grade;
            cout << "\n";

            while (grade < 0 || grade > 100) {

                cout << "INVALID INPUT : TRY AGAIN\n" << endl;

                cout << "Enter grade: ";
                cin >> grade;
                cout << "\n";

            }

            addGrade(grades, grade);

        } else if (choice == 2) {

            displayGrades(grades);

        } else if (choice == 3) {

            if (grades.empty()) {

                cout << "please enter grades, before continuing..." << endl;

            } else {

                cout << "Average: " << getAvg(grades) << endl;

            }
           
            cout << endl;

        } else if (choice == 4) {

            if (grades.empty()) {

                cout << "please enter grades, before continuing..." << endl;

            } else {

                cout << "Highest grade: " << getHighest(grades) << endl;

            }
            
            cout << endl;

        }

    } while (choice != 5);
}

    void addGrade(vector<double>& grades, double grade) {

        grades.push_back(grade);

        cout << "Added Successfully\n" << endl;

    }

    void displayGrades(const vector<double>& grades) {

        cout << "Grades: ";

        for(double grade : grades) {

            cout << grade << " ";

        }

        cout << "\n" << endl;

    }

    double getAvg(const vector<double>& grades) {

        double avg = 0;
    
        for(double grade : grades) {

           avg += grade;

        }

        avg = avg / grades.size();

        return avg;
    }

    double getHighest(const vector<double>& grades) {

        double highest = grades[0];

        for(double grade : grades) {

           if (grade > highest) {

            highest = grade;

           }

        }

        return highest;

    }
