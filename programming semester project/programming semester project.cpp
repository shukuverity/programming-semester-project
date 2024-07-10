//Programme that assists new students in selecting co-curricular activities
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;
struct Student {
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

vector<Student> students;
vector<Activity> sports = { {"Rugby", 20}, {"Athletics", 20}, {"Swimming", 20}, {"Soccer", 20} };
vector<Activity> clubs = { {"Journalism Club", 60}, {"Red Cross Society", 60}, {"AISEC", 60}, {"Business Club", 60}, {"Computer Science Club", 60} };

void addStudent() {
    Student student;
    cout << "Enter first name: ";
    cin >> student.firstname;
    cout << "Enter surname: ";
    cin >> student.surname;
    cout << "Enter gender (MUST BE Male/Female): ";
    cin >> student.gender;
    cout << "Enter age: ";
    cin >> student.age;
    cout << "Enter group (1,2,3): ";
    cin >> student.group;

    int choice;
    do {
        cout << "Choose activity type: 1. Sport 2. Club/Society 3. Done: ";
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
        else if (choice == 2) {
            cout << "Choose club/society: ";
            for (size_t i = 0; i < clubs.size(); ++i) {
                cout << i + 1 << ". " << clubs[i].name << " (" << clubs[i].members.size() << "/" << clubs[i].max_capacity << ")\n";
            }
    


