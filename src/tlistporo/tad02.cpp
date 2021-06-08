#include <iostream>

using namespace std;

#include "tporo.h"
#include "dlist.h"

int
main(void)
{
  TPoro auxOK;
  dlist<TPoro> a, b, c{ b };

  cout << a.size() << endl;
  cout << b.size() << endl;
  cout << c.size() << endl;
}
