#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
	std::cout << "Brain Default Constructor called\n";
}

Brain::Brain(const Brain &c)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = c.ideas[i];
	std::cout << "Brain Copy Constructor called\n";
}

Brain& Brain::operator=(const Brain &c)
{
	if (this == &c)
		return (*this);
	for (int i = 0; i < 100; i++)
		this->ideas[i] = c.ideas[i];
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain Destructor called\n";
}

void	Brain::printIdeas() const
{
	for (int i = 0; i < 100; i++)
		std::cout << "Idea[" << i << "] : " <<  this->ideas[i] << std::endl;
}

void	Brain::setIdea(unsigned int idx, const std::string idea)
{
	this->ideas[idx] = idea;
}