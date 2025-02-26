(TEST 2) maze_bfs_process_neighbor1 : ok
========================================

COMMENTS
--------


PROGRAM: ./test_mazesolve_funcs maze_bfs_process_neighbor1
----------------------------------------------------------
To run this individual test in GDB use the command:
  gdb --args ./test_mazesolve_funcs maze_bfs_process_neighbor1
but any input to the program must be typed within the debugger

FAILURE MESSAGES
----------------
None

SIDE-BY-SIDE DIFF of Expected vs Actual
---------------------------------------
. lines match; | lines differ; < expected line missing; > extra line in actual

```sdiff
===EXPECT===                                                             ===ACTUAL===
IF_TEST("maze_bfs_process_neighbor1") {                                . IF_TEST("maze_bfs_process_neighbor1") {
    // Make a single call to add a neighbor from an initial tile to an .     // Make a single call to add a neighbor from an initial tile to an
    // open neighbor which should create a path for the nighbor and    .     // open neighbor which should create a path for the nighbor and
    // queue the neighbor for later processing.                        .     // queue the neighbor for later processing.
    char *maze_str =                                                   .     char *maze_str =
      "################\n"                                             .       "################\n"
      "#S             #\n"                                             .       "#S             #\n"
      "# ### ###### # #\n"                                             .       "# ### ###### # #\n"
      "# ### ##E  #   #\n"                                             .       "# ### ##E  #   #\n"
      "# ### #### ##  #\n"                                             .       "# ### #### ##  #\n"
      "#              #\n"                                             .       "#              #\n"
      "################\n";                                            .       "################\n";
    maze_t *maze = maze_from_string(maze_str);                         .     maze_t *maze = maze_from_string(maze_str);
    maze_bfs_init(maze);                                               .     maze_bfs_init(maze);
    LOG_LEVEL = LOG_ALL;                                               .     LOG_LEVEL = LOG_ALL;
    printf("Maze BEFORE processing neighbor(s)\n");                    .     printf("Maze BEFORE processing neighbor(s)\n");
    maze_print_state(maze);                                            .     maze_print_state(maze);
    int ret = maze_bfs_process_neighbor(maze,1,1,SOUTH);               .     int ret = maze_bfs_process_neighbor(maze,1,1,SOUTH);
    printf("Maze AFTER processing neighbor\n");                        .     printf("Maze AFTER processing neighbor\n");
    maze_print_state(maze);                                            .     maze_print_state(maze);
    printf("ret: %d\n",ret);                                           .     printf("ret: %d\n",ret);
    printf("Tile Path:\n");                                            .     printf("Tile Path:\n");
    tile_print_path(&maze->tiles[2][1],PATH_FORMAT_VERBOSE);           .     tile_print_path(&maze->tiles[2][1],PATH_FORMAT_VERBOSE);
    maze_free(maze);                                                   .     maze_free(maze);
}                                                                      . }
---OUTPUT---                                                           . ---OUTPUT---
Maze BEFORE processing neighbor(s)                                     . Maze BEFORE processing neighbor(s)
################:  0                                                   . ################:  0
#0             #:  1                                                   . #0             #:  1
# ### ###### # #:  2                                                   . # ### ###### # #:  2
# ### ##E  #   #:  3                                                   . # ### ##E  #   #:  3
# ### #### ##  #:  4                                                   . # ### #### ##  #:  4
#              #:  5                                                   . #              #:  5
################:  6                                                   . ################:  6
0123456789012345                                                       . 0123456789012345
0         1                                                            . 0         1     
queue count: 1                                                         . queue count: 1
NN ROW COL                                                             . NN ROW COL
 0   1   1                                                             .  0   1   1
LOG: Found tile at (2,1) with len 1 path: S                            . LOG: Found tile at (2,1) with len 1 path: S
Maze AFTER processing neighbor                                         . Maze AFTER processing neighbor
################:  0                                                   . ################:  0
#0             #:  1                                                   . #0             #:  1
#1### ###### # #:  2                                                   . #1### ###### # #:  2
# ### ##E  #   #:  3                                                   . # ### ##E  #   #:  3
# ### #### ##  #:  4                                                   . # ### #### ##  #:  4
#              #:  5                                                   . #              #:  5
################:  6                                                   . ################:  6
0123456789012345                                                       . 0123456789012345
0         1                                                            . 0         1     
queue count: 2                                                         . queue count: 2
NN ROW COL                                                             . NN ROW COL
 0   1   1                                                             .  0   1   1
 1   2   1                                                             .  1   2   1
ret: 1                                                                 . ret: 1
Tile Path:                                                             . Tile Path:
path length: 1                                                         . path length: 1
 0: SOUTH                                                              .   0: SOUTH

```

LINE-BY-LINE DIFF of Expected vs Actual
---------------------------------------
No differences found

VALGRIND REPORT
---------------
The program is run on under valgrind as
  stdbuf -i 0 -o 0 -e 0 valgrind --error-exitcode=13 --leak-check=full --show-leak-kinds=all --track-origins=yes ./test_mazesolve_funcs maze_bfs_process_neighbor1
which may be pasted onto a command line to run it.

```
==15519== Memcheck, a memory error detector
==15519== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==15519== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==15519== Command: ./test_mazesolve_funcs maze_bfs_process_neighbor1
==15519== 
==15519== 
==15519== HEAP SUMMARY:
==15519==     in use at exit: 0 bytes in 0 blocks
==15519==   total heap usage: 14 allocs, 14 frees, 2,848 bytes allocated
==15519== 
==15519== All heap blocks were freed -- no leaks are possible
==15519== 
==15519== For lists of detected and suppressed errors, rerun with: -s
==15519== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

SUMMARY
-------
Test Passed
