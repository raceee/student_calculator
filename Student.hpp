#ifndef Student_hpp
#define Student_hpp
#include <iostream>
#include <stdio.h>

class Student {
public:
    
    Student (std::string name, int* grades, int numGrades);
    
    ~Student();
    
    void display() const;

    int average() const;
    
    
private:
    std::string name;
    int* grades;
    int numGrades;
};



#endif /* Student_hpp */