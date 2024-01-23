#include <iostream>
#include <string>
using namespace std;
int main()
{
  string jmeno[2][5] = {
      {"david", "milan", "josef", "jakub", "tomas"},
      {"heslo123", "heslo456", "heslo", "hesloheslo", "heslo123456789"}
  };
  string jmenoUzivatele;
  string hesloUzivatele;
  bool validCredentials = false;
  cout << "prosim zadejte jmeno: ";
  cin >> jmenoUzivatele;
  cout << "prosim zadejte heslo: ";
  cin >> hesloUzivatele;
  for (int i = 0; i < 5; i++)
  {
    if (jmeno[0][i] == jmenoUzivatele && jmeno[1][i] == hesloUzivatele)
    {
      validCredentials = true;
      break;
    }
  }
  if (validCredentials)
  {
    cout << "Access granted." << endl;
  }
  else
  {
    cout << "Invalid username or password." << endl;
  }
  return 0;
}
