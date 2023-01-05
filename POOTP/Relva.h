#ifndef POOTP_CBP_RELVA_H
#define POOTP_CBP_RELVA_H


#include "Alimento.h"

class Relva : public Alimento{
    string cheiro[2]= {"erva","verdura"}; //Cheiro caracteristico do alimento
public:
    Relva(char tipo, int nutri, int tox, int dur, int l, int c, int id); //Construtor
    ~Relva() override = default; //Destrutor
    string getCheiro() const override;
    string getAsString() const override; //Descrição do alimento
};


#endif //POOTP_CBP_RELVA_H
