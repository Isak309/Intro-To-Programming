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
  
  string tostring();
  // overloaded operators
  const ListType& operator=(const ListType& rightList);  // I also gave you the copy operator
};

// need to include the template implementations here, if/when you templatize
//#include "ListType.cpp"


#endif // _LISTTYPE_H_
