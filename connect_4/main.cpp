#include <iostream>
#include <unistd.h>
#include "functions.cpp"

int main(){
    bool player = true;
	bool win = false;
	int coordinatex;

    while(win == false){
        coordinatex = user_input();
        player = shoot(player, coordinatex);
    }
}