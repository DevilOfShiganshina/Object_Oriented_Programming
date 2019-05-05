// To prevent multiple inclusion during compilation
#ifndef BOARD_H
#define BOARD_H
#include <vector> // For the use of vectors

class Board {
private:
  int length_width;
  std::vector<std::vector<int> > vect;

public:
  /**
   * \brief This constructor is invoked when an instance of this board
   *        is made without passing any parameters.
   * 
   * \param This constructor does not require any parameters.
   * 
   * \return Nothing
   **/

  Board();

  /**
   * \brief This constructor is invoked when an instance of this board
   *        is made by passing the width and the length.
   * 
   * \param An integer value which is both the length and the width of
   *         the board.
   * 
   * \return Nothing
   **/

  Board(int length_width);

  /**
   * \brief This destructor deallocates all the memory that has been
   *        allocated.
   * 
   * \param This destructor does not require any parameters.
   * 
   * \return Nothing
   **/
  ~Board();
  /**
   * \brief This function creates the board
   * 
   * \param This function does not require any parameters, though it
   *        uses the private attributes of the Board class. length_width,
   *        and the vector vect.
   * 
   * \return Nothing
   **/

  void create_board();

  /**
   * \brief This function prints the board to the console window.
   * \param This function does not require any parameters, though it
   *        uses the private attributes of the Board class. length_width,
   *        and the vector vect.
   * \return Nothing
   **/

  void print_board();
};

#endif