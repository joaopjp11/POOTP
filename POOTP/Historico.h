#ifndef POOTP_CBP_HISTORICO_H
#define POOTP_CBP_HISTORICO_H

#include <sstream>
#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>

using namespace std;

class Historico {
public:
    Historico(string n, int nutri, int toxi);
    ~Historico() = default;
    string nome;
    int nutricao;
    int toxicidade;
    Historico* next;
};


#endif //POOTP_CBP_HISTORICO_H
