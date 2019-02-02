#ifndef USER_H
#define USER_H
#include <iostream>
using namespace std;

class User
{
    public:
        User(int,string,string);
        virtual ~User();

        unsigned int Getid() { return id; }
        void Setid(unsigned int val) { id = val; }
        string Getusername() { return username; }
        void Setusername(string val) { username = val; }
        string Getpassword() { return password; }
        void Setpassword(string val) { password = val; }
        bool ajouterUser();
        static void view();

    protected:

    private:
        unsigned int id;
        string username;
        string password;
};

#endif // USER_H
