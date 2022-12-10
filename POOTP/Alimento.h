#ifndef POOTP_ALIMENTO_H
#define POOTP_ALIMENTO_H

#include <sstream>
#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Alimento {
public:
    Alimento(int nutri, int tox, int dur, string cheiro, int l, int c, int id);
    ~Alimento();
    int getNutricao() const{return valornutritivo;}
    int getDuracao() const{return duracao;}
    int getToxicidade() const{return toxicidade;}
    string getCheiro() const{return cheiro;}
    int getPosLinha() const{return poslinha;}
    int getPosColuna() const{return poscoluna;}
    int getId() const{return idAlimento;}
    string getAsString() const;
private:
    int valornutritivo;
    int toxicidade;
    int duracao;
    string cheiro;
    int poslinha;
    int poscoluna;
    int idAlimento;
};

class Relva : public Alimento{
public:

};

class Cenoura : public Alimento{
public:

};

class Corpo : public Alimento{
public:

};

class Bife : public Alimento{
public:

};

class Misterio : public Alimento{
public:

};


#endif //POOTP_ALIMENTO_H
