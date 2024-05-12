#pragma once
#ifndef UNORDEREDset_H
#define UNORDEREDset_H

#include "UNORDEREDarrayLISTtype.h"

template <class elemType>
class UNORDEREDset : public UNORDEREDarrayLISTtype<elemType> {

public:
    // Constructor
    UNORDEREDset(int size = 100);

    void INSERTat(int location, const elemType& INSERTitem) override;
    void insertEND(const elemType& INSERTitem) override;
    void REPLACEat(int location, const elemType& REPitem) override;

    UNORDEREDset<elemType> operator+(const UNORDEREDset<elemType>& OTHERset) const;

    UNORDEREDset<elemType> operator-(const UNORDEREDset<elemType>& OTHERset) const;

    void print() const;
};

// Constructor
template <class elemType>
UNORDEREDset<elemType>::UNORDEREDset(int size) : UNORDEREDarrayLISTtype<elemType>(size) {}

// Override INSERTat to verify item is not already in the list
// Preconditions:
//   - location must be a valid index within the bounds of the list (0 <= location < length).
//   - The item to be inserted (INSERTitem) must be of the same type as the elements in the list.
template <class elemType>
void UNORDEREDset<elemType>::INSERTat(int location, const elemType& INSERTitem) {
    if (this->SEQUENTIALsearch(INSERTitem) == -1) {
        UNORDEREDarrayLISTtype<elemType>::INSERTat(location, INSERTitem);
    }
}

// Override INSERTend to verify item is not already in the list
// Postconditions:
//   - If the item to be inserted is not already in the list, it is inserted at the specified location.
//   - If the item to be inserted is already in the list, it is not inserted again.

// Preconditions:
//   - The item to be inserted (INSERTitem) must be of the same type as the elements in the list.
template <class elemType>
void UNORDEREDset<elemType>::insertEND(const elemType& INSERTitem) {
    if (this->SEQUENTIALsearch(INSERTitem) == -1) {
        UNORDEREDarrayLISTtype<elemType>::insertEND(INSERTitem);
    }
}
// Postconditions:
//   - If the item to be inserted is not already in the list, it is inserted at the end of the list.
//   - If the item to be inserted is already in the list, it is not inserted again.

// Override REPLACEat to verify item is not already in the list
// Preconditions:
//   - location must be a valid index within the bounds of the list (0 <= location < length).
//   - The item to be replaced (REPitem) must be of the same type as the elements in the list.
template <class elemType>
void UNORDEREDset<elemType>::REPLACEat(int location, const elemType& REPitem) {
    if (this->SEQUENTIALsearch(REPitem) == -1) {
        UNORDEREDarrayLISTtype<elemType>::REPLACEat(location, REPitem);
    }
}
// Postconditions:
//   - If the item to be replaced is not already in the list, it is replaced at the specified location.
//   - If the item to be replaced is already in the list, it is not replaced again.

template <class elemType>
UNORDEREDset<elemType> UNORDEREDset<elemType>::operator+(const UNORDEREDset<elemType>& OTHERset) const {
    UNORDEREDset<elemType> UNIONset(*this);
    for (int i = 0; i < OTHERset.length; ++i) {
        if (UNIONset.SEQUENTIALsearch(OTHERset.list[i]) == -1) {
            UNIONset.insertEND(OTHERset.list[i]);
        }
    }
    return UNIONset;
}

template <class elemType>
UNORDEREDset<elemType> UNORDEREDset<elemType>::operator-(const UNORDEREDset<elemType>& OTHERset) const {
    UNORDEREDset<elemType> INTERSECTIONset;
    for (int i = 0; i < this->length; ++i) {
        if (OTHERset.SEQUENTIALsearch(this->list[i]) != -1) {
            INTERSECTIONset.insertEND(this->list[i]);
        }
    }
    return INTERSECTIONset;
}

template <class elemType>
void UNORDEREDset<elemType>::print() const {
    for (int i = 0; i < this->length; ++i) {
        std::cout << this->list[i] << " ";
    }
    std::cout << std::endl;
}

#endif // UNORDEREDSET_H