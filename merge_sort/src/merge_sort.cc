#include "merge_sort.h"

using namespace std;

void merge(vector<uint32_t>& numbers, size_t start, size_t middle, size_t end) {
  uint32_t left_len = middle - start + 1;
  uint32_t right_len = end - middle;
  vector<uint32_t> left(left_len);
  vector<uint32_t> right(right_len);
  for (size_t i = 0; i < left_len; ++i)
    left[i] = numbers[start + i];
  for (size_t i = 0; i < right_len; ++i)
    right[i] = numbers[middle + i + 1];

  for (size_t i = 0, j = 0, k = start; k <= end; ++k) {
    if (i >= left_len) numbers[k] = right[j++];
    else if (j >= right_len) numbers[k] = left[i++];
    else if (left[i] > right[j]) numbers[k] = right[j++];
    else numbers[k] = left[i++];
  }
}

void merge_sort(vector<uint32_t>& numbers, size_t start, size_t end) {
  if (start >= end) return;
  auto middle = (end - start) / 2 + start;
  merge_sort(numbers, start, middle);
  merge_sort(numbers, middle + 1, end);
  merge(numbers, start, middle, end);
}
