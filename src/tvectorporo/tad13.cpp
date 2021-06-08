#include <iostream>

using namespace std;

#include "tporo.h"
#include "vector.h"

int
main(void)
{
  TPoro a(1, 1, 1, (char *)"rojo");
  TPoro b(2, 2, 2, (char *)"verde");
  TPoro c(3, 3, 3, (char *)"azul");
  TPoro d(4, 4, 4, (char *)"marron");
  TPoro e(5, 5, 5, (char *)"gris");

  vector<TPoro> v;

  v.insert(a, 0);

  v.push_back(b);
  v.push_back(e);

  v.insert(c, 2);
  cout << v.size() << endl;
  cout << v << endl;

  v.insert(d, 3);
  cout << v.size() << endl;
  cout << v << endl;
}
