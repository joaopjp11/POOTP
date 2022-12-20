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
    void setNomeJogo(string nome){nomeJogo = nome;}
    string getNomeJogo() const{return nomeJogo;}
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
    int getVRelva() const{return VRelva;}
    int getVBife() const{return VBife;}
    void setConstantes(istringstream &recebe);
    Jogo& operator=(const Jogo& aux)
    {
        nomeJogo = aux.nomeJogo;
        reserva = aux.reserva;
        instante = aux.instante;
        SCoelho = aux.SCoelho;
        VCoelho = aux.VCoelho;
        SOvelha = aux.SOvelha;
        VOvelha = aux.VOvelha;
        SLobo = aux.SLobo;
        PLobo = aux.PLobo;
        SCanguru = aux.SCanguru;
        VCanguru = aux.VCanguru;
        PCanguru = aux.PCanguru;
        VRelva = aux.VRelva;
        VBife = aux.VBife;
        return *this;
    }
private:
    string nomeJogo;
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
    int VRelva;
    int VBife;
};


class Store{
    vector<Jogo*> JogosGuardados;
public:
    void storeJogo(Jogo* aux);
    Jogo* encontraJogo(string nome);
};

#endif //POOTP_JOGO_H
