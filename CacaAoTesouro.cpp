/*
Espaço reservado para indexação de erros e Pendencias:
TODO: 

Bugs: nenhum encontrado até agora

*/

#include<iostream>
#include<iomanip>
#include<cmath>
#include<cctype>
#include<string>
#include<random>
#include<windows.h>
#define nl std::cout<<std::endl;
using namespace std;

char JOGADORES[4];

int INFOJOGADORES[3][3];
//linha 0 = linha
//linha 1 = coluna
//linha 2 = pontos
//coluna = index de cada jogador
const int TAMANHOMATRIZ = 30;
const int TAMANHOTUNEL = 90;
const int TAMANHOPROSSIGA = 45;
//facilitador para mudar o tamanho da matriz

char TABULEIRO_ESCONDIDO[TAMANHOMATRIZ][TAMANHOMATRIZ];
char TABULEIRO_MOSTRAR[TAMANHOMATRIZ][TAMANHOMATRIZ];


int DIAMANTES[3][300];
/*
DIAMANTES:
linha 0 = linha
linha 1 = coluna
linha 2 = quilate
coluna = cada diamante
*/


int TUNELSEMSAIDA[2][TAMANHOTUNEL];
//linha 0 = linha
//linha 1 = coluna
int PROSSIGA[2][TAMANHOPROSSIGA];
//linha 0 = linha
//linha 1 = coluna

int qtdJogadores=0;

void inicializarmatrizes(){
    for(int i=0;i<TAMANHOMATRIZ;i++){
        for(int j=0;j<TAMANHOMATRIZ;j++){
            TABULEIRO_ESCONDIDO[i][j] = ' ';
            TABULEIRO_MOSTRAR[i][j] = ' '; 
        }
    }

    for(int i=0; i<4; i++){
        JOGADORES[i] = '0';
    }

    for(int i=0; i < 3; i++){
        for(int j=0; j < 3; j++){
            INFOJOGADORES[i][j] = 0;
        }
    }
    
    for(int i=0; i < 2; i++){
        for(int j=0; j < 90; j++){
            TUNELSEMSAIDA[i][j] = 0;
        }
    }

    for(int i=0; i < 2; i++){
        for(int j=0; j < 45; j++){
            PROSSIGA[i][j] = 0;
        }
    }

}

bool encimaJogador(int linha, int coluna){
    for(int i=0; i < qtdJogadores; i++){
        if(TABULEIRO_MOSTRAR[linha][coluna] == JOGADORES[i]){
            return true;
        }
    }
    return false;
}

