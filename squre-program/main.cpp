#include <iostream>
using namespace std;

int main() {
  int x, y, f=0;
  char teach;
  char run_again = 'y';

  while(run_again == 'y') {
    cout<<"if you are a techer and want a simple square write s "<<endl;
    cout<<"if you are cool write c"<<endl;
    cout<< "if you are a teacher, but dont want to be restricted by dumb rules write t"<<endl;
    cin>>teach;

    cout << "how long?" << endl;
    cin >> x;
    f=0;

    if(!(teach=='s')){
      cout << "how wide?" << endl;
      cin >> y;
    }
    if (teach == 't') {
      while (x % 2 == 0) {
        cout << "Please enter an odd number for length." << endl;
        cin >> x;
        if(!(x % 2 ==1)){ 
            cout<<"this is not an odd number you dingus "<<endl;
            cout<<"I will now force one, wheather you like it or not"<<endl;
            x++;
            cout<<"WOW this number you picked "<< x <<" is so beatifull"<<endl;
          }   
      }
      while (y % 2 == 0) {
        cout << "Please enter an odd number for width." << endl;
        cin >> y;
        if(!(y % 2 == 1)){ 
            cout<<"this is not an odd number you dingus "<<endl;
            cout<<"I will now force one, wh"
                  "weather you like it or not"<<endl;
            y++;
            cout<<"WOW this number you picked "<< y <<" is so beatifull"<<endl;
          }
      }
    }
    ///////////////////////////////
    // THIS IS THE IMPORTANT PART//
    ///////////////////////////////

     if (teach == 's') {
        y=x;
        if(!(x % 2 ==1)){ 
          x++;
          y=x;
        }
      }
      ////////////)////////////////
    if(!(teach=='s')){
        cout << "funny offset? -(can also be negative)" << endl;
        cout << "if no, just wright 0" << endl;
        cin >> f;}


    ///////////////////////////
    // THIS IS ALSO IMPORTANT//
    ///////////////////////////
    for (int j = 0; j < x; j++) {
      for (int b = 0; b < y; b++) {
        if (j == 0 || j == x-1 || b == 0 || b == y-1 || b+f==y/2 || j+f==x/2) {
          cout << "* ";
        } else {
          cout << "  ";
        }
      }
      ////////////////////////
      cout << endl;
    }
    cout << "Do you want to run the code again? (y/n)" << endl;
    cin >> run_again;
  }
}

