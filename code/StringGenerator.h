#ifndef ALGS_SET09_STRINGGENERATOR_H
#define ALGS_SET09_STRINGGENERATOR_H

#pragma once
#include <vector>
#include <string>

class StringGenerator {
public:
  static std::vector<std::string> generateRandom(size_t n);
  static std::vector<std::string> generateReversed(size_t n);
  static std::vector<std::string> generateAlmostSorted(size_t n);
};

#endif
