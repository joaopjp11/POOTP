#ifndef POOTP_CBP_LOBO_H
#define POOTP_CBP_LOBO_H

#include "Animal.h"

class Lobo : public Animal{

public:
    Lobo(int massa, int fome, int saude, char especie, int poslinha, int poscoluna, int idAnimal, int vidainstantes);
    ~Lobo() override = default;
    string getAsString() const override;
    void aumentaFome() override;
};


#endif //POOTP_CBP_LOBO_H
