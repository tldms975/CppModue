/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasong <jasong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:17:31 by jasong            #+#    #+#             */
/*   Updated: 2022/09/03 04:54:55 by jasong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook()
  : old_idx(0), size(0) {}

void PhoneBook::add(void) {
  if (this->size < 8)
  {
    this->contacts[this->size].setFirstname();
    if (std::cin.fail())
      return ;
    this->contacts[this->size].setLastname();
    if (std::cin.fail())
      return ;
    this->contacts[this->size].setNickname();
    if (std::cin.fail())
      return ;
    this->contacts[this->size].setPhonenumber();
    if (std::cin.fail())
      return ;
    this->contacts[this->size].setSecret();
    if (std::cin.fail())
      return ;
    this->size++;
  }
  else {
    this->contacts[this->old_idx].setFirstname();
    if (std::cin.fail())
      return ;
    this->contacts[this->old_idx].setLastname();
    if (std::cin.fail())
      return ;
    this->contacts[this->old_idx].setNickname();
    if (std::cin.fail())
      return ;
    this->contacts[this->old_idx].setPhonenumber();
    if (std::cin.fail())
      return ;
    this->contacts[this->old_idx].setSecret();
    if (std::cin.fail())
      return ;
    this->old_idx++;
    if (this->old_idx > 8)
      this->old_idx = 0;
  }
}

void  PhoneBook::output(std::string s) {
  std::string sub;

  if (s.length() > 10) {
    sub = s.substr(0, 9) + ".";
    std::cout << sub;
  }
  else
    std::cout << s;
}

void PhoneBook::displayList(void) {
  std::cout << "+-------------------------------------------+" << std::endl;
  std::cout << "|     Index|First name| Last name|  Nickname|" << std::endl;
  std::cout << "+-------------------------------------------+" << std::endl;
  for (int i = 0; i < this->size; i++) {
    std::cout << '|';
    std::cout << std::setfill(' ') << std::setw(10) << std::right; // index
    std::cout << i + 1;
    std::cout << '|';
    std::cout << std::setfill(' ') << std::setw(10) << std::right; // first name
    this->output(this->contacts[i].getFirstname());
    std::cout << '|';
    std::cout << std::setfill(' ') << std::setw(10) << std::right; // last name
    this->output(this->contacts[i].getLastname());
    std::cout << '|';
    std::cout << std::setfill(' ') << std::setw(10) << std::right; // nickname
    this->output(this->contacts[i].getNickname());
    std::cout << '|' << std::endl;
    std::cout << "+-------------------------------------------+" << std::endl;
  }
}

void PhoneBook::search(void) {
  int input_idx;
  int valid;

  this->displayList();
  valid = false;
  while (valid == false) {
    std::cout << "Put the index number : ";
    std::cin >> input_idx;
    if (std::cin.eof()) {
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      return ;
    }
    if (input_idx > size || input_idx < 1) {
      std::cout << "Invalid index" << std::endl;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      return ;
    }
    else
      valid = true;
  }
  std::cout << this->contacts[input_idx - 1].getFirstname() << std::endl;
  std::cout << this->contacts[input_idx - 1].getLastname() << std::endl;
  std::cout << this->contacts[input_idx - 1].getNickname() << std::endl;
  std::cout << this->contacts[input_idx - 1].getPhonenumber() << std::endl;
  std::cout << this->contacts[input_idx - 1].getSecret() << std::endl;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
