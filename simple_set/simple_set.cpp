// simple_set.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "TreeSet.h"
#include "HashSet.h"
#include "LinkedHashSet.h"

int main()
{ 
    cout << ">>>>>>>>>>>>>>  TREESET Testing  <<<<<<<<<<<<<<" << endl;
    TreeSet newSet;
    newSet.add(3);
    newSet.add(5);
    newSet.add(7);
    newSet.add(6);
    newSet.add(4);
    newSet.add(11);
    newSet.add(9);
    newSet.add(13);
    newSet.add(14);
    newSet.add(2);
    cout << "First : " << newSet.first() << endl;
    cout << "Last : " << newSet.last() << endl;
    TreeSet head = newSet.headSet(5);
    head.prettyPrint();
    cout << endl;

    TreeSet tail = newSet.tailSet(11);
    tail.prettyPrint();
    
    cout << endl;
    TreeSet subset = newSet.subSet(5, 13);
    subset.prettyPrint();


    cout << ">>>>>>>>>>>>>>  Hashset Testing  <<<<<<<<<<<<<<" << endl;

    HashSet newHashset;
    newHashset.add(7);
    newHashset.add(9);
    newHashset.add(2);
    newHashset.add(2);

    cout << "Check 2 : " << newHashset.contains(2) << endl;
    cout << "Check 10 : " << newHashset.contains(10) << endl;
    cout << "Size : " << newHashset.size() << endl;


    cout << ">>>>>>>>>>>>>>  Linked Hashset Testing  <<<<<<<<<<<<<<" << endl;

}