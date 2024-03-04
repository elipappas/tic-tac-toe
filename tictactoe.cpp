#include <iostream>
using namespace std;

void drawBoard(char board[3][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout << board[i][j];
            if(j!=2){
                cout<<"|";
            }
        }
        if(i!=2){
            cout<<endl<<"-----\n";
        }
        else{
            cout<<endl;
        }
    }
}

bool checkWin(char board[3][3], char player) {
    for(int i = 0; i < 3; i++){
        if(board[0][i] == player && board[1][i] == player && board[2][i] == player){
            return true;
        }
        else if(board[i][0] == player && board[i][1] == player && board[i][2] == player){
            return true;
        }
    }
    if(board[0][0] == player && board[1][1] == player && board[2][2] == player){
        return true;
    }
    else if(board[0][2] == player && board[1][1] == player && board[2][0] == player){
        return true;
    }
    else{
        return false;
    }
}

int main() {
    char board[3][3] = {{'~','~','~'},
                        {'~','~','~'},
                        {'~','~','~'}};
    int turn;
    char player = 'X';
    int row, col;
    for(turn = 0; turn < 9; turn++){
        drawBoard(board);
        while(true){
            cout << "player " << player << ": enter row (0-2) and column (0-2): ";
            cin >> row >> col;
            if(board[row][col] != '~' || row < 0 || row > 2 || col < 0 || col > 2){
                cout << "invalid move. Try again" << endl;
            }
            else {
                break;
            }
        }
        board[row][col] = player;
        if(checkWin(board, player)){
            drawBoard(board);
            cout << "***** Player: " << player << ", has won! *****" << endl;
            break;
        }
        if(player == 'X'){
            player = 'O';
        }
        else{
            player = 'X';
        }
    }
    if(turn == 9 && !checkWin(board, player)){
        drawBoard(board);
        cout << "***** It's a Draw! *****";
    }
}

