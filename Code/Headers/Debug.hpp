#include <iostream>
namespace Debug{
template <typename T>
void Log(const T txt) { std::cout <<"\033[1;31m"<< txt <<"\033[0m"<< std::endl; };
}