(TEST 5) maze_bfs_step1 : ok
============================

COMMENTS
--------


PROGRAM: ./test_mazesolve_funcs maze_bfs_step1
----------------------------------------------
To run this individual test in GDB use the command:
  gdb --args ./test_mazesolve_funcs maze_bfs_step1
but any input to the program must be typed within the debugger

FAILURE MESSAGES
----------------
None

SIDE-BY-SIDE DIFF of Expected vs Actual
---------------------------------------
. lines match; | lines differ; < expected line missing; > extra line in actual

```sdiff
===EXPECT===                                                           ===ACTUAL===
IF_TEST("maze_bfs_step1") {                                          . IF_TEST("maze_bfs_step1") {
    // Performs the intial BFS step iterating over the 4 adjacent    .     // Performs the intial BFS step iterating over the 4 adjacent
    // tiles to the Start tile which is at the front of the queue in .     // tiles to the Start tile which is at the front of the queue in
    // the example. The NORTH, WEST, EAST neighbor tiles should be   .     // the example. The NORTH, WEST, EAST neighbor tiles should be
    // Found and added into the queue while the SOUTH neighbor is    .     // Found and added into the queue while the SOUTH neighbor is
    // blocked. Logging is on so messages concerning each neighbor   .     // blocked. Logging is on so messages concerning each neighbor
    // should be displayed.                                          .     // should be displayed.
    char *maze_str =                                                 .     char *maze_str =
      "###################\n"                                        .       "###################\n"
      "#          #    # #\n"                                        .       "#          #    # #\n"
      "# ###  ##    ## # #\n"                                        .       "# ###  ##    ## # #\n"
      "#  ##  # S #  # # #\n"                                        .       "#  ##  # S #  # # #\n"
      "##  #  #####  # # #\n"                                        .       "##  #  #####  # # #\n"
      "#E  #         #   #\n"                                        .       "#E  #         #   #\n"
      "###################\n";                                       .       "###################\n";
    maze_t *maze = maze_from_string(maze_str);                       .     maze_t *maze = maze_from_string(maze_str);
    maze_bfs_init(maze);                                             .     maze_bfs_init(maze);
    printf("Maze BEFORE BFS step\n");                                .     printf("Maze BEFORE BFS step\n");
    LOG_LEVEL = LOG_ALL;                                             .     LOG_LEVEL = LOG_ALL;
    maze_print_state(maze);                                          .     maze_print_state(maze);
    int ret = maze_bfs_step(maze);                                   .     int ret = maze_bfs_step(maze);
    printf("step ret: %d\n",ret);                                    .     printf("step ret: %d\n",ret);
    printf("Maze AFTER BFS step\n");                                 .     printf("Maze AFTER BFS step\n");
    maze_print_state(maze);                                          .     maze_print_state(maze);
    maze_free(maze);                                                 .     maze_free(maze);
}                                                                    . }
---OUTPUT---                                                         . ---OUTPUT---
Maze BEFORE BFS step                                                 . Maze BEFORE BFS step
###################:  0                                              . ###################:  0
#          #    # #:  1                                              . #          #    # #:  1
# ###  ##    ## # #:  2                                              . # ###  ##    ## # #:  2
#  ##  # 0 #  # # #:  3                                              . #  ##  # 0 #  # # #:  3
##  #  #####  # # #:  4                                              . ##  #  #####  # # #:  4
#E  #         #   #:  5                                              . #E  #         #   #:  5
###################:  6                                              . ###################:  6
0123456789012345678                                                  . 0123456789012345678
0         1                                                          . 0         1        
queue count: 1                                                       . queue count: 1
NN ROW COL                                                           . NN ROW COL
 0   3   9                                                           .  0   3   9
LOG: processing neighbors of (3,9)                                   . LOG: processing neighbors of (3,9)
LOG: Found tile at (2,9) with len 1 path: N                          . LOG: Found tile at (2,9) with len 1 path: N
LOG: Skipping BLOCKED tile at (4,9)                                  . LOG: Skipping BLOCKED tile at (4,9)
LOG: Found tile at (3,8) with len 1 path: W                          . LOG: Found tile at (3,8) with len 1 path: W
LOG: Found tile at (3,10) with len 1 path: E                         . LOG: Found tile at (3,10) with len 1 path: E
LOG: maze state after BFS step                                       . LOG: maze state after BFS step
###################:  0                                              . ###################:  0
#          #    # #:  1                                              . #          #    # #:  1
# ###  ##1   ## # #:  2                                              . # ###  ##1   ## # #:  2
#  ##  #101#  # # #:  3                                              . #  ##  #101#  # # #:  3
##  #  #####  # # #:  4                                              . ##  #  #####  # # #:  4
#E  #         #   #:  5                                              . #E  #         #   #:  5
###################:  6                                              . ###################:  6
0123456789012345678                                                  . 0123456789012345678
0         1                                                          . 0         1        
queue count: 3                                                       . queue count: 3
NN ROW COL                                                           . NN ROW COL
 0   2   9                                                           .  0   2   9
 1   3   8                                                           .  1   3   8
 2   3  10                                                           .  2   3   10
step ret: 1                                                          . step ret: 1
Maze AFTER BFS step                                                  . Maze AFTER BFS step
###################:  0                                              . ###################:  0
#          #    # #:  1                                              . #          #    # #:  1
# ###  ##1   ## # #:  2                                              . # ###  ##1   ## # #:  2
#  ##  #101#  # # #:  3                                              . #  ##  #101#  # # #:  3
##  #  #####  # # #:  4                                              . ##  #  #####  # # #:  4
#E  #         #   #:  5                                              . #E  #         #   #:  5
###################:  6                                              . ###################:  6
0123456789012345678                                                  . 0123456789012345678
0         1                                                          . 0         1        
queue count: 3                                                       . queue count: 3
NN ROW COL                                                           . NN ROW COL
 0   2   9                                                           .  0   2   9
 1   3   8                                                           .  1   3   8
 2   3  10                                                           .  2   3   10

```

LINE-BY-LINE DIFF of Expected vs Actual
---------------------------------------
No differences found

VALGRIND REPORT
---------------
The program is run on under valgrind as
  stdbuf -i 0 -o 0 -e 0 valgrind --error-exitcode=13 --leak-check=full --show-leak-kinds=all --track-origins=yes ./test_mazesolve_funcs maze_bfs_step1
which may be pasted onto a command line to run it.

```
==15522== Memcheck, a memory error detector
==15522== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==15522== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==15522== Command: ./test_mazesolve_funcs maze_bfs_step1
==15522== 
==15522== 
==15522== HEAP SUMMARY:
==15522==     in use at exit: 0 bytes in 0 blocks
==15522==   total heap usage: 18 allocs, 18 frees, 3,392 bytes allocated
==15522== 
==15522== All heap blocks were freed -- no leaks are possible
==15522== 
==15522== For lists of detected and suppressed errors, rerun with: -s
==15522== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

SUMMARY
-------
Test Passed
