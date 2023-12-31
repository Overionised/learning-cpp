#include <iostream>
#include "functions.cpp"
#include <time.h>
#include <cstdlib>
#include <stdlib.h>
#include <unistd.h>

using namespace std;



int main()
{
    char firstinput, move, coordinates, rules;
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
        cout <<endl <<"there are unfortunatelly two versions  of the rules"<<endl;
        cout <<"do you want the rules to be, that after a hit you get another turn(y), or not (n)"<<endl;
        cin >> rules;

        while(win != 1){
            system("cls");
            system("clear");        // HOLY SHIT THIS GAME WORKS ON MULTIPLE PLATFORMS
            turn++;
            cout<<endl<<"you can always ask for help with h"<<endl<<endl;
            cout<<"this is the "<<turn<<" turn"<<endl;

            if (turn %2 == 1){
                player_id = 1;
                action(turn, player_id, rules);
            }
            if (turn%2==0){
                player_id = 2;

                action(turn, player_id, rules);
            }
        }
    }
    else{
        cout<<"that is not a valid amount of players"<<endl;
    }
    return 0;
}
