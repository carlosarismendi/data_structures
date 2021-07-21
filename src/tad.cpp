#include <iostream>

using namespace std;

#include "tporo.h"
#include "vector.h"

int
main(void)
{
  TPoro a(1, 2, 3, (char *)"rojo");

  vector<TPoro> p;
  vector<TPoro> v(5);
  vector<TPoro> b(v);

  v.push_back(a);
  v.push_back(a);
  v.push_back(a);

  vector<TPoro> x(v);
  vector<TPoro> z;

  cout << "******TESTING CONSTRUCTORS, OPERATOR[], OPERATOR= AND GETTERS******" << endl;

  cout << p.capacity() << ", "<< p.size() << endl;
  cout << p << endl;

  cout << b.capacity() << ", "<< b.size() << endl;
  cout << b << endl;

  cout << v.capacity() << ", "<< v.size() << endl;
  v.push_back(a);
  v.push_back(a);
  cout << v.capacity() << ", "<< v.size() << endl;
  cout << v << endl;

  cout << x.capacity() << ", "<< x.size() << endl;
  cout << x << endl;

  z = v;
  cout << z.capacity() << ", "<< z.size() << endl;
  cout << z << endl;
}
