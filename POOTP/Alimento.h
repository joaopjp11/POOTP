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
    Alimento(char t, int nutri, int tox, int dur, int l, int c, int id); //construtor
    virtual ~Alimento(); //destrutor
    char getTipo() const{return tipo;} //Get tipo de alimento
    int getNutricao() const{return valornutritivo;} //Get valor nutritivo
    int getDuracao() const{return duracao;} //Get duração
    int getToxicidade() const{return toxicidade;} //Get toxicidade
    int getPosLinha() const{return poslinha;} //Get posição linha
    int getPosColuna() const{return poscoluna;} //get posição coluna
    int getId() const{return idAlimento;} //Get Id do alimento
    void diminuiDuracao(); //Diminui a duração de vida do alimento
    virtual string getAsString() const; //Descrição do alimento
    virtual void AtualizaNutriToxi(){}; //Caso default
    virtual string getCheiro() const{return nullptr;}
protected:
    char tipo;
    int valornutritivo;
    int toxicidade;
    int duracao;
    int poslinha; //Linha onde se encontra
    int poscoluna; //Coluna onde se encontra
    int idAlimento;
};

#endif //POOTP_ALIMENTO_H