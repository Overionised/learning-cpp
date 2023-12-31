
#include <iostream>
#include <unistd.h>

using namespace std;

void logo() {
    std::cout << "__________    ___________________________.____     ___________ _________ ___ ___ ._____________  _________\n"
                 "\\______   \\  /  _  \\__    ___/\\__    ___/|    |    \\_   _____//   _____//   |   \\|   \\______   \\/   _____/\n"
                 " |    |  _/ /  /_\\  \\|    |     |    |   |    |     |    __)_ \\_____  \\/    ~    \\   ||     ___/\\_____  \\\n"
                 " |    |   \\/    |    \\    |     |    |   |    |___  |        \\/        \\    Y    /   ||    |    /        \\\n"
                 " |______  /\\____|__  /____|     |____|   |_______ \\/_______  /_______  /\\___|_  /|___||____|   /_______  /\n"
                 "        \\/         \\/                            \\/        \\/        \\/       \\/                       \\/\n";
}

char arena_p1[10][10]{
        {'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
        {'~', '~', '~', '~', '~', '~', '~', '~', 'O', 'O'},
        {'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
        {'~', '~', '~', 'O', 'O', '~', '~', 'x', '~', '~'},
        {'~', '~', '~', 'O', '~', '~', 'x', '~', '~', '~'},
        {'O', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
        {'O', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
        {'O', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
        {'~', '~', '~', '~', '~', 'O', '~', '~', '~', '~'},
        {'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'}
    };
char arena_p2[10][10]{
        {'~', '~', '~', '~', '~', '~', '~', '~', '~', 'O'},
        {'~', '~', 'O', 'O', 'O', 'O', '~', '~', '~', '~'},
        {'~', '~', '~', '~', '~', 'O', '~', '~', '~', '~'},
        {'~', '~', '~', '~', '~', 'O', '~', '~', '~', '~'},
        {'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
        {'~', '~', '~', '~', '~', '~', '~', '~', 'O', 'O'},
        {'O', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
        {'O', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
        {'~', '~', '~', '~', '~', 'O', '~', '~', '~', '~'},
        {'~', '~', '~', 'O', '~', '~', '~', '~', '~', '~'}
    };
    char shot_p1[10][10]{
        {'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
        {'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
        {'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
        {'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
        {'~', '~', 'x', 'x', 'x', '~', '~', '~', '~', '~'},
        {'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
        {'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
        {'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
        {'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
        {'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'}
    };
    char shot_p2[10][10]{
        {'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
        {'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
        {'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
        {'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
        {'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
        {'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
        {'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
        {'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
        {'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
        {'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'}
    };

void visualise(char x[10][10]){
    cout << "\033[1;37m"<<endl;
    cout << " y"<<endl<<" ▲";
    for(int i = 0; i<10; i++){
        if(i<1){
            cout << "\033[0;37m";
            cout << endl<<10-i<<" ";
            cout << "\033[1;34m";
        }
        else{
            cout << "\033[0;37m";
            cout << endl<<" "<<10-i<<" ";
            cout << "\033[1;34m";
        }

         for(int j = 0; j<10; j++){
            if(x[i][j] == 'O'){
                cout << "\033[1;31m";
            }
            else if(x[i][j] == 'x'){
                cout << "\033[0;37m";
            }
            else if(x[i][j] == '@'){
                cout << "\033[0;31m";
            }
             cout<<x[i][j]<<" ";
             cout << "\033[1;34m";
        }
    }
    cout <<endl <<"\033[0;37m" <<" 0 1 2 3 4 5 6 7 8 9 10 ► x"<<flush;
};
void sank(char arena[10][10],int y,int x, char check_for){
    if (!(x == 1 || x == 10) && !(y == 1 || y == 10)){
         if ((arena[10 - (y + 1)][x - 1] != check_for) &&
            (arena[10 - (y - 1)][x - 1] != check_for) &&
            (arena[10 - y][(x + 1) - 1] != check_for) &&
            (arena[10 - y][(x - 1) - 1] != check_for)) {
                if (check_for == 'O'){
                        cout << "there aren't any non-broken ships next to this wreck" << endl;
                    }
        }
    }
    else{
        if (x == 1 && y == 1){
            if  ((arena[10 - (y + 1)][x - 1] != check_for) &&
                (arena[10 - y][(x + 1) - 1] != check_for)){
                    if (check_for == 'O'){
                        cout << "there aren't any non-broken ships next to this wreck" << endl;
                    }
            }
        }
        else if (x==1 && y == 10){
            if  ((arena[10 - (y - 1)][x - 1] != check_for) &&
                (arena[10 - y][(x + 1) - 1] != check_for)){
                    if (check_for == 'O'){
                        cout << "there aren't any non-broken ships next to this wreck" << endl;
                    }
            }
        }

        else if (x == 10 && y == 1){
            if  ((arena[10 - (y + 1)][x - 1] != check_for) &&
                (arena[10 - y][(x - 1) - 1] != check_for)){
                    if (check_for == 'O'){
                        cout << "there aren't any non-broken ships next to this wreck" << endl;
                    }
            }
        }
        else if (x == 10 && y == 10){
            if  ((arena[10 - (y - 1)][x - 1] != check_for) &&
                (arena[10 - y][(x - 1) - 1] != check_for)){
                    if (check_for == 'O'){
                        cout << "there aren't any non-broken ships next to this wreck" << endl;
                    }
            }
        }
        else if (x == 1){
            if  ((arena[10 - (y + 1)][x - 1] != check_for) &&
                (arena[10 - (y - 1)][x - 1] != check_for) &&
                (arena[10 - y][(x + 1) - 1] != check_for)){
                    if (check_for == 'O'){
                        cout << "there aren't any non-broken ships next to this wreck" << endl;
                    }
            }
        }

        else if (x == 10){
            if  ((arena[10 - (y + 1)][x - 1] != check_for) &&
                (arena[10 - (y - 1)][x - 1] != check_for) &&
                (arena[10 - y][(x - 1) - 1] != check_for)){
                    if (check_for == 'O'){
                        cout << "there aren't any non-broken ships next to this wreck" << endl;
                    }
            }
        }
        else if (y==1){
            if  ((arena[10 - (y + 1)][x - 1] != check_for) &&
                (arena[10 - y][(x + 1) - 1] != check_for) &&
                (arena[10 - y][(x - 1) - 1] != check_for)){
                    if (check_for == 'O'){
                        cout << "there aren't any non-broken ships next to this wreck" << endl;
                    }
            }
        }
        else if (y==10){
            if ((arena[10 - (y - 1)][x - 1] != check_for) &&
                (arena[10 - y][(x + 1) - 1] != check_for) &&
                (arena[10 - y][(x - 1) - 1] != check_for)){
                    if (check_for == 'O'){
                        cout << "there aren't any non-broken ships next to this wreck" << endl;
                    }
            }
        }
        /*else{
            if (!(x == 1 || x == 10) && !(y == 1 || y == 10)){
                if (arena[10 - (y + 1)][x - 1] == '@'){
                    sank(arena, y + 1, x - 1, 'O');
                }
                if(arena[10 - (y - 1)][x - 1] == '@'){
                    sank(arena, y-1, x-1, 'O');
                }
                if(arena[10 - y][(x + 1) - 1] == '@'){
                    sank(arena, y, x + 1, 'O');
                }
                if (arena[10 - y][(x - 1) - 1] == '@'){
                    sank(arena, y, x - 1, 'O');
                }
            }
            else{
                if (x == 1 && y == 1){
                    if  (arena[10 - (y + 1)][x - 1] == '@'){

                    }
                    if  (arena[10 - y][(x + 1) - 1] != check_for){

                    }
                }
            }
        } */
    }
};

void shoot(int player_id, int rules){
    int coordinate_x, coordinate_y;
    if(player_id==1){
        visualise(shot_p1);
    }

    if(player_id==2){
        visualise(shot_p2);
    }

    cout<<endl<<endl<<"enter coordinates like in this example 1 5 (x y)"<<endl;
    cout<<"enter the coordinates : ";
    cin>>coordinate_x>>coordinate_y;

    if(player_id==1){
        if(arena_p2[10 -coordinate_y][coordinate_x -1]=='O'){
            cout << "\033[1;31m";
            shot_p1[10 -coordinate_y][coordinate_x -1]='@';
            arena_p2[10 -coordinate_y][coordinate_x -1]='@';
            cout<<"HIT!!!"<<endl;
            sank(arena_p2, coordinate_y, coordinate_x, 'O');
            cout << "\033[1;37m";
            visualise(shot_p1);
            sleep(3);
            if (rules=='y'){
                shoot(player_id, rules);
            }

        }
        else{
            cout << "\033[1;37m";
            shot_p1[10 -coordinate_y][coordinate_x -1]='x';
            arena_p2[10 -coordinate_y][coordinate_x -1]='x';
            cout<<"MISS"<<endl;
            visualise(shot_p1);
            sleep(3);
        }
    }

    else if(player_id==2){
        if(arena_p1[10 -coordinate_y][coordinate_x -1]=='O'){
            cout << "\033[1;31m";
            shot_p2[10 -coordinate_y][coordinate_x -1]='@';
            arena_p1[10 -coordinate_y][coordinate_x -1]='@';
            cout<<"HIT!!!";
            sank(arena_p1, coordinate_y, coordinate_x, 'O');
            cout << "\033[1;37m";
            visualise(shot_p2);
            sleep(3);
            if (rules=='y'){
                shoot(player_id, rules);
            }
        }

        else{
            cout << "\033[1;37m";
            shot_p2[10 -coordinate_y][coordinate_x -1]='x';
            arena_p1[10 -coordinate_y][coordinate_x -1]='x';
            cout<<"MISS"<<endl;
            visualise(shot_p2);
            sleep(3);
        }
    }
};

void action(int turn, int player_id, int rules){
    char move, visualisator;
    int endturn = 0;

    while (endturn!= 1){
        cout<<endl<<endl<<"what is your move player "<<player_id<<" : ";
        cin>>move;
        switch (move){

            case 'v':
                cout <<endl << "what do you want to visualise ?"<<endl;
                cout <<"Do you wan to visualise the arena, or the shooting range ?" <<endl;
                cout<<"a for arena s for shooting range"<<endl;
                cout <<endl <<"visualise : ";
                cin >>visualisator;

                if (player_id==1){

                    switch (visualisator){

                        case 'a':
                            visualise(arena_p1);
                            break;
                        case 's':
                            visualise(shot_p1);
                            break;
                        default:
                            cout<<"that's not it"<<endl;
                    }
                }

                if (player_id==2){

                    switch (visualisator){

                        case 'a':
                            visualise(arena_p2);
                            break;
                        case 's':
                            visualise(shot_p2);
                            break;
                        default:
                            cout<<"that's not it"<<endl;
                    }
                }

                break;

            case 'h':
                cout<<"commands that you can do are :"<<endl<<"h for help (that's where you are now)"<<endl<<"v for visualise (visualises your arena or shooting range)"<<endl<<"and s for shoot"<<endl;
                break;

            case 's':
                shoot(player_id, rules);
                endturn=1;
                break;

            default:
                cout<<endl<<"that is not a command, try typing h, if you dont know what to do"<<endl;
                break;
        }
    }
};
