#include <iostream>
#include "Facteur.h"
#include "ZoneGeographique.h"
#include "Habitant.h"
#include "Recommandes.h"
#include "Lettre.h"
#include "Colis.h"
#include <windows.h>
#include <string>
#include <sstream>
#include "delete.h"
#include "User.h"
#include "Logs.h"
#include "mysql.h"
using namespace std;

int main()
{
    cout << endl;
    string user,pass;
    do{
        system("cls");
        system("color 0D");
        afficherLogo();
        cout << "\t\t\t\t\tVous deuver s'authetifier " << endl;
        cout << "\t\tUsername : \n";
        cout << "\t\t       ";
        cin >> user;
        cout << "\t\tPassword : \n";
        cout << "\t\t       ";
        cin >> pass;
    }while(login(user,pass)==false);
    int choix,choix1;
    int id;
    do{
        system("cls");
        afficherLogo();
        cout << "Veulez-vous entre votre commande parmi ci suivants:"<<endl;
        cout << "1)-Gestion des facteurs" <<endl;
        cout << "2)-Gestion des habitants" <<endl;
        cout << "3)-Gestion des zones geographiques" <<endl;
        cout << "4)-Gestion des recommandes" <<endl;
        cout << "5)-Gestion des utilisateurs" <<endl;
        cout << "6)-Views Logs achive" <<endl;
        cout << "7)-Quiter l'application"<< endl;
        cin >> choix;
        switch(choix){
        case 1:
            do{
                system("cls");
                afficherLogo();
                cout << "                         Gestions des Facteurs                                                               " << endl;
                cout << "Veulez-vous entre votre commande parmi ci suivants:"<<endl;
                cout << "1)-Ajouter un facteur" <<endl;
                cout << "2)-Afficher les facteurs" <<endl;
                cout << "3)-Supprimer un facteur" <<endl;
                cout << "4)-Retour" <<endl;
                cin >> choix1;
                if(choix1==1){
                    string nom,prenom,datecree,datenaiss;
                    cout << "Donner le nom : "<<endl;
                    cout << "\t";
                    cin >> nom;
                    cout << "Donner le prenom : "<<endl;
                    cout << "\t";
                    cin >> prenom;
                    cout << "Donner la date de naissance sous forme dd/mm/yyyy : "<<endl;
                    cout << "\t";
                    cin >> datenaiss;
                    cout << "Donner la date de debut du travail sous forme dd/mm/yyyy : "<<endl;
                    cout << "\t";
                    cin >> datecree;
                    Facteur f(1,nom,prenom,datenaiss,datecree);
                    f.ajouterFacteur();
                }else{
                    if(choix1==2){
                        Facteur::view();
                        system("pause");
                    }else{
                        if(choix1==3){
                            cout << "donner l'id : " << endl;
                            cout << "\t";
                            cin >> id;
                            deletef("facteur",id);
                        }else{
                            if(choix1!=4)
                                cout << "La commande n'est pas valid" << endl;                        }
                    }
                }
            }while(choix1!=4);
            system("cls");
            break;
        case 2:
            do{
                system("cls");
                afficherLogo();
                cout << "                         Gestions des Habitant                                                               " << endl;
                cout << "Veulez-vous entre votre commande parmi ci suivants:"<<endl;
                cout << "1)-Ajouter un habitant" <<endl;
                cout << "2)-Afficher les habitants" <<endl;
                cout << "3)-Supprimer un Habitant" <<endl;
                cout << "4)-Retour" <<endl;
                cin >> choix1;
                if(choix1==1){
                    string nom,prenom,zone;
                    cout << "Donner le nom : "<<endl;
                    cout << "\t";
                    cin >> nom;
                    cout << "Donner le prenom : "<<endl;
                    cout << "\t";
                    cin >> prenom;
                    cout << "Donner la zone : "<<endl;
                    cout << "\t";
                    cin >> zone;
                    Habitant f(1,nom,prenom,ZoneGeographique(1,zone,Facteur()));
                    f.ajouterHabitant();
                }else {
                        if(choix1==2){
                            Habitant::view();
                            system("pause");
                        }else {
                            if(choix1==3){

                                cout << "Donner l'id : " << endl;
                                cout << "\t";
                                cin >> id;
                                deletef("habitant",id);

                            }else{
                                if(choix1!=4)
                                    cout << "La commande n'est pas valid" << endl;
                            }
                        }
                }
            }while(choix1!=4);
            system("cls");
            break;
        case 3:
            do{
                system("cls");
                afficherLogo();
                cout << "                         Gestions des zone Geographiques                                                     " << endl;
                cout << "Veulez-vous entre votre commande parmi ci suivants:"<<endl;
                cout << "1)-Ajouter une zone geographique" <<endl;
                cout << "2)-Afficher les zones geographiques" <<endl;
                cout << "3)-Supprimer une zone geographique" <<endl;
                cout << "4)-Retour" <<endl;
                cin >> choix1;
                if(choix1==1){
                    string nom,fnom,fprenom;
                    cout << "Donner le nom de la zone : "<<endl;
                    cout << "\t";
                    cin >> nom;
                    cout << "Donner le nom de facteur : "<<endl;
                    cout << "\t";
                    cin >> fnom;
                    cout << "Donner le prenom de facteur : "<<endl;
                    cout << "\t";
                    cin >> fprenom;
                    ZoneGeographique f(1,nom,Facteur(1,fnom,fprenom,"12","23"));
                    f.ajouterZone();
                }else {
                        if(choix1==2){
                            ZoneGeographique::view();
                            system("pause");
                        }else {
                            if(choix1==3){
                                cout << "Donner l'id : " << endl;
                                cout << "\t";
                                cin >> id;
                                deletef("zonegeographique",id);
                            }else{
                                if(choix1!=4)
                                    cout << "La commande n'est pas valid" << endl;
                            }
                        }
                }
            }while(choix1!=4);
            system("cls");
            break;
        case 4:
            do{
                system("cls");
                afficherLogo();
                cout << "                         Gestion des rocommande                                                              " << endl;
                cout << "Veulez-vous entre votre commande parmi ci suivants:"<<endl;
                cout << "1)-Ajouter un recommande" <<endl;
                cout << "2)-Afficher les recommandes" <<endl;
                cout << "3)-Supprimer un recommande" <<endl;
                cout << "4)-Retour" <<endl;
                cin >> choix1;
                if(choix1==1){
                    string nom ,prenom,hnom,hprenom,date;
                    int type;
                    do{
                        cout << "Donner le type sous form un enties (1=colis , 2=lettre) : "<<endl;
                        cout << "\t";
                        cin >> type;
                    }while(type!=1 && type!=2);
                    cout << "Donner le nom de facteur : "<<endl;
                    cout << "\t";
                    cin >> nom;
                    cout << "Donner le prenom de facteur : "<<endl;
                    cout << "\t";
                    cin >> prenom;
                    cout << "Donner le nom de l'habitant : "<<endl;
                    cout << "\t";
                    cin >> hnom;
                    cout << "Donner le prenom de l'habitant : "<<endl;
                    cout << "\t";
                    cin >> hprenom;
                    cout << "Donner le date : ";
                    cout << "\t";
                    cin >> date;
                    Recommandes f(1,date,Facteur(1,nom,prenom,"12","23"),Habitant(1,hnom,hprenom,ZoneGeographique()),type);
                    f.ajouterRecommendes();
                }else {
                        if(choix1==2){
                            Recommandes::view();
                            system("pause");
                        }else {
                            if(choix1==3){
                                cout << "Donner l'id : " << endl;
                                cout << "\t";
                                cin >> id;
                                deletef("recommandes",id);

                            }else{
                                if(choix1!=4)
                                    cout << "La commande n'est pas valid" << endl;
                            }
                        }
                }
            }while(choix1!=4);
            system("cls");
            break;
        case 5:
            do{
                system("cls");
                afficherLogo();
                cout << "                         Gestion des Utilisatuers                                                            " << endl;
                cout << "Veulez-vous entre votre commande parmi ci suivants:"<<endl;
                cout << "1)-Ajouter un utilisateur" <<endl;
                cout << "2)-Afficher les utilisateurs" <<endl;
                cout << "3)-Supprimer un utilisateur" <<endl;
                cout << "4)-Retour" <<endl;
                cin >> choix1;
                if(choix1==1){
                    string nom,password;
                    cout << "Donner le nom d'utilisateur : "<<endl;
                    cout << "\t";
                    cin >> nom;
                    cout << "Donner le mot de passe : "<<endl;
                    cout << "\t";
                    cin >> password;
                    User f(1,nom,password);
                    f.ajouterUser();
                }else {
                        if(choix1==2){
                            User::view();
                            system("pause");
                        }else {
                            if(choix1==3){
                                cout << "Donner l'id : " << endl;
                                cout << "\t";
                                cin >> id;
                                deletef("user",id);
                            }else{
                                if(choix1!=4)
                                    cout << "La commande n'est pas valid" << endl;
                            }
                        }
                }
            }while(choix1!=4);
            system("cls");
            break;
        case 6:
            system("cls");
            afficherLogo();
            cout << "                         Logs                                                                                " << endl;
            Logs::view();
            system("pause");
            break;
        case 7:
            cout << "Good bye!!!!! !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<< endl;
            cout << "Merci de choisire notre application"<<endl;
            break;
        default:
            cout << "La commende n'est pas valid "<< endl;
            break;
        }
    }while(choix!=7);
    return 0;
}



