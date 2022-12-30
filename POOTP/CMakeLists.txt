cmake_minimum_required(VERSION 3.20)
project(POOTP)

set(CMAKE_CXX_STANDARD 14)

add_executable(POOTP main.cpp Reserva.cpp Reserva.h Simulador.cpp Simulador.h Jogo.cpp Jogo.h Animal.cpp Animal.h Alimento.cpp Alimento.h Terminal.cpp Terminal.h curses.h Coelho.cpp Coelho.h Ovelha.cpp Ovelha.h Lobo.cpp Lobo.h Canguru.cpp Canguru.h Relva.cpp Relva.h Cenoura.cpp Cenoura.h Corpo.cpp Corpo.h Bife.cpp Bife.h Cavalo.cpp Cavalo.h Maca.cpp Maca.h Historico.cpp Historico.h)

target_link_libraries(${PROJECT_NAME} C:/PDCurses-3.9/wincon/pdcurses.a)