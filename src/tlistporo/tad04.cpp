#include <iostream>

using namespace std;

#include "tporo.h"
#include "dlist.h"

int
main(void)
{
  dlist<TPoro> a;
  dlist<TPoro> b;

  if(a == b)
    cout << "SI"  << endl;
  else
    cout << "NO" << endl;
}
