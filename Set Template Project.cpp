#include <iostream>
#include <string>
#include "UNORDEREDset.h"

int main() {
    // Create an array of integers
    int intDATA[] = { 1,2,3,4,5,6,7,8 };
    int intSIZE = sizeof(intDATA) / sizeof(intDATA[0]);

    // Create an array of strings
    std::string STRdata[] = { "chocolate", "vanilla", "cookies", "vanilla", "strawberrey", "cake", "chocolate" };
    int STRsize = sizeof(STRdata) / sizeof(STRdata[0]);

    // Create UNORDEREDset object for integers
    UNORDEREDset<int> INTset;

    // Add integers to INTset using insertEnd
    for (int i = 0; i < STRsize; ++i) {
        INTset.insertEND(intDATA[i]);
    }

    // Create UNORDEREDset object for strings
    UNORDEREDset<std::string> STRset;

    // Add strings to STRset using insertEnd
    for (int i = 0; i < STRsize; ++i) {
        STRset.insertEND(STRdata[i]);
    }

    // Print INTset to verify insertEND does not allow duplicates
    std::cout << "Integer Set: " << std::endl;
    INTset.print();
    std::cout << std::endl;

    // Print STRset to verify insertEND does not allow duplicates
    std::cout << "String Set: " << std::endl;
    STRset.print();
    std::cout << std::endl;

    // Test INSERTat to add unique item to INTset
    INTset.INSERTat(3, 10);
    std::cout << "Integer Set after INSERTat: " << std::endl;
    INTset.print();
    std::cout << std::endl;

    // Test INSERTat to add duplicate item to INTset
    INTset.INSERTat(3, 5);
    // Duplicate of existing item
    std::cout << "Integer set after INSERTat (duplicate): " << std::endl;
    INTset.print();
    std::cout << std::endl;

    // Test REPLACEat to replace unique item in STRset
    STRset.REPLACEat(3, "mint chips");
    std::cout << "String Set after REPLACEat: " << std::endl;
    STRset.print();
    std::cout << std::endl;

    // Test REPLACEat to replace duplicate item in STRset
    STRset.REPLACEat(3, "cookies");
    // Duplicate of existing item
    std::cout << "String Set after REPLACEat (duplicate): " << std::endl;
    STRset.print();
    std::cout << std::endl;

    // Test set union and intersection operations
    UNORDEREDset<int> intSET1, intSET2, intUNION, intINTERSECTION;
    intSET1.insertEND(1);
    intSET1.insertEND(2);
    intSET1.insertEND(3);
    intSET2.insertEND(3);
    intSET2.insertEND(4);
    intSET2.insertEND(5);
    intUNION = intSET1 + intSET2;
    intINTERSECTION = intSET1 - intSET2;

    std::cout << "Integer Set 1: " << std::endl;
    intSET1.print();
    std::cout << "Integer Set 2: " << std::endl;
    intSET2.print();
    std::cout << "Union of Integer Set 1 and Set 2: " << std::endl;
    intUNION.print();
    std::cout << "Intersection of Integer Set 1 and Set2: " << std::endl;
    intINTERSECTION.print();
    std::cout << std::endl;

    UNORDEREDset<std::string> STRset1, STRset2, strUNION, strINTERSECTION;
    STRset1.insertEND("chocolate");
    STRset1.insertEND("vanilla");
    STRset1.insertEND("cookies");
    STRset2.insertEND("vanilla");
    STRset2.insertEND("strawberry");
    STRset2.insertEND("cake");
    strUNION = STRset1 + STRset2;
    strINTERSECTION = STRset1 - STRset2;

    std::cout << "String Set 1: " << std::endl;
    STRset1.print();
    std::cout << "String Set 2: " << std::endl;
    STRset2.print();
    std::cout << "Union of String Set 1 and String Set 2: " << std::endl;
    strUNION.print();
    std::cout << "Intersection of String Set 1 and String Set 2: " << std::endl;
    strINTERSECTION.print();

    return 0;
}