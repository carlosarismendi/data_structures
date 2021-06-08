#include <iostream>

using namespace std;

#include "tporo.h"
#include "dlist.h"

int
main(void)
{
  TPoro a(1, 2, 3, (char *)"rojo");

  dlist<TPoro> v;
  cout << v.empty() << endl;

  v.push_back(a);
  cout << v.size() << " " << v.empty() << endl;

  v.push_back(a);
  cout << v.size() << " " << v.empty() << endl;

  v.push_back(a);
  cout << v.size() << " " << v.empty() << endl;

  v.push_back(a);
  cout << v.size() << " " << v.empty() << endl;

  v.push_back(a);
  cout << v.size() << " " << v.empty() << endl;
}
