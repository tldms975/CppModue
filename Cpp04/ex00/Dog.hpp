#ifndef DOG_HPP
#define DOG_HPP
#include "Animal.hpp"

class Dog : public Animal
{
	public:
		Dog();
		Dog(const Dog &c);
		virtual ~Dog();
		Dog& operator=(const Dog &c);
		virtual void	makeSound() const;
};

#endif