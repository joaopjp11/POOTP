#include "Corpo.h"

Corpo::Corpo(char tipo, int nutri, int tox, int dur, int l, int c, int id) : Alimento(tipo, nutri, tox, dur, l, c, id) {
    conta = getNutricao()*2;
}

string Corpo::getAsString() const {
    ostringstream os;
    os << "Alimento:" << "Id-" << idAlimento << "|Tipo-" << tipo << "|C-" << cheiro << "|N-" << valornutritivo << "|T-" << toxicidade << "|L-" << poslinha << "|C-" << poscoluna << endl;
    return os.str();
}

void Corpo::AtualizaNutriToxi() {
    ++ninstantedecorrido;

    if(valornutritivo > 0)
        valornutritivo--;
    if(ninstantedecorrido <= conta)
        toxicidade++;
}
