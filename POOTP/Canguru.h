#ifndef POOTP_CBP_CANGURU_H
#define POOTP_CBP_CANGURU_H


#include "Animal.h"

class Canguru : public Animal{
public:
    Canguru(int massa, int fome, int saude, char especie, int poslinha, int poscoluna, int idAnimal, int vidainstantes); //Construtor
    ~Canguru() override= default; //Destrutor
    string getAsString() const override; //Descrição do animal
};


#endif //POOTP_CBP_CANGURU_H
