#pragma once
#ifndef H_arrayListType
#define H_arrayListType

#include <iostream>

using namespace std;

template <class elemType>
class arrayListType
{
public:
    const arrayListType<elemType>&
        operator=(const arrayListType<elemType>&);
    //Overloads the assignment operator

    bool isEmpty() const;
    //Function to determine whether the list is empty
    //Postcondition: Returns true if the list is empty;
    //               otherwise, returns false.

    bool isFull() const;
    //Function to determine whether the list is full
    //Postcondition: Returns true if the list is full; 
    //               otherwise, returns false.

    int listSize() const;
    //Function to determine the number of elements in 
    //the list.
    //Postcondition: Returns the value of length.

    int maxListSize() const;
    //Function to determine the maximum size of the list
    //Postcondition: Returns the value of maxSize.

    void print() const;
    //Function to output the elements of the list
    //Postcondition: Elements of the list are output on the 
    //               standard output device.

    bool isItemAtEqual(int location, const elemType& item) const;
    //Function to determine whether item is the same as
    //the item in the list at the position specified 
    //by location.
    //Postcondition: Returns true if the list[location] 
    //               is the same as item; otherwise, 
    //               returns false.
    //               If location is out of range, an 
    //               appropriate message is displayed.

    virtual void INSERTat(int location, const elemType& insertItem) = 0;
    //Function to insert insertItem in the list at the 
    //position specified by location. 
    //Note that this is an abstract function.
    //Postcondition: Starting at location, the elements of 
    //               the list are shifted down, 
    //               list[location] = insertItem; length++;    
    //               If the list is full or location is out of
    //               range, an appropriate message is displayed.

    virtual void insertEND(const elemType& insertItem) = 0;
    //Function to insert insertItem an item at the end of 
    //the list. Note that this is an abstract function.
    //Postcondition: list[length] = insertItem; and length++;
    //               If the list is full, an appropriate 
    //               message is displayed.

    void REMOVEat(int location);
    //Function to remove the item from the list at the 
    //position specified by location 
    //Postcondition: The list element at list[location] is 
    //               removed and length is decremented by 1.
    //               If location is out of range, an 
    //               appropriate message is displayed.

    void retrieveAt(int location, elemType& retItem) const;
    //Function to retrieve the element from the list at the  
    //position specified by location 
    //Postcondition: retItem = list[location] 
    //               If location is out of range, an 
    //               appropriate message is displayed.

    virtual void REPLACEat(int location, const elemType& repItem) = 0;
    //Function to replace repItem the elements in the list 
    //at the position specified by location. 
    //Note that this is an abstract function.
    //Postcondition: list[location] = repItem 
    //               If location is out of range, an 
    //               appropriate message is displayed.

    void clearList();
    //Function to remove all the elements from the list 
    //After this operation, the size of the list is zero.
    //Postcondition: length = 0;

    virtual int SEQUENTIALsearch(const elemType& searchItem) const = 0;
    //Function to search the list for searchItem.
    //Note that this is an abstract function.
    //Postcondition: If the item is found, returns the 
    //               location in the array where the item is  
    //               found; otherwise, returns -1.

    virtual void remove(const elemType& removeItem) = 0;
    //Function to remove removeItem from the list.
    //Note that this is an abstract function.
    //Postcondition: If removeItem is found in the list,
    //               it is removed from the list and length 
    //               is decremented by one.

    arrayListType(int size = 100);
    //Constructor
    //Creates an array of the size specified by the 
    //parameter size. The default array size is 100.
    //Postcondition: The list points to the array, length = 0,
    //               and maxSize = size;

    arrayListType(const arrayListType<elemType>& OTHERlist);
    //Copy constructor

    virtual ~arrayListType();
    //Destructor
    //Deallocate the memory occupied by the array.

protected:
    elemType* list; //array to hold the list elements
    int length;     //variable to store the length of the list
    int MAXsize;    //variable to store the maximum 
    //size of the list
};


template <class elemType>
bool arrayListType<elemType>::isEmpty() const
{
    return (this->length == 0);
}

template <class elemType>
bool arrayListType<elemType>::isFull() const
{
    return (this->length == this->MAXsize);
}

template <class elemType>
int arrayListType<elemType>::listSize() const
{
    return this->length;
}

template <class elemType>
int arrayListType<elemType>::maxListSize() const
{
    return this->MAXsize;
}

template <class elemType>
void arrayListType<elemType>::print() const
{
    for (int i = 0; i < this->length; i++)
        cout << list[i] << " ";
    cout << endl;
}

template <class elemType>
bool arrayListType<elemType>::isItemAtEqual(int location,
    const elemType& item)  const
{
    if (location < 0 || location >= this->length)
    {
        cout << "The location of the item to be removed "
            << "is out of range." << endl;

        return false;
    }
    else
        return (list[location] == item);
}

template <class elemType>
void arrayListType<elemType>::REMOVEat(int location)
{
    if (location < 0 || location >= this->length)
        cout << "The location of the item to be removed "
        << "is out of range." << endl;
    else
    {
        for (int i = location; i < this->length - 1; i++)
            list[i] = list[i + 1];

        this->length--;
    }
} //end removeAt

template <class elemType>
void arrayListType<elemType>::retrieveAt(int location,
    elemType& retItem) const
{
    if (location < 0 || location >= this->length)
        cout << "The location of the item to be retrieved is "
        << "out of range" << endl;
    else
        retItem = list[location];
} //end retrieveAt

template <class elemType>
void arrayListType<elemType>::clearList()
{
    this->length = 0;
} //end clearList

template <class elemType>
arrayListType<elemType>::arrayListType(int size)
{
    if (size <= 0)
    {
        cout << "The array size must be positive. Creating "
            << "an array of the size 100. " << endl;

        this->MAXsize = 100;
    }
    else
        this->MAXsize = size;

    this->length = 0;

    list = new elemType[this->MAXsize];
}

template <class elemType>
arrayListType<elemType>::~arrayListType()
{
    delete[] list;
}

template <class elemType>
arrayListType<elemType>::arrayListType(const arrayListType<elemType>& OTHERlist)
{
    this->MAXsize = OTHERlist.MAXsize;
    this->length = OTHERlist.length;

    list = new elemType[this->MAXsize]; 	//create the array

    for (int j = 0; j < this->length; j++)  //copy otherList
        list[j] = OTHERlist.list[j];
}//end copy constructor


template <class elemType>
const arrayListType<elemType>& arrayListType<elemType>::operator=
(const arrayListType<elemType>& OTHERlist)
{
    if (this != &OTHERlist)    //avoid self-assignment
    {
        delete[] list;
        this->MAXsize = OTHERlist.MAXsize;
        this->length = OTHERlist.length;

        list = new elemType[this->MAXsize];

        for (int i = 0; i < this->length; i++)
            list[i] = OTHERlist.list[i];
    }
    return *this;
}


#endif