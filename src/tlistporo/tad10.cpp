#include <iostream>

using namespace std;

#include "tporo.h"
#include "dlist.h"

int
main(void)
{
  TPoro a(1, 2, 3, (char *)"rojo");

  dlist<TPoro> v;
  
  v.push_back(a);
  v.push_back(a);
  v.push_back(a);
  v.push_back(a);
  v.push_back(a);

  dlist<TPoro> w(v);
  dlist<TPoro> x = v;

  if(v == w)
    cout << "true" << endl;

  if(v == x)
    cout << "true" << endl;

  if(v != w)
    cout << "ERROR v != w" << endl;

  if(v != x)
    cout << "ERROR v != x" << endl;
}
