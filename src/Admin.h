#pragma once
#include <string>

class Admin {
public:
    Admin(const std::string& username);
    std::string getUsername() const;
private:
    std::string _username;
};
