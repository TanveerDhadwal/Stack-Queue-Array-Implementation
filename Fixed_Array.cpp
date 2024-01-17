// $Id: Fixed_Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

//
// Fixed_Array
//

#include <stdexcept>
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (void)
	:data_(new T[N]),cur_size_(0)
{

}

//
// Fixed_Array
//
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (const Fixed_Array <T, N> & arr)
	:data_(new T[N]),cur_size_(N)
{
	for(int i = 0; i < arr.size(); i++){
		data_[i] = arr->get(i); 		
	}	
}

//
// Fixed_Array
//


//
// Fixed_Array
//
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (T fill)
	:data_(new T[N]),cur_size_(N)
{
	
	this->fill(fill);
}

//
// ~Fixed_Array
//
template <typename T, size_t N>
Fixed_Array <T, N>::~Fixed_Array (void)
{
	delete[] data_;
}

//
// operator =
//
template <typename T, size_t N>
const Fixed_Array <T, N> & Fixed_Array <T, N>::operator = (const Fixed_Array <T, N> & rhs)
{
	if(N == rhs->size()){
		for(int i = 0; i < N;i++){
			if(data_[i] == rhs->get(i)){

			}
			else{
				return false;
			}		
		}
		return true;
	}
	else{
		return false;
	}		
}

//
// operator =
//
template <typename T, size_t N>
template <size_t M>
const Fixed_Array <T, N> & Fixed_Array <T, N>::operator = (const Fixed_Array <T, M> & rhs)
{
	if(M == rhs->size()){
		for(int i =0; i < M; i++){
			if(data_[i] == rhs->get(i)){
			
			}
			else{
				return false;
			}
		}
		return true;
	}
	else{
		return false;

	}
}
template <typename T, size_t N>
void Fixed_Array<T,N>::fill(T element)
{
	for(int i = 0; i < N; i++){
		data_[i] = element;
	}
}

template <typename T,size_t N>
T Fixed_Array <T,N>::get(size_t index) const
{
	if(index > N){
		throw std::out_of_range("Out of Range");
	} 
	return data_[index];
}	
template <typename T,size_t N>
void Fixed_Array<T,N>::set(size_t index,T value)
{
	if(index > N){
		throw std::out_of_range("Out of Range");
	}
	data_[index] = value;

}
template <typename T,size_t N>
int Fixed_Array<T,N>::find( T value) const
{
	for(int i = 0; i < N;i++){
		if(data_[i]== value){
			return i;
		}
	return -1;
	}

}
template <typename T,size_t N>
int Fixed_Array<T,N>::find( T val,size_t start) const
{
	if(start > N){
		throw std::out_of_range("Out of Range");
	}
	for(int i = start; i < N; i++){
		if(data_[i] == val){
			return i;
		}
	}
	return -1;
}
