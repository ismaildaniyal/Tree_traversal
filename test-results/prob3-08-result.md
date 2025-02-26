(TEST 8) maze_bfs_iterate1 : ok
===============================

COMMENTS
--------


PROGRAM: ./test_mazesolve_funcs maze_bfs_iterate1
-------------------------------------------------
To run this individual test in GDB use the command:
  gdb --args ./test_mazesolve_funcs maze_bfs_iterate1
but any input to the program must be typed within the debugger

FAILURE MESSAGES
----------------
None

SIDE-BY-SIDE DIFF of Expected vs Actual
---------------------------------------
. lines match; | lines differ; < expected line missing; > extra line in actual

```sdiff
===EXPECT===                                                             ===ACTUAL===
IF_TEST("maze_bfs_iterate1") {                                         . IF_TEST("maze_bfs_iterate1") {
    // Checks the BFS iteration function to ensure it visits all tiles .     // Checks the BFS iteration function to ensure it visits all tiles
    // to obtain paths to each one from the start tile. A small maze   .     // to obtain paths to each one from the start tile. A small maze
    // is used which has wall tiles around the edges.                  .     // is used which has wall tiles around the edges.
    char *maze_str =                                                   .     char *maze_str =
      "#####\n"                                                        .       "#####\n"
      "# S #\n"                                                        .       "# S #\n"
      "# # #\n"                                                        .       "# # #\n"
      "# E #\n"                                                        .       "# E #\n"
      "#####\n";                                                       .       "#####\n";
    maze_t *maze = maze_from_string(maze_str);                         .     maze_t *maze = maze_from_string(maze_str);
    printf("Maze BEFORE BFS iteration\n");                             .     printf("Maze BEFORE BFS iteration\n");
    maze_print_state(maze);                                            .     maze_print_state(maze);
    LOG_LEVEL = LOG_ALL;                                               .     LOG_LEVEL = LOG_ALL;
    maze_bfs_iterate(maze);                                            .     maze_bfs_iterate(maze);
    printf("Maze AFTER BFS iteration\n");                              .     printf("Maze AFTER BFS iteration\n");
    maze_print_state(maze);                                            .     maze_print_state(maze);
    maze_free(maze);                                                   .     maze_free(maze);
}                                                                      . }
---OUTPUT---                                                           . ---OUTPUT---
Maze BEFORE BFS iteration                                              . Maze BEFORE BFS iteration
#####:  0                                                              . #####:  0
# S #:  1                                                              . # S #:  1
# # #:  2                                                              . # # #:  2
# E #:  3                                                              . # E #:  3
#####:  4                                                              . #####:  4
01234                                                                  . 01234
0                                                                      . 0    
null queue                                                             . null queue
LOG: BFS initialization complete                                       . LOG: BFS initialization complete
#####:  0                                                              . #####:  0
# 0 #:  1                                                              . # 0 #:  1
# # #:  2                                                              . # # #:  2
# E #:  3                                                              . # E #:  3
#####:  4                                                              . #####:  4
01234                                                                  . 01234
0                                                                      . 0    
queue count: 1                                                         . queue count: 1
NN ROW COL                                                             . NN ROW COL
 0   1   2                                                             .  0   1   2
LOG: BFS STEP 1                                                        . LOG: BFS STEP 1
LOG: processing neighbors of (1,2)                                     . LOG: processing neighbors of (1,2)
LOG: Skipping BLOCKED tile at (0,2)                                    . LOG: Skipping BLOCKED tile at (0,2)
LOG: Skipping BLOCKED tile at (2,2)                                    . LOG: Skipping BLOCKED tile at (2,2)
LOG: Found tile at (1,1) with len 1 path: W                            . LOG: Found tile at (1,1) with len 1 path: W
LOG: Found tile at (1,3) with len 1 path: E                            . LOG: Found tile at (1,3) with len 1 path: E
LOG: maze state after BFS step                                         . LOG: maze state after BFS step
#####:  0                                                              . #####:  0
#101#:  1                                                              . #101#:  1
# # #:  2                                                              . # # #:  2
# E #:  3                                                              . # E #:  3
#####:  4                                                              . #####:  4
01234                                                                  . 01234
0                                                                      . 0    
queue count: 2                                                         . queue count: 2
NN ROW COL                                                             . NN ROW COL
 0   1   1                                                             .  0   1   1
 1   1   3                                                             .  1   1   3
LOG: BFS STEP 2                                                        . LOG: BFS STEP 2
LOG: processing neighbors of (1,1)                                     . LOG: processing neighbors of (1,1)
LOG: Skipping BLOCKED tile at (0,1)                                    . LOG: Skipping BLOCKED tile at (0,1)
LOG: Found tile at (2,1) with len 2 path: WS                           . LOG: Found tile at (2,1) with len 2 path: WS
LOG: Skipping BLOCKED tile at (1,0)                                    . LOG: Skipping BLOCKED tile at (1,0)
LOG: Skipping FOUND tile at (1,2)                                      . LOG: Skipping FOUND tile at (1,2)
LOG: maze state after BFS step                                         . LOG: maze state after BFS step
#####:  0                                                              . #####:  0
#101#:  1                                                              . #101#:  1
#2# #:  2                                                              . #2# #:  2
# E #:  3                                                              . # E #:  3
#####:  4                                                              . #####:  4
01234                                                                  . 01234
0                                                                      . 0    
queue count: 2                                                         . queue count: 2
NN ROW COL                                                             . NN ROW COL
 0   1   3                                                             .  0   1   3
 1   2   1                                                             .  1   2   1
LOG: BFS STEP 3                                                        . LOG: BFS STEP 3
LOG: processing neighbors of (1,3)                                     . LOG: processing neighbors of (1,3)
LOG: Skipping BLOCKED tile at (0,3)                                    . LOG: Skipping BLOCKED tile at (0,3)
LOG: Found tile at (2,3) with len 2 path: ES                           . LOG: Found tile at (2,3) with len 2 path: ES
LOG: Skipping FOUND tile at (1,2)                                      . LOG: Skipping FOUND tile at (1,2)
LOG: Skipping BLOCKED tile at (1,4)                                    . LOG: Skipping BLOCKED tile at (1,4)
LOG: maze state after BFS step                                         . LOG: maze state after BFS step
#####:  0                                                              . #####:  0
#101#:  1                                                              . #101#:  1
#2#2#:  2                                                              . #2#2#:  2
# E #:  3                                                              . # E #:  3
#####:  4                                                              . #####:  4
01234                                                                  . 01234
0                                                                      . 0    
queue count: 2                                                         . queue count: 2
NN ROW COL                                                             . NN ROW COL
 0   2   1                                                             .  0   2   1
 1   2   3                                                             .  1   2   3
LOG: BFS STEP 4                                                        . LOG: BFS STEP 4
LOG: processing neighbors of (2,1)                                     . LOG: processing neighbors of (2,1)
LOG: Skipping FOUND tile at (1,1)                                      . LOG: Skipping FOUND tile at (1,1)
LOG: Found tile at (3,1) with len 3 path: WSS                          . LOG: Found tile at (3,1) with len 3 path: WSS
LOG: Skipping BLOCKED tile at (2,0)                                    . LOG: Skipping BLOCKED tile at (2,0)
LOG: Skipping BLOCKED tile at (2,2)                                    . LOG: Skipping BLOCKED tile at (2,2)
LOG: maze state after BFS step                                         . LOG: maze state after BFS step
#####:  0                                                              . #####:  0
#101#:  1                                                              . #101#:  1
#2#2#:  2                                                              . #2#2#:  2
#3E #:  3                                                              . #3E #:  3
#####:  4                                                              . #####:  4
01234                                                                  . 01234
0                                                                      . 0    
queue count: 2                                                         . queue count: 2
NN ROW COL                                                             . NN ROW COL
 0   2   3                                                             .  0   2   3
 1   3   1                                                             .  1   3   1
LOG: BFS STEP 5                                                        . LOG: BFS STEP 5
LOG: processing neighbors of (2,3)                                     . LOG: processing neighbors of (2,3)
LOG: Skipping FOUND tile at (1,3)                                      . LOG: Skipping FOUND tile at (1,3)
LOG: Found tile at (3,3) with len 3 path: ESS                          . LOG: Found tile at (3,3) with len 3 path: ESS
LOG: Skipping BLOCKED tile at (2,2)                                    . LOG: Skipping BLOCKED tile at (2,2)
LOG: Skipping BLOCKED tile at (2,4)                                    . LOG: Skipping BLOCKED tile at (2,4)
LOG: maze state after BFS step                                         . LOG: maze state after BFS step
#####:  0                                                              . #####:  0
#101#:  1                                                              . #101#:  1
#2#2#:  2                                                              . #2#2#:  2
#3E3#:  3                                                              . #3E3#:  3
#####:  4                                                              . #####:  4
01234                                                                  . 01234
0                                                                      . 0    
queue count: 2                                                         . queue count: 2
NN ROW COL                                                             . NN ROW COL
 0   3   1                                                             .  0   3   1
 1   3   3                                                             .  1   3   3
LOG: BFS STEP 6                                                        . LOG: BFS STEP 6
LOG: processing neighbors of (3,1)                                     . LOG: processing neighbors of (3,1)
LOG: Skipping FOUND tile at (2,1)                                      . LOG: Skipping FOUND tile at (2,1)
LOG: Skipping BLOCKED tile at (4,1)                                    . LOG: Skipping BLOCKED tile at (4,1)
LOG: Skipping BLOCKED tile at (3,0)                                    . LOG: Skipping BLOCKED tile at (3,0)
LOG: Found tile at (3,2) with len 4 path: WSSE                         . LOG: Found tile at (3,2) with len 4 path: WSSE
LOG: maze state after BFS step                                         . LOG: maze state after BFS step
#####:  0                                                              . #####:  0
#101#:  1                                                              . #101#:  1
#2#2#:  2                                                              . #2#2#:  2
#343#:  3                                                              . #343#:  3
#####:  4                                                              . #####:  4
01234                                                                  . 01234
0                                                                      . 0    
queue count: 2                                                         . queue count: 2
NN ROW COL                                                             . NN ROW COL
 0   3   3                                                             .  0   3   3
 1   3   2                                                             .  1   3   2
LOG: BFS STEP 7                                                        . LOG: BFS STEP 7
LOG: processing neighbors of (3,3)                                     . LOG: processing neighbors of (3,3)
LOG: Skipping FOUND tile at (2,3)                                      . LOG: Skipping FOUND tile at (2,3)
LOG: Skipping BLOCKED tile at (4,3)                                    . LOG: Skipping BLOCKED tile at (4,3)
LOG: Skipping FOUND tile at (3,2)                                      . LOG: Skipping FOUND tile at (3,2)
LOG: Skipping BLOCKED tile at (3,4)                                    . LOG: Skipping BLOCKED tile at (3,4)
LOG: maze state after BFS step                                         . LOG: maze state after BFS step
#####:  0                                                              . #####:  0
#101#:  1                                                              . #101#:  1
#2#2#:  2                                                              . #2#2#:  2
#343#:  3                                                              . #343#:  3
#####:  4                                                              . #####:  4
01234                                                                  . 01234
0                                                                      . 0    
queue count: 1                                                         . queue count: 1
NN ROW COL                                                             . NN ROW COL
 0   3   2                                                             .  0   3   2
LOG: BFS STEP 8                                                        . LOG: BFS STEP 8
LOG: processing neighbors of (3,2)                                     . LOG: processing neighbors of (3,2)
LOG: Skipping BLOCKED tile at (2,2)                                    . LOG: Skipping BLOCKED tile at (2,2)
LOG: Skipping BLOCKED tile at (4,2)                                    . LOG: Skipping BLOCKED tile at (4,2)
LOG: Skipping FOUND tile at (3,1)                                      . LOG: Skipping FOUND tile at (3,1)
LOG: Skipping FOUND tile at (3,3)                                      . LOG: Skipping FOUND tile at (3,3)
LOG: maze state after BFS step                                         . LOG: maze state after BFS step
#####:  0                                                              . #####:  0
#101#:  1                                                              . #101#:  1
#2#2#:  2                                                              . #2#2#:  2
#343#:  3                                                              . #343#:  3
#####:  4                                                              . #####:  4
01234                                                                  . 01234
0                                                                      . 0    
queue count: 0                                                         . queue count: 0
NN ROW COL                                                             . NN ROW COL
Maze AFTER BFS iteration                                               . Maze AFTER BFS iteration
#####:  0                                                              . #####:  0
#101#:  1                                                              . #101#:  1
#2#2#:  2                                                              . #2#2#:  2
#343#:  3                                                              . #343#:  3
#####:  4                                                              . #####:  4
01234                                                                  . 01234
0                                                                      . 0    
queue count: 0                                                         . queue count: 0
NN ROW COL                                                             . NN ROW COL

```

LINE-BY-LINE DIFF of Expected vs Actual
---------------------------------------
No differences found

VALGRIND REPORT
---------------
The program is run on under valgrind as
  stdbuf -i 0 -o 0 -e 0 valgrind --error-exitcode=13 --leak-check=full --show-leak-kinds=all --track-origins=yes ./test_mazesolve_funcs maze_bfs_iterate1
which may be pasted onto a command line to run it.

```
==15525== Memcheck, a memory error detector
==15525== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==15525== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==15525== Command: ./test_mazesolve_funcs maze_bfs_iterate1
==15525== 
==15525== 
==15525== HEAP SUMMARY:
==15525==     in use at exit: 0 bytes in 0 blocks
==15525==   total heap usage: 24 allocs, 24 frees, 900 bytes allocated
==15525== 
==15525== All heap blocks were freed -- no leaks are possible
==15525== 
==15525== For lists of detected and suppressed errors, rerun with: -s
==15525== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

SUMMARY
-------
Test Passed
