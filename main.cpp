/*
Espaço reservado para indexação de erros e Pendencias:
TODO: colocar os jogadores em posição.
TODO: implementar o layout
TODO: função para que a matriz principal seja atualizada conforme os jogadores se deslocam
TODO: função que checa uma movimentação valida do player
TODO: funçao que move o player
TODO: função que transforma letra em numero para as coordenadas
TODO: função para colocar armadilha e buffs


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

char JOGADORES[4] = {'\0'};
int PONTOS[4] ={0};

char TABULEIRO_ESCONDIDO [30][30];
char TABULEIRO_MOSTRAR [30][30];

/*
DIAMANTES:
linha 0 = linha
linha 1 = coluna
linha 2 = quilate
*/
int DIAMANTES [3][300];


int TAMANHOMATRIZ = sizeof(TABULEIRO_ESCONDIDO)/sizeof(TABULEIRO_ESCONDIDO[0]); 
//facilitador para mudar o tamanho da matriz

int qtdJogadores=0;

void inicializarmatrizes(){
    for(int i=0;i<TAMANHOMATRIZ;i++){
        for(int j=0;j<TAMANHOMATRIZ;j++){
            TABULEIRO_ESCONDIDO[i][j] = '0';
            TABULEIRO_MOSTRAR[i][j] = '0'; //alterar de '0' para um espaço ' '
        }
    }
}

void layout(){
    int matrizParede[30][30] = {
        {4},
        {2,4,7,8,9,14,15,16,19,20,21,22,23,24,26,27},
        {1,2,7,9,16,17,18,19,24,26,28},
        {7,9,19,20,21,22,24,26,28},
        {0,1,12,13,14,22,24,26},
        {5,13,18,19,20,24,26,27},
        {5,6,11,18,20,21,27,28},
        {1,2,3,5,10,11,15,17,18,21,23,25},
        {1,3,7,10,13,14,15,17,20,21,23,24,25},
        {4,7,10,11,13,16,17,20},
        {3,4,11,15,16,23,24,25},
        {1,4,6,11,14,15,18,23,28},
        {1,4,6,7,8,14,18,19,23,24,27,28},
        {4,8,24,28},
        {1,8,10,11,20,21,22,24},
        {1,3,8,11,12,20,22,27,28},
        {1,3,4,22,23,27},
        {1,4,11,18,27},
        {1,2,4,5,10,11,14,17,18,21,25,27},
        {2,5,10,14,17,21,25},
        {7,10,11,14,15,17,21,22},
        {0,1,2,3,6,7,10,11,15,16,17,24,25,26},
        {3,6,10,20,22,24,28,29},
        {1,2,3,6,7,8,11,18,19,22,24,26,27,28},
        {1,8,11,14,19,20,21,22,26},
        {7,8,10,11,14,24,28,29},
        {10,14,15,24,25,26},
        {4,5,9,10,11,12,18,19,24,26,27,28},
        {1,24,10,17,18,28},
        {1},
    };

    for (int i = 0; i < 30; i++){
        for (int j = 0; j < 30; i++){
            if (matrizParede[i][j] == 0){
                break;
            }
            int pos = matrizParede[i][j];
            TABULEIRO_MOSTRAR[i][pos] = '-'; //alterar para TABULEIRO_ESCONDIDO
        }
    }

    for (int i = 0; i < 30; i++){
        for (int j = 0; j < 30; i++){
            if (TABULEIRO_MOSTRAR[i][j] == '-'){//alterar para TABULEIRO_ESCONDIDO
                if(TABULEIRO_MOSTRAR[i-1][j] == '-' or TABULEIRO_MOSTRAR[i+1][j] == '-'){//alterar para TABULEIRO_ESCONDIDO
                    TABULEIRO_MOSTRAR[i][j] = '|';//alterar para TABULEIRO_ESCONDIDO
                }
            }
        }
    }

}

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

/*
int random(int min, int max){
    int n_aleatorio = min+rand()%max;
    return n_aleatorio;
}
*/

void girarMatriz(){
    for (int i = 0; i < TAMANHOMATRIZ; i++){
        for (int j = 0; j < TAMANHOMATRIZ; j++){
            swap(TABULEIRO_MOSTRAR[i][j], TABULEIRO_MOSTRAR[j][i]); //alterar para TABULEIRO_ESCONDIDO
        }
    }
    for(int i=0; i < TAMANHOMATRIZ; i++){
        int l=0; int r = TAMANHOMATRIZ - 1;
        while (l < r){
            swap(TABULEIRO_MOSTRAR[i][l],TABULEIRO_MOSTRAR[i][r]); //alterar para TABULEIRO_ESCONDIDO
            l++; r--;
        }
    }
    for(int i=0; i < TAMANHOMATRIZ; i++){
        for(int j=0; j < TAMANHOMATRIZ; j++){
            if(TABULEIRO_ESCONDIDO[i][j] == '|'){
                TABULEIRO_ESCONDIDO[i][j] = '-';
            }
            if(TABULEIRO_ESCONDIDO[i][j] == '-'){
                TABULEIRO_ESCONDIDO[i][j] = '|';
            }
        }
    }
    cout << "Girando a matriz em 90 graus...";nl
}

