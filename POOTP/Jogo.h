#ifndef POOTP_JOGO_H
#define POOTP_JOGO_H

#include "Reserva.h"

#include <sstream>
#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Jogo {
public:
    Jogo(Reserva *aux, int i = 0):reserva(aux),instante(i){} //Construtor
    ~Jogo() = default; //Destrutor
    Reserva* getReserva() const{return reserva;} //Obtem reserva
    void setNomeJogo(string nome){nomeJogo = nome;} //Declara nome do jogo(save)
    string getNomeJogo() const{return nomeJogo;} //Obtem nome do jogo(save)
    void incrementaInstante(int num, int pausa=0); //Incrementa o nº de instantes
    Jogo& operator=(const Jogo& aux) //Operador "="
    {
        nomeJogo = aux.nomeJogo;
        Reserva newreserva(*aux.reserva);
        instante = aux.instante;
        return *this;
    }
private:
    string nomeJogo; //nome jogo
    Reserva *reserva; //Reserva
    int instante; //nº de instantes
};


class Store{
    vector<Jogo*> JogosGuardados; //vetor que guarda a lista de jogo guardados
public:
    void storeJogo(Jogo* aux); //Guarda jogo no vetor JogosGuardados
    Jogo* encontraJogo(string nome); //Encontra um jogo especifico (através do nome) no vetor JogosGuardados
};

#endif //POOTP_JOGO_H
