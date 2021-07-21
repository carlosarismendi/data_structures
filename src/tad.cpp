#include <iostream>

using namespace std;

#include "tporo.h"
#include "vector.h"

int
main(void)
{
  TPoro a(1, 2, 3, (char *)"rojo");
  vector<TPoro> v(5);

  cout << "Cantidad: " << v.size() << endl;

  v.push_back(a);
  cout << "Cantidad: " << v.size() << endl;

  v.push_back(a);
  cout << "Cantidad: " << v.size() << endl;

  v.push_back(a);
  cout << "Cantidad: " << v.size() << endl;

  v.push_back(a);
  cout << "Cantidad: " << v.size() << endl;

  v.push_back(a);
  cout << "Cantidad: " << v.size() << endl;
}
