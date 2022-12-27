#ifndef POOTP_CBP_BIFE_H
#define POOTP_CBP_BIFE_H


#include "Alimento.h"

class Bife : public Alimento{
    string cheiro[2] = {"carne","ketchup"};
public:
    Bife(char tipo, int nutri, int tox, int dur, int l, int c, int id);
    ~Bife() override = default;
    string getAsString() const override; //Descrição do alimento
    void AtualizaNutriToxi() override;
};


#endif //POOTP_CBP_BIFE_H
