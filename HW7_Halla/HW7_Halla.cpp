/*
Written by Joseph Halla on 11/10/2022
*/

#include <iostream>
#include <algorithm>

// read in a number
int* readNum(int& numOfDigits/*OUT*/);

// add two numbers. Store result in third
int* sumNum(const int* pNum1/*IN*/, int numOfDigits1/*IN*/,
  const int* pNum2/*IN*/, int numOfDigits2/*IN*/,
  int& numOfDigitsResult/*OUT*/);

// print a number stored in int array
void print(const int* pNum/*IN*/, int numOfDigits/*IN*/);

int main() {
  int* num1;
  int* num2;
  int* num3;
  int dig1, dig2, dig3;
  num1 = readNum(dig1);
  num2 = readNum(dig2);
  num3 = sumNum(num1, dig1, num2, dig2, dig3);

  print(num3, dig3);
  free(num1);
  free(num2);
  free(num3);
}

// read in a number
int* readNum(int& numOfDigits/*OUT*/) {
  std::string input;
  std::cout << "Enter a positive integer: ";
  std::cin >> input;

  int* storage = (int*)std::calloc(input.length(), sizeof(int));
  for (int i = 0; i < input.length(); i++) {
    storage[i] = input[i] - '0';
  }
  numOfDigits = input.length();
  return storage;
}

// add two numbers. Store result in third
int* sumNum(const int* pNum1/*IN*/, int numOfDigits1/*IN*/,
  const int* pNum2/*IN*/, int numOfDigits2/*IN*/,
  int& numOfDigitsResult/*OUT*/) {

  // make local copies of pnum1 and pnum2 because they are const int*, which means data cannot be modified.
  int* pNum1Copy = (int*)std::calloc(numOfDigits1, sizeof(int));
  memcpy(pNum1Copy, pNum1, numOfDigits1*sizeof(int));
  int* pNum2Copy = (int*)std::calloc(numOfDigits2, sizeof(int));
  memcpy(pNum2Copy, pNum2, numOfDigits2*sizeof(int));


  const int* bigger = pNum1Copy;
  int max_digits = numOfDigits1;
  int min_digits = numOfDigits2;

  if (numOfDigits1 < numOfDigits2)
  {
    bigger = pNum2Copy;
    max_digits = numOfDigits2;
    min_digits = numOfDigits1;
  }

  // allocate output array
  int* out = (int*)std::calloc(max_digits + 1, sizeof(int));

  //reverse to make the math easier. now first digit is 1s place, not most significant digit.
  std::reverse(pNum1Copy, pNum1Copy + numOfDigits1);
  std::reverse(pNum2Copy, pNum2Copy + numOfDigits2);

  for (int i = 0; i <= max_digits + 1; i++)
  {
    if (i < min_digits) {
      out[i] += pNum1Copy[i] + pNum2Copy[i] ;
    }
    else if( i < max_digits)
    {
      out[i] += bigger[i];
    }

    // migrate 10's carry
    if (out[i] >= 10)
    {
      out[i] -= 10;
      out[i+1] = 1;
    }

  }

  free(pNum1Copy);
  free(pNum2Copy);
  numOfDigitsResult = max_digits + 1;
  std::reverse(out, out + numOfDigitsResult);
  return out;
}

// print a number stored in int array
void print(const int* pNum/*IN*/, int numOfDigits/*IN*/) {
  
  std::cout << "The sum of the numbers is: ";

  for (int i = 0; i < numOfDigits; i++) {
    //skip leading 0 if exists
    if (pNum[0] == 0 && i == 0)
    {
      continue;
    }

    // print digit
    std::cout << pNum[i];
}
  std::cout << std::endl;
}