#ifndef COLIS_H
#define COLIS_H

#include "Recommandes.h"


class Colis : public Recommandes
{
    public:
        Colis(unsigned int,string,Facteur,Habitant,int);
        virtual ~Colis();

    protected:

    private:
};

#endif // COLIS_H
