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

void shell_sort (int vet[], int n) {
  int gaps[] = {701, 301, 132, 57, 23, 10, 4, 1};

  for (int h = 0; h < 8; h++) {
    for (int i = gaps[h]; i < n; i++) {
      int j, key = vet[i];

      for (j = i - gaps[h]; j >= 0 && vet[j] > key; j -= gaps[h]) {
        vet[j + gaps[h]] = vet[j];
      }

      vet[j + gaps[h]] = key;
    }
  }
}

int partition (int vet[], int left, int right) {
  int i = left - 1, j = right + 1, pivot = vet[(left + right) / 2];

  while (1) {
    for (; vet[i] < pivot; i++);
    for (; vet[j] > pivot; j--);
    if (i >= j) return j;
    swap(&vet[i], &vet[j]);
  }
}

void quick_sort (int vet[], int left, int right) {
  if (left < right) {
    int p = partition(vet, left, right);
    quick_sort(vet, left, p);
    quick_sort(vet, p + 1, right);
  }
}

void cocktail_sort (int vet[], int n) {
  int sorted = 0;

  while (!sorted) {
    sorted = 1;

    for (int i = 0; i < n - 1; i++) {
      if (vet[i] > vet[i + 1]) {
        swap(&vet[i], &vet[i + 1]);
        sorted = 0;
      }
    }

    if (sorted) break;

    sorted = 1;

    for (int i = n - 1; i > 0; i--) {
      if (vet[i] < vet[i - 1]) {
        swap(&vet[i], &vet[i - 1]);
        sorted = 0;
      }
    }
  }
}

void comb_sort (int vet[], int n) {
  float shrink = 1.3;
  int gap = n, sorted = 0;

  while (!sorted) {
    gap /= shrink;

    if (gap <= 1) gap = sorted = 1;

    for (int i = 0; i < n - gap; i++) {
      if (vet[i] > vet[i + gap]) {
        swap(&vet[i], &vet[i + gap]);
        sorted = 0;
      }
    }
  }
}

void heapify (int vet[], int n, int i) {
  int largest = i, left = 2 * i + 1, right = 2 * i + 2;

  if (left < n && vet[left] > vet[largest]) largest = left;
  if (right < n && vet[right] > vet[largest]) largest = right;

  if (largest != i) {
    swap(&vet[i], &vet[largest]);
    heapify(vet, n, largest);
  }
}

void heap_sort (int vet[], int n) {
  for (int i = n / 2 - 1; i >= 0; i--) heapify(vet, n, i);

  for (int i = n - 1; i > 0; i--) {
    swap(&vet[0], &vet[i]);
    heapify(vet, i, 0);
  }
}

void counting_sort (int vet[], int n) {
  int i, j = 0, max = INT_MIN, min = INT_MAX;

  for (int i = 0; i < n; i++) {
    if (vet[i] > max) max = vet[i];
    if (vet[i] < min) min = vet[i];
  }

  int range = max - min + 1, *count = (int *) malloc(range * sizeof(int));

  for (i = 0; i < range; i++) count[i] = 0;
  for (i = 0; i < n; i++) count[vet[i] - min]++;

  for (i = min; i <= max; i++) {
    while (count[i - min]) {
      vet[j++] = i;
      count[i - min]--;
    }
  }
}
