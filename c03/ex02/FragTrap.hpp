#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
  public:
    FragTrap(void);
    FragTrap(const std::string& name);
    FragTrap(const std::string& name,
              const int& health,
              const int& energy,
              const int& damage
            );
    FragTrap(const FragTrap& f);
    FragTrap& operator=(const FragTrap& f);
    ~FragTrap(void);

    void  attack(const std::string& target);
    void  takeDamage(unsigned int amount);
    void  beRepaired(unsigned int amount);
    void  highFivesGuys(void);
};

#endif