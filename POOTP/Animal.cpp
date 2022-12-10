#include "Animal.h"

Animal::Animal(int m, int f, int s, string n, char e, int l, int c, int id): massa(m),fome(f),saude(s),nome(n),especie(e),poslinha(l),poscoluna(c), idAnimal(id){}

Animal::~Animal() {}

void Animal::aumentaFome() {
    fome++;
}

string Animal::getAsString() const {
    ostringstream os;
    os << "Animal:" << " Id - " << idAnimal << "| nome - " << nome << "| especie - " << especie << "| massa - " << massa << "| fome - " << fome << "| saude - " << saude << "| linha - " << poslinha << "| coluna - " << poscoluna << endl;
    return os.str();
}

Coelho::Coelho(int massa, int fome, int saude, string nome, char especie, int poslinha, int poscoluna, int idAnimal): Animal(massa, fome, saude, nome, especie, poslinha, poscoluna, idAnimal) {

}

Ovelha::Ovelha(int massa, int fome, int saude, string nome, char especie, int poslinha, int poscoluna, int idAnimal): Animal(massa, fome, saude, nome, especie, poslinha, poscoluna, idAnimal) {

}

Lobo::Lobo(int massa, int fome, int saude, string nome, char especie, int poslinha, int poscoluna, int idAnimal): Animal(massa, fome, saude, nome, especie, poslinha, poscoluna, idAnimal) {

}

Canguru::Canguru(int massa, int fome, int saude, string nome, char especie, int poslinha, int poscoluna, int idAnimal): Animal(massa, fome, saude, nome, especie, poslinha, poscoluna, idAnimal) {

}
