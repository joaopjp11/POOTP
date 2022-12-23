#ifndef POOTP_CBP_CORPO_H
#define POOTP_CBP_CORPO_H

#include "Alimento.h"

class Corpo : public Alimento{
    string cheiro = "carne";
public:
    Corpo(char tipo, int nutri, int tox, int dur, int l, int c, int id);
    ~Corpo() override = default;
    string getAsString() const override; //Descrição do alimento
};


#endif //POOTP_CBP_CORPO_H
