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

    //Terminal &t = Terminal::instance();

    //Window ViewReserva = Window(0, 0, 60, 24, true);
    //Window Comando = Window(0, 24, 60, 4, true);
    //Window Detalhes = Window(65, 0, 50, 24, true);
    //Window StatusComandos = Window(65, 24, 50, 6, true);

    mostraReservaInicial(jogo);

    do{
        //Comando << "\nComando(help):";
        //Comando >> comando;
        cout << "\nComando(help):";
        getline(cin,comando);
        istringstream iss(comando);
        validaComando(jogo, jogos, iss);

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

void Simulador::validaComando(Jogo &jogo, Store &jogos, istringstream &recebe) {
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

    if(com == "help"){
        cout << "################Lista de comandos################" << endl;
        cout << "criar animal -> animal <especie: c / o / l / g / m> <linha> <coluna>" << endl;
        cout << "criar animal -> animal <especie: c / o / l / g / m>" << endl;
        cout << "matar animal -> kill <linha> <coluna>" << endl;
        cout << "matar animal -> killid <id>" << endl;
        cout << "colocar alimento -> food <tipo: r / t / b / a> <linha> <coluna>" << endl;
        cout << "colocar alimento -> food <tipo: r / t / b / a>" << endl;
        cout << "alimentar diretamente animais -> feed <linha> <coluna> <pontos nutritivos> <pontos de toxicidade>" << endl;
        cout << "alimentar diretamente animais -> feedid <ID> <pontos nutritivos> <pontos de toxicidade>" << endl;
        cout << "remover alimento -> nofood <linha> <coluna>" << endl;
        cout << "remover alimento -> nofood <ID> " << endl;
        cout << "eliminar o que quer que esteja numa posicao -> empty <linha> <coluna>" << endl;
        cout << "ver o que se encontra numa posicao -> see <linha> <coluna>" << endl;
        cout << "ver informacao sobre elemento do simulador -> info <ID>" << endl;
        cout << "passar para o instante seguinte -> n" << endl;
        cout << "passar para o instante seguinte -> n <N>" << endl;
        cout << "passar para o instante seguinte -> n <N> <P>" << endl;
        cout << "listar ID dos animais na reserva -> anim" << endl;
        cout << "listar ID dos animais na area visivel da reserva -> visanim" << endl;
        cout << "Armazenar o estado da reserva em memoria -> store <nome>" << endl;
        cout << "Reativar um estado da reserva previamente armazenado em memoria -> restore <nome>" << endl;
        cout << "Carregar e executar comandos a partir de um ficheiro de texto -> load <nome-do-ficheiro>" << endl;
        cout << "Deslocar a area de visualizacao -> slide <direcao: up/down/right/left> <linhas/colunas>" << endl;
        cout << "Encerrar o simulador -> exit" << endl;
        cout << "#################################################" << endl;

    }else if(com == "animal"){
        recebe >> especie;
        if(recebe.fail()){
            cout << "\nComando invalido!";
        }else{
            recebe >> linha >> coluna;
            if(recebe.fail()){
                linha = rand() % jogo.getReserva()->getLinhas() + 1;
                coluna = rand() % jogo.getReserva()->getColunas() + 1;

                if(especie == 'c'){
                    massa = rand() % 4+1;
                    Coelho tmp(massa,0,jogo.getSCoelho(),especie,linha,coluna,jogo.getReserva()->newId(),jogo.getVCoelho());
                    jogo.getReserva()->AddAnimal(tmp);
                    cout << "\nCria coelho em posicao aleatoria!";
                } else if (especie == 'o'){
                    massa = rand() % 5 + 4;
                    Ovelha tmp(massa,0,jogo.getSOvelha(),especie,linha,coluna,jogo.getReserva()->newId(),jogo.getVOvelha());
                    jogo.getReserva()->AddAnimal(tmp);
                    cout << "\nCria ovelha em posicao aleatoria!";
                } else if (especie == 'l'){
                    Lobo tmp(jogo.getPLobo(),0,jogo.getSLobo(),especie,linha,coluna,jogo.getReserva()->newId(),-1);
                    jogo.getReserva()->AddAnimal(tmp);
                    cout << "\nCria lobo em posicao aleatoria!";
                } else if (especie == 'g'){
                    Canguru tmp(jogo.getPCanguru(),0,jogo.getSCanguru(),especie,linha,coluna,jogo.getReserva()->newId(),jogo.getVCanguru());
                    jogo.getReserva()->AddAnimal(tmp);
                    cout << "\nCria canguru em posicao aleatoria!";
                } else {
                    cout << "\nImpossivel criar animal da especie: " << especie << endl;
                }
            }else{
                if(linha > jogo.getReserva()->getLinhas() || linha <= 0 || coluna <= 0 || coluna > jogo.getReserva()->getColunas())
                    cout << "\nFora da dimensao da reserva!";
                else{
                    if(especie == 'c'){
                        massa = rand() % 4+1;
                        Coelho tmp(massa,0,jogo.getSCoelho(),especie,linha,coluna,jogo.getReserva()->newId(),jogo.getVCoelho());
                        jogo.getReserva()->AddAnimal(tmp);
                        cout << "\nCria coelho na linha:" << linha << " coluna:" << coluna;
                    } else if (especie == 'o'){
                        massa = rand() % 5 + 4;
                        Ovelha tmp(massa,0,jogo.getSOvelha(),especie,linha,coluna,jogo.getReserva()->newId(),jogo.getVOvelha());
                        jogo.getReserva()->AddAnimal(tmp);
                        cout << "\nCria ovelha na linha:" << linha << " coluna:" << coluna;
                    } else if (especie == 'l'){
                        Lobo tmp(jogo.getPLobo(),0,jogo.getSLobo(),especie,linha,coluna,jogo.getReserva()->newId(),-1);
                        jogo.getReserva()->AddAnimal(tmp);
                        cout << "\nCria lobo na linha:" << linha << " coluna:" << coluna;
                    } else if (especie == 'g'){
                        Canguru tmp(jogo.getPCanguru(),0,jogo.getSCanguru(),especie,linha,coluna,jogo.getReserva()->newId(),jogo.getVCanguru());
                        jogo.getReserva()->AddAnimal(tmp);
                        cout << "\nCria canguru na linha:" << linha << " coluna:" << coluna;
                    } else {
                        cout << "\nImpossivel criar animal da especie: " << especie << endl;
                    }
                }
            }
        }

    }else if(com == "kill"){
        recebe >> linha >> coluna;
        if(recebe.fail()){
            cout << "\nComando invalido!";
        }else{
            if(linha > jogo.getReserva()->getLinhas() || linha <= 0 || coluna <= 0 || coluna > jogo.getReserva()->getColunas())
                cout << "\nFora da dimensao da reserva!";
            else{
                if(jogo.getReserva()->verificaLinhaColunaAnimal(linha,coluna) == 0)
                    cout << "\nPosicao sem animais";
                else{
                    jogo.getReserva()->mataAnimal(linha,coluna);
                    cout << "\nAnimais mortos!";
                }
            }
        }
    }else if(com == "killid"){
        recebe >> id;
        if(recebe.fail()){
            cout << "\nComando invalido!";
        }else{
            if(jogo.getReserva()->procuraIdAnimal(id)){
                jogo.getReserva()->mataAnimal(id);
                //FALTA DEFINIR A FUNÇÃO PARA MATAR ANIMAL
                cout << "\nAnimal morto!";
            }
            else
                cout << "\nNao existem animais com esse id!";
        }
    }else if(com == "food"){
        recebe >> tipo;
        if(recebe.fail()){
            cout << "\nComando invalido!";
        }else{
            recebe >> linha >> coluna;
            if(recebe.fail()){
                linha = rand() % jogo.getReserva()->getLinhas() + 1;
                coluna = rand() % jogo.getReserva()->getColunas() + 1;
                if(jogo.getReserva()->verificaLinhaColunaAlimento(linha,coluna) == 0) {
                    if (tipo == 'r') {
                        //string cheiro[2] = {"erva","verdura"};
                        Relva tmp(tipo, 3, 0, jogo.getVRelva(), "teste", linha, coluna, jogo.getReserva()->newId());
                        jogo.getReserva()->AddAlimento(tmp);
                        cout << "\nColocar relva em posicao aleatoria!";
                    } else if (tipo == 't') {
                        Cenoura tmp(tipo, 4, 0, 1000, "verdura", linha, coluna, jogo.getReserva()->newId());
                        jogo.getReserva()->AddAlimento(tmp);
                        cout << "\nColocar cenoura em posicao aleatoria!";
                    } else if (tipo == 'b') {
                        Bife tmp(tipo, 10, 2, jogo.getVBife(), "teste", linha, coluna, jogo.getReserva()->newId());
                        jogo.getReserva()->AddAlimento(tmp);
                        cout << "\nColocar bife em posicao aleatoria!";
                    } else {
                        cout << "\nImpossivel criar alimento do tipo: " << tipo << endl;
                    }
                }
                else
                    cout << "\nPosicao ja tem um alimento";
            }else{
                if(linha > jogo.getReserva()->getLinhas() || linha <= 0 || coluna <= 0 || coluna > jogo.getReserva()->getColunas())
                    cout << "\nFora da dimensao da reserva!";
                else{
                    if(jogo.getReserva()->verificaLinhaColunaAlimento(linha,coluna) == 0) {
                        if (tipo == 'r') {
                            //string cheiro[2] = {"erva","verdura"};
                            Relva tmp(tipo, 3, 0, jogo.getVRelva(), "teste", linha, coluna, jogo.getReserva()->newId());
                            jogo.getReserva()->AddAlimento(tmp);
                            cout << "\nColocar relva na linha:" << linha << " coluna:" << coluna;
                        } else if (tipo == 't') {
                            Cenoura tmp(tipo, 4, 0, 1000, "verdura", linha, coluna, jogo.getReserva()->newId());
                            jogo.getReserva()->AddAlimento(tmp);
                            cout << "\nColocar cenoura na linha:" << linha << " coluna:" << coluna;
                        } else if (tipo == 'b') {
                            //string cheiro[2] = {"carne","ketchup"};
                            Bife tmp(tipo, 10, 2, jogo.getVBife(), "teste", linha, coluna, jogo.getReserva()->newId());
                            jogo.getReserva()->AddAlimento(tmp);
                            cout << "\nColocar bife na linha:" << linha << " coluna:" << coluna;
                        } else {
                            cout << "\nImpossivel criar alimento do tipo: " << tipo << endl;
                        }
                    }
                    else
                        cout << "\nPosicao ja tem um alimento";
                }
            }
        }

    }else if(com == "feed"){
        recebe >> linha >> coluna >> nutri >> toxi;
        if(recebe.fail()){
            cout << "\nComando invalido!";
        }else{
            if(linha > jogo.getReserva()->getLinhas() || linha <= 0 || coluna <= 0 || coluna > jogo.getReserva()->getColunas())
                cout << "\nlinha ou coluna invalida!";
            else{
                if( jogo.getReserva()->verificaLinhaColunaAnimal(linha,coluna) != 0){
                    jogo.getReserva()->alimentaAnimal(linha,coluna, nutri, toxi);
                    cout << "\nAnimais alimentados!";
                } else{
                    cout << "\nPosicao vazia!";
                }
            }
        }
    }else if(com == "feedid"){
        recebe >> id >> nutri >> toxi;
        if(recebe.fail()){
            cout << "\nComando invalido!";
        }else{
            if(jogo.getReserva()->procuraIdAnimal(id)){
                jogo.getReserva()->alimentaAnimal(id, nutri, toxi);
                cout << "\nAnimal alimentado!";
            }
            else
                cout << "\nNao existem animais com esse id!";
        }
    }else if(com == "nofood"){
        recebe >> linha;
        if(recebe.fail()){
            cout << "\nComando invalido!";
        }else{
            recebe >> coluna;
            if(recebe.fail()){
                if(jogo.getReserva()->procuraIdAlimento(linha)){
                    jogo.getReserva()->removeAlimento(linha);
                    cout << "\nAlimento com id " << linha << " removido!";
                }
                else
                    cout << "\nNao existem alimentos com esse id!";
            } else{
                if(linha > jogo.getReserva()->getLinhas() || linha <= 0 || coluna <= 0 || coluna > jogo.getReserva()->getColunas())
                    cout << "\nFora da dimensao da reserva!";
                else{
                    int num = jogo.getReserva()->verificaLinhaColunaAlimento(linha, coluna);
                    if(num != 0){
                        jogo.getReserva()->removeAlimento(num);
                        cout << "\nRemove alimento na linha:" << linha << " coluna:" << coluna;
                    }else
                        cout << "\nPosicao sem alimentos!";
                }
            }
        }

    }else if(com == "empty"){
        recebe >> linha >> coluna;
        if(recebe.fail()){
            cout << "\nComando invalido!";
        }else{
            if(linha > jogo.getReserva()->getLinhas() || linha <= 0 || coluna <= 0 || coluna > jogo.getReserva()->getColunas())
                cout << "\nFora da dimensao da reserva!";
            else {
                if(jogo.getReserva()->verificaLinhaColunaAnimal(linha, coluna) == 0 && jogo.getReserva()->verificaLinhaColunaAlimento(linha, coluna) == 0){
                    cout << "\nPosicao vazia!";
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
                    cout << "\nPosicao (" << linha << "," << coluna << ") foi limpa!";
                }
            }
        }
    }else if(com == "see"){
        recebe >> linha >> coluna;
        if(recebe.fail()){
            cout << "\nComando invalido!";
        }else{
            if(linha > jogo.getReserva()->getLinhas() || linha <= 0 || coluna <= 0 || coluna > jogo.getReserva()->getColunas())
                cout << "\nFora da dimensao da reserva!";
            else{
                if(jogo.getReserva()->verificaLinhaColunaAnimal(linha, coluna) == 0 && jogo.getReserva()->verificaLinhaColunaAlimento(linha, coluna) == 0){
                    cout << "\nPosicao vazia!";
                }
                jogo.getReserva()->listPosicao(linha,coluna);
            }
        }
    }else if(com == "info"){
        recebe >> id;
        if(recebe.fail()){
            cout << "\nComando invalido!";
        }else{
            if(jogo.getReserva()->procuraIdAnimal(id)){
                cout << jogo.getReserva()->listAnimal(id);
            }else if(jogo.getReserva()->procuraIdAlimento(id)){
                cout << jogo.getReserva()->listAlimento(id);
            }else
                cout << "\nNao existem animais nem alimentos com esse id!";
        }
    }else if(com == "n"){
        recebe >> num;
        if(recebe.fail()){
            cout << "\nPassa 1 instante\n";
            jogo.getReserva()->movimentaAnimais();
            mostraReserva(jogo);
            //jogo.incrementaInstante(1);
        }else{
            recebe >> pausa;
            if(recebe.fail()){
                cout << "\nPassa " << num << " instantes";
                //jogo.incrementaInstante(num);
            }else{
                cout << "\nPassa " << num << " instantes com pausa de " << pausa << " segundos";
                //jogo.incrementaInstante(num);
            }
        }

    }else if(com == "anim"){
        jogo.getReserva()->ComandoAnim();

    }else if(com == "visanim"){
        cout << "\nComando valido!";

    }else if(com == "store"){
        recebe >> nome;
        if(recebe.fail()){
            cout << "\nComando invalido!";
        }else{
            jogo.setNomeJogo(nome);
            Jogo* guardar = new Jogo(jogo);
            jogos.storeJogo(guardar);
            cout << "\nJogo guardado com sucesso!\n";
        }

    }else if(com == "restore"){
        recebe >> nome;
        if(recebe.fail()){
            cout << "\nComando invalido!";
        }else{
            /*Jogo* guardado = jogos.encontraJogo(nome);
            jogo.operator=(*guardado);
            cout << "\nJogo carregado!";*/
            cout << "\nPor implementar";
        }

    }else if(com == "load"){
        recebe >> ficheiro;
        if(leficheiro(jogo, jogos, ficheiro)){
            cout << "\nFicheiro de comandos lido com sucesso!\n";
        }
        else{
            cout << "\nErro ao abrir ficheiro!\n";
        }

    }else if(com == "slide"){
        recebe >> direcao >> num;
        if(recebe.fail()){
            cout << "\nComando invalido!";
        }else{
            cout << "\nComando valido!";
        }

    }else if(com == "list"){
        cout << jogo.getReserva()->getAsString();

    }else if(com == "exit"){
        cout << "\nA sair do jogo atual!\n";
    }else{
        cout << "\nComando invalido!";
    }
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