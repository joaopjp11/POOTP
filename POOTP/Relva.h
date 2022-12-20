#ifndef POOTP_CBP_RELVA_H
#define POOTP_CBP_RELVA_H


#include "Alimento.h"

class Relva : public Alimento{
public:
    Relva(char tipo, int nutri, int tox, int dur, string cheiro, int l, int c, int id);
};


#endif //POOTP_CBP_RELVA_H
