#ifndef USER_H
#define USER_H

#include <string>
using namespace std;

class User
{
private:
    int userId;
    string name;

public:
    User(int userId, string name);
    int getId() const;
    string getName() const;
};

#endif
