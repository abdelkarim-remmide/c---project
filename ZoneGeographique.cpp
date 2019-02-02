#include "ZoneGeographique.h"
#include "Facteur.h"
#include <iostream>
#include <windows.h>
#include <string>
#include <sstream>
#include "cryptage.h"
#include "mysql.h"

using namespace std;
ZoneGeographique::ZoneGeographique(){}
ZoneGeographique::ZoneGeographique(unsigned int id,string nom,Facteur f):id(id),nom(nom),facteur(f)
{
    //ctor
}

ZoneGeographique::~ZoneGeographique()
{
    //dtor
}

void ZoneGeographique::afficher() const{
    cout << id << " " << nom << " " << facteur.Getid() << endl;
}


void ZoneGeographique::view(){
    MYSQL* conn;
	conn=mysql_init(0);
	conn = mysql_real_connect(conn,"localhost","root","","projetcplus",0,NULL,0);
	if(!conn){
		exit(-1);
	}
    MYSQL_ROW row;
    MYSQL_RES* res;
    int qstate=0;

        qstate = mysql_query(conn, "SELECT * FROM zonegeographique");

        if(!qstate){
            res = mysql_store_result(conn);
            cout << "ID" <<" | \t" << "Nom" <<"\t | \t" << "Facteur"<< endl << endl;

            while((row = mysql_fetch_row(res))){
                cout << row[0] <<" | \t" << decrypter(row[1],"this is just a test") <<"\t | \t" << decrypter(row[2],"this is just a test") << endl << endl;
             }
        }
}

bool ZoneGeographique::ajouterZone(){
    MYSQL* conn;
	conn=mysql_init(0);
	conn = mysql_real_connect(conn,"localhost","root","","projetcplus",0,NULL,0);
	if(!conn){
		exit(-1);
	}
      int qstate = 0;
        string nom;
        string f;
        nom=crypter(ZoneGeographique::nom,"this is just a test");
        f=crypter(ZoneGeographique::facteur.Getnom()+" "+ZoneGeographique::facteur.Getprenom(),"this is just a test");




        stringstream ss;
        ss << "INSERT INTO zonegeographique(nom,facteur) VALUES('" << nom << "','" << f << "')";
        string query = ss.str();
        const char* q = query.c_str();
        qstate = mysql_query(conn, q);
        if(qstate == 0){
            cout << "Record Inserted..." << endl;
        }else{
            cout << "Insert Error" << mysql_error(conn) << endl;
        }
}
