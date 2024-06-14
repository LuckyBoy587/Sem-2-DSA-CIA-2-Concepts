#include <iostream>
#include <string>
#include <map>

using namespace std;

struct Student {
    string name;
    string gender;
};

int main() {
    int numStudents;
    cout << "Enter the number of students: ";
    cin >> numStudents;

    map<int, Student> studentMap;

    for (int i = 0; i < numStudents; i++) {
        int rollNumber;
        string name, gender;
        cin >> rollNumber >> name >> gender;
        Student student = {name, gender};
        studentMap[rollNumber] = student;
    }

    int searchRollNumber;
    cin >> searchRollNumber;

    if (studentMap.find(searchRollNumber)!= studentMap.end()) {
        Student foundStudent = studentMap[searchRollNumber];
        cout << "Student with roll number " << searchRollNumber << " found." << endl;
        cout << "Name: " << foundStudent.name << endl;
        cout << "Gender: " << foundStudent.gender << endl;
    } else {
        cout << "No student found with roll number " << searchRollNumber << "." << endl;
    }

    return 0;
}