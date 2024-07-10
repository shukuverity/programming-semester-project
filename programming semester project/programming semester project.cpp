//Programme that assists new students in selecting co-curricular activities
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;
struct Student
{
    string firstname;
    string surname;
    string gender;
    int age;
    int group;
    vector<string> activities;
};
struct Activity {
    string name;
    int max_capacity;
    vector<Student> members;
};

 do {
     cout << "Choose activity type:\n 1. Sport\n 2.Club/Society\n 3. Done: ";
     cin >> choice;

     if (choice == 1) {
         cout << "Choose sport: ";
         for (size_t i = 0; i < sports.size(); ++i) {
             cout << i + 1 << ". " << sports[i].name << " (" << sports[i].members.size() << "/" << sports[i].max_capacity << ")\n";
         }
         int sport_choice;
         cin >> sport_choice;
         if (sport_choice >= 1 && sport_choice <= sports.size()) {
             if (sports[sport_choice - 1].members.size() < sports[sport_choice - 1].max_capacity) {
                 student.activities.push_back(sports[sport_choice - 1].name);
                 sports[sport_choice - 1].members.push_back(student);
             }
             else {
                 cout << "Sport is at full capacity.\n";
             }
         }
     }
        else if (choice == 2) 
        { 
            cout << "Choose club/society: ";
            for (size_t i = 0; i < clubs.size(); ++i) {
                cout << i + 1 << ". " << clubs[i].name << " (" << clubs[i].members.size() << "/" << clubs[i].max_capacity << ")\n";
            }
            int club_choice;
            cin >> club_choice;
            if (club_choice >= 1 && club_choice <= clubs.size()) {
                if (clubs[club_choice - 1].members.size() < clubs[club_choice - 1].max_capacity) {
                    student.activities.push_back(clubs[club_choice - 1].name);
                    clubs[club_choice - 1].members.push_back(student);
                }
                else {
                    cout << "Club/Society is at full capacity.\n";
                }
            }
        }
    } while (choice != 3);

    students.push_back(student);
}

void viewStudents() {
    for (const auto& student : students) {
        cout << "Name: " << student.firstname << " " << student.surname << ", Gender: " << student.gender << ", Age: " << student.age << ", Group: " << student.group << "\n";
        cout << "Activities: ";
        for (const auto& activity : student.activities) {
            cout << activity << " ";
        }
        cout << "\n";
    }
}
void viewActivities(const vector<Activity>& activities) {
    for (const auto& activity : activities) {
        cout << "Activity: " << activity.name << ", Capacity: " << activity.members.size() << "/" << activity.max_capacity << "\n";
    }
}

void saveToFile() {
    ofstream file("students.csv");
    file << "Firstname,Surname,Gender,Age,Group,Activities\n";
    for (const auto& student : students) {
        file << student.firstname << "," << student.surname << "," << student.gender << "," << student.age << "," << student.group << ",";
        for (const auto& activity : student.activities) {
            file << activity << " ";
        }
        file << "\n";
    }
    file.close();
    cout << "Data saved to students.csv\n";
}
int main() {
    int choice;
    do {
        cout << "Menu:\n";
        cout << "1. Add Student\n";
        cout << "2. View Students\n";
        cout << "3. View Clubs/Societies\n";
        cout << "4. View Sports\n";
        cout << "5. Save all Files\n";
        cout << "6. Exit\n";
        cin >> choice;

              switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                viewStudents();
                break;
            case 3:
                viewActivities(clubs);
                break;
            case 4:
                viewActivities(sports);
                break;
            case 5:
                saveToFile();
                break;
            case 6:
                cout << "Exiting....\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 6);

    return 0;
}
