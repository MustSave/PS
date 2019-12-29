#include <stdio.h>

struct person{
    int age;
    char name[101];
};

void swap(person& a, person& b) {
    person tmp = a;
    a = b;
    b = tmp;
}

void merge(int left, int mid, int right, person* p, int* index, int* tmp) {
    int i = left;
    int j = mid+1;
    int k = left;

    while(i <= mid && j <= right) {
        if (p[index[i]].age < p[index[j]].age) {
            tmp[k++] = index[i++];
        }
        else if (p[index[i]].age == p[index[j]].age) {
            tmp[k++] = index[i++];
        }
        else {
            tmp[k++] = index[j++];
        }
    }

    if (i > mid) {
        for (int a = j; a <= right; a++) {
            tmp[k++] = index[a];
        }
    }
    else {
        for (int a = i; a <= mid; a++) {
            tmp[k++] = index[a];
        }
    }

    for (int a = left; a <= right; a++) {
        index[a] = tmp[a];
    }
}

void merge_sort(int left, int right, person* p, int* index, int* tmp) {
    int mid;

    if (left < right) {
        mid = (left+right)/2;

        merge_sort(left, mid, p, index, tmp);
        merge_sort(mid+1, right, p, index, tmp);

        merge(left, mid, right, p, index, tmp);
    }
}

int main() {
    int N;
    scanf("%d", &N);

    struct person p[N];
    int index[N];
    int tmp[N];

    for (int i = 0; i < N; i++) {
        scanf("%d %s", &p[i].age, &p[i].name);
        index[i] = i;
    }

    merge_sort(0, N-1, p, index, tmp);

    for (int i = 0; i < N; i++) {
        printf("%d %s\n", p[index[i]].age, p[index[i]].name);
    }
}