#include<iostream>




template <typename T>
Queue <T>::Queue(void)
        :q(Array<T>(0)),qsize(0)
{

}

template<typename T>
Queue <T>::Queue(const Queue & queue)
        :q(Array<T>(queue.size())),qsize(queue.size())
{
        for(int i = 0; i < queue.size(); i++){
                q.set(i,queue.dequeue());
        }
}


template <typename T>
Queue <T>::~Queue(void)
{
//didn't know what I should destruct since all my code was on the stack
//and not the heap
}

template <typename T>
void Queue <T>::enqueue(T element)
{
        q.resize(qsize+1);
        q.set(qsize,element);
        qsize++;

}
template <typename T>
T Queue <T>::dequeue(){
	if(qsize == 0){
		throw empty_exception();
	}
	else{
        	T temp = q.get(0);
	        Array <T> temp_Array = Array<T>(qsize-1);
	        for(int i = 1; i < qsize; i++){
	                temp_Array.set(i-1,q.get(i));
	        }
	        for(int j = 0; j< qsize-1; j++){
			q.set(j,temp_Array.get(j));
		}
		q.resize(qsize-1);
		qsize--;
	        return temp;
	}
}
template <typename T>
bool Queue<T>::is_empty(){
        if(qsize == 0){
                return true;
        }
        else{
                return false;
        }
}
template <typename T>
size_t Queue <T>::size(){
         return qsize;
}

template <typename T>
void Queue <T>::clear(){
	q.resize(0);
	qsize = 0;
}  
