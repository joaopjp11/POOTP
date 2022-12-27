#ifndef POOTP_CBP_OVELHA_H
#define POOTP_CBP_OVELHA_H

#include "Animal.h"

class Ovelha : public Animal{
    int vidainstantes;
public:
    Ovelha(int massa, int fome, int saude, char especie, int poslinha, int poscoluna, int idAnimal, int vidainstantes);
    ~Ovelha() override = default;
    void aumentaFome() override;
};


#endif //POOTP_CBP_OVELHA_H
