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
#include "ListType.hpp"


// static member variables have to be initialized like this
int ListType::nextListId = 1;


/** default constructor
 * Initialize as an empty list.  Initially we have no memory
 * allocated, and the size (and allocation size) are 0.
 */
ListType::ListType()
{
  id = nextListId++;
  size = allocSize = 0;
  item = NULL;
}


/** constructor (empty)
 * Initialize as an empty list with indicated iniaial
 * size of memory allocated.
 *
 * @param allocSize The initialze size for the empty list.
 */
ListType::ListType(int allocSize)
{
  id = nextListId++;
  size = 0;
  this->allocSize = allocSize;
  item = new int[this->allocSize];
}


/** constructor (array)
 * Initialize a list using an array of items for the initial values
 * in the list.
 *
 * @param size The number of items in the array given for initialization.
 * @param items An array (pointer to base address) of items to initialize
 *   this list with.
 */
ListType::ListType(int size, int* initItem)
{
  id = nextListId++;
  this->size = size;
  this->allocSize = size;
  item = new int[this->size];

  // copy the items into this list
  for (int index = 0; index < this->size; index++)
  {
    item[index] = initItem[index];
  }
}


/** destructor
 * The class destructor.  Be good stewards of memory and make
 * sure that we free up memory allocated to hold our list items
 * by this object when it goes out of scope.  We display some
 * information for debugging/tracking ListType destruction.
 */
ListType::~ListType()
{
  cout << "ListType: <id=" << id << "> out of scope, size: "
       << size
       << " allocSize: " << allocSize << endl;

  // be a good memory manager, free up memory we have allocated
  if (item != NULL)
  {
    delete [] item;
  }
}


/** overload operator=
 * Overload the operator= assignment operator.  Whenever one list
 * variable is assigned to another this operator is invoked.
 *
 * @param rhs The list on the right hand side of the assignment, the
 *   contents of which is to be (deep) copied to this list contents.
 *
 * @returns ListType Returns a reference to this list, after contents
 *   have been copied/assigned.
 */
const ListType& ListType::operator=(const ListType& rhs)
{
  // only assign if not doing a self-assignment
  if (this != &rhs)
  {
    // copy the values from rightList into this list
    int newAllocSize = rhs.size;

    // if not enough space, grow our list
    if (this->allocSize < newAllocSize)
    {
      int* newItem = new int[newAllocSize];
      delete [] item;
      item = newItem;
      this->allocSize = newAllocSize;
    }

    // copy the items from righ hand side into this list
    for (int index = 0; index < rhs.size; index++)
    {
      this->item[index] = rhs.item[index];
    }

    this->size = rhs.size;
  }

  // return the object assigned
  return *this;
}

/*
* two simple getter methods in order
* to access the size and allocSize class member values
* getSize() - return int size
* getAllocSize() - return int size allocation
*/
int ListType::getSize()
{
  return size;
}

int ListType::getAllocSize()
{
  return allocSize;
}


/*
* This function takes no parameters
* as input, and it returns a string
* will return a string of items currently
* in list.
*/
string ListType::tostring() const
{
  ostringstream out;

  out << "[";

  // output first value, so we can remove , at end
  if (size >= 1)
  {
    out << item[0];
  }

  // output each follow with a preceeding comma,
  // which allows us to end list without trailing ,
  for (int index = 1; index < size; index++)
  {
    out << ", " << item[index];
  }

  out << "]";

  return out.str();
}


/*
* This operator will provide the ability for the ListType
* class to be output to a stream.
* @ param out - output stream
* @ param aString - representation of output stream
*/
ostream& operator<<(ostream& out, const ListType& aString)
{
  out << aString.tostring();
  return out;
}


/*
* Void function that appends a value and puts it at the end of
* the list varying if its over 9 or not
* @ param int value - takes user input value to add to the array
*/
void ListType::appendItem(int value)
{
    int* newArray = new int[size + 1];
    
    for(int i = 0;i < size; i++)
    {
      newArray[i] = item[i];
    }
    
  newArray[size] = value;
  delete item;
  item = newArray;
  size = size + 1;
  
  allocSize = allocSize + ALLOCATION_INCREMENT;


}
