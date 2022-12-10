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
    Animal(int m, int f, int s, string n, char e, int l, int c, int id);
    ~Animal();
    int getMassa() const{return massa;}
    int getFome() const{return fome;}
    int getSaude() const{return saude;}
    string getNome() const{return nome;}
    char getEspecie() const{return especie;}
    int getPosLinha() const{return poslinha;}
    int getPosColuna() const{return poscoluna;}
    int getId() const{return idAnimal;}
    void aumentaFome();
    string getAsString() const;
private:
    int massa;
    int fome;
    int saude;
    string nome;
    char especie;
    int poslinha;
    int poscoluna;
    int idAnimal;
};


class Coelho : public Animal{
public:
    Coelho(int massa, int fome, int saude, string nome, char especie, int poslinha, int poscoluna, int idAnimal);
};

class Ovelha : public Animal{
public:
    Ovelha(int massa, int fome, int saude, string nome, char especie, int poslinha, int poscoluna, int idAnimal);
};

class Lobo : public Animal{
public:
    Lobo(int massa, int fome, int saude, string nome, char especie, int poslinha, int poscoluna, int idAnimal);
};

class Canguru : public Animal{
public:
    Canguru(int massa, int fome, int saude, string nome, char especie, int poslinha, int poscoluna, int idAnimal);
};

class Especial : public Animal{
public:

};

#endif //POOTP_ANIMAL_H
