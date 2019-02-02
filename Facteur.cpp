#include "Facteur.h"
#include <iostream>
#include <windows.h>
#include <string>
#include <sstream>
#include "cryptage.h"
#include "mysql.h"
using namespace std;
Facteur::Facteur(){}
Facteur::Facteur(int id,string nom,string prenom,string dateNaiss,string dateCree):id(id),nom(nom),prenom(prenom),dateNaiss(dateNaiss),dateCree(dateCree)
{
    //ctor
}

Facteur::~Facteur()
{
    //dtor
}

void Facteur::afficher() const{
    cout << nom << " " << prenom << " " << dateNaiss << " " << dateCree << endl;
}

void Facteur::view(){
    MYSQL* conn;
	conn=mysql_init(0);
	conn = mysql_real_connect(conn,"localhost","root","","projetcplus",0,NULL,0);
	if(!conn){
		exit(-1);
	}
    MYSQL_ROW row;
    MYSQL_RES* res;
    int qstate=0;

        qstate = mysql_query(conn, "SELECT * FROM facteur");

        if(!qstate){
            res = mysql_store_result(conn);
            cout << "ID" <<" | \t" << "Nom" <<"\t | \t" << "Prenom" <<"\t | \t" << "Date de naissance" <<"\t | \t" << "Date de debut de travail" << endl << endl;
            while((row = mysql_fetch_row(res))){
                cout << row[0] <<" | \t" << decrypter(row[1],"this is just a test") <<"\t | \t" << decrypter(row[2],"this is just a test") <<"\t | \t" << decrypter(row[3],"this is just a test") <<"\t | \t" << decrypter(row[4],"this is just a test") << endl << endl;
             }
        }
}

bool Facteur::ajouterFacteur(){
    MYSQL* conn;
	conn=mysql_init(0);
	conn = mysql_real_connect(conn,"localhost","root","","projetcplus",0,NULL,0);
	if(!conn){
		exit(-1);
	}
      int qstate = 0;
        string nom, prenom,dateNaiss,dateCree;
        nom=crypter(Facteur::nom,"this is just a test");
        prenom=crypter(Facteur::prenom,"this is just a test");
        dateNaiss=crypter(Facteur::dateNaiss,"this is just a test");
        dateCree=crypter(Facteur::dateCree,"this is just a test");



        stringstream ss;
        ss << "INSERT INTO facteur(nom,prenom,dateNaiss,dateCree) VALUES('" << nom << "','" << prenom << "','" << dateNaiss << "','" << dateCree <<"')";
        string query = ss.str();
        const char* q = query.c_str();
        qstate = mysql_query(conn, q);
        if(qstate == 0){
            cout << "Record Inserted..." << endl;
        }else{
            cout << "Insert Error" << mysql_error(conn) << endl;
        }
}
