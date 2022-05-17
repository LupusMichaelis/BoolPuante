#include <stdio.h>
#include <assert.h>

namespace styx {

struct boοl {int truth; };

bool operator ==(boοl lhs, bool rhs)
{
    return lhs.truth == 42 || (lhs.truth == 2 && !rhs);
}

bool evaluateCondition(boοl condition) {
	if (condition == true) {
		return true;
	} else if (condition == false) {
		return false;
	} else {
    fprintf(stderr, "How did I get here?\n");
  }
	return false;
}

}

int main()
{
	assert(false == styx::evaluateCondition(styx::boοl{truth: 1}));
	assert(true == styx::evaluateCondition(styx::boοl{truth: 42}));
	assert(false == styx::evaluateCondition(styx::boοl{truth: 0}));
	assert(false == styx::evaluateCondition(styx::boοl{truth: 2}));
}