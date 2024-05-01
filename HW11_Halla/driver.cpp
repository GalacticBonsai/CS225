#include "queue.h"
#include <cassert>
//--------------
// client code
//--------------

//--------------------
// non-member, friend
//--------------------
std::ostream& operator<<(std::ostream& out, queue& obj)
{
  int temp;
  for (int i = 0; i < obj.size(); i++)
  {
    temp = obj.deque();
    std::cout << temp << ", ";
    obj.enque(temp);
  }
  std::cout << std::endl;
  return out;
} //end operator<<

int main()
{
  queue intList(25);

  for (int i = 0; i < 8; i++)
    intList.enque(i * 10 + 5);
  std::cout << "intList: " << intList << std::endl;

  //Create temp and initialize it using intList
  queue temp(intList);
  std::cout << "temp: " << temp << std::endl;

  //Replace the first element of temp.
  temp.deque();
  std::cout << "temp first element removed: " << temp << std::endl;

  std::cout << "intList: " << intList << std::endl;

  assert(temp.isEmpty() == false);
  assert(temp.size() == 7);
  assert(temp.front() == 15);
  assert(temp.back() == 75);
  
  return 0;
} // end main