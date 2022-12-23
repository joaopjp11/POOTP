#ifndef POOTP_CBP_RELVA_H
#define POOTP_CBP_RELVA_H


#include "Alimento.h"

class Relva : public Alimento{
    string cheiro[2]= {"erva","verdura"};
public:
    Relva(char tipo, int nutri, int tox, int dur, int l, int c, int id);
    ~Relva() override = default;
    string getAsString() const override; //Descrição do alimento
};


#endif //POOTP_CBP_RELVA_H
