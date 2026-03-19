#include <istream>
#include <string>
#include <deque>
#include <iostream>


struct LLLong {
    void getnum(std::istream& in);
    void printnum();
    LLLong operator+(LLLong q);
    size_t size();
    LLLong operator=(LLLong q);
  private:
    std::string s;
    std::deque<int> d;
    size_t si;
};