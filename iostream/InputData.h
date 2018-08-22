#pragma once
#include <iostream>
#include <iterator>

template<class ContainerType>
ContainerType InputData(std::istream &in = std::cin)
{
	// ContainerType is template argument here so must add typename
	using ElementType = typename ContainerType::value_type;

	// pre-C++11, cannot use tempory object here. 
	// For more info, refer to Effective STL #6
	/*std::istream_iterator<ElementType> begin_iter(in);
	std::istream_iterator<ElementType> end_iter;
	return ContainerType(begin_iter, end_iter);*/

	// C++11, Range initialization
	return { std::istream_iterator<ElementType>{ in }, std::istream_iterator<ElementType>{} };
}

// Simplied for std::vector, same as below
#include <vector>
template<class T>
std::vector<T> InputDataToVector(std::istream &in = std::cin)
{
	return { std::istream_iterator<T>{ in }, std::istream_iterator<T>{} };
}

// For legacy array
#include <algorithm> // copy
template<class T, size_t N>
void InputDataToArray(T (&arr)[N], std::istream &in = std::cin)
{
	std::copy_n(std::istream_iterator<T>{ in }, N, std::begin(arr));
}

/*
Feature:
reads all data from cin (ending with CTRL+Z) into std::vector

Example:
auto vec = InputData<std::vector<int>>(); 
for(int x : vec) std::cout << x << ", ";
*/