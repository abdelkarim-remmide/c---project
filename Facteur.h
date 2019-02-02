#ifndef FACTEUR_H
#define FACTEUR_H

#include <iostream>
using namespace std;

class Facteur
{
    public:
        Facteur();
        Facteur(int id,string nom,string prenom,string dateNaiss,string dateCree);
        virtual ~Facteur();

        string Getnom() const { return nom; }
        void Setnom(string val) { nom = val; }
        string Getprenom() const { return prenom; }
        void Setprenom(string val) { prenom = val; }
        int Getid() const { return id; }
        void Setid(int val) { id = val; }
        string GetdateCree() const { return dateCree; }
        void SetdateCree(string val) { dateCree = val; }
        string GetdateNaiss() const { return dateNaiss; }
        void SetdateNaiss(string val) { dateNaiss = val; }
        void afficher() const;
        static void view();
        bool ajouterFacteur();

    protected:

    private:
        string nom;
        string prenom;
        int id;
        string dateCree;
        string dateNaiss;
};

#endif // FACTEUR_H
