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
        validaComando(jogo, iss);

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
            for(j=0;j<colunas;j++){
                cout << " ";
            }
        }
        cout << "|" << endl;
    }
}

void Simulador::validaComando(Jogo &jogo, istringstream &recebe) {
    int linha;
    int coluna;
    int id;
    int nutri;
    int toxi;
    int num;
    int pausa;
    char especie;
    int massa;
    string tipo;
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
                    Coelho tmp(massa,0,jogo.getSCoelho(),"maria",especie,linha,coluna,jogo.getReserva()->newId());
                    jogo.getReserva()->AddAnimal(tmp);
                    cout << "\nCria coelho em posicao aleatoria!";
                } else if (especie == 'o'){
                    massa = rand() % 5 + 4;
                    Ovelha tmp(massa,0,jogo.getSOvelha(),"maria",especie,linha,coluna,jogo.getReserva()->newId());
                    jogo.getReserva()->AddAnimal(tmp);
                    cout << "\nCria ovelha em posicao aleatoria!";
                } else if (especie == 'l'){
                    Lobo tmp(jogo.getPLobo(),0,jogo.getSLobo(),"maria",especie,linha,coluna,jogo.getReserva()->newId());
                    jogo.getReserva()->AddAnimal(tmp);
                    cout << "\nCria lobo em posicao aleatoria!";
                } else if (especie == 'g'){
                    Canguru tmp(jogo.getPCanguru(),0,jogo.getSCanguru(),"maria",especie,linha,coluna,jogo.getReserva()->newId());
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
                        Coelho tmp(massa,0,jogo.getSCoelho(),"maria",especie,linha,coluna,jogo.getReserva()->newId());
                        jogo.getReserva()->AddAnimal(tmp);
                        cout << "\nCria coelho na linha:" << linha << " coluna:" << coluna;
                    } else if (especie == 'o'){
                        massa = rand() % 5 + 4;
                        Ovelha tmp(massa,0,jogo.getSOvelha(),"maria",especie,linha,coluna,jogo.getReserva()->newId());
                        jogo.getReserva()->AddAnimal(tmp);
                        cout << "\nCria ovelha na linha:" << linha << " coluna:" << coluna;
                    } else if (especie == 'l'){
                        Lobo tmp(jogo.getPLobo(),0,jogo.getSLobo(),"maria",especie,linha,coluna,jogo.getReserva()->newId());
                        jogo.getReserva()->AddAnimal(tmp);
                        cout << "\nCria lobo na linha:" << linha << " coluna:" << coluna;
                    } else if (especie == 'g'){
                        Canguru tmp(jogo.getPCanguru(),0,jogo.getSCanguru(),"maria",especie,linha,coluna,jogo.getReserva()->newId());
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
                    jogo.getReserva()->mataAnimal(jogo.getReserva()->verificaLinhaColunaAnimal(linha,coluna));
                    cout << "\nAnimal morto!";
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
                Alimento tmp(10,0,20,tipo,linha,coluna,jogo.getReserva()->newId());
                jogo.getReserva()->AddAlimento(tmp);
                cout << "\nColocar alimento em posicao aleatoria!";
            }else{
                if(linha > jogo.getReserva()->getLinhas() || linha <= 0 || coluna <= 0 || coluna > jogo.getReserva()->getColunas())
                    cout << "\nFora da dimensao da reserva!";
                else{
                    Alimento tmp(10,0,20,tipo,linha,coluna,jogo.getReserva()->newId());
                    jogo.getReserva()->AddAlimento(tmp);
                    cout << "\nColocar alimento na linha:" << linha << " coluna:" << coluna;
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
            else
                cout << "\nComando valido!";
        }
    }else if(com == "feedid"){
        recebe >> id >> nutri >> toxi;
        if(recebe.fail()){
            cout << "\nComando invalido!";
        }else{
            if(jogo.getReserva()->procuraIdAnimal(id))
                cout << "\nComando valido!";
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
                if(jogo.getReserva()->procuraIdAlimento(linha))
                    cout << "\nRemover alimento com id:" << linha;
                else
                    cout << "\nNao existem alimentos com esse id!";
            } else{
                if(linha > jogo.getReserva()->getLinhas() || linha <= 0 || coluna <= 0 || coluna > jogo.getReserva()->getColunas())
                    cout << "\nFora da dimensao da reserva!";
                else
                    cout << "\nRemover alimento na linha:" << linha << " coluna:" << coluna;
            }
        }

    }else if(com == "empty"){
        recebe >> linha >> coluna;
        if(recebe.fail()){
            cout << "\nComando invalido!";
        }else{
            if(linha > jogo.getReserva()->getLinhas() || linha <= 0 || coluna <= 0 || coluna > jogo.getReserva()->getColunas())
                cout << "\nFora da dimensao da reserva!";
            else
                cout << "\nComando valido!";
        }
    }else if(com == "see"){
        recebe >> linha >> coluna;
        if(recebe.fail()){
            cout << "\nComando invalido!";
        }else{
            if(linha > jogo.getReserva()->getLinhas() || linha <= 0 || coluna <= 0 || coluna > jogo.getReserva()->getColunas())
                cout << "\nFora da dimensao da reserva!";
            else{
                cout << "\nComando valido!";
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
            cout << "\nPassa 1 instante";
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
        cout << "\nComando valido!";

    }else if(com == "visanim"){
        cout << "\nComando valido!";

    }else if(com == "store"){
        recebe >> nome;
        if(recebe.fail()){
            cout << "\nComando invalido!";
        }else{
            cout << "\nComando valido!";
        }

    }else if(com == "restore"){
        recebe >> nome;
        if(recebe.fail()){
            cout << "\nComando invalido!";
        }else{
            cout << "\nComando valido!";
        }

    }else if(com == "load"){
        recebe >> ficheiro;
        if(leficheiro(jogo,ficheiro)){
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

bool Simulador::leficheiro(Jogo &jogo, const string ficheiro) {
    ifstream comandos;
    string aux;
    comandos.open(ficheiro);

    if(comandos.is_open()){
        while(getline(comandos, aux))
        {
            istringstream recebe(aux);
            validaComando(jogo, recebe);
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