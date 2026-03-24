#include <istream>
#include <string>
#include <deque>
#include <iostream>

int to_int(char s) {
  return s - 48;
}

struct LLLong {
    void getnum(std::istream& in);
    void printnum();
    void operator+=(LLLong q);
    size_t size();
    void operator=(LLLong q);
  private:
    std::string s;
    std::deque<int> d;
    size_t si;
};

void LLLong::getnum(std::istream& in) {
  in >> s;
  for (size_t i = 0; i < s.size(); ++i) {
    d.push_back(to_int(s[i]));
  }
  si = d.size();
  s = "";
}

void LLLong::printnum() {
  for (auto q:d) 
    std::cout << q;
  std::cout << "\n";
}

size_t LLLong::size() {
  return si;
}

void LLLong::operator=(LLLong q) {
  d = q.d;
  s = q.s;
  si = q.si;
}

void LLLong::operator+=(LLLong q) {
  if (q.si > si) {
    int ost = 0;
    std::deque<int> l;
    for (size_t i = q.si - 1; i > si - 1; --i) {
      int c = d[i - si] + q.d[i] + ost;
      ost = c/10;
      l.push_front(c%10);
    }
    for (size_t i = si - 1; i >= 0; --i) {
      if (i == 0) {
        int c = q.d[i] + ost;
        ost = c/10;
        l.push_front(c%10);
        break;
      } else {
        int c = q.d[i] + ost;
        ost = c/10;
        l.push_front(c%10);
      }
    }
    d = l;
    si = d.size();
  } else {
    int ost = 0;
    std::deque<int> l;
    for (size_t i = si - 1; i > q.si - 1; --i) {
      int c = q.d[i - q.si] + d[i] + ost;
      ost = c/10;
      l.push_front(c%10);
    }
    for (size_t i = q.si - 1; i >= 0; --i) {
      if (i == 0) {
        int c = d[i] + ost;
        ost = c/10;
        l.push_front(c%10);
        break;
      } else {
        int c = d[i] + ost;
        ost = c/10;
        l.push_front(c%10);
      }
    }
    d = l;
    si = d.size();
  }
}