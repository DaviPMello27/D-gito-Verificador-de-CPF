#include <iostream>
#include "velha.h"
#include "snake.h"
#include "minado.h"

using namespace std;

int main(){
    enum game {
        VELHA,
        SNAKE,
        MINADO,
    };
    int choice;
    cout << "Digite o numero referente ao seu jogo \n0 = Jogo da Velha; \n1 = Snake; \n2 = Campo Minado; "<<endl;
    cin >> choice;
    switch(choice){
    case VELHA:
        runJogodaVelha();
        break;
    case SNAKE:
        runSnake();
        break;
    case MINADO:
        runMineSweeper();
        break;
    }
    return 0;
}
