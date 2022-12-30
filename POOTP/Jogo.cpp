#include "Jogo.h"

void Jogo::incrementaInstante(int num, int pausa) {
    instante += num;
}

void Store::storeJogo(Jogo *aux) {
    JogosGuardados.push_back(aux);
}

Jogo *Store::encontraJogo(string nome) {
    for(int i=0; i<JogosGuardados.size(); i++) {
        if (JogosGuardados[i]->getNomeJogo() == nome) {
            return JogosGuardados[i];
        }
    }
    return nullptr;
}
