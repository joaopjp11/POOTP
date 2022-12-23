#ifndef POOTP_CBP_CENOURA_H
#define POOTP_CBP_CENOURA_H


#include "Alimento.h"

class Cenoura : public Alimento{
    string cheiro = "verdura";
public:
    Cenoura(char tipo, int nutri, int tox, int dur, int l, int c, int id);
    ~Cenoura() override = default;
    string getAsString() const override; //Descrição do alimento
};



#endif //POOTP_CBP_CENOURA_H
