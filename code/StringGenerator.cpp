#include "StringGenerator.h"
#include "CompareCounter.h"
#include <random>
#include <algorithm>

const std::string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#%:;^&*()-.";

std::vector<std::string> StringGenerator::generateRandom(size_t n) {
  std::random_device rd;
  std::mt19937 gen(rd());

  std::uniform_int_distribution<> len_dist(10, 200);
  std::uniform_int_distribution<> char_dist(0, ALPHABET.size() - 1);

  std::vector<std::string> result(n);
  for (auto& s : result) {
    int len = len_dist(gen);
    s.resize(len);
    for (int i = 0; i < len; ++i) {
      s[i] = ALPHABET[char_dist(gen)];
    }
  }
  return result;
}

std::vector<std::string> StringGenerator::generateReversed(size_t n) {
  auto base = generateRandom(3000);

  std::sort(base.begin(), base.end(), [](const std::string& a, const std::string& b) {
    return CompareCounter::compare(a, b) < 0;
  });

  std::reverse(base.begin(), base.end());

  return { base.begin(), base.begin() + n };
}

std::vector<std::string> StringGenerator::generateAlmostSorted(size_t n) {
  auto base = generateRandom(3000);

  std::sort(base.begin(), base.end(), [](const std::string& a, const std::string& b) {
    return CompareCounter::compare(a, b) < 0;
  });

  std::random_device rd;
  std::mt19937 gen(rd());

  std::uniform_int_distribution<> dist(0, n - 1);

  for (int i = 0; i < n / 100; ++i) {
    int i1 = dist(gen);
    int i2 = dist(gen);

    if (i1 != i2) {
      std::swap(base[i1], base[i2]);
    }
  }
  return { base.begin(), base.begin() + n };
}
