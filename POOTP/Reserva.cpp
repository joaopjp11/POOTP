#include "Reserva.h"

Reserva::Reserva(int nl, int nc): NL(nl), NC(nc) {}

Reserva::Reserva(const Reserva &obj) {
    this->NL = obj.NL;
    this->NC = obj.NC;
    this->id = obj.id;

    auto it = obj.animais.begin();
    while (it < obj.animais.end()){
        this->AddAnimal(new Animal(**it));
        ++it;
    }

    auto i = obj.alimentos.begin();
    while (i < obj.alimentos.end()){
        this->AddAlimento(new Alimento(**i));
        ++i;
    }

}

Reserva::~Reserva() {}


void Reserva::AddAnimal(Animal *a) {
    animais.push_back(a);
}

void Reserva::AddAlimento(Alimento *a) {
    alimentos.push_back(a);
}

void Reserva::eliminaAnimal(int num) {
    auto i = this->animais.begin();
    while(i != this->animais.end()){
        if((*i)->getId() == num)
            this->animais.erase(i);
        else
            ++i;
    }
}

void Reserva::eliminaAlimento(int num) {
    auto i = this->alimentos.begin();
    while(i != this->alimentos.end()){
        if((*i)->getId() == num)
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
            buffer << (*i)->getAsString();
            ++i;
        }
    }

    if(alimentos.empty())
        buffer << "Sem alimentos!\n";
    else{
        auto it = this->alimentos.begin();
        while(it != this->alimentos.end()){
            buffer << (*it)->getAsString();
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
            if((*i)->getId() == id)
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
            if((*it)->getId() == id)
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
        if((*it)->getId() == id)
            return (*it)->getAsString();
        else
            ++it;
    }
    return nullptr;
}

string Reserva::listAlimento(int id) const {
    auto it = this->alimentos.begin();
    while(it != this->alimentos.end()){
        if((*it)->getId() == id)
            return (*it)->getAsString();
        else
            ++it;
    }
    return nullptr;
}

int Reserva::verificaLinhaColunaAnimal(int nl, int nc) const {
    auto it = this->animais.begin();
    while(it != this->animais.end()){
        if((*it)->getPosLinha() == nl && (*it)->getPosColuna() == nc){

            return (*it)->getId();
        }
        else
            ++it;
    }
    return 0;
}

int Reserva::verificaLinhaColunaAlimento(int nl, int nc) const {
    auto i = this->alimentos.begin();
    while(i != this->alimentos.end()){
        if((*i)->getPosLinha() == nl && (*i)->getPosColuna() == nc){

            return (*i)->getId();
        }
        else
            ++i;
    }
    return 0;
}

void Reserva::mataAnimal(int num){
    auto it = this->animais.begin();
    while(it != this->animais.end()){
        if((*it)->getId() == num){
            Alimento * tmp = new Corpo('p', 7, 0, 1000, (*it)->getPosLinha(), (*it)->getPosColuna(), newId());
            AddAlimento(tmp);
            this->animais.erase(it);
        }
        else
            ++it;
    }
}

void Reserva::mataAnimal(int nl, int nc) {
    auto it = this->animais.begin();
    while(it != this->animais.end()){
        if((*it)->getPosLinha() == nl && (*it)->getPosColuna() == nc){
            Alimento * tmp = new Corpo('p', 7, 0, 1000, nl, nc, newId());
            AddAlimento(tmp);
            this->animais.erase(it);
        }
        else
            ++it;
    }
}

bool Reserva::removeAlimento(int num) {
    auto i = this->alimentos.begin();
    while(i != this->alimentos.end()){
        if((*i)->getId() == num){
            this->alimentos.erase(i);
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
        if((*it)->getId() == num){
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
        if((*it)->getPosLinha() == nl && (*it)->getPosColuna() == nc){
            //ALIMENTAR ANIMAL -> EM FALTA!!!
            cout << "\nALIMENTADO!";
            ++it;
        }
        else
            ++it;
    }
}

string Reserva::listPosicao(int nl, int nc) const {
    ostringstream os;
    auto it = this->animais.begin();
    while(it != this->animais.end()){
        if((*it)->getPosLinha() == nl && (*it)->getPosColuna() == nc){
            os << (*it)->getAsString();
            ++it;
        }
        else
            ++it;
    }

    auto i = this->alimentos.begin();
    while(i != this->alimentos.end()){
        if((*i)->getPosLinha() == nl && (*i)->getPosColuna() == nc){
            os << (*i)->getAsString();
            ++i;
        }
        else
            ++i;
    }
    return os.str();
}

void Reserva::ComandoAnim() const {
    if(animais.empty())
        cout << "Sem animais!\n";
    else {
        auto it = this->animais.begin();
        while (it != this->animais.end()) {
            cout << "\nId: " << (*it)->getId() << " Especie: " << (*it)->getEspecie() << " Saude: " << (*it)->getSaude();
            ++it;
        }
    }
}

char Reserva::especieAnimal(int nl, int nc) const{
    auto it = this->animais.begin();
    while(it != this->animais.end()){
        if((*it)->getPosLinha() == nl && (*it)->getPosColuna() == nc){
            return (*it)->getEspecie();
        }
        else
            ++it;
    }
    return 0;
}

char Reserva::tipoAlimento(int nl, int nc) const {
    auto it = this->alimentos.begin();
    while(it != this->alimentos.end()){
        if((*it)->getPosLinha() == nl && (*it)->getPosColuna() == nc){

            return (*it)->getTipo();
        }
        else
            ++it;
    }
    return 0;
}

void Reserva::movimentaAnimais() {
    auto it = this->animais.begin();
    while(it != this->animais.end()){
        if((*it)->getEspecie() == 'c'){
            (*it)->movimentoCoelho(NL,NC);
            ++it;
        } else if((*it)->getEspecie() == 'o'){
            (*it)->movimentoOvelha(NL,NC);
            ++it;
        } else if((*it)->getEspecie() == 'l'){
            (*it)->movimentoLobo(NL,NC);
            ++it;
        } else if((*it)->getEspecie() == 'g'){
            (*it)->movimentoCanguru(NL,NC);
            ++it;
        }
        else
            ++it;
    }
}

void Reserva::AumentaFomeAnimais() {
    auto it = this->animais.begin();
    while(it != this->animais.end()){
        (*it)->aumentaFome();
        ++it;
    }
}

void Reserva::DiminuiDuracaoAlimentos() {
    auto it = this->alimentos.begin();
    while(it != this->alimentos.end()){
        (*it)->diminuiDuracao();
        if((*it)->getDuracao() == 0)
            alimentos.erase(it);
        else
            ++it;
    }
}

