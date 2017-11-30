#pragma once
#include "TestTemplate.h"

template<class T>
TestTemplate<T>::TestTemplate(T val)
{
	this->val = val;
}

template<class T>
void TestTemplate<T>::setVal(T val)
{
	this->val = val;
}

template<class T>
T TestTemplate<T>::getVal()
{
	return val;
}
