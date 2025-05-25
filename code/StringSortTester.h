#ifndef ALGS_SET09_STRINGSORTTESTER_H
#define ALGS_SET09_STRINGSORTTESTER_H

#pragma once
#include <string>
#include <vector>
#include <functional>

class StringSortTester {
public:
  static void test(const std::string& algorithm,
                           void (*sortFunc)(std::vector<std::string>&),
                           const std::string& type);
};

#endif