#include "User.h"
#include <iostream>
#include <windows.h>
#include <string>
#include <sstream>
#include "cryptage.h"
#include "mysql.h"
using namespace std;
User::User(int id,string user,string pass):id(id),username(user),password(pass)
{
    //ctor
}

User::~User()
{
    //dtor
}


void User::view(){
    MYSQL* conn;
	conn=mysql_init(0);
	conn = mysql_real_connect(conn,"localhost","root","","projetcplus",0,NULL,0);
	if(!conn){
		exit(-1);
	}
    MYSQL_ROW row;
    MYSQL_RES* res;
    int qstate=0;

        qstate = mysql_query(conn, "SELECT * FROM user");

        if(!qstate){
            res = mysql_store_result(conn);
            cout << "ID" <<" | \t" << "Username" << endl << endl;
            while((row = mysql_fetch_row(res))){
                cout << row[0] <<" | \t" << decrypter(row[1],"this is just a test") << endl << endl;
             }
        }
}

bool User::ajouterUser(){
    MYSQL* conn;
	conn=mysql_init(0);
	conn = mysql_real_connect(conn,"localhost","root","","projetcplus",0,NULL,0);
	if(!conn){
		exit(-1);
	}
      int qstate = 0;
        string user, pass;
        user=crypter(User::username,"this is just a test");
        pass=crypter(User::password,"this is just a test");



        stringstream ss;
        ss << "INSERT INTO user(username,password) VALUES('" << user << "','" << pass <<"')";
        string query = ss.str();
        const char* q = query.c_str();
        qstate = mysql_query(conn, q);
        if(qstate == 0){
            cout << "Record Inserted..." << endl;
        }else{
            cout << "Insert Error" << mysql_error(conn) << endl;
        }
}

