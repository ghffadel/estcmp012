void swap (int *x, int *y) {
  *x ^= *y;
  *y ^= *x;
  *x ^= *y;
}

void bubble_sort (int vet[], int n) {
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (vet[i] > vet[j]) {
        swap(&vet[i], &vet[j]);
      }
    }
  }
}

void selection_sort (int vet[], int n) {
  for (int i = 0; i < n - 1; i++) {
    int min_pos = i;

    for (int j = i + 1; j < n; j++) {
      if (vet[j] < vet[min_pos]) {
        min_pos = j;
      }
    }

    if (min_pos != i) {
      swap(&vet[i], &vet[min_pos]);
    }
  }
}

void insertion_sort (int vet[], int n) {
  for (int i = 1; i < n; i++) {
    int j, key = vet[i];

    for (j = i - 1; j >= 0 && vet[j] > key; j--) {
      vet[j + 1] = vet[j];
    }

    vet[j + 1] = key;
  }
}