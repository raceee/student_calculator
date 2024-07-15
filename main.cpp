#include "Student.hpp"
#include <iostream>

int main(){
    int numGrades = 3;
    int* grades = new int[numGrades];
    grades[0] = 100;
    grades[1] = 90;
    grades[2] = 80;

    Student student("John Doe", grades, numGrades);

    student.display();
    return 0;
    
}