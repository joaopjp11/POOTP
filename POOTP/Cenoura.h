#ifndef POOTP_CBP_CENOURA_H
#define POOTP_CBP_CENOURA_H


#include "Alimento.h"

class Cenoura : public Alimento{
    string cheiro = "verdura"; //Cheiro caracteristico do alimento
    int ninstantedecorrido = 0; //nº de instantes decorridos desde que este alimento apareceu na reserva
public:
    Cenoura(char tipo, int nutri, int tox, int dur, int l, int c, int id); //Construtor
    ~Cenoura() override = default; //Destrutor
    string getAsString() const override; //Descrição do alimento
    string getCheiro() const override{return cheiro;}
    void AtualizaNutriToxi() override; //Função que vai atualizar o valor nutricional e de toxicidade do alimento com o passar de cada instante
};



#endif //POOTP_CBP_CENOURA_H
