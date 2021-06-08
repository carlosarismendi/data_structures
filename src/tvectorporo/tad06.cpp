#include <iostream>

using namespace std;

#include "tporo.h"
#include "vector.h"

int
main(void)
{
  TPoro a(1, 2, 3, (char *)"rojo");
  vector<TPoro> v(5), w;

  v.push_back(a);
  v.push_back(a);
  v.push_back(a);
  v.push_back(a);
  v.push_back(a);

  w = v;

  cout << v << endl;
  cout << w << endl;
}
