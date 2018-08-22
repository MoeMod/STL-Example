#pragma once

#include <iostream>
#include <iterator>
#include <algorithm>

template<class ContainerType>
void OutputData(const ContainerType &container, const char *delim = " ", std::ostream &out = std::cout)
{
	// Need to support legacy array such as int[10]
	//using ElementType = typename ContainerType::value_type;
	using ElementType = decltype(*std::cbegin(container));
	std::copy(std::cbegin(container), std::cend(container), std::ostream_iterator<ElementType>(out, delim));
}

/*
Example:

auto vec = InputData<std::vector<int>>();
OutputData(vec, ", ");

*/