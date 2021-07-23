#include <iostream>

using namespace std;

#include "tporo.h"
#include "vector.h"

int
main(void)
{  
  vector<TPoro> v(2);

  v.emplace_back(1, 2, 3, (char *)"rojo");
  v.emplace_back(1, 2, 3, (char *)"rojo");
  v.emplace_back(1, 2, 3, (char *)"rojo");
  v.emplace_back(1, 2, 3, (char *)"rojo");
  v.emplace_back(1, 2, 3, (char *)"rojo");

  for(const auto& value: v)
    cout << value << endl;
}
