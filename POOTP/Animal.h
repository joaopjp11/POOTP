#ifndef POOTP_ANIMAL_H
#define POOTP_ANIMAL_H

#include "Alimento.h"

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
    int getFome() const{return fome;} //Get fome
    int getSaude() const{return saude;} //Get saude
    char getEspecie() const{return especie;} //Get especia
    int getPosLinha() const{return poslinha;} //Get posição linha
    int getPosColuna() const{return poscoluna;} //Get posição coluna
    int getVidaInstantes() const{return vidainstantes;} //Get instantes que o animal fica vivo
    int getId() const{return idAnimal;} //get Id
    void aumentaFome(); //Aumenta a fome do animal
    string getAsString() const; //Descrição do animal
    void movimentoCoelho(int nl, int nc);
    void movimentoOvelha(int nl, int nc);
    void movimentoLobo(int nl, int nc);
    void movimentoCanguru(int nl, int nc);
private:
    int massa;
    int fome;
    int saude;
    char especie;
    int poslinha;
    int poscoluna;
    int idAnimal;
    int vidainstantes;
};


class Especial : public Animal{
public:

};

#endif //POOTP_ANIMAL_H
