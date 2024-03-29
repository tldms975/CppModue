#ifndef DOG_HPP
#define DOG_HPP
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain *_brain;
	public:
		Dog();
		Dog(const Dog &c);
		virtual ~Dog();
		Dog& operator=(const Dog &c);
		virtual void	makeSound() const;
		Brain*			getBrain() const;
};

#endif