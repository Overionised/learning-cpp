
#include <iostream>
#include <unistd.h>
#include <tuple>

using namespace std;

void logo() {
         cout << "__________    ___________________________.____     ___________ _________ ___ ___ ._____________  _________\n"
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

tuple <bool, int, int, int, int, int, int, int, int> checker(char arena[10][10],int y,int x, char check_for){
    bool found = 0;
    int my_y1 = 11, my_y2 = 11, my_y3 = 11, my_y4 = 11;
    int my_x1 = 11, my_x2 = 11, my_x3 = 11, my_x4 = 11;

        if (!(x == 1 || x == 10) && !(y == 1 || y == 10)){
            if (arena[10 - (y + 1)][x - 1] == check_for){
                if (check_for == 'O'){
                        found = 1;
                        return make_tuple(found, my_y1, my_y2, my_y3, my_y4, my_x1, my_x2, my_x3, my_x4);
                        }
                else if (check_for == '@'){
                        my_y1 = y + 1;
                        my_x1 = x;
                    }
            }
            if (arena[10 - (y - 1)][x - 1] == check_for){
                    if (check_for == 'O'){
                        found = 1;
                        return make_tuple(found, my_y1, my_y2, my_y3, my_y4, my_x1, my_x2, my_x3, my_x4);
                        }
                    else if (check_for == '@'){
                        my_y2 = y - 1;
                        my_x2 = x;
                    }
            }
            if (arena[10 - y][(x + 1) - 1] == check_for){
                    if (check_for == 'O'){
                        found = 1;
                        return make_tuple(found, my_y1, my_y2, my_y3, my_y4, my_x1, my_x2, my_x3, my_x4);
                        }
                        else if (check_for == '@'){
                        my_y3 = y;
                        my_x3 = x + 1;
                    }
            }
            if (arena[10 - y][(x - 1) - 1] == check_for) {
                    if (check_for == 'O'){
                        found = 1;
                        return make_tuple(found, my_y1, my_y2, my_y3, my_y4, my_x1, my_x2, my_x3, my_x4);
                        }
                        if (check_for == '@'){
                        my_y4 = y;
                        my_x4 = x - 1;
                    }
            }
        }

        ///// CORNER CHECKS //////////////////////////////////
        else{
            if (x == 1 && y == 1){
                if  (arena[10 - (y + 1)][x - 1] == check_for){
                    if (check_for == 'O'){
                        found = 1;
                        return make_tuple(found, my_y1, my_y2, my_y3, my_y4, my_x1, my_x2, my_x3, my_x4);
                        }
                    if (check_for == '@'){
                        my_y1 = y + 1;
                        my_x1 = x;
                    }
                }
                if  (arena[10 - y][(x + 1) - 1] == check_for){
                    if (check_for == 'O'){
                        found = 1;
                        return make_tuple(found, my_y1, my_y2, my_y3, my_y4, my_x1, my_x2, my_x3, my_x4);
                        }
                    if (check_for == '@'){
                        my_y3 = y;
                        my_x3 = x + 1;
                    }
                }
            }
            else if (x==1 && y == 10){
                if  (arena[10 - (y - 1)][x - 1] == check_for){
                    if (check_for == 'O'){
                        found = 1;
                        return make_tuple(found, my_y1, my_y2, my_y3, my_y4, my_x1, my_x2, my_x3, my_x4);
                        }
                    if (check_for == '@'){
                        my_y2 = y - 1;
                        my_x2 = x;
                    }
                }
                if (arena[10 - y][(x + 1) - 1] == check_for){
                    if (check_for == 'O'){
                        found = 1;
                        return make_tuple(found, my_y1, my_y2, my_y3, my_y4, my_x1, my_x2, my_x3, my_x4);
                        }
                    if (check_for == '@'){
                        my_y3 = y;
                        my_x3 = x + 1;

                    }
                }
            }

            else if (x == 10 && y == 1){
                if  (arena[10 - (y + 1)][x - 1] == check_for){
                    if (check_for == 'O'){
                        found = 1;
                        return make_tuple(found, my_y1, my_y2, my_y3, my_y4, my_x1, my_x2, my_x3, my_x4);
                        }
                    if (check_for == '@'){
                        my_y1 = y + 1;
                        my_x1 = x;
                    }
                }
                if (arena[10 - y][(x - 1) - 1] == check_for){
                        if (check_for == 'O'){
                        found = 1;
                        return make_tuple(found, my_y1, my_y2, my_y3, my_y4, my_x1, my_x2, my_x3, my_x4);
                        }
                    if (check_for == '@'){
                        my_y4 = y;
                        my_x4 = x - 1;
                    }
                }
            }
            else if (x == 10 && y == 10){
                if  (arena[10 - (y - 1)][x - 1] == check_for){
                    if (check_for == 'O'){
                        found = 1;
                        return make_tuple(found, my_y1, my_y2, my_y3, my_y4, my_x1, my_x2, my_x3, my_x4);
                        }
                    if (check_for == '@'){
                        my_y2 = y - 1;
                        my_x2 = x;

                    }
                }
                if  (arena[10 - y][(x - 1) - 1] == check_for){
                        if (check_for == 'O'){
                        found = 1;
                        return make_tuple(found, my_y1, my_y2, my_y3, my_y4, my_x1, my_x2, my_x3, my_x4);
                        }
                    if (check_for == '@'){
                        my_y4 = y;
                        my_x4 = x - 1;
                    }
                }
            }
            else if (x == 1){
                if  (arena[10 - (y + 1)][x - 1] == check_for){
                    if (check_for == 'O'){
                        found = 1;
                        return make_tuple(found, my_y1, my_y2, my_y3, my_y4, my_x1, my_x2, my_x3, my_x4);
                        }
                    if (check_for == '@'){
                        my_y1 = y + 1;
                        my_x1 = x;
                    }
                }
                if  (arena[10 - (y - 1)][x - 1] == check_for){
                    if (check_for == 'O'){
                        found = 1;
                        return make_tuple(found, my_y1, my_y2, my_y3, my_y4, my_x1, my_x2, my_x3, my_x4);
                        }
                    if (check_for == '@'){
                        my_y2 = y - 1;
                        my_x2 = x;
                    }
                }
                if  (arena[10 - y][(x + 1) - 1] == check_for){
                        if (check_for == 'O'){
                        found = 1;
                        return make_tuple(found, my_y1, my_y2, my_y3, my_y4, my_x1, my_x2, my_x3, my_x4);
                        }
                    if (check_for == '@'){
                        my_y3 = y;
                        my_x3 = x + 1;

                    }
                }
            }

            else if (x == 10){
                if  (arena[10 - (y + 1)][x - 1] == check_for){
                    if (check_for == 'O'){
                        found = 1;
                        return make_tuple(found, my_y1, my_y2, my_y3, my_y4, my_x1, my_x2, my_x3, my_x4);
                        }
                    if (check_for == '@'){
                        my_y1 = y + 1;
                        my_x1 = x;
                    }
                }
                if (arena[10 - (y - 1)][x - 1] == check_for){
                    if (check_for == 'O'){
                        found = 1;
                        return make_tuple(found, my_y1, my_y2, my_y3, my_y4, my_x1, my_x2, my_x3, my_x4);
                        }
                    if (check_for == '@'){
                        my_y2 = y - 1;
                        my_x2 = x;
                        }
                    }
                if  (arena[10 - y][(x - 1) - 1] == check_for){
                        if (check_for == 'O'){
                        found = 1;
                        return make_tuple(found, my_y1, my_y2, my_y3, my_y4, my_x1, my_x2, my_x3, my_x4);
                        }
                    if (check_for == '@'){
                        my_y4 = y;
                        my_x4 = x - 1;
                    }
                }
            }
            else if (y==1){
                if  (arena[10 - (y + 1)][x - 1] == check_for){
                    if (check_for == 'O'){
                        found = 1;
                        return make_tuple(found, my_y1, my_y2, my_y3, my_y4, my_x1, my_x2, my_x3, my_x4);
                        }
                    if (check_for == '@'){
                        my_y1 = y + 1;
                        my_x1 = x;

                    }
                }
                if  (arena[10 - y][(x + 1) - 1] == check_for){
                    if (check_for == 'O'){
                        found = 1;
                        return make_tuple(found, my_y1, my_y2, my_y3, my_y4, my_x1, my_x2, my_x3, my_x4);
                        }
                    if (check_for == '@'){
                        my_y3 = y;
                        my_x3 = x + 1;
                    }
                }
                if  (arena[10 - y][(x - 1) - 1] == check_for){
                        if (check_for == 'O'){
                        found = 1;
                        return make_tuple(found, my_y1, my_y2, my_y3, my_y4, my_x1, my_x2, my_x3, my_x4);
                        }
                    if (check_for == '@'){
                        my_y4 = y;
                        my_x4 = x - 1;
                    }
                }
            }
            else if (y==10){
                if  (arena[10 - (y - 1)][x - 1] == check_for){
                    if (check_for == 'O'){
                        found = 1;
                        return make_tuple(found, my_y1, my_y2, my_y3, my_y4, my_x1, my_x2, my_x3, my_x4);
                        }
                    if (check_for == '@'){
                        my_y2 = y - 1;
                        my_x2 = x;
                    }
                }
                if  (arena[10 - y][(x + 1) - 1] == check_for){
                    if (check_for == 'O'){
                        found = 1;
                        return make_tuple(found, my_y1, my_y2, my_y3, my_y4, my_x1, my_x2, my_x3, my_x4);
                        }
                    if (check_for == '@'){
                        my_y3 = y;
                        my_x3 = x + 1;
                    }
                }
                if  (arena[10 - y][(x - 1) - 1] == check_for){
                        if (check_for == 'O'){
                        found = 1;
                        return make_tuple(found, my_y1, my_y2, my_y3, my_y4, my_x1, my_x2, my_x3, my_x4);
                        }
                    if (check_for == '@'){
                        my_y4 = y;
                        my_x4 = x - 1;
                    }
                }
            }

        }
        return make_tuple(found, my_y1, my_y2, my_y3, my_y4, my_x1, my_x2, my_x3, my_x4);
};

void sank(char arena[10][10],int y,int x, int cycle){
    tuple <bool, int, int, int, int, int, int, int, int> check_res;
    bool itsunk=0;

    check_res = checker(arena, y, x, 'O');

    while (cycle <2){
        if ( get<0>(check_res) == 1 ){
            cout <<"not sunk"<< cycle<<endl;
            itsunk=1;
            return;
        }
        else{
            if ( get<1>(check_res) != 11 ){
                sank ( arena, get<1>(check_res), get<5>(check_res), cycle);
            }
            if ( get<2>(check_res) != 11 ){
                sank ( arena, get<2>(check_res), get<6>(check_res), cycle);
            }
            if ( get<3>(check_res) != 11 ){
                sank( arena, get<3>(check_res), get<7>(check_res), cycle);
            }
            if ( get<4>(check_res) != 11 ){
                sank( arena, get<4>(check_res), get<8>(check_res), cycle);
            }
            else{
                check_res = checker( arena, y, x, '@');
                cycle++;
                if (get<0>(check_res) == 0 && cycle == 2 && itsunk != 1){
                    cout <<"sunk"<< cycle<<endl;
                    cout<<get<1>(check_res)<<endl;
                }
            }
        }
    }
/*
        if ( drowning == 1 ){
            cout <<"not sunk"<<cyclecount<<endl;  // quit function
        }
        else if ( drowning == 0 ){
            if (check_for == '@'){
                if (1==1){
                    cout<< "sunk" ;
                    cout <<cyclecount<<endl;
                }
            }
            else if (check_for != '@'){
                cout << "checking for @ for the "<< cyclecount+1<< "th time" <<endl;
                cyclecount++;
                if (cyclecount <= 20){
                    sank(arena, y, x, '@', drowning, cyclecount);
                    return;
                }
            }
        }
    cyclecount = 0;
    */
};

void shoot(int player_id, char rules){
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
            cout<<endl<<"HIT!!!"<<endl;
            sank(arena_p2, coordinate_y, coordinate_x, 0);
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
            sank(arena_p1, coordinate_y, coordinate_x, 0);
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
