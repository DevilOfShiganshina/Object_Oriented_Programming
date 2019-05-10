#ifndef EMPTYSET_H
#define EMPTYSET_H

#include <exception>

class EmptySet : public std::exception {
public:
  const char* what() const noexcept override {
    return "The set is empty!\0";
  }
};

#endif