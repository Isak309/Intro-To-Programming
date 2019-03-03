/** 
 * @author Isak Angerstig
 * @cwid   502 09 016
 * @class  COSC 2336, Spring 2019
 * @ide    Visual Studio Community 2017
 * @date   February 28, 2019
 * @assg   Assignment 07 Templates and Operator Overloading
 * 
 * @description Assignment 07 part 01, practice with operator overloading.
 *   In this first part of assignment, you need to define a ListType class
 *   and overload the indicated operators.  This version of your class
 *   will only support list of int values.  You will turn this into a
 *   class template in part 2 of the assignment.
 */
#include <iostream>
#include <sstream>
using namespace std;

#ifndef _LISTTYPE_H_
#define _LISTTYPE_H_
/** ListType abstract data type
 * This list type is "templatized" to support creating concrete lists of
 * any type of object.  This list supports dynamic shrinking and growing
 * of its size as items are appended and removed from the list.
 * In addition, several operators are overloaded for convenience of
 * inserting, accessing and outputting the list to a stream.
 *
 * @value id A unique id, each list is assigned its own unique id
 *   upon creation.
 * @value size The current size (an int) or number of items currently
 *   contained in the list.
 * @value allocSize The actual amount of memory we currently
 *   have allocated.
 * @value item A (pointer to an) array of items of our templated
 *   <Type> we are holding in our list.
 */
class ListType
{
private:
  // initial allocSize, unless overridden in construction
  const int ALLOCATION_INCREMENT = 10;
  static int nextListId; // class variable, assign unique listid
  int id;
  int size;
  int allocSize;
  int* item;

public:
  ListType(); // default constructor
  ListType(int allocSize); // empty constructor
  ListType(int size, int* items); // construct from array
  ~ListType(); // class destructor

  // getters
  int getSize();
  int getAllocSize();


  // member functions
  string tostring() const;
  void appendItem(int value);
  
  // overloaded operators
  friend ostream& operator<<(ostream& out, const ListType& aString);
  
  
  //ListType operator<<(tostring);
  const ListType& operator=(const ListType& rightList);  // I also gave you the copy operator
  
};

// need to include the template implementations here, if/when you templatize
//#include "ListType.cpp"


#endif // _LISTTYPE_H_
