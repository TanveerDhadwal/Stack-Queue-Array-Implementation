//Array_Base.cpp

#include "Array_Base.h"

template <typename T>
Array_Base <T>::Array_Base(void)
	:data_(new T[0]),cur_size_(0)
{

}
template <typename T>
Array_Base <T>::Array_Base(size_t length)
	:data_(new T[length]), cur_size_(length)
{

}
template <typename T>
Array_Base <T>::Array_Base(size_t length,T fill)
	:data_(new T[length]),cur_size_(length)
{
	this->fill(fill);
}

template <typename T>
Array_Base <T>::Array_Base(const Array_Base & arr)
	:data_(new T[arr.size()]),cur_size_(arr.size())
{
	for(int i = 0; i < cur_size_; i++){
		data_[i] = arr.get(i);
	}
}
template <typename T>
Array_Base <T>::~Array_Base(void)
{
	delete[] data_;
}
template <typename T>
const Array_Base <T> & Array_Base <T>::operator = (const Array_Base & rhs)
{
	for(int i = 0; i < rhs.size(); i++){
		data_[i] = rhs.get(i);
	}
	cur_size_ = rhs.size();
	return data_;
} 
template <typename T>
const T & Array_Base <T>::operator [] (size_t index) const
{
	if(index > cur_size_){
		throw std::out_of_range("Out of Range");
	}
	return data_[index];
}
template <typename T>
T Array_Base <T>::get(size_t index) const
{
	if(index > cur_size_){
		throw std::out_of_range("Out of Range");
	}
	return data_[index];
}
template <typename T>
void Array_Base<T>::set(size_t index, T value)
{
	if(index > cur_size_){
		throw std::out_of_range("Out of Range");
	}
}
template <typename T>
int Array_Base <T>::find(T value) const
{
	for(int i = 0; i < cur_size_; i++){
		if(data_[i] == value){
			return i;
		}
	}
	return -1;
}
template <typename T>
int Array_Base <T>::find(T val, size_t start) const
{
	if(start > cur_size_){
		throw std::out_of_range("Out of Range");
	}	
	for(int i = start; i <cur_size_; i++){
		if(data_[i] == val){
			return i;
		}
	}
	return -1;
}
template <typename T>
bool Array_Base <T>::operator == (const Array_Base & rhs) const
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
template <typename T>
bool Array_Base <T>::operator != (const Array_Base & rhs) const
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
template <typename T>
void Array_Base <T>::fill(T value){
	for(int i = 0; i < cur_size_; i++){
		data_[i] = value;
	}
}
