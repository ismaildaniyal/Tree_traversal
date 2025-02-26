(TEST 7) maze_tile_blocked1 : ok
================================

COMMENTS
--------


PROGRAM: ./test_mazesolve_funcs maze_tile_blocked1
--------------------------------------------------
To run this individual test in GDB use the command:
  gdb --args ./test_mazesolve_funcs maze_tile_blocked1
but any input to the program must be typed within the debugger

FAILURE MESSAGES
----------------
None

SIDE-BY-SIDE DIFF of Expected vs Actual
---------------------------------------
. lines match; | lines differ; < expected line missing; > extra line in actual

```sdiff
===EXPECT===                                         ===ACTUAL===
IF_TEST("maze_tile_blocked1") {                    . IF_TEST("maze_tile_blocked1") {
    maze_t maze = {.rows=3, .cols=5, .tiles=NULL}; .     maze_t maze = {.rows=3, .cols=5, .tiles=NULL};
    int r,c,ret;                                   .     int r,c,ret;
    r=-1; c=2; ret = maze_tile_blocked(&maze,r,c); .     r=-1; c=2; ret = maze_tile_blocked(&maze,r,c);
    printf("(%d,%d) blocked? %d\n",r,c,ret);       .     printf("(%d,%d) blocked? %d\n",r,c,ret);
    r=3; c=2; ret = maze_tile_blocked(&maze,r,c);  .     r=3; c=2; ret = maze_tile_blocked(&maze,r,c);
    printf("(%d,%d) blocked? %d\n",r,c,ret);       .     printf("(%d,%d) blocked? %d\n",r,c,ret);
    r=1; c=-1; ret = maze_tile_blocked(&maze,r,c); .     r=1; c=-1; ret = maze_tile_blocked(&maze,r,c);
    printf("(%d,%d) blocked? %d\n",r,c,ret);       .     printf("(%d,%d) blocked? %d\n",r,c,ret);
    r=1; c=6; ret = maze_tile_blocked(&maze,r,c);  .     r=1; c=6; ret = maze_tile_blocked(&maze,r,c);
    printf("(%d,%d) blocked? %d\n",r,c,ret);       .     printf("(%d,%d) blocked? %d\n",r,c,ret);
}                                                  . }
---OUTPUT---                                       . ---OUTPUT---
(-1,2) blocked? 1                                  . (-1,2) blocked? 1
(3,2) blocked? 1                                   . (3,2) blocked? 1
(1,-1) blocked? 1                                  . (1,-1) blocked? 1
(1,6) blocked? 1                                   . (1,6) blocked? 1

```

LINE-BY-LINE DIFF of Expected vs Actual
---------------------------------------
No differences found

VALGRIND REPORT
---------------
The program is run on under valgrind as
  stdbuf -i 0 -o 0 -e 0 valgrind --error-exitcode=13 --leak-check=full --show-leak-kinds=all --track-origins=yes ./test_mazesolve_funcs maze_tile_blocked1
which may be pasted onto a command line to run it.

```
==15441== Memcheck, a memory error detector
==15441== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==15441== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==15441== Command: ./test_mazesolve_funcs maze_tile_blocked1
==15441== 
==15441== 
==15441== HEAP SUMMARY:
==15441==     in use at exit: 0 bytes in 0 blocks
==15441==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==15441== 
==15441== All heap blocks were freed -- no leaks are possible
==15441== 
==15441== For lists of detected and suppressed errors, rerun with: -s
==15441== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

SUMMARY
-------
Test Passed
