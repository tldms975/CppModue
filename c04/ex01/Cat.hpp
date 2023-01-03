#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal {
	private:
		Brain*	brain;
	public:
		Cat();
		Cat(const Cat& c);
		Cat& operator=(const Cat& c);
		virtual ~Cat();

		Cat(const std::string& idea);
		std::string		getType(void) const;
		void					setType(std::string type);
		virtual void makeSound(void) const;

		Brain*	getBrain(void) const;
};

#endif