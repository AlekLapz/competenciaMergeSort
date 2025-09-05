#ifndef MERGESORT_H
#define MERGESORT_H

#include <vector>
void mergeSort(std::vector<int>& arr, int left, int right);
void merge(std::vector<int>& arr, int left, int mid, int right);
void printArray(const std::vector<int>& arr);

#endif