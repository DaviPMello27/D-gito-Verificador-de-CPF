#include <iostream>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <string>
using namespace std;

void showInstructions(){
    system("cls");
    cout << "This is the classic game of minesweeper written in C.\nRules for minesweeper:\n";
    cout << "1. You are in a mine field and you have to successfully flag all the places which have a mine(" << char(15) << ". If you flag all the mines, You win!\n";
    cout << "2. In your first turn, you have to choose a starting square. You can open a square by entering its row number(x) and column number(y)\n(Note: row and column number starts from 1)\n";
    cout << "3. There are three modes of operation:\n";
    cout << "(i) open mode. type 'o' in mode option. This mode lets the user to open a square\n";
    cout << "(ii) flag mode. type 'f' in mode option. This mode lets the user to flag a particular square. Flagged square is denoted by an 'F'\n";
    cout << "(iii) remove flag mode. type 'r' in mode option. This mode lets the user to remove a particular flag from a flagged square\n";
    cout << "4.If you open a square with a mine, you lose\n";
    cout << "5.If you open a square with a number written on it. The number shows that how many mines are there in the adjacent 8 squares\n";
    cout << "For eg:\n" << char(219) << " " << char(219) << " " << char(219) << "\n\n" << char(219) << " 4 " << char(219) << "\n\n" << char(219) << " " << char(219) << " " << char(219);
    cout << "\nHere 4 denoted that there are 4 mines in the remaining uncovered squares";
    cout << "\n\npress enter to continue.....";
    fflush(stdin);
}

void showMenu(){
    char menu;
    while(true){
        system("cls");
        cout << "Minesweeper 6x6\nversion 1.0\n\n";
        cout << "1. Play Minesweeper\n2. Rules\n";
        menu = getch();
        if(menu==49){
            break;
        } else if(menu==50){
            showInstructions();
            _getch();
        }
    }
}

void delay(clock_t a){
    clock_t start;
    start = clock();
    while(clock()-start < a){}
}

void showMap(char field[6][6]){
    system("cls");
    for(int i=0;i<6;i++) {
        for(int j=0;j<30;j++){
            cout << " ";
        }
        for(int j=0;j<6;j++){
            cout << field[i][j] << " ";
        }
        cout << "\n\n";
    }
}

void startingMap(int &PlayerXStart, int &PlayerYStart){
    while(true){
        cout << "\nOpen the starting square.\ny: ";
        cin >> PlayerXStart;
        cout << "x: ";
        cin >> PlayerYStart;
        if(PlayerXStart > 6 || PlayerYStart > 6 || PlayerXStart < 1 || PlayerYStart < 1){
            cout << "Row or column not defined. Try again\n";
            continue;
        } else {
            break;
        }
    }
}

void runMineSweeper(){
    char grid[6][6], field[6][6], m[2];
    int gridn[6][6]={0};
    int i, j, i1, j1, x, y, PlayerXStart, PlayerYStart, mine = 0, NumberOfFlags, BombsWithFlag = 0;
    showMenu();
    system("cls");
    for(i=0;i<6;i++){
        for(j=0;j<6;j++){
            field[i][j] = char(219);
        }
    }
    for(i=0;i<6;i++){
        for(j=0;j<30;j++){
            cout << " ";
        }
        for(j=0;j<6;j++){
            cout << field[i][j] << " ";
        }
        cout << "\n\n";
    }
    startingMap(PlayerXStart,PlayerYStart);
    PlayerXStart -= 1;
    PlayerYStart -= 1;
    srand(time(NULL));
    while(true){
        i = rand() % 6;
        j = rand() % 6;
        if(grid[i][j] != 15 && i != PlayerXStart && j != PlayerYStart){
            grid[i][j] = 15;
        } else {
            continue;
        }
        mine++;
        if(mine == 9){
            break;
        }
    }
    NumberOfFlags=mine;
    for(i=0;i<6;i++){
        for(j=0;j<6;j++){
            if(grid[i][j]!=15){
                for(i1=i-1;i1<=i+1;i1++){
                    for(j1=j-1;j1<=j+1;j1++){
                        if(grid[i1][j1]==15 && 0<=i1 && 0<=j1 &&i1<=5 && j1<=5){
                            gridn[i][j]++;
                        }
                    }
                }
                grid[i][j]=gridn[i][j] + 48;
            }
        }
    }
    for(i = PlayerXStart - 1; i <= PlayerXStart + 1; i++){
        for(j = PlayerYStart - 1; j <= PlayerYStart + 1; j++){
            if(grid[i][j] != 15){
                field[i][j] = grid[i][j];
            }
        }
    }
    x = PlayerXStart;
    y = PlayerYStart;
    while(true){
        //----MAP DRAW----//
        showMap(field);
        //----OPEN MINE----//
        cout << "No of Flags: " << NumberOfFlags << "\n";
        if(grid[x][y]==15 && strcmp(m,"o") == 0){
            printf("\nGame Over\n");
            break;
        }
        //----CHECK BOMBS WITH FLAGS----//
        for(i=0;i<6;i++){
            for(j=0;j<6;j++){
                if(grid[i][j]==15 && field[i][j]==70)
                    BombsWithFlag++;
            }
        }
        //----GAME WIN----//
        if(BombsWithFlag == mine){
            cout << "You win\n";
            break;
        }
        //----GAMEPLAY----//
        BombsWithFlag = 0;
        cout << "mode: ";
        cin >> m;
        cout << "y: ";
        cin >> x;
        cout << "x: ";
        cin >> y;
        x--;
        y--;
        //----OPEN----//
        if(strcmp(m,"o") == 0){
            field[x][y]=grid[x][y];
        }
        //----FLAG----//
        if(strcmp(m,"f") == 0 && field[x][y] != 70 && field[x][y] == -37){
            field[x][y] = 70;
            NumberOfFlags--;
        }
        //----REMOVE FLAG----//
        if(strcmp(m,"r") == 0){
            if(field[x][y] == 70){
                field[x][y] = 219;
                NumberOfFlags++;
            }
        }
        //----GAME-OVER----//
        if(grid[x][y] == 15 && strcmp(m,"o") == 0){
            for(i = 0; i < 6; i++){
                for(j = 0; j < 6; j++){
                    if(grid[i][j] == 15){
                        field[i][j] = grid[i][j];
                    }
                }
            }
        }
    }
    return;
}
