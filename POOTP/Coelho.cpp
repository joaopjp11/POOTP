#include "Coelho.h"

Coelho::Coelho(int massa, int fome, int saude, char especie, int poslinha, int poscoluna, int idAnimal, int vidainstantes): Animal(massa, fome, saude, especie, poslinha, poscoluna, idAnimal, vidainstantes){}

void Coelho::aumentaFome() {
    Animal::aumentaFome();
    if(getFome() > 10 && getFome() <= 20)
        Animal::diminuiSaude(1);
    else if(getFome() > 20)
        Animal::diminuiSaude(2);
}
