#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>

class Animal {
  protected:
    std::string _type;
  public:
    Animal();
    Animal(const Animal& a);
    Animal& operator=(const Animal& a);
    virtual ~Animal();

    Animal(const std::string& type);
    virtual void  makeSound(void) const;
    void  setType(const std::string& type);
    std::string  getType(void) const;
};

#endif