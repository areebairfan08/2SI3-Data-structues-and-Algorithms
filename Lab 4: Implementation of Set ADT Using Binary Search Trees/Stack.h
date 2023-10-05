/*
 * Stack.h
 *
 *  Created on: Dec 8, 2022
 *      Author: Scott Chen
 */

#ifndef STACK_H_
#define STACK_H_

// Stack Interface
template <typename E>
class Stack
{
	public:
		virtual bool isEmpty() = 0;
		virtual E top() = 0;
		virtual void push(const E &e) = 0;
		virtual E pop() = 0;
};

#endif /* STACK_H_ */
