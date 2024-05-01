#include "queue.h"

bool queue::isEmpty() const {
  return (length == 0);
}

int queue::size() const {
  return length;
}

int queue::front() const {
  int item;
  retrieveAt(0, item);
  return item;
}
// returns the element at the front of the queue. This should be the "oldest" element, the same element that will be removed if deque() is called next
// Pre: the queue is not empty
// Post: returns the element at the front of the queue

int queue::back() const {
// this isn't how queues work, unless you want to clear the whole queue just to get to the last element? I'll just implement it anyways
  int item;
  retrieveAt(size() - 1, item);
  return item;
}
// returns the element at the back of the queue. This should be the "youngest" element, the same element that was added into the queue most recently using enque()
// Pre: the queue is not empty
// Post: returns the element at the back of the queue

// insert one element at the back of the queue, after its current last element (the "youngest" element before this enque)
 // Post: newItem added at the end of the queue, after the current last element
void queue::enque(int newItem) {
  insertEnd(newItem);
} 

// remove one element from the front of the queue. The "oldest" element should be removed
// Pre: the queue is not empty
// Post: the item at the front of the queue is removed from the queue and returned
int queue::deque() {
  int temp = front();
  removeAt(0);
  return temp;
}

queue::queue(int size): unorderedArrayListType(size)
{
}  //end constructor