using namespace std;

char arena[6][7]{
    {'x', 'x', 'x', 'x', 'x', 'x', 'x'},
    {'x', 'x', 'x', 'x', 'x', 'x', 'x'},
    {'x', 'x', 'x', 'x', 'x', 'x', 'x'},
    {'x', 'x', 'x', 'x', 'x', 'x', 'x'},
    {'x', 'x', 'x', 'x', 'x', 'x', 'x'},
    {'x', 'x', 'x', 'x', 'x', 'x', 'x'}
};


void visualise(char x[6][7]){
    cout << "\033[1;34m"<<endl;
    cout << " y"<<endl<<" ▲";
    for(int i = 0; i<6; i++){
        if(i<1){
            cout << "\033[1;34m";
            cout << endl<<" "<< 6-i<<" ";
            cout << "\033[1;37m";
        }
        else{
            cout << "\033[0;34m";
            cout << endl<<" "<<6-i<<" ";
            cout << "\033[1;37m";
        }

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
             cout<<x[i][j]<<" ";
             cout << "\033[1;34m";
        }
    }
    cout <<endl <<"\033[0;34m" <<" 0 1 2 3 4 5 6 7 ► x"<<flush;
};

bool shoot( bool player){
    int coordinatex, coordinatey, turn;
    visualise(arena);
    cout << endl<<" enter your coordinates :";
    cin >> coordinatex;
    

    for (int turn = 0 ; turn < 7 ; turn++){
        if (arena[6 - turn][coordinatex - 1] == 'x'){
            if (player == true){
                    arena[6 - turn][coordinatex - 1] = 'O';
                    break;
            }
            if (player == false){
                    arena[6 - turn][coordinatex - 1] = '@';
                    break;
            }
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
};
