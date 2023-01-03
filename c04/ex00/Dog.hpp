#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal {
	public:
		Dog();
		Dog(const Dog& d);
		Dog& operator=(const Dog& d);
		virtual ~Dog();

		std::string		getType(void) const;
		void					setType(const std::string& type);
		virtual void	makeSound(void) const;
};

#endif
