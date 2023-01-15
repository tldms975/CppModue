#ifndef BRAIN_HPP
#define BRAIN_HPP
#include <string>

class Brain
{
	private:
		std::string ideas[100];
	public:
		Brain();
		Brain(const Brain& c);
		~Brain();
		Brain& operator=(const Brain& c);
		void	setIdea(unsigned int idx, const std::string idea);
		void	printIdeas(void) const;
};

#endif