#include<iostream>
#include<iomanip>
#include<cmath>
#include<cctype>
#include<string>
#include<random>
#include<cstdlib>
#define nl cout<<endl;
using namespace std;

char TABULEIRO [10][10];
int tamTABULEIRO = sizeof(TABULEIRO)/ sizeof(TABULEIRO[0]);
/*
void traducao(string str){
    char str[2];
    cout << "Digite a posicao inicial do barco (Ex: A1): ";
    cin >> str;
    j = str[0];
    i = str[1] - '0';
}
*/

void tabuleiro(){
    cout << "-------------------------------------------------------" <<endl;
    //colocar identificadores
    cout << " #  A B C D E F G H I J K L M N O";
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
}

int random(int min, int max) {
    // Usando uma seed baseada no tempo do sistema
    static mt19937 gen(static_cast<unsigned int>(time(nullptr)));
    uniform_int_distribution<> dis(min, max);

    return dis(gen);
}

int main() {
    //coloca 0 em todas as posiçoes
    for(int i=0;i<tamTABULEIRO;i++){
        for(int j=0;j<tamTABULEIRO;j++){
            TABULEIRO[i][j] = '0';
        }
    }

    tabuleiro();

    return 0;
}




