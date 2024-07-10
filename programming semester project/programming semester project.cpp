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

