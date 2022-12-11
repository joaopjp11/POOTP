#include "Alimento.h"

Alimento::Alimento(char t, int nutri, int tox, int dur, string cheiro, int l, int c, int id):tipo(t), valornutritivo(nutri),toxicidade(tox),duracao(dur),cheiro(cheiro),poslinha(l),poscoluna(c), idAlimento(id) {}

Alimento::~Alimento() {}

string Alimento::getAsString() const {
    ostringstream os;
    os << "Alimento:" << " Id - " << idAlimento << "| cheiro - " << cheiro << "| valor nutritivo - " << valornutritivo << "| toxicidade - " << toxicidade << "| duracao - " << duracao << "| linha - " << poslinha << "| coluna - " << poscoluna << endl;
    return os.str();
}

Relva::Relva(char tipo, int nutri, int tox, int dur, string cheiro, int l, int c, int id) : Alimento(tipo, nutri, tox, dur, cheiro, l, c, id) {

}

Cenoura::Cenoura(char tipo, int nutri, int tox, int dur, string cheiro, int l, int c, int id) : Alimento(tipo, nutri, tox, dur, cheiro, l, c, id) {

}

Corpo::Corpo(char tipo, int nutri, int tox, int dur, string cheiro, int l, int c, int id) : Alimento(tipo, nutri, tox, dur, cheiro, l, c, id) {

}

Bife::Bife(char tipo, int nutri, int tox, int dur, string cheiro, int l, int c, int id) : Alimento(tipo, nutri, tox, dur, cheiro, l, c, id) {

}
