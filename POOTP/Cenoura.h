#ifndef POOTP_CBP_CENOURA_H
#define POOTP_CBP_CENOURA_H


#include "Alimento.h"

class Cenoura : public Alimento{
    string cheiro = "verdura";
    int ninstantedecorrido = 0;
public:
    Cenoura(char tipo, int nutri, int tox, int dur, int l, int c, int id);
    ~Cenoura() override = default;
    string getAsString() const override; //Descrição do alimento
    void AtualizaNutriToxi() override;
};



#endif //POOTP_CBP_CENOURA_H
