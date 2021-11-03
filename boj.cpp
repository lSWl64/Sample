#include <iostream>
#include <random>
using namespace std;

int main()
{
  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<int> dis(0,3);
  int rNum;
  for(int i =0; i<20; i++)
  {

  rNum = dis(gen) % 4;
  cout << rNum;
  }
}
