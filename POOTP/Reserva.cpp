#include "Reserva.h"

Reserva::Reserva(int nl, int nc): NL(nl), NC(nc) {}

Reserva::~Reserva() {}


void Reserva::AddAnimal(const Animal &a) {
    this->animais.push_back(a);
    cout << "Animal adicionado com sucesso!" << endl;
}

void Reserva::AddAlimento(const Alimento &a) {
    this->alimentos.push_back(a);
    cout << "Alimento adicionado com sucesso!" << endl;
}

void Reserva::eliminaAnimal(int num) {
    auto i = this->animais.begin();
    while(i != this->animais.end()){
        if(i->getId() == num)
            this->animais.erase(i);
        else
            ++i;
    }
}

void Reserva::eliminaAlimento(int num) {
    auto i = this->alimentos.begin();
    while(i != this->alimentos.end()){
        if(i->getId() == num)
            this->alimentos.erase(i);
        else
            ++i;
    }
}

string Reserva::getAsString() const {
    ostringstream buffer;
    if(animais.empty())
        buffer << "Sem animais!\n";
    else{
        auto i = this->animais.begin();
        while(i != this->animais.end()){
            buffer << i->getAsString();
            ++i;
        }
    }

    if(alimentos.empty())
        buffer << "Sem alimentos!\n";
    else{
        auto it = this->alimentos.begin();
        while(it != this->alimentos.end()){
            buffer << it->getAsString();
            ++it;
        }
    }

    return buffer.str();
}

int Reserva::newId() {
    return id++;
}

bool Reserva::procuraIdAnimal(int id) const {
    if(animais.empty())
        return false;
    else{
        auto i = this->animais.begin();
        while(i != this->animais.end()){
            if(i->getId() == id)
                return true;
            else
                ++i;
        }
    }
    return false;
}

bool Reserva::procuraIdAlimento(int id) const {
    if(alimentos.empty())
        return false;
    else{
        auto it = this->alimentos.begin();
        while(it != this->alimentos.end()){
            if(it->getId() == id)
                return true;
            else
                ++it;
        }
    }
    return false;
}

string Reserva::listAnimal(int id) const {
    auto it = this->animais.begin();
    while(it != this->animais.end()){
        if(it->getId() == id)
            return it->getAsString();
        else
            ++it;
    }
    return nullptr;
}

string Reserva::listAlimento(int id) const {
    auto it = this->alimentos.begin();
    while(it != this->alimentos.end()){
        if(it->getId() == id)
            return it->getAsString();
        else
            ++it;
    }
    return nullptr;
}

int Reserva::verificaLinhaColunaAnimal(int nl, int nc) const {
    auto it = this->animais.begin();
    while(it != this->animais.end()){
        if(it->getPosLinha() == nl && it->getPosColuna() == nc){

            return it->getId();
        }
        else
            ++it;
    }
    return 0;
}

int Reserva::verificaLinhaColunaAlimento(int nl, int nc) const {
    auto i = this->alimentos.begin();
    while(i != this->alimentos.end()){
        if(i->getPosLinha() == nl && i->getPosColuna() == nc){

            return i->getId();
        }
        else
            ++i;
    }
    return 0;
}

void Reserva::mataAnimal(int num) const {
    auto it = this->animais.begin();
    while(it != this->animais.end()){
        if(it->getId() == num){
            //MATAR ANIMAL -> EM FALTA!!!
            cout << "\nMORTO!";
            ++it;
        }
        else
            ++it;
    }
}

void Reserva::mataAnimal(int nl, int nc) const {
    auto it = this->animais.begin();
    while(it != this->animais.end()){
        if(it->getPosLinha() == nl && it->getPosColuna() == nc){
            //MATAR ANIMAL -> EM FALTA!!!
            cout << "\nMORTO!";
            ++it;
        }
        else
            ++it;
    }
}

bool Reserva::removeAlimento(int num) const {
    auto i = this->alimentos.begin();
    while(i != this->alimentos.end()){
        if(i->getId() == num){
            //MATAR Alimento -> EM FALTA!!!
            return true;
        }
        else
            ++i;
    }
    return false;
}

void Reserva::alimentaAnimal(int num, int nutri, int toxi) {
    auto it = this->animais.begin();
    while(it != this->animais.end()){
        if(it->getId() == num){
            //ALIMENTAR ANIMAL -> EM FALTA!!!
            cout << "\nALIMENTADO!";
            ++it;
        }
        else
            ++it;
    }
}

void Reserva::alimentaAnimal(int nl, int nc, int nutri, int toxi) {
    auto it = this->animais.begin();
    while(it != this->animais.end()){
        if(it->getPosLinha() == nl && it->getPosColuna() == nc){
            //ALIMENTAR ANIMAL -> EM FALTA!!!
            cout << "\nALIMENTADO!";
            ++it;
        }
        else
            ++it;
    }
}

void Reserva::listPosicao(int nl, int nc) const {
    auto it = this->animais.begin();
    while(it != this->animais.end()){
        if(it->getPosLinha() == nl && it->getPosColuna() == nc){
            cout << it->getAsString() << endl;
            ++it;
        }
        else
            ++it;
    }

    auto i = this->alimentos.begin();
    while(i != this->alimentos.end()){
        if(i->getPosLinha() == nl && i->getPosColuna() == nc){
            cout << i->getAsString() << endl;
            ++i;
        }
        else
            ++i;
    }
}

void Reserva::ComandoAnim() const {
    if(animais.empty())
        cout << "Sem animais!\n";
    else {
        auto it = this->animais.begin();
        while (it != this->animais.end()) {
            cout << "\nId: " << it->getId() << " Especie: " << it->getEspecie() << " Saude: " << it->getSaude();
            ++it;
        }
    }
}
