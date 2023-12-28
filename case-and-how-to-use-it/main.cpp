#include <iostream>
#include <cmath>
using namespace std;

int main() {
  int x, y, res;
  char char1;

  cout << "Enter the first number, operator, and the second number: ";
  cin >> x >> char1 >> y;

  switch (char1) {
    case '+':
      res = x + y;
      break;

    case '-':
      res = x - y;
      break;

    case '*':
      res = x * y;
      break;

    case '/':
      if(!(y==0))
        res = x / y;
      else {
        cout << "nonononononononononono you troll" << endl;
        res = 0;
      }
      break;

    case '%':
      res = x % y;
      break;

    case '^':
      res = pow(x, y); // Power operator
      break;

    case '&':
      res = x & y; // Bitwise AND operator
      break;

    case '|':
      res = x | y; // Bitwise OR operator
      break;

    case 'r':
      res = sqrt(x); // Square root
      break;
    // You can add additional mathematical functions as needed

    default:
      cout << "Invalid operator" << endl;
      return 1;
  }

  cout << "Result: " << res;

  return 0;
}
