#include "StringSortTester.h"
#include "StringGenerator.h"
#include "CompareCounter.h"
#include <fstream>
#include <iostream>
#include <chrono>

using namespace std::chrono;

void StringSortTester::test(const std::string& algorithm, void (*sortFunc)(std::vector<std::string>&), const std::string& type) {
  std::ofstream out(algorithm + "_" + type + ".txt");

  for (int size = 100; size <= 3000; size += 100) {
    long long totalTime = 0;
    long long totalComparisons = 0;

    for (int rep = 0; rep < 100; ++rep) {
      std::vector<std::string> data;

      if (type == "random") {
        data = StringGenerator::generateRandom(size);
      }
      else if (type == "reversed") {
        data = StringGenerator::generateReversed(size);
      }
      else {
        data = StringGenerator::generateAlmostSorted(size);
      }

      CompareCounter::reset();

      auto start = high_resolution_clock::now();
      sortFunc(data);
      auto end = high_resolution_clock::now();

      totalTime += duration_cast<microseconds>(end - start).count();
      totalComparisons += CompareCounter::comparisons;
    }

    out << size << " " << (totalTime / 100) << " " << (totalComparisons / 100) << "\n";
  }

  out.close();
}

