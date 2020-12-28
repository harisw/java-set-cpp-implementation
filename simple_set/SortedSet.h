#pragma once

template <typename T, typename I>
class SortedSet
{
public:
    virtual int first() = 0;
    virtual T headSet(int toElement) = 0;       //Exclusive to
    virtual int last() = 0;
    virtual T subSet(int fromElement, int toElement) = 0;
    virtual T tailSet(int fromElement) = 0;
};