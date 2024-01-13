using namespace std;

char arena[6][7]{
//    0    1    2    3    4    5    6
    {'x', 'x', 'x', 'x', 'x', 'x', 'x'}, //0
    {'x', 'x', 'x', 'x', 'x', 'x', 'x'}, //1
    {'x', 'x', 'x', 'x', 'x', 'x', 'x'}, //2
    {'x', 'x', 'x', 'x', 'x', 'x', 'x'}, //3
    {'x', 'x', 'x', 'x', 'x', 'x', 'x'}, //4
    {'x', 'x', 'x', 'x', 'x', 'x', 'x'}  //5
}; // 1    2    3    4    5    6    7


void visualise(char x[6][7]){
    cout << "\033[1;34m"<<endl;
    for(int i = 0; i<6; i++){
            cout << "\033[0;34m";
            cout << endl<<"  |";
            cout << "\033[1;37m";

         for(int j = 0; j<7; j++){
            if(x[i][j] == 'O'){
                cout << "\033[1;31m";
            }
            else if(x[i][j] == 'x'){
                cout << "\033[0;37m";
            }

            else if(x[i][j] == '@'){
                cout << "\033[1;33m";
            }
            if (j<=5){
                cout<<x[i][j]<<" ";
                cout << "\033[1;34m";
            }
            if (j == 6){
                cout<<x[i][j];
                cout << "\033[0;34m";
                cout <<"|";
            }
        }
    }
    cout <<endl <<"\033[0;34m" <<"   1 2 3 4 5 6 7" <<"\033[0;37m"<<flush;
};
int user_input (){
    int coordinatex;
    bool valid_input = false;

    visualise(arena);
    while (valid_input == false){
        cout << endl<<" enter your coordinate :";
        cin >> coordinatex;

        if (cin.fail()){
            cin.clear(); cin.ignore(512, '\n');
        }

        if ((coordinatex < 8) && (coordinatex != 0)){
            valid_input = true;
        }
        else {
            cout <<endl <<"invalid input try again"<<endl;
        }
    }
    return coordinatex;
}
void animate (bool player, int turn, int coordinate){
        for (int i = 0; i < 6; i++){
            system("cls");
            system("clear");
            if (player == true){
                arena[i - turn][coordinate - 1] =  'O';
            }
            if (player == false){
                arena[i - turn][coordinate - 1] =  '@';
            }
            visualise(arena);
            usleep(70000);
            arena[i - turn][coordinate - 1] =  'x';
    }
}
bool connected4 (int player, int coordinate, bool win){
    for (int turn = 0 ; turn < 7 ; turn++){
        for (int j = 0; j < 6; j++){
           if (arena[turn][j] == 'O'){
               // cout<<"found an O at "<< turn << " "<<j<<endl;
               // return win = true;
            }
        }
    }
}
bool shoot( bool player, int coordinatex){

    for (int turn = 0 ; turn < 7 ; turn++){
        if (arena[6 - turn][coordinatex - 1] == 'x'){
            animate(player, turn, coordinatex);
            if (player == true){
                    arena[6 - turn][coordinatex - 1] = 'O';
            }
            else if (player == false){
                arena[6 - turn][coordinatex - 1] = '@';
            }
            break;
        }
    }
    if(player == true){
        player = false;
        system("cls");
        system("clear");
        return player;
    }
    else if(player == false){
        player = true;
        system("cls");
        system("clear");
        return player;
    }
}
