/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sielee <sielee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 19:12:07 by jasong            #+#    #+#             */
/*   Updated: 2022/12/14 02:45:11 by sielee           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#define P_ADD 1
#define P_SEARCH 2
#define P_EXIT 3
#define P_DISCARD 4

#include "PhoneBook.hpp"

bool getStatus(int &status) {
  std::string cmd;

  if (std::cin.fail()) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << std::endl;
    return (false);
  }
  std::cout << "Put command - <ADD, SEARCH, EXIT>" << std::endl;
  std::getline(std::cin, cmd);
  if (cmd == "ADD")
    status = P_ADD;
  else if (cmd == "SEARCH")
    status = P_SEARCH;
  else if (cmd == "EXIT")
    return (false);
  else
    status = P_DISCARD;
  if (std::cin.fail()) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return (false);
  }
  return (true);
}

int main(void) {
  PhoneBook   pb;
  std::string input;
  int         status;

  while (true) {
    if (!getStatus(status))
      break ;
    switch (status) {
      case P_ADD:
        pb.add();
        break ;
      case P_SEARCH:
        pb.search();
        break ;
      default:
        std::cout << "Error: Not valid command" << std::endl;
    }
  }
  std::cout << "Program exited" << std::endl;
  return (0);
}
