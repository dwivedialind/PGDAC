#include <iostream>
#include <string>

int main() {
  std::string myString = "This string has some non-ASCII characters: ¡Hola!"; // ¡ and ¿ require 2 bytes each
  std::cout << "String content: " << myString << std::endl;
  std::cout << "Size of string: " << myString.size() << " characters" << std::endl;
  std::cout << "Size of string in bytes: " << sizeof(myString) << " bytes (might include overhead)" << std::endl;
  return 0;
}
