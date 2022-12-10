#include "Simulador.h"
#include "Reserva.h"
#include "Jogo.h"
#include "Animal.h"
#include "Alimento.h"
#include "Terminal.h"
#include "curses.h"

#include <sstream>
#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

int main() {
    Simulador::comecaSimulador();
    return 0;
}
