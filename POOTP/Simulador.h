#ifndef POOTP_SIMULADOR_H
#define POOTP_SIMULADOR_H

#include "Terminal.h"
#include "Reserva.h"
#include "Jogo.h"
#include "Animal.h"
#include "Alimento.h"


#include <sstream>
#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>

using namespace std;
using namespace term;

class Simulador {
public:
    static void comecaSimulador();
    static void validaComando(Jogo &jogo, istringstream &recebe);
    static void mostraReservaInicial(Jogo &jogo);
    static bool leficheiro(Jogo &jogo,const string ficheiro);
    static bool config(Jogo &jogo,const string ficheiro);
};


#endif //POOTP_SIMULADOR_H
