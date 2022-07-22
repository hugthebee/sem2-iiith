#include "deque.h"

int main()
{
    deque* Q = initializedeque();
    pushFront(Q,5);
    pushFront(Q,-56);
    pushFront(Q,91);
    pushFront(Q,78);
    pushBack(Q,45);

    int ans = popFront(Q);
    printf("popped element -> %d\n",ans);

    ans = popBack(Q);
    printf("popped element -> %d\n",ans);

    ans = front(Q);
    printf("front element -> %d\n",ans);

    ans = isEmpty(Q);
    printf("Is queue empty? -> %d\n",ans);

    ans = size(Q);
    printf("size -> %d\n",ans);

    printDeque(Q);
}