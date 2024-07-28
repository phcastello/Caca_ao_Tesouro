/*
Espaço reservado para indexação de erros e Pendencias:
TODO: colocar os jogadores em posição.
TODO: implementar o layout
TODO: função para que a matriz principal seja atualizada conforme os jogadores se deslocam




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

}
/*
int random(int min, int max){
    
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
    


    static mt19937 geracao(static_cast<unsigned int>(time(nullptr)));
    uniform_int_distribution<> distNormal(min, max);

    return distNormal(geracao);
}
*/

int random(int min, int max){
    int n_aleatorio = min+rand()%max;
    return n_aleatorio;
}


void girarMatriz(){
    for (int i = 0; i < TAMANHOMATRIZ; i++) {
        for (int j = 0; j < TAMANHOMATRIZ; j++) {
            swap(TABULEIRO_MOSTRAR[i][j], TABULEIRO_MOSTRAR[j][i]); //trocar para TABULEIRO_ESCONDIDO
        }
    }
    for(int i=0; i < TAMANHOMATRIZ; i++){
        int l=0; int r = TAMANHOMATRIZ - 1;
        while (l < r){
            swap(TABULEIRO_MOSTRAR[i][l],TABULEIRO_MOSTRAR[i][r]); //trocar para TABULEIRO_ESCONDIDO
            l++; r--;
        }
    }
    cout << "Girando a matriz em 90 graus...";nl
}

void caverna(){
    int var = random(1,4);
    switch(var){
        case '1':
            girarMatriz();
            break;
        case '2':
            girarMatriz();
            girarMatriz();
            break;
        case '3':
            girarMatriz();
            girarMatriz();
            girarMatriz();
            break;
        default:
            break;
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
        int Ldiamante = random(0, 20);
        int Cdiamante = random(0, 20);
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
    cout << " Apos igualar as duas matrizes";
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
    girarMatriz();
    tabuleiro();

    return 0;
}
