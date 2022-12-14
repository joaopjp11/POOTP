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

    mostraReserva(jogo, ViewReserva);


    do{
        ViewReserva.clear();
        Comando << "Comando:";
        Comando >> comando;
        istringstream iss(comando);
        StatusComandos << validaComando(jogo, jogos, iss, ViewReserva);
        StatusComandos.clear();
        mostraReserva(jogo, ViewReserva);
        Detalhes << jogo.DetalhesJogo();
        //Detalhes << jogo.getReserva()->getAsString();
        Detalhes.clear();
        Comando.clear();

    }while(comando != "exit");
}


void Simulador::mostraReserva(Jogo &jogo,Window &ViewReserva) {
    int linhas = jogo.getReserva()->getLinhas();
    int colunas = jogo.getReserva()->getColunas();
    int i = 0;
    int j = 0;

    //Dimensões da ViewReserva = 22 Linhas x 58 Colunas
    for(i=1;i<linhas+1;i++){
            for(j=1;j<colunas+1;j++){
                if(jogo.getReserva()->numElementosPorPosicao(i,j) > 1){
                    ViewReserva << "*";
                }else if(jogo.getReserva()->verificaLinhaColunaAnimal(i,j)) {
                    ViewReserva << jogo.getReserva()->especieAnimal(i, j);

                }else if(jogo.getReserva()->verificaLinhaColunaAlimento(i,j)) {
                    ViewReserva << jogo.getReserva()->tipoAlimento(i, j);

                }else if(!jogo.getReserva()->verificaLinhaColunaAnimal(i,j) && !jogo.getReserva()->verificaLinhaColunaAlimento(i,j))
                    ViewReserva << "_";
            }
            ViewReserva << "\n";
    }
}

