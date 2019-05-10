#include <iostream>
#include <exception>
#include <vector>
#include "TemplateSet.cpp"
using std::cout;
using std::endl;

int main() {
  Set<int> a;
  
  try {
    cout << "Items of set a: ";
    a.PrintSet();
  } catch (const std::exception& e) {
    cout << e.what() << endl;
  }

  try {
    a.Add(1);
  } catch (const std::exception& e) {
    cout << e.what() << endl;
  }

  try {
    a.Add(2);
  } catch (const std::exception& e) {
    cout << e.what() << endl;
  }

  try {
    a.Add(3);
  } catch (const std::exception& e) {
    cout << e.what() << endl;
  }

  try {
    a.Add(4);
  } catch (const std::exception& e) {
    cout << e.what() << endl;
  }

  try {
    a.Add(5);
  } catch (const std::exception& e) {
    cout << e.what() << endl;
  }

  try {
    cout << "Items of set a: ";
    a.PrintSet();
  } catch (const std::exception& e) {
    cout << e.what() << endl;
  }

  Set<int> b;

  try {
    b.Add(3);
  } catch (const std::exception& e) {
    cout << e.what() << endl;
  }

  try {
    b.Add(4);
  } catch (const std::exception& e) {
    cout << e.what() << endl;
  }

  try {
    b.Add(5);
  } catch (const std::exception& e) {
    cout << e.what() << endl;
  }

  try {
    b.Add(6);
  } catch (const std::exception& e) {
    cout << e.what() << endl;
  }

  try {
    b.Add(7);
  } catch (const std::exception& e) {
    cout << e.what() << endl;
  }

  try {
    cout << "Items of set b: ";
    b.PrintSet();
  } catch (const std::exception& e) {
    cout << e.what() << endl;
  }

  Set<int> c;

  try {
    c = a.Union(b);
  } catch (const std::exception& e) {
    cout << e.what() << endl;
  }

  try {
    cout << "Union of sets a and b: ";
    c.PrintSet();
  } catch (const std::exception& e) {
    cout << e.what() << endl;
  }

  Set<int> d;

  try {
    d = a.Intersection(b);
  } catch (const std::exception& e) {
    cout << e.what() << endl;
  }

  try {
    cout << "Intersection of sets a and b: ";
    d.PrintSet();
  } catch (const std::exception& e) {
    cout << e.what() << endl;
  }

  return 0;
}