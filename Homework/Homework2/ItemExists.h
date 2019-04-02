#ifndef ITEMEXISTS_H
#define ITEMEXISTS_H

#include <exception>

class ItemExists : public std::exception {
public:
  const char* what() const noexcept override {
    return "The item exists in the set!\0";
  }
};

#endif