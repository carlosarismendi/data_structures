#include <iostream>

using namespace std;

#include "tporo.h"
#include "dlist.h"

int
main(void)
{
  TPoro a(1, 1, 1, (char *)"rojo");
  TPoro b(2, 2, 2, (char *)"verde");
  TPoro c(3, 3, 3, (char *)"azul");
  TPoro d(4, 4, 4, (char *)"marron");
  TPoro e(5, 5, 5, (char *)"gris");

  dlist<TPoro> v;

  v.push_front(a);
  v.push_front(b);
  v.push_front(c);
  v.push_front(d);
  v.push_front(e);

  cout << v.size() << endl; // 5

  v.pop_front();
  cout << v.size() << endl; // 4
  cout << v << endl;

  v.pop_front();
  cout << v.size() << endl; // 3
  cout << v << endl;

  v.pop_front();
  cout << v.size() << endl; // 2
  cout << v << endl;

  v.pop_front();
  cout << v.size() << endl; // 1
  cout << v << endl;

  v.pop_front();
  cout << v.size() << endl; // 0
  cout << v << endl;

  v.pop_front();
  cout << v.size() << endl; // 0
  cout << v << endl;
}
