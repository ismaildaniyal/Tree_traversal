(TEST 1) rcqueue_allocate_free1 : ok
====================================

COMMENTS
--------


PROGRAM: ./test_mazesolve_funcs rcqueue_allocate_free1
------------------------------------------------------
To run this individual test in GDB use the command:
  gdb --args ./test_mazesolve_funcs rcqueue_allocate_free1
but any input to the program must be typed within the debugger

FAILURE MESSAGES
----------------
None

SIDE-BY-SIDE DIFF of Expected vs Actual
---------------------------------------
. lines match; | lines differ; < expected line missing; > extra line in actual

```sdiff
===EXPECT===                                     ===ACTUAL===
IF_TEST("rcqueue_allocate_free1") {            . IF_TEST("rcqueue_allocate_free1") {
    // Allocate and free an empty queue.       .     // Allocate and free an empty queue.
    rcqueue_t *queue = rcqueue_allocate();     .     rcqueue_t *queue = rcqueue_allocate();
    printf("queue->count: %d\n",queue->count); .     printf("queue->count: %d\n",queue->count);
    printf("queue->front: %p\n",queue->front); .     printf("queue->front: %p\n",queue->front);
    printf("queue->rear:  %p\n",queue->rear);  .     printf("queue->rear:  %p\n",queue->rear);
    rcqueue_free(queue);                       .     rcqueue_free(queue);
}                                              . }
---OUTPUT---                                   . ---OUTPUT---
queue->count: 0                                . queue->count: 0
queue->front: (nil)                            . queue->front: (nil)
queue->rear:  (nil)                            . queue->rear:  (nil)

```

LINE-BY-LINE DIFF of Expected vs Actual
---------------------------------------
No differences found

VALGRIND REPORT
---------------
The program is run on under valgrind as
  stdbuf -i 0 -o 0 -e 0 valgrind --error-exitcode=13 --leak-check=full --show-leak-kinds=all --track-origins=yes ./test_mazesolve_funcs rcqueue_allocate_free1
which may be pasted onto a command line to run it.

```
==15375== Memcheck, a memory error detector
==15375== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==15375== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==15375== Command: ./test_mazesolve_funcs rcqueue_allocate_free1
==15375== 
==15375== 
==15375== HEAP SUMMARY:
==15375==     in use at exit: 0 bytes in 0 blocks
==15375==   total heap usage: 1 allocs, 1 frees, 24 bytes allocated
==15375== 
==15375== All heap blocks were freed -- no leaks are possible
==15375== 
==15375== For lists of detected and suppressed errors, rerun with: -s
==15375== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

SUMMARY
-------
Test Passed
