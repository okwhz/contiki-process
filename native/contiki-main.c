/*
 * Copyright (c) 2017, George Oikonomou - http://www.spd.gr
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE
 * COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/*---------------------------------------------------------------------------*/
/**
 * \addtogroup main
 * @{
 */
/*---------------------------------------------------------------------------*/
/**
 * \file
 *
 * Implementation of \os's main routine
 */
/*---------------------------------------------------------------------------*/
#include "contiki.h"
/* #include "sys/platform.h" */
#include <stdio.h>
/* #include <stdint.h> */
#include <unistd.h> //usleep声明
/*---------------------------------------------------------------------------*/
PROCESS_NAME(hello_world_process);
PROCESS_NAME(cfiles_process);
/*---------------------------------------------------------------------------*/
int _stack_origin;
int _stack;
int main(int argc, char **argv)
{
    /* platform_init_stage_one(); */
    clock_init();
    process_init();
    process_start(&etimer_process, NULL);
    /* process_start(&hello_world_process, NULL); */

    if(argc == 2) {
        process_start(&cfiles_process, argv);

    } else {
        process_start(&cfiles_process, NULL);
    }

    while(1) {
        process_num_events_t r;

        do {
            r = process_run();
            usleep(100000); /* if(etimer_pending())//此语句加上减少一点运行时间 */ etimer_request_poll(); /* watchdog_periodic(); */
        } while(r > 0); /* platform_idle(); */
    }

    return 0;
}
/*---------------------------------------------------------------------------*/
/**
 * @}
 */
