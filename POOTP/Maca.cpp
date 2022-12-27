#include "Maca.h"

Maca::Maca(char tipo, int nutri, int tox, int dur, int l, int c, int id) : Alimento(tipo, nutri, tox, dur, l, c, id) {}

string Maca::getAsString() const {
    ostringstream os;
    os << "Alimento:" << "Id-" << idAlimento << "|Tipo-" << tipo << "|C-" << cheiro << "|N-" << valornutritivo << "|T-" << toxicidade << "|D-" << duracao << "|L-" << poslinha << "|C-" << poscoluna << endl;
    return os.str();
}

void Maca::AtualizaNutriToxi() {
    if(valornutritivo > 0)
        valornutritivo--;
    if(toxicidade < 5)
        toxicidade++;
}
