#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal {
	private:
		Brain*	brain;
	public:
		Dog();
		Dog(const Dog& d);
		Dog& operator=(const Dog& d);
		virtual ~Dog();

		Dog(const std::string& idea);
		std::string		getType(void) const;
		void					setType(const std::string& idea);
		virtual void	makeSound(void) const;

		Brain*	getBrain(void) const;
};

#endif
