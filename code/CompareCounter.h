#ifndef ALGS_SET09_COMPARECOUNTER_H
#define ALGS_SET09_COMPARECOUNTER_H

#pragma once
#include <string>

struct CompareCounter {
  static size_t comparisons;
  static void reset();

  template<typename T>
  static int compare(const T& a, const T& b) {
    ++comparisons;
    if (a < b) return -1;
    if (a > b) return 1;
    return 0;
  }
};

#endif
