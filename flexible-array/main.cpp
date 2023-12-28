#include <iostream>
#include <vector>
#include <math.h>

// this is suprisingly complex
using namespace std;
int main()
{
  int howmany;
  cout << "how many ints do you want:";
  cin >> howmany;
  vector<int> ar(howmany);
  for (int i = 0; i < howmany; i++)
  {
    cout << "enter number " << i + 1 << " " << endl;
    cin >> ar[i];
  }
  int max = ar[0];
  for (int i = 1; i < howmany; i++)
  {
    if (ar[i] > max)
    {
      max = ar[i];
    }
  }
  cout << "The maximum number is: " << max << endl;
  return 0;
}
