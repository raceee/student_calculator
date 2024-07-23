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
    std::string id = id_generator();
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(50, 100);
    
    for (int i = 0; i < 20000; i++){
        file << id << "," << dis(gen) << "," << dis(gen) << "," << dis(gen) << "\n";
    }

    file.close();

}

std::vector<std::string> split( const std::string& s, const std::string& f ){
    std::vector<std::string> result;
    std::string temp = s;
    size_t pos = 0;
    std::string token;
    while ((pos = temp.find(f)) != std::string::npos) {
        token = temp.substr(0, pos);
        result.push_back(token);
        temp.erase(0, pos + f.length());
    }
    result.push_back(temp);
    return result;
}

void readCSV(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open the file " << filename << std::endl;
        return;
    }

    std::string line;

    // Read the header line
    if (std::getline(file, line)) {
        std::vector<std::string> header = split(line, ",");
        std::cout << "Header: ";
        for (const auto& field : header) {
            std::cout << field << " ";
        }
        std::cout << std::endl;
    }

    // Read the data lines
    while (std::getline(file, line)) {
        std::vector<std::string> fields = split(line, ",");
        int sum = 0;
        for (int i = 0; i < fields.size(); i++){
            if (i >= 1){
                sum += std::stoi(fields[i]);
            }
            if (i == 3){
                std::cout << "average: " << sum / 3 << std::endl;
            }
        }
        std::cout << std::endl;
    }

    file.close();
}


int main(){
    std::string filename = "data.csv";
    readCSV(filename);
    // create_csv();
    // int numGrades = 3;
    // int* grades = new int[numGrades];
    // grades[0] = 100;
    // grades[1] = 90;
    // grades[2] = 80;

    // Student student("John Doe", grades, numGrades);

    // student.display();
    // std::cout << "Average: " << student.average() << std::endl;
    // return 0;
    
}