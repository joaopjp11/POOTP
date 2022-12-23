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
    //Obtem variáveis constantes - que serão declaradas no ficheiro constantes.txt
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
    void setConstantes(istringstream &recebe); //Lê ficheiro constantes.txt e retira os valores das variáveis
    Jogo& operator=(const Jogo& aux) //Operador "="
    {
        nomeJogo = aux.nomeJogo;
        Reserva newreserva(*aux.reserva);
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
    string nomeJogo; //nome jogo
    Reserva *reserva; //Reserva
    int instante; //nº de instantes
    //variáveis definidas pelo ficheiro constantes.txt
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
    vector<Jogo*> JogosGuardados; //vetor que guarda a lista de jogo guardados
public:
    void storeJogo(Jogo* aux); //Guarda jogo no vetor JogosGuardados
    Jogo* encontraJogo(string nome); //Encontra um jogo especifico (através do nome) no vetor JogosGuardados
};

#endif //POOTP_JOGO_H
