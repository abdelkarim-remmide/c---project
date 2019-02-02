#include "Recommandes.h"
#include "Facteur.h"
#include "Habitant.h"
#include <iostream>
#include <windows.h>
#include <string>
#include <sstream>
#include "cryptage.h"
#include "mysql.h"
using namespace std;
Recommandes::Recommandes(unsigned int id,string date,Facteur f,Habitant h,int n):id(id),date(date),distribuepar(f),pour(h),type(n)
{
    //ctor
}

Recommandes::~Recommandes()
{
    //dtor
}


void Recommandes::afficher() const {
    distribuepar.afficher();
    pour.afficher();
    cout << date << endl;
}


void Recommandes::view(){
    MYSQL* conn;
	conn=mysql_init(0);
	conn = mysql_real_connect(conn,"localhost","root","","projetcplus",0,NULL,0);
	if(!conn){
		exit(-1);
	}
    MYSQL_ROW row;
    MYSQL_RES* res;
    int qstate=0;

        qstate = mysql_query(conn, "SELECT * FROM recommendes");

        if(!qstate){
            res = mysql_store_result(conn);
            cout << "ID" <<" | \t" << "Date" <<"\t | \t" << "Facteur" <<"\t | \t" << "Habitant" <<"\t | \t" << "Type" << endl << endl;

            while((row = mysql_fetch_row(res))){
                cout << row[0] <<" | \t" << decrypter(row[1],"this is just a test") <<"\t | \t" << decrypter(row[2],"this is just a test") <<"\t | \t" << decrypter(row[3],"this is just a test") << "\t | \t" << decrypter(row[4],"this is just a test") << endl;
             }
        }
}

bool Recommandes::ajouterRecommendes(){
    MYSQL* conn;
	conn=mysql_init(0);
	conn = mysql_real_connect(conn,"localhost","root","","projetcplus",0,NULL,0);
	if(!conn){
		exit(-1);
	}
      int qstate = 0;
        string date,f,h;
        date=crypter(Recommandes::date,"this is just a test");
        f=crypter(Recommandes::distribuepar.Getnom()+" "+Recommandes::distribuepar.Getprenom(),"this is just a test");
        h=crypter(Recommandes::pour.Getnom()+" "+Recommandes::pour.Getprenom(),"this is just a test");
        string type;
        if(Recommandes::type==1)
            type="lettre";
        else type="colis";
        type=crypter(type,"this is just a test");



        stringstream ss;
        ss << "INSERT INTO recommendes(date,facteur,habitant,type) VALUES('" << date << "','" << f << "','"<< h << "','"<< type << "')";
        string query = ss.str();
        const char* q = query.c_str();
        qstate = mysql_query(conn, q);
        if(qstate == 0){
            cout << "Record Inserted..." << endl;
        }else{
            cout << "Insert Error" << mysql_error(conn) << endl;
        }
}
