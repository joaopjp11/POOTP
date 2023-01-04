#ifndef POOTP_ANIMAL_H
#define POOTP_ANIMAL_H

#include "Alimento.h"
#include "Historico.h"

#include <sstream>
#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Animal {
public:
    Animal(int m, int f, int s, char e, int l, int c, int id, int vinst); //construtor
    virtual ~Animal(); //destrutor
    void setPoslinha(int nl){poslinha = nl;} //Set posição linha
    void setPoscoluna(int nc){poscoluna = nc;} //Set posição coluna
    int getMassa() const{return massa;} //Get massa
    void setMassa(int num){this->massa = num;} //Set massa
    int getFome() const{return fome;} //Get fome
    int getSaude() const{return saude;} //Get saude
    char getEspecie() const{return especie;} //Get especia
    int getPosLinha() const{return poslinha;} //Get posição linha
    int getPosColuna() const{return poscoluna;} //Get posição coluna
    int getVidaInstantes() const{return vidainstantes;} //Get instantes que o animal fica vivo
    int getId() const{return idAnimal;} //get Id
    int getInstantesDecorridos() const {return instantesDecorridos;} //Get instantes decorridos na vida de um animal
    void aumentaInstantesDecorridos(); //Incrementa o numero de instantes já vividos pelo animal
    virtual void aumentaFome(); //Aumenta a fome do animal
    void aumentaSaude(int num); //Incrementa a fome
    void diminuiSaude(int num); //Decrementa a saude
    void diminuiFome(int num); //Decrementa a fome
    void diminuiinstantes(); //Diminui os instantes de vida que sobram para cada animal
    virtual string getAsString() const; //Descrição do animal
    void insertHist(string n, int nutri, int tox); //Insere alimento no histórico de alimentação
    string printList(); //Devolve a descrição do histórico de alimentação

protected:
    int massa;
    int fome;
    int saude;
    char especie;
    int poslinha; //Linha onde se encontra
    int poscoluna; //Coluna onde se encontra
    int vidainstantes; //Limite de instantes que o animal pode viver
    int idAnimal;
    Historico * hist; //Histórico de alimentação
    int instantesDecorridos; //Nº de instantes decorridos desde que este animal apareceu
};

#endif //POOTP_ANIMAL_H