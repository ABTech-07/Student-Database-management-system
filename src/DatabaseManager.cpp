#include "DatabaseManager.h"
#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/uri.hpp>
//#include <mongocxx/stdx.hpp>
#include <bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/json.hpp>
#include <iostream>

static mongocxx::instance instance{};

DatabaseManager::DatabaseManager(const std::string& uri, const std::string& dbName)
    : _uri(uri), _dbName(dbName) {}

bool DatabaseManager::insertStudent(const std::string& name, int rollNo, const std::string& email) {
    try {
        mongocxx::client client{mongocxx::uri{_uri}};
        auto db = client[_dbName];
        auto collection = db["students"];
        bsoncxx::builder::stream::document document{};
        document << "name" << name << "roll_no" << rollNo << "email" << email;
        collection.insert_one(document.view());
        return true;
    } catch (const std::exception& e) {
        std::cerr << "Insert failed: " << e.what() << std::endl;
        return false;
    }
}

std::vector<bsoncxx::document::value> DatabaseManager::getAllStudents() {
    std::vector<bsoncxx::document::value> students;
    try {
        mongocxx::client client{mongocxx::uri{_uri}};
        auto db = client[_dbName];
        auto collection = db["students"];
        auto cursor = collection.find({});
        for (auto&& doc : cursor) {
            students.push_back(bsoncxx::document::value(doc));
        }
    } catch (const std::exception& e) {
        std::cerr << "Fetch failed: " << e.what() << std::endl;
    }
    return students;
}
