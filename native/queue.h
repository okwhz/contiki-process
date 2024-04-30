#ifndef QUEUE_H
#define QUEUE_H

#include "contiki.h"
#define QUEUE_MAX 128
typedef struct {
    u8  q[QUEUE_MAX];
    u32 front;
    u32 size;
}queue_core;
extern queue_core qDebug;
void QUEUE_INIT(queue_core * q);
void QUEUE_PUSH(queue_core * q,u8 e);
u8   QUEUE_POP(queue_core * q);
#endif /* QUEUE_H */
