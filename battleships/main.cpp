#include <iostream>
#include "functions.cpp"

using namespace std;

int main()
{    
    char firstinput;
    logo();
    cout<<endl<<endl<<endl;

    cout<<"welcome to BATTLESHIPS"<<endl;
    cout<<"For rules and actions type h"<<endl;

    cin>>firstinput;
    switch (firstinput){

        case 'h':
            cout<<"you chose help, someone should probably wite some options here"<<endl;
            break;
        case 'v':
            visualise(arena_p1);
    }
    
    return 0;
}
