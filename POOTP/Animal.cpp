#include "Animal.h"

Animal::Animal(int m, int f, int s, char e, int l, int c, int id, int vinst): massa(m),fome(f),saude(s),especie(e),poslinha(l),poscoluna(c), idAnimal(id), vidainstantes(vinst){}

Animal::~Animal() {}

void Animal::aumentaFome() {
    fome++;
}

string Animal::getAsString() const {
    ostringstream os;
    os << "Animal:" << "Id-" << idAnimal << "|Especie-" << especie << "|M-" << massa << "|F-" << fome << "|S-" << saude << "|L-" << poslinha << "|C-" << poscoluna << "\n";
    return os.str();
}

void Animal::movimentoCoelho(int nl, int nc) {
    int direcao = rand() % 4+1;
    int distancia = rand() % 2+1;
    switch(direcao) {
        case 1:
            //Anda para cima
            if(this->getPosLinha() == 1){
                this->setPoslinha(nl-distancia+1);
            } else if(this->getPosLinha() - distancia < 1){
                this->setPoslinha(nl);
            } else {
                this->setPoslinha(this->getPosLinha()-distancia);
            }
            break;
        case 2:
            //Anda para a direita
            if(this->getPosColuna() == nc){
                this->setPoscoluna(distancia);
            } else if(this->getPosColuna()+distancia > nc){
                this->setPoscoluna(1);
            } else{
                this->setPoscoluna(this->getPosColuna()+distancia);
            }
            break;
        case 3:
            //Anda para baixo
            if(this->getPosLinha() == nl){
                this->setPoslinha(distancia);
            } else if(this->getPosLinha() + distancia > nl){
                this->setPoslinha(1);
            } else {
                this->setPoslinha(this->getPosLinha()+distancia);
            }
            break;
        case 4:
            //Anda para a esquerda
            if(this->getPosColuna() == 1){
                this->setPoscoluna(nc-distancia+1);
            } else if(this->getPosColuna()-distancia < 1){
                this->setPoscoluna(nc);
            } else{
                this->setPoscoluna(this->getPosColuna()-distancia);
            }
            break;
    }

}

void Animal::movimentoOvelha(int nl, int nc){
    int direcao = rand() % 4+1;
    int distancia = 1;
    switch(direcao) {
        case 1:
            //Anda para cima
            if(this->getPosLinha() == 1){
                this->setPoslinha(nl);
            } else{
                this->setPoslinha(this->getPosLinha()-distancia);
            }
            break;
        case 2:
            //Anda para a direita
            if(this->getPosColuna() == nc){
                this->setPoscoluna(distancia);
            } else{
                this->setPoscoluna(this->getPosColuna()+distancia);
            }
            break;
        case 3:
            //Anda para baixo
            if(this->getPosLinha() == nl){
                this->setPoslinha(distancia);
            } else{
                this->setPoslinha(this->getPosLinha()+distancia);
            }
            break;
        case 4:
            //Anda para a esquerda
            if(this->getPosColuna() == 1){
                this->setPoscoluna(nc);
            } else{
                this->setPoscoluna(this->getPosColuna()-distancia);
            }
            break;
    }
}

void Animal::movimentoLobo(int nl, int nc){
    int direcao = rand() % 4+1;
    int distancia = 1;
    switch(direcao) {
        case 1:
            //Anda para cima
            if(this->getPosLinha() == 1){
                this->setPoslinha(nl);
            } else{
                this->setPoslinha(this->getPosLinha()-distancia);
            }
            break;
        case 2:
            //Anda para a direita
            if(this->getPosColuna() == nc){
                this->setPoscoluna(distancia);
            } else{
                this->setPoscoluna(this->getPosColuna()+distancia);
            }
            break;
        case 3:
            //Anda para baixo
            if(this->getPosLinha() == nl){
                this->setPoslinha(distancia);
            } else{
                this->setPoslinha(this->getPosLinha()+distancia);
            }
            break;
        case 4:
            //Anda para a esquerda
            if(this->getPosColuna() == 1){
                this->setPoscoluna(nc);
            } else{
                this->setPoscoluna(this->getPosColuna()-distancia);
            }
            break;
    }
}

void Animal::movimentoCanguru(int nl, int nc) {
    int direcao = rand() % 4+1;
    int distancia = 1;
    switch(direcao) {
        case 1:
            //Anda para cima
            if(this->getPosLinha() == 1){
                this->setPoslinha(nl);
            } else{
                this->setPoslinha(this->getPosLinha()-distancia);
            }
            break;
        case 2:
            //Anda para a direita
            if(this->getPosColuna() == nc){
                this->setPoscoluna(distancia);
            } else{
                this->setPoscoluna(this->getPosColuna()+distancia);
            }
            break;
        case 3:
            //Anda para baixo
            if(this->getPosLinha() == nl){
                this->setPoslinha(distancia);
            } else{
                this->setPoslinha(this->getPosLinha()+distancia);
            }
            break;
        case 4:
            //Anda para a esquerda
            if(this->getPosColuna() == 1){
                this->setPoscoluna(nc);
            } else{
                this->setPoscoluna(this->getPosColuna()-distancia);
            }
            break;
    }
}
