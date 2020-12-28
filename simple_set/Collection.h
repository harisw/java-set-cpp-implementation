#pragma once
#include "Iterable.h"

template<typename T, typename I>
class Collection
	: public Iterable<I>
{
public:
	virtual void addAll(T c) = 0;
	virtual void clear() = 0;
	virtual bool contains(int i) = 0;
	virtual bool isEmpty() = 0;
	virtual int max() = 0;
	virtual int size() = 0;
};