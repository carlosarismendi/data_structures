#include <iostream>

using namespace std;

#include "tporo.h"
#include "vector.h"

int
main(void)
{
  TPoro auxOK;
  vector<TPoro> a, b(5), c(10);

  cout << a.capacity() << endl;
  cout << b.capacity() << endl;
  cout << c.capacity() << endl;
}
