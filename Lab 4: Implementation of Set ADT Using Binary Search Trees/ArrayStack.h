/*
 * ArrayStack.h
 *
 *  Created on: Dec 8, 2022
 *      Author: Scott Chen
 */

#include "Stack.h"

#ifndef ARRAYSTACK_H_
#define ARRAYSTACK_H_

// Array List implementation of Stack ADT
template <typename E>
class ArrayStack : public Stack<E>
{
	private:
		int capacity;
		E* items;
		int topIndex = -1;      // We dropped size. TOS is more useful.
								// -1 indicates Stack is Empty
	public:
		ArrayStack() : ArrayStack(100)
		{ };	// Default Size = 100

		ArrayStack(int n) 	// Constructor – create empty stack
		{
			items = new E[n];
			capacity = n;
		}

		virtual ~ArrayStack()
		{
			delete[] items;
		}	 	// Destructor

		virtual bool isEmpty();
		virtual E top();
		virtual void push(const E &e);
		virtual E pop();
};

#endif /* ARRAYSTACK_H_ */
