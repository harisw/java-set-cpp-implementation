#pragma once
#include "HashSet.h"
#include<list>

struct LinkedNode {
    LinkedNode* prev;
	LinkedNode* next;
};
typedef LinkedNode* LinkedNodePtr;

class LinkedHashSet :
    public HashSet
{
private:
	LinkedNodePtr head = nullptr;
	LinkedNodePtr tail = nullptr;

    std::unordered_map<int, LinkedNode> hashMap;
public:
	LinkedHashSet();
	//LinkedHashSet(std::unordered_map<int, Node> input);
	bool add(int e);
	void clear();
	LinkedHashSet clone();
	bool contains(int e);
	bool isEmpty();
	bool remove(int e);
	int size();
};