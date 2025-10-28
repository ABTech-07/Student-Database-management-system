#pragma once
#include <string>

class Student {
public:
    Student(const std::string& name, int rollNo, const std::string& email);
    std::string getName() const;
    int getRollNo() const;
    std::string getEmail() const;
private:
    std::string _name;
    int _rollNo;
    std::string _email;
};
