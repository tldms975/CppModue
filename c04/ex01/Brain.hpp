#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>

class Brain {
  private:
    std::string ideas[100];

  public:
    Brain();
    Brain(const Brain& b);
    Brain& operator=(const Brain& b);
    ~Brain();

    Brain(const std::string& idea);
    void  printIdea(void) const;
};

#endif