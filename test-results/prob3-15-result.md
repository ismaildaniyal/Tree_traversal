(TEST 15) maze_bfs_complete2 : ok
=================================

COMMENTS
--------


PROGRAM: ./test_mazesolve_funcs maze_bfs_complete2
--------------------------------------------------
To run this individual test in GDB use the command:
  gdb --args ./test_mazesolve_funcs maze_bfs_complete2
but any input to the program must be typed within the debugger

FAILURE MESSAGES
----------------
None

SIDE-BY-SIDE DIFF of Expected vs Actual
---------------------------------------
. lines match; | lines differ; < expected line missing; > extra line in actual

```sdiff
===EXPECT===                                                          ===ACTUAL===
IF_TEST("maze_bfs_complete2") {                                     . IF_TEST("maze_bfs_complete2") {
    // Perform BFS iteration on a medium maze then set the solution .     // Perform BFS iteration on a medium maze then set the solution
    // and print it. Represents similar flow to the main program.   .     // and print it. Represents similar flow to the main program.
    char *maze_str =                                                .     char *maze_str =
      "#########\n"                                                 .       "#########\n"
      "#    #  #\n"                                                 .       "#    #  #\n"
      "# ##S  ##\n"                                                 .       "# ##S  ##\n"
      "#  # ##E#\n"                                                 .       "#  # ##E#\n"
      "#       #\n"                                                 .       "#       #\n"
      "#########\n";                                                .       "#########\n";
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
#########:  0                                                       . #########:  0
#    #  #:  1                                                       . #    #  #:  1
# ##S  ##:  2                                                       . # ##S  ##:  2
#  # ##E#:  3                                                       . #  # ##E#:  3
#       #:  4                                                       . #       #:  4
#########:  5                                                       . #########:  5
012345678                                                           . 012345678
0                                                                   . 0        
null queue                                                          . null queue
LOG: BFS initialization complete                                    . LOG: BFS initialization complete
#########:  0                                                       . #########:  0
#    #  #:  1                                                       . #    #  #:  1
# ##0  ##:  2                                                       . # ##0  ##:  2
#  # ##E#:  3                                                       . #  # ##E#:  3
#       #:  4                                                       . #       #:  4
#########:  5                                                       . #########:  5
012345678                                                           . 012345678
0                                                                   . 0        
queue count: 1                                                      . queue count: 1
NN ROW COL                                                          . NN ROW COL
 0   2   4                                                          .  0   2   4
LOG: BFS STEP 1                                                     . LOG: BFS STEP 1
LOG: processing neighbors of (2,4)                                  . LOG: processing neighbors of (2,4)
LOG: Found tile at (1,4) with len 1 path: N                         . LOG: Found tile at (1,4) with len 1 path: N
LOG: Found tile at (3,4) with len 1 path: S                         . LOG: Found tile at (3,4) with len 1 path: S
LOG: Skipping BLOCKED tile at (2,3)                                 . LOG: Skipping BLOCKED tile at (2,3)
LOG: Found tile at (2,5) with len 1 path: E                         . LOG: Found tile at (2,5) with len 1 path: E
LOG: maze state after BFS step                                      . LOG: maze state after BFS step
#########:  0                                                       . #########:  0
#   1#  #:  1                                                       . #   1#  #:  1
# ##01 ##:  2                                                       . # ##01 ##:  2
#  #1##E#:  3                                                       . #  #1##E#:  3
#       #:  4                                                       . #       #:  4
#########:  5                                                       . #########:  5
012345678                                                           . 012345678
0                                                                   . 0        
queue count: 3                                                      . queue count: 3
NN ROW COL                                                          . NN ROW COL
 0   1   4                                                          .  0   1   4
 1   3   4                                                          .  1   3   4
 2   2   5                                                          .  2   2   5
LOG: BFS STEP 2                                                     . LOG: BFS STEP 2
LOG: processing neighbors of (1,4)                                  . LOG: processing neighbors of (1,4)
LOG: Skipping BLOCKED tile at (0,4)                                 . LOG: Skipping BLOCKED tile at (0,4)
LOG: Skipping FOUND tile at (2,4)                                   . LOG: Skipping FOUND tile at (2,4)
LOG: Found tile at (1,3) with len 2 path: NW                        . LOG: Found tile at (1,3) with len 2 path: NW
LOG: Skipping BLOCKED tile at (1,5)                                 . LOG: Skipping BLOCKED tile at (1,5)
LOG: maze state after BFS step                                      . LOG: maze state after BFS step
#########:  0                                                       . #########:  0
#  21#  #:  1                                                       . #  21#  #:  1
# ##01 ##:  2                                                       . # ##01 ##:  2
#  #1##E#:  3                                                       . #  #1##E#:  3
#       #:  4                                                       . #       #:  4
#########:  5                                                       . #########:  5
012345678                                                           . 012345678
0                                                                   . 0        
queue count: 3                                                      . queue count: 3
NN ROW COL                                                          . NN ROW COL
 0   3   4                                                          .  0   3   4
 1   2   5                                                          .  1   2   5
 2   1   3                                                          .  2   1   3
LOG: BFS STEP 3                                                     . LOG: BFS STEP 3
LOG: processing neighbors of (3,4)                                  . LOG: processing neighbors of (3,4)
LOG: Skipping FOUND tile at (2,4)                                   . LOG: Skipping FOUND tile at (2,4)
LOG: Found tile at (4,4) with len 2 path: SS                        . LOG: Found tile at (4,4) with len 2 path: SS
LOG: Skipping BLOCKED tile at (3,3)                                 . LOG: Skipping BLOCKED tile at (3,3)
LOG: Skipping BLOCKED tile at (3,5)                                 . LOG: Skipping BLOCKED tile at (3,5)
LOG: maze state after BFS step                                      . LOG: maze state after BFS step
#########:  0                                                       . #########:  0
#  21#  #:  1                                                       . #  21#  #:  1
# ##01 ##:  2                                                       . # ##01 ##:  2
#  #1##E#:  3                                                       . #  #1##E#:  3
#   2   #:  4                                                       . #   2   #:  4
#########:  5                                                       . #########:  5
012345678                                                           . 012345678
0                                                                   . 0        
queue count: 3                                                      . queue count: 3
NN ROW COL                                                          . NN ROW COL
 0   2   5                                                          .  0   2   5
 1   1   3                                                          .  1   1   3
 2   4   4                                                          .  2   4   4
LOG: BFS STEP 4                                                     . LOG: BFS STEP 4
LOG: processing neighbors of (2,5)                                  . LOG: processing neighbors of (2,5)
LOG: Skipping BLOCKED tile at (1,5)                                 . LOG: Skipping BLOCKED tile at (1,5)
LOG: Skipping BLOCKED tile at (3,5)                                 . LOG: Skipping BLOCKED tile at (3,5)
LOG: Skipping FOUND tile at (2,4)                                   . LOG: Skipping FOUND tile at (2,4)
LOG: Found tile at (2,6) with len 2 path: EE                        . LOG: Found tile at (2,6) with len 2 path: EE
LOG: maze state after BFS step                                      . LOG: maze state after BFS step
#########:  0                                                       . #########:  0
#  21#  #:  1                                                       . #  21#  #:  1
# ##012##:  2                                                       . # ##012##:  2
#  #1##E#:  3                                                       . #  #1##E#:  3
#   2   #:  4                                                       . #   2   #:  4
#########:  5                                                       . #########:  5
012345678                                                           . 012345678
0                                                                   . 0        
queue count: 3                                                      . queue count: 3
NN ROW COL                                                          . NN ROW COL
 0   1   3                                                          .  0   1   3
 1   4   4                                                          .  1   4   4
 2   2   6                                                          .  2   2   6
LOG: BFS STEP 5                                                     . LOG: BFS STEP 5
LOG: processing neighbors of (1,3)                                  . LOG: processing neighbors of (1,3)
LOG: Skipping BLOCKED tile at (0,3)                                 . LOG: Skipping BLOCKED tile at (0,3)
LOG: Skipping BLOCKED tile at (2,3)                                 . LOG: Skipping BLOCKED tile at (2,3)
LOG: Found tile at (1,2) with len 3 path: NWW                       . LOG: Found tile at (1,2) with len 3 path: NWW
LOG: Skipping FOUND tile at (1,4)                                   . LOG: Skipping FOUND tile at (1,4)
LOG: maze state after BFS step                                      . LOG: maze state after BFS step
#########:  0                                                       . #########:  0
# 321#  #:  1                                                       . # 321#  #:  1
# ##012##:  2                                                       . # ##012##:  2
#  #1##E#:  3                                                       . #  #1##E#:  3
#   2   #:  4                                                       . #   2   #:  4
#########:  5                                                       . #########:  5
012345678                                                           . 012345678
0                                                                   . 0        
queue count: 3                                                      . queue count: 3
NN ROW COL                                                          . NN ROW COL
 0   4   4                                                          .  0   4   4
 1   2   6                                                          .  1   2   6
 2   1   2                                                          .  2   1   2
LOG: BFS STEP 6                                                     . LOG: BFS STEP 6
LOG: processing neighbors of (4,4)                                  . LOG: processing neighbors of (4,4)
LOG: Skipping FOUND tile at (3,4)                                   . LOG: Skipping FOUND tile at (3,4)
LOG: Skipping BLOCKED tile at (5,4)                                 . LOG: Skipping BLOCKED tile at (5,4)
LOG: Found tile at (4,3) with len 3 path: SSW                       . LOG: Found tile at (4,3) with len 3 path: SSW
LOG: Found tile at (4,5) with len 3 path: SSE                       . LOG: Found tile at (4,5) with len 3 path: SSE
LOG: maze state after BFS step                                      . LOG: maze state after BFS step
#########:  0                                                       . #########:  0
# 321#  #:  1                                                       . # 321#  #:  1
# ##012##:  2                                                       . # ##012##:  2
#  #1##E#:  3                                                       . #  #1##E#:  3
#  323  #:  4                                                       . #  323  #:  4
#########:  5                                                       . #########:  5
012345678                                                           . 012345678
0                                                                   . 0        
queue count: 4                                                      . queue count: 4
NN ROW COL                                                          . NN ROW COL
 0   2   6                                                          .  0   2   6
 1   1   2                                                          .  1   1   2
 2   4   3                                                          .  2   4   3
 3   4   5                                                          .  3   4   5
LOG: BFS STEP 7                                                     . LOG: BFS STEP 7
LOG: processing neighbors of (2,6)                                  . LOG: processing neighbors of (2,6)
LOG: Found tile at (1,6) with len 3 path: EEN                       . LOG: Found tile at (1,6) with len 3 path: EEN
LOG: Skipping BLOCKED tile at (3,6)                                 . LOG: Skipping BLOCKED tile at (3,6)
LOG: Skipping FOUND tile at (2,5)                                   . LOG: Skipping FOUND tile at (2,5)
LOG: Skipping BLOCKED tile at (2,7)                                 . LOG: Skipping BLOCKED tile at (2,7)
LOG: maze state after BFS step                                      . LOG: maze state after BFS step
#########:  0                                                       . #########:  0
# 321#3 #:  1                                                       . # 321#3 #:  1
# ##012##:  2                                                       . # ##012##:  2
#  #1##E#:  3                                                       . #  #1##E#:  3
#  323  #:  4                                                       . #  323  #:  4
#########:  5                                                       . #########:  5
012345678                                                           . 012345678
0                                                                   . 0        
queue count: 4                                                      . queue count: 4
NN ROW COL                                                          . NN ROW COL
 0   1   2                                                          .  0   1   2
 1   4   3                                                          .  1   4   3
 2   4   5                                                          .  2   4   5
 3   1   6                                                          .  3   1   6
LOG: BFS STEP 8                                                     . LOG: BFS STEP 8
LOG: processing neighbors of (1,2)                                  . LOG: processing neighbors of (1,2)
LOG: Skipping BLOCKED tile at (0,2)                                 . LOG: Skipping BLOCKED tile at (0,2)
LOG: Skipping BLOCKED tile at (2,2)                                 . LOG: Skipping BLOCKED tile at (2,2)
LOG: Found tile at (1,1) with len 4 path: NWWW                      . LOG: Found tile at (1,1) with len 4 path: NWWW
LOG: Skipping FOUND tile at (1,3)                                   . LOG: Skipping FOUND tile at (1,3)
LOG: maze state after BFS step                                      . LOG: maze state after BFS step
#########:  0                                                       . #########:  0
#4321#3 #:  1                                                       . #4321#3 #:  1
# ##012##:  2                                                       . # ##012##:  2
#  #1##E#:  3                                                       . #  #1##E#:  3
#  323  #:  4                                                       . #  323  #:  4
#########:  5                                                       . #########:  5
012345678                                                           . 012345678
0                                                                   . 0        
queue count: 4                                                      . queue count: 4
NN ROW COL                                                          . NN ROW COL
 0   4   3                                                          .  0   4   3
 1   4   5                                                          .  1   4   5
 2   1   6                                                          .  2   1   6
 3   1   1                                                          .  3   1   1
LOG: BFS STEP 9                                                     . LOG: BFS STEP 9
LOG: processing neighbors of (4,3)                                  . LOG: processing neighbors of (4,3)
LOG: Skipping BLOCKED tile at (3,3)                                 . LOG: Skipping BLOCKED tile at (3,3)
LOG: Skipping BLOCKED tile at (5,3)                                 . LOG: Skipping BLOCKED tile at (5,3)
LOG: Found tile at (4,2) with len 4 path: SSWW                      . LOG: Found tile at (4,2) with len 4 path: SSWW
LOG: Skipping FOUND tile at (4,4)                                   . LOG: Skipping FOUND tile at (4,4)
LOG: maze state after BFS step                                      . LOG: maze state after BFS step
#########:  0                                                       . #########:  0
#4321#3 #:  1                                                       . #4321#3 #:  1
# ##012##:  2                                                       . # ##012##:  2
#  #1##E#:  3                                                       . #  #1##E#:  3
# 4323  #:  4                                                       . # 4323  #:  4
#########:  5                                                       . #########:  5
012345678                                                           . 012345678
0                                                                   . 0        
queue count: 4                                                      . queue count: 4
NN ROW COL                                                          . NN ROW COL
 0   4   5                                                          .  0   4   5
 1   1   6                                                          .  1   1   6
 2   1   1                                                          .  2   1   1
 3   4   2                                                          .  3   4   2
LOG: BFS STEP 10                                                    . LOG: BFS STEP 10
LOG: processing neighbors of (4,5)                                  . LOG: processing neighbors of (4,5)
LOG: Skipping BLOCKED tile at (3,5)                                 . LOG: Skipping BLOCKED tile at (3,5)
LOG: Skipping BLOCKED tile at (5,5)                                 . LOG: Skipping BLOCKED tile at (5,5)
LOG: Skipping FOUND tile at (4,4)                                   . LOG: Skipping FOUND tile at (4,4)
LOG: Found tile at (4,6) with len 4 path: SSEE                      . LOG: Found tile at (4,6) with len 4 path: SSEE
LOG: maze state after BFS step                                      . LOG: maze state after BFS step
#########:  0                                                       . #########:  0
#4321#3 #:  1                                                       . #4321#3 #:  1
# ##012##:  2                                                       . # ##012##:  2
#  #1##E#:  3                                                       . #  #1##E#:  3
# 43234 #:  4                                                       . # 43234 #:  4
#########:  5                                                       . #########:  5
012345678                                                           . 012345678
0                                                                   . 0        
queue count: 4                                                      . queue count: 4
NN ROW COL                                                          . NN ROW COL
 0   1   6                                                          .  0   1   6
 1   1   1                                                          .  1   1   1
 2   4   2                                                          .  2   4   2
 3   4   6                                                          .  3   4   6
LOG: BFS STEP 11                                                    . LOG: BFS STEP 11
LOG: processing neighbors of (1,6)                                  . LOG: processing neighbors of (1,6)
LOG: Skipping BLOCKED tile at (0,6)                                 . LOG: Skipping BLOCKED tile at (0,6)
LOG: Skipping FOUND tile at (2,6)                                   . LOG: Skipping FOUND tile at (2,6)
LOG: Skipping BLOCKED tile at (1,5)                                 . LOG: Skipping BLOCKED tile at (1,5)
LOG: Found tile at (1,7) with len 4 path: EENE                      . LOG: Found tile at (1,7) with len 4 path: EENE
LOG: maze state after BFS step                                      . LOG: maze state after BFS step
#########:  0                                                       . #########:  0
#4321#34#:  1                                                       . #4321#34#:  1
# ##012##:  2                                                       . # ##012##:  2
#  #1##E#:  3                                                       . #  #1##E#:  3
# 43234 #:  4                                                       . # 43234 #:  4
#########:  5                                                       . #########:  5
012345678                                                           . 012345678
0                                                                   . 0        
queue count: 4                                                      . queue count: 4
NN ROW COL                                                          . NN ROW COL
 0   1   1                                                          .  0   1   1
 1   4   2                                                          .  1   4   2
 2   4   6                                                          .  2   4   6
 3   1   7                                                          .  3   1   7
LOG: BFS STEP 12                                                    . LOG: BFS STEP 12
LOG: processing neighbors of (1,1)                                  . LOG: processing neighbors of (1,1)
LOG: Skipping BLOCKED tile at (0,1)                                 . LOG: Skipping BLOCKED tile at (0,1)
LOG: Found tile at (2,1) with len 5 path: NWWWS                     . LOG: Found tile at (2,1) with len 5 path: NWWWS
LOG: Skipping BLOCKED tile at (1,0)                                 . LOG: Skipping BLOCKED tile at (1,0)
LOG: Skipping FOUND tile at (1,2)                                   . LOG: Skipping FOUND tile at (1,2)
LOG: maze state after BFS step                                      . LOG: maze state after BFS step
#########:  0                                                       . #########:  0
#4321#34#:  1                                                       . #4321#34#:  1
#5##012##:  2                                                       . #5##012##:  2
#  #1##E#:  3                                                       . #  #1##E#:  3
# 43234 #:  4                                                       . # 43234 #:  4
#########:  5                                                       . #########:  5
012345678                                                           . 012345678
0                                                                   . 0        
queue count: 4                                                      . queue count: 4
NN ROW COL                                                          . NN ROW COL
 0   4   2                                                          .  0   4   2
 1   4   6                                                          .  1   4   6
 2   1   7                                                          .  2   1   7
 3   2   1                                                          .  3   2   1
LOG: BFS STEP 13                                                    . LOG: BFS STEP 13
LOG: processing neighbors of (4,2)                                  . LOG: processing neighbors of (4,2)
LOG: Found tile at (3,2) with len 5 path: SSWWN                     . LOG: Found tile at (3,2) with len 5 path: SSWWN
LOG: Skipping BLOCKED tile at (5,2)                                 . LOG: Skipping BLOCKED tile at (5,2)
LOG: Found tile at (4,1) with len 5 path: SSWWW                     . LOG: Found tile at (4,1) with len 5 path: SSWWW
LOG: Skipping FOUND tile at (4,3)                                   . LOG: Skipping FOUND tile at (4,3)
LOG: maze state after BFS step                                      . LOG: maze state after BFS step
#########:  0                                                       . #########:  0
#4321#34#:  1                                                       . #4321#34#:  1
#5##012##:  2                                                       . #5##012##:  2
# 5#1##E#:  3                                                       . # 5#1##E#:  3
#543234 #:  4                                                       . #543234 #:  4
#########:  5                                                       . #########:  5
012345678                                                           . 012345678
0                                                                   . 0        
queue count: 5                                                      . queue count: 5
NN ROW COL                                                          . NN ROW COL
 0   4   6                                                          .  0   4   6
 1   1   7                                                          .  1   1   7
 2   2   1                                                          .  2   2   1
 3   3   2                                                          .  3   3   2
 4   4   1                                                          .  4   4   1
LOG: BFS STEP 14                                                    . LOG: BFS STEP 14
LOG: processing neighbors of (4,6)                                  . LOG: processing neighbors of (4,6)
LOG: Skipping BLOCKED tile at (3,6)                                 . LOG: Skipping BLOCKED tile at (3,6)
LOG: Skipping BLOCKED tile at (5,6)                                 . LOG: Skipping BLOCKED tile at (5,6)
LOG: Skipping FOUND tile at (4,5)                                   . LOG: Skipping FOUND tile at (4,5)
LOG: Found tile at (4,7) with len 5 path: SSEEE                     . LOG: Found tile at (4,7) with len 5 path: SSEEE
LOG: maze state after BFS step                                      . LOG: maze state after BFS step
#########:  0                                                       . #########:  0
#4321#34#:  1                                                       . #4321#34#:  1
#5##012##:  2                                                       . #5##012##:  2
# 5#1##E#:  3                                                       . # 5#1##E#:  3
#5432345#:  4                                                       . #5432345#:  4
#########:  5                                                       . #########:  5
012345678                                                           . 012345678
0                                                                   . 0        
queue count: 5                                                      . queue count: 5
NN ROW COL                                                          . NN ROW COL
 0   1   7                                                          .  0   1   7
 1   2   1                                                          .  1   2   1
 2   3   2                                                          .  2   3   2
 3   4   1                                                          .  3   4   1
 4   4   7                                                          .  4   4   7
LOG: BFS STEP 15                                                    . LOG: BFS STEP 15
LOG: processing neighbors of (1,7)                                  . LOG: processing neighbors of (1,7)
LOG: Skipping BLOCKED tile at (0,7)                                 . LOG: Skipping BLOCKED tile at (0,7)
LOG: Skipping BLOCKED tile at (2,7)                                 . LOG: Skipping BLOCKED tile at (2,7)
LOG: Skipping FOUND tile at (1,6)                                   . LOG: Skipping FOUND tile at (1,6)
LOG: Skipping BLOCKED tile at (1,8)                                 . LOG: Skipping BLOCKED tile at (1,8)
LOG: maze state after BFS step                                      . LOG: maze state after BFS step
#########:  0                                                       . #########:  0
#4321#34#:  1                                                       . #4321#34#:  1
#5##012##:  2                                                       . #5##012##:  2
# 5#1##E#:  3                                                       . # 5#1##E#:  3
#5432345#:  4                                                       . #5432345#:  4
#########:  5                                                       . #########:  5
012345678                                                           . 012345678
0                                                                   . 0        
queue count: 4                                                      . queue count: 4
NN ROW COL                                                          . NN ROW COL
 0   2   1                                                          .  0   2   1
 1   3   2                                                          .  1   3   2
 2   4   1                                                          .  2   4   1
 3   4   7                                                          .  3   4   7
LOG: BFS STEP 16                                                    . LOG: BFS STEP 16
LOG: processing neighbors of (2,1)                                  . LOG: processing neighbors of (2,1)
LOG: Skipping FOUND tile at (1,1)                                   . LOG: Skipping FOUND tile at (1,1)
LOG: Found tile at (3,1) with len 6 path: NWWWSS                    . LOG: Found tile at (3,1) with len 6 path: NWWWSS
LOG: Skipping BLOCKED tile at (2,0)                                 . LOG: Skipping BLOCKED tile at (2,0)
LOG: Skipping BLOCKED tile at (2,2)                                 . LOG: Skipping BLOCKED tile at (2,2)
LOG: maze state after BFS step                                      . LOG: maze state after BFS step
#########:  0                                                       . #########:  0
#4321#34#:  1                                                       . #4321#34#:  1
#5##012##:  2                                                       . #5##012##:  2
#65#1##E#:  3                                                       . #65#1##E#:  3
#5432345#:  4                                                       . #5432345#:  4
#########:  5                                                       . #########:  5
012345678                                                           . 012345678
0                                                                   . 0        
queue count: 4                                                      . queue count: 4
NN ROW COL                                                          . NN ROW COL
 0   3   2                                                          .  0   3   2
 1   4   1                                                          .  1   4   1
 2   4   7                                                          .  2   4   7
 3   3   1                                                          .  3   3   1
LOG: BFS STEP 17                                                    . LOG: BFS STEP 17
LOG: processing neighbors of (3,2)                                  . LOG: processing neighbors of (3,2)
LOG: Skipping BLOCKED tile at (2,2)                                 . LOG: Skipping BLOCKED tile at (2,2)
LOG: Skipping FOUND tile at (4,2)                                   . LOG: Skipping FOUND tile at (4,2)
LOG: Skipping FOUND tile at (3,1)                                   . LOG: Skipping FOUND tile at (3,1)
LOG: Skipping BLOCKED tile at (3,3)                                 . LOG: Skipping BLOCKED tile at (3,3)
LOG: maze state after BFS step                                      . LOG: maze state after BFS step
#########:  0                                                       . #########:  0
#4321#34#:  1                                                       . #4321#34#:  1
#5##012##:  2                                                       . #5##012##:  2
#65#1##E#:  3                                                       . #65#1##E#:  3
#5432345#:  4                                                       . #5432345#:  4
#########:  5                                                       . #########:  5
012345678                                                           . 012345678
0                                                                   . 0        
queue count: 3                                                      . queue count: 3
NN ROW COL                                                          . NN ROW COL
 0   4   1                                                          .  0   4   1
 1   4   7                                                          .  1   4   7
 2   3   1                                                          .  2   3   1
LOG: BFS STEP 18                                                    . LOG: BFS STEP 18
LOG: processing neighbors of (4,1)                                  . LOG: processing neighbors of (4,1)
LOG: Skipping FOUND tile at (3,1)                                   . LOG: Skipping FOUND tile at (3,1)
LOG: Skipping BLOCKED tile at (5,1)                                 . LOG: Skipping BLOCKED tile at (5,1)
LOG: Skipping BLOCKED tile at (4,0)                                 . LOG: Skipping BLOCKED tile at (4,0)
LOG: Skipping FOUND tile at (4,2)                                   . LOG: Skipping FOUND tile at (4,2)
LOG: maze state after BFS step                                      . LOG: maze state after BFS step
#########:  0                                                       . #########:  0
#4321#34#:  1                                                       . #4321#34#:  1
#5##012##:  2                                                       . #5##012##:  2
#65#1##E#:  3                                                       . #65#1##E#:  3
#5432345#:  4                                                       . #5432345#:  4
#########:  5                                                       . #########:  5
012345678                                                           . 012345678
0                                                                   . 0        
queue count: 2                                                      . queue count: 2
NN ROW COL                                                          . NN ROW COL
 0   4   7                                                          .  0   4   7
 1   3   1                                                          .  1   3   1
LOG: BFS STEP 19                                                    . LOG: BFS STEP 19
LOG: processing neighbors of (4,7)                                  . LOG: processing neighbors of (4,7)
LOG: Found tile at (3,7) with len 6 path: SSEEEN                    . LOG: Found tile at (3,7) with len 6 path: SSEEEN
LOG: Skipping BLOCKED tile at (5,7)                                 . LOG: Skipping BLOCKED tile at (5,7)
LOG: Skipping FOUND tile at (4,6)                                   . LOG: Skipping FOUND tile at (4,6)
LOG: Skipping BLOCKED tile at (4,8)                                 . LOG: Skipping BLOCKED tile at (4,8)
LOG: maze state after BFS step                                      . LOG: maze state after BFS step
#########:  0                                                       . #########:  0
#4321#34#:  1                                                       . #4321#34#:  1
#5##012##:  2                                                       . #5##012##:  2
#65#1##6#:  3                                                       . #65#1##6#:  3
#5432345#:  4                                                       . #5432345#:  4
#########:  5                                                       . #########:  5
012345678                                                           . 012345678
0                                                                   . 0        
queue count: 2                                                      . queue count: 2
NN ROW COL                                                          . NN ROW COL
 0   3   1                                                          .  0   3   1
 1   3   7                                                          .  1   3   7
LOG: BFS STEP 20                                                    . LOG: BFS STEP 20
LOG: processing neighbors of (3,1)                                  . LOG: processing neighbors of (3,1)
LOG: Skipping FOUND tile at (2,1)                                   . LOG: Skipping FOUND tile at (2,1)
LOG: Skipping FOUND tile at (4,1)                                   . LOG: Skipping FOUND tile at (4,1)
LOG: Skipping BLOCKED tile at (3,0)                                 . LOG: Skipping BLOCKED tile at (3,0)
LOG: Skipping FOUND tile at (3,2)                                   . LOG: Skipping FOUND tile at (3,2)
LOG: maze state after BFS step                                      . LOG: maze state after BFS step
#########:  0                                                       . #########:  0
#4321#34#:  1                                                       . #4321#34#:  1
#5##012##:  2                                                       . #5##012##:  2
#65#1##6#:  3                                                       . #65#1##6#:  3
#5432345#:  4                                                       . #5432345#:  4
#########:  5                                                       . #########:  5
012345678                                                           . 012345678
0                                                                   . 0        
queue count: 1                                                      . queue count: 1
NN ROW COL                                                          . NN ROW COL
 0   3   7                                                          .  0   3   7
LOG: BFS STEP 21                                                    . LOG: BFS STEP 21
LOG: processing neighbors of (3,7)                                  . LOG: processing neighbors of (3,7)
LOG: Skipping BLOCKED tile at (2,7)                                 . LOG: Skipping BLOCKED tile at (2,7)
LOG: Skipping FOUND tile at (4,7)                                   . LOG: Skipping FOUND tile at (4,7)
LOG: Skipping BLOCKED tile at (3,6)                                 . LOG: Skipping BLOCKED tile at (3,6)
LOG: Skipping BLOCKED tile at (3,8)                                 . LOG: Skipping BLOCKED tile at (3,8)
LOG: maze state after BFS step                                      . LOG: maze state after BFS step
#########:  0                                                       . #########:  0
#4321#34#:  1                                                       . #4321#34#:  1
#5##012##:  2                                                       . #5##012##:  2
#65#1##6#:  3                                                       . #65#1##6#:  3
#5432345#:  4                                                       . #5432345#:  4
#########:  5                                                       . #########:  5
012345678                                                           . 012345678
0                                                                   . 0        
queue count: 0                                                      . queue count: 0
NN ROW COL                                                          . NN ROW COL
Maze AFTER BFS iteration                                            . Maze AFTER BFS iteration
#########:  0                                                       . #########:  0
#4321#34#:  1                                                       . #4321#34#:  1
#5##012##:  2                                                       . #5##012##:  2
#65#1##6#:  3                                                       . #65#1##6#:  3
#5432345#:  4                                                       . #5432345#:  4
#########:  5                                                       . #########:  5
012345678                                                           . 012345678
0                                                                   . 0        
queue count: 0                                                      . queue count: 0
NN ROW COL                                                          . NN ROW COL
Maze BEFORE Setting Solution                                        . Maze BEFORE Setting Solution
maze: 6 rows 9 cols                                                 . maze: 6 rows 9 cols
      (2,4) start                                                   .       (2,4) start
      (3,7) end                                                     .       (3,7) end
maze tiles:                                                         . maze tiles:
#########                                                           . #########
#    #  #                                                           . #    #  #
# ##S  ##                                                           . # ##S  ##
#  # ##E#                                                           . #  # ##E#
#       #                                                           . #       #
#########                                                           . #########
                                                                    ) 
Setting Solution Path                                               . Setting Solution Path
LOG: solution START at (2,4)                                        . LOG: solution START at (2,4)
LOG: solution path[0] is SOUTH, set (3,4) to ONPATH                 . LOG: solution path[0] is SOUTH, set (3,4) to ONPATH
LOG: solution path[1] is SOUTH, set (4,4) to ONPATH                 . LOG: solution path[1] is SOUTH, set (4,4) to ONPATH
LOG: solution path[2] is EAST, set (4,5) to ONPATH                  . LOG: solution path[2] is EAST, set (4,5) to ONPATH
LOG: solution path[3] is EAST, set (4,6) to ONPATH                  . LOG: solution path[3] is EAST, set (4,6) to ONPATH
LOG: solution path[4] is EAST, set (4,7) to ONPATH                  . LOG: solution path[4] is EAST, set (4,7) to ONPATH
LOG: solution path[5] is NORTH, set (3,7) to ONPATH                 . LOG: solution path[5] is NORTH, set (3,7) to ONPATH
LOG: solution END at (3,7)                                          . LOG: solution END at (3,7)
ret: 1                                                              . ret: 1
Maze AFTER Setting Solution                                         . Maze AFTER Setting Solution
maze: 6 rows 9 cols                                                 . maze: 6 rows 9 cols
      (2,4) start                                                   .       (2,4) start
      (3,7) end                                                     .       (3,7) end
maze tiles:                                                         . maze tiles:
#########                                                           . #########
#    #  #                                                           . #    #  #
# ##S  ##                                                           . # ##S  ##
#  #.##E#                                                           . #  #.##E#
#   ....#                                                           . #   ....#
#########                                                           . #########
                                                                    ) 

```

LINE-BY-LINE DIFF of Expected vs Actual
---------------------------------------
No differences found

VALGRIND REPORT
---------------
The program is run on under valgrind as
  stdbuf -i 0 -o 0 -e 0 valgrind --error-exitcode=13 --leak-check=full --show-leak-kinds=all --track-origins=yes ./test_mazesolve_funcs maze_bfs_complete2
which may be pasted onto a command line to run it.

```
==15556== Memcheck, a memory error detector
==15556== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==15556== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==15556== Command: ./test_mazesolve_funcs maze_bfs_complete2
==15556== 
==15556== 
==15556== HEAP SUMMARY:
==15556==     in use at exit: 0 bytes in 0 blocks
==15556==   total heap usage: 51 allocs, 51 frees, 2,024 bytes allocated
==15556== 
==15556== All heap blocks were freed -- no leaks are possible
==15556== 
==15556== For lists of detected and suppressed errors, rerun with: -s
==15556== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

SUMMARY
-------
Test Passed
