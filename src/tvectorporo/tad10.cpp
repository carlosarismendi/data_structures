#include <iostream>

using namespace std;

#include "tporo.h"
#include "vector.h"

int
main(void)
{
  TPoro a(1, 2, 3, (char *)"rojo");

  vector<TPoro> v(5);
  
  v.push_back(a);
  v.push_back(a);
  v.push_back(a);
  v.push_back(a);
  v.push_back(a);

  vector<TPoro> w(v);
  vector<TPoro> x = v;

  cout << "******TESTING REDIMENSIONAR, OPERATOR== AND OPERATOR!=******" << endl;

  if(v == w)
    cout << "true" << endl;

  if(v == x)
    cout << "true" << endl;

  cout << v.capacity() << ", "<< v.size() << endl;
  cout << v << endl;

  v.resize(3);

  if(v == w)
    cout << "ERROR" << endl;

  if(v == x)
    cout << "ERROR" << endl;

  cout << v.capacity() << ", "<< v.size() << endl;
  cout << v << endl;

  v.resize(6);

  if(v != w)
    cout << "true" << endl;

  if(v != x)
    cout << "true" << endl;

  cout << v.capacity() << ", "<< v.size() << endl;
  cout << v << endl;

  v.resize(v.capacity());

  cout << v.capacity() << ", "<< v.size() << endl;
  cout << v << endl;

}
