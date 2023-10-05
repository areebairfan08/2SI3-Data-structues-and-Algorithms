/*
 * ArrayStack.cpp
 *
 *  Created on: Dec 8, 2022
 *      Author: Scott Chen
 */

#include <stdexcept>	// for exception throwing
#include "ArrayStack.h"

template <typename E>
bool ArrayStack<E>::isEmpty()
{
	return topIndex < 0;
}


template <typename E>
void ArrayStack<E>::push(const E &e)
{
	if(topIndex == capacity - 1)
	{
		E* newArray = new E[2 * capacity];

		for(int i = 0; i < capacity; i++)
		{
			newArray[i] = items[i];
		}

		delete[] items;
		items = newArray;
		capacity *= 2;
	}
	items[++topIndex] = e;
}


template <typename E>
E ArrayStack<E>::top()
{
	if(isEmpty())
	{
		throw std::underflow_error("Stack Underflow");
	}
	else
	{
		return items[topIndex];
	}
}


template <typename E>
E ArrayStack<E>::pop()
{
	if(isEmpty())
	{
		throw std::underflow_error("Stack Underflow");
	}
	else
	{
		E tempE = items[topIndex--];
		return tempE;
	}
}


// Pre-template generation - not recommended
template class ArrayStack<int>;
template class ArrayStack<char>;
template class ArrayStack<float>;
template class ArrayStack<double>;
template class ArrayStack<long>;
template class ArrayStack<bool>;
template class ArrayStack<short>;
