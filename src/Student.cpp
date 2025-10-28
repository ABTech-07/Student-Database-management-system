#include "Student.h"

Student::Student(const std::string& name, int rollNo, const std::string& email)
    : _name(name), _rollNo(rollNo), _email(email) {}

std::string Student::getName() const { return _name; }
int Student::getRollNo() const { return _rollNo; }
std::string Student::getEmail() const { return _email; }
