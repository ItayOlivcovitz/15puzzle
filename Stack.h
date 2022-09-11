#pragma once
#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "list.h"
using std::string;
using std::to_string;
using std::cout;
using std::endl;




template<class T = int >
class Stack
{
	int elements;
	list<T>* start;
	list<T>* end;

	list<T>* updateEnd()
	{
		list<T>* newEnd = this->start;
		for (int i = 0; i < this->elements-1; i++)
		{
			newEnd = newEnd->next;
		}
		newEnd->next = NULL;
		return newEnd;
	}

public:
	Stack()
	{
		start = NULL;
		start = new list<T>;
		end = start;
		this->elements = 0;
	}

	void push(const T value)
	{
		this->end->value = value;
		this->elements = this->elements + 1;

		list<T>* newList = new list<T>;
		newList->value = value;
		end->next = newList;

		end = newList;


	}
	T pop()
	{
		T value;
		
		list<T>* needToDelete = this->end;
		value = this->end->value;

		this->elements = this->elements - 1;
		delete needToDelete ;
		this->end =this->updateEnd();
		return value;
	}
	T top()
	{
		return this->end->value;
	}
	int size() const
	{
		return this->elements;
	}
	bool empty()
	{
		if (this->elements == 0)
		{
			return true;
		}
		return false;
	}

	void print_queue()
	{
		Stack<T> temp = *this;
		while (!temp.empty()) {
			cout << temp.front() << " ";
			temp.pop();
		}
		cout << '\n';
	}
	~Stack()
	{
	}
};





