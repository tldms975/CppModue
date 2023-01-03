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
    int animalCount = 100;
    Animal* animals[animalCount];

    for (int i = 0; i < animalCount / 2; i++)
      animals[i] = new Cat();
    for (int i = animalCount / 2; i < animalCount; i++)
      animals[i] = new Dog();

    for (int i = 0; i < animalCount; i++)
      delete animals[i];
  }
  std::cout << "--------------------\n";
  {
    Cat* cat1 = new Cat("cat's idea");
    Cat* cat2 = new Cat();

    cat1->getBrain()->printIdea();
    cat2->getBrain()->printIdea();

    delete cat1;
    delete cat2;
  }
}
