#include "Student.hpp"
#include <iostream>
#include <stdio.h>


// Constructor
Student::Student (std::string name, int* grades, int numGrades) {
    this->name = name;
    this->grades = grades;
    this->numGrades = numGrades;
}

Student::~Student() {
    delete[] grades;
}

void Student::display() const {
    std::cout << "Name: " << name << std::endl;
    std::cout << "Grades: ";
    for (int i = 0; i < numGrades; i++) {
        std::cout << grades[i] << " ";
    }
    std::cout << std::endl;
}

