#include <exception>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>
#include <tuple>
#include <utility>

using namespace std;
bool operator<(const Region& larg, const Region& rarg) {
  return tie(lhs.std_name, lhs.parent_std_name, lhs.names, lhs.population) <
      tie(rhs.std_name, rhs.parent_std_name, rhs.names, rhs.population);
}

int FindMaxRepetitionCount(const vector<Region>& regions) {
  int result = 0;
  map<Region, int> repetition_count;
  for (const Region& region : regions) {
    result = max(result, ++repetition_count[region]);
  }
  return result;
}