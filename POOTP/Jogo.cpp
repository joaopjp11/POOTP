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
    }
}