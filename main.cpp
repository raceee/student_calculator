#include "Student.hpp"
#include <iostream>
#include <fstream>
#include <random>



std::string id_generator(){
    std::string id = "";
    for (int i = 0; i < 9; i++){
        id += std::to_string(rand() % 10);
    }
    return id;
}

void create_csv(){
    std::ofstream file("data.csv");
    file << "Name,Grade1,Grade2,Grade3\n";
    for (int i = 0; i < 20000; i++){
        std::string id = id_generator();
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(50, 100);
        file << id << "," << dis(gen) << "," << dis(gen) << "," << dis(gen) << "\n";
    }

    file.close();

}

int main(){
    int numGrades = 3;
    int* grades = new int[numGrades];
    grades[0] = 100;
    grades[1] = 90;
    grades[2] = 80;

    Student student("John Doe", grades, numGrades);

    student.display();
    std::cout << "Average: " << student.average() << std::endl;
    return 0;
    
}