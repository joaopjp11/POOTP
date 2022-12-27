#include "Cenoura.h"

Cenoura::Cenoura(char tipo, int nutri, int tox, int dur, int l, int c, int id) : Alimento(tipo, nutri, tox, dur, l, c, id) {}

string Cenoura::getAsString() const {
    ostringstream os;
    os << "Alimento:" << "Id-" << idAlimento << "|Tipo-" << tipo << "|C-" << cheiro << "|N-" << valornutritivo << "|T-" << toxicidade << "|L-" << poslinha << "|C-" << poscoluna << endl;
    return os.str();
}

void Cenoura::AtualizaNutriToxi() {
    ++ninstantedecorrido;

    if(ninstantedecorrido == 10 || ninstantedecorrido == 20 || ninstantedecorrido == 30)
        toxicidade++;
}
