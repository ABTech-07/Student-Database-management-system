#pragma once
#include <string>
#include <vector>
#include <bsoncxx/document/view.hpp>
#include <bsoncxx/document/value.hpp>

class DatabaseManager {
public:
    DatabaseManager(const std::string& uri, const std::string& dbName);
    bool insertStudent(const std::string& name, int rollNo, const std::string& email);
    std::vector<bsoncxx::document::value> getAllStudents();
    // Add more CRUD methods as needed
private:
    std::string _uri;
    std::string _dbName;
};
