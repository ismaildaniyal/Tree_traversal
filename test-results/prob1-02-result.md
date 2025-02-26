(TEST 2) rcqueue_add_rear1 : ok
===============================

COMMENTS
--------


PROGRAM: ./test_mazesolve_funcs rcqueue_add_rear1
-------------------------------------------------
To run this individual test in GDB use the command:
  gdb --args ./test_mazesolve_funcs rcqueue_add_rear1
but any input to the program must be typed within the debugger

FAILURE MESSAGES
----------------
None

SIDE-BY-SIDE DIFF of Expected vs Actual
---------------------------------------
. lines match; | lines differ; < expected line missing; > extra line in actual

```sdiff
===EXPECT===                                                             ===ACTUAL===
IF_TEST("rcqueue_add_rear1") {                                         . IF_TEST("rcqueue_add_rear1") {
    // Add a single element to the queue and print that node. Verifies .     // Add a single element to the queue and print that node. Verifies
    // that the front/rear node is the same for a single element add.  .     // that the front/rear node is the same for a single element add.
    rcqueue_t *queue = rcqueue_allocate();                             .     rcqueue_t *queue = rcqueue_allocate();
    rcqueue_add_rear(queue,5,9);                                       .     rcqueue_add_rear(queue,5,9);
    printf("queue->count: %d\n",queue->count);                         .     printf("queue->count: %d\n",queue->count);
    printf("queue->front->row: %d\n",queue->front->row);               .     printf("queue->front->row: %d\n",queue->front->row);
    printf("queue->front->col: %d\n",queue->front->col);               .     printf("queue->front->col: %d\n",queue->front->col);
    printf("queue->rear->row: %d\n",queue->rear->row);                 .     printf("queue->rear->row: %d\n",queue->rear->row);
    printf("queue->rear->col: %d\n",queue->rear->col);                 .     printf("queue->rear->col: %d\n",queue->rear->col);
    rcqueue_free(queue);                                               .     rcqueue_free(queue);
}                                                                      . }
---OUTPUT---                                                           . ---OUTPUT---
queue->count: 1                                                        . queue->count: 1
queue->front->row: 5                                                   . queue->front->row: 5
queue->front->col: 9                                                   . queue->front->col: 9
queue->rear->row: 5                                                    . queue->rear->row: 5
queue->rear->col: 9                                                    . queue->rear->col: 9

```

LINE-BY-LINE DIFF of Expected vs Actual
---------------------------------------
No differences found

VALGRIND REPORT
---------------
The program is run on under valgrind as
  stdbuf -i 0 -o 0 -e 0 valgrind --error-exitcode=13 --leak-check=full --show-leak-kinds=all --track-origins=yes ./test_mazesolve_funcs rcqueue_add_rear1
which may be pasted onto a command line to run it.

```
==15376== Memcheck, a memory error detector
==15376== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==15376== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==15376== Command: ./test_mazesolve_funcs rcqueue_add_rear1
==15376== 
==15376== 
==15376== HEAP SUMMARY:
==15376==     in use at exit: 0 bytes in 0 blocks
==15376==   total heap usage: 2 allocs, 2 frees, 40 bytes allocated
==15376== 
==15376== All heap blocks were freed -- no leaks are possible
==15376== 
==15376== For lists of detected and suppressed errors, rerun with: -s
==15376== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

SUMMARY
-------
Test Passed
