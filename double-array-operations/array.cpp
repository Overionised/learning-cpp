#include <iostream>
using namespace std;

void spacing_big(){
  for(int i = 0; i < 3; i++){
  cout<<endl;
  }
}
void spacing_small(){
  for(int i = 0; i < 2; i++){
  cout<<endl;
  }
}

int main() {
  int how_big_is_array=12;
  int numbers[3][4] = {
  { 1,  2,  3,  4},
  { 5,  6,  7,  8},
  { 9, 10, 11, 12}  
};
  int biggest = numbers[0][0];
  int sum = 0;

  cout<<"we have an array, it looks like this: ";
  spacing_small();
  for(int i = 0; i < 3; i++){
    if(i!=0){
      cout<<endl;
    }
    for(int j = 0; j < 4; j++){
      if(numbers[i][j]<10){
        cout<<"0";
      }
      cout<<numbers[i][j]<<" ";
    }
  }

  spacing_big();
  for(int i =0; i < 3; i++){
    for(int j = 0; j < 4; j++){
      if(numbers[i][j]>biggest){
        biggest = numbers[i][j];
      }
    }
  }
  cout<<"the biggest num in the array is: "<<biggest<<endl;

  spacing_small();
  for(int i =0; i < 3; i++){
    for(int j = 0; j < 4; j++){
      sum += numbers[i][j];
    }
      }
  cout<<"the sum of all the numbers in the array is: "<<sum<<endl;

  spacing_small();
  cout<<"the average of all the numbers in the array is: "<<sum/how_big_is_array<<endl;
}
