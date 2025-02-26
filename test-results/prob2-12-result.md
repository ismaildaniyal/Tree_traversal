(TEST 12) maze_print_state1 : ok
================================

COMMENTS
--------


PROGRAM: ./test_mazesolve_funcs maze_print_state1
-------------------------------------------------
To run this individual test in GDB use the command:
  gdb --args ./test_mazesolve_funcs maze_print_state1
but any input to the program must be typed within the debugger

FAILURE MESSAGES
----------------
None

SIDE-BY-SIDE DIFF of Expected vs Actual
---------------------------------------
. lines match; | lines differ; < expected line missing; > extra line in actual

```sdiff
===EXPECT===                                                                           ===ACTUAL===
IF_TEST("maze_print_state1") {                                                       . IF_TEST("maze_print_state1") {
    // Print the state of searching the following 3x2 maze (vertical                 .     // Print the state of searching the following 3x2 maze (vertical
    // bars | show the boundaries).                                                  .     // bars | show the boundaries).
    //                                                                               .     //
    // |S | 0                                                                        .     // |S | 0
    // |# | 1                                                                        .     // |# | 1
    // |E | 2                                                                        .     // |E | 2
    //  01                                                                           .     //  01
    //                                                                               .     //
    // In the test case, the maze is set up to show progress to tile                 .     // In the test case, the maze is set up to show progress to tile
    // (1,1) with paths determined for (0,0), (0,1), and (1,1) and                   .     // (1,1) with paths determined for (0,0), (0,1), and (1,1) and
    // (1,1) is in the search queue.                                                 .     // (1,1) is in the search queue.
    direction_t path00[] = {};                                                       .     direction_t path00[] = {};
    direction_t path01[] = {EAST};                                                   .     direction_t path01[] = {EAST};
    direction_t path11[] = {EAST,SOUTH};                                             .     direction_t path11[] = {EAST,SOUTH};
    tile_t rows[3][2] = {                                                            .     tile_t rows[3][2] = {
      { {.type=START, .state=FOUND,    .path_len= 0, .path=path00 }, // tiles[0][0]  .       { {.type=START, .state=FOUND,    .path_len= 0, .path=path00 }, // tiles[0][0] 
        {.type=ONPATH,.state=FOUND,    .path_len= 1, .path=path01 }, // tiles[0][1]  .         {.type=ONPATH,.state=FOUND,    .path_len= 1, .path=path01 }, // tiles[0][1] 
      },                                                                             .       },
      { {.type=WALL,  .state=NOTFOUND, .path_len=-1, .path=NULL },   // tiles[1][0]  .       { {.type=WALL,  .state=NOTFOUND, .path_len=-1, .path=NULL },   // tiles[1][0] 
        {.type=OPEN,  .state=FOUND,    .path_len= 2, .path=path11 }, // tiles[1][1]  .         {.type=OPEN,  .state=FOUND,    .path_len= 2, .path=path11 }, // tiles[1][1] 
      },                                                                             .       },
      { {.type=END,   .state=NOTFOUND, .path_len=-1, .path=NULL },   // tiles[2][0]  .       { {.type=END,   .state=NOTFOUND, .path_len=-1, .path=NULL },   // tiles[2][0] 
        {.type=OPEN,  .state=NOTFOUND, .path_len=-1, .path=NULL },   // tiles[2][1]  .         {.type=OPEN,  .state=NOTFOUND, .path_len=-1, .path=NULL },   // tiles[2][1] 
      },                                                                             .       },
    };                                                                               .     };
    tile_t *tiles[] = {rows[0], rows[1], rows[2] };                                  .     tile_t *tiles[] = {rows[0], rows[1], rows[2] };
    rcnode_t node = {.row=1, .col=1, .next=NULL };                                   .     rcnode_t node = {.row=1, .col=1, .next=NULL };
    rcqueue_t queue = {.count=1, .front=&node, .rear=&node};                         .     rcqueue_t queue = {.count=1, .front=&node, .rear=&node};
    maze_t maze = {                                                                  .     maze_t maze = {
      .rows=3, .cols=2, .tiles = tiles, .queue=&queue,                               .       .rows=3, .cols=2, .tiles = tiles, .queue=&queue,
      .start_row=0, .start_col=0, .end_row=2, .end_col=0,                            .       .start_row=0, .start_col=0, .end_row=2, .end_col=0,
    };                                                                               .     };
    maze_print_state(&maze);                                                         .     maze_print_state(&maze);
}                                                                                    . }
---OUTPUT---                                                                         . ---OUTPUT---
01:  0                                                                               . 01:  0
#2:  1                                                                               . #2:  1
E :  2                                                                               . E :  2
01                                                                                   . 01
0                                                                                    . 0 
queue count: 1                                                                       . queue count: 1
NN ROW COL                                                                           . NN ROW COL
 0   1   1                                                                           .  0   1   1

```

LINE-BY-LINE DIFF of Expected vs Actual
---------------------------------------
No differences found

VALGRIND REPORT
---------------
The program is run on under valgrind as
  stdbuf -i 0 -o 0 -e 0 valgrind --error-exitcode=13 --leak-check=full --show-leak-kinds=all --track-origins=yes ./test_mazesolve_funcs maze_print_state1
which may be pasted onto a command line to run it.

```
==15470== Memcheck, a memory error detector
==15470== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==15470== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==15470== Command: ./test_mazesolve_funcs maze_print_state1
==15470== 
==15470== 
==15470== HEAP SUMMARY:
==15470==     in use at exit: 0 bytes in 0 blocks
==15470==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==15470== 
==15470== All heap blocks were freed -- no leaks are possible
==15470== 
==15470== For lists of detected and suppressed errors, rerun with: -s
==15470== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

SUMMARY
-------
Test Passed
