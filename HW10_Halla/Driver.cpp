/*
Written by Joseph Halla on 11/22/2022
*/
#include <iostream>
#include <cassert>
#include "dynListType.h"

// Standalone function declared in driver with no relation to dynListType
std::ostream& operator<<(std::ostream& os, const dynListType& lt)
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

const dynListType& operator+(dynListType& a, dynListType& b)
{
  int max_size = a.getMaxSize() + b.getMaxSize();
  int new_size = a.getSize() + b.getSize();

  // use new to allocate this to the heap and not the stack
  dynListType* c = new dynListType(max_size);


  for (int i = 0; i < new_size; i++) {

    // The docs say order doesn't matter, should be easiest way to populate new class. 
    if (i < a.getSize())
    {
      c->insert(a.at(i));
    }
    if (i < b.getSize())
    {
      c->insert(b.at(i));
    }
  }

  return *c;
}

dynListType& dynListType::operator=(const dynListType &other) noexcept
{
  while (this->remove(0));
  
  this->maxSize = other.maxSize;
  for (int i = 0; i < other.getSize(); i++)
  {
    this->insert(other.at(i));
  }
  return *this;
}


int main() {
  dynListType a = dynListType(3);
  a.insert(1);
  a.insert(0, 2);
  //a.print();
  std::cout << "list a: " << a << std::endl;
  dynListType b = dynListType(2);
  b.insert(59);
  b.insert(69);

  dynListType c = a + b;

  std::cout << "list b: " << b << std::endl << "list c = a + b:" << c << std::endl;

  // testing arbitrary functions
  assert(c.search(69) == 3);
  assert(c.remove(0));
  assert(c.search(69) == 2);

  // test expansibility
  dynListType d = dynListType(1);
  for (int i = 0; i < 100; i++)
  {
    d.insert(i);
    d.insert(i-1, i);
    std::cout << "d loop:" << d << std::endl;
  }

  return 0;
}