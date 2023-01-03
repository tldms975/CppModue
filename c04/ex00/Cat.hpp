#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal {
	public:
		Cat();
		Cat(const Cat& c);
		Cat& operator=(const Cat& c);
		virtual ~Cat();

		std::string		getType(void) const;
		void					setType(std::string type);
		virtual void makeSound(void) const;
};

#endif