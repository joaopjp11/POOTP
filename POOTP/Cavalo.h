#ifndef POOTP_CBP_CAVALO_H
#define POOTP_CBP_CAVALO_H

#include "Animal.h"

class Cavalo : public Animal{
public:
    Cavalo(int massa, int fome, int saude, char especie, int poslinha, int poscoluna, int idAnimal, int vidainstantes); //Construtor
    ~Cavalo() override = default; //Destrutor
    void aumentaFome() override; //Função que vai aumentar a fome do animal com o passar de cada instante
};

#endif //POOTP_CBP_CAVALO_H
