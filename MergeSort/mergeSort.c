#include "./mergeSort.h"

#include <stdio.h>
#include <stdlib.h>

// Merge two sorted subarrays:
// arr[l..m] and arr[m+1..r] are sorted. Merge them into arr[l..r].
void mergeProcess(int arr[], int l, int m, int r) {
  int n1 = m - l + 1;
  int n2 = r - m;

  // create temporary arrays
  int *L = malloc(n1 * sizeof(int));
  int *R = malloc(n2 * sizeof(int));
  if (L == NULL || R == NULL) {
    // handle memory allocation failure
    fprintf(stderr, "Memory allocation failed\n");
    exit(EXIT_FAILURE);
  }

  // copy data into temp arrays
  for (int i = 0; i < n1; i++) {
    L[i] = arr[l + i];
  }
  for (int j = 0; j < n2; j++) {
    R[j] = arr[m + 1 + j];
  }

  // merge back to arr[l..r]
  int i = 0, j = 0, k = l;
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      arr[k++] = L[i++];
    } else {
      arr[k++] = R[j++];
    }
  }
  // copy remaining elements (if any)
  while (i < n1) {
    arr[k++] = L[i++];
  }
  while (j < n2) {
    arr[k++] = R[j++];
  }

  free(L);
  free(R);
}

// Recursive merge sort on arr[l..r]
void mergeSort(int arr[], int l, int r) {
  if (l < r) {
    int m = l + (r - l) / 2; // avoid overflow

    // sort first half
    mergeSort(arr, l, m);
    // sort second half
    mergeSort(arr, m + 1, r);

    // merge them
    mergeProcess(arr, l, m, r);
  }
}