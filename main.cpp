#include <iostream>
#include <algorithm>
using namespace std;

#include "iostream/InputData.h"
#include "iostream/OutputData.h"

int main()
{
	auto vec = InputData<std::vector<int>>();
	std::sort(vec.begin(), vec.end());
	OutputData(vec, ", ");
	return 0;
}
