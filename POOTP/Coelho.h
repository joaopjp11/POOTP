#ifndef POOTP_CBP_COELHO_H
#define POOTP_CBP_COELHO_H

#include "Animal.h"

class Coelho : public Animal{
public:
    Coelho(int massa, int fome, int saude, char especie, int poslinha, int poscoluna, int idAnimal, int vidainstantes); //Construtor
    ~Coelho() override = default; //Destrutor
    void aumentaFome() override; //Função que vai aumentar a fome do animal com o passar de cada instante
};


#endif //POOTP_CBP_COELHO_H
