#ifndef LETTRE_H
#define LETTRE_H

#include "Recommandes.h"


class Lettre : public Recommandes
{
    public:
        Lettre(unsigned int,string,Facteur,Habitant,int);
        virtual ~Lettre();

    protected:

    private:
};

#endif // LETTRE_H
