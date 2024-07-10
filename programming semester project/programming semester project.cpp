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

    
