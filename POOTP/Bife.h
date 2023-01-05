#ifndef POOTP_CBP_BIFE_H
#define POOTP_CBP_BIFE_H


#include "Alimento.h"

class Bife : public Alimento{
    string cheiro[2] = {"carne","ketchup"}; //Cheiro caracteristico do alimento
public:
    Bife(char tipo, int nutri, int tox, int dur, int l, int c, int id); //Construtor
    ~Bife() override = default; //Destrutor
    string getCheiro() const override;
    string getAsString() const override; //Descrição do alimento
    void AtualizaNutriToxi() override; //Função que vai atualizar o valor nutricional e de toxicidade do alimento com o passar de cada instante
};


#endif //POOTP_CBP_BIFE_H
