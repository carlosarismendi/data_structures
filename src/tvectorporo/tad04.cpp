#include <iostream>

using namespace std;

#include "tporo.h"
#include "vector.h"

int
main(void)
{
  vector<TPoro> a(5);
  vector<TPoro> b;

  if(a == b)
    cout << "SI"  << endl;
  else
    cout << "NO" << endl;
}
