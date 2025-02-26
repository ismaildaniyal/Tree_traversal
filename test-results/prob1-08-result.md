(TEST 8) rcqueue_print1 : ok
============================

COMMENTS
--------


PROGRAM: ./test_mazesolve_funcs rcqueue_print1
----------------------------------------------
To run this individual test in GDB use the command:
  gdb --args ./test_mazesolve_funcs rcqueue_print1
but any input to the program must be typed within the debugger

FAILURE MESSAGES
----------------
None

SIDE-BY-SIDE DIFF of Expected vs Actual
---------------------------------------
. lines match; | lines differ; < expected line missing; > extra line in actual

```sdiff
===EXPECT===                                                        ===ACTUAL===
IF_TEST("rcqueue_print1") {                                       . IF_TEST("rcqueue_print1") {
    // Print an empty and single element queue                    .     // Print an empty and single element queue
    rcqueue_t *queue = rcqueue_allocate();                        .     rcqueue_t *queue = rcqueue_allocate();
    rcqueue_add_rear(queue,10,2);                                 .     rcqueue_add_rear(queue,10,2);
    rcqueue_free(queue);                                          .     rcqueue_free(queue);
}                                                                 . }
---OUTPUT---                                                      . ---OUTPUT---
IF_TEST("rcqueue_print1") {                                       . IF_TEST("rcqueue_print1") {
    // Add coordinates to a queue printing after each addition to .     // Add coordinates to a queue printing after each addition to
    // ensure proper printing format.                             .     // ensure proper printing format.
    rcqueue_t *queue = rcqueue_allocate();                        .     rcqueue_t *queue = rcqueue_allocate();
    printf("EMPTY QUEUE:\n");                                     .     printf("EMPTY QUEUE:\n");
    rcqueue_print(queue);                                         .     rcqueue_print(queue);
    rcqueue_add_rear(queue,10,2);                                 .     rcqueue_add_rear(queue,10,2);
    printf("\nONE ELEMENT QUEUE:\n");                             .     printf("\nONE ELEMENT QUEUE:\n");
    rcqueue_print(queue);                                         .     rcqueue_print(queue);
    rcqueue_add_rear(queue,9,3);                                  .     rcqueue_add_rear(queue,9,3);
    rcqueue_add_rear(queue,11,4);                                 .     rcqueue_add_rear(queue,11,4);
    printf("THREE ELEMENT QUEUE:\n");                             .     printf("THREE ELEMENT QUEUE:\n");
    rcqueue_print(queue);                                         .     rcqueue_print(queue);
    rcqueue_free(queue);                                          .     rcqueue_free(queue);
}                                                                 . }
---OUTPUT---                                                      . ---OUTPUT---
EMPTY QUEUE:                                                      . EMPTY QUEUE:
queue count: 0                                                    . queue count: 0
NN ROW COL                                                        . NN ROW COL
                                                                  . 
ONE ELEMENT QUEUE:                                                . ONE ELEMENT QUEUE:
queue count: 1                                                    . queue count: 1
NN ROW COL                                                        . NN ROW COL
 0  10   2                                                        .  0  10   2
THREE ELEMENT QUEUE:                                              . THREE ELEMENT QUEUE:
queue count: 3                                                    . queue count: 3
NN ROW COL                                                        . NN ROW COL
 0  10   2                                                        .  0  10   2
 1   9   3                                                        .  1   9   3
 2  11   4                                                        .  2  11   4
2 tests run                                                       . 2 tests run

```

LINE-BY-LINE DIFF of Expected vs Actual
---------------------------------------
No differences found

VALGRIND REPORT
---------------
The program is run on under valgrind as
  stdbuf -i 0 -o 0 -e 0 valgrind --error-exitcode=13 --leak-check=full --show-leak-kinds=all --track-origins=yes ./test_mazesolve_funcs rcqueue_print1
which may be pasted onto a command line to run it.

```
==15381== Memcheck, a memory error detector
==15381== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==15381== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==15381== Command: ./test_mazesolve_funcs rcqueue_print1
==15381== 
==15381== 
==15381== HEAP SUMMARY:
==15381==     in use at exit: 0 bytes in 0 blocks
==15381==   total heap usage: 6 allocs, 6 frees, 112 bytes allocated
==15381== 
==15381== All heap blocks were freed -- no leaks are possible
==15381== 
==15381== For lists of detected and suppressed errors, rerun with: -s
==15381== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

SUMMARY
-------
Test Passed
