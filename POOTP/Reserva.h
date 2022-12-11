#ifndef POOTP_RESERVA_H
#define POOTP_RESERVA_H

#include "Animal.h"
#include <sstream>
#include <string>
#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Reserva {
public:
    Reserva(int nl, int nc);
    ~Reserva();
    int getLinhas() const{return NL;}
    int getColunas() const{return NC;}
    void AddAnimal(const Animal &a);
    void AddAlimento(const Alimento &a);
    string getAsString() const;
    int newId();
    bool procuraIdAnimal(int id) const;
    bool procuraIdAlimento(int id) const;
    string listAnimal(int id) const;
    string listAlimento(int id) const;
    int verificaLinhaColunaAnimal(int nl, int nc) const;
    int verificaLinhaColunaAlimento(int nl, int nc) const;
    bool mataAnimal(int id) const;
    bool removeAlimento(int id) const;
private:
    int NL;
    int NC;
    int id = 1;
    vector<Animal> animais;
    vector<Alimento> alimentos;
};


#endif //POOTP_RESERVA_H
