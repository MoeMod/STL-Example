#pragma once
#include <string>
#include <sstream>

// MakeString: build a string using all args.
template<class...Args>
std::string MakeString(Args &&...args) // perfect forward
{
	std::ostringstream oss;
	int n[] = { (oss << std::forward<Args>(args), 0)... }; // oss<<arg1<<arg2<<...
	return oss.str();
}

template<class...Args>
std::wstring MakeStringW(Args &&...args) // perfect forward
{
	std::wostringstream oss;
	int n[] = { (oss << std::forward<Args>(args), 0)... }; // oss<<arg1<<arg2<<...
	return oss.str();
}

/*
Usage:
	replace clumsy sprintf
	
Requires:
	C++11
	args can be cout(ed).

Example:
	std::string str = MakeString(1, "2", 3.0, '4'); // std::string str("1234");
	puts(MakeString("Hello", "World").c_str()); // puts("Hello World");

Tips:
	MakeString CANNOT handle const wchar_t *
	MakeStringW CANNOT handle const char *
*/