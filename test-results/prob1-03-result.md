(TEST 3) rcqueue_add_rear2 : ok
===============================

COMMENTS
--------


PROGRAM: ./test_mazesolve_funcs rcqueue_add_rear2
-------------------------------------------------
To run this individual test in GDB use the command:
  gdb --args ./test_mazesolve_funcs rcqueue_add_rear2
but any input to the program must be typed within the debugger

FAILURE MESSAGES
----------------
None

SIDE-BY-SIDE DIFF of Expected vs Actual
---------------------------------------
. lines match; | lines differ; < expected line missing; > extra line in actual

```sdiff
===EXPECT===                                                     ===ACTUAL===
IF_TEST("rcqueue_add_rear2") {                                 . IF_TEST("rcqueue_add_rear2") {
    // Add 3 elements successively to the queue then print the .     // Add 3 elements successively to the queue then print the
    // front/rear elements.                                    .     // front/rear elements.
    rcqueue_t *queue = rcqueue_allocate();                     .     rcqueue_t *queue = rcqueue_allocate();
    rcqueue_add_rear(queue,10,2);                              .     rcqueue_add_rear(queue,10,2);
    rcqueue_add_rear(queue,9,3);                               .     rcqueue_add_rear(queue,9,3);
    rcqueue_add_rear(queue,11,4);                              .     rcqueue_add_rear(queue,11,4);
    printf("queue->count: %d\n",queue->count);                 .     printf("queue->count: %d\n",queue->count);
    printf("queue->front->row: %d\n",queue->front->row);       .     printf("queue->front->row: %d\n",queue->front->row);
    printf("queue->front->col: %d\n",queue->front->col);       .     printf("queue->front->col: %d\n",queue->front->col);
    printf("queue->rear->row: %d\n",queue->rear->row);         .     printf("queue->rear->row: %d\n",queue->rear->row);
    printf("queue->rear->col: %d\n",queue->rear->col);         .     printf("queue->rear->col: %d\n",queue->rear->col);
    rcqueue_free(queue);                                       .     rcqueue_free(queue);
}                                                              . }
---OUTPUT---                                                   . ---OUTPUT---
queue->count: 3                                                . queue->count: 3
queue->front->row: 10                                          . queue->front->row: 10
queue->front->col: 2                                           . queue->front->col: 2
queue->rear->row: 11                                           . queue->rear->row: 11
queue->rear->col: 4                                            . queue->rear->col: 4

```

LINE-BY-LINE DIFF of Expected vs Actual
---------------------------------------
No differences found

VALGRIND REPORT
---------------
The program is run on under valgrind as
  stdbuf -i 0 -o 0 -e 0 valgrind --error-exitcode=13 --leak-check=full --show-leak-kinds=all --track-origins=yes ./test_mazesolve_funcs rcqueue_add_rear2
which may be pasted onto a command line to run it.

```
==15377== Memcheck, a memory error detector
==15377== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==15377== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==15377== Command: ./test_mazesolve_funcs rcqueue_add_rear2
==15377== 
==15377== 
==15377== HEAP SUMMARY:
==15377==     in use at exit: 0 bytes in 0 blocks
==15377==   total heap usage: 4 allocs, 4 frees, 72 bytes allocated
==15377== 
==15377== All heap blocks were freed -- no leaks are possible
==15377== 
==15377== For lists of detected and suppressed errors, rerun with: -s
==15377== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

SUMMARY
-------
Test Passed
