#include "HashSet.h"

HashSet::HashSet()
{
}

HashSet::HashSet(std::unordered_map<int, std::string> input)
{
}

bool HashSet::add(int e)
{
    if(this->hashMap.find(e) != this->hashMap.end())
        return false;
    this->hashMap.insert(std::make_pair(e, std::string("PRESENT")));
    return true;
}

void HashSet::clear()
{
    this->hashMap.clear();
}

HashSet HashSet::clone()
{
    return HashSet(this->hashMap);
}

bool HashSet::contains(int e)
{
    return this->hashMap.find(e) != this->hashMap.end();
}

bool HashSet::isEmpty()
{
    return this->hashMap.empty();
}

bool HashSet::remove(int e)
{
    if (this->hashMap.find(e) == this->hashMap.end())
        return false;
    this->hashMap.erase(e);
    return true;
}

int HashSet::size()
{
    return this->hashMap.size();
}