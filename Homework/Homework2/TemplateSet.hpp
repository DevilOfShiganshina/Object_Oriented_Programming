#ifndef TEMPLATESET_H
#define TEMPLATESET_H
#include <vector>
using std::vector;

template <class T>
class Set {
public:
  /**
   * \brief This destructor deallocates the memory which was allocated on the heap.
   * 
   * \param This function does not take in any parameters
   * 
   * \return This function does not return anything
   */

  ~Set() {
    MakeEmpty();
  }

  /**
   * \brief This function adds a new item to the set, only if the item does not
   * already exist in the set. If the item already exist in set, an exception
   * is thrown
   * 
   * \param Takes in a single item from the user, the item that is to be added
   * to the set.
   * 
   * Return Value: This function does not return anything
   */

  void Add(T item);

  /**
   * \brief This function removes an item from the set, only if specified item
   * exists in the set. If the set is empty, or the item does not exist in the
   * set, an exception is thrown
   * 
   * \param Takes in a specified item from the user, the item that is to be
   * removed from the set.
   * 
   * \return This function does not return anything
   */

  void Remove(T item);

  /**
   * \brief This function returns the number of items that exists in the set.
   * 
   * \param This function does not take in any parameters.
   * 
   * \return This function returns an integer value, which indicates the
   * number of items that that exist in the set.
   */

  int sizeofSet();

  /**
   * \brief This function checks if the specified item is in the set.
   * 
   * \param One parameter, the item that is to be searched for in the set to
   * determine if it exists in the set.
   * 
   * \return Returns a boolean value which indicates if the items exists
   * in the set or not.
   */

  bool Exist(T item);

  /**
   * \brief This function adds two sets together.
   * 
   * \params One parameter, the object, the set of which is to be added to
   * the set of the calling object.
   * 
   * \return A Set object
   */

  Set Union(Set<T> &other);

  /**
   * \brief This function determines the items that two sets have in common.
   * 
   * \param One parameter, the object, the set of which is compared with the
   * set of the current class.
   * 
   * \return A Set object
   */

  Set Intersection(Set<T> &other);

  /**
   * \brief This function removes all items from the set. This function is also
   * going to be placed in the deconstructor, so that the allocated memory can be
   * properly freed before the program terminates gracefully.
   * 
   * \param This function does not take in any parameters.
   * 
   * \return This function does not return anything.
   */

  void MakeEmpty();

  /**
   * \brief This function prints all the items to the console window.
   * 
   * \param This function does not take in any parameters.
   * 
   * Return Value: This function does not return anything. 
   */

  void PrintSet();

private:
  //! Container to store the set
  vector<T> set;

  /**
   * \brief This function determines the index of an item that is passed to it.
   *        It is guaranteed that the specified element does exist in the set.
   * 
   * \param One parameter, the item, the index of which is to be determined.
   * 
   * \return An integer value which represents the index of the item in the set.
   */

  int index(T item);

  /**
   * \brief This function determines if an item exist in the set of an object.
   * 
   * \param Two parameters, the item that is to be searched for, and the object
   * where the item is to be searched for.
   * 
   * \return A boolean value which indicates if the item exist in the object
   * or not.
   */

  bool ExistObject(Set<T> &other, T item);
};

#endif