#include "User.h"

User::User(int userId, string name)
{
    this->userId = userId;
    this->name = name;
}

int User::getId() const
{
    return userId;
}

string User::getName() const
{
    return name;
}
