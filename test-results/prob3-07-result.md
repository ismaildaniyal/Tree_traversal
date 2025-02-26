(TEST 7) maze_bfs_step3 : ok
============================

COMMENTS
--------


PROGRAM: ./test_mazesolve_funcs maze_bfs_step3
----------------------------------------------
To run this individual test in GDB use the command:
  gdb --args ./test_mazesolve_funcs maze_bfs_step3
but any input to the program must be typed within the debugger

FAILURE MESSAGES
----------------
None

SIDE-BY-SIDE DIFF of Expected vs Actual
---------------------------------------
. lines match; | lines differ; < expected line missing; > extra line in actual

```sdiff
===EXPECT===                                                         ===ACTUAL===
IF_TEST("maze_bfs_step3") {                                        . IF_TEST("maze_bfs_step3") {
    // Perform 3 BFS step calls starting from the Start tile. This .     // Perform 3 BFS step calls starting from the Start tile. This
    // will add 3 initial neighbors and then process each in turn  .     // will add 3 initial neighbors and then process each in turn
    // adding additional tiles in the second wave. There is some   .     // adding additional tiles in the second wave. There is some
    // redundancy with neighbors so this test also checks that the .     // redundancy with neighbors so this test also checks that the
    // FOUND field of tiles is set properly and respected.         .     // FOUND field of tiles is set properly and respected.
    char *maze_str =                                               .     char *maze_str =
      "#########\n"                                                .       "#########\n"
      "#       #\n"                                                .       "#       #\n"
      "# # S  ##\n"                                                .       "# # S  ##\n"
      "#  # ##E#\n"                                                .       "#  # ##E#\n"
      "#       #\n"                                                .       "#       #\n"
      "#########\n";                                               .       "#########\n";
    maze_t *maze = maze_from_string(maze_str);                     .     maze_t *maze = maze_from_string(maze_str);
    maze_bfs_init(maze);                                           .     maze_bfs_init(maze);
    printf("Maze BEFORE BFS step\n");                              .     printf("Maze BEFORE BFS step\n");
    LOG_LEVEL = LOG_ALL;                                           .     LOG_LEVEL = LOG_ALL;
    maze_print_state(maze);                                        .     maze_print_state(maze);
    int ret;                                                       .     int ret;
    ret = maze_bfs_step(maze);                                     .     ret = maze_bfs_step(maze);
    printf("step ret: %d\n",ret);                                  .     printf("step ret: %d\n",ret);
    printf("Maze AFTER BFS step 1\n");                             .     printf("Maze AFTER BFS step 1\n");
    maze_print_state(maze);                                        .     maze_print_state(maze);
    ret = maze_bfs_step(maze);                                     .     ret = maze_bfs_step(maze);
    printf("step ret: %d\n",ret);                                  .     printf("step ret: %d\n",ret);
    printf("Maze AFTER BFS step 2\n");                             .     printf("Maze AFTER BFS step 2\n");
    maze_print_state(maze);                                        .     maze_print_state(maze);
    ret = maze_bfs_step(maze);                                     .     ret = maze_bfs_step(maze);
    printf("step ret: %d\n",ret);                                  .     printf("step ret: %d\n",ret);
    printf("Maze AFTER BFS step 3\n");                             .     printf("Maze AFTER BFS step 3\n");
    maze_print_state(maze);                                        .     maze_print_state(maze);
    maze_free(maze);                                               .     maze_free(maze);
}                                                                  . }
---OUTPUT---                                                       . ---OUTPUT---
Maze BEFORE BFS step                                               . Maze BEFORE BFS step
#########:  0                                                      . #########:  0
#       #:  1                                                      . #       #:  1
# # 0  ##:  2                                                      . # # 0  ##:  2
#  # ##E#:  3                                                      . #  # ##E#:  3
#       #:  4                                                      . #       #:  4
#########:  5                                                      . #########:  5
012345678                                                          . 012345678
0                                                                  . 0        
queue count: 1                                                     . queue count: 1
NN ROW COL                                                         . NN ROW COL
 0   2   4                                                         .  0   2   4
LOG: processing neighbors of (2,4)                                 . LOG: processing neighbors of (2,4)
LOG: Found tile at (1,4) with len 1 path: N                        . LOG: Found tile at (1,4) with len 1 path: N
LOG: Found tile at (3,4) with len 1 path: S                        . LOG: Found tile at (3,4) with len 1 path: S
LOG: Found tile at (2,3) with len 1 path: W                        . LOG: Found tile at (2,3) with len 1 path: W
LOG: Found tile at (2,5) with len 1 path: E                        . LOG: Found tile at (2,5) with len 1 path: E
LOG: maze state after BFS step                                     . LOG: maze state after BFS step
#########:  0                                                      . #########:  0
#   1   #:  1                                                      . #   1   #:  1
# #101 ##:  2                                                      . # #101 ##:  2
#  #1##E#:  3                                                      . #  #1##E#:  3
#       #:  4                                                      . #       #:  4
#########:  5                                                      . #########:  5
012345678                                                          . 012345678
0                                                                  . 0        
queue count: 4                                                     . queue count: 4
NN ROW COL                                                         . NN ROW COL
 0   1   4                                                         .  0   1   4
 1   3   4                                                         .  1   3   4
 2   2   3                                                         .  2   2   3
 3   2   5                                                         .  3   2   5
step ret: 1                                                        . step ret: 1
Maze AFTER BFS step 1                                              . Maze AFTER BFS step 1
#########:  0                                                      . #########:  0
#   1   #:  1                                                      . #   1   #:  1
# #101 ##:  2                                                      . # #101 ##:  2
#  #1##E#:  3                                                      . #  #1##E#:  3
#       #:  4                                                      . #       #:  4
#########:  5                                                      . #########:  5
012345678                                                          . 012345678
0                                                                  . 0        
queue count: 4                                                     . queue count: 4
NN ROW COL                                                         . NN ROW COL
 0   1   4                                                         .  0   1   4
 1   3   4                                                         .  1   3   4
 2   2   3                                                         .  2   2   3
 3   2   5                                                         .  3   2   5
LOG: processing neighbors of (1,4)                                 . LOG: processing neighbors of (1,4)
LOG: Skipping BLOCKED tile at (0,4)                                . LOG: Skipping BLOCKED tile at (0,4)
LOG: Skipping FOUND tile at (2,4)                                  . LOG: Skipping FOUND tile at (2,4)
LOG: Found tile at (1,3) with len 2 path: NW                       . LOG: Found tile at (1,3) with len 2 path: NW
LOG: Found tile at (1,5) with len 2 path: NE                       . LOG: Found tile at (1,5) with len 2 path: NE
LOG: maze state after BFS step                                     . LOG: maze state after BFS step
#########:  0                                                      . #########:  0
#  212  #:  1                                                      . #  212  #:  1
# #101 ##:  2                                                      . # #101 ##:  2
#  #1##E#:  3                                                      . #  #1##E#:  3
#       #:  4                                                      . #       #:  4
#########:  5                                                      . #########:  5
012345678                                                          . 012345678
0                                                                  . 0        
queue count: 5                                                     . queue count: 5
NN ROW COL                                                         . NN ROW COL
 0   3   4                                                         .  0   3   4
 1   2   3                                                         .  1   2   3
 2   2   5                                                         .  2   2   5
 3   1   3                                                         .  3   1   3
 4   1   5                                                         .  4   1   5
step ret: 1                                                        . step ret: 1
Maze AFTER BFS step 2                                              . Maze AFTER BFS step 2
#########:  0                                                      . #########:  0
#  212  #:  1                                                      . #  212  #:  1
# #101 ##:  2                                                      . # #101 ##:  2
#  #1##E#:  3                                                      . #  #1##E#:  3
#       #:  4                                                      . #       #:  4
#########:  5                                                      . #########:  5
012345678                                                          . 012345678
0                                                                  . 0        
queue count: 5                                                     . queue count: 5
NN ROW COL                                                         . NN ROW COL
 0   3   4                                                         .  0   3   4
 1   2   3                                                         .  1   2   3
 2   2   5                                                         .  2   2   5
 3   1   3                                                         .  3   1   3
 4   1   5                                                         .  4   1   5
LOG: processing neighbors of (3,4)                                 . LOG: processing neighbors of (3,4)
LOG: Skipping FOUND tile at (2,4)                                  . LOG: Skipping FOUND tile at (2,4)
LOG: Found tile at (4,4) with len 2 path: SS                       . LOG: Found tile at (4,4) with len 2 path: SS
LOG: Skipping BLOCKED tile at (3,3)                                . LOG: Skipping BLOCKED tile at (3,3)
LOG: Skipping BLOCKED tile at (3,5)                                . LOG: Skipping BLOCKED tile at (3,5)
LOG: maze state after BFS step                                     . LOG: maze state after BFS step
#########:  0                                                      . #########:  0
#  212  #:  1                                                      . #  212  #:  1
# #101 ##:  2                                                      . # #101 ##:  2
#  #1##E#:  3                                                      . #  #1##E#:  3
#   2   #:  4                                                      . #   2   #:  4
#########:  5                                                      . #########:  5
012345678                                                          . 012345678
0                                                                  . 0        
queue count: 5                                                     . queue count: 5
NN ROW COL                                                         . NN ROW COL
 0   2   3                                                         .  0   2   3
 1   2   5                                                         .  1   2   5
 2   1   3                                                         .  2   1   3
 3   1   5                                                         .  3   1   5
 4   4   4                                                         .  4   4   4
step ret: 1                                                        . step ret: 1
Maze AFTER BFS step 3                                              . Maze AFTER BFS step 3
#########:  0                                                      . #########:  0
#  212  #:  1                                                      . #  212  #:  1
# #101 ##:  2                                                      . # #101 ##:  2
#  #1##E#:  3                                                      . #  #1##E#:  3
#   2   #:  4                                                      . #   2   #:  4
#########:  5                                                      . #########:  5
012345678                                                          . 012345678
0                                                                  . 0        
queue count: 5                                                     . queue count: 5
NN ROW COL                                                         . NN ROW COL
 0   2   3                                                         .  0   2   3
 1   2   5                                                         .  1   2   5
 2   1   3                                                         .  2   1   3
 3   1   5                                                         .  3   1   5
 4   4   4                                                         .  4   4   4

```

LINE-BY-LINE DIFF of Expected vs Actual
---------------------------------------
No differences found

VALGRIND REPORT
---------------
The program is run on under valgrind as
  stdbuf -i 0 -o 0 -e 0 valgrind --error-exitcode=13 --leak-check=full --show-leak-kinds=all --track-origins=yes ./test_mazesolve_funcs maze_bfs_step3
which may be pasted onto a command line to run it.

```
==15524== Memcheck, a memory error detector
==15524== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==15524== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==15524== Command: ./test_mazesolve_funcs maze_bfs_step3
==15524== 
==15524== 
==15524== HEAP SUMMARY:
==15524==     in use at exit: 0 bytes in 0 blocks
==15524==   total heap usage: 25 allocs, 25 frees, 1,580 bytes allocated
==15524== 
==15524== All heap blocks were freed -- no leaks are possible
==15524== 
==15524== For lists of detected and suppressed errors, rerun with: -s
==15524== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

SUMMARY
-------
Test Passed
