#ifndef POOTP_CBP_CAVALO_H
#define POOTP_CBP_CAVALO_H

#include "Animal.h"

class Cavalo : public Animal{
public:
    Cavalo(int massa, int fome, int saude, char especie, int poslinha, int poscoluna, int idAnimal, int vidainstantes);
    ~Cavalo() override = default;
    void aumentaFome() override;
};

#endif //POOTP_CBP_CAVALO_H
