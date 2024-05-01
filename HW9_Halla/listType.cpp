#include <cassert>
#include <iostream>

#include "listType.h"

listType::listType(int max)
{
  this->size = 0;
  this->maxSize = max;
  this->dataArr[100] = {0};
}

// look for an item. return index of first occurrence
  int listType::search(int element) const {
    for (int i = 0; i < this->size; i++) {
      if (this->dataArr[i] == element)
      {
        return i;
      }
    }
    return -1;
  }

  // return element at a specific location
  int listType::at(int index) const {
    assert(index >= 0 && index < this->size);
    return this->dataArr[index];
  }
  /*
  //Commented out for part 2;
  // print content of list on screen in format of [a, b, c]
  void listType::print() const {
    std::cout << "[";
    for (int i = 0; i < this->size; i++) {
      std::cout << at(i);
      if (i < this->size - 1) {
        std::cout << ", ";
      }
    }
    std::cout << "]" << std::endl;
  } */

  // append/insert an element at the end
  bool listType::insert(int element) {
    if (this->size < this->maxSize) {
      this->dataArr[this->size] = element;
      this->size++;
      return true;
    }
    return false;
  }

  // insert an element into location index
  // Shifts the element currently at that index (if any) and any subsequent elements to the right
  bool listType::insert(int index, int element)
  {
    if (this->size == this->maxSize || index >= this->size || index < 0)
    {
      return false;
    }
    for (int i = this->size; i > index; i--) {
      this->dataArr[i] = this->dataArr[i - 1];
    }
    this->dataArr[index] = element;
    this->size++;
    return true;
  }

  // remove element at the specified location
  bool listType::remove(int index) {
    if (this->size <= 0 || index >= this->size || index < 0)
    {
      return false;
    }
    for (int i = index; i < this->size; i++)
    {
      this->dataArr[i] = this->dataArr[i + 1];
    }
    this->size--;
    return true;
  }

