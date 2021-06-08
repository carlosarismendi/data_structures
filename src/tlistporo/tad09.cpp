#include <iostream>

using namespace std;

#include "tporo.h"
#include "dlist.h"

int
main(void)
{
  TPoro a(1, 2, 3, (char *)"rojo");

  dlist<TPoro> p;
  dlist<TPoro> v;
  dlist<TPoro> b(v);

  v.push_back(a);
  v.push_back(a);
  v.push_back(a);

  dlist<TPoro> x(v);
  dlist<TPoro> z;

  cout << "******TESTING CONSTRUCTORS, OPERATOR[], OPERATOR= AND GETTERS******" << endl;

  cout << p.size() << endl;
  cout << p << endl;

  cout << b.size() << endl;
  cout << b << endl;

  cout << v.size() << endl;
  v.push_back(a);
  v.push_back(a);
  cout << v.size() << endl;
  cout << v << endl;

  cout << x.size() << endl;
  cout << x << endl;

  z = v;
  cout << z.size() << endl;
  cout << z << endl;
}
