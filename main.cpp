#include "LLLong.hpp"

int main() {
  LLLong a, c;
  a.getnum(std::cin);
  c.getnum(std::cin);
  a += c;
  a.printnum();
}