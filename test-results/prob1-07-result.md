(TEST 7) rcqueue_remove_front3 : ok
===================================

COMMENTS
--------


PROGRAM: ./test_mazesolve_funcs rcqueue_remove_front3
-----------------------------------------------------
To run this individual test in GDB use the command:
  gdb --args ./test_mazesolve_funcs rcqueue_remove_front3
but any input to the program must be typed within the debugger

FAILURE MESSAGES
----------------
None

SIDE-BY-SIDE DIFF of Expected vs Actual
---------------------------------------
. lines match; | lines differ; < expected line missing; > extra line in actual

```sdiff
===EXPECT===                                                            ===ACTUAL===
IF_TEST("rcqueue_remove_front3") {                                    . IF_TEST("rcqueue_remove_front3") {
    // Adds 3 coordinates to the queue and then removes all 3 before  .     // Adds 3 coordinates to the queue and then removes all 3 before
    // printing to show whether the queue is properly empty. If rear  .     // printing to show whether the queue is properly empty. If rear
    // pointer is not set to NULL, this test will print incorrect     .     // pointer is not set to NULL, this test will print incorrect
    // results. Checks progressive attempts to get the row/col of the .     // results. Checks progressive attempts to get the row/col of the
    // front node to verify it is the correct value and the return    .     // front node to verify it is the correct value and the return
    // values of remove/get calls.                                    .     // values of remove/get calls.
    int ret, row, col;                                                .     int ret, row, col;
    rcqueue_t *queue = rcqueue_allocate();                            .     rcqueue_t *queue = rcqueue_allocate();
    rcqueue_add_rear(queue,10,2);                                     .     rcqueue_add_rear(queue,10,2);
    rcqueue_add_rear(queue,9,3);                                      .     rcqueue_add_rear(queue,9,3);
    rcqueue_add_rear(queue,11,4);                                     .     rcqueue_add_rear(queue,11,4);
    ret = rcqueue_remove_front(queue);                                .     ret = rcqueue_remove_front(queue);
    printf("remove ret: %d\n",ret);                                   .     printf("remove ret: %d\n",ret);
    ret = rcqueue_get_front(queue, &row, &col);                       .     ret = rcqueue_get_front(queue, &row, &col);
    printf("get ret: %d\n",ret);                                      .     printf("get ret: %d\n",ret);
    printf("front row/col: (%d,%d)\n",row,col);                       .     printf("front row/col: (%d,%d)\n",row,col);
    ret = rcqueue_remove_front(queue);                                .     ret = rcqueue_remove_front(queue);
    printf("remove ret: %d\n",ret);                                   .     printf("remove ret: %d\n",ret);
    ret = rcqueue_get_front(queue, &row, &col);                       .     ret = rcqueue_get_front(queue, &row, &col);
    printf("get ret: %d\n",ret);                                      .     printf("get ret: %d\n",ret);
    printf("front row/col: (%d,%d)\n",row,col);                       .     printf("front row/col: (%d,%d)\n",row,col);
    ret = rcqueue_remove_front(queue);                                .     ret = rcqueue_remove_front(queue);
    printf("remove ret: %d\n",ret);                                   .     printf("remove ret: %d\n",ret);
    printf("queue->count: %d\n",queue->count);                        .     printf("queue->count: %d\n",queue->count);
    printf("queue->count: %d\n",queue->count);                        .     printf("queue->count: %d\n",queue->count);
    printf("queue->front: %p\n",queue->front);                        .     printf("queue->front: %p\n",queue->front);
    printf("queue->rear:  %p\n",queue->rear);                         .     printf("queue->rear:  %p\n",queue->rear);
    ret = rcqueue_get_front(queue, &row, &col);                       .     ret = rcqueue_get_front(queue, &row, &col);
    printf("get ret: %d\n",ret);                                      .     printf("get ret: %d\n",ret);
    printf("front row/col: (%d,%d) //previous vals\n",row,col);       .     printf("front row/col: (%d,%d) //previous vals\n",row,col);
    ret = rcqueue_remove_front(queue);                                .     ret = rcqueue_remove_front(queue);
    printf("remove ret: %d\n",ret);                                   .     printf("remove ret: %d\n",ret);
    printf("queue->count: %d\n",queue->count);                        .     printf("queue->count: %d\n",queue->count);
    printf("queue->count: %d\n",queue->count);                        .     printf("queue->count: %d\n",queue->count);
    printf("queue->front: %p\n",queue->front);                        .     printf("queue->front: %p\n",queue->front);
    printf("queue->rear:  %p\n",queue->rear);                         .     printf("queue->rear:  %p\n",queue->rear);
    rcqueue_free(queue);                                              .     rcqueue_free(queue);
}                                                                     . }
---OUTPUT---                                                          . ---OUTPUT---
remove ret: 1                                                         . remove ret: 1
get ret: 1                                                            . get ret: 1
front row/col: (9,3)                                                  . front row/col: (9,3)
remove ret: 1                                                         . remove ret: 1
get ret: 1                                                            . get ret: 1
front row/col: (11,4)                                                 . front row/col: (11,4)
remove ret: 1                                                         . remove ret: 1
queue->count: 0                                                       . queue->count: 0
queue->count: 0                                                       . queue->count: 0
queue->front: (nil)                                                   . queue->front: (nil)
queue->rear:  (nil)                                                   . queue->rear:  (nil)
get ret: 0                                                            . get ret: 0
front row/col: (11,4) //previous vals                                 . front row/col: (11,4) //previous vals
remove ret: 0                                                         . remove ret: 0
queue->count: 0                                                       . queue->count: 0
queue->count: 0                                                       . queue->count: 0
queue->front: (nil)                                                   . queue->front: (nil)
queue->rear:  (nil)                                                   . queue->rear:  (nil)

```

LINE-BY-LINE DIFF of Expected vs Actual
---------------------------------------
No differences found

VALGRIND REPORT
---------------
The program is run on under valgrind as
  stdbuf -i 0 -o 0 -e 0 valgrind --error-exitcode=13 --leak-check=full --show-leak-kinds=all --track-origins=yes ./test_mazesolve_funcs rcqueue_remove_front3
which may be pasted onto a command line to run it.

```
==15382== Memcheck, a memory error detector
==15382== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==15382== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==15382== Command: ./test_mazesolve_funcs rcqueue_remove_front3
==15382== 
==15382== 
==15382== HEAP SUMMARY:
==15382==     in use at exit: 0 bytes in 0 blocks
==15382==   total heap usage: 4 allocs, 4 frees, 72 bytes allocated
==15382== 
==15382== All heap blocks were freed -- no leaks are possible
==15382== 
==15382== For lists of detected and suppressed errors, rerun with: -s
==15382== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

SUMMARY
-------
Test Passed
