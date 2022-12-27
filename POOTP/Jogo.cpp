#include "Jogo.h"

void Jogo::incrementaInstante(int num, int pausa) {
    instante += num;
}

void Jogo::setConstantes(istringstream &recebe) {
    string var;
    int valor;
    recebe >> var;

    if(var == "SCoelho"){
        recebe >> valor;
        SCoelho = valor;
    }else if(var == "VCoelho"){
        recebe >> valor;
        VCoelho = valor;
    }else if(var == "SOvelha"){
        recebe >> valor;
        SOvelha = valor;
    }else if(var == "VOvelha"){
        recebe >> valor;
        VOvelha = valor;
    }else if(var == "SLobo"){
        recebe >> valor;
        SLobo = valor;
    }else if(var == "PLobo"){
        recebe >> valor;
        PLobo = valor;
    }else if(var == "SCanguru"){
        recebe >> valor;
        SCanguru = valor;
    }else if(var == "VCanguru"){
        recebe >> valor;
        VCanguru = valor;
    }else if(var == "PCanguru"){
        recebe >> valor;
        PCanguru = valor;
    }else if(var == "SCavalo"){
        recebe >> valor;
        SCavalo = valor;
    }else if(var == "VCavalo"){
        recebe >> valor;
        VCavalo = valor;
    }else if(var == "PCavalo"){
        recebe >> valor;
        PCavalo = valor;
    }else if(var == "VRelva"){
        recebe >> valor;
        VRelva = valor;
    }else if(var == "VBife"){
        recebe >> valor;
        VBife = valor;
    }else if(var == "VMaca"){
        recebe >> valor;
        VMaca = valor;
    }
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
