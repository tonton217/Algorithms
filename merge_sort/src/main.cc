#include <iostream>
#include <vector>
#include "merge_sort.h"

using namespace std;

void print_numbers(const vector<uint32_t>& numbers) {
  cout << "[ ";
  for (auto& number : numbers) {
    cout << number << " ";
  }
  cout << "]" << endl;
}

int main() {
  vector<uint32_t> numbers = { 5, 2, 4, 7, 1, 3, 2, 6 };
  cout << "unsorted numbers: " << endl;
  print_numbers(numbers);
  merge_sort(numbers, 0, numbers.size()-1);
  cout << "sorted numbers: " << endl;
  print_numbers(numbers);
  return 0;
}
