#ifndef POOTP_CBP_MACA_H
#define POOTP_CBP_MACA_H

#include "Alimento.h"

class Maca : public Alimento{
    string cheiro = "fruta";
public:
    Maca(char tipo, int nutri, int tox, int dur, int l, int c, int id);
    ~Maca() override = default;
    string getAsString() const override; //Descrição do alimento
    void AtualizaNutriToxi() override;
};


#endif //POOTP_CBP_MACA_H
