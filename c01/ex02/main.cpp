#include <iostream>
#include <string>

int main(void) {
  std::string str = "HI THIS IS BRAIN";
  std::string *stringPTR = &str;
  std::string &stringREF = str;

  std::cout << "------------ origin str address ------------" << std::endl;
  std::cout << &str << std::endl;
  std::cout << "------------ stringPTR address ------------" << std::endl;
  std::cout << stringPTR << std::endl;
  std::cout << "------------ stringREF address ------------" << std::endl;
  std::cout << &stringREF << std::endl;
  std::cout << "------------ print origin str ------------" << std::endl;
  std::cout << str << std::endl;
  std::cout << "------------ print stringPTR ------------" << std::endl;
  std::cout << *stringPTR << std::endl;
  std::cout << "------------ print stringREF ------------" << std::endl;
  std::cout << stringREF << std::endl;
}