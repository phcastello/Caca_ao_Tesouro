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

char TABULEIRO_ESCONDIDO [20][20] = {0};


/*
DIAMANTES:
linha 0 = linha
linha 1 = coluna
linha 2 = quilate
*/
int DIAMANTES [3][300];


int tamTABULEIRO_ESCONDIDO = sizeof(TABULEIRO_ESCONDIDO)/sizeof(TABULEIRO_ESCONDIDO[0]); //facilitador para mudar o tamanho da matriz

int random(int min, int max){
    /*
    A função gera um numero aleatorio num intervalo entre as variaveis min e max.

    Static faz a variavel geracao ser inicializada uma unica vez, mesmo que a funçao seja chamada outras vezes.
    Ela é necessaria para que o valor aleatorio seja diferente a cada vez que a função seja chamada.
    Foi escolhida pelo criterio de organização do codigo. 

    mt19937 é um algoritmo de de numeros pseudo-aleatorios "Mersenne Twister".

    time(nullptr) retorna o tempo atual do sistema em segundos, a partir de 1 de janeiro de 1970

    (static_cast<unsigned int>(time(nullptr))) converte time(nullptr) em um inteiro sem sinal, isso é necessario pois
    mt19937 espera um inteiro sem sinal como parametro.

    static_cast é usado para converter com segurança dois tipos de dados (no caso de int para unsigned int)

    uniform_int_distribution<> garante que todo numero do intervalo tenha a mesma chance de ser escolhido

    distNormal(min, max) inicializa a distribuição para gerar numeros aleatorios inteiros no intervalo dado

    a função retorna o numero aleatorio da função
    */


    static mt19937 geracao(static_cast<unsigned int>(time(nullptr)));
    uniform_int_distribution<> distNormal(min, max);

    return distNormal(geracao);
}

void iniciarTabuleiro(){
    for(int i=0;i<tamTABULEIRO_ESCONDIDO;i++){
        for(int j=0;j<tamTABULEIRO_ESCONDIDO;j++){
            TABULEIRO_ESCONDIDO[i][j] = ' ';
        }
    }
    TABULEIRO_ESCONDIDO[20][6] = '|';

}

void colocarDiamantes(){
    //25% = 100
    for(int i=0; i < 100; i++){
        int quilateDiamante = random(1,10);
        int Ldiamante = random(0, 20);
        int Cdiamante = random(0, 20);
        //TABULEIRO[Ldiamante][Cdiamante] = 'D'; //retirar depois

        DIAMANTES[0][i] = Ldiamante;
        DIAMANTES[1][i] = Cdiamante;
        DIAMANTES[2][i] = quilateDiamante;

    }
}

bool inicialValida(char c, int qtdjogadores){
    for(int i=0; i < qtdjogadores; i++){
        if(c == JOGADORES[i]){
            return false;
        }
    }
    if(c == '+' or c == '-' or c == 'D' or c == 'O'){
        return false;
    }
    return true;
}

void colocarJogadores(){}

void tabuleiro(int qtdJogadores){
    cout << "----------------------------------------------------------------------------------------------" <<endl;
    //colocar identificadores
    cout << " #  A  B  C  D  E  F  G  H  I  J  K  L  M  N  O  P  Q  R  S  T";
    int contador=1;
    for(int i=0; i<tamTABULEIRO_ESCONDIDO; i++){
        if(contador<10){
        cout <<endl;
        cout << " " << contador << " |";
        }
        else{
        cout <<endl;
        cout << contador << " |";
        }
        contador++;
        for(int j=0; j<tamTABULEIRO_ESCONDIDO; j++){
            cout << TABULEIRO_ESCONDIDO[i][j];
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

    while(qtdJogadores < 2 or qtdJogadores > 4){
        cout << "Indique a quantidade de jogadores(entre 2 e 4): ";
        cin >> qtdJogadores;
    }
        cout << "Jogadores selecionados: " << qtdJogadores;
        nl


    cout << "Suas Iniciais serao suas identificacoes,";
    cout << " portanto, coloquem iniciais diferentes.";nl
    
    for(int i=0; i < qtdJogadores; i++){
        cout << "Jogador " << i+1 << " indique sua inicial";nl
        char inicial;
        do{
            cout << "Lembre-se, a inicial nao pode ser igual a:";
            cout << "'+', '-', 'D', 'O' e qualquer outra inicial ja usada.";nl
            cout << "podem existir uma inicial em caixa alta e em caixa baixa.";nl
            cin >> inicial;
        }while(!(inicialValida(inicial, qtdJogadores)));
        JOGADORES[i] = inicial;
    }
    

    tabuleiro(qtdJogadores);
    colocarDiamantes();


    return 0;
}