void visaoJogador(int linha, int coluna, int tamVisao){
    for(int i = -tamVisao; i <= tamVisao; i++){
        for(int j = -tamVisao; j <= tamVisao; j++){
            int linhaNova = linha + i;
            int colunaNova = coluna + j;
            int pos = TABULEIRO_ESCONDIDO[linhaNova][colunaNova];
            if((!encimaJogador(linhaNova, colunaNova)) and (pos != '+' or pos != '-' or pos != 'D' or pos != 'O')){
                TABULEIRO_MOSTRAR[linhaNova][colunaNova] = TABULEIRO_ESCONDIDO[linhaNova][colunaNova];
            }
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
        for (int j = 0; j < 30; j++){
            if (matrizParede[i][j] == 0){
                break;
            }
            int pos = matrizParede[i][j];
            TABULEIRO_ESCONDIDO[i][pos] = '-'; //alterar para TABULEIRO_ESCONDIDO
        }
    }

    for (int i = 0; i < 30; i++){
        for (int j = 0; j < 30; j++){
            if (TABULEIRO_ESCONDIDO[i][j] == '-'){//alterar para TABULEIRO_ESCONDIDO
                if(TABULEIRO_ESCONDIDO[i-1][j] == '-' or TABULEIRO_ESCONDIDO[i+1][j] == '-'){//alterar para TABULEIRO_ESCONDIDO
                    
                    TABULEIRO_ESCONDIDO[i][j] = '|';//alterar para TABULEIRO_ESCONDIDO
                }
                else if(TABULEIRO_ESCONDIDO[i-1][j] == '|' or TABULEIRO_MOSTRAR[i+1][j] == '|'){
                    TABULEIRO_ESCONDIDO[i][j] = '|';//alterar para TABULEIRO_ESCONDIDO
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

bool posicaoValida(int linha, int coluna){
    for(int i=0; i < qtdJogadores; i++){
        if(linha == INFOJOGADORES[0][i] and coluna == INFOJOGADORES[1][i]){
            cout << "Posicao invalida! Seu amigo esta ai!.\nTente novamente: ";
            return false;
        }
    }
    if(linha > 29 or linha < 0 or coluna > 29 or coluna < 0){
        cout << "Posicao invalida! Fora dos limites.\nTente novamente: ";
        return false;
    }
    else if(TABULEIRO_ESCONDIDO[linha][coluna] == '|' or TABULEIRO_ESCONDIDO[linha][coluna] == '-'){
        cout << "Posicao invalida! A Posicao e uma parede!.\nTente novamente: ";
        return false;
    }
    else{
        return true;
    }
}

void andar(int jogador){
    
    int linhaAtual = INFOJOGADORES[0][jogador];
    int colunaAtual = INFOJOGADORES[1][jogador];

    int linhaNova = linhaAtual;
    int colunaNova = colunaAtual;

    bool movimentoValido = false;

    
    do{
        char tecla;
        cin >> tecla;
        tecla = toupper(tecla);

        if(tecla == 'W'){
            linhaNova = linhaAtual - 1;
            colunaNova = colunaAtual;
            if(posicaoValida(linhaNova, colunaNova)){
                movimentoValido = true;
            }
            else{
                linhaNova = linhaAtual + 1;
                movimentoValido = false;
            }
        }
        else if(tecla == 'A'){
            colunaNova = colunaAtual - 1;
            linhaNova = linhaAtual;
            if(posicaoValida(linhaNova, colunaNova)){
                movimentoValido = true;
            }
            else{
                colunaNova = colunaAtual + 1;
                movimentoValido = false;
            }
        }
        else if(tecla == 'S'){
            linhaNova = linhaAtual + 1;
            colunaNova = colunaAtual;
            if(posicaoValida(linhaNova, colunaNova)){
                movimentoValido = true;
            }
            else{
                linhaNova = linhaAtual - 1;
                movimentoValido = false;
            }
        }
        else if(tecla == 'D'){
            colunaNova = colunaAtual + 1;
            linhaNova = linhaAtual;
            if(posicaoValida(linhaNova, colunaNova)){
                movimentoValido = true;
            }
            else{
                colunaNova = colunaAtual - 1;
                movimentoValido = false;
            }
        }
        else{
            cout << "Tecla invalida\n Tente novamente:";nl
            movimentoValido = false;
        }


    }while(!movimentoValido);

    visaoJogador(linhaNova,colunaNova,4);

    TABULEIRO_MOSTRAR[linhaNova][colunaNova] = JOGADORES[jogador];
    TABULEIRO_MOSTRAR[linhaAtual][colunaAtual] = ' ';

    TABULEIRO_ESCONDIDO[linhaAtual][colunaAtual] = ' ';
    TABULEIRO_ESCONDIDO[linhaNova][colunaNova] = TABULEIRO_MOSTRAR[linhaNova][colunaNova];

    INFOJOGADORES[0][jogador] = linhaNova;
    INFOJOGADORES[1][jogador] = colunaNova;

    //para checar se tem diamantes
    for(int j=0; j < 225; j++){
        if(linhaNova == DIAMANTES[0][j] and colunaNova == DIAMANTES[1][j]){
            INFOJOGADORES[2][jogador] += DIAMANTES[2][j];
            cout << "Parabens jogador " << JOGADORES[jogador] << "! \nDiamante encontrado!";nl
            cout << "O valor do diamante eh de " << DIAMANTES[2][j] << " quilates";nl
            DIAMANTES[0][j] = '\0';
            DIAMANTES[1][j] = '\0';
        }
    }
    //para checar se tem tunel
    for(int j=0; j < 90; j++){
        if(linhaNova == TUNELSEMSAIDA[0][j] and colunaNova == TUNELSEMSAIDA[1][j]){
            INFOJOGADORES[2][jogador] -= 10;
            cout << "Que pena jogador  " << JOGADORES[jogador] << "! \nVoce caiu em um tunel sem saida!";nl
            cout << "Voce perdeu 10 pontos";nl
            TUNELSEMSAIDA[0][j] = '\0';
            TUNELSEMSAIDA[1][j] = '\0';
        }
    }

    for(int j=0; j < 90; j++){
        if(linhaNova == PROSSIGA[0][j] and colunaNova == PROSSIGA[1][j]){
            INFOJOGADORES[2][jogador] += 3;
            cout << "Parabens jogador " << JOGADORES[jogador] << "! \nProssiga encontrado!";nl
            cout << "Voce ganhou 3 pontos";nl
            PROSSIGA[0][j] = '\0';
            PROSSIGA[1][j] = '\0';
        }
    }
}

void girarMatriz(){
    //Transposição da matriz
    for (int i = 0; i < TAMANHOMATRIZ; i++){
        for (int j = i + 1; j < TAMANHOMATRIZ; j++){
            swap(TABULEIRO_ESCONDIDO[i][j], TABULEIRO_ESCONDIDO[j][i]);
        }
    }

    //Inversão horizontal
    for(int i = 0; i < TAMANHOMATRIZ; i++){
        int l = 0; 
        int r = TAMANHOMATRIZ - 1;
        while (l < r){
            swap(TABULEIRO_ESCONDIDO[i][l], TABULEIRO_ESCONDIDO[i][r]);
            l++; 
            r--;
        }
    }

    //Troca de caracteres
    for(int i = 0; i < TAMANHOMATRIZ; i++){
        for(int j = 0; j < TAMANHOMATRIZ; j++){
            if(TABULEIRO_ESCONDIDO[i][j] == '|'){
                TABULEIRO_ESCONDIDO[i][j] = '-';
            }
            else if(TABULEIRO_ESCONDIDO[i][j] == '-'){
                TABULEIRO_ESCONDIDO[i][j] = '|';
            }
        }
    }

    cout << "Girando a matriz em 90 graus..." << endl;
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
    //linha 0 = linha
    //linha 1 = coluna
    //linha 2 = pontos
    //coluna = index de cada jogador
    switch(qtdJogadores){
        case 2:
            TABULEIRO_MOSTRAR[14][14] = JOGADORES[0]; 
            INFOJOGADORES[0][0] = 14; INFOJOGADORES[1][0] = 14; //estou aqui

            TABULEIRO_MOSTRAR[14][15] = JOGADORES[1]; 
            INFOJOGADORES[0][1] = 14; INFOJOGADORES[1][1] = 15;
            break;
        case 3:

            TABULEIRO_MOSTRAR[14][14] = JOGADORES[0]; 
            INFOJOGADORES[0][0] = 14; INFOJOGADORES[1][0] = 15;

            TABULEIRO_MOSTRAR[14][15] = JOGADORES[1]; 
            INFOJOGADORES[0][1] = 14; INFOJOGADORES[1][1] = 15;

            TABULEIRO_MOSTRAR[15][14] = JOGADORES[2]; 
            INFOJOGADORES[0][2] = 15; INFOJOGADORES[1][2] = 14;
            break;

        case 4:
            TABULEIRO_MOSTRAR[14][14] = JOGADORES[0]; 
            INFOJOGADORES[0][0] = 14; INFOJOGADORES[1][0] = 15;

            TABULEIRO_MOSTRAR[14][15] = JOGADORES[1]; 
            INFOJOGADORES[0][1] = 14; INFOJOGADORES[1][1] = 15;

            TABULEIRO_MOSTRAR[15][14] = JOGADORES[2]; 
            INFOJOGADORES[0][2] = 15; INFOJOGADORES[1][2] = 14;

            TABULEIRO_MOSTRAR[15][15] = JOGADORES[3]; 
            INFOJOGADORES[0][3] = 15; INFOJOGADORES[1][3] = 15;
            break;
    }
}

bool interativosErrados(int linha, int coluna){
    for(int i=0; i < 225; i++){
        if(linha == DIAMANTES[0][i] and coluna == DIAMANTES[1][i]){
            return true;
        }
    }
    for(int i=0; i < TAMANHOPROSSIGA; i++){
        if(linha == PROSSIGA[0][i] and coluna == PROSSIGA[1][i]){
            return true;
        }
    }
    for(int i=0; i < TAMANHOTUNEL; i++){
        if(linha == TUNELSEMSAIDA[0][i] and coluna == TUNELSEMSAIDA[1][i]){
            return true;
        }
    }
    if(TABULEIRO_MOSTRAR[linha][coluna] == '|' or TABULEIRO_MOSTRAR[linha][coluna] == '-'){
            return true;
    }
    else{
        for(int i=0; i < 4; i++){
            if(TABULEIRO_MOSTRAR[linha][coluna] == JOGADORES[i]){
                return true;
            }
        }
    }
    return false;
}

void colocarInterativos() {
    for (int i=0; i < 300; i++){
        int Ldiamante, Cdiamante;

        do{
            Ldiamante = random(0, TAMANHOMATRIZ-1);
            Cdiamante = random(0, TAMANHOMATRIZ-1);
        }while(interativosErrados(Ldiamante,Cdiamante));

        int quilateDiamante = random(1, 10);

        //TABULEIRO_ESCONDIDO[Ldiamante][Cdiamante] = '1'; // retirar depois

        DIAMANTES[0][i] = Ldiamante;
        DIAMANTES[1][i] = Cdiamante;
        DIAMANTES[2][i] = quilateDiamante;
    }

    for (int i=0; i < 90; i++){
        int Ltunel, Ctunel;

        do{
            Ltunel = random(0, TAMANHOMATRIZ-1);
            Ctunel = random(0, TAMANHOMATRIZ-1);
        }while(interativosErrados(Ltunel,Ctunel));


        TUNELSEMSAIDA[0][i] = Ltunel;
        TUNELSEMSAIDA[1][i] = Ctunel;
    }

    for (int i=0; i < 45; i++){
        int Lprossiga, Cprossiga;

        do{
            Lprossiga = random(0, TAMANHOMATRIZ-1);
            Cprossiga = random(0, TAMANHOMATRIZ-1);
        }while(interativosErrados(Lprossiga,Cprossiga));


        TUNELSEMSAIDA[0][i] = Lprossiga;
        TUNELSEMSAIDA[1][i] = Cprossiga;
    }
}

bool inicialValida(char c){
    for(int i=0; i < qtdJogadores; i++){
        if(c == JOGADORES[i]){
            return false;
        }
    }
    if(c == '|' or c == '-'){
        return false;
    }
    return true;
}

bool vitoria(){
    for(int i=0; i < qtdJogadores; i++){
        if(INFOJOGADORES[2][i] >= 50){
            cout << "Jogador " << JOGADORES[i] << " Venceu!";nl
            cout << "Parabens!";nl
            return true;
        }
    }
    return false;
}

void tabuleiro(){
    cout << "--------------------------------------------------------------------------------------------------------------------------" <<endl;
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
        cout << "Pontos Jogador " << JOGADORES[i] << ": " << INFOJOGADORES[2][i];
        nl
    }
    cout << "--------------------------------------------------------------------------------------------------------------------------" <<endl;
}

int main(){
    //colocar mensagem de introdução
    inicializarmatrizes();


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
            cout << "Lembre-se, a inicial nao pode ser igual a ";
            cout << "qualquer outra inicial ja usada.";nl
            cout << "Contudo, eh possivel existir uma inicial em caixa alta e em caixa baixa ao mesmo tempo.";nl
            cin >> inicial;
        }while(!(inicialValida(inicial)));
        JOGADORES[i] = inicial;
    }

    layout();
    aleatorizarCaverna();
    colocarInterativos();
    deployPlayers();

    
    int jogadorAtual = 0;
    do{

        tabuleiro();
        cout << "Vez do jogador " << JOGADORES[jogadorAtual];nl
        cout << "(w,a,s ou d) para se mover:";
        andar(jogadorAtual);
        jogadorAtual = (jogadorAtual + 1) % qtdJogadores;

    }while(!vitoria());

    cout << "Fim de Jogo, Obrigado por Jogar.";nl
    cout << "Jogo produzido por Pedro Castello e Patrick Correa como projeto\ndo final do primeiro periodo de faculdade na UNICENTRO Guarapuava";nl

    Sleep(30);

    return 0;
}
