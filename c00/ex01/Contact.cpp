/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasong <jasong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:59:19 by jasong            #+#    #+#             */
/*   Updated: 2022/09/03 04:27:47 by jasong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string Contact::getFirstname(void) {
  return (this->first_name);
}

std::string Contact::getLastname(void) {
  return (this->last_name);
}

std::string Contact::getNickname(void) {
  return (this->nickname);
}

std::string Contact::getPhonenumber(void) {
  return (this->phonenumber);
}

std::string Contact::getSecret(void) {
  return (this->darkest_secret);
}

void Contact::setFirstname(void) {
  std::string _firstname;

  if (std::cin.fail()) 
    return ;
  while (true) {
    std::cout << "First name : ";
    std::getline(std::cin, _firstname);
    if (std::cin.fail())
      return ;
    else if (_firstname.empty())
      std::cout << "Fields should not be empty." << std::endl;
    else
      break ;
  }
  this->first_name = _firstname;
}

void Contact::setLastname(void) {
  std::string _lastname;

  if (std::cin.fail()) {
    return ;
  }
  while (true) {
    std::cout << "Last name : ";
    std::getline(std::cin, _lastname);
    if (std::cin.fail()) {
      return ;
    }
    else if (_lastname.empty())
      std::cout << "Fields should not be empty." << std::endl;
    else
      break ;
  }
  this->last_name = _lastname;
}

void Contact::setNickname(void) {
  std::string _nickname;

  if (std::cin.fail()) {
    return ;
  }
  while (true) {
    std::cout << "Nickname : ";
    std::getline(std::cin, _nickname);
    if (std::cin.fail()) {
      return ;
    }
    else if (_nickname.empty())
      std::cout << "Fields should not be empty." << std::endl;
    else
      break ;
  }
  this->nickname = _nickname;
}

void Contact::setPhonenumber(void) {
  std::string _phonenumber;

  if (std::cin.fail()) {
    return ;
  }
  while (_phonenumber.empty()) {
    std::cout << "Phonenumber : ";
    std::getline(std::cin, _phonenumber);
    if (std::cin.fail()) {
      std::cout << "An exception occured. Try again" << std::endl;
      break ;
    }
    else if (_phonenumber.empty())
      std::cout << "Fields should not be empty." << std::endl;
    else
      break ;
  }
  this->phonenumber = _phonenumber;
}

void Contact::setSecret(void) {
  std::string _secret;

  if (std::cin.fail()) {
    return ;
  }
  while (_secret.empty()) {
    std::cout << "Darkest secret : ";
    std::getline(std::cin, _secret);
    if (std::cin.fail()) {
      std::cout << "An exception occured. Try again" << std::endl;
      break ;
    }
    else if (_secret.empty())
      std::cout << "Fields should not be empty." << std::endl;
    else
      break ;
  }
  this->darkest_secret = _secret;
}