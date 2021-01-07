#include "LinkedHashSet.h"

LinkedHashSet::LinkedHashSet()
{
}

//LinkedHashSet::LinkedHashSet(std::unordered_map<int, Node> input)
//{ 
//    this->hashMap = input;
//}

bool LinkedHashSet::add(int e)
{
    if (this->hashMap.find(e) != this->hashMap.end())
        return false;    
    
    LinkedNodePtr newNode = new LinkedNode;
    newNode->next = nullptr;
    if (this->head == nullptr) {
        newNode->prev = nullptr;
        this->head = newNode;
        this->tail = newNode;
    }
    else {
        newNode->prev = this->tail;
        this->tail->next = newNode;

        this->tail = newNode;
    }
    this->hashMap.insert(std::make_pair(e, *newNode));

    return true;
}

void LinkedHashSet::clear()
{
    this->hashMap.clear();
    this->head == nullptr;
    this->tail == nullptr;
}

LinkedHashSet LinkedHashSet::clone()
{
    return *this;
}

bool LinkedHashSet::contains(int e)
{
    return this->hashMap.find(e) != this->hashMap.end();
}

bool LinkedHashSet::isEmpty()
{
    return this->hashMap.empty();
}

bool LinkedHashSet::remove(int e)
{
    if (this->hashMap.find(e) == this->hashMap.end())
        return false;
    //IF deleted node is head
    if (this->hashMap[e].prev == nullptr) {
        head = this->hashMap[e].next;
        head->prev = nullptr;
    }
    else if (this->hashMap[e].next == nullptr) {
        tail = this->hashMap[e].prev;
        tail->next = nullptr;
    }
    else {
        LinkedNode* prevNode = hashMap[e].prev;
        prevNode->next = hashMap[e].next;

        LinkedNode* nextNode = hashMap[e].next;
        nextNode->prev = hashMap[e].prev;
    }
    this->hashMap.erase(e);
    return true;
}

int LinkedHashSet::size()
{
    return hashMap.size();
}
