#ifndef POOTP_CBP_CANGURU_H
#define POOTP_CBP_CANGURU_H


#include "Animal.h"

class Canguru : public Animal{
public:
    Canguru(int massa, int fome, int saude, char especie, int poslinha, int poscoluna, int idAnimal, int vidainstantes);
    ~Canguru() override= default;
    string getAsString() const override;
};


#endif //POOTP_CBP_CANGURU_H
