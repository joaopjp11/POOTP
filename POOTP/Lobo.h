#ifndef POOTP_CBP_LOBO_H
#define POOTP_CBP_LOBO_H

#include "Animal.h"

class Lobo : public Animal{
public:
    Lobo(int massa, int fome, int saude, char especie, int poslinha, int poscoluna, int idAnimal, int vidainstantes); //Construtor
    ~Lobo() override = default; //Destrutor
    string getAsString() const override; //Descrição do animal
    void aumentaFome() override; //Função que vai aumentar a fome do animal com o passar de cada instante
};


#endif //POOTP_CBP_LOBO_H
