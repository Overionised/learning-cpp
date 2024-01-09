#include <iostream>
#include <unistd.h>
#include "functions.cpp"

int main(){
    bool player = true;
	bool win = false;

    while(win == false){
        player = shoot(player);
    }
}