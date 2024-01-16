#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include "functions.cpp"

int main(){
    bool player = true;
    bool win = false;
    int coordinatex;

    while(win == false){
        coordinatex = user_input();
        shoot(player, coordinatex);
        win = connected4(arena, playerToken);
        
        if (win) {
            cout <<endl << "Player " << (playerToken) << " wins!" << endl;
            break;
        }
        player = turnchange(player);
    }
}
