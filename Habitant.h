#ifndef HABITANT_H
#define HABITANT_H

#include "ZoneGeographique.h"
#include<iostream>
using  namespace std;
class Habitant
{
    public:
        Habitant();
        Habitant(unsigned int,string,string,ZoneGeographique);
        virtual ~Habitant();

        unsigned int Getid() const { return id; }
        void Setid(unsigned int val) { id = val; }
        string Getnom() const { return nom; }
        void Setnom(string nom) { this->nom = nom; }
        string Getprenom() const { return prenom; }
        void Setprenom(string val) { prenom = val; }
        ZoneGeographique Getassocies() const { return associes; }
        void Setassocies(ZoneGeographique val) { associes = val; }
        void afficher() const;
        static void view();
        bool ajouterHabitant();


    protected:

    private:
        unsigned int id;
        string nom;
        string prenom;
        ZoneGeographique associes;
};

#endif // HABITANT_H
