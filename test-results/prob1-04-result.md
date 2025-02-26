(TEST 4) rcqueue_get_front1 : ok
================================

COMMENTS
--------


PROGRAM: ./test_mazesolve_funcs rcqueue_get_front1
--------------------------------------------------
To run this individual test in GDB use the command:
  gdb --args ./test_mazesolve_funcs rcqueue_get_front1
but any input to the program must be typed within the debugger

FAILURE MESSAGES
----------------
None

SIDE-BY-SIDE DIFF of Expected vs Actual
---------------------------------------
. lines match; | lines differ; < expected line missing; > extra line in actual

```sdiff
===EXPECT===                                                       ===ACTUAL===
IF_TEST("rcqueue_get_front1") {                                  . IF_TEST("rcqueue_get_front1") {
    // Add several elements then use accessor get_front() to set .     // Add several elements then use accessor get_front() to set
    // integers to the front row/col. Ensures that proper        .     // integers to the front row/col. Ensures that proper
    // pointer-dereferencing is used.                            .     // pointer-dereferencing is used.
    int ret, row, col;                                           .     int ret, row, col;
    rcqueue_t *queue = rcqueue_allocate();                       .     rcqueue_t *queue = rcqueue_allocate();
    rcqueue_add_rear(queue,10,2);                                .     rcqueue_add_rear(queue,10,2);
    rcqueue_add_rear(queue,9,3);                                 .     rcqueue_add_rear(queue,9,3);
    rcqueue_add_rear(queue,11,4);                                .     rcqueue_add_rear(queue,11,4);
    ret = rcqueue_get_front(queue, &row, &col);                  .     ret = rcqueue_get_front(queue, &row, &col);
    printf("ret: %d\n",ret);                                     .     printf("ret: %d\n",ret);
    printf("front row/col: (%d,%d)\n",row,col);                  .     printf("front row/col: (%d,%d)\n",row,col);
    rcqueue_free(queue);                                         .     rcqueue_free(queue);
}                                                                . }
---OUTPUT---                                                     . ---OUTPUT---
ret: 1                                                           . ret: 1
front row/col: (10,2)                                            . front row/col: (10,2)

```

LINE-BY-LINE DIFF of Expected vs Actual
---------------------------------------
No differences found

VALGRIND REPORT
---------------
The program is run on under valgrind as
  stdbuf -i 0 -o 0 -e 0 valgrind --error-exitcode=13 --leak-check=full --show-leak-kinds=all --track-origins=yes ./test_mazesolve_funcs rcqueue_get_front1
which may be pasted onto a command line to run it.

```
==15378== Memcheck, a memory error detector
==15378== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==15378== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==15378== Command: ./test_mazesolve_funcs rcqueue_get_front1
==15378== 
==15378== 
==15378== HEAP SUMMARY:
==15378==     in use at exit: 0 bytes in 0 blocks
==15378==   total heap usage: 4 allocs, 4 frees, 72 bytes allocated
==15378== 
==15378== All heap blocks were freed -- no leaks are possible
==15378== 
==15378== For lists of detected and suppressed errors, rerun with: -s
==15378== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

SUMMARY
-------
Test Passed
