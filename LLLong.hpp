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
    void operator-=(LLLong a);
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

/*void LLLong::operator-=(LLLong q) {
  if (q.si > si) {
    int ost = 0;
    for (size_t i = q.si - 1, j = si - 1; i >= 0 && j >= 0; --i, --j) {
      if (q.d[i] >= d[i]) {

      }
    }
  }
}*/

void LLLong::operator+=(LLLong q) {
  if (q.si > si) {
    int ost = 0;
    std::deque<int> l;
    for (size_t i = q.si - 1, j = si - 1; i >= 0 && j >= 0; --i, --j) {
      if (i == 0 || j == 0) {
        int c = q.d[i] + d[j] + ost;
        ost = c/10;
        l.push_front(c%10);
        break;
      } else {
        int c = q.d[i] + d[j] + ost;
        ost = c/10;
        l.push_front(c%10);
      }
    }
    for (size_t i = q.si - 1 - si; i >= 0; --i) {
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
    if (ost)
      l.push_front(ost);
    d = l;
    si = d.size();
  } else if (q.si < si) {
    int ost = 0;
    std::deque<int> l;
    for (size_t i = q.si - 1, j = si - 1; i >= 0 && j >= 0; --i, --j) {
      if (i == 0 || j == 0) {
        int c = q.d[i] + d[j] + ost;
        ost = c/10;
        l.push_front(c%10);
        break;
      } else {
        int c = q.d[i] + d[j] + ost;
        ost = c/10;
        l.push_front(c%10);
      }
    }
    for (size_t i = si - 1 - q.si; i >= 0; --i) {
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
    if (ost)
      l.push_front(ost);
    d = l;
    si = d.size();
  } else {
    int ost = 0;
    std::deque<int> l;
    for (size_t i = q.si - 1, j = si - 1; i >= 0 && j >= 0; --i, --j) {
      if (i == 0 || j == 0) {
        int c = q.d[i] + d[j] + ost;
        ost = c/10;
        l.push_front(c%10);
        break;
      } else {
        int c = q.d[i] + d[j] + ost;
        ost = c/10;
        l.push_front(c%10);
      }
    }
    if (ost)
      l.push_front(ost);
    d = l;
    si = d.size();
  }
}