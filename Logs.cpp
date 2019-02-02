#include "Logs.h"
#include <iostream>
#include <windows.h>
#include <string>
#include <sstream>
#include "cryptage.h"
#include "mysql.h"
using namespace std;
Logs::Logs(string user):username(user)
{
    //ctor
}

Logs::~Logs()
{
    //dtor
}

void Logs::view(){
    MYSQL* conn;
	conn=mysql_init(0);
	conn = mysql_real_connect(conn,"localhost","root","","projetcplus",0,NULL,0);
	if(!conn){
		exit(-1);
	}
    MYSQL_ROW row;
    MYSQL_RES* res;
    int qstate=0;

        qstate = mysql_query(conn, "SELECT * FROM logs");

        if(!qstate){
            res = mysql_store_result(conn);
            cout << "ID" <<" | \t" << "Username" <<" | \t" << "Time" << endl << endl;
            while((row = mysql_fetch_row(res))){
                cout << row[0] <<" | \t" << decrypter(row[1],"this is just a test") <<" | \t" << row[2] << endl << endl;
             }
        }
}

bool Logs::ajouterLogs(){
    MYSQL* conn;
	conn=mysql_init(0);
	conn = mysql_real_connect(conn,"localhost","root","","projetcplus",0,NULL,0);
	if(!conn){
		exit(-1);
	}
      int qstate = 0;
        string user;
        user=crypter(Logs::username,"this is just a test");



        stringstream ss;
        ss << "INSERT INTO logs(username) VALUES('" << user <<"')";
        string query = ss.str();
        const char* q = query.c_str();
        qstate = mysql_query(conn, q);
        if(qstate == 0){
            cout << "Record Inserted..." << endl;
        }else{
            cout << "Insert Error" << mysql_error(conn) << endl;
        }
}


