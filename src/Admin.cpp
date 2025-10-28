#include "Admin.h"

Admin::Admin(const std::string& username) : _username(username) {}
std::string Admin::getUsername() const { return _username; }
