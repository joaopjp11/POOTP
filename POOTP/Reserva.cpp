#include "Reserva.h"

Reserva::Reserva(int nl, int nc): NL(nl), NC(nc) {}

Reserva::Reserva(const Reserva &obj) {
    this->NL = obj.NL;
    this->NC = obj.NC;
    this->id = obj.id;
    this->SCoelho = obj.SCoelho;
    this->SCavalo = obj.SCavalo;
    this->SCanguru = obj.SCanguru;
    this->SOvelha = obj.SOvelha;
    this->SLobo = obj.SLobo;
    this->PCanguru = obj.PCanguru;
    this->PCavalo = obj.PCavalo;
    this->PLobo = obj.PLobo;
    this->VCoelho = obj.VCoelho;
    this->VCavalo = obj.VCavalo;
    this->VCanguru = obj.VCanguru;
    this->VLobo = obj.VLobo;
    this->VOvelha = obj.VOvelha;
    this->VRelva = obj.VRelva;
    this->VBife = obj.VBife;
    this->VMaca = obj.VMaca;

    auto b = this->animais.begin();
    while(b < this->animais.end()){
        this->animais.erase(b);
        ++b;
    }
    auto a = this->alimentos.begin();
    while(a < this->alimentos.end()){
        this->alimentos.erase(a);
        ++a;
    }

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

void Reserva::setConstantes(istringstream &recebe) {
    string var;
    int valor;
    recebe >> var;

    if(var == "SCoelho"){
        recebe >> valor;
        SCoelho = valor;
    }else if(var == "VCoelho"){
        recebe >> valor;
        VCoelho = valor;
    }else if(var == "SOvelha"){
        recebe >> valor;
        SOvelha = valor;
    }else if(var == "VOvelha"){
        recebe >> valor;
        VOvelha = valor;
    }else if(var == "SLobo"){
        recebe >> valor;
        SLobo = valor;
    }else if(var == "VLobo"){
        recebe >> valor;
        VLobo = valor;
    }else if(var == "PLobo"){
        recebe >> valor;
        PLobo = valor;
    }else if(var == "SCanguru"){
        recebe >> valor;
        SCanguru = valor;
    }else if(var == "VCanguru"){
        recebe >> valor;
        VCanguru = valor;
    }else if(var == "PCanguru"){
        recebe >> valor;
        PCanguru = valor;
    }else if(var == "SCavalo"){
        recebe >> valor;
        SCavalo = valor;
    }else if(var == "VCavalo"){
        recebe >> valor;
        VCavalo = valor;
    }else if(var == "PCavalo"){
        recebe >> valor;
        PCavalo = valor;
    }else if(var == "VRelva"){
        recebe >> valor;
        VRelva = valor;
    }else if(var == "VBife"){
        recebe >> valor;
        VBife = valor;
    }else if(var == "VMaca"){
        recebe >> valor;
        VMaca = valor;
    }
}


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
            if((*it)->getEspecie() == 'o'){
                Alimento * tmp = new Corpo('p', (*it)->getMassa(), 0, 9999, (*it)->getPosLinha(), (*it)->getPosColuna(), newId());
                AddAlimento(tmp);
            } else if((*it)->getEspecie() == 'l'){
                Alimento * tmp = new Corpo('p', 10, 0, 9999, (*it)->getPosLinha(), (*it)->getPosColuna(), newId());
                AddAlimento(tmp);
            } else if((*it)->getEspecie() == 'g'){
                Alimento * tmp = new Corpo('p', 15, 5, 9999, (*it)->getPosLinha(), (*it)->getPosColuna(), newId());
                AddAlimento(tmp);
            } else if((*it)->getEspecie() == 'M'){
                Alimento * tmp = new Corpo('p', (*it)->getMassa(), 0, 9999, (*it)->getPosLinha(), (*it)->getPosColuna(), newId());
                AddAlimento(tmp);
            }
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
            if((*it)->getEspecie() == 'o'){
                Alimento * tmp = new Corpo('p', (*it)->getMassa(), 0, 9999, (*it)->getPosLinha(), (*it)->getPosColuna(), newId());
                AddAlimento(tmp);
            } else if((*it)->getEspecie() == 'l'){
                Alimento * tmp = new Corpo('p', 10, 0, 9999, (*it)->getPosLinha(), (*it)->getPosColuna(), newId());
                AddAlimento(tmp);
            } else if((*it)->getEspecie() == 'g'){
                Alimento * tmp = new Corpo('p', 15, 5, 9999, (*it)->getPosLinha(), (*it)->getPosColuna(), newId());
                AddAlimento(tmp);
            } else if((*it)->getEspecie() == 'M'){
                Alimento * tmp = new Corpo('p', (*it)->getMassa(), 0, 9999, (*it)->getPosLinha(), (*it)->getPosColuna(), newId());
                AddAlimento(tmp);
            }
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

void Reserva::alimentaAnimal(int num, int nutri, int toxi, char t) {
    auto it = this->animais.begin();
    while(it != this->animais.end()){
        if((*it)->getId() == num){
            (*it)->aumentaSaude(nutri);
            (*it)->diminuiSaude(toxi);
            (*it)->diminuiFome(nutri);
            if(t == 'r'){
                (*it)->insertHist("relva", nutri, toxi);
            } else if(t == 't'){
                (*it)->insertHist("cenoura", nutri, toxi);
            } else if(t == 'b'){
                (*it)->insertHist("bife", nutri, toxi);
            } else if(t == 'p'){
                (*it)->insertHist("corpo", nutri, toxi);
            } else if(t == 'a'){
                (*it)->insertHist("maca", nutri, toxi);
            } else {
                (*it)->insertHist("user", nutri, toxi);
            }
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
            (*it)->aumentaSaude(nutri);
            (*it)->diminuiSaude(toxi);
            (*it)->diminuiFome(nutri);
            (*it)->insertHist("user",nutri,toxi);
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

string Reserva::ComandoAnim() const {
    ostringstream os;
    if(animais.empty())
        os << "Sem animais!\n";
    else {
        auto it = this->animais.begin();
        while (it != this->animais.end()) {
            os << "Id: " << (*it)->getId() << " Especie: " << (*it)->getEspecie() << " Saude: " << (*it)->getSaude() << "\n";
            ++it;
        }
    }
    return os.str();
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
    if(!animais.empty()) {
        auto it = this->animais.begin();
        while (it != this->animais.end()) {
            if ((*it)->getEspecie() == 'c') {
                int distancia = 0;
                int direcao = rand() % 4+1;

                if((*it)->getFome() < 10)
                    distancia = rand() % 2+1;
                else if((*it)->getFome() > 20)
                    distancia = rand() % 4+1;
                else
                    distancia = rand() % 3+1;

                for(int a = 1; a < 5; a++){
                    if(EncontraAnimalPesado((*it)->getId(),(*it)->getPosLinha()-a, (*it)->getPosColuna(), 10)){
                        direcao = 3; //Ia para cima agora vai para baixo
                    } else if(EncontraAnimalPesado((*it)->getId(),(*it)->getPosLinha()+a, (*it)->getPosColuna(), 10)){
                        direcao = 1; //Ia para baixo agora vai para cima
                    } else if(EncontraAnimalPesado((*it)->getId(),(*it)->getPosLinha(), (*it)->getPosColuna()-a, 10)){
                        direcao = 2; //Ia para a esquerda agora vai para a direita
                    } else if(EncontraAnimalPesado((*it)->getId(),(*it)->getPosLinha(), (*it)->getPosColuna()+a, 10)){
                        direcao = 4; //Ia para a direita agora vai para a esquerda
                    }
                }

                switch(direcao) {
                    case 1:
                        //Anda para cima
                        if((*it)->getPosLinha() - distancia < 1){
                            (*it)->setPoslinha(NL + (*it)->getPosLinha() - distancia);
                        } else {
                            (*it)->setPoslinha((*it)->getPosLinha()-distancia);
                        }
                        break;
                    case 2:
                        //Anda para a direita
                        if((*it)->getPosColuna()+distancia > NC){
                            (*it)->setPoscoluna((*it)->getPosColuna() + distancia - NC);
                        } else{
                            (*it)->setPoscoluna((*it)->getPosColuna()+distancia);
                        }
                        break;
                    case 3:
                        //Anda para baixo
                        if((*it)->getPosLinha() + distancia > NL){
                            (*it)->setPoslinha((*it)->getPosLinha() + distancia - NL);
                        } else {
                            (*it)->setPoslinha((*it)->getPosLinha()+distancia);
                        }
                        break;
                    case 4:
                        //Anda para a esquerda
                        if((*it)->getPosColuna()-distancia < 1){
                            (*it)->setPoscoluna(NC + (*it)->getPosColuna() - distancia);
                        } else{
                            (*it)->setPoscoluna((*it)->getPosColuna()-distancia);
                        }
                        break;
                }

                auto i = alimentos.begin();
                while (i < alimentos.end()){
                    if((*i)->getPosLinha() == (*it)->getPosLinha() && (*i)->getPosColuna() == (*it)->getPosColuna()){
                        string cheiro;
                        istringstream iss((*i)->getCheiro());
                        while (!iss.eof()){
                            cheiro.clear();
                            iss >> cheiro;
                            if(cheiro == "verdura"){
                                alimentaAnimal((*it)->getId(),(*i)->getNutricao(),(*i)->getToxicidade(), (*i)->getTipo());
                                alimentos.erase(i);
                            }
                        }
                    }
                    ++i;
                }

                ++it;
            } else if ((*it)->getEspecie() == 'o') {

                int direcao = rand() % 4+1;
                int distancia = 0;
                if((*it)->getFome() <= 15)
                    distancia = 1;
                else
                    distancia = rand() % 2+1;

                for(int a = 1; a < 4; a++){
                    if(EncontraAnimalPesado((*it)->getId(),(*it)->getPosLinha()-a, (*it)->getPosColuna(), 15)){
                        direcao = 3; //Ia para cima agora vai para baixo
                    } else if(EncontraAnimalPesado((*it)->getId(),(*it)->getPosLinha()+a, (*it)->getPosColuna(), 15)){
                        direcao = 1; //Ia para baixo agora vai para cima
                    } else if(EncontraAnimalPesado((*it)->getId(),(*it)->getPosLinha(), (*it)->getPosColuna()-a, 15)){
                        direcao = 2; //Ia para a esquerda agora vai para a direita
                    } else if(EncontraAnimalPesado((*it)->getId(),(*it)->getPosLinha(), (*it)->getPosColuna()+a, 15)){
                        direcao = 4; //Ia para a direita agora vai para a esquerda
                    }
                }

                switch(direcao) {
                    case 1:
                        //Anda para cima
                        if((*it)->getPosLinha() - distancia < 1){
                            (*it)->setPoslinha(NL + (*it)->getPosLinha() - distancia);
                        } else {
                            (*it)->setPoslinha((*it)->getPosLinha()-distancia);
                        }
                        break;
                    case 2:
                        //Anda para a direita
                        if((*it)->getPosColuna()+distancia > NC){
                            (*it)->setPoscoluna((*it)->getPosColuna() + distancia - NC);
                        } else{
                            (*it)->setPoscoluna((*it)->getPosColuna()+distancia);
                        }
                        break;
                    case 3:
                        //Anda para baixo
                        if((*it)->getPosLinha() + distancia > NL){
                            (*it)->setPoslinha((*it)->getPosLinha() + distancia - NL);
                        } else {
                            (*it)->setPoslinha((*it)->getPosLinha()+distancia);
                        }
                        break;
                    case 4:
                        //Anda para a esquerda
                        if((*it)->getPosColuna()-distancia < 1){
                            (*it)->setPoscoluna(NC + (*it)->getPosColuna() - distancia);
                        } else{
                            (*it)->setPoscoluna((*it)->getPosColuna()-distancia);
                        }
                        break;
                }

                auto i = alimentos.begin();
                while (i < alimentos.end()){
                    if((*i)->getPosLinha() == (*it)->getPosLinha() && (*i)->getPosColuna() == (*it)->getPosColuna()){
                        string cheiro;
                        istringstream iss((*i)->getCheiro());
                        while (!iss.eof()){
                            cheiro.clear();
                            iss >> cheiro;
                            if(cheiro == "erva"){
                                alimentaAnimal((*it)->getId(),(*i)->getNutricao(),(*i)->getToxicidade(), (*i)->getTipo());
                                alimentos.erase(i);
                            }
                        }
                    }
                    ++i;
                }

                ++it;
            } else if ((*it)->getEspecie() == 'l') {

                int direcao = rand() % 4+1;
                int distancia = 1;

                if((*it)->getFome() <= 15)
                    distancia = 1;
                else
                    distancia = 2;

                switch(direcao) {
                    case 1:
                        //Anda para cima
                        if((*it)->getPosLinha() - distancia < 1){
                            (*it)->setPoslinha(NL + (*it)->getPosLinha() - distancia);
                        } else {
                            (*it)->setPoslinha((*it)->getPosLinha()-distancia);
                        }
                        break;
                    case 2:
                        //Anda para a direita
                        if((*it)->getPosColuna()+distancia > NC){
                            (*it)->setPoscoluna((*it)->getPosColuna() + distancia - NC);
                        } else{
                            (*it)->setPoscoluna((*it)->getPosColuna()+distancia);
                        }
                        break;
                    case 3:
                        //Anda para baixo
                        if((*it)->getPosLinha() + distancia > NL){
                            (*it)->setPoslinha((*it)->getPosLinha() + distancia - NL);
                        } else {
                            (*it)->setPoslinha((*it)->getPosLinha()+distancia);
                        }
                        break;
                    case 4:
                        //Anda para a esquerda
                        if((*it)->getPosColuna()-distancia < 1){
                            (*it)->setPoscoluna(NC + (*it)->getPosColuna() - distancia);
                        } else{
                            (*it)->setPoscoluna((*it)->getPosColuna()-distancia);
                        }
                        break;
                }

                auto i = alimentos.begin();
                while (i < alimentos.end()){
                    if((*i)->getPosLinha() == (*it)->getPosLinha() && (*i)->getPosColuna() == (*it)->getPosColuna()){
                        string cheiro;
                        istringstream iss((*i)->getCheiro());
                        while (!iss.eof()){
                            cheiro.clear();
                            iss >> cheiro;
                            if(cheiro == "carne"){
                                alimentaAnimal((*it)->getId(),(*i)->getNutricao(),(*i)->getToxicidade(), (*i)->getTipo());
                                alimentos.erase(i);
                            }
                        }
                    }
                    ++i;
                }

                auto it2 = animais.begin();
                while (it2 < animais.end()){
                    if((*it2)->getPosLinha() == (*it)->getPosLinha() && (*it2)->getPosColuna() == (*it)->getPosColuna() && (*it2)->getId() != (*it)->getId()){
                        if((*it2)->getMassa() < (*it)->getMassa()){
                            mataAnimal((*it2)->getId());
                        } else{
                            int morrer = rand() % 2+1;
                            if(morrer == 1){
                                mataAnimal((*it)->getId());
                            } else if(morrer == 2){
                                mataAnimal((*it2)->getId());
                            }
                        }
                    }
                    ++it2;
                }

                ++it;
            } else if ((*it)->getEspecie() == 'g') {

                int direcao = rand() % 4+1;
                int distancia = 1;
                switch(direcao) {
                    case 1:
                        //Anda para cima
                        if((*it)->getPosLinha() == 1){
                            (*it)->setPoslinha(NL);
                        } else{
                            (*it)->setPoslinha((*it)->getPosLinha()-distancia);
                        }
                        break;
                    case 2:
                        //Anda para a direita
                        if((*it)->getPosColuna() == NC){
                            (*it)->setPoscoluna(distancia);
                        } else{
                            (*it)->setPoscoluna((*it)->getPosColuna()+distancia);
                        }
                        break;
                    case 3:
                        //Anda para baixo
                        if((*it)->getPosLinha() == NL){
                            (*it)->setPoslinha(distancia);
                        } else{
                            (*it)->setPoslinha((*it)->getPosLinha()+distancia);
                        }
                        break;
                    case 4:
                        //Anda para a esquerda
                        if((*it)->getPosColuna() == 1){
                            (*it)->setPoscoluna(NC);
                        } else{
                            (*it)->setPoscoluna((*it)->getPosColuna()-distancia);
                        }
                        break;
                }
                ++it;
            } else if ((*it)->getEspecie() == 'M'){
                int direcao = rand() % 4+1;
                int distancia = 1;
                switch(direcao) {
                    case 1:
                        //Anda para cima
                        if((*it)->getPosLinha() == 1){
                            (*it)->setPoslinha(NL);
                        } else{
                            (*it)->setPoslinha((*it)->getPosLinha()-distancia);
                        }
                        break;
                    case 2:
                        //Anda para a direita
                        if((*it)->getPosColuna() == NC){
                            (*it)->setPoscoluna(distancia);
                        } else{
                            (*it)->setPoscoluna((*it)->getPosColuna()+distancia);
                        }
                        break;
                    case 3:
                        //Anda para baixo
                        if((*it)->getPosLinha() == NL){
                            (*it)->setPoslinha(distancia);
                        } else{
                            (*it)->setPoslinha((*it)->getPosLinha()+distancia);
                        }
                        break;
                    case 4:
                        //Anda para a esquerda
                        if((*it)->getPosColuna() == 1){
                            (*it)->setPoscoluna(NC);
                        } else{
                            (*it)->setPoscoluna((*it)->getPosColuna()-distancia);
                        }
                        break;
                }

                auto i = alimentos.begin();
                while (i < alimentos.end()){
                    if((*i)->getPosLinha() == (*it)->getPosLinha() && (*i)->getPosColuna() == (*it)->getPosColuna()){
                        string cheiro;
                        istringstream iss((*i)->getCheiro());
                        while (!iss.eof()){
                            cheiro.clear();
                            iss >> cheiro;
                            if(cheiro == "fruta"){
                                alimentaAnimal((*it)->getId(),(*i)->getNutricao(),(*i)->getToxicidade(), (*i)->getTipo());
                                alimentos.erase(i);
                            }
                        }
                    }
                    ++i;
                }
                ++it;
            }
        }
    }
}

void Reserva::AumentaFomeAnimais() {
    if(!animais.empty()) {
        auto it = this->animais.begin();
        while (it != this->animais.end()) {
            (*it)->aumentaFome();
            ++it;
        }
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

void Reserva::DiminuiVinstantes() {
    if(!animais.empty()) {
        auto it = this->animais.begin();
        while (it != this->animais.end()) {
            if ((*it)->getEspecie() == 'c') {
                (*it)->diminuiinstantes();
                if ((*it)->getVidaInstantes() == 0) {
                    animais.erase(it);
                } else{
                    ++it;
                }
            } else if ((*it)->getEspecie() == 'o') {
                (*it)->diminuiinstantes();
                if ((*it)->getVidaInstantes() == 0) {
                    Alimento * tmp = new Corpo('p', (*it)->getMassa(), 0, 9999, (*it)->getPosLinha(), (*it)->getPosColuna(), newId());
                    AddAlimento(tmp);
                    animais.erase(it);
                } else{
                    ++it;
                }
            } else if ((*it)->getEspecie() == 'g') {
                (*it)->diminuiinstantes();
                if ((*it)->getVidaInstantes() == 0) {
                    Alimento * tmp = new Corpo('p', 15, 5, 9999, (*it)->getPosLinha(), (*it)->getPosColuna(), newId());
                    AddAlimento(tmp);
                    animais.erase(it);
                } else{
                    ++it;
                }
            } else if ((*it)->getEspecie() == 'M') {
                (*it)->diminuiinstantes();
                if ((*it)->getVidaInstantes() == 0) {
                    Alimento * tmp = new Corpo('p', (*it)->getMassa(), 0, 9999, (*it)->getPosLinha(), (*it)->getPosColuna(), newId());
                    AddAlimento(tmp);
                    animais.erase(it);
                } else{
                    ++it;
                }
            } else {
                ++it;
            }
        }
    }
}

void Reserva::AumentaInstantesDecorridosAnimal() {
    auto it = this->animais.begin();
    while(it != this->animais.end()){
        (*it)->aumentaInstantesDecorridos();
        if((*it)->getEspecie()=='g' && (*it)->getInstantesDecorridos() == 20)
            (*it)->setMassa(20);
        ++it;
    }
}

void Reserva::verificaSaude() {
    if(!animais.empty()) {
        auto it = this->animais.begin();
        while (it != this->animais.end()) {
            if ((*it)->getEspecie() == 'c') {
                if ((*it)->getSaude() <= 0) {
                    animais.erase(it);
                } else{
                    ++it;
                }
            } else if ((*it)->getEspecie() == 'o') {
                if ((*it)->getSaude() <= 0) {
                    Alimento * tmp = new Corpo('p', (*it)->getMassa(), 0, 9999, (*it)->getPosLinha(), (*it)->getPosColuna(), newId());
                    AddAlimento(tmp);
                    animais.erase(it);
                } else{
                    ++it;
                }
            } else if ((*it)->getEspecie() == 'l') {
                if ((*it)->getSaude() <= 0) {
                    Alimento * tmp = new Corpo('p', 10, 0, 9999, (*it)->getPosLinha(), (*it)->getPosColuna(), newId());
                    AddAlimento(tmp);
                    animais.erase(it);
                } else{
                    ++it;
                }
            } else if ((*it)->getEspecie() == 'g') {
                if ((*it)->getSaude() <= 0) {
                    Alimento * tmp = new Corpo('p', 15, 5, 9999, (*it)->getPosLinha(), (*it)->getPosColuna(), newId());
                    AddAlimento(tmp);
                    animais.erase(it);
                } else{
                    ++it;
                }
            }else if ((*it)->getEspecie() == 'M') {
                if ((*it)->getSaude() <= 0) {
                    Alimento * tmp = new Corpo('p', (*it)->getMassa(), 0, 9999, (*it)->getPosLinha(), (*it)->getPosColuna(), newId());
                    AddAlimento(tmp);
                    animais.erase(it);
                } else{
                    ++it;
                }
            }
        }
    }
}

void Reserva::updateNutriToxiAlimentos() {
    auto it = this->alimentos.begin();
    while(it != this->alimentos.end()){
        if((*it)->getTipo() != 'r'){
            (*it)->AtualizaNutriToxi();
            ++it;
        } else {
            ++it;
        }
    }
}

string Reserva::printHistAlimentacaoAnimal(int num) const {
    ostringstream os;
    auto it = this->animais.begin();
    while(it != this->animais.end()){
        if((*it)->getId() == num){
            return (*it)->printList();
        }
        else
            ++it;
    }
    return nullptr;
}

bool Reserva::verificaOcupacaoEspaco(int nl, int nc) {
    int conta = 0;
    auto it = this->animais.begin();
    while(it != this->animais.end()){
        if((*it)->getPosLinha() == nl && (*it)->getPosColuna() == nc){
            conta++;
            ++it;
        }
        else
            ++it;
    }

    if(conta >= 2)
        return false;
    else
        return true;
}

bool Reserva::verificaOcupacaoEspacoAlimento(int nl, int nc) {
    int conta = 0;
    auto it = this->alimentos.begin();
    while(it != this->alimentos.end()){
        if((*it)->getPosLinha() == nl && (*it)->getPosColuna() == nc){
            conta++;
            ++it;
        }
        else
            ++it;
    }

    if(conta >= 1)
        return false;
    else
        return true;
}

void Reserva::FazNascer() {

    std::vector<Animal*>::size_type size = animais.size();
    for (std::vector<Animal*>::size_type i = 0; i < size; ++i){
        if(animais[i]->getEspecie() == 'c'){
            if(animais[i]->getInstantesDecorridos() == 8 || animais[i]->getInstantesDecorridos() == 16 || animais[i]->getInstantesDecorridos() == 24){
                int probabilidade = rand() % 2+1;
                if(probabilidade == 1){
                    int direcao = rand() % 4+1;
                    int distancia = rand() % 10+1;
                    int massa = rand() % 4+1;
                    switch(direcao) {
                        case 1:
                            //Anda para cima
                            if(animais[i]->getPosLinha() == 1){
                                while (!verificaOcupacaoEspaco(NL - distancia + 1,animais[i]->getPosColuna())){
                                    distancia = rand() % 10+1;
                                }
                                Animal *tmp = new Coelho(massa, 0, getSCoelho(), 'c', NL - distancia + 1, animais[i]->getPosColuna(), newId(), getVCoelho());
                                AddAnimal(tmp);
                            } else if(animais[i]->getPosLinha() - distancia < 1){
                                while (!verificaOcupacaoEspaco(NL-(animais[i]->getPosLinha() - distancia),animais[i]->getPosColuna())){
                                    distancia = rand() % 10+1;
                                }
                                Animal * tmp = new Coelho(massa,0,getSCoelho(),'c',NL-(animais[i]->getPosLinha() - distancia),animais[i]->getPosColuna(),newId(),getVCoelho());
                                AddAnimal(tmp);
                            } else {
                                while (!verificaOcupacaoEspaco(animais[i]->getPosLinha()-distancia,animais[i]->getPosColuna())){
                                    distancia = rand() % 10+1;
                                }
                                Animal * tmp = new Coelho(massa,0,getSCoelho(),'c',animais[i]->getPosLinha()-distancia,animais[i]->getPosColuna(),newId(),getVCoelho());
                                AddAnimal(tmp);
                            }
                            break;
                        case 2:
                            //Anda para a direita
                            if(animais[i]->getPosColuna() == NC){
                                while (!verificaOcupacaoEspaco(animais[i]->getPosLinha(),distancia)){
                                    distancia = rand() % 10+1;
                                }
                                Animal * tmp = new Coelho(massa,0,getSCoelho(),'c',animais[i]->getPosLinha(),distancia,newId(),getVCoelho());
                                AddAnimal(tmp);
                            } else if(animais[i]->getPosColuna()+distancia > NC){
                                while (!verificaOcupacaoEspaco(animais[i]->getPosLinha(),distancia-(NC-animais[i]->getPosColuna()))){
                                    distancia = rand() % 10+1;
                                }
                                Animal * tmp = new Coelho(massa,0,getSCoelho(),'c',animais[i]->getPosLinha(),distancia-(NC-animais[i]->getPosColuna()),newId(),getVCoelho());
                                AddAnimal(tmp);
                            } else{
                                while (!verificaOcupacaoEspaco(animais[i]->getPosLinha(),animais[i]->getPosColuna()+distancia)){
                                    distancia = rand() % 10+1;
                                }
                                Animal * tmp = new Coelho(massa,0,getSCoelho(),'c',animais[i]->getPosLinha(),animais[i]->getPosColuna()+distancia,newId(),getVCoelho());
                                AddAnimal(tmp);
                            }
                            break;
                        case 3:
                            //Anda para baixo
                            if(animais[i]->getPosLinha() == NL){
                                while (!verificaOcupacaoEspaco(distancia,animais[i]->getPosColuna())){
                                    distancia = rand() % 10+1;
                                }
                                Animal * tmp = new Coelho(massa,0,getSCoelho(),'c',distancia,animais[i]->getPosColuna(),newId(),getVCoelho());
                                AddAnimal(tmp);
                            } else if(animais[i]->getPosLinha() + distancia > NL){
                                while (!verificaOcupacaoEspaco(distancia-(NL-animais[i]->getPosLinha()),animais[i]->getPosColuna())){
                                    distancia = rand() % 10+1;
                                }
                                Animal * tmp = new Coelho(massa,0,getSCoelho(),'c',distancia-(NL-animais[i]->getPosLinha()),animais[i]->getPosColuna(),newId(),getVCoelho());
                                AddAnimal(tmp);
                            } else {
                                while (!verificaOcupacaoEspaco(animais[i]->getPosLinha()+distancia,animais[i]->getPosColuna())){
                                    distancia = rand() % 10+1;
                                }
                                Animal * tmp = new Coelho(massa,0,getSCoelho(),'c',animais[i]->getPosLinha()+distancia,animais[i]->getPosColuna(),newId(),getVCoelho());
                                AddAnimal(tmp);
                            }
                            break;
                        case 4:
                            //Anda para a esquerda
                            if(animais[i]->getPosColuna() == 1){
                                while (!verificaOcupacaoEspaco(animais[i]->getPosLinha(),NC-distancia+1)){
                                    distancia = rand() % 10+1;
                                }
                                Animal * tmp = new Coelho(massa,0,getSCoelho(),'c',animais[i]->getPosLinha(),NC-distancia+1,newId(),getVCoelho());
                                AddAnimal(tmp);
                            } else if(animais[i]->getPosColuna()-distancia < 1){
                                while (!verificaOcupacaoEspaco(animais[i]->getPosLinha(),NC+animais[i]->getPosColuna()-distancia)){
                                    distancia = rand() % 10+1;
                                }
                                Animal * tmp = new Coelho(massa,0,getSCoelho(),'c',animais[i]->getPosLinha(),NC+animais[i]->getPosColuna()-distancia,newId(),getVCoelho());
                                AddAnimal(tmp);
                            } else{
                                while (!verificaOcupacaoEspaco(animais[i]->getPosLinha(),animais[i]->getPosColuna()-distancia)){
                                    distancia = rand() % 10+1;
                                }
                                Animal * tmp = new Coelho(massa,0,getSCoelho(),'c',animais[i]->getPosLinha(),animais[i]->getPosColuna()-distancia,newId(),getVCoelho());
                                AddAnimal(tmp);
                            }
                            break;
                    }
                }
            }
        }else if(animais[i]->getEspecie() == 'o'){
            if(animais[i]->getInstantesDecorridos() == 15 || animais[i]->getInstantesDecorridos() == 30){
                    int direcao = rand() % 4+1;
                    int distancia = rand() % 12+1;
                    int massa = rand() % 5 + 4;
                    switch(direcao) {
                        case 1:
                            //Anda para cima
                            if(animais[i]->getPosLinha() == 1){
                                while (!verificaOcupacaoEspaco(NL - distancia + 1,animais[i]->getPosColuna())){
                                    distancia = rand() % 12+1;
                                }
                                Animal *tmp = new Ovelha(massa, 0,animais[i]->getSaude(), 'o', NL - distancia + 1, animais[i]->getPosColuna(), newId(), getVOvelha());
                                AddAnimal(tmp);
                            } else if(animais[i]->getPosLinha() - distancia < 1){
                                while (!verificaOcupacaoEspaco(NL-(animais[i]->getPosLinha() - distancia),animais[i]->getPosColuna())){
                                    distancia = rand() % 12+1;
                                }
                                Animal * tmp = new Ovelha(massa,0,animais[i]->getSaude(),'o',NL-(animais[i]->getPosLinha() - distancia),animais[i]->getPosColuna(),newId(),getVOvelha());
                                AddAnimal(tmp);
                            } else {
                                while (!verificaOcupacaoEspaco(animais[i]->getPosLinha()-distancia,animais[i]->getPosColuna())){
                                    distancia = rand() % 12+1;
                                }
                                Animal * tmp = new Ovelha(massa,0,animais[i]->getSaude(),'o',animais[i]->getPosLinha()-distancia,animais[i]->getPosColuna(),newId(),getVOvelha());
                                AddAnimal(tmp);
                            }
                            break;
                        case 2:
                            //Anda para a direita
                            if(animais[i]->getPosColuna() == NC){
                                while (!verificaOcupacaoEspaco(animais[i]->getPosLinha(),distancia)){
                                    distancia = rand() % 12+1;
                                }
                                Animal * tmp = new Ovelha(massa,0,animais[i]->getSaude(),'o',animais[i]->getPosLinha(),distancia,newId(),getVOvelha());
                                AddAnimal(tmp);
                            } else if(animais[i]->getPosColuna()+distancia > NC){
                                while (!verificaOcupacaoEspaco(animais[i]->getPosLinha(),distancia-(NC-animais[i]->getPosColuna()))){
                                    distancia = rand() % 12+1;
                                }
                                Animal * tmp = new Ovelha(massa,0,animais[i]->getSaude(),'o',animais[i]->getPosLinha(),distancia-(NC-animais[i]->getPosColuna()),newId(),getVOvelha());
                                AddAnimal(tmp);
                            } else{
                                while (!verificaOcupacaoEspaco(animais[i]->getPosLinha(),animais[i]->getPosColuna()+distancia)){
                                    distancia = rand() % 12+1;
                                }
                                Animal * tmp = new Ovelha(massa,0,animais[i]->getSaude(),'o',animais[i]->getPosLinha(),animais[i]->getPosColuna()+distancia,newId(),getVOvelha());
                                AddAnimal(tmp);
                            }
                            break;
                        case 3:
                            //Anda para baixo
                            if(animais[i]->getPosLinha() == NL){
                                while (!verificaOcupacaoEspaco(distancia,animais[i]->getPosColuna())){
                                    distancia = rand() % 12+1;
                                }
                                Animal * tmp = new Ovelha(massa,0,animais[i]->getSaude(),'o',distancia,animais[i]->getPosColuna(),newId(),getVOvelha());
                                AddAnimal(tmp);
                            } else if(animais[i]->getPosLinha() + distancia > NL){
                                while (!verificaOcupacaoEspaco(distancia-(NL-animais[i]->getPosLinha()),animais[i]->getPosColuna())){
                                    distancia = rand() % 12+1;
                                }
                                Animal * tmp = new Ovelha(massa,0,animais[i]->getSaude(),'o',distancia-(NL-animais[i]->getPosLinha()),animais[i]->getPosColuna(),newId(),getVOvelha());
                                AddAnimal(tmp);
                            } else {
                                while (!verificaOcupacaoEspaco(animais[i]->getPosLinha()+distancia,animais[i]->getPosColuna())){
                                    distancia = rand() % 12+1;
                                }
                                Animal * tmp = new Ovelha(massa,0,animais[i]->getSaude(),'o',animais[i]->getPosLinha()+distancia,animais[i]->getPosColuna(),newId(),getVOvelha());
                                AddAnimal(tmp);
                            }
                            break;
                        case 4:
                            //Anda para a esquerda
                            if(animais[i]->getPosColuna() == 1){
                                while (!verificaOcupacaoEspaco(animais[i]->getPosLinha(),NC-distancia+1)){
                                    distancia = rand() % 12+1;
                                }
                                Animal * tmp = new Ovelha(massa,0,animais[i]->getSaude(),'o',animais[i]->getPosLinha(),NC-distancia+1,newId(),getVOvelha());
                                AddAnimal(tmp);
                            } else if(animais[i]->getPosColuna()-distancia < 1){
                                while (!verificaOcupacaoEspaco(animais[i]->getPosLinha(),NC+animais[i]->getPosColuna()-distancia)){
                                    distancia = rand() % 12+1;
                                }
                                Animal * tmp = new Ovelha(massa,0,animais[i]->getSaude(),'o',animais[i]->getPosLinha(),NC+animais[i]->getPosColuna()-distancia,newId(),getVOvelha());
                                AddAnimal(tmp);
                            } else{
                                while (!verificaOcupacaoEspaco(animais[i]->getPosLinha(),animais[i]->getPosColuna()-distancia)){
                                    distancia = rand() % 12+1;
                                }
                                Animal * tmp = new Ovelha(massa,0,animais[i]->getSaude(),'o',animais[i]->getPosLinha(),animais[i]->getPosColuna()-distancia,newId(),getVOvelha());
                                AddAnimal(tmp);
                            }
                            break;
                    }
            }
        }else if(animais[i]->getEspecie() == 'l'){
            if(animais[i]->getInstantesDecorridos() == 25){
                int direcao = rand() % 4+1;
                int distancia = rand() % 15+1;
                switch(direcao) {
                    case 1:
                        //Anda para cima
                        if(animais[i]->getPosLinha() == 1){
                            while (!verificaOcupacaoEspaco(NL - distancia + 1,animais[i]->getPosColuna())){
                                distancia = rand() % 15+1;
                            }
                            Animal *tmp = new Lobo(getPLobo(), 0,getSLobo(), 'l', NL - distancia + 1, animais[i]->getPosColuna(), newId(), getSLobo());
                            AddAnimal(tmp);
                        } else if(animais[i]->getPosLinha() - distancia < 1){
                            while (!verificaOcupacaoEspaco(NL-(animais[i]->getPosLinha() - distancia),animais[i]->getPosColuna())){
                                distancia = rand() % 15+1;
                            }
                            Animal * tmp = new Lobo(getPLobo(),0,getSLobo(),'l',NL-(animais[i]->getPosLinha() - distancia),animais[i]->getPosColuna(),newId(),getSLobo());
                            AddAnimal(tmp);
                        } else {
                            while (!verificaOcupacaoEspaco(animais[i]->getPosLinha()-distancia,animais[i]->getPosColuna())){
                                distancia = rand() % 15+1;
                            }
                            Animal * tmp = new Lobo(getPLobo(),0,getSLobo(),'l',animais[i]->getPosLinha()-distancia,animais[i]->getPosColuna(),newId(),getSLobo());
                            AddAnimal(tmp);
                        }
                        break;
                    case 2:
                        //Anda para a direita
                        if(animais[i]->getPosColuna() == NC){
                            while (!verificaOcupacaoEspaco(animais[i]->getPosLinha(),distancia)){
                                distancia = rand() % 15+1;
                            }
                            Animal * tmp = new Lobo(getPLobo(),0,getSLobo(),'l',animais[i]->getPosLinha(),distancia,newId(),getSLobo());
                            AddAnimal(tmp);
                        } else if(animais[i]->getPosColuna()+distancia > NC){
                            while (!verificaOcupacaoEspaco(animais[i]->getPosLinha(),distancia-(NC-animais[i]->getPosColuna()))){
                                distancia = rand() % 15+1;
                            }
                            Animal * tmp = new Lobo(getPLobo(),0,getSLobo(),'l',animais[i]->getPosLinha(),distancia-(NC-animais[i]->getPosColuna()),newId(),getSLobo());
                            AddAnimal(tmp);
                        } else{
                            while (!verificaOcupacaoEspaco(animais[i]->getPosLinha(),animais[i]->getPosColuna()+distancia)){
                                distancia = rand() % 15+1;
                            }
                            Animal * tmp = new Lobo(getPLobo(),0,getSLobo(),'l',animais[i]->getPosLinha(),animais[i]->getPosColuna()+distancia,newId(),getSLobo());
                            AddAnimal(tmp);
                        }
                        break;
                    case 3:
                        //Anda para baixo
                        if(animais[i]->getPosLinha() == NL){
                            while (!verificaOcupacaoEspaco(distancia,animais[i]->getPosColuna())){
                                distancia = rand() % 15+1;
                            }
                            Animal * tmp = new Lobo(getPLobo(),0,getSLobo(),'l',distancia,animais[i]->getPosColuna(),newId(),getSLobo());
                            AddAnimal(tmp);
                        } else if(animais[i]->getPosLinha() + distancia > NL){
                            while (!verificaOcupacaoEspaco(distancia-(NL-animais[i]->getPosLinha()),animais[i]->getPosColuna())){
                                distancia = rand() % 15+1;
                            }
                            Animal * tmp = new Lobo(getPLobo(),0,getSLobo(),'l',distancia-(NL-animais[i]->getPosLinha()),animais[i]->getPosColuna(),newId(),getSLobo());
                            AddAnimal(tmp);
                        } else {
                            while (!verificaOcupacaoEspaco(animais[i]->getPosLinha()+distancia,animais[i]->getPosColuna())){
                                distancia = rand() % 15+1;
                            }
                            Animal * tmp = new Lobo(getPLobo(),0,getSLobo(),'l',animais[i]->getPosLinha()+distancia,animais[i]->getPosColuna(),newId(),getSLobo());
                            AddAnimal(tmp);
                        }
                        break;
                    case 4:
                        //Anda para a esquerda
                        if(animais[i]->getPosColuna() == 1){
                            while (!verificaOcupacaoEspaco(animais[i]->getPosLinha(),NC-distancia+1)){
                                distancia = rand() % 15+1;
                            }
                            Animal * tmp = new Lobo(getPLobo(),0,getSLobo(),'l',animais[i]->getPosLinha(),NC-distancia+1,newId(),getSLobo());
                            AddAnimal(tmp);
                        } else if(animais[i]->getPosColuna()-distancia < 1){
                            while (!verificaOcupacaoEspaco(animais[i]->getPosLinha(),NC+animais[i]->getPosColuna()-distancia)){
                                distancia = rand() % 15+1;
                            }
                            Animal * tmp = new Lobo(getPLobo(),0,getSLobo(),'l',animais[i]->getPosLinha(),NC+animais[i]->getPosColuna()-distancia,newId(),getSLobo());
                            AddAnimal(tmp);
                        } else{
                            while (!verificaOcupacaoEspaco(animais[i]->getPosLinha(),animais[i]->getPosColuna()-distancia)){
                                distancia = rand() % 15+1;
                            }
                            Animal * tmp = new Lobo(getPLobo(),0,getSLobo(),'l',animais[i]->getPosLinha(),animais[i]->getPosColuna()-distancia,newId(),getSLobo());
                            AddAnimal(tmp);
                        }
                        break;
                }
            }
        }else if(animais[i]->getEspecie() == 'g'){
            if(animais[i]->getInstantesDecorridos() == 30 || animais[i]->getInstantesDecorridos() == 60){
                int direcao = rand() % 4+1;
                int distancia = rand() % 3+1;
                switch(direcao) {
                    case 1:
                        //Anda para cima
                        if(animais[i]->getPosLinha() == 1){
                            while (!verificaOcupacaoEspaco(NL - distancia + 1,animais[i]->getPosColuna())){
                                distancia = rand() % 3+1;
                            }
                            Animal *tmp = new Canguru(getPCanguru(), 0,getSCanguru(), 'g', NL - distancia + 1, animais[i]->getPosColuna(), newId(), getVCanguru());
                            AddAnimal(tmp);
                        } else if(animais[i]->getPosLinha() - distancia < 1){
                            while (!verificaOcupacaoEspaco(NL-(animais[i]->getPosLinha() - distancia),animais[i]->getPosColuna())){
                                distancia = rand() % 3+1;
                            }
                            Animal * tmp = new Canguru(getPCanguru(),0,getSCanguru(),'g',NL-(animais[i]->getPosLinha() - distancia),animais[i]->getPosColuna(),newId(),getVCanguru());
                            AddAnimal(tmp);
                        } else {
                            while (!verificaOcupacaoEspaco(animais[i]->getPosLinha()-distancia,animais[i]->getPosColuna())){
                                distancia = rand() % 3+1;
                            }
                            Animal * tmp = new Canguru(getPCanguru(),0,getSCanguru(),'g',animais[i]->getPosLinha()-distancia,animais[i]->getPosColuna(),newId(),getVCanguru());
                            AddAnimal(tmp);
                        }
                        break;
                    case 2:
                        //Anda para a direita
                        if(animais[i]->getPosColuna() == NC){
                            while (!verificaOcupacaoEspaco(animais[i]->getPosLinha(),distancia)){
                                distancia = rand() % 3+1;
                            }
                            Animal * tmp = new Canguru(getPCanguru(),0,getSCanguru(),'g',animais[i]->getPosLinha(),distancia,newId(),getVCanguru());
                            AddAnimal(tmp);
                        } else if(animais[i]->getPosColuna()+distancia > NC){
                            while (!verificaOcupacaoEspaco(animais[i]->getPosLinha(),distancia-(NC-animais[i]->getPosColuna()))){
                                distancia = rand() % 3+1;
                            }
                            Animal * tmp = new Canguru(getPCanguru(),0,getSCanguru(),'g',animais[i]->getPosLinha(),distancia-(NC-animais[i]->getPosColuna()),newId(),getVCanguru());
                            AddAnimal(tmp);
                        } else{
                            while (!verificaOcupacaoEspaco(animais[i]->getPosLinha(),animais[i]->getPosColuna()+distancia)){
                                distancia = rand() % 3+1;
                            }
                            Animal * tmp = new Canguru(getPCanguru(),0,getSCanguru(),'g',animais[i]->getPosLinha(),animais[i]->getPosColuna()+distancia,newId(),getVCanguru());
                            AddAnimal(tmp);
                        }
                        break;
                    case 3:
                        //Anda para baixo
                        if(animais[i]->getPosLinha() == NL){
                            while (!verificaOcupacaoEspaco(distancia,animais[i]->getPosColuna())){
                                distancia = rand() % 3+1;
                            }
                            Animal * tmp = new Canguru(getPCanguru(),0,getSCanguru(),'g',distancia,animais[i]->getPosColuna(),newId(),getVCanguru());
                            AddAnimal(tmp);
                        } else if(animais[i]->getPosLinha() + distancia > NL){
                            while (!verificaOcupacaoEspaco(distancia-(NL-animais[i]->getPosLinha()),animais[i]->getPosColuna())){
                                distancia = rand() % 3+1;
                            }
                            Animal * tmp = new Canguru(getPCanguru(),0,getSCanguru(),'g',distancia-(NL-animais[i]->getPosLinha()),animais[i]->getPosColuna(),newId(),getVCanguru());
                            AddAnimal(tmp);
                        } else {
                            while (!verificaOcupacaoEspaco(animais[i]->getPosLinha()+distancia,animais[i]->getPosColuna())){
                                distancia = rand() % 3+1;
                            }
                            Animal * tmp = new Canguru(getPCanguru(),0,getSCanguru(),'g',animais[i]->getPosLinha()+distancia,animais[i]->getPosColuna(),newId(),getVCanguru());
                            AddAnimal(tmp);
                        }
                        break;
                    case 4:
                        //Anda para a esquerda
                        if(animais[i]->getPosColuna() == 1){
                            while (!verificaOcupacaoEspaco(animais[i]->getPosLinha(),NC-distancia+1)){
                                distancia = rand() % 3+1;
                            }
                            Animal * tmp = new Canguru(getPCanguru(),0,getSCanguru(),'g',animais[i]->getPosLinha(),NC-distancia+1,newId(),getVCanguru());
                            AddAnimal(tmp);
                        } else if(animais[i]->getPosColuna()-distancia < 1){
                            while (!verificaOcupacaoEspaco(animais[i]->getPosLinha(),NC+animais[i]->getPosColuna()-distancia)){
                                distancia = rand() % 3+1;
                            }
                            Animal * tmp = new Canguru(getPCanguru(),0,getSCanguru(),'g',animais[i]->getPosLinha(),NC+animais[i]->getPosColuna()-distancia,newId(),getVCanguru());
                            AddAnimal(tmp);
                        } else{
                            while (!verificaOcupacaoEspaco(animais[i]->getPosLinha(),animais[i]->getPosColuna()-distancia)){
                                distancia = rand() % 3+1;
                            }
                            Animal * tmp = new Canguru(getPCanguru(),0,getSCanguru(),'g',animais[i]->getPosLinha(),animais[i]->getPosColuna()-distancia,newId(),getVCanguru());
                            AddAnimal(tmp);
                        }
                        break;
                }
            }
        }else if(animais[i]->getEspecie() == 'M'){
            if(animais[i]->getInstantesDecorridos() == 20){
                int direcao = rand() % 4+1;
                int distancia = rand() % 5+1;
                switch(direcao) {
                    case 1:
                        //Anda para cima
                        if(animais[i]->getPosLinha() == 1){
                            while (!verificaOcupacaoEspaco(NL - distancia + 1,animais[i]->getPosColuna())){
                                distancia = rand() % 5+1;
                            }
                            Animal * tmp = new Cavalo(getPCavalo(),0,getSCavalo(), 'M', NL - distancia + 1, animais[i]->getPosColuna(), newId(), getVCavalo());
                            AddAnimal(tmp);
                        } else if(animais[i]->getPosLinha() - distancia < 1){
                            while (!verificaOcupacaoEspaco(NL-(animais[i]->getPosLinha() - distancia),animais[i]->getPosColuna())){
                                distancia = rand() % 5+1;
                            }
                            Animal * tmp = new Cavalo(getPCavalo(),0,getSCavalo(),'M',NL-(animais[i]->getPosLinha() - distancia),animais[i]->getPosColuna(),newId(),getVCavalo());
                            AddAnimal(tmp);
                        } else {
                            while (!verificaOcupacaoEspaco(animais[i]->getPosLinha()-distancia,animais[i]->getPosColuna())){
                                distancia = rand() % 5+1;
                            }
                            Animal * tmp = new Cavalo(getPCavalo(),0,getSCavalo(),'M',animais[i]->getPosLinha()-distancia,animais[i]->getPosColuna(),newId(),getVCavalo());
                            AddAnimal(tmp);
                        }
                        break;
                    case 2:
                        //Anda para a direita
                        if(animais[i]->getPosColuna() == NC){
                            while (!verificaOcupacaoEspaco(animais[i]->getPosLinha(),distancia)){
                                distancia = rand() % 5+1;
                            }
                            Animal * tmp = new Cavalo(getPCavalo(),0,getSCavalo(),'M',animais[i]->getPosLinha(),distancia,newId(),getVCavalo());
                            AddAnimal(tmp);
                        } else if(animais[i]->getPosColuna()+distancia > NC){
                            while (!verificaOcupacaoEspaco(animais[i]->getPosLinha(),distancia-(NC-animais[i]->getPosColuna()))){
                                distancia = rand() % 5+1;
                            }
                            Animal * tmp = new Cavalo(getPCavalo(),0,getSCavalo(),'M',animais[i]->getPosLinha(),distancia-(NC-animais[i]->getPosColuna()),newId(),getVCavalo());
                            AddAnimal(tmp);
                        } else{
                            while (!verificaOcupacaoEspaco(animais[i]->getPosLinha(),animais[i]->getPosColuna()+distancia)){
                                distancia = rand() % 5+1;
                            }
                            Animal * tmp = new Cavalo(getPCavalo(),0,getSCavalo(),'M',animais[i]->getPosLinha(),animais[i]->getPosColuna()+distancia,newId(),getVCavalo());
                            AddAnimal(tmp);
                        }
                        break;
                    case 3:
                        //Anda para baixo
                        if(animais[i]->getPosLinha() == NL){
                            while (!verificaOcupacaoEspaco(distancia,animais[i]->getPosColuna())){
                                distancia = rand() % 5+1;
                            }
                            Animal * tmp = new Cavalo(getPCavalo(),0,getSCavalo(),'M',distancia,animais[i]->getPosColuna(),newId(),getVCavalo());
                            AddAnimal(tmp);
                        } else if(animais[i]->getPosLinha() + distancia > NL){
                            while (!verificaOcupacaoEspaco(distancia-(NL-animais[i]->getPosLinha()),animais[i]->getPosColuna())){
                                distancia = rand() % 5+1;
                            }
                            Animal * tmp = new Cavalo(getPCavalo(),0,getSCavalo(),'M',distancia-(NL-animais[i]->getPosLinha()),animais[i]->getPosColuna(),newId(),getVCavalo());
                            AddAnimal(tmp);
                        } else {
                            while (!verificaOcupacaoEspaco(animais[i]->getPosLinha()+distancia,animais[i]->getPosColuna())){
                                distancia = rand() % 5+1;
                            }
                            Animal * tmp = new Cavalo(getPCavalo(),0,getSCavalo(),'M',animais[i]->getPosLinha()+distancia,animais[i]->getPosColuna(),newId(),getVCavalo());
                            AddAnimal(tmp);
                        }
                        break;
                    case 4:
                        //Anda para a esquerda
                        if(animais[i]->getPosColuna() == 1){
                            while (!verificaOcupacaoEspaco(animais[i]->getPosLinha(),NC-distancia+1)){
                                distancia = rand() % 5+1;
                            }
                            Animal * tmp = new Cavalo(getPCavalo(),0,getSCavalo(),'M',animais[i]->getPosLinha(),NC-distancia+1,newId(),getVCavalo());
                            AddAnimal(tmp);
                        } else if(animais[i]->getPosColuna()-distancia < 1){
                            while (!verificaOcupacaoEspaco(animais[i]->getPosLinha(),NC+animais[i]->getPosColuna()-distancia)){
                                distancia = rand() % 5+1;
                            }
                            Animal * tmp = new Cavalo(getPCavalo(),0,getSCavalo(),'M',animais[i]->getPosLinha(),NC+animais[i]->getPosColuna()-distancia,newId(),getVCavalo());
                            AddAnimal(tmp);
                        } else{
                            while (!verificaOcupacaoEspaco(animais[i]->getPosLinha(),animais[i]->getPosColuna()-distancia)){
                                distancia = rand() % 5+1;
                            }
                            Animal * tmp = new Cavalo(getPCavalo(),0,getSCavalo(),'M',animais[i]->getPosLinha(),animais[i]->getPosColuna()-distancia,newId(),getVCavalo());
                            AddAnimal(tmp);
                        }
                        break;
                }
            }
        }
    }

    std::vector<Alimento*>::size_type sizeAlimento = alimentos.size();
    for (std::vector<Alimento*>::size_type i = 0; i < sizeAlimento; ++i){
        if(alimentos[i]->getTipo() == 'r'){
            if(alimentos[i]->getDuracao() == getVRelva()/4){
                int direcao = rand() % 4+1;
                int distancia = rand() % 5+4;
                switch (direcao) {
                    case 1:
                        //Anda para cima
                        if(alimentos[i]->getPosLinha() == 1){
                            if(verificaOcupacaoEspacoAlimento(NL - distancia + 1,alimentos[i]->getPosColuna())){
                                Alimento * tmp = new Relva('r', 3, 0, getVRelva(), NL - distancia + 1,alimentos[i]->getPosColuna(), newId());
                                AddAlimento(tmp);
                            }
                        } else if(alimentos[i]->getPosLinha() - distancia < 1){
                            if(verificaOcupacaoEspacoAlimento(NL-(alimentos[i]->getPosLinha() - distancia),alimentos[i]->getPosColuna())){
                                Alimento * tmp = new Relva('r', 3, 0, getVRelva(), NL-(alimentos[i]->getPosLinha() - distancia),alimentos[i]->getPosColuna(), newId());
                                AddAlimento(tmp);
                            }
                        } else {
                            if(verificaOcupacaoEspacoAlimento(alimentos[i]->getPosLinha()-distancia,alimentos[i]->getPosColuna())){
                                Alimento * tmp = new Relva('r', 3, 0, getVRelva(), alimentos[i]->getPosLinha()-distancia,alimentos[i]->getPosColuna(), newId());
                                AddAlimento(tmp);
                            }
                        }
                        break;
                    case 2:
                        //Anda para a direita
                        if(alimentos[i]->getPosColuna() == NC){
                            if(verificaOcupacaoEspacoAlimento(alimentos[i]->getPosLinha(),distancia)){
                                Alimento * tmp = new Relva('r', 3, 0, getVRelva(), alimentos[i]->getPosLinha(),distancia, newId());
                                AddAlimento(tmp);
                            }
                        } else if(alimentos[i]->getPosColuna()+distancia > NC){
                            if(verificaOcupacaoEspacoAlimento(alimentos[i]->getPosLinha(),distancia-(NC-alimentos[i]->getPosColuna()))){
                                Alimento * tmp = new Relva('r', 3, 0, getVRelva(), alimentos[i]->getPosLinha(),distancia-(NC-alimentos[i]->getPosColuna()), newId());
                                AddAlimento(tmp);
                            }
                        } else{
                            if(verificaOcupacaoEspacoAlimento(alimentos[i]->getPosLinha(),alimentos[i]->getPosColuna()+distancia)){
                                Alimento * tmp = new Relva('r', 3, 0, getVRelva(), alimentos[i]->getPosLinha(),alimentos[i]->getPosColuna()+distancia, newId());
                                AddAlimento(tmp);
                            }
                        }
                        break;
                    case 3:
                        //Anda para baixo
                        if(alimentos[i]->getPosLinha() == NL){
                            if(verificaOcupacaoEspacoAlimento(distancia,alimentos[i]->getPosColuna())){
                                Alimento * tmp = new Relva('r', 3, 0, getVRelva(), distancia,alimentos[i]->getPosColuna(), newId());
                                AddAlimento(tmp);
                            }
                        } else if(alimentos[i]->getPosLinha() + distancia > NL){
                            if(verificaOcupacaoEspacoAlimento(distancia-(NL-alimentos[i]->getPosLinha()),alimentos[i]->getPosColuna())){
                                Alimento * tmp = new Relva('r', 3, 0, getVRelva(), distancia-(NL-alimentos[i]->getPosLinha()),alimentos[i]->getPosColuna(), newId());
                                AddAlimento(tmp);
                            }
                        } else {
                            if(verificaOcupacaoEspacoAlimento(alimentos[i]->getPosLinha()+distancia,alimentos[i]->getPosColuna())){
                                Alimento * tmp = new Relva('r', 3, 0, getVRelva(), alimentos[i]->getPosLinha()+distancia,alimentos[i]->getPosColuna(), newId());
                                AddAlimento(tmp);
                            }
                        }
                        break;
                    case 4:
                        //Anda para a esquerda
                        if(alimentos[i]->getPosColuna() == 1){
                            if(verificaOcupacaoEspacoAlimento(alimentos[i]->getPosLinha(),NC-distancia+1)){
                                Alimento * tmp = new Relva('r', 3, 0, getVRelva(), alimentos[i]->getPosLinha(),NC-distancia+1, newId());
                                AddAlimento(tmp);
                            }
                        } else if(alimentos[i]->getPosColuna()-distancia < 1){
                            if(verificaOcupacaoEspacoAlimento(alimentos[i]->getPosLinha(),NC+alimentos[i]->getPosColuna()-distancia)){
                                Alimento * tmp = new Relva('r', 3, 0, getVRelva(), alimentos[i]->getPosLinha(),NC+alimentos[i]->getPosColuna()-distancia, newId());
                                AddAlimento(tmp);
                            }
                        } else{
                            if(verificaOcupacaoEspacoAlimento(alimentos[i]->getPosLinha(),alimentos[i]->getPosColuna()-distancia)){
                                Alimento * tmp = new Relva('r', 3, 0, getVRelva(), alimentos[i]->getPosLinha(),alimentos[i]->getPosColuna()-distancia, newId());
                                AddAlimento(tmp);
                            }
                        }
                        break;
                }
            }
        }
    }
}

int Reserva::TotalAnimais() {
    int conta = animais.size();
    return conta;
}

int Reserva::TotalAlimentos() {
    int conta = alimentos.size();
    return conta;
}

int Reserva::numElementosPorPosicao(int nl, int nc) {
    int contador = 0;
    auto it = this->animais.begin();
    while(it != this->animais.end()){
        if((*it)->getPosLinha() == nl && (*it)->getPosColuna() == nc){
            contador++;
            ++it;
        }
        else
            ++it;
    }

    auto i = this->alimentos.begin();
    while(i != this->alimentos.end()){
        if((*i)->getPosLinha() == nl && (*i)->getPosColuna() == nc){
            contador++;
            ++i;
        }
        else
            ++i;
    }

    return contador;
}

string Reserva::CheiroDoAlimento(int nl, int nc) {
    auto i = this->alimentos.begin();
    while(i != this->alimentos.end()){
        if((*i)->getPosLinha() == nl && (*i)->getPosColuna() == nc){
            return (*i)->getCheiro();
        }
        else
            ++i;
    }
    return nullptr;
}

bool Reserva::EncontraAnimalPesado(int num, int nl, int nc, int m) const { //id, linha, coluna, massa
    auto it = this->animais.begin();
    while(it != this->animais.end()){
        if((*it)->getId() != num && (*it)->getPosLinha() == nl && (*it)->getPosColuna() == nc){
            if((*it)->getMassa() > m){
                return true;
            }
            ++it;
        }
        else
            ++it;
    }
    return false;
}

/*bool Reserva::animalSegueAlimento(int num) {
    auto it = this->animais.begin();
    while(it != this->animais.end()){
        if((*it)->getId() == num){
            for(int a = 1; a < 5; a++){
                if(CheiroDoAlimento((*it)->getPosLinha()-a, (*it)->getPosColuna()) == "verdura"){
                    (*it)->setPoslinha((*it)->getPosLinha()-a);
                }else if(CheiroDoAlimento((*it)->getPosLinha(), (*it)->getPosColuna()+a) == "verdura"){
                    (*it)->setPoscoluna((*it)->getPosColuna()+a);
                }else if(CheiroDoAlimento((*it)->getPosLinha()+a, (*it)->getPosColuna()) == "verdura"){
                    (*it)->setPoslinha((*it)->getPosLinha()+a);
                }else if(CheiroDoAlimento((*it)->getPosLinha(), (*it)->getPosColuna()-a) == "verdura"){
                    (*it)->setPoscoluna((*it)->getPosColuna()-a);
                }
            }
            return true;
        }
        else
            ++it;
    }

    return false;
}*/
