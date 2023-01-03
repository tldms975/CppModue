#include <iostream>
#include "Cat.hpp"
#include "Dog.hpp"

int main() {
  {
    const Animal* i = new Cat();
    const Animal* j = new Dog();

    delete j;
    delete i;
  }
  std::cout << "--------------------\n";
  {
    Dog dog1;
    Dog dog2(dog1);
  }
  std::cout << "--------------------\n";
  {
    Cat* cat1 = new Cat();
    Cat* cat2 = new Cat();

    *cat1 = *cat2;

    delete cat2;
    delete cat1;
  }
  std::cout << "--------------------\n";
  {
    // const Animal* a1 = new Animal(); // this might be fail cuz this is abstract class.
    const Animal* a2 = new Cat();
    
    // delete a1; // meaningless... a1 cannot be allocated
    delete a2;
  }
  return (0);
}
