#ifndef POOTP_CBP_MACA_H
#define POOTP_CBP_MACA_H

#include "Alimento.h"

class Maca : public Alimento{
    string cheiro = "fruta"; //Cheiro caracteristico do alimento
public:
    Maca(char tipo, int nutri, int tox, int dur, int l, int c, int id); //Construtor
    ~Maca() override = default; //Destrutor
    string getCheiro() const override{return cheiro;}
    string getAsString() const override; //Descrição do alimento
    void AtualizaNutriToxi() override; //Função que vai atualizar o valor nutricional e de toxicidade do alimento com o passar de cada instante
};


#endif //POOTP_CBP_MACA_H
