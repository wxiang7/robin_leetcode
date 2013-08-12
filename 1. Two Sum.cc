#include <set>
#include <vector>
#include <algorithm>
#include <utility>
#include <iostream>
#include <cstdlib>

using namespace std;

set<pair<int, int> >* twoSum(vector<int>& numbers, int sum);

int main() {
  vector<int> numbers;
  //srand(1012012);
  //for (int i = 0; i < 1000; ++i) {
  //  numbers.push_back(rand() % 1000);
  //}
  int ns[] = {150,24,79,50,88,345,3};
  for (int i = 0; i < 7; ++i)
    numbers.push_back(ns[i]);
  set<pair<int, int> >* result = twoSum(numbers, 200);
  set<pair<int, int> >::const_iterator it;
  for (it = result->begin(); it != result->end(); ++it) {
    cout << "(" << it->first << ", " << it->second << ")" << endl;
  }
}

set<pair<int, int> >* twoSum(vector<int>& numbers, int sum) {
  set<pair<int, int> >* results = new set<pair<int, int> >();
  sort(numbers.begin(), numbers.end());
  int first = 0, last = numbers.size() - 1;
  while (first < last) {
    int a = numbers[first]
      , b = sum - a;
    if (b < numbers[last])
      last--;
    else if (b == numbers[last]) {
      results->insert(pair<int, int>(first, last));
      first++;
      last--;
    } else {
      first++;
    }
  }
  return results;
}