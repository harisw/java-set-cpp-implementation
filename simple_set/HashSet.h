#pragma once
#include<unordered_map>
class HashSet
{
private:
	std::unordered_map<int, std::string> hashMap;
public:
	HashSet();
	HashSet(std::unordered_map<int, std::string> input);
	bool add(int e);
	void clear();
	HashSet clone();
	bool contains(int e);
	bool isEmpty();
	bool remove(int e);
	int size();
};