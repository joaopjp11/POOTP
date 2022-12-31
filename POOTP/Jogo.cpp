#include "Jogo.h"

void Jogo::incrementaInstante(int num, int pausa) {
    instante += num;
}

string Jogo::DetalhesJogo() {
    ostringstream os;
    os << "Instante: " << instante << "\n";
    os << "Total de Animais: " << getReserva()->TotalAnimais() << "\n";
    os << "Total de Alimentos: " << getReserva()->TotalAlimentos() << "\n";
    os << "Coordenadas: " << "POR IMPLEMENTAR" << "\n";
    return os.str();
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
