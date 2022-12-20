#ifndef POOTP_CBP_CORPO_H
#define POOTP_CBP_CORPO_H

#include "Alimento.h"

class Corpo : public Alimento{
public:
    Corpo(char tipo, int nutri, int tox, int dur, string cheiro, int l, int c, int id);
};


#endif //POOTP_CBP_CORPO_H
