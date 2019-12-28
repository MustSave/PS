#include <stdio.h>

struct coord
{
    int x;
    int y;
};

void merge(coord tmp[], coord list[], int left, int mid, int right)
{
    int i = left;
    int j = mid + 1;
    int k = left;

    while (i <= mid && j <= right)
    {
        tmp[k++] = list[i].x < list[j].x ? list[i++] : list[i].x == list[j].x ? list[i].y < list[j].y ? list[i++] : list[j++] : list[j++];
    }

    if (i > mid)
    {
        for (int a = j; a <= right; a++)
            tmp[k++] = list[a];
    }
    else
    {
        for (int a = i; a <= mid; a++)
            tmp[k++] = list[a];
    }

    for (int a = left; a <= right; a++)
        list[a] = tmp[a];
}

void merge_sort(coord tmp[], coord list[], int left, int right)
{
    int mid;

    if (left < right)
    {
        mid = (left + right) / 2;

        merge_sort(tmp, list, left, mid);
        merge_sort(tmp, list, mid + 1, right);

        merge(tmp, list, left, mid, right);
    }
}

int main()
{
    int N, x, y, j;
    scanf("%d", &N);

    struct coord c[N];
    struct coord tmp[N];

    for (int i = 0; i < N; i++)
    {
        scanf("%d %d", &c[i].x, &c[i].y);
    }

    merge_sort(tmp, c, 0, N - 1);

    for (int i = 0; i < N; i++)
    {
        printf("%d %d\n", c[i].x, c[i].y);
    }

    return 0;
}