string Simulador::validaComando(Jogo &jogo, Store &jogos, istringstream &recebe,Window &ViewReserva) {
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
                    Animal * tmp = new Coelho(massa,0,jogo.getReserva()->getSCoelho(),especie,linha,coluna,jogo.getReserva()->newId(),jogo.getReserva()->getVCoelho());
                    jogo.getReserva()->AddAnimal(tmp);
                    return "Cria coelho em posicao aleatoria!";
                } else if (especie == 'o'){
                    massa = rand() % 5 + 4;
                    Animal * tmp = new Ovelha(massa,0,jogo.getReserva()->getSOvelha(),especie,linha,coluna,jogo.getReserva()->newId(),jogo.getReserva()->getVOvelha());
                    jogo.getReserva()->AddAnimal(tmp);
                    return "Cria ovelha em posicao aleatoria!";
                } else if (especie == 'l'){
                    Animal * tmp = new Lobo(jogo.getReserva()->getPLobo(),0,jogo.getReserva()->getSLobo(),especie,linha,coluna,jogo.getReserva()->newId(),-1);
                    jogo.getReserva()->AddAnimal(tmp);
                    return "Cria lobo em posicao aleatoria!";
                } else if (especie == 'g'){
                    Animal * tmp = new Canguru(jogo.getReserva()->getPCanguru(),0,jogo.getReserva()->getSCanguru(),especie,linha,coluna,jogo.getReserva()->newId(),jogo.getReserva()->getVCanguru());
                    jogo.getReserva()->AddAnimal(tmp);
                    return "Cria canguru em posicao aleatoria!";
                } else if (especie == 'M'){
                    Animal * tmp = new Cavalo(jogo.getReserva()->getPCavalo(),0,jogo.getReserva()->getSCavalo(),especie,linha,coluna,jogo.getReserva()->newId(),jogo.getReserva()->getVCavalo());
                    jogo.getReserva()->AddAnimal(tmp);
                    return "Cria cavalo em posicao aleatoria!";
                }else {
                    return "Impossivel criar animal dessa especie";
                }
            }else{
                if(linha > jogo.getReserva()->getLinhas() || linha <= 0 || coluna <= 0 || coluna > jogo.getReserva()->getColunas())
                    return "Fora da dimensao da reserva!";
                else{
                    if(especie == 'c'){
                        massa = rand() % 4+1;
                        Animal * tmp = new Coelho(massa,0,jogo.getReserva()->getSCoelho(),especie,linha,coluna,jogo.getReserva()->newId(),jogo.getReserva()->getVCoelho());
                        jogo.getReserva()->AddAnimal(tmp);
                        return "Coelho criado";
                    } else if (especie == 'o'){
                        massa = rand() % 5 + 4;
                        Animal * tmp = new Ovelha(massa,0,jogo.getReserva()->getSOvelha(),especie,linha,coluna,jogo.getReserva()->newId(),jogo.getReserva()->getVOvelha());
                        jogo.getReserva()->AddAnimal(tmp);
                        return "Ovelha criada";
                    } else if (especie == 'l'){
                        Animal * tmp = new Lobo(jogo.getReserva()->getPLobo(),0,jogo.getReserva()->getSLobo(),especie,linha,coluna,jogo.getReserva()->newId(),-1);
                        jogo.getReserva()->AddAnimal(tmp);
                        return "Lobo criado";
                    } else if (especie == 'g'){
                        Animal * tmp = new Canguru(jogo.getReserva()->getPCanguru(),0,jogo.getReserva()->getSCanguru(),especie,linha,coluna,jogo.getReserva()->newId(),jogo.getReserva()->getVCanguru());
                        jogo.getReserva()->AddAnimal(tmp);
                        return "Canguru criado";
                    } else if (especie == 'M'){
                        Animal * tmp = new Cavalo(jogo.getReserva()->getPCavalo(),0,jogo.getReserva()->getSCavalo(),especie,linha,coluna,jogo.getReserva()->newId(),jogo.getReserva()->getVCavalo());
                        jogo.getReserva()->AddAnimal(tmp);
                        return "Cavalo criado";
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
                        Alimento * tmp = new Relva(tipo, 3, 0, jogo.getReserva()->getVRelva(), linha, coluna, jogo.getReserva()->newId());
                        jogo.getReserva()->AddAlimento(tmp);
                        return "Colocar relva em posicao aleatoria!";
                    } else if (tipo == 't') {
                        Alimento * tmp = new Cenoura(tipo, 4, 0, 1000, linha, coluna, jogo.getReserva()->newId());
                        jogo.getReserva()->AddAlimento(tmp);
                        return "Colocar cenoura em posicao aleatoria!";
                    } else if (tipo == 'b') {
                        Alimento * tmp = new Bife(tipo, 10, 2, jogo.getReserva()->getVBife(), linha, coluna, jogo.getReserva()->newId());
                        jogo.getReserva()->AddAlimento(tmp);
                        return "Colocar bife em posicao aleatoria!";
                    } else if (tipo == 'a') {
                        Alimento * tmp = new Maca(tipo, 5, 0, jogo.getReserva()->getVMaca(), linha, coluna, jogo.getReserva()->newId());
                        jogo.getReserva()->AddAlimento(tmp);
                        return "Colocar maca em posicao aleatoria!";
                    }else {
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
                            Alimento * tmp = new Relva(tipo, 3, 0, jogo.getReserva()->getVRelva(), linha, coluna, jogo.getReserva()->newId());
                            jogo.getReserva()->AddAlimento(tmp);
                            return "Relva colocada";
                        } else if (tipo == 't') {
                            Alimento * tmp = new Cenoura(tipo, 4, 0, 1000, linha, coluna, jogo.getReserva()->newId());
                            jogo.getReserva()->AddAlimento(tmp);
                            return "Cenoura colocada";
                        } else if (tipo == 'b') {
                            Alimento * tmp = new Bife(tipo, 10, 2, jogo.getReserva()->getVBife(), linha, coluna, jogo.getReserva()->newId());
                            jogo.getReserva()->AddAlimento(tmp);
                            return "Bife colocado";
                        } else if (tipo == 'a') {
                            Alimento * tmp = new Maca(tipo, 5, 0, jogo.getReserva()->getVMaca(), linha, coluna, jogo.getReserva()->newId());
                            jogo.getReserva()->AddAlimento(tmp);
                            return "Maca colocada";
                        }else {
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
    }else if(com == "hist"){
        recebe >> id;
        if(recebe.fail()){
            return "Comando invalido!";
        }else{
            if(jogo.getReserva()->procuraIdAnimal(id)){
                return jogo.getReserva()->printHistAlimentacaoAnimal(id);
            }else
                return "Nao existem animais com esse id!";
        }
    }else if(com == "n"){
        recebe >> num;
        if(recebe.fail()){
            jogo.getReserva()->movimentaAnimais();
            jogo.getReserva()->AumentaFomeAnimais();
            jogo.getReserva()->DiminuiVinstantes();
            jogo.getReserva()->AumentaInstantesDecorridosAnimal();
            jogo.getReserva()->DiminuiDuracaoAlimentos();
            jogo.getReserva()->updateNutriToxiAlimentos();
            jogo.getReserva()->verificaSaude();
            jogo.getReserva()->FazNascer();
            jogo.incrementaInstante(1);
            return "Passa 1 instante";
        }else{
            recebe >> pausa;
            if(recebe.fail()){
                int aux = num;
                do{
                    jogo.getReserva()->movimentaAnimais();
                    jogo.getReserva()->AumentaFomeAnimais();
                    jogo.getReserva()->DiminuiVinstantes();
                    jogo.getReserva()->AumentaInstantesDecorridosAnimal();
                    jogo.getReserva()->DiminuiDuracaoAlimentos();
                    jogo.getReserva()->updateNutriToxiAlimentos();
                    jogo.getReserva()->verificaSaude();
                    jogo.getReserva()->FazNascer();
                    jogo.incrementaInstante(1);
                    aux--;
                } while (aux > 0);
                return "Passa instantes";
            }else{
                int aux = num;
                do{
                    jogo.getReserva()->movimentaAnimais();
                    jogo.getReserva()->AumentaFomeAnimais();
                    jogo.getReserva()->DiminuiVinstantes();
                    jogo.getReserva()->AumentaInstantesDecorridosAnimal();
                    jogo.getReserva()->DiminuiDuracaoAlimentos();
                    jogo.getReserva()->updateNutriToxiAlimentos();
                    jogo.getReserva()->verificaSaude();
                    jogo.getReserva()->FazNascer();
                    jogo.incrementaInstante(1);
                    ViewReserva.clear();
                    mostraReserva(jogo, ViewReserva);
                    sleep(pausa);
                    ViewReserva.clear();
                    aux--;
                } while (aux > 0);
                return "Passa instantes com pausa";
            }
        }

    }else if(com == "anim"){
        return jogo.getReserva()->ComandoAnim();

    }else if(com == "visanim"){
        return "Por Implementar!";

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
            Jogo* guardado = jogos.encontraJogo(nome);
            jogo = *guardado;
            return "Por implementar";
        }

    }else if(com == "load"){
        recebe >> ficheiro;
        if(leficheiro(jogo, jogos, ficheiro, ViewReserva)){
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
            /*
            string s;
            ViewReserva >> s;
            if (s == "KEY_UP") {
                if( y>0 ) y--;
            }
            if (s == "KEY_DOWN") {
                if( y<t.getNumRows()-5 ) y++;
            }
            if (s == "KEY_LEFT") {
                if( x>0 ) x--;
            }
            if (s == "KEY_RIGHT") {
                if( x<t.getNumCols()-30 ) x++;
            }
             */
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

bool Simulador::leficheiro(Jogo &jogo, Store &jogos, const string ficheiro,Window &ViewReserva) {
    ifstream comandos;
    string aux;
    comandos.open(ficheiro);

    if(comandos.is_open()){
        while(getline(comandos, aux))
        {
            istringstream recebe(aux);
            validaComando(jogo, jogos, recebe, ViewReserva);
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
            jogo.getReserva()->setConstantes(recebe);
        }
        constante.close();
        return true;
    } else{
        return false;
    }
}