#pragma once
#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using std::string;
using std::to_string;
using std::cout;
using std::endl;

template< class T = int >
class list {
public:
	T value;
	list<T>* next;
};
