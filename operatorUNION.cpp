#ifndef UNORDEREDset_H
#define UNORDEREDset_H

#include "UNORDEREDarrayLISTtype.h"

template <class elemType>
class UNORDEREDset : public UNORDEREDarrayLISTtype<elemType> {
public:
    // Constructor
    UNORDEREDset(int size = 100);

    // Override INSERTat, insertEnd, REPLACEat
    void INSERTat(int location, const elemType& INSERTitem) override;
    void insertEND(const elemType& INSERTitem) override;
    void REPLACEat(int location, const elemType& REPitem) override;

    // Overload + operator for set union
    UNORDEREDset<elemType> operator+(const UNORDEREDset<elemType>& OTHERset) const;

    // Overload - operator for set intersection
    UNORDEREDset<elemType> operator-(const UNORDEREDset<elemType>& OTHERset) const;
};

// Constructor
template <class elemType>
UNORDEREDset<elemType>::UNORDEREDset(int size) : UNORDEREDarrayLISTtype<elemType>(size) {}

// Override INSERTat to verify item is not already in the list
template <class elemType>
void UNORDEREDset<elemType>::INSERTat(int location, const elemType& INSERTitem) {
    if (this->SEQUENTIALsearch(INSERTitem) == -1) {
        UNORDEREDarrayLISTtype<elemType>::INSERTat(location, INSERTitem);
    }
}

// Override INSERTend to verify item is not already in the list
template <class elemType>
void UNORDEREDset<elemType>::insertEND(const elemType& INSERTitem) {
    if (this->SEQUENTIALsearch(INSERTitem) == -1) {
        UNORDEREDarrayLISTtype<elemType>::insertEND(INSERTitem);
    }
}

// Override REPLACEat to verify item is not already in the list
template <class elemType>
void UNORDEREDset<elemType>::REPLACEat(int location, const elemType& REPitem) {
    if (this->SEQUENTIALsearch(REPitem == -1)) {
        UNORDEREDarrayLISTtype<elemType>::REPLACEat(location, REPitem);
    }
}

// Overload + operator for set union
// Preconditions:
//   - The other set (OTHERset) must be of the same type as the current set.
template <class elemType>
UNORDEREDset<elemType> UNORDEREDset<elemType>::operator+(const UNORDEREDset<elemType>& OTHERset) const {
    UNORDEREDset<elemType> UNIONset(*this);
    for (int i = 0; i < OTHERset.length; ++i) {
        if (UNIONset.SEQUENTIALsearch(OTHERset.list[i]) == -1) {
            UNIONset.INSERTend(OTHERset.list[i]);
        }
    }
    return UNIONset;
}
// Postconditions:
//   - A new set (UNIONset) is created, containing all elements from both the current set and the other set.
//   - The elements in the new set are unique (no duplicates).

// Overload - operator for set intersection
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

#endif // UNORDEREDSET_H