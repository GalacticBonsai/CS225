#include <string>
#include <iostream>
#include <algorithm>

const char ALPHABET[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
const char numberline[] = "0123456789";

std::string encrypt(std::string input) {
  // rotate
  int rotate_ammount = 0;
  if (input.length() % 2) {
    rotate_ammount = input.length() / 2 + 1;
  }
  else {
    rotate_ammount = input.length() / 2;
  }

  std::rotate(input.begin(), input.begin() + rotate_ammount, input.end());

  // letter swap
  for (int i = 0; i < input.length(); i++) {
    if (strchr(ALPHABET, input[i])) {
      const char* found = strchr(ALPHABET, input[i]);
      int index = found - ALPHABET +1;

      input[i] = ALPHABET[26 - index];
    }
    if (strchr(alphabet, input[i])) {
      const char* found = strchr(alphabet, input[i]);
      int index = found - alphabet +1;

      input[i] = alphabet[26 - index];
    }
    if (strchr(numberline, input[i])) {
      const char* found = strchr(numberline, input[i]);
      int index = found - numberline +1;

      input[i] = numberline[10 - index];
    }
  }

  return input;
}

// The encryption is almost perfectly reflexive, so to decrypt we run encrypt again and rotate once if needed.
std::string decrypt(std::string input) {
  input = encrypt(input);

  if (input.length() % 2) {
    std::rotate(input.begin(), input.end()-1, input.end());
  }

  return input;
}

int main() 
{
  std::string str = "Secret 12";
  std::string secretStr = encrypt(str);
  std::cout << "original:  " << str << '\n';
  std::cout << "encrypted: " << secretStr << '\n';
  std::cout << "decrypted: " << decrypt(secretStr) << '\n';

  str = "123456";
  secretStr = encrypt(str);
  std::cout << "original:  " << str << '\n';
  std::cout << "encrypted: " << secretStr << '\n';
  std::cout << "decrypted: " << decrypt(secretStr) << '\n';

  str = "this is much longer but is otherwise simple";
  secretStr = encrypt(str);
  std::cout << "original:  " << str << '\n';
  std::cout << "encrypted: " << secretStr << '\n';
  std::cout << "decrypted: " << decrypt(secretStr) << '\n';

  return 0;
}