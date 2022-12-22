#include "Simulador.h"

void Simulador::comecaSimulador() {
    string comando;
    string dimensao;
    int nl, nc;

    do{
        cout << "Dimensao para a reserva (linhas colunas): ";
        getline(cin,dimensao);
        istringstream dim(dimensao);
        dim >> nl >> nc;
        if(nl < 16 || nl > 500 || nc < 16 || nc > 500)
            cout << "Numero de linhas e colunas tem de ser entre 16-500" << endl;
    } while (nl < 16 || nl > 500 || nc < 16 || nc > 500 );

    Reserva reserva(nl,nc);
    Jogo jogo(&reserva);
    Store jogos;
    config(jogo,"constantes.txt");

    Terminal &t = Terminal::instance();

    Window ViewReserva = Window(0, 0, 60, 24, true);
    Window Comando = Window(0, 24, 60, 4, true);
    Window Detalhes = Window(65, 0, 50, 24, true);
    Window StatusComandos = Window(65, 24, 50, 6, true);

    mostraReservaInicial(jogo);

    do{
        Comando << "Comando(help):";
        Comando >> comando;
        //cout << "\nComando(help):";
        //getline(cin,comando);
        istringstream iss(comando);
        StatusComandos << validaComando(jogo, jogos, iss);
        StatusComandos.clear();
        Detalhes << jogo.getReserva()->getAsString();
        Detalhes.clear();
        Comando.clear();

    }while(comando != "exit");
}

void Simulador::mostraReservaInicial(Jogo &jogo) {
    int linhas = jogo.getReserva()->getLinhas();
    int colunas = jogo.getReserva()->getColunas();
    int i = 0;
    int j = 0;

    for(i=0;i<linhas+2;i++){
        cout << "|";
        if(i == 0){
            for(j=0;j<colunas;j++){
                cout << "|";
            }
        }
        else if(i == linhas+1){
            for(j=0;j<colunas;j++){
                cout << "|";
            }
        }
        else {
            for(j=1;j<colunas+1;j++){
                cout << " ";
            }
        }
        cout << "|" << endl;
    }
}

void Simulador::mostraReserva(Jogo &jogo) {
    int linhas = jogo.getReserva()->getLinhas();
    int colunas = jogo.getReserva()->getColunas();
    int i = 0;
    int j = 0;

    for(i=0;i<linhas+2;i++){
        cout << "|";
        if(i == 0){
            for(j=0;j<colunas;j++){
                cout << "|";
            }
        }
        else if(i == linhas+1){
            for(j=0;j<colunas;j++){
                cout << "|";
            }
        }
        else {
            for(j=1;j<colunas+1;j++){
                if(jogo.getReserva()->verificaLinhaColunaAnimal(i,j))
                    cout << jogo.getReserva()->especieAnimal(i,j);

                if(jogo.getReserva()->verificaLinhaColunaAlimento(i,j))
                    cout << jogo.getReserva()->tipoAlimento(i,j);

                if(!jogo.getReserva()->verificaLinhaColunaAnimal(i,j) && !jogo.getReserva()->verificaLinhaColunaAlimento(i,j))
                    cout << " ";
            }
        }
        cout << "|" << endl;
    }
}

