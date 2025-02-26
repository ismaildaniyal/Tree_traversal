(TEST 10) rcqueue_print2 : ok
=============================

COMMENTS
--------


PROGRAM: ./test_mazesolve_funcs rcqueue_print2
----------------------------------------------
To run this individual test in GDB use the command:
  gdb --args ./test_mazesolve_funcs rcqueue_print2
but any input to the program must be typed within the debugger

FAILURE MESSAGES
----------------
None

SIDE-BY-SIDE DIFF of Expected vs Actual
---------------------------------------
. lines match; | lines differ; < expected line missing; > extra line in actual

```sdiff
===EXPECT===                                                             ===ACTUAL===
IF_TEST("rcqueue_print2") {                                            . IF_TEST("rcqueue_print2") {
    // Add more coordinates to the queue and print it to show that the .     // Add more coordinates to the queue and print it to show that the
    // output is displayed correctly.                                  .     // output is displayed correctly.
    rcqueue_t *queue = rcqueue_allocate();                             .     rcqueue_t *queue = rcqueue_allocate();
    for(int i=1; i<=15; i++){                                          .     for(int i=1; i<=15; i++){
      rcqueue_add_rear(queue,i,i*2+1);                                 .       rcqueue_add_rear(queue,i,i*2+1);
    }                                                                  .     }
    rcqueue_print(queue);                                              .     rcqueue_print(queue);
    rcqueue_free(queue);                                               .     rcqueue_free(queue);
}                                                                      . }
---OUTPUT---                                                           . ---OUTPUT---
queue count: 15                                                        . queue count: 15
NN ROW COL                                                             . NN ROW COL
 0   1   3                                                             .  0   1   3
 1   2   5                                                             .  1   2   5
 2   3   7                                                             .  2   3   7
 3   4   9                                                             .  3   4   9
 4   5  11                                                             .  4   5  11
 5   6  13                                                             .  5   6  13
 6   7  15                                                             .  6   7  15
 7   8  17                                                             .  7   8  17
 8   9  19                                                             .  8   9  19
 9  10  21                                                             .  9  10  21
10  11  23                                                             . 10  11  23
11  12  25                                                             . 11  12  25
12  13  27                                                             . 12  13  27
13  14  29                                                             . 13  14  29
14  15  31                                                             . 14  15  31

```

LINE-BY-LINE DIFF of Expected vs Actual
---------------------------------------
No differences found

VALGRIND REPORT
---------------
The program is run on under valgrind as
  stdbuf -i 0 -o 0 -e 0 valgrind --error-exitcode=13 --leak-check=full --show-leak-kinds=all --track-origins=yes ./test_mazesolve_funcs rcqueue_print2
which may be pasted onto a command line to run it.

```
==15405== Memcheck, a memory error detector
==15405== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==15405== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==15405== Command: ./test_mazesolve_funcs rcqueue_print2
==15405== 
==15405== 
==15405== HEAP SUMMARY:
==15405==     in use at exit: 0 bytes in 0 blocks
==15405==   total heap usage: 16 allocs, 16 frees, 264 bytes allocated
==15405== 
==15405== All heap blocks were freed -- no leaks are possible
==15405== 
==15405== For lists of detected and suppressed errors, rerun with: -s
==15405== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

SUMMARY
-------
Test Passed
