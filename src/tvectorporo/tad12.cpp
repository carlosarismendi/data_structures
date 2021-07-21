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

  v.push_back(a);
  // v.push_back(b);
  // v.push_back(c);
  // v.push_back(d);
  // v.push_back(e);

  // cout << v.size() << endl; // 5

  // v.pop_back();
  // cout << v.size() << endl; // 4

  // v.pop_back();
  // cout << v.size() << endl; // 3

  // v.pop_back();
  // cout << v.size() << endl; // 2

  // v.pop_back();
  // cout << v.size() << endl; // 1

  // v.pop_back();
  // cout << v.size() << endl; // 0

  // v.pop_back();
  // cout << v.size() << endl; // 0
}
