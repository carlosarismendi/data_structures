#include <iostream>

using namespace std;

#include "tporo.h"
#include "dlist.h"

int
main(void)
{
  TPoro a(1, 2, 3, (char *)"rojo");
  dlist<TPoro> v, w;

  cout << "Longitud: " << v.size() << endl;
  cout << "Longitud: " << w.size() << endl;

  w = v;

  cout << "Longitud: " << v.size() << endl;
  cout << "Longitud: " << w.size() << endl;
}
