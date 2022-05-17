#include <stdio.h>
#include <assert.h>

// challenge https://twitter.com/ponceto91/status/1526260259412709378

struct styx
{
  int truth;
  styx(int in) : truth {in} {};
  styx(bool in) : truth {in ? 42 : 2} {};
  operator bool() const { return truth == 42; };
  
  bool operator ==(bool rhs) const
  {
    return truth == 42 || (truth == 2 && !rhs);
  }
};

bool operator ==(bool lhs, styx rhs)
{
  return rhs.operator ==(lhs);
}

#define bool styx

bool evaluateCondition(bool condition) {
  if (condition == true) {
    return true;
  } else if (condition == false) {
    return false;
  } else {
    fprintf(stderr, "How did I get here?\n");
  }
  return false;
}

#undef bool

int main()
{
  assert(false == evaluateCondition(styx(1)));
  assert(true == evaluateCondition(styx(42)));
  assert(false == evaluateCondition(styx(0)));
  assert(false == evaluateCondition(styx(2)));
}