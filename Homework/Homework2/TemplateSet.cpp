#include <iostream>
#include <vector>
#include "TemplateSet.hpp"
#include "EmptySet.h"
#include "ItemExists.h"
#include "ItemDoesNotExist.h"
using std::cout;
using std::endl;
using std::vector;

template <class T>
void Set<T>::Add(T item) {

  //! If the set container is empty, then simply add the item to
  //! the set
  if (set.empty()) {
    set.push_back(item);
    return;
  }

  //! If the item already exists in the set throw an exception
  if (Exist(item) == true) {
    throw ItemExists();
  }

  //! Otherwise add the item to the set.
  else {
    set.push_back(item);
  }
}

template <class T>
void Set<T>::Remove(T item) {
  //! If the set is empty, throw an exception
  if (set.empty()) {
    throw EmptySet();
  }

  //! If the item does not exist in the set, throw an exception
  if (Exist(item) == false) {
    throw ItemDoesNotExist();
  }

  //! If the item exists, remove it from the set
  else {
    set.erase(set.begin() + index(item));
  }
}

template <class T>
int Set<T>::sizeofSet() {
  //! Returns size of the set
  return set.size();
}

template <class T>
bool Set<T>::Exist(T item) {
  
  //! If container is empty, throw an excetion;
  if (set.empty()) {
    throw EmptySet();
  } 
  
  //! If the container is not empty
  else {
    
    //! Loop through the entire set
    for (int i = 0; i < set.size(); i++) {
      
      //! If item passed to the function is found in the set
      //! return true;
      if (set[i] == item) return true;
    }
  }

  //! If the item is not found return false;
  return false;
}

template <class T>
Set<T> Set<T>::Union(Set<T> &other) {
  Set<T> retSet;
  //! If both set are empty, then an empty object will be returned
  //! to main, so nothing needs to be done here
  if (set.empty() && other.set.empty()) {
  }

  //! If the set passed to the function is empty, 
  //! place the current set in retSet 
  else if (other.set.empty()) {
    retSet.set = set;
  }

  //! If the current object's set is empty, then simply place
  //! all items of the other object's set in the retSet objects set.
  else if (set.empty()) {
    retSet.set = other.set;
  }

  //! If neither of the sets are empty, the following code will
  //! execute.  
  else {
    //! Place all items of current set in the retSet object's set.
    retSet.set = set;
    //! Iterate through all the other object's set
    for (int i = 0; i < other.set.size(); i++) {
      //! if the other object's set item does not exist
      //! current object's set, then simply append the
      //! other object's set item to the retSet's set.
      if (Exist(other.set[i]) == false) {
        retSet.set.push_back(other.set[i]);
      }
    }
  }

  // Return retSet
  return retSet;
}

template <class T>
Set<T> Set<T>::Intersection(Set<T> &other) {

  //! The set that will be returned.
  Set<T> retSet;
  //! If both of the sets are empty, do nothing, since an empty object
  //! will be returned to main. So nothing needs to be done here.
  if (set.empty() && other.set.empty()) {
  }

  //! If the other object's set is empty or the current object's set
  //! is empty, then nothing needs to be done, since an empty set
  //! will be returned to main.
  else if (set.empty() || other.set.empty()) {
  }

  //! If neither of the set is empty, then following code will
  //! execute.
  else {
    //! Iterate through the current set.
    for (int i = 0; i < set.size(); i++) {

      //! If the current sets' item(s) exists in the other
      //! object's set, then add that item to the retSet
      //! object's set
      if (ExistObject(other, set[i]) == true) {
        retSet.set.push_back(set[i]);
      }
    }
  }

  return retSet;
}

template <class T>
void Set<T>::MakeEmpty() {

  //! Clear the vector.
  //! However, clear() does not affect the capacity of the set
  //! container.
  set.clear();

  //! Resize the vector to 0
  set.resize(0);

  //! shrink_to_fit requests the container to reduce its capacity to
  //! fit its size.
  set.shrink_to_fit();

  //! Now both the size and capacity of the set container is 0.
}

template <class T>
void Set<T>::PrintSet() {
  //! Iterate through the set and print every single item to the
  //! Console window
  for (int i = 0; i < set.size(); i++) {
    cout << set[i] << " ";
  } cout << endl;
}

template <class T>
int Set<T>::index(T item) {
  //! If this function is invoked, then it is guaranteed
  //! the item exists in the set.

  //! Iterate through the set
  for (int i = 0; i < set.size(); i++) {

    //!If and when the item is found
    if (set[i] == item) {

      //! Return it's index;
      return i;
    }
  }
}

template <class T>
bool Set<T>::ExistObject(Set<T> &other, T item) {
  
  //! Iterate through the object's set.
  for (int i = 0; i < other.set.size(); i++) {
    
    //! If the item exist in the object's set, return true.
    if (other.set[i] == item) return true;
  }

  //! Return false, if the item is not found in the object's
  //! set.
  return false;
}