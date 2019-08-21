#include <iostream>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

using namespace std;

char square[10] = {'o','1','2','3','4','5','6','7','8','9'};

void imprimemapa(){

    system("cls");

    cout << "\n\n\tTic Tac Toe\n\n";
    cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;
    cout << endl;
    cout << "     |     |     " << endl;
    cout << "  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << endl;
    cout << "     |     |     " << endl << endl;
}

int selecionaJogador(int player){
        int jogador = (player % 2) ? 1 : 2;
        return jogador;
}

int selecionaPosicao(int player){
    int choice;
    cout << "Player " << player << ", enter a number:  ";
    cin >> choice;
    return choice;
}

bool validaPosicao(int choice){
    if (choice == 1 && square[1] == '1')
        return true;
    else if (choice == 2 && square[2] == '2')
        return true;
    else if (choice == 3 && square[3] == '3')
        return true;
    else if (choice == 4 && square[4] == '4')
        return true;
    else if (choice == 5 && square[5] == '5')
        return true;
    else if (choice == 6 && square[6] == '6')
        return true;
    else if (choice == 7 && square[7] == '7')
        return true;
    else if (choice == 8 && square[8] == '8')
        return true;
    else if (choice == 9 && square[9] == '9')
        return true;
    else
    {
        return false;
    }
}

void marcaPosicao(int player, int choice){
     char mark =(player == 1) ? 'X' : 'O';
     square[choice] = mark;
}

int verificaVitoria(){
    if (square[1] == square[2] && square[2] == square[3])
        return 1;
    else if (square[4] == square[5] && square[5] == square[6])
        return 1;
    else if (square[7] == square[8] && square[8] == square[9])
        return 1;
    else if (square[1] == square[4] && square[4] == square[7])
        return 1;
    else if (square[2] == square[5] && square[5] == square[8])
        return 1;
    else if (square[3] == square[6] && square[6] == square[9])
        return 1;
    else if (square[1] == square[5] && square[5] == square[9])
        return 1;
    else if (square[3] == square[5] && square[5] == square[7])
        return 1;
    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' && square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7] != '7' && square[8] != '8' && square[9] != '9')
        return 0;
    else
        return -1;
}

int runJogodaVelha(){
    int player;
    int posicao;
    int status;
    bool validade;
    do{
        imprimemapa();
        player = selecionaJogador(player);
        posicao = selecionaPosicao(player);
        validade = validaPosicao(posicao);
        if (validade == true){
            marcaPosicao(player, posicao);
            player++;
        }else{
            cout<<"Invalid move ";
            _getch();
        }
        status = verificaVitoria();
    }while(status == -1);
    if(status == 1)
        cout<<"==>\aPlayer "<<--player<<" win ";
    else
        cout<<"==>\aGame draw";
    _getch();
    return 0;
}
