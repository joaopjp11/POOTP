#ifndef POOTP_CBP_CORPO_H
#define POOTP_CBP_CORPO_H

#include "Alimento.h"

class Corpo : public Alimento{
    string cheiro = "carne"; //Cheiro caracteristico do alimento
    int conta = 0; //Vai ser usada para guardar o dobro do valor da nutrição do corpo
    int ninstantedecorrido = 0; //nº de instantes decorridos desde que este alimento apareceu na reserva
public:
    Corpo(char tipo, int nutri, int tox, int dur, int l, int c, int id); //Construtor
    ~Corpo() override = default; //Destrutor
    string getCheiro() const override{return cheiro;}
    string getAsString() const override; //Descrição do alimento
    void AtualizaNutriToxi() override; //Função que vai atualizar o valor nutricional e de toxicidade do alimento com o passar de cada instante
};


#endif //POOTP_CBP_CORPO_H
