#include "CompareCounter.h"

size_t CompareCounter::comparisons = 0;

void CompareCounter::reset() {
  comparisons = 0;
}

