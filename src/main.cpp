// Entry point for Student DBMS

#include "DatabaseManager.h"
#include "Student.h"
#include "Admin.h"
#include <iostream>
#include <bsoncxx/json.hpp>

int main() {
    std::cout << "Welcome to Student Database Management System" << std::endl;
    std::string uri = "mongodb+srv://abandekar_db_user:ZDHCVUbf8GqOLPcI@cluster1.5njcftq.mongodb.net/";
    std::string dbName = "student_db";
    DatabaseManager dbManager(uri, dbName);
    int choice;
    while (true) {
        std::cout << "\n1. Add Student\n2. View All Students\n3. Exit\nEnter choice: ";
        std::cin >> choice;
        if (choice == 1) {
            std::string name, email;
            int rollNo;
            std::cout << "Enter name: "; std::cin >> name;
            std::cout << "Enter roll number: "; std::cin >> rollNo;
            std::cout << "Enter email: "; std::cin >> email;
            if (dbManager.insertStudent(name, rollNo, email))
                std::cout << "Student added successfully!" << std::endl;
            else
                std::cout << "Failed to add student." << std::endl;
        } else if (choice == 2) {
            auto students = dbManager.getAllStudents();
            for (const auto& doc : students) {
                std::cout << bsoncxx::to_json(doc) << std::endl;
            }
        } else if (choice == 3) {
            break;
        } else {
            std::cout << "Invalid choice. Try again." << std::endl;
        }
    }
    return 0;
}
