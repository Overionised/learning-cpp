#include <iostream>
#include <unistd.h>
#include "functions.cpp"

using namespace std;

int main()
{
    bool player = true;
    
    while(true){
        player = shoot(player);
    }

}
