/*
Written by Joseph Halla on 11/22/2022
*/

#include <cassert>
#include "dynListType.h"
#include <malloc.h>

//constructor with default
dynListType::dynListType(int max) {
  this->maxSize = max;
  this->size = 0;
  this->dataPtr = (int*)calloc(max, sizeof(int));
}

dynListType::~dynListType() {
  free(this->dataPtr);
}
dynListType::dynListType(const dynListType& dlt) {
  this->maxSize = dlt.getMaxSize();
  this->dataPtr = (int*)calloc(this->maxSize, sizeof(int));

  for (int i = 0; i < dlt.getSize(); i++) {
    this->insert(dlt.at(i));
  }
}

// look for an item. return index of first occurrence
int dynListType::search(int element) const {
  for (int i = 0; i < this->size; i++) {
    if (this->dataPtr[i] == element)
    {
      return i;
    }
  }
  return -1;
}

// return element at a specific location
int dynListType::at(int index) const {
  assert(index >= 0 && index < this->size);
  return this->dataPtr[index];
}
/*
//Commented out for part 2;
// print content of list on screen in format of [a, b, c]
void dynListType::print() const {
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
bool dynListType::insert(int element) {
  // If size before insertion is equal to maxSize // current maxSize reached
  if (this->size == this->maxSize)
  {
    // maxSize < -2 * maxSize
    this->maxSize *= 2;

    // allocate a new dynamic array with maxSize slots
    int* tempPtr = (int*)calloc(this->maxSize, sizeof(int));

    // copy data pointed by dataPtr over to new array
    for (int i = 0; i < size; i++)
    {
      tempPtr[i] = this->dataPtr[i];
    }
    // delete the dynamic array currently pointed by dataPtr
    free(this->dataPtr);
    // let dataPtr point to the newly allocated dynamic array
    this->dataPtr = tempPtr;
    // End if
  }
  // Insert as normal
  this->dataPtr[this->size] = element;
  this->size++;
  return true;
}

// insert an element into location index
// Shifts the element currently at that index (if any) and any subsequent elements to the right
bool dynListType::insert(int index, int element)
{
  // If size before insertion is equal to maxSize // current maxSize reached
  if (this->size == this->maxSize)
  {
    // maxSize < -2 * maxSize
    this->maxSize *= 2;
    
    // allocate a new dynamic array with maxSize slots
    int* tempPtr = (int*)calloc(this->maxSize, sizeof(int));
    
    // copy data pointed by dataPtr over to new array
    for (int i = 0; i < size; i++)
    {
      tempPtr[i] = this->dataPtr[i];
    }
    // delete the dynamic array currently pointed by dataPtr
    free(this->dataPtr);
    // let dataPtr point to the newly allocated dynamic array
    this->dataPtr = tempPtr;
    // End if
  }
  // Insert as normal
  if (index >= this->size || index < 0)
  {
    return false;
  }
  for (int i = this->size; i > index; i--) {
    this->dataPtr[i] = this->dataPtr[i - 1];
  }
  this->dataPtr[index] = element;
  this->size++;
  return true;
}

// remove element at the specified location
bool dynListType::remove(int index) {
  if (this->size <= 0 || index >= this->size || index < 0)
  {
    return false;
  }
  for (int i = index; i < this->size; i++)
  {
    this->dataPtr[i] = this->dataPtr[i + 1];
  }
  this->size--;
  return true;
}

bool dynListType::operator==(const dynListType& other)
{
  if (other.getSize() != this->getSize())
  {
    return false;
  }
  for (int i = 0; i < other.getSize(); i++)
  {
    if(this->at(i) != other.at(i));
    {
      return false;
    }
  }
  return true;
}