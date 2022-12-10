cmake_minimum_required(VERSION 3.20)
project(POOTP)

set(CMAKE_CXX_STANDARD 14)

add_executable(POOTP main.cpp Reserva.cpp Reserva.h Simulador.cpp Simulador.h Jogo.cpp Jogo.h Animal.cpp Animal.h Alimento.cpp Alimento.h Terminal.cpp Terminal.h curses.h)

target_link_libraries(${PROJECT_NAME} C:/PDCurses-3.9/wincon/pdcurses.a)