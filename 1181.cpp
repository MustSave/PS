#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void swap(int &a, int &b)
{
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}

void merge(int sorted[], int idx[], char list[][51], int left, int mid, int right)
{
    int i = left;
    int j = mid + 1;
    int k = left;

    while (i <= mid && j <= right)
    {
        if (strlen(list[idx[i]]) < strlen(list[idx[j]]))
        {
            sorted[k++] = idx[i++];
        }
        else if (strlen(list[idx[i]]) == strlen(list[idx[j]])) {
            if (strcmp(list[idx[i]], list[idx[j]]) > 0) {
                sorted[k++] = idx[j++];
            }
            else {
                sorted[k++] = idx[i++];
            }
        }
        else
        {
            sorted[k++] = idx[j++];
        }
    }

    if (i > mid)
    {
        for (int a = j; a <= right; a++)
        {
            sorted[k++] = idx[a];
        }
    }
    else
    {
        for (int a = i; a <= mid; a++)
        {
            sorted[k++] = idx[a];
        }
    }

    for (int a = left; a <= right; a++)
    {
        idx[a] = sorted[a];
    }
}

void merge_sort(int sorted[], int idx[], char list[][51], int left, int right)
{
    int mid;

    if (left < right)
    {
        mid = (left + right) / 2;
        merge_sort(sorted, idx, list, left, mid);
        merge_sort(sorted, idx, list, mid + 1, right);

        merge(sorted, idx, list, left, mid, right);
    }
}

int main()
{
    int N;
    scanf("%d", &N);

    char c[N][51];
    int a[N];
    int b[N];

    for (int i = 0; i < N; i++)
        b[i] = i;

    for (int i = 0; i < N; i++)
    {
        scanf("%s", &c[i]);
        a[i] = strlen(c[i]);
    }

    merge_sort(a, b, c, 0, N - 1);

    for (int i = 0; i < N; i++)
    {

        if (i == 0)
        {
            if (b[i] == 0)
                printf("%s\n", c[b[i]]);
            else
            {
                int k;
                for (k = 0; k < N; k++)
                {
                    if (b[k] == b[0] - 1)
                        break;
                }
                if (strcmp(c[b[i]], c[b[k]]) != 0)
                {
                    printf("%s\n", c[b[i]]);
                }
            }
        }
        else
        {
            if (strcmp(c[b[i]], c[b[i - 1]]) != 0)
            {
                printf("%s\n", c[b[i]]);
            }
        }
    }
}