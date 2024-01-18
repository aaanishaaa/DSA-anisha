#include<stdio.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void traverse(int A[], int N) {
    for (int i = 0; i < N; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void MaxHeapify(int A[], int i, int N) {
    int l, r, m;
    while (2 * i + 1 < N) {
        l = 2 * i + 1;
        r = l + 1;
        m = l;
        if (r < N && A[r] > A[l]) {
            m = r;
        }
        if (A[i] < A[m]) {
            swap(&A[i], &A[m]);
        } else {
            break;
        }
        i = m;
    }
}

void BMH(int A[], int N) {
    for (int i = (N - 1) / 2; i >= 0; i--) {
        MaxHeapify(A, i, N);
    }
}

void heapsort(int A[], int N) {
    BMH(A, N);
    int last = N - 1;
    while (last > 0) {
        swap(&A[0], &A[last]);
        MaxHeapify(A, 0, last);
        last--;
    }
}

int main() {
    int A[] = {9, 1, 32, 72, 30, 2, 8, 6, 3};
    int N = sizeof(A) / sizeof(A[0]);
    heapsort(A, N);
    traverse(A, N);

    return 0;
}
