#ifndef ITEMDOESNOTEXIST_H
#define ITEMDOESNOTEXIST_H

#include <exception>

class ItemDoesNotExist : public std::exception {
public:
  const char* what() const noexcept override {
    return "Item does not exist in the set!\0";
  }
};

#endif