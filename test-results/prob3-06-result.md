(TEST 6) maze_bfs_step2 : ok
============================

COMMENTS
--------


PROGRAM: ./test_mazesolve_funcs maze_bfs_step2
----------------------------------------------
To run this individual test in GDB use the command:
  gdb --args ./test_mazesolve_funcs maze_bfs_step2
but any input to the program must be typed within the debugger

FAILURE MESSAGES
----------------
None

SIDE-BY-SIDE DIFF of Expected vs Actual
---------------------------------------
. lines match; | lines differ; < expected line missing; > extra line in actual

```sdiff
===EXPECT===                                                             ===ACTUAL===
IF_TEST("maze_bfs_step2") {                                            . IF_TEST("maze_bfs_step2") {
    // Sets up a BFS that has proceeded a few steps using only stack   .     // Sets up a BFS that has proceeded a few steps using only stack
    // data and goes one additional step. Ensures that two neighbors   .     // data and goes one additional step. Ensures that two neighbors
    // are added for the processed node. This test relies on a         .     // are added for the processed node. This test relies on a
    // combination of stack set up in the test and heap data allocated .     // combination of stack set up in the test and heap data allocated
    // by user functions so may yield some strange effects if          .     // by user functions so may yield some strange effects if
    // allocation is done improperly in functions.                     .     // allocation is done improperly in functions.
    tile_t rows[5][3] = {                                              .     tile_t rows[5][3] = {
      { {.type=WALL},{.type=WALL}, {.type=START} },// 0                .       { {.type=WALL},{.type=WALL}, {.type=START} },// 0
      { {.type=OPEN},{.type=OPEN}, {.type=OPEN}  },// 1                .       { {.type=OPEN},{.type=OPEN}, {.type=OPEN}  },// 1
      { {.type=END}, {.type=OPEN}, {.type=WALL}  },// 2                .       { {.type=END}, {.type=OPEN}, {.type=WALL}  },// 2
      { {.type=WALL},{.type=OPEN}, {.type=WALL}  },// 3                .       { {.type=WALL},{.type=OPEN}, {.type=WALL}  },// 3
      { {.type=OPEN},{.type=OPEN}, {.type=OPEN}  },// 4                .       { {.type=OPEN},{.type=OPEN}, {.type=OPEN}  },// 4
      //     0            1             2                              .       //     0            1             2
    };                                                                 .     };
    tile_t *tiles[5] =                                                 .     tile_t *tiles[5] =
      {rows[0],rows[1],rows[2],rows[3],rows[4]};                       .       {rows[0],rows[1],rows[2],rows[3],rows[4]};
    maze_t maze = {.rows=5, .cols=3, .tiles=tiles};                    .     maze_t maze = {.rows=5, .cols=3, .tiles=tiles};
    for(int i=0; i<5; i++){                                            .     for(int i=0; i<5; i++){
      for(int j=0; j<3; j++){                                          .       for(int j=0; j<3; j++){
        maze.tiles[i][j].state = NOTFOUND;                             .         maze.tiles[i][j].state = NOTFOUND;
      }                                                                .       }
    }                                                                  .     }
    tile_t *tile;                                                      .     tile_t *tile;
    direction_t path02[] = {};                                         .     direction_t path02[] = {};
    tile = &maze.tiles[0][2];                                          .     tile = &maze.tiles[0][2];
    tile->path = path02;                                               .     tile->path = path02;
    tile->path_len = 0;                                                .     tile->path_len = 0;
    tile->state = FOUND;                                               .     tile->state = FOUND;
    direction_t path12[] = {SOUTH};                                    .     direction_t path12[] = {SOUTH};
    tile = &maze.tiles[1][2];                                          .     tile = &maze.tiles[1][2];
    tile->path = path12;                                               .     tile->path = path12;
    tile->path_len = 1;                                                .     tile->path_len = 1;
    tile->state = FOUND;                                               .     tile->state = FOUND;
    direction_t path11[] = {SOUTH,WEST};                               .     direction_t path11[] = {SOUTH,WEST};
    tile = &maze.tiles[1][1];                                          .     tile = &maze.tiles[1][1];
    tile->path = path11;                                               .     tile->path = path11;
    tile->path_len = 2;                                                .     tile->path_len = 2;
    tile->state = FOUND;                                               .     tile->state = FOUND;
    maze.queue = rcqueue_allocate();                                   .     maze.queue = rcqueue_allocate();
    rcqueue_add_rear(maze.queue,1,1);                                  .     rcqueue_add_rear(maze.queue,1,1);
    printf("Maze BEFORE BFS step\n");                                  .     printf("Maze BEFORE BFS step\n");
    LOG_LEVEL = LOG_ALL;                                               .     LOG_LEVEL = LOG_ALL;
    maze_print_state(&maze);                                           .     maze_print_state(&maze);
    int ret = maze_bfs_step(&maze);                                    .     int ret = maze_bfs_step(&maze);
    printf("step ret: %d\n",ret);                                      .     printf("step ret: %d\n",ret);
    printf("Maze AFTER BFS step\n");                                   .     printf("Maze AFTER BFS step\n");
    maze_print_state(&maze);                                           .     maze_print_state(&maze);
    free(maze.tiles[1][0].path);                                       .     free(maze.tiles[1][0].path);
    free(maze.tiles[2][1].path);                                       .     free(maze.tiles[2][1].path);
    rcqueue_free(maze.queue);                                          .     rcqueue_free(maze.queue);
}                                                                      . }
---OUTPUT---                                                           . ---OUTPUT---
Maze BEFORE BFS step                                                   . Maze BEFORE BFS step
##0:  0                                                                . ##0:  0
 21:  1                                                                .  21:  1
E #:  2                                                                . E #:  2
# #:  3                                                                . # #:  3
   :  4                                                                .    :  4
012                                                                    . 012
0                                                                      . 0  
queue count: 1                                                         . queue count: 1
NN ROW COL                                                             . NN ROW COL
 0   1   1                                                             .  0   1   1
LOG: processing neighbors of (1,1)                                     . LOG: processing neighbors of (1,1)
LOG: Skipping BLOCKED tile at (0,1)                                    . LOG: Skipping BLOCKED tile at (0,1)
LOG: Found tile at (2,1) with len 3 path: SWS                          . LOG: Found tile at (2,1) with len 3 path: SWS
LOG: Found tile at (1,0) with len 3 path: SWW                          . LOG: Found tile at (1,0) with len 3 path: SWW
LOG: Skipping FOUND tile at (1,2)                                      . LOG: Skipping FOUND tile at (1,2)
LOG: maze state after BFS step                                         . LOG: maze state after BFS step
##0:  0                                                                . ##0:  0
321:  1                                                                . 321:  1
E3#:  2                                                                . E3#:  2
# #:  3                                                                . # #:  3
   :  4                                                                .    :  4
012                                                                    . 012
0                                                                      . 0  
queue count: 2                                                         . queue count: 2
NN ROW COL                                                             . NN ROW COL
 0   2   1                                                             .  0   2   1
 1   1   0                                                             .  1   1   0
step ret: 1                                                            . step ret: 1
Maze AFTER BFS step                                                    . Maze AFTER BFS step
##0:  0                                                                . ##0:  0
321:  1                                                                . 321:  1
E3#:  2                                                                . E3#:  2
# #:  3                                                                . # #:  3
   :  4                                                                .    :  4
012                                                                    . 012
0                                                                      . 0  
queue count: 2                                                         . queue count: 2
NN ROW COL                                                             . NN ROW COL
 0   2   1                                                             .  0   2   1
 1   1   0                                                             .  1   1   0

```

LINE-BY-LINE DIFF of Expected vs Actual
---------------------------------------
No differences found

VALGRIND REPORT
---------------
The program is run on under valgrind as
  stdbuf -i 0 -o 0 -e 0 valgrind --error-exitcode=13 --leak-check=full --show-leak-kinds=all --track-origins=yes ./test_mazesolve_funcs maze_bfs_step2
which may be pasted onto a command line to run it.

```
==15523== Memcheck, a memory error detector
==15523== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==15523== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==15523== Command: ./test_mazesolve_funcs maze_bfs_step2
==15523== 
==15523== 
==15523== HEAP SUMMARY:
==15523==     in use at exit: 0 bytes in 0 blocks
==15523==   total heap usage: 6 allocs, 6 frees, 96 bytes allocated
==15523== 
==15523== All heap blocks were freed -- no leaks are possible
==15523== 
==15523== For lists of detected and suppressed errors, rerun with: -s
==15523== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

SUMMARY
-------
Test Passed
