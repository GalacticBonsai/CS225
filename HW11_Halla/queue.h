#pragma once
#include "unorderredArrayListType.h"

//--------------
// queue (grand-sub)
//--------------
class queue : private unorderedArrayListType
{
public:
  bool isEmpty() const; // test whether queue is empty
  // Post: returns true if queue is empty, otherwise returns false

  int size() const; // return size
  // Post: returns the number of elements in the queue

  int front() const; // returns the element at the front of the queue. This should be the "oldest" element, the same element that will be removed if deque() is called next
  // Pre: the queue is not empty
  // Post: returns the element at the front of the queue

  // this isn't how queues work, unless you want to clear the whole queue just to get to the last element?
  int back() const; // returns the element at the back of the queue. This should be the "youngest" element, the same element that was added into the queue most recently using enque()
  // Pre: the queue is not empty
  // Post: returns the element at the back of the queue

  void enque(int newItem); // insert one element at the back of the queue, after its current last element (the "youngest" element before this enque)
  // Post: newItem added at the end of the queue, after the current last element

  int deque(); // remove one element from the front of the queue. The "oldest" element should be removed
  // Pre: the queue is not empty
  // Post: the item at the front of the queue is removed from the queue and returned

  queue(int size = 100);
  // Post: queue initialized with capacity being size param and contains 0 elements.
  //       if no size is specified, 100 is used for the capacity
};