void aleatorizarCaverna(){
    int var = random(1,4);
    cout << "valor randomico da orientacao da matriz: " << var;nl
    if(var == 1){
        girarMatriz();
    }
    else if(var == 2){
        girarMatriz();
        girarMatriz();
    }
    else if(var == 3){
        girarMatriz();
        girarMatriz();
        girarMatriz();
    }
}

void deployPlayers(){
    switch(qtdJogadores){
        case 2:
            TABULEIRO_MOSTRAR[14][14] = JOGADORES[0];
            TABULEIRO_MOSTRAR[14][15] = JOGADORES[1];
            break;

        case 3:

            TABULEIRO_MOSTRAR[14][14] = JOGADORES[0];
            TABULEIRO_MOSTRAR[14][15] = JOGADORES[1];
            TABULEIRO_MOSTRAR[15][14] = JOGADORES[2];
            break;

        case 4:
            TABULEIRO_MOSTRAR[14][14] = JOGADORES[0];
            TABULEIRO_MOSTRAR[14][15] = JOGADORES[1];
            TABULEIRO_MOSTRAR[15][14] = JOGADORES[2];
            TABULEIRO_MOSTRAR[15][15] = JOGADORES[3];
            break;
    }
}

void colocarDiamantes(){
    //25% = 100
    for(int i=0; i < 100; i++){
        int quilateDiamante = random(1,10);
        int Ldiamante = random(0, 30);
        int Cdiamante = random(0, 30);
        TABULEIRO_MOSTRAR[Ldiamante][Cdiamante] = '1'; //retirar depois

        DIAMANTES[0][i] = Ldiamante;
        DIAMANTES[1][i] = Cdiamante;
        DIAMANTES[2][i] = quilateDiamante;

    }
}

bool inicialValida(char c){
    for(int i=0; i < qtdJogadores; i++){
        if(c == JOGADORES[i]){
            return false;
        }
    }
    if(c == '+' or c == '-' or c == 'D' or c == 'O'){
        return false;
    }
    return true;
}

void tabuleiro(){
    cout << "--------------------------------------------------------------------------------------------------------------------------" <<endl;
    //colocar identificadores
    cout << " #  AA AB AC AD AE AF AG AH AI AJ AK AL AM AN AO AP AQ AR AS AT AU AV AW AX AY AZ BA BB BC BD";
    int contador=1;
    for(int i=0; i<TAMANHOMATRIZ; i++){
        if(contador<10){
        cout <<endl;
        cout << " " << contador << " |";
        }
        else{
        cout <<endl;
        cout << contador << " |";
        }
        contador++;
        for(int j=0; j<TAMANHOMATRIZ; j++){
            cout << TABULEIRO_MOSTRAR[i][j] << "  ";
        }
    }
    nl nl

    for(int i=0; i < qtdJogadores; i++){
        cout << "Pontos Jogador " << JOGADORES[i] << ": " << PONTOS[i];
        nl
    }
    cout << "--------------------------------------------------------------------------------------------------------------------------" <<endl;
}


int main(){
    //colocar mensagem de introdução
    inicializarmatrizes();

    //retirar depois
    for(int i=0; i < TAMANHOMATRIZ; i++){
        for(int j=0; j < TAMANHOMATRIZ; j++){
            TABULEIRO_MOSTRAR[i][j] = TABULEIRO_ESCONDIDO[i][j];
        }
    }
    //retirar depois

    while(qtdJogadores < 2 or qtdJogadores > 4){
        cout << "Indique a quantidade de jogadores(entre 2 e 4): ";
        cin >> qtdJogadores;
    }

    cout << "Jogadores selecionados: " << qtdJogadores;nl

    cout << "Suas Iniciais serao suas identificacoes,";
    cout << " portanto, coloquem iniciais diferentes.";nl
    
    for(int i=0; i < qtdJogadores; i++){
        cout << "Jogador " << i+1 << " indique sua inicial";nl
        char inicial;
        do{
            cout << "Lembre-se, a inicial nao pode ser igual a:";
            cout << "'+', '-', 'D', 'O' e qualquer outra inicial ja usada.";
            cout << " Contudo, eh possivel existir uma inicial em caixa alta e em caixa baixa ao mesmo tempo.";nl
            cin >> inicial;
        }while(!(inicialValida(inicial)));
        JOGADORES[i] = inicial;
    }

    
    colocarDiamantes();
    tabuleiro();
    aleatorizarCaverna();
    tabuleiro();

    return 0;
}
