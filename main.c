#include "MergeSort/mergeSort.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int arr[] = {12, 11, 13, 5, 6, 7};
  int size = sizeof(arr) / sizeof(arr[0]);

  if (argc > 1) {
    int argArr[argc - 1];
    for (int i = 1; i < argc; i++) {
      argArr[i - 1] = atoi(argv[i]);
    }
    mergeSort(argArr, 0, argc - 2);

    for (int i = 0; i < argc - 1; i++) {
      printf("%d ", argArr[i]);
    }
    printf("\n");
  }
  return 0;
}