#ifndef LOGS_H
#define LOGS_H

#include <iostream>
using namespace std;

class Logs
{
    public:
        Logs(string);
        virtual ~Logs();
        static void view();
        bool ajouterLogs();

    protected:

    private:
        string username;
};

#endif // LOGS_H
