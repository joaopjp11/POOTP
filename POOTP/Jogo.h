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
    Jogo(Reserva *aux, int i = 0):reserva(aux),instante(i){}
    Reserva* getReserva() const{return reserva;}
    void incrementaInstante(int num, int pausa=0);
    int getSCoelho() const{return SCoelho;}
    int getVCoelho() const{return VCoelho;}
    int getSOvelha() const{return SOvelha;}
    int getVOvelha() const{return VOvelha;}
    int getSLobo() const{return SLobo;}
    int getPLobo() const{return PLobo;}
    int getSCanguru() const{return SCanguru;}
    int getVCanguru() const{return VCanguru;}
    int getPCanguru() const{return PCanguru;}
    void setConstantes(istringstream &recebe);
private:
    Reserva *reserva;
    int instante;
    int SCoelho;
    int VCoelho;
    int SOvelha;
    int VOvelha;
    int SLobo;
    int PLobo;
    int SCanguru;
    int VCanguru;
    int PCanguru;
};


#endif //POOTP_JOGO_H
