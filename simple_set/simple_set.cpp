// simple_set.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "TreeSet.h"

int main()
{
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

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
