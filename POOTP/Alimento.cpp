#include "Alimento.h"

Alimento::Alimento(int nutri, int tox, int dur, string cheiro, int l, int c, int id):valornutritivo(nutri),toxicidade(tox),duracao(dur),cheiro(cheiro),poslinha(l),poscoluna(c), idAlimento(id) {}

Alimento::~Alimento() {}

string Alimento::getAsString() const {
    ostringstream os;
    os << "Alimento:" << " Id - " << idAlimento << "| cheiro - " << cheiro << "| valor nutritivo - " << valornutritivo << "| toxicidade - " << toxicidade << "| duracao - " << duracao << "| linha - " << poslinha << "| coluna - " << poscoluna << endl;
    return os.str();
}

Relva::Relva(int nutri, int tox, int dur, string cheiro, int l, int c, int id) : Alimento(nutri, tox, dur, cheiro, l, c, id) {

}

Cenoura::Cenoura(int nutri, int tox, int dur, string cheiro, int l, int c, int id) : Alimento(nutri, tox, dur, cheiro, l, c, id) {

}

Corpo::Corpo(int nutri, int tox, int dur, string cheiro, int l, int c, int id) : Alimento(nutri, tox, dur, cheiro, l, c, id) {

}

Bife::Bife(int nutri, int tox, int dur, string cheiro, int l, int c, int id) : Alimento(nutri, tox, dur, cheiro, l, c, id) {

}
