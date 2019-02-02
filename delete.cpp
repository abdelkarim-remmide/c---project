#include "delete.h"
#include <iostream>
#include <windows.h>
#include <string>
#include <sstream>
#include "cryptage.h"
#include "mysql.h"
#include "Logs.h"
void afficherLogo(){
    cout <<endl;
    cout << "     ###########                                                ########       #########           ########"<<endl;
    cout << "    ############                                                ##     ##      ##      ##        ##        ##"<<endl;
    cout << "   ##                                                           ##      ##     ##       ##      ##          ##" << endl;
    cout << "  ##                      #####                #####            ##      ##     ##       ##     ##            ##" <<endl;
    cout << "  ##                      #####                #####            ##     ##      ##      ##     ##              ##"<<endl;
    cout << "  ##                      #####                #####            ########       #########      ##              ##"<<endl;
    cout << "  ##               ##################   ##################      ##             ####           ##              ##"<<endl;
    cout << "  ##               ##################   ##################      ##             ## ##          ##              ##"<<endl;
    cout << "  ##                      #####                #####            ##             ##  ##         ##              ##"<<endl;
    cout << "  ##                      #####                #####            ##             ##   ##         ##            ##"<<endl;
    cout << "  ##                      #####                #####            ##             ##    ##         ##          ##"<<endl;
    cout << "   ##                                                           ##             ##     ##         ##        ##" << endl;
    cout << "    ############                                                ##             ##      ##         ##      ##"<<endl;
    cout << "     ###########                                                ##             ##       ##          #######"<<endl;
    cout << endl;
    cout << endl;

}
void deletef(string bdname,int id){
    MYSQL* conn;
	conn=mysql_init(0);
	conn = mysql_real_connect(conn,"localhost","root","","projetcplus",0,NULL,0);
	if(!conn){
		exit(-1);
	}
      int qstate = 0;




        stringstream ss;
        ss << "DELETE FROM "<<bdname<< " WHERE id="<<id;
        string query = ss.str();
        const char* q = query.c_str();
        qstate = mysql_query(conn, q);
        if(qstate == 0){
            cout << "Record deleted..." << endl;
        }else{
            cout << "Delete Error" << mysql_error(conn) << endl;
        }
}

bool login(string username,string password){
    MYSQL* conn;
	conn=mysql_init(0);
	conn = mysql_real_connect(conn,"localhost","root","","projetcplus",0,NULL,0);
	if(!conn){
		exit(-1);
	}
    MYSQL_ROW row;
    MYSQL_RES* res;
    int qstate=0;

    stringstream ss;
        ss << "SELECT * FROM user WHERE username='"<<crypter(username,"this is just a test")<< "' AND password='"<<crypter(password,"this is just a test")<<"'";
        string query = ss.str();
        const char* q = query.c_str();

        qstate = mysql_query(conn, q);

        if(!qstate){
            res = mysql_store_result(conn);

            if((row = mysql_fetch_row(res))){
                Logs l(username);
                cout<<l.ajouterLogs();
                return true;
            }

        }
    return false;
}
