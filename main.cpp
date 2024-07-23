/*
Espaço reservado para indexação de erros e Pendencias:
TODO: colocar os jogadores em posição.
TODO: fazer o layout




*/

#include<iostream>
#include<iomanip>
#include<cmath>
#include<cctype>
#include<string>
#include<random>
#include<cstdlib>
#define nl cout<<endl;
using namespace std;

char JOGADORES[4] = {'\0','\0','\0','\0'};
int PONTOS[4];

char TABULEIRO [20][20];


/*
DIAMANTES:
linha 0 = linha
linha 1 = coluna
linha 2 = quilate
*/
int DIAMANTES [3][300];


int tamTABULEIRO = sizeof(TABULEIRO)/sizeof(TABULEIRO[0]); //facilitador para mudar o tamanho da matriz

int random(int min, int max) {
    // Usando uma seed baseada no tempo do sistema
    static mt19937 gen(static_cast<unsigned int>(time(nullptr)));
    uniform_int_distribution<> dis(min, max);

    return dis(gen);
}



void colocarDiamantes(){
    //25% = 100
    for(int i=0; i < 100; i++){
        int quilateDiamante = random(1,10);
        int Ldiamante = random(0, 20);
        int Cdiamante = random(0, 20);
        TABULEIRO[Ldiamante][Cdiamante] = 'D'; //retirar depois

        DIAMANTES[0][i] = Ldiamante;
        DIAMANTES[1][i] = Cdiamante;
        DIAMANTES[2][i] = quilateDiamante;

    }
}

bool posicaoValida(char c, int qtdjogadores){
    for(int i=0; i < qtdjogadores; i++){
        if(c == JOGADORES[i]){
            return false;
        }
    }
    return true;
}


void tabuleiro(int qtdJogadores){
    cout << "-----------------------------------------------------------------------------------------------------------------------" <<endl;
    //colocar identificadores
    cout << " #  A  B  C  D  E  F  G  H  I  J  K  L  M  N  O  P  Q  R  S  T";
    int p=1;
    for(int i=0; i<tamTABULEIRO; i++){
        if(p<10){
        cout <<endl;
        cout << " " << p << " |";
        }
        else{
        cout <<endl;
        cout << p << " |";
        }
        p++;
        for(int j=0; j<tamTABULEIRO; j++){
            cout << TABULEIRO[i][j] << "  ";
        }
    }
    nl nl

    for(int i=0; i < qtdJogadores; i++){
        cout << "Pontos Jogador " << JOGADORES[i] << ": " << PONTOS[i];
        nl
    }
    cout << "-----------------------------------------------------------------------------------------------------------------------" <<endl;
}


int main() {
    int qtdJogadores=0;
    //coloca 0 em todas as posiçoes
    for(int i=0;i<tamTABULEIRO;i++){
        for(int j=0;j<tamTABULEIRO;j++){
            TABULEIRO[i][j] = '0';
        }
    }
    /*

    // para imprimir barras entre os quadrantes, se necessario

    for(int i=3; i < tamTABULEIRO; i+=4){
        for(int j=0; j < tamTABULEIRO; j++){
            TABULEIRO[i][j] = '-';
        }
    }

    for(int i=0; i < tamTABULEIRO; i++){
        for(int j=3; j < tamTABULEIRO; j+=4){
            TABULEIRO[i][j] = '|';
        }
    }
    */

    while(qtdJogadores < 2 or qtdJogadores > 4){
        cout << "Indique a quantidade de jogadores(entre 2 e 4): ";
        cin >> qtdJogadores;
    }
        cout << "Jogadores selecionados: " << qtdJogadores;
        nl


    cout << "Suas Iniciais serao suas identificacoes,";
    cout << " portanto, coloquem iniciais diferentes";nl
    
    for(int i=0; i < qtdJogadores; i++){
        cout << "Jogador " << i+1 << " indique sua inicial";nl
        char inicial;
        do{
            cout << "Debug";nl
            cin >> inicial;
            cout << "Debug " << inicial;nl
        }while(!(posicaoValida(inicial, qtdJogadores)));
        JOGADORES[i] = inicial;
    }
    

    tabuleiro(qtdJogadores);

    return 0;
}




