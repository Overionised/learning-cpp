#include <iostream>
#include <cmath>

double whatnum(){
    double number;
    char tanchoice;

    std::cout<<"what number do you choose : ";
    std::cin>>number;
    std::cout<< "do you want NOT TANGENT, (y/n) ";
    std::cin>>tanchoice;
    if (tanchoice == 'y'){
        number = number / 57.2958;
    }

    return number;
}
double choice(double num) {

    char what_to_use;

    std::cout<<" tan (t), sin(s), cosin(c), cotan(a) "<<std::endl;
    std::cin>>what_to_use;
 switch(what_to_use){
     case 't' :
         num =whatnum();
         num = tan(num);
         break;
     case 's' :
         num =whatnum();
         num = sin(num);
         break;
     case 'c' :
         num =whatnum();
         num = cos(num);
         break;
     case 'a' :
         num =whatnum();
         num = cos(num)/sin(num);
         break;
     default:
         std::cout<<"that's not it"<<std::endl;

 }
 return num;
}

int main() {
    double number, result;


    result = choice(number);

    std::cout<<result;

}
