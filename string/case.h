#pragma once
#include <string>
#include <algorithm>
#include <cctype>
#include <cwctype>

std::string tolower(std::string s)
{
	std::transform(s.begin(), s.end(), s.begin(), std::tolower);
	return s;
}
std::wstring towlower(std::wstring s)
{
	std::transform(s.begin(), s.end(), s.begin(), std::towlower);
	return s;
}
std::string toupper(std::string s)
{
	std::transform(s.begin(), s.end(), s.begin(), std::toupper);
	return s;
}
std::wstring towupper(std::wstring s)
{
	std::transform(s.begin(), s.end(), s.begin(), std::towupper);
	return s;
}

/*
Example:
std::string str("abcd"); // std::string str("1234");
puts(toupper(str).c_str()); // puts("ABCD");
*/