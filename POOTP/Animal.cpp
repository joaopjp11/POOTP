#include "Animal.h"

Animal::Animal(int m, int f, int s, char e, int l, int c, int id, int vinst): massa(m),fome(f),saude(s),especie(e),poslinha(l),poscoluna(c), idAnimal(id), vidainstantes(vinst){}

Animal::~Animal() {}

void Animal::aumentaFome() {
    fome++;
}

string Animal::getAsString() const {
    ostringstream os;
    os << "Animal:" << "Id-" << idAnimal << "|Especie-" << especie << "|M-" << massa << "|F-" << fome << "|S-" << saude << "|V-" << vidainstantes << "|L-" << poslinha << "|C-" << poscoluna << "\n";
    return os.str();
}

void Animal::diminuiinstantes() {
    this->vidainstantes--;
}

void Animal::diminuiSaude(int num) {
    this->saude = this->saude - num;
}
