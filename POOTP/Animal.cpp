#include "Animal.h"

Animal::Animal(int m, int f, int s, char e, int l, int c, int id, int vinst): massa(m),fome(f),saude(s),especie(e),poslinha(l),poscoluna(c), idAnimal(id), vidainstantes(vinst), hist(nullptr){
    instantesDecorridos = 0;
}

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

void Animal::aumentaSaude(int num) {
    this->saude = this->saude + num;
}

void Animal::diminuiSaude(int num) {
    this->saude = this->saude - num;
}

void Animal::diminuiFome(int num) {
    if(this->fome - num <= 0)
        this->fome = 0;
    else
        this->fome = fome - num;
}

void Animal::insertHist(string n, int nutri, int tox) {
    Historico * newNode = new Historico{n, nutri, tox};
    if (hist == nullptr) {
        hist = newNode;
    } else {
        Historico* current = hist;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

string Animal::printList() {
    ostringstream os;
    Historico* current = hist;
    while (current != nullptr) {
        os << current->nome << " " << current->nutricao << " " << current->toxicidade << endl;
        current = current->next;
    }
    return os.str();
}

void Animal::aumentaInstantesDecorridos() {
    ++instantesDecorridos;
}
