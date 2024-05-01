#include <iostream>
#include <cassert>
#include "listType.h"

// Standalone function declared in driver with no relation to listType
std::ostream& operator<<(std::ostream& os, const listType& lt)
{
  int size = lt.getSize();

  os << "[";
  for (int i = 0; i < size; i++) {
    os << lt.at(i);
    if (i < size - 1) {
      os << ", ";
    }
  }
  os << "]" << std::endl;
  return os;
}

listType& operator+(listType& a, listType& b)
{
  int max_size = a.getMaxSize() + b.getMaxSize();
  int new_size = a.getSize() + b.getSize();
  listType c = listType(max_size);
  int temp;

  for (int i = 0; i < new_size; i++) {
    
    // The docs say order doesn't matter, should be easiest way to populate new class. 
    if (i < a.getSize())
    {
      c.insert(a.at(i));
    }
    if (i < b.getSize())
    {
      c.insert(b.at(i));
    }
  }

  return c;
}

int main() {
  listType a = listType(3);
  a.insert(1);
  a.insert(0, 2);
  //a.print();
  std::cout << "list a: " << a << std::endl;
  listType b = listType(2);
  b.insert(59);
  b.insert(69);

  listType c = a + b;

  std::cout << "list b: " << b << std::endl << "list c = a + b:" << c << std::endl;

  // testing arbitrary functions
  assert(c.search(69) == 3);
  assert(c.remove(0));
  assert(c.search(69) == 2);

  return 0;
}