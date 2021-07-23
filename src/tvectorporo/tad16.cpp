#include <iostream>

using namespace std;

#include "tporo.h"
#include "vector.h"

int
main(void)
{  
  vector<TPoro> v(1), w;

  v.emplace_back(1, 2, 3, (char *)"rojo");
  v.emplace_back(1, 2, 3, (char *)"rojo");
  v.emplace_back(1, 2, 3, (char *)"rojo");
  v.emplace_back(1, 2, 3, (char *)"rojo");
  v.emplace_back(1, 2, 3, (char *)"rojo");

  w = v;

  cout << v << endl;
  cout << w << endl;
}
