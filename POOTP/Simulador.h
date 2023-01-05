#ifndef POOTP_SIMULADOR_H
#define POOTP_SIMULADOR_H

#include "Terminal.h"
#include "Reserva.h"
#include "Jogo.h"
#include "Animal.h"
#include "Alimento.h"
#include "Coelho.h"
#include "Ovelha.h"
#include "Lobo.h"
#include "Canguru.h"
#include "Cavalo.h"
#include "Maca.h"
#include "Relva.h"
#include "Cenoura.h"
#include "Corpo.h"
#include "Bife.h"


#include <sstream>
#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <unistd.h>

using namespace std;
using namespace term;

class Simulador {
public:
    static void comecaSimulador(); //Cria a windows a mostrar na consola e é responsável pelo funcionamento da simulação
    static string validaComando(Jogo &jogo, Store &jogos, istringstream &recebe,Window &ViewReserva); //Valida os comandos introduzidos e executa as suas ações
    static void mostraReservaInicial(Jogo &jogo, Window &ViewReserva); //Mostra a reserva inicial (VAZIA)
    static void mostraReserva(Jogo &jogo, Window &ViewReserva); //Mostra a reserva ao longo da simulação
    static bool leficheiro(Jogo &jogo, Store &jogos, const string ficheiro,Window &ViewReserva); //Lê o ficheiro com comandos a executar
    static bool config(Jogo &jogo,const string ficheiro); //Lê o ficheiro das constantes (contantes.txt) - Este ficheiro é lido no inicio da simulação
};


#endif //POOTP_SIMULADOR_H
