/*
O codigo tem um ero nas linhas 43-46, quando 4 jogadores são selecionados, a ultima inicial vira os pontos do indice 1 do vetor JOGADORES
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

char TABULEIRO [6][6];
int tamTABULEIRO = sizeof(TABULEIRO)/ sizeof(TABULEIRO[0]); //facilitador para aumentar o tamanho da matriz


void tabuleiro(int qtdJogadores){
    cout << "--------------------------------------------------------" <<endl;
    //colocar identificadores
    cout << " #  A B C D E F";
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
            cout << TABULEIRO[i][j] << " ";
        }
    }
    nl nl

    for(int i=0; i < qtdJogadores; i++){
        cout << "Pontos Jogador " << i+1 << ": " << PONTOS[i];
        nl
    }

}

int random(int min, int max) {
    // Usando uma seed baseada no tempo do sistema
    static mt19937 gen(static_cast<unsigned int>(time(nullptr)));
    uniform_int_distribution<> dis(min, max);

    return dis(gen);
}

int main() {
    int qtdJogadores=0;
    //coloca 0 em todas as posiçoes
    for(int i=0;i<tamTABULEIRO;i++){
        for(int j=0;j<tamTABULEIRO;j++){
            TABULEIRO[i][j] = '0';
        }
    }

    while(qtdJogadores < 2 or qtdJogadores > 4){
        cout << "Indique a quantidade de jogadores(entre 2 e 4): ";
        cin >> qtdJogadores;
    }
        cout << "Jogadores selecionados: " << qtdJogadores;
        nl
    
    for(int i=1; i < qtdJogadores+1; i++){
        cout << "Jogador " << i << " indique sua inicial";nl
        cout << "Sua Inicial sera sua identificacao,";
        cout << " entao coloquem iniciais diferentes";nl
        cin >> JOGADORES[i];
    }
    
    for(int i=0; i < 4; i++){
        cout << JOGADORES[i];
        nl
    }

    tabuleiro(qtdJogadores);

    return 0;
}




