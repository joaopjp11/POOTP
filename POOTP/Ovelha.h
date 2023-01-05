#ifndef POOTP_CBP_OVELHA_H
#define POOTP_CBP_OVELHA_H

#include "Animal.h"

class Ovelha : public Animal{
public:
    Ovelha(int massa, int fome, int saude, char especie, int poslinha, int poscoluna, int idAnimal, int vidainstantes); //Construtor
    ~Ovelha() override = default; //Destrutor
    void aumentaFome() override; //Função que vai aumentar a fome do animal com o passar de cada instante
};


#endif //POOTP_CBP_OVELHA_H
