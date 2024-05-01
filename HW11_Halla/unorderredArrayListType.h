#pragma once
#include "arrayListType.h"

//--------------
// unorderedArrayListType (sub)
//--------------

class unorderedArrayListType : public arrayListType
{
public:
  void insertAt(int location, int insertItem);
  void insertEnd(int insertItem);
  void replaceAt(int location, int repItem);
  int seqSearch(int searchItem) const;
  void remove(int removeItem);

  unorderedArrayListType(int size = 100); //Constructor
};
