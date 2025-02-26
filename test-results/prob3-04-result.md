(TEST 4) maze_bfs_process_neighbor3 : ok
========================================

COMMENTS
--------


PROGRAM: ./test_mazesolve_funcs maze_bfs_process_neighbor3
----------------------------------------------------------
To run this individual test in GDB use the command:
  gdb --args ./test_mazesolve_funcs maze_bfs_process_neighbor3
but any input to the program must be typed within the debugger

FAILURE MESSAGES
----------------
None

SIDE-BY-SIDE DIFF of Expected vs Actual
---------------------------------------
. lines match; | lines differ; < expected line missing; > extra line in actual

```sdiff
===EXPECT===                                                            ===ACTUAL===
IF_TEST("maze_bfs_process_neighbor3") {                               . IF_TEST("maze_bfs_process_neighbor3") {
    // Process all 4 neighbors of the start tile which is at the edge .     // Process all 4 neighbors of the start tile which is at the edge
    // of the maze; some of its neighbors are out of bounds so the    .     // of the maze; some of its neighbors are out of bounds so the
    // test ensures that bounds checking is done via                  .     // test ensures that bounds checking is done via
    // maze_tile_blocked().                                           .     // maze_tile_blocked(). 
    char *maze_str =                                                  .     char *maze_str =
      "############## S\n"                                            .       "############## S\n"
      "#               \n"                                            .       "#               \n"
      "# ### ###### # #\n"                                            .       "# ### ###### # #\n"
      "# ### ##E  #   #\n"                                            .       "# ### ##E  #   #\n"
      "# ### #### ##  #\n"                                            .       "# ### #### ##  #\n"
      "#              #\n"                                            .       "#              #\n"
      "################\n";                                           .       "################\n";
    maze_t *maze = maze_from_string(maze_str);                        .     maze_t *maze = maze_from_string(maze_str);
    maze_bfs_init(maze);                                              .     maze_bfs_init(maze);
    LOG_LEVEL = LOG_ALL;                                              .     LOG_LEVEL = LOG_ALL;
    printf("Maze BEFORE processing neighbor(s)\n");                   .     printf("Maze BEFORE processing neighbor(s)\n");
    maze_print_state(maze);                                           .     maze_print_state(maze);
    int ret, r=maze->start_row, c=maze->start_col;                    .     int ret, r=maze->start_row, c=maze->start_col;
    ret = maze_bfs_process_neighbor(maze,r,c,NORTH);                  .     ret = maze_bfs_process_neighbor(maze,r,c,NORTH);
    printf("Maze AFTER processing 1 neighbor(s)\n");                  .     printf("Maze AFTER processing 1 neighbor(s)\n");
    maze_print_state(maze);                                           .     maze_print_state(maze);
    printf("ret: %d\n",ret);                                          .     printf("ret: %d\n",ret);
    ret = maze_bfs_process_neighbor(maze,r,c,SOUTH);                  .     ret = maze_bfs_process_neighbor(maze,r,c,SOUTH);
    printf("Maze AFTER processing 1 neighbor(s)\n");                  .     printf("Maze AFTER processing 1 neighbor(s)\n");
    maze_print_state(maze);                                           .     maze_print_state(maze);
    printf("ret: %d\n",ret);                                          .     printf("ret: %d\n",ret);
    ret = maze_bfs_process_neighbor(maze,r,c,WEST);                   .     ret = maze_bfs_process_neighbor(maze,r,c,WEST);
    printf("Maze AFTER processing 1 neighbor(s)\n");                  .     printf("Maze AFTER processing 1 neighbor(s)\n");
    maze_print_state(maze);                                           .     maze_print_state(maze);
    printf("ret: %d\n",ret);                                          .     printf("ret: %d\n",ret);
    ret = maze_bfs_process_neighbor(maze,r,c,EAST);                   .     ret = maze_bfs_process_neighbor(maze,r,c,EAST);
    printf("Maze AFTER processing 1 neighbor(s)\n");                  .     printf("Maze AFTER processing 1 neighbor(s)\n");
    maze_print_state(maze);                                           .     maze_print_state(maze);
    printf("ret: %d\n",ret);                                          .     printf("ret: %d\n",ret);
    maze_free(maze);                                                  .     maze_free(maze);
}                                                                     . }
---OUTPUT---                                                          . ---OUTPUT---
Maze BEFORE processing neighbor(s)                                    . Maze BEFORE processing neighbor(s)
############## 0:  0                                                  . ############## 0:  0
#               :  1                                                  . #               :  1
# ### ###### # #:  2                                                  . # ### ###### # #:  2
# ### ##E  #   #:  3                                                  . # ### ##E  #   #:  3
# ### #### ##  #:  4                                                  . # ### #### ##  #:  4
#              #:  5                                                  . #              #:  5
################:  6                                                  . ################:  6
0123456789012345                                                      . 0123456789012345
0         1                                                           . 0         1     
queue count: 1                                                        . queue count: 1
NN ROW COL                                                            . NN ROW COL
 0   0  15                                                            .  0   0   15
LOG: Skipping BLOCKED tile at (-1,15)                                 . LOG: Skipping BLOCKED tile at (-1,15)
Maze AFTER processing 1 neighbor(s)                                   . Maze AFTER processing 1 neighbor(s)
############## 0:  0                                                  . ############## 0:  0
#               :  1                                                  . #               :  1
# ### ###### # #:  2                                                  . # ### ###### # #:  2
# ### ##E  #   #:  3                                                  . # ### ##E  #   #:  3
# ### #### ##  #:  4                                                  . # ### #### ##  #:  4
#              #:  5                                                  . #              #:  5
################:  6                                                  . ################:  6
0123456789012345                                                      . 0123456789012345
0         1                                                           . 0         1     
queue count: 1                                                        . queue count: 1
NN ROW COL                                                            . NN ROW COL
 0   0  15                                                            .  0   0   15
ret: 0                                                                . ret: 0
LOG: Found tile at (1,15) with len 1 path: S                          . LOG: Found tile at (1,15) with len 1 path: S
Maze AFTER processing 1 neighbor(s)                                   . Maze AFTER processing 1 neighbor(s)
############## 0:  0                                                  . ############## 0:  0
#              1:  1                                                  . #              1:  1
# ### ###### # #:  2                                                  . # ### ###### # #:  2
# ### ##E  #   #:  3                                                  . # ### ##E  #   #:  3
# ### #### ##  #:  4                                                  . # ### #### ##  #:  4
#              #:  5                                                  . #              #:  5
################:  6                                                  . ################:  6
0123456789012345                                                      . 0123456789012345
0         1                                                           . 0         1     
queue count: 2                                                        . queue count: 2
NN ROW COL                                                            . NN ROW COL
 0   0  15                                                            .  0   0   15
 1   1  15                                                            .  1   1   15
ret: 1                                                                . ret: 1
LOG: Found tile at (0,14) with len 1 path: W                          . LOG: Found tile at (0,14) with len 1 path: W
Maze AFTER processing 1 neighbor(s)                                   . Maze AFTER processing 1 neighbor(s)
##############10:  0                                                  . ##############10:  0
#              1:  1                                                  . #              1:  1
# ### ###### # #:  2                                                  . # ### ###### # #:  2
# ### ##E  #   #:  3                                                  . # ### ##E  #   #:  3
# ### #### ##  #:  4                                                  . # ### #### ##  #:  4
#              #:  5                                                  . #              #:  5
################:  6                                                  . ################:  6
0123456789012345                                                      . 0123456789012345
0         1                                                           . 0         1     
queue count: 3                                                        . queue count: 3
NN ROW COL                                                            . NN ROW COL
 0   0  15                                                            .  0   0   15
 1   1  15                                                            .  1   1   15
 2   0  14                                                            .  2   0   14
ret: 1                                                                . ret: 1
LOG: Skipping BLOCKED tile at (0,16)                                  . LOG: Skipping BLOCKED tile at (0,16)
Maze AFTER processing 1 neighbor(s)                                   . Maze AFTER processing 1 neighbor(s)
##############10:  0                                                  . ##############10:  0
#              1:  1                                                  . #              1:  1
# ### ###### # #:  2                                                  . # ### ###### # #:  2
# ### ##E  #   #:  3                                                  . # ### ##E  #   #:  3
# ### #### ##  #:  4                                                  . # ### #### ##  #:  4
#              #:  5                                                  . #              #:  5
################:  6                                                  . ################:  6
0123456789012345                                                      . 0123456789012345
0         1                                                           . 0         1     
queue count: 3                                                        . queue count: 3
NN ROW COL                                                            . NN ROW COL
 0   0  15                                                            .  0   0   15
 1   1  15                                                            .  1   1   15
 2   0  14                                                            .  2   0   14
ret: 0                                                                . ret: 0

```

LINE-BY-LINE DIFF of Expected vs Actual
---------------------------------------
No differences found

VALGRIND REPORT
---------------
The program is run on under valgrind as
  stdbuf -i 0 -o 0 -e 0 valgrind --error-exitcode=13 --leak-check=full --show-leak-kinds=all --track-origins=yes ./test_mazesolve_funcs maze_bfs_process_neighbor3
which may be pasted onto a command line to run it.

```
==15521== Memcheck, a memory error detector
==15521== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==15521== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==15521== Command: ./test_mazesolve_funcs maze_bfs_process_neighbor3
==15521== 
==15521== 
==15521== HEAP SUMMARY:
==15521==     in use at exit: 0 bytes in 0 blocks
==15521==   total heap usage: 16 allocs, 16 frees, 2,868 bytes allocated
==15521== 
==15521== All heap blocks were freed -- no leaks are possible
==15521== 
==15521== For lists of detected and suppressed errors, rerun with: -s
==15521== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

SUMMARY
-------
Test Passed
