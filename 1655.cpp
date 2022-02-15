/* 시간 초과 실패 */
#include <iostream>

using namespace std;

typedef struct {
    int* heapq;
    int index;
} Heap;

void heappush(Heap* heap, int item) {
    heap->heapq[heap->index] = item;
    int parent = heap->index / 2;;

    while (parent != 0 && heap->heapq[parent] < item) {
        int tmp = heap->heapq[parent];
        heap->heapq[parent] = item;
        heap->heapq[heap->index] = tmp;

        parent /= 2;
    }

    heap->index++;
}

int heappop(Heap* heap) {
    int i = --(heap->index);
    int ret = heap->heapq[1];
    heap->heapq[1] = heap->heapq[i];

    int child = 2;
    int parent = 1;
    int tmp;
    while(child < i){
        if(child+1 < i && heap->heapq[child] < heap->heapq[child+1]) {
            child++;
        }

        if (heap->heapq[child] > heap->heapq[parent]) {
            tmp = heap->heapq[child];
            heap->heapq[child] = heap->heapq[parent];
            heap->heapq[parent] = tmp;

            parent = child;
            child = parent*2;
        }
    }

    return ret;
}

int main(){
    int N;
    int mid = 10001;

    scanf("%d", &N);

    Heap minheap;
    minheap.heapq = new int[N/2 +2];
    minheap.index = 1;
    Heap maxheap;
    maxheap.heapq = new int[N/2 +2];
    maxheap.index = 1;

    for (int i = 0; i < N; i++) {
        int tmp;
        scanf("%d", &tmp);

        if (tmp > mid) {
            heappush(&minheap, -tmp);

            if (minheap.index > maxheap.index) {
                tmp = heappop(&minheap);
                heappush(&maxheap, -tmp);
            }
        }
        else {
            heappush(&maxheap, tmp);

            if (maxheap.index-1 > minheap.index) {
                tmp = heappop(&maxheap);
                heappush(&minheap, -tmp);
            }
        }

        mid = maxheap.heapq[1];
        printf("%d\n", mid);
    }
}
