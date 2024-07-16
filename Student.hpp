#ifndef Student_hpp
#define Student_hpp
#include <iostream>
#include <stdio.h>

class Student {
public:
    // Constructor
    Student (std::string name, int* grades, int numGrades);
    
    ~Student();
    
    void display() const;

    int average();
    
private:
    std::string name;
    int* grades;
    int numGrades;
};



#endif /* Student_hpp */