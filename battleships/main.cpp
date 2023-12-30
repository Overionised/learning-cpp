#include <iostream>
#include "functions.cpp"
#include <time.h>
#include <cstdlib>
#include <stdlib.h>

using namespace std;



int main()
{
    char firstinput, move;
    int playercount, win, player_id;
    int turn=0;


    logo();
    cout<<endl<<endl<<endl;

    cout<<"welcome to BATTLESHIPS"<<endl;
    cout<<"For rules and actions type h"<<endl;
    cout<<"to play the game type p"<<endl;

    cin>>firstinput;
    switch (firstinput){

        case 'h':
            cout<<"you chose help, someone should probably wite some options here"<<endl;
            break;
        case 'p':
            cout<<"how many players do you want (1 or 2) : ";
            cin>>playercount;
            break;

    }


    if(playercount==1){
        cout<<"This has yet to be supported, sorry";
        srand(time(0));
        // 1 + rand() % 99;

    }

    if (playercount==2){

        while(win != 1){
            system("cls");
            system("clear");        // HOLY SHIT THIS GAME WORKS ON MULTIPLE PLATFORMS
            turn++;
            cout<<endl<<"you can always ask for help with h"<<endl<<endl;
            cout<<"this is the "<<turn<<" turn"<<endl;

            if (turn %2 == 1){
                player_id = 1;
                action(turn, player_id);
            }
            if (turn%2==0){
                player_id = 2;

                action(turn, player_id);
            }
        }
    }
    else{
        cout<<"that is not a valid amount of players"<<endl;
    }
    return 0;
}
