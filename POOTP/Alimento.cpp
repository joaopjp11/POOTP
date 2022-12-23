#include "Alimento.h"

Alimento::Alimento(char t, int nutri, int tox, int dur, int l, int c, int id):tipo(t), valornutritivo(nutri),toxicidade(tox),duracao(dur),poslinha(l),poscoluna(c), idAlimento(id) {}

Alimento::~Alimento() {}

void Alimento::diminuiDuracao() {
    duracao--;
}

string Alimento::getAsString() const {
    ostringstream os;
    os << "Alimento:" << "Id-" << idAlimento << "|Tipo-" << tipo << "|N-" << valornutritivo << "|T-" << toxicidade << "|D-" << duracao << "|L-" << poslinha << "|C-" << poscoluna << endl;
    return os.str();
}
