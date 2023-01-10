#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include "ClapTrap.hpp"
# include <string>

class ScavTrap : virtual public ClapTrap
{
	public:
		ScavTrap(void);
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap& c);
		~ScavTrap(void);
		ScavTrap&	operator=(const ScavTrap& c);
		void		guardGate(void);
		void		attack(std::string const& target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
};

#endif