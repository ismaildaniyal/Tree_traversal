(TEST 3) maze_bfs_process_neighbor2 : ok
========================================

COMMENTS
--------


PROGRAM: ./test_mazesolve_funcs maze_bfs_process_neighbor2
----------------------------------------------------------
To run this individual test in GDB use the command:
  gdb --args ./test_mazesolve_funcs maze_bfs_process_neighbor2
but any input to the program must be typed within the debugger

FAILURE MESSAGES
----------------
None

SIDE-BY-SIDE DIFF of Expected vs Actual
---------------------------------------
. lines match; | lines differ; < expected line missing; > extra line in actual

```sdiff
===EXPECT===                                                             ===ACTUAL===
IF_TEST("maze_bfs_process_neighbor2") {                                . IF_TEST("maze_bfs_process_neighbor2") {
    // Make 3 successive calls to process neighbors. The 1st and 2nd   .     // Make 3 successive calls to process neighbors. The 1st and 2nd
    // will add a new neighbor but the 3rd call will not as due to the .     // will add a new neighbor but the 3rd call will not as due to the
    // neighbor being a blocked wall.                                  .     // neighbor being a blocked wall.
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
    int ret = maze_bfs_process_neighbor(maze,1,1,EAST);                .     int ret = maze_bfs_process_neighbor(maze,1,1,EAST);
    printf("Maze AFTER processing 1 neighbor(s)\n");                   .     printf("Maze AFTER processing 1 neighbor(s)\n");
    maze_print_state(maze);                                            .     maze_print_state(maze);
    printf("ret: %d\n",ret);                                           .     printf("ret: %d\n",ret);
    printf("Tile Path:\n");                                            .     printf("Tile Path:\n");
    tile_print_path(&maze->tiles[1][2],PATH_FORMAT_VERBOSE);           .     tile_print_path(&maze->tiles[1][2],PATH_FORMAT_VERBOSE);
    ret = maze_bfs_process_neighbor(maze,1,1,SOUTH);                   .     ret = maze_bfs_process_neighbor(maze,1,1,SOUTH);
    printf("Maze AFTER processing 2 neighbor(s)\n");                   .     printf("Maze AFTER processing 2 neighbor(s)\n");
    maze_print_state(maze);                                            .     maze_print_state(maze);
    printf("ret: %d\n",ret);                                           .     printf("ret: %d\n",ret);
    printf("Tile Path:\n");                                            .     printf("Tile Path:\n");
    tile_print_path(&maze->tiles[2][1],PATH_FORMAT_VERBOSE);           .     tile_print_path(&maze->tiles[2][1],PATH_FORMAT_VERBOSE);
    ret = maze_bfs_process_neighbor(maze,1,1,NORTH);                   .     ret = maze_bfs_process_neighbor(maze,1,1,NORTH);
    printf("Maze AFTER processing 3 neighbor(s)\n");                   .     printf("Maze AFTER processing 3 neighbor(s)\n");
    maze_print_state(maze);                                            .     maze_print_state(maze);
    printf("ret: %d\n",ret);                                           .     printf("ret: %d\n",ret);
    printf("Tile Path:\n");                                            .     printf("Tile Path:\n");
    tile_print_path(&maze->tiles[0][1],PATH_FORMAT_VERBOSE);           .     tile_print_path(&maze->tiles[0][1],PATH_FORMAT_VERBOSE);
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
LOG: Found tile at (1,2) with len 1 path: E                            . LOG: Found tile at (1,2) with len 1 path: E
Maze AFTER processing 1 neighbor(s)                                    . Maze AFTER processing 1 neighbor(s)
################:  0                                                   . ################:  0
#01            #:  1                                                   . #01            #:  1
# ### ###### # #:  2                                                   . # ### ###### # #:  2
# ### ##E  #   #:  3                                                   . # ### ##E  #   #:  3
# ### #### ##  #:  4                                                   . # ### #### ##  #:  4
#              #:  5                                                   . #              #:  5
################:  6                                                   . ################:  6
0123456789012345                                                       . 0123456789012345
0         1                                                            . 0         1     
queue count: 2                                                         . queue count: 2
NN ROW COL                                                             . NN ROW COL
 0   1   1                                                             .  0   1   1
 1   1   2                                                             .  1   1   2
ret: 1                                                                 . ret: 1
Tile Path:                                                             . Tile Path:
path length: 1                                                         . path length: 1
 0: EAST                                                               .   0: EAST
LOG: Found tile at (2,1) with len 1 path: S                            . LOG: Found tile at (2,1) with len 1 path: S
Maze AFTER processing 2 neighbor(s)                                    . Maze AFTER processing 2 neighbor(s)
################:  0                                                   . ################:  0
#01            #:  1                                                   . #01            #:  1
#1### ###### # #:  2                                                   . #1### ###### # #:  2
# ### ##E  #   #:  3                                                   . # ### ##E  #   #:  3
# ### #### ##  #:  4                                                   . # ### #### ##  #:  4
#              #:  5                                                   . #              #:  5
################:  6                                                   . ################:  6
0123456789012345                                                       . 0123456789012345
0         1                                                            . 0         1     
queue count: 3                                                         . queue count: 3
NN ROW COL                                                             . NN ROW COL
 0   1   1                                                             .  0   1   1
 1   1   2                                                             .  1   1   2
 2   2   1                                                             .  2   2   1
ret: 1                                                                 . ret: 1
Tile Path:                                                             . Tile Path:
path length: 1                                                         . path length: 1
 0: SOUTH                                                              .   0: SOUTH
LOG: Skipping BLOCKED tile at (0,1)                                    . LOG: Skipping BLOCKED tile at (0,1)
Maze AFTER processing 3 neighbor(s)                                    . Maze AFTER processing 3 neighbor(s)
################:  0                                                   . ################:  0
#01            #:  1                                                   . #01            #:  1
#1### ###### # #:  2                                                   . #1### ###### # #:  2
# ### ##E  #   #:  3                                                   . # ### ##E  #   #:  3
# ### #### ##  #:  4                                                   . # ### #### ##  #:  4
#              #:  5                                                   . #              #:  5
################:  6                                                   . ################:  6
0123456789012345                                                       . 0123456789012345
0         1                                                            . 0         1     
queue count: 3                                                         . queue count: 3
NN ROW COL                                                             . NN ROW COL
 0   1   1                                                             .  0   1   1
 1   1   2                                                             .  1   1   2
 2   2   1                                                             .  2   2   1
ret: 0                                                                 . ret: 0
Tile Path:                                                             . Tile Path:
No path found                                                          . No path found

```

LINE-BY-LINE DIFF of Expected vs Actual
---------------------------------------
No differences found

VALGRIND REPORT
---------------
The program is run on under valgrind as
  stdbuf -i 0 -o 0 -e 0 valgrind --error-exitcode=13 --leak-check=full --show-leak-kinds=all --track-origins=yes ./test_mazesolve_funcs maze_bfs_process_neighbor2
which may be pasted onto a command line to run it.

```
==15520== Memcheck, a memory error detector
==15520== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==15520== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==15520== Command: ./test_mazesolve_funcs maze_bfs_process_neighbor2
==15520== 
==15520== 
==15520== HEAP SUMMARY:
==15520==     in use at exit: 0 bytes in 0 blocks
==15520==   total heap usage: 16 allocs, 16 frees, 2,868 bytes allocated
==15520== 
==15520== All heap blocks were freed -- no leaks are possible
==15520== 
==15520== For lists of detected and suppressed errors, rerun with: -s
==15520== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

SUMMARY
-------
Test Passed
