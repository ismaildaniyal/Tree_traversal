(TEST 9) maze_bfs_iterate2 : ok
===============================

COMMENTS
--------


PROGRAM: ./test_mazesolve_funcs maze_bfs_iterate2
-------------------------------------------------
To run this individual test in GDB use the command:
  gdb --args ./test_mazesolve_funcs maze_bfs_iterate2
but any input to the program must be typed within the debugger

FAILURE MESSAGES
----------------
None

SIDE-BY-SIDE DIFF of Expected vs Actual
---------------------------------------
. lines match; | lines differ; < expected line missing; > extra line in actual

```sdiff
===EXPECT===                                                             ===ACTUAL===
IF_TEST("maze_bfs_iterate2") {                                         . IF_TEST("maze_bfs_iterate2") {
    // Checks the BFS iteration function to ensure it visits all tiles .     // Checks the BFS iteration function to ensure it visits all tiles
    // to obtain paths to each one from the start tile. A small maze   .     // to obtain paths to each one from the start tile. A small maze
    // is used without a "bounding wall".                              .     // is used without a "bounding wall".
    char *maze_str =                                                   .     char *maze_str =
      "S \n"                                                           .       "S \n"
      "# \n"                                                           .       "# \n"
      "E \n";                                                          .       "E \n";
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
S :  0                                                                 . S :  0
# :  1                                                                 . # :  1
E :  2                                                                 . E :  2
01                                                                     . 01
0                                                                      . 0 
null queue                                                             . null queue
LOG: BFS initialization complete                                       . LOG: BFS initialization complete
0 :  0                                                                 . 0 :  0
# :  1                                                                 . # :  1
E :  2                                                                 . E :  2
01                                                                     . 01
0                                                                      . 0 
queue count: 1                                                         . queue count: 1
NN ROW COL                                                             . NN ROW COL
 0   0   0                                                             .  0   0   0
LOG: BFS STEP 1                                                        . LOG: BFS STEP 1
LOG: processing neighbors of (0,0)                                     . LOG: processing neighbors of (0,0)
LOG: Skipping BLOCKED tile at (-1,0)                                   . LOG: Skipping BLOCKED tile at (-1,0)
LOG: Skipping BLOCKED tile at (1,0)                                    . LOG: Skipping BLOCKED tile at (1,0)
LOG: Skipping BLOCKED tile at (0,-1)                                   . LOG: Skipping BLOCKED tile at (0,-1)
LOG: Found tile at (0,1) with len 1 path: E                            . LOG: Found tile at (0,1) with len 1 path: E
LOG: maze state after BFS step                                         . LOG: maze state after BFS step
01:  0                                                                 . 01:  0
# :  1                                                                 . # :  1
E :  2                                                                 . E :  2
01                                                                     . 01
0                                                                      . 0 
queue count: 1                                                         . queue count: 1
NN ROW COL                                                             . NN ROW COL
 0   0   1                                                             .  0   0   1
LOG: BFS STEP 2                                                        . LOG: BFS STEP 2
LOG: processing neighbors of (0,1)                                     . LOG: processing neighbors of (0,1)
LOG: Skipping BLOCKED tile at (-1,1)                                   . LOG: Skipping BLOCKED tile at (-1,1)
LOG: Found tile at (1,1) with len 2 path: ES                           . LOG: Found tile at (1,1) with len 2 path: ES
LOG: Skipping FOUND tile at (0,0)                                      . LOG: Skipping FOUND tile at (0,0)
LOG: Skipping BLOCKED tile at (0,2)                                    . LOG: Skipping BLOCKED tile at (0,2)
LOG: maze state after BFS step                                         . LOG: maze state after BFS step
01:  0                                                                 . 01:  0
#2:  1                                                                 . #2:  1
E :  2                                                                 . E :  2
01                                                                     . 01
0                                                                      . 0 
queue count: 1                                                         . queue count: 1
NN ROW COL                                                             . NN ROW COL
 0   1   1                                                             .  0   1   1
LOG: BFS STEP 3                                                        . LOG: BFS STEP 3
LOG: processing neighbors of (1,1)                                     . LOG: processing neighbors of (1,1)
LOG: Skipping FOUND tile at (0,1)                                      . LOG: Skipping FOUND tile at (0,1)
LOG: Found tile at (2,1) with len 3 path: ESS                          . LOG: Found tile at (2,1) with len 3 path: ESS
LOG: Skipping BLOCKED tile at (1,0)                                    . LOG: Skipping BLOCKED tile at (1,0)
LOG: Skipping BLOCKED tile at (1,2)                                    . LOG: Skipping BLOCKED tile at (1,2)
LOG: maze state after BFS step                                         . LOG: maze state after BFS step
01:  0                                                                 . 01:  0
#2:  1                                                                 . #2:  1
E3:  2                                                                 . E3:  2
01                                                                     . 01
0                                                                      . 0 
queue count: 1                                                         . queue count: 1
NN ROW COL                                                             . NN ROW COL
 0   2   1                                                             .  0   2   1
LOG: BFS STEP 4                                                        . LOG: BFS STEP 4
LOG: processing neighbors of (2,1)                                     . LOG: processing neighbors of (2,1)
LOG: Skipping FOUND tile at (1,1)                                      . LOG: Skipping FOUND tile at (1,1)
LOG: Skipping BLOCKED tile at (3,1)                                    . LOG: Skipping BLOCKED tile at (3,1)
LOG: Found tile at (2,0) with len 4 path: ESSW                         . LOG: Found tile at (2,0) with len 4 path: ESSW
LOG: Skipping BLOCKED tile at (2,2)                                    . LOG: Skipping BLOCKED tile at (2,2)
LOG: maze state after BFS step                                         . LOG: maze state after BFS step
01:  0                                                                 . 01:  0
#2:  1                                                                 . #2:  1
43:  2                                                                 . 43:  2
01                                                                     . 01
0                                                                      . 0 
queue count: 1                                                         . queue count: 1
NN ROW COL                                                             . NN ROW COL
 0   2   0                                                             .  0   2   0
LOG: BFS STEP 5                                                        . LOG: BFS STEP 5
LOG: processing neighbors of (2,0)                                     . LOG: processing neighbors of (2,0)
LOG: Skipping BLOCKED tile at (1,0)                                    . LOG: Skipping BLOCKED tile at (1,0)
LOG: Skipping BLOCKED tile at (3,0)                                    . LOG: Skipping BLOCKED tile at (3,0)
LOG: Skipping BLOCKED tile at (2,-1)                                   . LOG: Skipping BLOCKED tile at (2,-1)
LOG: Skipping FOUND tile at (2,1)                                      . LOG: Skipping FOUND tile at (2,1)
LOG: maze state after BFS step                                         . LOG: maze state after BFS step
01:  0                                                                 . 01:  0
#2:  1                                                                 . #2:  1
43:  2                                                                 . 43:  2
01                                                                     . 01
0                                                                      . 0 
queue count: 0                                                         . queue count: 0
NN ROW COL                                                             . NN ROW COL
Maze AFTER BFS iteration                                               . Maze AFTER BFS iteration
01:  0                                                                 . 01:  0
#2:  1                                                                 . #2:  1
43:  2                                                                 . 43:  2
01                                                                     . 01
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
  stdbuf -i 0 -o 0 -e 0 valgrind --error-exitcode=13 --leak-check=full --show-leak-kinds=all --track-origins=yes ./test_mazesolve_funcs maze_bfs_iterate2
which may be pasted onto a command line to run it.

```
==15544== Memcheck, a memory error detector
==15544== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==15544== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==15544== Command: ./test_mazesolve_funcs maze_bfs_iterate2
==15544== 
==15544== 
==15544== HEAP SUMMARY:
==15544==     in use at exit: 0 bytes in 0 blocks
==15544==   total heap usage: 16 allocs, 16 frees, 356 bytes allocated
==15544== 
==15544== All heap blocks were freed -- no leaks are possible
==15544== 
==15544== For lists of detected and suppressed errors, rerun with: -s
==15544== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

SUMMARY
-------
Test Passed
