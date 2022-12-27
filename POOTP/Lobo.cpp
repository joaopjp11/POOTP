#include "Lobo.h"

Lobo::Lobo(int massa, int fome, int saude, char especie, int poslinha, int poscoluna, int idAnimal, int vidainstantes): Animal(massa, fome, saude, especie, poslinha, poscoluna, idAnimal, vidainstantes){}

void Lobo::aumentaFome() {
    Animal::aumentaFome();
    Animal::aumentaFome();
    if(getFome() > 15 && getFome() <= 25)
        Animal::diminuiSaude(1);
    else if(getFome() > 25)
        Animal::diminuiSaude(2);
}

string Lobo::getAsString() const {
    ostringstream os;
    os << "Animal:" << "Id-" << idAnimal << "|Especie-" << especie << "|M-" << massa << "|F-" << fome << "|S-" << saude << "|L-" << poslinha << "|C-" << poscoluna << "\n";
    return os.str();
}
