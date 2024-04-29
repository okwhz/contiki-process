#include "queue.h"
queue_core qDebug;
void QUEUE_INIT(queue_core * q)
{
    q->front = 0;
    q->size  = 0;
}

void QUEUE_PUSH(queue_core * q,u8 e)
{
    if(q->size < QUEUE_MAX){
        q->q[(q->front + q->size) % QUEUE_MAX] = e;
        q->size++;
    }
}

u8 QUEUE_POP(queue_core * q)
{
    u8 e;
    if((q)->size > 0){
        e = q->q[q->front];
        q->front = (q->front + 1) % QUEUE_MAX;
        q->size--;
    }
    else{
        e = 0;
    }
    return (e);
}
