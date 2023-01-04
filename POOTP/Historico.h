#ifndef POOTP_CBP_HISTORICO_H
#define POOTP_CBP_HISTORICO_H

#include <sstream>
#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>

using namespace std;

class Historico { //Representa cada elemento do histórico de alimentação dos animais
public:
    Historico(string n, int nutri, int toxi); //Construtor
    ~Historico() = default; //Destrutor
    string nome; //nome
    int nutricao; //valor nutricional
    int toxicidade; //valor de toxicidade
    Historico* next; //Ponteiro para o próximo elemento do histórico
};


#endif //POOTP_CBP_HISTORICO_H
