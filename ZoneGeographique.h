#ifndef ZONEGEOGRAPHIQUE_H
#define ZONEGEOGRAPHIQUE_H

#include "Facteur.h"
#include<iostream>
using namespace std;
class ZoneGeographique
{
    public:
        ZoneGeographique();
        ZoneGeographique(unsigned int,string,Facteur);
        virtual ~ZoneGeographique();

        unsigned int Getid() const { return id; }
        void Setid(unsigned int val) { id = val; }
        string Getnom() const { return nom; }
        void Setnom(string val) { nom = val; }
        Facteur Getfacteur() const { return facteur; }
        void Setfacteur(Facteur val) { facteur = val; }
        void afficher() const;
        bool ajouterZone();
        static void view();

    protected:

    private:
        unsigned int id;
        string nom;
        Facteur facteur;
};

#endif // ZONEGEOGRAPHIQUE_H
