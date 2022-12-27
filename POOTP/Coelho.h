#ifndef POOTP_CBP_COELHO_H
#define POOTP_CBP_COELHO_H

#include "Animal.h"

class Coelho : public Animal{
public:
    Coelho(int massa, int fome, int saude, char especie, int poslinha, int poscoluna, int idAnimal, int vidainstantes);
    ~Coelho() override = default;
    void aumentaFome() override;
};


#endif //POOTP_CBP_COELHO_H