string Simulador::validaComando(Jogo &jogo, Store &jogos, istringstream &recebe) {
    int linha;
    int coluna;
    int id;
    int nutri;
    int toxi;
    int num;
    int pausa;
    char especie;
    int massa;
    char tipo;
    string ficheiro;
    string nome;
    string com;
    string direcao;

    srand(time(nullptr));

    recebe >> com;

    if(com == "animal"){
        recebe >> especie;
        if(recebe.fail()){
            return "Comando invalido!";
        }else{
            recebe >> linha >> coluna;
            if(recebe.fail()){
                linha = rand() % jogo.getReserva()->getLinhas() + 1;
                coluna = rand() % jogo.getReserva()->getColunas() + 1;

                if(especie == 'c'){
                    massa = rand() % 4+1;
                    Animal * tmp = new Coelho(massa,0,jogo.getSCoelho(),especie,linha,coluna,jogo.getReserva()->newId(),jogo.getVCoelho());
                    jogo.getReserva()->AddAnimal(tmp);
                    return "Cria coelho em posicao aleatoria!";
                } else if (especie == 'o'){
                    massa = rand() % 5 + 4;
                    Animal * tmp = new Ovelha(massa,0,jogo.getSOvelha(),especie,linha,coluna,jogo.getReserva()->newId(),jogo.getVOvelha());
                    jogo.getReserva()->AddAnimal(tmp);
                    return "Cria ovelha em posicao aleatoria!";
                } else if (especie == 'l'){
                    Animal * tmp = new Lobo(jogo.getPLobo(),0,jogo.getSLobo(),especie,linha,coluna,jogo.getReserva()->newId(),-1);
                    jogo.getReserva()->AddAnimal(tmp);
                    return "Cria lobo em posicao aleatoria!";
                } else if (especie == 'g'){
                    Animal * tmp = new Canguru(jogo.getPCanguru(),0,jogo.getSCanguru(),especie,linha,coluna,jogo.getReserva()->newId(),jogo.getVCanguru());
                    jogo.getReserva()->AddAnimal(tmp);
                    return "Cria canguru em posicao aleatoria!";
                } else {
                    return "Impossivel criar animal dessa especie";
                }
            }else{
                if(linha > jogo.getReserva()->getLinhas() || linha <= 0 || coluna <= 0 || coluna > jogo.getReserva()->getColunas())
                    return "Fora da dimensao da reserva!";
                else{
                    if(especie == 'c'){
                        massa = rand() % 4+1;
                        Animal * tmp = new Coelho(massa,0,jogo.getSCoelho(),especie,linha,coluna,jogo.getReserva()->newId(),jogo.getVCoelho());
                        //Coelho tmp(massa,0,jogo.getSCoelho(),especie,linha,coluna,jogo.getReserva()->newId(),jogo.getVCoelho());
                        jogo.getReserva()->AddAnimal(tmp);
                        return "Coelho criado";
                    } else if (especie == 'o'){
                        massa = rand() % 5 + 4;
                        Animal * tmp = new Ovelha(massa,0,jogo.getSOvelha(),especie,linha,coluna,jogo.getReserva()->newId(),jogo.getVOvelha());
                        jogo.getReserva()->AddAnimal(tmp);
                        return "Ovelha criada";
                    } else if (especie == 'l'){
                        Animal * tmp = new Lobo(jogo.getPLobo(),0,jogo.getSLobo(),especie,linha,coluna,jogo.getReserva()->newId(),-1);
                        jogo.getReserva()->AddAnimal(tmp);
                        return "Lobo criado";
                    } else if (especie == 'g'){
                        Animal * tmp = new Canguru(jogo.getPCanguru(),0,jogo.getSCanguru(),especie,linha,coluna,jogo.getReserva()->newId(),jogo.getVCanguru());
                        jogo.getReserva()->AddAnimal(tmp);
                        return "Canguru criado";
                    } else {
                        return "Impossivel criar animal dessa especie";
                    }
                }
            }
        }

    }else if(com == "kill"){
        recebe >> linha >> coluna;
        if(recebe.fail()){
            return "Comando invalido!";
        }else{
            if(linha > jogo.getReserva()->getLinhas() || linha <= 0 || coluna <= 0 || coluna > jogo.getReserva()->getColunas())
                return "Fora da dimensao da reserva!";
            else{
                if(jogo.getReserva()->verificaLinhaColunaAnimal(linha,coluna) == 0)
                    return "Posicao sem animais";
                else{
                    jogo.getReserva()->mataAnimal(linha,coluna);
                    return "Animais mortos!";
                }
            }
        }
    }else if(com == "killid"){
        recebe >> id;
        if(recebe.fail()){
            return "Comando invalido!";
        }else{
            if(jogo.getReserva()->procuraIdAnimal(id)){
                jogo.getReserva()->mataAnimal(id);
                return "Animal morto!";
            }
            else
                return "Nao existem animais com esse id!";
        }
    }else if(com == "food"){
        recebe >> tipo;
        if(recebe.fail()){
            return "Comando invalido!";
        }else{
            recebe >> linha >> coluna;
            if(recebe.fail()){
                linha = rand() % jogo.getReserva()->getLinhas() + 1;
                coluna = rand() % jogo.getReserva()->getColunas() + 1;
                if(jogo.getReserva()->verificaLinhaColunaAlimento(linha,coluna) == 0) {
                    if (tipo == 'r') {
                        //string cheiro[2] = {"erva","verdura"};
                        Alimento * tmp = new Relva(tipo, 3, 0, jogo.getVRelva(), "teste", linha, coluna, jogo.getReserva()->newId());
                        jogo.getReserva()->AddAlimento(tmp);
                        return "Colocar relva em posicao aleatoria!";
                    } else if (tipo == 't') {
                        Alimento * tmp = new Cenoura(tipo, 4, 0, 1000, "verdura", linha, coluna, jogo.getReserva()->newId());
                        jogo.getReserva()->AddAlimento(tmp);
                        return "Colocar cenoura em posicao aleatoria!";
                    } else if (tipo == 'b') {
                        Alimento * tmp = new Bife(tipo, 10, 2, jogo.getVBife(), "teste", linha, coluna, jogo.getReserva()->newId());
                        jogo.getReserva()->AddAlimento(tmp);
                        return "Colocar bife em posicao aleatoria!";
                    } else {
                        return "Impossivel criar alimento desse tipo";
                    }
                }
                else
                    return "Posicao ja tem um alimento";
            }else{
                if(linha > jogo.getReserva()->getLinhas() || linha <= 0 || coluna <= 0 || coluna > jogo.getReserva()->getColunas())
                    return "Fora da dimensao da reserva!";
                else{
                    if(jogo.getReserva()->verificaLinhaColunaAlimento(linha,coluna) == 0) {
                        if (tipo == 'r') {
                            //string cheiro[2] = {"erva","verdura"};
                            Alimento * tmp = new Relva(tipo, 3, 0, jogo.getVRelva(), "teste", linha, coluna, jogo.getReserva()->newId());
                            jogo.getReserva()->AddAlimento(tmp);
                            return "Relva colocada";
                        } else if (tipo == 't') {
                            Alimento * tmp = new Cenoura(tipo, 4, 0, 1000, "verdura", linha, coluna, jogo.getReserva()->newId());
                            jogo.getReserva()->AddAlimento(tmp);
                            return "Cenoura colocada";
                        } else if (tipo == 'b') {
                            //string cheiro[2] = {"carne","ketchup"};
                            Alimento * tmp = new Bife(tipo, 10, 2, jogo.getVBife(), "teste", linha, coluna, jogo.getReserva()->newId());
                            jogo.getReserva()->AddAlimento(tmp);
                            return "Bife colocado";
                        } else {
                            return "Impossivel criar alimento desse tipo";
                        }
                    }
                    else
                        return "Posicao ja tem um alimento";
                }
            }
        }

    }else if(com == "feed"){
        recebe >> linha >> coluna >> nutri >> toxi;
        if(recebe.fail()){
            return "Comando invalido!";
        }else{
            if(linha > jogo.getReserva()->getLinhas() || linha <= 0 || coluna <= 0 || coluna > jogo.getReserva()->getColunas())
                return "linha ou coluna invalida!";
            else{
                if( jogo.getReserva()->verificaLinhaColunaAnimal(linha,coluna) != 0){
                    jogo.getReserva()->alimentaAnimal(linha,coluna, nutri, toxi);
                    return "Animais alimentados!";
                } else{
                    return "Posicao vazia!";
                }
            }
        }
    }else if(com == "feedid"){
        recebe >> id >> nutri >> toxi;
        if(recebe.fail()){
            return "Comando invalido!";
        }else{
            if(jogo.getReserva()->procuraIdAnimal(id)){
                jogo.getReserva()->alimentaAnimal(id, nutri, toxi);
                return "Animal alimentado!";
            }
            else
                return "Nao existem animais com esse id!";
        }
    }else if(com == "nofood"){
        recebe >> linha;
        if(recebe.fail()){
            return "Comando invalido!";
        }else{
            recebe >> coluna;
            if(recebe.fail()){
                if(jogo.getReserva()->procuraIdAlimento(linha)){
                    jogo.getReserva()->removeAlimento(linha);
                    return "Alimento removido!";
                }
                else
                    return "Nao existem alimentos com esse id!";
            } else{
                if(linha > jogo.getReserva()->getLinhas() || linha <= 0 || coluna <= 0 || coluna > jogo.getReserva()->getColunas())
                    return "Fora da dimensao da reserva!";
                else{
                    int num = jogo.getReserva()->verificaLinhaColunaAlimento(linha, coluna);
                    if(num != 0){
                        jogo.getReserva()->removeAlimento(num);
                        return "Alimento removido";
                    }else
                        return "Posicao sem alimentos!";
                }
            }
        }

    }else if(com == "empty"){
        recebe >> linha >> coluna;
        if(recebe.fail()){
            return "Comando invalido!";
        }else{
            if(linha > jogo.getReserva()->getLinhas() || linha <= 0 || coluna <= 0 || coluna > jogo.getReserva()->getColunas())
                return "Fora da dimensao da reserva!";
            else {
                if(jogo.getReserva()->verificaLinhaColunaAnimal(linha, coluna) == 0 && jogo.getReserva()->verificaLinhaColunaAlimento(linha, coluna) == 0){
                    return "Posicao vazia!";
                }
                else {
                    int numAnimal = 0;
                    do {
                        numAnimal = jogo.getReserva()->verificaLinhaColunaAnimal(linha, coluna);
                        jogo.getReserva()->eliminaAnimal(numAnimal);
                    }while (jogo.getReserva()->verificaLinhaColunaAnimal(linha, coluna) != 0);

                    int numAlimento = jogo.getReserva()->verificaLinhaColunaAlimento(linha, coluna);
                    if (numAlimento != 0) {
                        jogo.getReserva()->eliminaAlimento(numAlimento);
                    }
                    return "Posicao foi limpa!";
                }
            }
        }
    }else if(com == "see"){
        recebe >> linha >> coluna;
        if(recebe.fail()){
            return "Comando invalido!";
        }else{
            if(linha > jogo.getReserva()->getLinhas() || linha <= 0 || coluna <= 0 || coluna > jogo.getReserva()->getColunas())
                return "Fora da dimensao da reserva!";
            else{
                if(jogo.getReserva()->verificaLinhaColunaAnimal(linha, coluna) == 0 && jogo.getReserva()->verificaLinhaColunaAlimento(linha, coluna) == 0){
                    return "Posicao vazia!";
                }
                return jogo.getReserva()->listPosicao(linha,coluna);
            }
        }
    }else if(com == "info"){
        recebe >> id;
        if(recebe.fail()){
            return "Comando invalido!";
        }else{
            if(jogo.getReserva()->procuraIdAnimal(id)){
                return jogo.getReserva()->listAnimal(id);
            }else if(jogo.getReserva()->procuraIdAlimento(id)){
                return jogo.getReserva()->listAlimento(id);
            }else
                return "Nao existem animais nem alimentos com esse id!";
        }
    }else if(com == "n"){
        recebe >> num;
        if(recebe.fail()){
            jogo.getReserva()->movimentaAnimais();
            //mostraReserva(jogo);
            jogo.getReserva()->AumentaFomeAnimais();
            jogo.incrementaInstante(1);
            return "Passa 1 instante";
        }else{
            recebe >> pausa;
            if(recebe.fail()){
                return "Passa instantes";
                //jogo.incrementaInstante(num);
            }else{
                return "Passa instantes com pausa";
                //jogo.incrementaInstante(num);
            }
        }

    }else if(com == "anim"){
        jogo.getReserva()->ComandoAnim();

    }else if(com == "visanim"){
        return "Comando valido!";

    }else if(com == "store"){
        recebe >> nome;
        if(recebe.fail()){
            return "Comando invalido!";
        }else{
            jogo.setNomeJogo(nome);
            Jogo* guardar = new Jogo(jogo);
            jogos.storeJogo(guardar);
            return "Jogo guardado com sucesso!";
        }

    }else if(com == "restore"){
        recebe >> nome;
        if(recebe.fail()){
            return "Comando invalido!";
        }else{
            /*Jogo* guardado = jogos.encontraJogo(nome);
            jogo.operator=(*guardado);
            cout << "\nJogo carregado!";*/
            return "Por implementar";
        }

    }else if(com == "load"){
        recebe >> ficheiro;
        if(leficheiro(jogo, jogos, ficheiro)){
            return "Ficheiro de comandos lido com sucesso!";
        }
        else{
            return "Erro ao abrir ficheiro!";
        }

    }else if(com == "slide"){
        recebe >> direcao >> num;
        if(recebe.fail()){
            return "Comando invalido!";
        }else{
            return "Comando valido!";
        }

    }else if(com == "list"){
        return jogo.getReserva()->getAsString();

    }else if(com == "exit"){
        return "A sair do jogo atual!";
    }else{
        return "Comando invalido!";
    }
    return "Comando invalido!";
}

bool Simulador::leficheiro(Jogo &jogo, Store &jogos, const string ficheiro) {
    ifstream comandos;
    string aux;
    comandos.open(ficheiro);

    if(comandos.is_open()){
        while(getline(comandos, aux))
        {
            istringstream recebe(aux);
            validaComando(jogo, jogos, recebe);
        }
        comandos.close();
        return true;
    } else{
        return false;
    }
}

bool Simulador::config(Jogo &jogo, const string ficheiro)
{
    ifstream constante;
    string aux;
    constante.open(ficheiro);

    if(constante.is_open()){
        while(getline(constante, aux)){
            istringstream recebe(aux);
            jogo.setConstantes(recebe);
        }
        constante.close();
        return true;
    } else{
        return false;
    }
}