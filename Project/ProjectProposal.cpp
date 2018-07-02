//Asmita Dhakal
//CSCI 1300 
//Reciatation: Bu Sun 202
//Cloud9 workspace esitor link: https://ide.c9.io/asmita97/csci1300
//Homework 8

#ifndef TICTACTOE_H
#define TICTACTOE_H

class TicTacToe{
    public:
        TicTacToe(){
            void Board();
            bool setValues(int rows, int columns, int playerNum);
            int status();
        };
        private:
        char board[3][3];
};

#endif //TICTACTOE_H


#ifndef PLAYER_H
#define Player_H

class Player{
  public:
    Player();
        virtual ~Player();
        //Player willl have a temp name and number of the player.
        Player(string tempName, int tempPlayerNum);
        //Game will get the players name.
        string getName;
        //take in the TicTacToe class and an object
        void nextMove(TicTacToe & object);
    private:
    //Name and the Player number is in private so no one can mess with it.
    string name;
    int playerNum;
};

#endif //PLAYER_H