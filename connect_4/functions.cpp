using namespace std;

char playerToken = 'O';

char arena[6][7]{
//    0    1    2    3    4    5    6
    {'x', 'x', 'x', 'x', 'x', 'x', 'x'}, //0
    {'x', 'x', 'x', 'x', 'x', 'x', 'x'}, //1
    {'x', 'x', 'x', 'x', 'x', 'x', 'x'}, //2
    {'x', 'x', 'x', 'x', 'x', 'x', 'x'}, //3
    {'x', 'x', 'x', 'x', 'x', 'x', 'x'}, //4
    {'x', 'x', 'x', 'x', 'x', 'x', 'x'}  //5
}; // 1    2    3    4    5    6    7


/*bool connected4(char arena[6][7], char playerToken) {
    bool stalemate = true;
    // Check horizontal
    for (int row = 0; row < 6; row++) {
        for (int col = 0; col < 4; col++) {
            if (arena[row][col] == playerToken && arena[row][col + 1] == playerToken &&
                arena[row][col + 2] == playerToken && arena[row][col + 3] == playerToken) {
                return true;
            }
        }
    }
    // Check vertical
    for (int col = 0; col < 7; col++) {
        for (int row = 0; row < 3; row++) {
            if (arena[row][col] == playerToken && arena[row + 1][col] == playerToken &&
                arena[row + 2][col] == playerToken && arena[row + 3][col] == playerToken) {
                return true;
            }
        }
    }
    // Check diagonal (top-left to bottom-right)
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 4; col++) {
            if (arena[row][col] == playerToken && arena[row + 1][col + 1] == playerToken &&
                arena[row + 2][col + 2] == playerToken && arena[row + 3][col + 3] == playerToken) {
                return true;
            }
        }
    }
    // Check diagonal (bottom-left to top-right)
    for (int row = 3; row < 6; row++) {
        for (int col = 0; col < 4; col++) {
            if (arena[row][col] == playerToken && arena[row - 1][col + 1] == playerToken &&
                arena[row - 2][col + 2] == playerToken && arena[row - 3][col + 3] == playerToken) {
                return true;
            }
        }
    }
    for (int row = 3; row < 6; row++) {
        for (int col = 0; col < 4; col++) {
            if (arena [row][col] == 'x'){
                stalemate = false;
            }
        }
    }
    if (!stalemate){
        return false;
    }
    else {
        cout<<endl<< "stalemate"<<endl;
        return true;
    }
} */

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
        cout << endl<< "Player" << playerToken<< " enter your coordinate :";
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
void shoot( bool player, int coordinatex){

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
}
bool turnchange(bool player){
    if(player == true){
        player = false;
        playerToken = '@';

    }
    else if(player == false){
        player = true;
        playerToken = 'O';
    }
        system("cls");
        system("clear");
        return player;
};
