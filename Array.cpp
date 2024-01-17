#include "Array.h"
#include <stdexcept>         // for std::out_of_bounds exception

//
// Array
//
template <typename T>
Array <T>::Array (void)
	:data_(new T[0]),cur_size_(0)
{

}

//
// Array (size_t)
//
template <typename T>
Array <T>::Array (size_t length)
	:data_(new T[length]), cur_size_(length)
{

}

//
// Array (size_t, char)
//
template <typename T>
Array <T>::Array (size_t length, T fill)
	:data_(new T[length]),cur_size_(length)
{
	this->fill(fill);
}

//
// Array (const Array &)
//
template <typename T>
Array <T>::Array (const Array & array)
	:data_(new T[array.cur_size_])
{
	for(int i = 0; i < cur_size_; i++){
		data_[i] = array[i];
	}
}

//
// ~Array
//
template <typename T>
Array <T>::~Array (void)
{
	delete[] data_;
}

//
// operator =
//
template <typename T>
const Array <T> & Array <T>::operator = (const Array & rhs)
{
	int counter = 0;
	while(rhs[counter]){
		data_[counter] = rhs[counter];
		counter++;
	}
	cur_size_ = counter;
	return * this;
}

//
// operator []
//
template <typename T>
T & Array <T>::operator [] (size_t index)
{
	if(index > cur_size_){
		throw std::out_of_range("Out of Range");		
	}
	return data_[index];
}

//
// operator [] 
//
template <typename T>
const T & Array <T>::operator [] (size_t index) const
{
	if(index > cur_size_){
		throw std::out_of_range("Out of Range");
	}
	return data_[index];
}

//
// get
//
template <typename T>
T Array <T>::get (size_t index) const
{
	if(index > cur_size_){
		throw std::out_of_range("Out of Range");
	}
	return data_[index];
}

//
// set
//
template <typename T>
void Array <T>::set (size_t index, T value)
{
	if(index > cur_size_){
		throw std::out_of_range("Out of Range");
	}
	data_[index] = value;
}

//
// resize
//
template <typename T>
void Array <T>::resize (size_t new_size)
{
	if(new_size < cur_size_){
		cur_size_ = new_size;
	}
	else if (new_size > cur_size_){
		T * sub_Array = new T[new_size];
		for(int j = 0; j < cur_size_; j++){
			sub_Array[j] = data_[j];
		}
		delete[] data_;
		cur_size_ = new_size;
		data_ = sub_Array;
	}
}

//
// find (char)
//
template  <typename T>
int Array <T>::find (T value) const
{
	for(int i = 0; i < cur_size_; i++){
		if(data_[i] == value){
			return i;
		}
	}
	return -1;
}

//
// find (char, size_t) 
//
template <typename T>
int Array <T>::find (T val, size_t start) const
{
	if(start > cur_size_){
		throw std::out_of_range("Out of Range");
	}
	for(int i = start; i < cur_size_; i++){
		if(data_[i] == val){
			return i;
		}
	}
	return -1;
}

//
// operator ==
//
template <typename T>
bool Array <T>::operator == (const Array & rhs) const
{
	if(cur_size_ == rhs.size()){
		for(int i = 0; i < cur_size_; i++){
			if(data_[i] != rhs.get(i)){
				return true;
			}
		}
		return false;
	}
	else{
		return false;
	}
}

//
// operator !=
//
template <typename T>
bool Array <T>::operator != (const Array & rhs) const
{
	int counter = 0;
	if(cur_size_ == rhs.size()){
		return false;
	}
	else{
		for(int i = 0; i < cur_size_; i++){
			if(data_[i] == rhs.get(i)){
				counter++;
			}
		}
		if(counter == cur_size_){
			return true;
		}
		return false;
		
	}
}

//
// fill
//
template <typename T>
void Array <T>::fill (T value)
{
	for(int i = 0; i <cur_size_; i++){
		data_[i] = value;
	}
}
