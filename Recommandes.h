#ifndef RECOMMANDES_H
#define RECOMMANDES_H

#include "Facteur.h"
#include "Habitant.h"
#include <iostream>
using namespace std;
class Recommandes
{
    public:
        Recommandes();
        Recommandes(unsigned int,string,Facteur,Habitant,int);
        virtual ~Recommandes();

        unsigned int Getid() const { return id; }
        void Setid(unsigned int val) { id = val; }
        string Getdate() const { return date; }
        void Setdate(string val) { date = val; }
        Facteur Getdistribuepar() const { return distribuepar; }
        void Setdistribuepar(Facteur val) { distribuepar = val; }
        Habitant Getpour() const { return pour; }
        void Setpour(Habitant val) { pour = val; }
        void afficher() const;
        static void view();
        bool ajouterRecommendes();


    protected:

    private:
        unsigned int id;
        string date;
        Facteur distribuepar;
        Habitant pour;
        int type;
};

#endif // RECOMMANDES_H
