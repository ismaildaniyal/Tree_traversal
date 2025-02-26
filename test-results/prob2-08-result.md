(TEST 8) maze_tile_blocked2 : ok
================================

COMMENTS
--------


PROGRAM: ./test_mazesolve_funcs maze_tile_blocked2
--------------------------------------------------
To run this individual test in GDB use the command:
  gdb --args ./test_mazesolve_funcs maze_tile_blocked2
but any input to the program must be typed within the debugger

FAILURE MESSAGES
----------------
None

SIDE-BY-SIDE DIFF of Expected vs Actual
---------------------------------------
. lines match; | lines differ; < expected line missing; > extra line in actual

```sdiff
===EXPECT===                                                           ===ACTUAL===
IF_TEST("maze_tile_blocked2") {                                      . IF_TEST("maze_tile_blocked2") {
    // Checks correct blocked tile checking for in bounds cases some .     // Checks correct blocked tile checking for in bounds cases some
    // of which are walls and Blocked and others of which are OPEN,  .     // of which are walls and Blocked and others of which are OPEN,
    // START, END, and ONPATH tiles which are not Blocked.           .     // START, END, and ONPATH tiles which are not Blocked.
    tile_t rows[5][3] = {                                            .     tile_t rows[5][3] = {
      { {.type=WALL},{.type=WALL},{.type=START} },// 0               .       { {.type=WALL},{.type=WALL},{.type=START} },// 0
      { {.type=OPEN},{.type=OPEN},{.type=ONPATH}},// 1               .       { {.type=OPEN},{.type=OPEN},{.type=ONPATH}},// 1
      { {.type=END}, {.type=OPEN},{.type=WALL}  },// 2               .       { {.type=END}, {.type=OPEN},{.type=WALL}  },// 2
      { {.type=WALL},{.type=OPEN},{.type=WALL}  },// 3               .       { {.type=WALL},{.type=OPEN},{.type=WALL}  },// 3
      { {.type=OPEN},{.type=OPEN},{.type=OPEN}  },// 4               .       { {.type=OPEN},{.type=OPEN},{.type=OPEN}  },// 4
      //     0            1             2                            .       //     0            1             2
    };                                                               .     };
    tile_t *tiles[5] =                                               .     tile_t *tiles[5] =
      {rows[0],rows[1],rows[2],rows[3],rows[4]};                     .       {rows[0],rows[1],rows[2],rows[3],rows[4]};
    maze_t maze = {.rows=5, .cols=3, .tiles=tiles};                  .     maze_t maze = {.rows=5, .cols=3, .tiles=tiles};
    int r,c,ret;                                                     .     int r,c,ret;
    r=0; c=0; ret = maze_tile_blocked(&maze,r,c);                    .     r=0; c=0; ret = maze_tile_blocked(&maze,r,c);
    printf("(%d,%d) blocked? %d\n",r,c,ret);                         .     printf("(%d,%d) blocked? %d\n",r,c,ret);
    r=0; c=2; ret = maze_tile_blocked(&maze,r,c);                    .     r=0; c=2; ret = maze_tile_blocked(&maze,r,c);
    printf("(%d,%d) blocked? %d\n",r,c,ret);                         .     printf("(%d,%d) blocked? %d\n",r,c,ret);
    r=1; c=1; ret = maze_tile_blocked(&maze,r,c);                    .     r=1; c=1; ret = maze_tile_blocked(&maze,r,c);
    printf("(%d,%d) blocked? %d\n",r,c,ret);                         .     printf("(%d,%d) blocked? %d\n",r,c,ret);
    r=2; c=0; ret = maze_tile_blocked(&maze,r,c);                    .     r=2; c=0; ret = maze_tile_blocked(&maze,r,c);
    printf("(%d,%d) blocked? %d\n",r,c,ret);                         .     printf("(%d,%d) blocked? %d\n",r,c,ret);
    r=4; c=1; ret = maze_tile_blocked(&maze,r,c);                    .     r=4; c=1; ret = maze_tile_blocked(&maze,r,c);
    printf("(%d,%d) blocked? %d\n",r,c,ret);                         .     printf("(%d,%d) blocked? %d\n",r,c,ret);
    r=3; c=2; ret = maze_tile_blocked(&maze,r,c);                    .     r=3; c=2; ret = maze_tile_blocked(&maze,r,c);
    printf("(%d,%d) blocked? %d\n",r,c,ret);                         .     printf("(%d,%d) blocked? %d\n",r,c,ret);
    r=4; c=2; ret = maze_tile_blocked(&maze,r,c);                    .     r=4; c=2; ret = maze_tile_blocked(&maze,r,c);
    printf("(%d,%d) blocked? %d\n",r,c,ret);                         .     printf("(%d,%d) blocked? %d\n",r,c,ret);
    r=1; c=2; ret = maze_tile_blocked(&maze,r,c);                    .     r=1; c=2; ret = maze_tile_blocked(&maze,r,c);
    printf("(%d,%d) blocked? %d\n",r,c,ret);                         .     printf("(%d,%d) blocked? %d\n",r,c,ret);
}                                                                    . }
---OUTPUT---                                                         . ---OUTPUT---
(0,0) blocked? 1                                                     . (0,0) blocked? 1
(0,2) blocked? 0                                                     . (0,2) blocked? 0
(1,1) blocked? 0                                                     . (1,1) blocked? 0
(2,0) blocked? 0                                                     . (2,0) blocked? 0
(4,1) blocked? 0                                                     . (4,1) blocked? 0
(3,2) blocked? 1                                                     . (3,2) blocked? 1
(4,2) blocked? 0                                                     . (4,2) blocked? 0
(1,2) blocked? 0                                                     . (1,2) blocked? 0

```

LINE-BY-LINE DIFF of Expected vs Actual
---------------------------------------
No differences found

VALGRIND REPORT
---------------
The program is run on under valgrind as
  stdbuf -i 0 -o 0 -e 0 valgrind --error-exitcode=13 --leak-check=full --show-leak-kinds=all --track-origins=yes ./test_mazesolve_funcs maze_tile_blocked2
which may be pasted onto a command line to run it.

```
==15443== Memcheck, a memory error detector
==15443== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==15443== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==15443== Command: ./test_mazesolve_funcs maze_tile_blocked2
==15443== 
==15443== 
==15443== HEAP SUMMARY:
==15443==     in use at exit: 0 bytes in 0 blocks
==15443==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==15443== 
==15443== All heap blocks were freed -- no leaks are possible
==15443== 
==15443== For lists of detected and suppressed errors, rerun with: -s
==15443== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

SUMMARY
-------
Test Passed
