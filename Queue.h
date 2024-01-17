#ifndef _QUEUE_H_
#define _QUEUE_H_
#include <iostream>
#include <exception>
#include "Array.h"
// COMMENT Per the assignment directions, you are required to use the
//  Array class from assignment 1. Because you failed to follow directions
//  you will not be receiving any feedback on your queue implementation.

template <typename T>
class Queue{

public:
	
	typedef T type;
	class empty_exception : public std::exception
	{
	public:
	  empty_exception(void)
		:std::exception(){
		std::cout<<"Queue is empty"<<std::endl;
	  }
	  empty_exception(const char * msg)
		:std::exception(msg){
		 std::cout<<"Queue is empty. Error Message: "<<msg<<std::endl; 
	} 
	};



	Queue(void);
	Queue(const Queue & queue);
	~Queue(void);
	void enqueue(T element);
	T dequeue();
	bool is_empty();
	size_t size();
	void clear();
private:
	Array <T>q;
	int qsize;

};
#include "Queue.cpp"

#endif
