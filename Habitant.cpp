#include "Habitant.h"
#include "ZoneGeographique.h"
#include <iostream>
#include <windows.h>
#include <string>
#include <sstream>
#include "cryptage.h"
#include "mysql.h"

using namespace std;
Habitant::Habitant(){}
Habitant::Habitant(unsigned int id,string nom,string prenom,ZoneGeographique z):id(id),nom(nom),prenom(prenom),associes(z)
{
    //ctor
}

Habitant::~Habitant()
{
    //dtor
}

void Habitant::afficher() const {
    cout << id << nom << " " << prenom << " " << associes.Getnom() << endl;
}


void Habitant::view(){
    MYSQL* conn;
	conn=mysql_init(0);
	conn = mysql_real_connect(conn,"localhost","root","","projetcplus",0,NULL,0);
	if(!conn){
		exit(-1);
	}
    MYSQL_ROW row;
    MYSQL_RES* res;
    int qstate=0;

        qstate = mysql_query(conn, "SELECT * FROM habitant");

        if(!qstate){
            res = mysql_store_result(conn);
            cout << "ID" <<" | \t" << "Nom" <<"\t | \t" << "Prenom" <<"\t | \t" << "Zone" << endl << endl;

            while((row = mysql_fetch_row(res))){
                cout << row[0] <<" | \t" << decrypter(row[1],"this is just a test") <<"\t | \t" << decrypter(row[2],"this is just a test") <<"\t | \t" << decrypter(row[3],"this is just a test") << endl << endl;
             }
        }
}

bool Habitant::ajouterHabitant(){
    MYSQL* conn;
	conn=mysql_init(0);
	conn = mysql_real_connect(conn,"localhost","root","","projetcplus",0,NULL,0);
	if(!conn){
		exit(-1);
	}
      int qstate = 0;
        string nom,prenom;
        string zone;
        nom=crypter(Habitant::nom,"this is just a test");
        prenom=crypter(Habitant::prenom,"this is just a test");

        zone=crypter(Habitant::associes.Getnom(),"this is just a test");




        stringstream ss;
        ss << "INSERT INTO habitant(nom,prenom,zone) VALUES('" << nom << "','" << prenom << "','"<<zone << "')";
        string query = ss.str();
        const char* q = query.c_str();
        qstate = mysql_query(conn, q);
        if(qstate == 0){
            cout << "Record Inserted..." << endl;
        }else{
            cout << "Insert Error" << mysql_error(conn) << endl;
        }
}

