#ifndef POOTP_RESERVA_H
#define POOTP_RESERVA_H

#include "Animal.h"
#include <sstream>
#include <string>
#include <iostream>
#include <cstdlib>
#include <vector>
#include "Corpo.h"
#include "Coelho.h"
#include "Ovelha.h"
#include "Lobo.h"
#include "Canguru.h"
#include "Cavalo.h"
#include "Maca.h"
#include "Relva.h"
#include "Cenoura.h"
#include "Bife.h"

using namespace std;

class Reserva {
public:
    Reserva(int nl, int nc); //Construtor
    Reserva(const Reserva &obj); //Construtor por cópia
    ~Reserva(); //Destrutor
    //Obtem variáveis constantes - que serão declaradas no ficheiro constantes.txt
    int getSCoelho() const{return SCoelho;}
    int getVCoelho() const{return VCoelho;}
    int getSOvelha() const{return SOvelha;}
    int getVOvelha() const{return VOvelha;}
    int getSLobo() const{return SLobo;}
    int getVLobo() const{return VLobo;}
    int getPLobo() const{return PLobo;}
    int getSCanguru() const{return SCanguru;}
    int getVCanguru() const{return VCanguru;}
    int getPCanguru() const{return PCanguru;}
    int getSCavalo() const{return SCavalo;}
    int getVCavalo() const{return VCavalo;}
    int getPCavalo() const{return PCavalo;}
    int getVRelva() const{return VRelva;}
    int getVBife() const{return VBife;}
    int getVMaca() const{return VMaca;}
    void setConstantes(istringstream &recebe); //Lê ficheiro constantes.txt e retira os valores das variáveis
    int getLinhas() const{return NL;} //Get nº linhas
    int getColunas() const{return NC;} //Get nº colunas
    void AddAnimal(Animal *a); //Adiciona animal à lista de animais na reserva
    void AddAlimento(Alimento *a); //Adiciona alimento à lista de alimentos na reserva
    void eliminaAnimal(int num); //Elimina animal da lista de animais na reserva
    void eliminaAlimento(int num); //Elimina alimentos da lista de alimentos na reserva
    string getAsString() const; //Odtem descrição da reserva
    int newId(); //Incrementa o id global
    bool procuraIdAnimal(int id) const; //Procura animal na reserva por Id
    bool procuraIdAlimento(int id) const; //Procura alimento na reserva por Id
    string listAnimal(int id) const; //Descricao de um animal por Id
    string listAlimento(int id) const; //Descricao de um alimento por Id
    int verificaLinhaColunaAnimal(int nl, int nc) const; //Verifica se existe um animal na linha e coluna recebidas
    int verificaLinhaColunaAlimento(int nl, int nc) const; //Verifica se existe um alimento na linha e coluna recebidas
    void mataAnimal(int num); //Mata animal por Id
    void mataAnimal(int nl, int nc); //Mata animal numa dada posição
    bool removeAlimento(int num); //Remove alimento por Id
    void alimentaAnimal(int num, int nutri, int toxi, char t = 0); //Alimenta um animal com Id = num
    void alimentaAnimal(int nl, int nc, int nutri, int toxi); //Alimenta animal/animais na posicao (linha=nl, coluna=nc)
    string listPosicao(int nl, int nc)const; //Faz descrição da posição (linha=nl, coluna=nc)
    string ComandoAnim() const; //Mostra o Id, Especie e Saude para todos os animais na reserva
    char especieAnimal(int nl, int nc) const; //Retorna a especie de animal na posição nl x nc
    char tipoAlimento(int nl, int nc) const; //Retorna o tipo de alimento na posição nl x nc
    void movimentaAnimais(); //Lança as funções responsáveis pelos movimentos de cada especie de animal
    void AumentaFomeAnimais(); //Aumenta a fome dos animais na reserva
    void DiminuiDuracaoAlimentos(); //Diminui a duracao dos alimentos na reserva
    void DiminuiVinstantes(); //Diminui os instantes de vida limite de cada animal
    void AumentaInstantesDecorridosAnimal(); //Aumenta o nº de instantes vividos por cada animal
    void verificaSaude(); //Verifica se o animal ainda está vivo, caso contrário é removido da reserva
    void updateNutriToxiAlimentos(); //Atualiza o valor da nutrição e toxicidade de cada alimento
    string printHistAlimentacaoAnimal(int num) const; //print historico de alimentação de um animal com id = num - Função utilizada apenas para teste
    bool verificaOcupacaoEspaco(int nl, int nc); //Verifica se a posição ainda tem espaço para animais
    bool verificaOcupacaoEspacoAlimento(int nl, int nc); //Verifica se a posição ainda tem espaço para um alimento
    void FazNascer(); //Responsavel por fazer nascer novos animais a partir de animais já existentes
    int TotalAnimais(); //Conta o total de animais
    int TotalAlimentos(); //Conta o total de alimentos
    int numElementosPorPosicao(int nl, int nc);
    string CheiroDoAlimento(int nl, int nc);
    //bool animalSegueAlimento(int num);
    bool EncontraAnimalPesado(int num, int nl, int nc, int m) const;

private:
    int NL; //Nº de linhas
    int NC; //Nº de colunas
    int id = 1; //Id global
    vector<Animal*> animais; //lista de animais na reserva
    vector<Alimento*> alimentos; //lista de alimentos na reserva
    //variáveis definidas pelo ficheiro constantes.txt
    int SCoelho;
    int VCoelho;
    int SOvelha;
    int VOvelha;
    int SLobo;
    int VLobo;
    int PLobo;
    int SCanguru;
    int VCanguru;
    int PCanguru;
    int SCavalo;
    int VCavalo;
    int PCavalo;
    int VRelva;
    int VBife;
    int VMaca;
};


#endif //POOTP_RESERVA_H
