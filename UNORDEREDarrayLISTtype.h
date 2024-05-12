#pragma once
#ifndef H_unorderedArrayListType
#define H_unorderedArrayListType

#include "ARRAYlistTYPE.h"  

template <class elemType>
class UNORDEREDarrayLISTtype : public arrayListType<elemType>
{
public:
    void INSERTat(int location, const elemType& INSERTitem);
    void insertEND(const elemType& INSERTitem);
    void REPLACEat(int location, const elemType& REPitem);
    int SEQUENTIALsearch(const elemType& SEARCHitem) const;
    void remove(const elemType& REMOVEitem);

    UNORDEREDarrayLISTtype(int size = 100);
    //Constructor

};

template <class elemType>
void UNORDEREDarrayLISTtype<elemType>::INSERTat(int location,
    const elemType& INSERTitem)
{
    if (location < 0 || location >= this->MAXsize)
        cout << "The position of the item to be inserted "
        << "is out of range." << endl;
    else if (this->length >= this->MAXsize)  //list is full
        cout << "Cannot insert in a full list" << endl;
    else
    {
        for (int i = this->length; i > location; i--)
            this->list[i] = this->list[i - 1];	//move the elements down

        this->list[location] = INSERTitem; //insert the item at 
        //the specified position

        this->length++;	//increment the length
    }
} //end insertAt

template <class elemType>
void UNORDEREDarrayLISTtype<elemType>::insertEND
(const elemType& INSERTitem)
{
    if (this->length >= this->MAXsize)  //the list is full
        cout << "Cannot insert in a full list." << endl;
    else
    {
        this->list[this->length] = INSERTitem; //insert the item at the end
        this->length++; //increment the length
    }
} //end insertEnd

template <class elemType>
int UNORDEREDarrayLISTtype<elemType>::SEQUENTIALsearch
(const elemType& SEARCHitem) const
{
    int loc;
    bool found = false;

    for (loc = 0; loc < this->length; loc++)
        if (this->list[loc] == SEARCHitem)
        {
            found = true;
            break;
        }

    if (found)
        return loc;
    else
        return -1;
} //end seqSearch

template <class elemType>
void UNORDEREDarrayLISTtype<elemType>::remove
(const elemType& REMOVEitem)
{
    int loc;

    if (this->length == 0)
        cout << "Cannot delete from an empty list." << endl;
    else
    {
        loc = SEQUENTIALsearch(REMOVEitem);

        if (loc != -1)
            this->REMOVEat(loc);
        else
            cout << "The item to be deleted is not in the list."
            << endl;
    }
} //end remove

template <class elemType>
void UNORDEREDarrayLISTtype<elemType>::REPLACEat(int location,
    const elemType& REPitem)
{
    if (location < 0 || location >= this->length)
        cout << "The location of the item to be "
        << "replaced is out of range." << endl;
    else
        this->list[location] = REPitem;
} //end replaceAt

template <class elemType>
UNORDEREDarrayLISTtype<elemType>::UNORDEREDarrayLISTtype(int size)
    : arrayListType<elemType>(size)
{
}


#endif