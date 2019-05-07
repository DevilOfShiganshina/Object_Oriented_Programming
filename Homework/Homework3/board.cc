#include <iostream> // Input / Output
#include <vector> // For the use of vectors
#include "board.hpp" // Board class declation

//! If this constructor is invoked, a board of length and width of 10
//! will be construction.
Board::Board() {
  this->length_width = 10;
  vect.resize(length_width);
  create_board();

}
//! If this constructor is invoked, a board with the user specified
//! length and width is constructed.
Board::Board(int length_width) {
  this->length_width = length_width;
  vect.resize(length_width);
  create_board();
}

//! Deallocating the memory which was allocated to store the board.
Board::~Board() {
  vect.clear();
  vect.resize(0);
  vect.shrink_to_fit();
}

//! Creates the board.
void Board::create_board() {
  for (int i = 0; i < length_width; i++) {
    std::vector<int> temp;
    for(int j = 0; j < length_width; j++) {
      temp.push_back(10);
    } vect.push_back(temp);
  }
}

//! Prints the board to the console window.
void Board::print_board() {
  vect.resize(length_width, std::vector<int>(length_width, 0));
  for (int i = 0; i < length_width; i++) {
    for (int j = 0; j < vect[i].size(); j++) {
      std::cout << vect[i][j] << "*";
    } std::cout << std::endl;
  }
}