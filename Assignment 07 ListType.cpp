//ListType.cpp

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

string ListType::tostring()
{
  ostringstream out;

  out << " [";

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
