#include "Bife.h"

Bife::Bife(char tipo, int nutri, int tox, int dur, int l, int c, int id) : Alimento(tipo, nutri, tox, dur, l, c, id) {}

string Bife::getAsString() const {
    ostringstream os;
    os << "Alimento:" << "Id-" << idAlimento << "|Tipo-" << tipo << "|C-carne,ketchup" << "|N-" << valornutritivo << "|T-" << toxicidade << "|D-" << duracao << "|L-" << poslinha << "|C-" << poscoluna << endl;
    return os.str();
}

void Bife::AtualizaNutriToxi() {
    if(valornutritivo > 0)
        valornutritivo--;
}

string Bife::getCheiro() const {
    ostringstream os;
    os << cheiro[0] << " " << cheiro[1];
    return os.str();
}
