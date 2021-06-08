#include <iostream>

using namespace std;

#include "tporo.h"
#include "vector.h"

int
main(void)
{
  TPoro a(1, 2, 3, (char *)"rojo");
  vector<TPoro> v(5);

  v.push_back(a);
  v.push_back(a);
  v.push_back(a);
  v.push_back(a);
  v.push_back(a);

  cout << v << endl;
}
