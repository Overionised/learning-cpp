#include <iostream>
#include <time.h>
#include <cstdlib>

int main() {
  srand(time(0));
  int x[10][5];
  for(int i = 0; i < 10; i++){
    for(int j = 0; j < 5; j++){
     x[i][j] = 1 + rand() % 99;
    }
  }
  for(int i = 0; i < 10; i++){
    std::cout<<std::endl;
    for(int j = 0; j < 5; j++){
      if(x[i][j] < 10){
        std::cout << "0";
      }
      std::cout << x[i][j] << " ";
    }
  }
}
