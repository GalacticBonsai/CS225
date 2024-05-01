#pragma once
/*
Written by Joseph Halla on 11/22/2022
*/

// no more MAX
class dynListType
{
public:
  //constructor
  dynListType(int max =5);

  // copy constructor
  dynListType(const dynListType& dlt);
  
  //destructor
  ~dynListType();
  
  int getSize() const { return size; }            // return # of elements actually stored
  int getMaxSize() const { return maxSize; }      // return capacity
  bool isEmpty() const { return size == 0; }
  bool isFull() const { return size == maxSize; }

  int search(int element) const;        // look for an item. return index of first occurrence
  int at(int index) const;              // return element at a specific location
  void print() const;                   // print content of list on screen in format of [a, b, c] (like what ArrayList in Java does)

  bool insert(int element);             // append/insert an element at the end
  bool insert(int index, int element);
  // insert an element into location index. 
  // Shifts the element currently at that index (if any) and any subsequent elements to the right

  bool remove(int index);               // remove element at the specified location

  dynListType& operator=(const dynListType& other) noexcept;
  bool operator==(const dynListType& other);

private:
  int* dataPtr;
  int size;
  int maxSize;
};
