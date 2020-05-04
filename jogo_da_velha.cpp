#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

void tabuleiro(char a[]){
    for(int i = 0; i < 9; i = i + 3){
        cout << "[" << a[i] << "]" << "[" << a[i+1] << "]" << "[" << a[i+2] << "]" << endl;
    }
}

void tabmod(int a[]){
    for(int i = 0; i < 9; i = i + 3){
        cout << "[" << a[i] << "]" << "[" << a[i+1] << "]" << "[" << a[i+2] << "]" << endl;
    }
}

int vencedor(char a[], int b){

    //Análise das Colunas

    for(int i = 0; i < 3; i++){
        if(a[i] == 'X' && a[i+3] == 'X' && a[i+6] == 'X'){
            b = 1;
        }
    }

    for(int i = 0; i < 3; i++){
        if(a[i] == 'O' && a[i+3] == 'O' && a[i+6] == 'O'){
            b = 1;
        }
    }

    //Análise das Linhas

    for(int i = 0; i <= 6;i = i + 3){
        if(a[i] == 'X' && a[i+1] == 'X' && a[i+2] == 'X'){
            b = 1;
        }
    }

    for(int i = 0; i <= 6;i = i + 3){
        if(a[i] == 'O' && a[i+1] == 'O' && a[i+2] == 'O'){
            b = 1;
        }
    }

    //Análise das Diagonais

    if(a[0] == 'X' && a[4] == 'X' && a[8] == 'X'){
        b = 1;
    }
    if(a[2] == 'X' && a[4] == 'X' && a[6] == 'X'){
        b = 1;
    }
    if(a[0] == 'O' && a[4] == 'O' && a[8] == 'O'){
        b = 1;
    }
    if(a[2] =='O' && a[4] == 'O' && a[6] == 'O'){
        b = 1;
    }

    return b;
}

void LimparTela(){
    system("clear || cls");
}

void jogadaX(char a[], int b, int c){
    cin >> b; c++;
    if(a[b] == 'X' || a[b] == 'O'){
        cout << "Opcao Invalida";
        jogadaX(a,b,c);
    }
    else if(a[b] != 'X' || a[b] != 'O'){
        a[b] = 'X';
    }
}

void jogadaO(char a[], int b, int c){
    cin >> b; c++;
    if(a[b] == 'X' || a[b] == 'O'){
        cout << "Opcao Invalida";
        jogadaX(a,b,c);
    }
    else if(a[b] != 'X' || a[b] != 'O'){
        a[b] = 'O';
    }
}

int main (){

    char jogo[9], jogador, ganhador;
    int posicao_jogada, fim_do_jogo = 0, contador = 0, modelo[9];

    // Montagem do Tabuleiro

    for(int i = 0; i < 9; i++){
        jogo[i] = ' ';
    }

    for(int i = 0; i < 9; i++){
        modelo[i] = i;
    }

    tabmod(modelo);

    // Ordem dos jogadores

    cout << "Quem vai comecar? (X/O)" << endl;
    cin >> jogador;
    LimparTela();

    // Jogo
    if(jogador == 'X'){

        ganhador = 'O';

        while(vencedor(jogo, fim_do_jogo) != 1){

            // Jogada X

            tabuleiro(jogo);

            jogadaX(jogo,posicao_jogada,contador);

            vencedor(jogo,fim_do_jogo);

            LimparTela();

            if(vencedor(jogo,fim_do_jogo) == 1){
                ganhador = 'X';
                break;
            }

            if(contador == 9){
                ganhador = ' ';
                break;
            }

            // Jogada O

            tabuleiro(jogo);

            jogadaO(jogo,posicao_jogada,contador);

            vencedor(jogo,fim_do_jogo);

            LimparTela();
        }
    }

    else if (jogador == 'O'){

        ganhador = 'X';

        while(vencedor(jogo,fim_do_jogo) != 1){

            // Jogada O

            tabuleiro(jogo);

            jogadaO(jogo,posicao_jogada,contador);

            vencedor(jogo,fim_do_jogo);

            LimparTela();

            if(vencedor(jogo,fim_do_jogo) == 1){
                ganhador = 'O';
                break;
            }

            if(contador == 9){
                ganhador = ' ';
                break;
            }

            // Jogada X

            tabuleiro(jogo);

            jogadaX(jogo,posicao_jogada,contador);

            vencedor(jogo,fim_do_jogo);

            LimparTela();
        }
    }
    
    tabuleiro(jogo);
    if(ganhador == 'X' || ganhador == 'O'){
        cout << "O Vencedor eh o Jogador " << ganhador;
    }
    else cout << "Deu Velha";

    return 0;
}