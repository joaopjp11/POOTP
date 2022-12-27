#include "Canguru.h"

Canguru::Canguru(int massa, int fome, int saude, char especie, int poslinha, int poscoluna, int idAnimal, int vidainstantes): Animal(massa, fome, saude, especie, poslinha, poscoluna, idAnimal, vidainstantes){}

string Canguru::getAsString() const {
    ostringstream os;
    os << "Animal:" << "Id-" << idAnimal << "|Especie-" << especie << "|M-" << massa << "|S-" << saude << "|V-" << vidainstantes << "|L-" << poslinha << "|C-" << poscoluna << "\n";
    return os.str();
}
