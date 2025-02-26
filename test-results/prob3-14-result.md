(TEST 14) maze_bfs_complete1 : ok
=================================

COMMENTS
--------


PROGRAM: ./test_mazesolve_funcs maze_bfs_complete1
--------------------------------------------------
To run this individual test in GDB use the command:
  gdb --args ./test_mazesolve_funcs maze_bfs_complete1
but any input to the program must be typed within the debugger

FAILURE MESSAGES
----------------
None

SIDE-BY-SIDE DIFF of Expected vs Actual
---------------------------------------
. lines match; | lines differ; < expected line missing; > extra line in actual

```sdiff
===EXPECT===                                                          ===ACTUAL===
IF_TEST("maze_bfs_complete1") {                                     . IF_TEST("maze_bfs_complete1") {
    // Perform BFS iteration on a medium maze then set the solution .     // Perform BFS iteration on a medium maze then set the solution
    // and print it. Represents similar flow to the main program.   .     // and print it. Represents similar flow to the main program.
    char *maze_str =                                                .     char *maze_str =
      "###########\n"                                               .       "###########\n"
      "#S       ##\n"                                               .       "#S       ##\n"
      "# ### ## ##\n"                                               .       "# ### ## ##\n"
      "# ### ## ##\n"                                               .       "# ### ## ##\n"
      "# ###E## ##\n"                                               .       "# ###E## ##\n"
      "#        ##\n"                                               .       "#        ##\n"
      "###########\n";                                              .       "###########\n";
    maze_t *maze = maze_from_string(maze_str);                      .     maze_t *maze = maze_from_string(maze_str);
    printf("Maze BEFORE BFS iteration\n");                          .     printf("Maze BEFORE BFS iteration\n");
    maze_print_state(maze);                                         .     maze_print_state(maze);
    LOG_LEVEL = LOG_ALL;                                            .     LOG_LEVEL = LOG_ALL;
    maze_bfs_iterate(maze);                                         .     maze_bfs_iterate(maze);
    printf("Maze AFTER BFS iteration\n");                           .     printf("Maze AFTER BFS iteration\n");
    maze_print_state(maze);                                         .     maze_print_state(maze);
    printf("Maze BEFORE Setting Solution\n");                       .     printf("Maze BEFORE Setting Solution\n");
    maze_print_tiles(maze);                                         .     maze_print_tiles(maze);
    printf("Setting Solution Path\n");                              .     printf("Setting Solution Path\n");
    int ret = maze_set_solution(maze);                              .     int ret = maze_set_solution(maze);
    printf("ret: %d\n",ret);                                        .     printf("ret: %d\n",ret);
    printf("Maze AFTER Setting Solution\n");                        .     printf("Maze AFTER Setting Solution\n");
    maze_print_tiles(maze);                                         .     maze_print_tiles(maze);
    maze_free(maze);                                                .     maze_free(maze);
}                                                                   . }
---OUTPUT---                                                        . ---OUTPUT---
Maze BEFORE BFS iteration                                           . Maze BEFORE BFS iteration
###########:  0                                                     . ###########:  0
#S       ##:  1                                                     . #S       ##:  1
# ### ## ##:  2                                                     . # ### ## ##:  2
# ### ## ##:  3                                                     . # ### ## ##:  3
# ###E## ##:  4                                                     . # ###E## ##:  4
#        ##:  5                                                     . #        ##:  5
###########:  6                                                     . ###########:  6
01234567890                                                         . 01234567890
0         1                                                         . 0         1
null queue                                                          . null queue
LOG: BFS initialization complete                                    . LOG: BFS initialization complete
###########:  0                                                     . ###########:  0
#0       ##:  1                                                     . #0       ##:  1
# ### ## ##:  2                                                     . # ### ## ##:  2
# ### ## ##:  3                                                     . # ### ## ##:  3
# ###E## ##:  4                                                     . # ###E## ##:  4
#        ##:  5                                                     . #        ##:  5
###########:  6                                                     . ###########:  6
01234567890                                                         . 01234567890
0         1                                                         . 0         1
queue count: 1                                                      . queue count: 1
NN ROW COL                                                          . NN ROW COL
 0   1   1                                                          .  0   1   1
LOG: BFS STEP 1                                                     . LOG: BFS STEP 1
LOG: processing neighbors of (1,1)                                  . LOG: processing neighbors of (1,1)
LOG: Skipping BLOCKED tile at (0,1)                                 . LOG: Skipping BLOCKED tile at (0,1)
LOG: Found tile at (2,1) with len 1 path: S                         . LOG: Found tile at (2,1) with len 1 path: S
LOG: Skipping BLOCKED tile at (1,0)                                 . LOG: Skipping BLOCKED tile at (1,0)
LOG: Found tile at (1,2) with len 1 path: E                         . LOG: Found tile at (1,2) with len 1 path: E
LOG: maze state after BFS step                                      . LOG: maze state after BFS step
###########:  0                                                     . ###########:  0
#01      ##:  1                                                     . #01      ##:  1
#1### ## ##:  2                                                     . #1### ## ##:  2
# ### ## ##:  3                                                     . # ### ## ##:  3
# ###E## ##:  4                                                     . # ###E## ##:  4
#        ##:  5                                                     . #        ##:  5
###########:  6                                                     . ###########:  6
01234567890                                                         . 01234567890
0         1                                                         . 0         1
queue count: 2                                                      . queue count: 2
NN ROW COL                                                          . NN ROW COL
 0   2   1                                                          .  0   2   1
 1   1   2                                                          .  1   1   2
LOG: BFS STEP 2                                                     . LOG: BFS STEP 2
LOG: processing neighbors of (2,1)                                  . LOG: processing neighbors of (2,1)
LOG: Skipping FOUND tile at (1,1)                                   . LOG: Skipping FOUND tile at (1,1)
LOG: Found tile at (3,1) with len 2 path: SS                        . LOG: Found tile at (3,1) with len 2 path: SS
LOG: Skipping BLOCKED tile at (2,0)                                 . LOG: Skipping BLOCKED tile at (2,0)
LOG: Skipping BLOCKED tile at (2,2)                                 . LOG: Skipping BLOCKED tile at (2,2)
LOG: maze state after BFS step                                      . LOG: maze state after BFS step
###########:  0                                                     . ###########:  0
#01      ##:  1                                                     . #01      ##:  1
#1### ## ##:  2                                                     . #1### ## ##:  2
#2### ## ##:  3                                                     . #2### ## ##:  3
# ###E## ##:  4                                                     . # ###E## ##:  4
#        ##:  5                                                     . #        ##:  5
###########:  6                                                     . ###########:  6
01234567890                                                         . 01234567890
0         1                                                         . 0         1
queue count: 2                                                      . queue count: 2
NN ROW COL                                                          . NN ROW COL
 0   1   2                                                          .  0   1   2
 1   3   1                                                          .  1   3   1
LOG: BFS STEP 3                                                     . LOG: BFS STEP 3
LOG: processing neighbors of (1,2)                                  . LOG: processing neighbors of (1,2)
LOG: Skipping BLOCKED tile at (0,2)                                 . LOG: Skipping BLOCKED tile at (0,2)
LOG: Skipping BLOCKED tile at (2,2)                                 . LOG: Skipping BLOCKED tile at (2,2)
LOG: Skipping FOUND tile at (1,1)                                   . LOG: Skipping FOUND tile at (1,1)
LOG: Found tile at (1,3) with len 2 path: EE                        . LOG: Found tile at (1,3) with len 2 path: EE
LOG: maze state after BFS step                                      . LOG: maze state after BFS step
###########:  0                                                     . ###########:  0
#012     ##:  1                                                     . #012     ##:  1
#1### ## ##:  2                                                     . #1### ## ##:  2
#2### ## ##:  3                                                     . #2### ## ##:  3
# ###E## ##:  4                                                     . # ###E## ##:  4
#        ##:  5                                                     . #        ##:  5
###########:  6                                                     . ###########:  6
01234567890                                                         . 01234567890
0         1                                                         . 0         1
queue count: 2                                                      . queue count: 2
NN ROW COL                                                          . NN ROW COL
 0   3   1                                                          .  0   3   1
 1   1   3                                                          .  1   1   3
LOG: BFS STEP 4                                                     . LOG: BFS STEP 4
LOG: processing neighbors of (3,1)                                  . LOG: processing neighbors of (3,1)
LOG: Skipping FOUND tile at (2,1)                                   . LOG: Skipping FOUND tile at (2,1)
LOG: Found tile at (4,1) with len 3 path: SSS                       . LOG: Found tile at (4,1) with len 3 path: SSS
LOG: Skipping BLOCKED tile at (3,0)                                 . LOG: Skipping BLOCKED tile at (3,0)
LOG: Skipping BLOCKED tile at (3,2)                                 . LOG: Skipping BLOCKED tile at (3,2)
LOG: maze state after BFS step                                      . LOG: maze state after BFS step
###########:  0                                                     . ###########:  0
#012     ##:  1                                                     . #012     ##:  1
#1### ## ##:  2                                                     . #1### ## ##:  2
#2### ## ##:  3                                                     . #2### ## ##:  3
#3###E## ##:  4                                                     . #3###E## ##:  4
#        ##:  5                                                     . #        ##:  5
###########:  6                                                     . ###########:  6
01234567890                                                         . 01234567890
0         1                                                         . 0         1
queue count: 2                                                      . queue count: 2
NN ROW COL                                                          . NN ROW COL
 0   1   3                                                          .  0   1   3
 1   4   1                                                          .  1   4   1
LOG: BFS STEP 5                                                     . LOG: BFS STEP 5
LOG: processing neighbors of (1,3)                                  . LOG: processing neighbors of (1,3)
LOG: Skipping BLOCKED tile at (0,3)                                 . LOG: Skipping BLOCKED tile at (0,3)
LOG: Skipping BLOCKED tile at (2,3)                                 . LOG: Skipping BLOCKED tile at (2,3)
LOG: Skipping FOUND tile at (1,2)                                   . LOG: Skipping FOUND tile at (1,2)
LOG: Found tile at (1,4) with len 3 path: EEE                       . LOG: Found tile at (1,4) with len 3 path: EEE
LOG: maze state after BFS step                                      . LOG: maze state after BFS step
###########:  0                                                     . ###########:  0
#0123    ##:  1                                                     . #0123    ##:  1
#1### ## ##:  2                                                     . #1### ## ##:  2
#2### ## ##:  3                                                     . #2### ## ##:  3
#3###E## ##:  4                                                     . #3###E## ##:  4
#        ##:  5                                                     . #        ##:  5
###########:  6                                                     . ###########:  6
01234567890                                                         . 01234567890
0         1                                                         . 0         1
queue count: 2                                                      . queue count: 2
NN ROW COL                                                          . NN ROW COL
 0   4   1                                                          .  0   4   1
 1   1   4                                                          .  1   1   4
LOG: BFS STEP 6                                                     . LOG: BFS STEP 6
LOG: processing neighbors of (4,1)                                  . LOG: processing neighbors of (4,1)
LOG: Skipping FOUND tile at (3,1)                                   . LOG: Skipping FOUND tile at (3,1)
LOG: Found tile at (5,1) with len 4 path: SSSS                      . LOG: Found tile at (5,1) with len 4 path: SSSS
LOG: Skipping BLOCKED tile at (4,0)                                 . LOG: Skipping BLOCKED tile at (4,0)
LOG: Skipping BLOCKED tile at (4,2)                                 . LOG: Skipping BLOCKED tile at (4,2)
LOG: maze state after BFS step                                      . LOG: maze state after BFS step
###########:  0                                                     . ###########:  0
#0123    ##:  1                                                     . #0123    ##:  1
#1### ## ##:  2                                                     . #1### ## ##:  2
#2### ## ##:  3                                                     . #2### ## ##:  3
#3###E## ##:  4                                                     . #3###E## ##:  4
#4       ##:  5                                                     . #4       ##:  5
###########:  6                                                     . ###########:  6
01234567890                                                         . 01234567890
0         1                                                         . 0         1
queue count: 2                                                      . queue count: 2
NN ROW COL                                                          . NN ROW COL
 0   1   4                                                          .  0   1   4
 1   5   1                                                          .  1   5   1
LOG: BFS STEP 7                                                     . LOG: BFS STEP 7
LOG: processing neighbors of (1,4)                                  . LOG: processing neighbors of (1,4)
LOG: Skipping BLOCKED tile at (0,4)                                 . LOG: Skipping BLOCKED tile at (0,4)
LOG: Skipping BLOCKED tile at (2,4)                                 . LOG: Skipping BLOCKED tile at (2,4)
LOG: Skipping FOUND tile at (1,3)                                   . LOG: Skipping FOUND tile at (1,3)
LOG: Found tile at (1,5) with len 4 path: EEEE                      . LOG: Found tile at (1,5) with len 4 path: EEEE
LOG: maze state after BFS step                                      . LOG: maze state after BFS step
###########:  0                                                     . ###########:  0
#01234   ##:  1                                                     . #01234   ##:  1
#1### ## ##:  2                                                     . #1### ## ##:  2
#2### ## ##:  3                                                     . #2### ## ##:  3
#3###E## ##:  4                                                     . #3###E## ##:  4
#4       ##:  5                                                     . #4       ##:  5
###########:  6                                                     . ###########:  6
01234567890                                                         . 01234567890
0         1                                                         . 0         1
queue count: 2                                                      . queue count: 2
NN ROW COL                                                          . NN ROW COL
 0   5   1                                                          .  0   5   1
 1   1   5                                                          .  1   1   5
LOG: BFS STEP 8                                                     . LOG: BFS STEP 8
LOG: processing neighbors of (5,1)                                  . LOG: processing neighbors of (5,1)
LOG: Skipping FOUND tile at (4,1)                                   . LOG: Skipping FOUND tile at (4,1)
LOG: Skipping BLOCKED tile at (6,1)                                 . LOG: Skipping BLOCKED tile at (6,1)
LOG: Skipping BLOCKED tile at (5,0)                                 . LOG: Skipping BLOCKED tile at (5,0)
LOG: Found tile at (5,2) with len 5 path: SSSSE                     . LOG: Found tile at (5,2) with len 5 path: SSSSE
LOG: maze state after BFS step                                      . LOG: maze state after BFS step
###########:  0                                                     . ###########:  0
#01234   ##:  1                                                     . #01234   ##:  1
#1### ## ##:  2                                                     . #1### ## ##:  2
#2### ## ##:  3                                                     . #2### ## ##:  3
#3###E## ##:  4                                                     . #3###E## ##:  4
#45      ##:  5                                                     . #45      ##:  5
###########:  6                                                     . ###########:  6
01234567890                                                         . 01234567890
0         1                                                         . 0         1
queue count: 2                                                      . queue count: 2
NN ROW COL                                                          . NN ROW COL
 0   1   5                                                          .  0   1   5
 1   5   2                                                          .  1   5   2
LOG: BFS STEP 9                                                     . LOG: BFS STEP 9
LOG: processing neighbors of (1,5)                                  . LOG: processing neighbors of (1,5)
LOG: Skipping BLOCKED tile at (0,5)                                 . LOG: Skipping BLOCKED tile at (0,5)
LOG: Found tile at (2,5) with len 5 path: EEEES                     . LOG: Found tile at (2,5) with len 5 path: EEEES
LOG: Skipping FOUND tile at (1,4)                                   . LOG: Skipping FOUND tile at (1,4)
LOG: Found tile at (1,6) with len 5 path: EEEEE                     . LOG: Found tile at (1,6) with len 5 path: EEEEE
LOG: maze state after BFS step                                      . LOG: maze state after BFS step
###########:  0                                                     . ###########:  0
#012345  ##:  1                                                     . #012345  ##:  1
#1###5## ##:  2                                                     . #1###5## ##:  2
#2### ## ##:  3                                                     . #2### ## ##:  3
#3###E## ##:  4                                                     . #3###E## ##:  4
#45      ##:  5                                                     . #45      ##:  5
###########:  6                                                     . ###########:  6
01234567890                                                         . 01234567890
0         1                                                         . 0         1
queue count: 3                                                      . queue count: 3
NN ROW COL                                                          . NN ROW COL
 0   5   2                                                          .  0   5   2
 1   2   5                                                          .  1   2   5
 2   1   6                                                          .  2   1   6
LOG: BFS STEP 10                                                    . LOG: BFS STEP 10
LOG: processing neighbors of (5,2)                                  . LOG: processing neighbors of (5,2)
LOG: Skipping BLOCKED tile at (4,2)                                 . LOG: Skipping BLOCKED tile at (4,2)
LOG: Skipping BLOCKED tile at (6,2)                                 . LOG: Skipping BLOCKED tile at (6,2)
LOG: Skipping FOUND tile at (5,1)                                   . LOG: Skipping FOUND tile at (5,1)
LOG: Found tile at (5,3) with len 6 path: SSSSEE                    . LOG: Found tile at (5,3) with len 6 path: SSSSEE
LOG: maze state after BFS step                                      . LOG: maze state after BFS step
###########:  0                                                     . ###########:  0
#012345  ##:  1                                                     . #012345  ##:  1
#1###5## ##:  2                                                     . #1###5## ##:  2
#2### ## ##:  3                                                     . #2### ## ##:  3
#3###E## ##:  4                                                     . #3###E## ##:  4
#456     ##:  5                                                     . #456     ##:  5
###########:  6                                                     . ###########:  6
01234567890                                                         . 01234567890
0         1                                                         . 0         1
queue count: 3                                                      . queue count: 3
NN ROW COL                                                          . NN ROW COL
 0   2   5                                                          .  0   2   5
 1   1   6                                                          .  1   1   6
 2   5   3                                                          .  2   5   3
LOG: BFS STEP 11                                                    . LOG: BFS STEP 11
LOG: processing neighbors of (2,5)                                  . LOG: processing neighbors of (2,5)
LOG: Skipping FOUND tile at (1,5)                                   . LOG: Skipping FOUND tile at (1,5)
LOG: Found tile at (3,5) with len 6 path: EEEESS                    . LOG: Found tile at (3,5) with len 6 path: EEEESS
LOG: Skipping BLOCKED tile at (2,4)                                 . LOG: Skipping BLOCKED tile at (2,4)
LOG: Skipping BLOCKED tile at (2,6)                                 . LOG: Skipping BLOCKED tile at (2,6)
LOG: maze state after BFS step                                      . LOG: maze state after BFS step
###########:  0                                                     . ###########:  0
#012345  ##:  1                                                     . #012345  ##:  1
#1###5## ##:  2                                                     . #1###5## ##:  2
#2###6## ##:  3                                                     . #2###6## ##:  3
#3###E## ##:  4                                                     . #3###E## ##:  4
#456     ##:  5                                                     . #456     ##:  5
###########:  6                                                     . ###########:  6
01234567890                                                         . 01234567890
0         1                                                         . 0         1
queue count: 3                                                      . queue count: 3
NN ROW COL                                                          . NN ROW COL
 0   1   6                                                          .  0   1   6
 1   5   3                                                          .  1   5   3
 2   3   5                                                          .  2   3   5
LOG: BFS STEP 12                                                    . LOG: BFS STEP 12
LOG: processing neighbors of (1,6)                                  . LOG: processing neighbors of (1,6)
LOG: Skipping BLOCKED tile at (0,6)                                 . LOG: Skipping BLOCKED tile at (0,6)
LOG: Skipping BLOCKED tile at (2,6)                                 . LOG: Skipping BLOCKED tile at (2,6)
LOG: Skipping FOUND tile at (1,5)                                   . LOG: Skipping FOUND tile at (1,5)
LOG: Found tile at (1,7) with len 6 path: EEEEEE                    . LOG: Found tile at (1,7) with len 6 path: EEEEEE
LOG: maze state after BFS step                                      . LOG: maze state after BFS step
###########:  0                                                     . ###########:  0
#0123456 ##:  1                                                     . #0123456 ##:  1
#1###5## ##:  2                                                     . #1###5## ##:  2
#2###6## ##:  3                                                     . #2###6## ##:  3
#3###E## ##:  4                                                     . #3###E## ##:  4
#456     ##:  5                                                     . #456     ##:  5
###########:  6                                                     . ###########:  6
01234567890                                                         . 01234567890
0         1                                                         . 0         1
queue count: 3                                                      . queue count: 3
NN ROW COL                                                          . NN ROW COL
 0   5   3                                                          .  0   5   3
 1   3   5                                                          .  1   3   5
 2   1   7                                                          .  2   1   7
LOG: BFS STEP 13                                                    . LOG: BFS STEP 13
LOG: processing neighbors of (5,3)                                  . LOG: processing neighbors of (5,3)
LOG: Skipping BLOCKED tile at (4,3)                                 . LOG: Skipping BLOCKED tile at (4,3)
LOG: Skipping BLOCKED tile at (6,3)                                 . LOG: Skipping BLOCKED tile at (6,3)
LOG: Skipping FOUND tile at (5,2)                                   . LOG: Skipping FOUND tile at (5,2)
LOG: Found tile at (5,4) with len 7 path: SSSSEEE                   . LOG: Found tile at (5,4) with len 7 path: SSSSEEE
LOG: maze state after BFS step                                      . LOG: maze state after BFS step
###########:  0                                                     . ###########:  0
#0123456 ##:  1                                                     . #0123456 ##:  1
#1###5## ##:  2                                                     . #1###5## ##:  2
#2###6## ##:  3                                                     . #2###6## ##:  3
#3###E## ##:  4                                                     . #3###E## ##:  4
#4567    ##:  5                                                     . #4567    ##:  5
###########:  6                                                     . ###########:  6
01234567890                                                         . 01234567890
0         1                                                         . 0         1
queue count: 3                                                      . queue count: 3
NN ROW COL                                                          . NN ROW COL
 0   3   5                                                          .  0   3   5
 1   1   7                                                          .  1   1   7
 2   5   4                                                          .  2   5   4
LOG: BFS STEP 14                                                    . LOG: BFS STEP 14
LOG: processing neighbors of (3,5)                                  . LOG: processing neighbors of (3,5)
LOG: Skipping FOUND tile at (2,5)                                   . LOG: Skipping FOUND tile at (2,5)
LOG: Found tile at (4,5) with len 7 path: EEEESSS                   . LOG: Found tile at (4,5) with len 7 path: EEEESSS
LOG: Skipping BLOCKED tile at (3,4)                                 . LOG: Skipping BLOCKED tile at (3,4)
LOG: Skipping BLOCKED tile at (3,6)                                 . LOG: Skipping BLOCKED tile at (3,6)
LOG: maze state after BFS step                                      . LOG: maze state after BFS step
###########:  0                                                     . ###########:  0
#0123456 ##:  1                                                     . #0123456 ##:  1
#1###5## ##:  2                                                     . #1###5## ##:  2
#2###6## ##:  3                                                     . #2###6## ##:  3
#3###7## ##:  4                                                     . #3###7## ##:  4
#4567    ##:  5                                                     . #4567    ##:  5
###########:  6                                                     . ###########:  6
01234567890                                                         . 01234567890
0         1                                                         . 0         1
queue count: 3                                                      . queue count: 3
NN ROW COL                                                          . NN ROW COL
 0   1   7                                                          .  0   1   7
 1   5   4                                                          .  1   5   4
 2   4   5                                                          .  2   4   5
LOG: BFS STEP 15                                                    . LOG: BFS STEP 15
LOG: processing neighbors of (1,7)                                  . LOG: processing neighbors of (1,7)
LOG: Skipping BLOCKED tile at (0,7)                                 . LOG: Skipping BLOCKED tile at (0,7)
LOG: Skipping BLOCKED tile at (2,7)                                 . LOG: Skipping BLOCKED tile at (2,7)
LOG: Skipping FOUND tile at (1,6)                                   . LOG: Skipping FOUND tile at (1,6)
LOG: Found tile at (1,8) with len 7 path: EEEEEEE                   . LOG: Found tile at (1,8) with len 7 path: EEEEEEE
LOG: maze state after BFS step                                      . LOG: maze state after BFS step
###########:  0                                                     . ###########:  0
#01234567##:  1                                                     . #01234567##:  1
#1###5## ##:  2                                                     . #1###5## ##:  2
#2###6## ##:  3                                                     . #2###6## ##:  3
#3###7## ##:  4                                                     . #3###7## ##:  4
#4567    ##:  5                                                     . #4567    ##:  5
###########:  6                                                     . ###########:  6
01234567890                                                         . 01234567890
0         1                                                         . 0         1
queue count: 3                                                      . queue count: 3
NN ROW COL                                                          . NN ROW COL
 0   5   4                                                          .  0   5   4
 1   4   5                                                          .  1   4   5
 2   1   8                                                          .  2   1   8
LOG: BFS STEP 16                                                    . LOG: BFS STEP 16
LOG: processing neighbors of (5,4)                                  . LOG: processing neighbors of (5,4)
LOG: Skipping BLOCKED tile at (4,4)                                 . LOG: Skipping BLOCKED tile at (4,4)
LOG: Skipping BLOCKED tile at (6,4)                                 . LOG: Skipping BLOCKED tile at (6,4)
LOG: Skipping FOUND tile at (5,3)                                   . LOG: Skipping FOUND tile at (5,3)
LOG: Found tile at (5,5) with len 8 path: SSSSEEEE                  . LOG: Found tile at (5,5) with len 8 path: SSSSEEEE
LOG: maze state after BFS step                                      . LOG: maze state after BFS step
###########:  0                                                     . ###########:  0
#01234567##:  1                                                     . #01234567##:  1
#1###5## ##:  2                                                     . #1###5## ##:  2
#2###6## ##:  3                                                     . #2###6## ##:  3
#3###7## ##:  4                                                     . #3###7## ##:  4
#45678   ##:  5                                                     . #45678   ##:  5
###########:  6                                                     . ###########:  6
01234567890                                                         . 01234567890
0         1                                                         . 0         1
queue count: 3                                                      . queue count: 3
NN ROW COL                                                          . NN ROW COL
 0   4   5                                                          .  0   4   5
 1   1   8                                                          .  1   1   8
 2   5   5                                                          .  2   5   5
LOG: BFS STEP 17                                                    . LOG: BFS STEP 17
LOG: processing neighbors of (4,5)                                  . LOG: processing neighbors of (4,5)
LOG: Skipping FOUND tile at (3,5)                                   . LOG: Skipping FOUND tile at (3,5)
LOG: Skipping FOUND tile at (5,5)                                   . LOG: Skipping FOUND tile at (5,5)
LOG: Skipping BLOCKED tile at (4,4)                                 . LOG: Skipping BLOCKED tile at (4,4)
LOG: Skipping BLOCKED tile at (4,6)                                 . LOG: Skipping BLOCKED tile at (4,6)
LOG: maze state after BFS step                                      . LOG: maze state after BFS step
###########:  0                                                     . ###########:  0
#01234567##:  1                                                     . #01234567##:  1
#1###5## ##:  2                                                     . #1###5## ##:  2
#2###6## ##:  3                                                     . #2###6## ##:  3
#3###7## ##:  4                                                     . #3###7## ##:  4
#45678   ##:  5                                                     . #45678   ##:  5
###########:  6                                                     . ###########:  6
01234567890                                                         . 01234567890
0         1                                                         . 0         1
queue count: 2                                                      . queue count: 2
NN ROW COL                                                          . NN ROW COL
 0   1   8                                                          .  0   1   8
 1   5   5                                                          .  1   5   5
LOG: BFS STEP 18                                                    . LOG: BFS STEP 18
LOG: processing neighbors of (1,8)                                  . LOG: processing neighbors of (1,8)
LOG: Skipping BLOCKED tile at (0,8)                                 . LOG: Skipping BLOCKED tile at (0,8)
LOG: Found tile at (2,8) with len 8 path: EEEEEEES                  . LOG: Found tile at (2,8) with len 8 path: EEEEEEES
LOG: Skipping FOUND tile at (1,7)                                   . LOG: Skipping FOUND tile at (1,7)
LOG: Skipping BLOCKED tile at (1,9)                                 . LOG: Skipping BLOCKED tile at (1,9)
LOG: maze state after BFS step                                      . LOG: maze state after BFS step
###########:  0                                                     . ###########:  0
#01234567##:  1                                                     . #01234567##:  1
#1###5##8##:  2                                                     . #1###5##8##:  2
#2###6## ##:  3                                                     . #2###6## ##:  3
#3###7## ##:  4                                                     . #3###7## ##:  4
#45678   ##:  5                                                     . #45678   ##:  5
###########:  6                                                     . ###########:  6
01234567890                                                         . 01234567890
0         1                                                         . 0         1
queue count: 2                                                      . queue count: 2
NN ROW COL                                                          . NN ROW COL
 0   5   5                                                          .  0   5   5
 1   2   8                                                          .  1   2   8
LOG: BFS STEP 19                                                    . LOG: BFS STEP 19
LOG: processing neighbors of (5,5)                                  . LOG: processing neighbors of (5,5)
LOG: Skipping FOUND tile at (4,5)                                   . LOG: Skipping FOUND tile at (4,5)
LOG: Skipping BLOCKED tile at (6,5)                                 . LOG: Skipping BLOCKED tile at (6,5)
LOG: Skipping FOUND tile at (5,4)                                   . LOG: Skipping FOUND tile at (5,4)
LOG: Found tile at (5,6) with len 9 path: SSSSEEEEE                 . LOG: Found tile at (5,6) with len 9 path: SSSSEEEEE
LOG: maze state after BFS step                                      . LOG: maze state after BFS step
###########:  0                                                     . ###########:  0
#01234567##:  1                                                     . #01234567##:  1
#1###5##8##:  2                                                     . #1###5##8##:  2
#2###6## ##:  3                                                     . #2###6## ##:  3
#3###7## ##:  4                                                     . #3###7## ##:  4
#456789  ##:  5                                                     . #456789  ##:  5
###########:  6                                                     . ###########:  6
01234567890                                                         . 01234567890
0         1                                                         . 0         1
queue count: 2                                                      . queue count: 2
NN ROW COL                                                          . NN ROW COL
 0   2   8                                                          .  0   2   8
 1   5   6                                                          .  1   5   6
LOG: BFS STEP 20                                                    . LOG: BFS STEP 20
LOG: processing neighbors of (2,8)                                  . LOG: processing neighbors of (2,8)
LOG: Skipping FOUND tile at (1,8)                                   . LOG: Skipping FOUND tile at (1,8)
LOG: Found tile at (3,8) with len 9 path: EEEEEEESS                 . LOG: Found tile at (3,8) with len 9 path: EEEEEEESS
LOG: Skipping BLOCKED tile at (2,7)                                 . LOG: Skipping BLOCKED tile at (2,7)
LOG: Skipping BLOCKED tile at (2,9)                                 . LOG: Skipping BLOCKED tile at (2,9)
LOG: maze state after BFS step                                      . LOG: maze state after BFS step
###########:  0                                                     . ###########:  0
#01234567##:  1                                                     . #01234567##:  1
#1###5##8##:  2                                                     . #1###5##8##:  2
#2###6##9##:  3                                                     . #2###6##9##:  3
#3###7## ##:  4                                                     . #3###7## ##:  4
#456789  ##:  5                                                     . #456789  ##:  5
###########:  6                                                     . ###########:  6
01234567890                                                         . 01234567890
0         1                                                         . 0         1
queue count: 2                                                      . queue count: 2
NN ROW COL                                                          . NN ROW COL
 0   5   6                                                          .  0   5   6
 1   3   8                                                          .  1   3   8
LOG: BFS STEP 21                                                    . LOG: BFS STEP 21
LOG: processing neighbors of (5,6)                                  . LOG: processing neighbors of (5,6)
LOG: Skipping BLOCKED tile at (4,6)                                 . LOG: Skipping BLOCKED tile at (4,6)
LOG: Skipping BLOCKED tile at (6,6)                                 . LOG: Skipping BLOCKED tile at (6,6)
LOG: Skipping FOUND tile at (5,5)                                   . LOG: Skipping FOUND tile at (5,5)
LOG: Found tile at (5,7) with len 10 path: SSSSEEEEEE               . LOG: Found tile at (5,7) with len 10 path: SSSSEEEEEE
LOG: maze state after BFS step                                      . LOG: maze state after BFS step
###########:  0                                                     . ###########:  0
#01234567##:  1                                                     . #01234567##:  1
#1###5##8##:  2                                                     . #1###5##8##:  2
#2###6##9##:  3                                                     . #2###6##9##:  3
#3###7## ##:  4                                                     . #3###7## ##:  4
#456789a ##:  5                                                     . #456789a ##:  5
###########:  6                                                     . ###########:  6
01234567890                                                         . 01234567890
0         1                                                         . 0         1
queue count: 2                                                      . queue count: 2
NN ROW COL                                                          . NN ROW COL
 0   3   8                                                          .  0   3   8
 1   5   7                                                          .  1   5   7
LOG: BFS STEP 22                                                    . LOG: BFS STEP 22
LOG: processing neighbors of (3,8)                                  . LOG: processing neighbors of (3,8)
LOG: Skipping FOUND tile at (2,8)                                   . LOG: Skipping FOUND tile at (2,8)
LOG: Found tile at (4,8) with len 10 path: EEEEEEESSS               . LOG: Found tile at (4,8) with len 10 path: EEEEEEESSS
LOG: Skipping BLOCKED tile at (3,7)                                 . LOG: Skipping BLOCKED tile at (3,7)
LOG: Skipping BLOCKED tile at (3,9)                                 . LOG: Skipping BLOCKED tile at (3,9)
LOG: maze state after BFS step                                      . LOG: maze state after BFS step
###########:  0                                                     . ###########:  0
#01234567##:  1                                                     . #01234567##:  1
#1###5##8##:  2                                                     . #1###5##8##:  2
#2###6##9##:  3                                                     . #2###6##9##:  3
#3###7##a##:  4                                                     . #3###7##a##:  4
#456789a ##:  5                                                     . #456789a ##:  5
###########:  6                                                     . ###########:  6
01234567890                                                         . 01234567890
0         1                                                         . 0         1
queue count: 2                                                      . queue count: 2
NN ROW COL                                                          . NN ROW COL
 0   5   7                                                          .  0   5   7
 1   4   8                                                          .  1   4   8
LOG: BFS STEP 23                                                    . LOG: BFS STEP 23
LOG: processing neighbors of (5,7)                                  . LOG: processing neighbors of (5,7)
LOG: Skipping BLOCKED tile at (4,7)                                 . LOG: Skipping BLOCKED tile at (4,7)
LOG: Skipping BLOCKED tile at (6,7)                                 . LOG: Skipping BLOCKED tile at (6,7)
LOG: Skipping FOUND tile at (5,6)                                   . LOG: Skipping FOUND tile at (5,6)
LOG: Found tile at (5,8) with len 11 path: SSSSEEEEEEE              . LOG: Found tile at (5,8) with len 11 path: SSSSEEEEEEE
LOG: maze state after BFS step                                      . LOG: maze state after BFS step
###########:  0                                                     . ###########:  0
#01234567##:  1                                                     . #01234567##:  1
#1###5##8##:  2                                                     . #1###5##8##:  2
#2###6##9##:  3                                                     . #2###6##9##:  3
#3###7##a##:  4                                                     . #3###7##a##:  4
#456789a1##:  5                                                     . #456789a1##:  5
###########:  6                                                     . ###########:  6
01234567890                                                         . 01234567890
0         1                                                         . 0         1
queue count: 2                                                      . queue count: 2
NN ROW COL                                                          . NN ROW COL
 0   4   8                                                          .  0   4   8
 1   5   8                                                          .  1   5   8
LOG: BFS STEP 24                                                    . LOG: BFS STEP 24
LOG: processing neighbors of (4,8)                                  . LOG: processing neighbors of (4,8)
LOG: Skipping FOUND tile at (3,8)                                   . LOG: Skipping FOUND tile at (3,8)
LOG: Skipping FOUND tile at (5,8)                                   . LOG: Skipping FOUND tile at (5,8)
LOG: Skipping BLOCKED tile at (4,7)                                 . LOG: Skipping BLOCKED tile at (4,7)
LOG: Skipping BLOCKED tile at (4,9)                                 . LOG: Skipping BLOCKED tile at (4,9)
LOG: maze state after BFS step                                      . LOG: maze state after BFS step
###########:  0                                                     . ###########:  0
#01234567##:  1                                                     . #01234567##:  1
#1###5##8##:  2                                                     . #1###5##8##:  2
#2###6##9##:  3                                                     . #2###6##9##:  3
#3###7##a##:  4                                                     . #3###7##a##:  4
#456789a1##:  5                                                     . #456789a1##:  5
###########:  6                                                     . ###########:  6
01234567890                                                         . 01234567890
0         1                                                         . 0         1
queue count: 1                                                      . queue count: 1
NN ROW COL                                                          . NN ROW COL
 0   5   8                                                          .  0   5   8
LOG: BFS STEP 25                                                    . LOG: BFS STEP 25
LOG: processing neighbors of (5,8)                                  . LOG: processing neighbors of (5,8)
LOG: Skipping FOUND tile at (4,8)                                   . LOG: Skipping FOUND tile at (4,8)
LOG: Skipping BLOCKED tile at (6,8)                                 . LOG: Skipping BLOCKED tile at (6,8)
LOG: Skipping FOUND tile at (5,7)                                   . LOG: Skipping FOUND tile at (5,7)
LOG: Skipping BLOCKED tile at (5,9)                                 . LOG: Skipping BLOCKED tile at (5,9)
LOG: maze state after BFS step                                      . LOG: maze state after BFS step
###########:  0                                                     . ###########:  0
#01234567##:  1                                                     . #01234567##:  1
#1###5##8##:  2                                                     . #1###5##8##:  2
#2###6##9##:  3                                                     . #2###6##9##:  3
#3###7##a##:  4                                                     . #3###7##a##:  4
#456789a1##:  5                                                     . #456789a1##:  5
###########:  6                                                     . ###########:  6
01234567890                                                         . 01234567890
0         1                                                         . 0         1
queue count: 0                                                      . queue count: 0
NN ROW COL                                                          . NN ROW COL
Maze AFTER BFS iteration                                            . Maze AFTER BFS iteration
###########:  0                                                     . ###########:  0
#01234567##:  1                                                     . #01234567##:  1
#1###5##8##:  2                                                     . #1###5##8##:  2
#2###6##9##:  3                                                     . #2###6##9##:  3
#3###7##a##:  4                                                     . #3###7##a##:  4
#456789a1##:  5                                                     . #456789a1##:  5
###########:  6                                                     . ###########:  6
01234567890                                                         . 01234567890
0         1                                                         . 0         1
queue count: 0                                                      . queue count: 0
NN ROW COL                                                          . NN ROW COL
Maze BEFORE Setting Solution                                        . Maze BEFORE Setting Solution
maze: 7 rows 11 cols                                                . maze: 7 rows 11 cols
      (1,1) start                                                   .       (1,1) start
      (4,5) end                                                     .       (4,5) end
maze tiles:                                                         . maze tiles:
###########                                                         . ###########
#S       ##                                                         . #S       ##
# ### ## ##                                                         . # ### ## ##
# ### ## ##                                                         . # ### ## ##
# ###E## ##                                                         . # ###E## ##
#        ##                                                         . #        ##
###########                                                         . ###########
                                                                    ) 
Setting Solution Path                                               . Setting Solution Path
LOG: solution START at (1,1)                                        . LOG: solution START at (1,1)
LOG: solution path[0] is EAST, set (1,2) to ONPATH                  . LOG: solution path[0] is EAST, set (1,2) to ONPATH
LOG: solution path[1] is EAST, set (1,3) to ONPATH                  . LOG: solution path[1] is EAST, set (1,3) to ONPATH
LOG: solution path[2] is EAST, set (1,4) to ONPATH                  . LOG: solution path[2] is EAST, set (1,4) to ONPATH
LOG: solution path[3] is EAST, set (1,5) to ONPATH                  . LOG: solution path[3] is EAST, set (1,5) to ONPATH
LOG: solution path[4] is SOUTH, set (2,5) to ONPATH                 . LOG: solution path[4] is SOUTH, set (2,5) to ONPATH
LOG: solution path[5] is SOUTH, set (3,5) to ONPATH                 . LOG: solution path[5] is SOUTH, set (3,5) to ONPATH
LOG: solution path[6] is SOUTH, set (4,5) to ONPATH                 . LOG: solution path[6] is SOUTH, set (4,5) to ONPATH
LOG: solution END at (4,5)                                          . LOG: solution END at (4,5)
ret: 1                                                              . ret: 1
Maze AFTER Setting Solution                                         . Maze AFTER Setting Solution
maze: 7 rows 11 cols                                                . maze: 7 rows 11 cols
      (1,1) start                                                   .       (1,1) start
      (4,5) end                                                     .       (4,5) end
maze tiles:                                                         . maze tiles:
###########                                                         . ###########
#S....   ##                                                         . #S....   ##
# ###.## ##                                                         . # ###.## ##
# ###.## ##                                                         . # ###.## ##
# ###E## ##                                                         . # ###E## ##
#        ##                                                         . #        ##
###########                                                         . ###########
                                                                    ) 

```

LINE-BY-LINE DIFF of Expected vs Actual
---------------------------------------
No differences found

VALGRIND REPORT
---------------
The program is run on under valgrind as
  stdbuf -i 0 -o 0 -e 0 valgrind --error-exitcode=13 --leak-check=full --show-leak-kinds=all --track-origins=yes ./test_mazesolve_funcs maze_bfs_complete1
which may be pasted onto a command line to run it.

```
==15554== Memcheck, a memory error detector
==15554== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==15554== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==15554== Command: ./test_mazesolve_funcs maze_bfs_complete1
==15554== 
==15554== 
==15554== HEAP SUMMARY:
==15554==     in use at exit: 0 bytes in 0 blocks
==15554==   total heap usage: 60 allocs, 60 frees, 2,928 bytes allocated
==15554== 
==15554== All heap blocks were freed -- no leaks are possible
==15554== 
==15554== For lists of detected and suppressed errors, rerun with: -s
==15554== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

SUMMARY
-------
Test Passed
