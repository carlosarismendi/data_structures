#include <iostream>

using namespace std;

#include "tporo.h"
#include "vector.h"

int
main(void)
{
  TPoro a(1, 2, 3, (char *)"rojo");
  vector<TPoro> v(5), w;

  cout << "Longitud: " << v.capacity() << endl;
  cout << "Longitud: " << w.capacity() << endl;

  w = v;

  cout << "Longitud: " << v.capacity() << endl;
  cout << "Longitud: " << w.capacity() << endl;
}
