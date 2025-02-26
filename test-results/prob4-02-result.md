(TEST 2) maze_from_file_medium : ok
===================================

COMMENTS
--------


PROGRAM: ./test_mazesolve_funcs maze_from_file_medium
-----------------------------------------------------
To run this individual test in GDB use the command:
  gdb --args ./test_mazesolve_funcs maze_from_file_medium
but any input to the program must be typed within the debugger

FAILURE MESSAGES
----------------
None

SIDE-BY-SIDE DIFF of Expected vs Actual
---------------------------------------
. lines match; | lines differ; < expected line missing; > extra line in actual

```sdiff
===EXPECT===                                                            ===ACTUAL===
IF_TEST("maze_from_file_medium") {                                    . IF_TEST("maze_from_file_medium") {
    // Load a medium maze from a file AND perform BFS iteration on it .     // Load a medium maze from a file AND perform BFS iteration on it
    // then set the solution for display.                             .     // then set the solution for display.
    LOG_LEVEL = LOG_ALL;                                              .     LOG_LEVEL = LOG_ALL;
    maze_t *maze = maze_from_file("data/maze-medium1.txt");           .     maze_t *maze = maze_from_file("data/maze-medium1.txt");
    printf("LOADED MAZE:\n");                                         .     printf("LOADED MAZE:\n");
    maze_print_tiles(maze);                                           .     maze_print_tiles(maze);
    maze_bfs_iterate(maze);                                           .     maze_bfs_iterate(maze);
    printf("Maze AFTER BFS iteration\n");                             .     printf("Maze AFTER BFS iteration\n");
    maze_print_state(maze);                                           .     maze_print_state(maze);
    int ret = maze_set_solution(maze);                                .     int ret = maze_set_solution(maze);
    printf("ret: %d\n",ret);                                          .     printf("ret: %d\n",ret);
    printf("Maze AFTER Setting Solution\n");                          .     printf("Maze AFTER Setting Solution\n");
    maze_print_tiles(maze);                                           .     maze_print_tiles(maze);
    maze_free(maze);                                                  .     maze_free(maze);
}                                                                     . }
---OUTPUT---                                                          . ---OUTPUT---
LOG: expecting 10 rows and 8 columns                                  . LOG: expecting 10 rows and 8 columns
LOG: beginning to read tiles                                          . LOG: beginning to read tiles
LOG: (0,0) has character '#' type 1                                   . LOG: (0,0) has character '#' type 1
LOG: (0,1) has character '#' type 1                                   . LOG: (0,1) has character '#' type 1
LOG: (0,2) has character '#' type 1                                   . LOG: (0,2) has character '#' type 1
LOG: (0,3) has character '#' type 1                                   . LOG: (0,3) has character '#' type 1
LOG: (0,4) has character '#' type 1                                   . LOG: (0,4) has character '#' type 1
LOG: (0,5) has character '#' type 1                                   . LOG: (0,5) has character '#' type 1
LOG: (0,6) has character '#' type 1                                   . LOG: (0,6) has character '#' type 1
LOG: (0,7) has character '#' type 1                                   . LOG: (0,7) has character '#' type 1
LOG: finished reading row 0 of tiles                                  . LOG: finished reading row 0 of tiles
LOG: (1,0) has character '#' type 1                                   . LOG: (1,0) has character '#' type 1
LOG: (1,1) has character ' ' type 2                                   . LOG: (1,1) has character ' ' type 2
LOG: (1,2) has character ' ' type 2                                   . LOG: (1,2) has character ' ' type 2
LOG: (1,3) has character ' ' type 2                                   . LOG: (1,3) has character ' ' type 2
LOG: (1,4) has character ' ' type 2                                   . LOG: (1,4) has character ' ' type 2
LOG: (1,5) has character ' ' type 2                                   . LOG: (1,5) has character ' ' type 2
LOG: (1,6) has character 'S' type 4                                   . LOG: (1,6) has character 'S' type 4
LOG: setting START at (1,6)                                           . LOG: setting START at (1,6)
LOG: (1,7) has character '#' type 1                                   . LOG: (1,7) has character '#' type 1
LOG: finished reading row 1 of tiles                                  . LOG: finished reading row 1 of tiles
LOG: (2,0) has character '#' type 1                                   . LOG: (2,0) has character '#' type 1
LOG: (2,1) has character ' ' type 2                                   . LOG: (2,1) has character ' ' type 2
LOG: (2,2) has character '#' type 1                                   . LOG: (2,2) has character '#' type 1
LOG: (2,3) has character ' ' type 2                                   . LOG: (2,3) has character ' ' type 2
LOG: (2,4) has character '#' type 1                                   . LOG: (2,4) has character '#' type 1
LOG: (2,5) has character '#' type 1                                   . LOG: (2,5) has character '#' type 1
LOG: (2,6) has character '#' type 1                                   . LOG: (2,6) has character '#' type 1
LOG: (2,7) has character '#' type 1                                   . LOG: (2,7) has character '#' type 1
LOG: finished reading row 2 of tiles                                  . LOG: finished reading row 2 of tiles
LOG: (3,0) has character '#' type 1                                   . LOG: (3,0) has character '#' type 1
LOG: (3,1) has character ' ' type 2                                   . LOG: (3,1) has character ' ' type 2
LOG: (3,2) has character '#' type 1                                   . LOG: (3,2) has character '#' type 1
LOG: (3,3) has character ' ' type 2                                   . LOG: (3,3) has character ' ' type 2
LOG: (3,4) has character ' ' type 2                                   . LOG: (3,4) has character ' ' type 2
LOG: (3,5) has character ' ' type 2                                   . LOG: (3,5) has character ' ' type 2
LOG: (3,6) has character ' ' type 2                                   . LOG: (3,6) has character ' ' type 2
LOG: (3,7) has character '#' type 1                                   . LOG: (3,7) has character '#' type 1
LOG: finished reading row 3 of tiles                                  . LOG: finished reading row 3 of tiles
LOG: (4,0) has character '#' type 1                                   . LOG: (4,0) has character '#' type 1
LOG: (4,1) has character ' ' type 2                                   . LOG: (4,1) has character ' ' type 2
LOG: (4,2) has character '#' type 1                                   . LOG: (4,2) has character '#' type 1
LOG: (4,3) has character '#' type 1                                   . LOG: (4,3) has character '#' type 1
LOG: (4,4) has character '#' type 1                                   . LOG: (4,4) has character '#' type 1
LOG: (4,5) has character '#' type 1                                   . LOG: (4,5) has character '#' type 1
LOG: (4,6) has character '#' type 1                                   . LOG: (4,6) has character '#' type 1
LOG: (4,7) has character '#' type 1                                   . LOG: (4,7) has character '#' type 1
LOG: finished reading row 4 of tiles                                  . LOG: finished reading row 4 of tiles
LOG: (5,0) has character '#' type 1                                   . LOG: (5,0) has character '#' type 1
LOG: (5,1) has character ' ' type 2                                   . LOG: (5,1) has character ' ' type 2
LOG: (5,2) has character ' ' type 2                                   . LOG: (5,2) has character ' ' type 2
LOG: (5,3) has character ' ' type 2                                   . LOG: (5,3) has character ' ' type 2
LOG: (5,4) has character ' ' type 2                                   . LOG: (5,4) has character ' ' type 2
LOG: (5,5) has character ' ' type 2                                   . LOG: (5,5) has character ' ' type 2
LOG: (5,6) has character ' ' type 2                                   . LOG: (5,6) has character ' ' type 2
LOG: (5,7) has character '#' type 1                                   . LOG: (5,7) has character '#' type 1
LOG: finished reading row 5 of tiles                                  . LOG: finished reading row 5 of tiles
LOG: (6,0) has character '#' type 1                                   . LOG: (6,0) has character '#' type 1
LOG: (6,1) has character '#' type 1                                   . LOG: (6,1) has character '#' type 1
LOG: (6,2) has character '#' type 1                                   . LOG: (6,2) has character '#' type 1
LOG: (6,3) has character '#' type 1                                   . LOG: (6,3) has character '#' type 1
LOG: (6,4) has character '#' type 1                                   . LOG: (6,4) has character '#' type 1
LOG: (6,5) has character '#' type 1                                   . LOG: (6,5) has character '#' type 1
LOG: (6,6) has character ' ' type 2                                   . LOG: (6,6) has character ' ' type 2
LOG: (6,7) has character '#' type 1                                   . LOG: (6,7) has character '#' type 1
LOG: finished reading row 6 of tiles                                  . LOG: finished reading row 6 of tiles
LOG: (7,0) has character '#' type 1                                   . LOG: (7,0) has character '#' type 1
LOG: (7,1) has character ' ' type 2                                   . LOG: (7,1) has character ' ' type 2
LOG: (7,2) has character '#' type 1                                   . LOG: (7,2) has character '#' type 1
LOG: (7,3) has character '#' type 1                                   . LOG: (7,3) has character '#' type 1
LOG: (7,4) has character ' ' type 2                                   . LOG: (7,4) has character ' ' type 2
LOG: (7,5) has character ' ' type 2                                   . LOG: (7,5) has character ' ' type 2
LOG: (7,6) has character ' ' type 2                                   . LOG: (7,6) has character ' ' type 2
LOG: (7,7) has character '#' type 1                                   . LOG: (7,7) has character '#' type 1
LOG: finished reading row 7 of tiles                                  . LOG: finished reading row 7 of tiles
LOG: (8,0) has character '#' type 1                                   . LOG: (8,0) has character '#' type 1
LOG: (8,1) has character ' ' type 2                                   . LOG: (8,1) has character ' ' type 2
LOG: (8,2) has character '#' type 1                                   . LOG: (8,2) has character '#' type 1
LOG: (8,3) has character ' ' type 2                                   . LOG: (8,3) has character ' ' type 2
LOG: (8,4) has character ' ' type 2                                   . LOG: (8,4) has character ' ' type 2
LOG: (8,5) has character '#' type 1                                   . LOG: (8,5) has character '#' type 1
LOG: (8,6) has character 'E' type 5                                   . LOG: (8,6) has character 'E' type 5
LOG: setting END at (8,6)                                             . LOG: setting END at (8,6)
LOG: (8,7) has character '#' type 1                                   . LOG: (8,7) has character '#' type 1
LOG: finished reading row 8 of tiles                                  . LOG: finished reading row 8 of tiles
LOG: (9,0) has character '#' type 1                                   . LOG: (9,0) has character '#' type 1
LOG: (9,1) has character '#' type 1                                   . LOG: (9,1) has character '#' type 1
LOG: (9,2) has character '#' type 1                                   . LOG: (9,2) has character '#' type 1
LOG: (9,3) has character '#' type 1                                   . LOG: (9,3) has character '#' type 1
LOG: (9,4) has character '#' type 1                                   . LOG: (9,4) has character '#' type 1
LOG: (9,5) has character '#' type 1                                   . LOG: (9,5) has character '#' type 1
LOG: (9,6) has character '#' type 1                                   . LOG: (9,6) has character '#' type 1
LOG: (9,7) has character '#' type 1                                   . LOG: (9,7) has character '#' type 1
LOG: finished reading row 9 of tiles                                  . LOG: finished reading row 9 of tiles
LOADED MAZE:                                                          . LOADED MAZE:
maze: 10 rows 8 cols                                                  . maze: 10 rows 8 cols
      (1,6) start                                                     .       (1,6) start
      (8,6) end                                                       .       (8,6) end
maze tiles:                                                           . maze tiles:
########                                                              . ########
#     S#                                                              . #     S#
# # ####                                                              . # # ####
# #    #                                                              . # #    #
# ######                                                              . # ######
#      #                                                              . #      #
###### #                                                              . ###### #
# ##   #                                                              . # ##   #
# #  #E#                                                              . # #  #E#
########                                                              . ########
                                                                      ) 
LOG: BFS initialization complete                                      . LOG: BFS initialization complete
########:  0                                                          . ########:  0
#     0#:  1                                                          . #     0#:  1
# # ####:  2                                                          . # # ####:  2
# #    #:  3                                                          . # #    #:  3
# ######:  4                                                          . # ######:  4
#      #:  5                                                          . #      #:  5
###### #:  6                                                          . ###### #:  6
# ##   #:  7                                                          . # ##   #:  7
# #  #E#:  8                                                          . # #  #E#:  8
########:  9                                                          . ########:  9
01234567                                                              . 01234567
0                                                                     . 0       
queue count: 1                                                        . queue count: 1
NN ROW COL                                                            . NN ROW COL
 0   1   6                                                            .  0   1   6
LOG: BFS STEP 1                                                       . LOG: BFS STEP 1
LOG: processing neighbors of (1,6)                                    . LOG: processing neighbors of (1,6)
LOG: Skipping BLOCKED tile at (0,6)                                   . LOG: Skipping BLOCKED tile at (0,6)
LOG: Skipping BLOCKED tile at (2,6)                                   . LOG: Skipping BLOCKED tile at (2,6)
LOG: Found tile at (1,5) with len 1 path: W                           . LOG: Found tile at (1,5) with len 1 path: W
LOG: Skipping BLOCKED tile at (1,7)                                   . LOG: Skipping BLOCKED tile at (1,7)
LOG: maze state after BFS step                                        . LOG: maze state after BFS step
########:  0                                                          . ########:  0
#    10#:  1                                                          . #    10#:  1
# # ####:  2                                                          . # # ####:  2
# #    #:  3                                                          . # #    #:  3
# ######:  4                                                          . # ######:  4
#      #:  5                                                          . #      #:  5
###### #:  6                                                          . ###### #:  6
# ##   #:  7                                                          . # ##   #:  7
# #  #E#:  8                                                          . # #  #E#:  8
########:  9                                                          . ########:  9
01234567                                                              . 01234567
0                                                                     . 0       
queue count: 1                                                        . queue count: 1
NN ROW COL                                                            . NN ROW COL
 0   1   5                                                            .  0   1   5
LOG: BFS STEP 2                                                       . LOG: BFS STEP 2
LOG: processing neighbors of (1,5)                                    . LOG: processing neighbors of (1,5)
LOG: Skipping BLOCKED tile at (0,5)                                   . LOG: Skipping BLOCKED tile at (0,5)
LOG: Skipping BLOCKED tile at (2,5)                                   . LOG: Skipping BLOCKED tile at (2,5)
LOG: Found tile at (1,4) with len 2 path: WW                          . LOG: Found tile at (1,4) with len 2 path: WW
LOG: Skipping FOUND tile at (1,6)                                     . LOG: Skipping FOUND tile at (1,6)
LOG: maze state after BFS step                                        . LOG: maze state after BFS step
########:  0                                                          . ########:  0
#   210#:  1                                                          . #   210#:  1
# # ####:  2                                                          . # # ####:  2
# #    #:  3                                                          . # #    #:  3
# ######:  4                                                          . # ######:  4
#      #:  5                                                          . #      #:  5
###### #:  6                                                          . ###### #:  6
# ##   #:  7                                                          . # ##   #:  7
# #  #E#:  8                                                          . # #  #E#:  8
########:  9                                                          . ########:  9
01234567                                                              . 01234567
0                                                                     . 0       
queue count: 1                                                        . queue count: 1
NN ROW COL                                                            . NN ROW COL
 0   1   4                                                            .  0   1   4
LOG: BFS STEP 3                                                       . LOG: BFS STEP 3
LOG: processing neighbors of (1,4)                                    . LOG: processing neighbors of (1,4)
LOG: Skipping BLOCKED tile at (0,4)                                   . LOG: Skipping BLOCKED tile at (0,4)
LOG: Skipping BLOCKED tile at (2,4)                                   . LOG: Skipping BLOCKED tile at (2,4)
LOG: Found tile at (1,3) with len 3 path: WWW                         . LOG: Found tile at (1,3) with len 3 path: WWW
LOG: Skipping FOUND tile at (1,5)                                     . LOG: Skipping FOUND tile at (1,5)
LOG: maze state after BFS step                                        . LOG: maze state after BFS step
########:  0                                                          . ########:  0
#  3210#:  1                                                          . #  3210#:  1
# # ####:  2                                                          . # # ####:  2
# #    #:  3                                                          . # #    #:  3
# ######:  4                                                          . # ######:  4
#      #:  5                                                          . #      #:  5
###### #:  6                                                          . ###### #:  6
# ##   #:  7                                                          . # ##   #:  7
# #  #E#:  8                                                          . # #  #E#:  8
########:  9                                                          . ########:  9
01234567                                                              . 01234567
0                                                                     . 0       
queue count: 1                                                        . queue count: 1
NN ROW COL                                                            . NN ROW COL
 0   1   3                                                            .  0   1   3
LOG: BFS STEP 4                                                       . LOG: BFS STEP 4
LOG: processing neighbors of (1,3)                                    . LOG: processing neighbors of (1,3)
LOG: Skipping BLOCKED tile at (0,3)                                   . LOG: Skipping BLOCKED tile at (0,3)
LOG: Found tile at (2,3) with len 4 path: WWWS                        . LOG: Found tile at (2,3) with len 4 path: WWWS
LOG: Found tile at (1,2) with len 4 path: WWWW                        . LOG: Found tile at (1,2) with len 4 path: WWWW
LOG: Skipping FOUND tile at (1,4)                                     . LOG: Skipping FOUND tile at (1,4)
LOG: maze state after BFS step                                        . LOG: maze state after BFS step
########:  0                                                          . ########:  0
# 43210#:  1                                                          . # 43210#:  1
# #4####:  2                                                          . # #4####:  2
# #    #:  3                                                          . # #    #:  3
# ######:  4                                                          . # ######:  4
#      #:  5                                                          . #      #:  5
###### #:  6                                                          . ###### #:  6
# ##   #:  7                                                          . # ##   #:  7
# #  #E#:  8                                                          . # #  #E#:  8
########:  9                                                          . ########:  9
01234567                                                              . 01234567
0                                                                     . 0       
queue count: 2                                                        . queue count: 2
NN ROW COL                                                            . NN ROW COL
 0   2   3                                                            .  0   2   3
 1   1   2                                                            .  1   1   2
LOG: BFS STEP 5                                                       . LOG: BFS STEP 5
LOG: processing neighbors of (2,3)                                    . LOG: processing neighbors of (2,3)
LOG: Skipping FOUND tile at (1,3)                                     . LOG: Skipping FOUND tile at (1,3)
LOG: Found tile at (3,3) with len 5 path: WWWSS                       . LOG: Found tile at (3,3) with len 5 path: WWWSS
LOG: Skipping BLOCKED tile at (2,2)                                   . LOG: Skipping BLOCKED tile at (2,2)
LOG: Skipping BLOCKED tile at (2,4)                                   . LOG: Skipping BLOCKED tile at (2,4)
LOG: maze state after BFS step                                        . LOG: maze state after BFS step
########:  0                                                          . ########:  0
# 43210#:  1                                                          . # 43210#:  1
# #4####:  2                                                          . # #4####:  2
# #5   #:  3                                                          . # #5   #:  3
# ######:  4                                                          . # ######:  4
#      #:  5                                                          . #      #:  5
###### #:  6                                                          . ###### #:  6
# ##   #:  7                                                          . # ##   #:  7
# #  #E#:  8                                                          . # #  #E#:  8
########:  9                                                          . ########:  9
01234567                                                              . 01234567
0                                                                     . 0       
queue count: 2                                                        . queue count: 2
NN ROW COL                                                            . NN ROW COL
 0   1   2                                                            .  0   1   2
 1   3   3                                                            .  1   3   3
LOG: BFS STEP 6                                                       . LOG: BFS STEP 6
LOG: processing neighbors of (1,2)                                    . LOG: processing neighbors of (1,2)
LOG: Skipping BLOCKED tile at (0,2)                                   . LOG: Skipping BLOCKED tile at (0,2)
LOG: Skipping BLOCKED tile at (2,2)                                   . LOG: Skipping BLOCKED tile at (2,2)
LOG: Found tile at (1,1) with len 5 path: WWWWW                       . LOG: Found tile at (1,1) with len 5 path: WWWWW
LOG: Skipping FOUND tile at (1,3)                                     . LOG: Skipping FOUND tile at (1,3)
LOG: maze state after BFS step                                        . LOG: maze state after BFS step
########:  0                                                          . ########:  0
#543210#:  1                                                          . #543210#:  1
# #4####:  2                                                          . # #4####:  2
# #5   #:  3                                                          . # #5   #:  3
# ######:  4                                                          . # ######:  4
#      #:  5                                                          . #      #:  5
###### #:  6                                                          . ###### #:  6
# ##   #:  7                                                          . # ##   #:  7
# #  #E#:  8                                                          . # #  #E#:  8
########:  9                                                          . ########:  9
01234567                                                              . 01234567
0                                                                     . 0       
queue count: 2                                                        . queue count: 2
NN ROW COL                                                            . NN ROW COL
 0   3   3                                                            .  0   3   3
 1   1   1                                                            .  1   1   1
LOG: BFS STEP 7                                                       . LOG: BFS STEP 7
LOG: processing neighbors of (3,3)                                    . LOG: processing neighbors of (3,3)
LOG: Skipping FOUND tile at (2,3)                                     . LOG: Skipping FOUND tile at (2,3)
LOG: Skipping BLOCKED tile at (4,3)                                   . LOG: Skipping BLOCKED tile at (4,3)
LOG: Skipping BLOCKED tile at (3,2)                                   . LOG: Skipping BLOCKED tile at (3,2)
LOG: Found tile at (3,4) with len 6 path: WWWSSE                      . LOG: Found tile at (3,4) with len 6 path: WWWSSE
LOG: maze state after BFS step                                        . LOG: maze state after BFS step
########:  0                                                          . ########:  0
#543210#:  1                                                          . #543210#:  1
# #4####:  2                                                          . # #4####:  2
# #56  #:  3                                                          . # #56  #:  3
# ######:  4                                                          . # ######:  4
#      #:  5                                                          . #      #:  5
###### #:  6                                                          . ###### #:  6
# ##   #:  7                                                          . # ##   #:  7
# #  #E#:  8                                                          . # #  #E#:  8
########:  9                                                          . ########:  9
01234567                                                              . 01234567
0                                                                     . 0       
queue count: 2                                                        . queue count: 2
NN ROW COL                                                            . NN ROW COL
 0   1   1                                                            .  0   1   1
 1   3   4                                                            .  1   3   4
LOG: BFS STEP 8                                                       . LOG: BFS STEP 8
LOG: processing neighbors of (1,1)                                    . LOG: processing neighbors of (1,1)
LOG: Skipping BLOCKED tile at (0,1)                                   . LOG: Skipping BLOCKED tile at (0,1)
LOG: Found tile at (2,1) with len 6 path: WWWWWS                      . LOG: Found tile at (2,1) with len 6 path: WWWWWS
LOG: Skipping BLOCKED tile at (1,0)                                   . LOG: Skipping BLOCKED tile at (1,0)
LOG: Skipping FOUND tile at (1,2)                                     . LOG: Skipping FOUND tile at (1,2)
LOG: maze state after BFS step                                        . LOG: maze state after BFS step
########:  0                                                          . ########:  0
#543210#:  1                                                          . #543210#:  1
#6#4####:  2                                                          . #6#4####:  2
# #56  #:  3                                                          . # #56  #:  3
# ######:  4                                                          . # ######:  4
#      #:  5                                                          . #      #:  5
###### #:  6                                                          . ###### #:  6
# ##   #:  7                                                          . # ##   #:  7
# #  #E#:  8                                                          . # #  #E#:  8
########:  9                                                          . ########:  9
01234567                                                              . 01234567
0                                                                     . 0       
queue count: 2                                                        . queue count: 2
NN ROW COL                                                            . NN ROW COL
 0   3   4                                                            .  0   3   4
 1   2   1                                                            .  1   2   1
LOG: BFS STEP 9                                                       . LOG: BFS STEP 9
LOG: processing neighbors of (3,4)                                    . LOG: processing neighbors of (3,4)
LOG: Skipping BLOCKED tile at (2,4)                                   . LOG: Skipping BLOCKED tile at (2,4)
LOG: Skipping BLOCKED tile at (4,4)                                   . LOG: Skipping BLOCKED tile at (4,4)
LOG: Skipping FOUND tile at (3,3)                                     . LOG: Skipping FOUND tile at (3,3)
LOG: Found tile at (3,5) with len 7 path: WWWSSEE                     . LOG: Found tile at (3,5) with len 7 path: WWWSSEE
LOG: maze state after BFS step                                        . LOG: maze state after BFS step
########:  0                                                          . ########:  0
#543210#:  1                                                          . #543210#:  1
#6#4####:  2                                                          . #6#4####:  2
# #567 #:  3                                                          . # #567 #:  3
# ######:  4                                                          . # ######:  4
#      #:  5                                                          . #      #:  5
###### #:  6                                                          . ###### #:  6
# ##   #:  7                                                          . # ##   #:  7
# #  #E#:  8                                                          . # #  #E#:  8
########:  9                                                          . ########:  9
01234567                                                              . 01234567
0                                                                     . 0       
queue count: 2                                                        . queue count: 2
NN ROW COL                                                            . NN ROW COL
 0   2   1                                                            .  0   2   1
 1   3   5                                                            .  1   3   5
LOG: BFS STEP 10                                                      . LOG: BFS STEP 10
LOG: processing neighbors of (2,1)                                    . LOG: processing neighbors of (2,1)
LOG: Skipping FOUND tile at (1,1)                                     . LOG: Skipping FOUND tile at (1,1)
LOG: Found tile at (3,1) with len 7 path: WWWWWSS                     . LOG: Found tile at (3,1) with len 7 path: WWWWWSS
LOG: Skipping BLOCKED tile at (2,0)                                   . LOG: Skipping BLOCKED tile at (2,0)
LOG: Skipping BLOCKED tile at (2,2)                                   . LOG: Skipping BLOCKED tile at (2,2)
LOG: maze state after BFS step                                        . LOG: maze state after BFS step
########:  0                                                          . ########:  0
#543210#:  1                                                          . #543210#:  1
#6#4####:  2                                                          . #6#4####:  2
#7#567 #:  3                                                          . #7#567 #:  3
# ######:  4                                                          . # ######:  4
#      #:  5                                                          . #      #:  5
###### #:  6                                                          . ###### #:  6
# ##   #:  7                                                          . # ##   #:  7
# #  #E#:  8                                                          . # #  #E#:  8
########:  9                                                          . ########:  9
01234567                                                              . 01234567
0                                                                     . 0       
queue count: 2                                                        . queue count: 2
NN ROW COL                                                            . NN ROW COL
 0   3   5                                                            .  0   3   5
 1   3   1                                                            .  1   3   1
LOG: BFS STEP 11                                                      . LOG: BFS STEP 11
LOG: processing neighbors of (3,5)                                    . LOG: processing neighbors of (3,5)
LOG: Skipping BLOCKED tile at (2,5)                                   . LOG: Skipping BLOCKED tile at (2,5)
LOG: Skipping BLOCKED tile at (4,5)                                   . LOG: Skipping BLOCKED tile at (4,5)
LOG: Skipping FOUND tile at (3,4)                                     . LOG: Skipping FOUND tile at (3,4)
LOG: Found tile at (3,6) with len 8 path: WWWSSEEE                    . LOG: Found tile at (3,6) with len 8 path: WWWSSEEE
LOG: maze state after BFS step                                        . LOG: maze state after BFS step
########:  0                                                          . ########:  0
#543210#:  1                                                          . #543210#:  1
#6#4####:  2                                                          . #6#4####:  2
#7#5678#:  3                                                          . #7#5678#:  3
# ######:  4                                                          . # ######:  4
#      #:  5                                                          . #      #:  5
###### #:  6                                                          . ###### #:  6
# ##   #:  7                                                          . # ##   #:  7
# #  #E#:  8                                                          . # #  #E#:  8
########:  9                                                          . ########:  9
01234567                                                              . 01234567
0                                                                     . 0       
queue count: 2                                                        . queue count: 2
NN ROW COL                                                            . NN ROW COL
 0   3   1                                                            .  0   3   1
 1   3   6                                                            .  1   3   6
LOG: BFS STEP 12                                                      . LOG: BFS STEP 12
LOG: processing neighbors of (3,1)                                    . LOG: processing neighbors of (3,1)
LOG: Skipping FOUND tile at (2,1)                                     . LOG: Skipping FOUND tile at (2,1)
LOG: Found tile at (4,1) with len 8 path: WWWWWSSS                    . LOG: Found tile at (4,1) with len 8 path: WWWWWSSS
LOG: Skipping BLOCKED tile at (3,0)                                   . LOG: Skipping BLOCKED tile at (3,0)
LOG: Skipping BLOCKED tile at (3,2)                                   . LOG: Skipping BLOCKED tile at (3,2)
LOG: maze state after BFS step                                        . LOG: maze state after BFS step
########:  0                                                          . ########:  0
#543210#:  1                                                          . #543210#:  1
#6#4####:  2                                                          . #6#4####:  2
#7#5678#:  3                                                          . #7#5678#:  3
#8######:  4                                                          . #8######:  4
#      #:  5                                                          . #      #:  5
###### #:  6                                                          . ###### #:  6
# ##   #:  7                                                          . # ##   #:  7
# #  #E#:  8                                                          . # #  #E#:  8
########:  9                                                          . ########:  9
01234567                                                              . 01234567
0                                                                     . 0       
queue count: 2                                                        . queue count: 2
NN ROW COL                                                            . NN ROW COL
 0   3   6                                                            .  0   3   6
 1   4   1                                                            .  1   4   1
LOG: BFS STEP 13                                                      . LOG: BFS STEP 13
LOG: processing neighbors of (3,6)                                    . LOG: processing neighbors of (3,6)
LOG: Skipping BLOCKED tile at (2,6)                                   . LOG: Skipping BLOCKED tile at (2,6)
LOG: Skipping BLOCKED tile at (4,6)                                   . LOG: Skipping BLOCKED tile at (4,6)
LOG: Skipping FOUND tile at (3,5)                                     . LOG: Skipping FOUND tile at (3,5)
LOG: Skipping BLOCKED tile at (3,7)                                   . LOG: Skipping BLOCKED tile at (3,7)
LOG: maze state after BFS step                                        . LOG: maze state after BFS step
########:  0                                                          . ########:  0
#543210#:  1                                                          . #543210#:  1
#6#4####:  2                                                          . #6#4####:  2
#7#5678#:  3                                                          . #7#5678#:  3
#8######:  4                                                          . #8######:  4
#      #:  5                                                          . #      #:  5
###### #:  6                                                          . ###### #:  6
# ##   #:  7                                                          . # ##   #:  7
# #  #E#:  8                                                          . # #  #E#:  8
########:  9                                                          . ########:  9
01234567                                                              . 01234567
0                                                                     . 0       
queue count: 1                                                        . queue count: 1
NN ROW COL                                                            . NN ROW COL
 0   4   1                                                            .  0   4   1
LOG: BFS STEP 14                                                      . LOG: BFS STEP 14
LOG: processing neighbors of (4,1)                                    . LOG: processing neighbors of (4,1)
LOG: Skipping FOUND tile at (3,1)                                     . LOG: Skipping FOUND tile at (3,1)
LOG: Found tile at (5,1) with len 9 path: WWWWWSSSS                   . LOG: Found tile at (5,1) with len 9 path: WWWWWSSSS
LOG: Skipping BLOCKED tile at (4,0)                                   . LOG: Skipping BLOCKED tile at (4,0)
LOG: Skipping BLOCKED tile at (4,2)                                   . LOG: Skipping BLOCKED tile at (4,2)
LOG: maze state after BFS step                                        . LOG: maze state after BFS step
########:  0                                                          . ########:  0
#543210#:  1                                                          . #543210#:  1
#6#4####:  2                                                          . #6#4####:  2
#7#5678#:  3                                                          . #7#5678#:  3
#8######:  4                                                          . #8######:  4
#9     #:  5                                                          . #9     #:  5
###### #:  6                                                          . ###### #:  6
# ##   #:  7                                                          . # ##   #:  7
# #  #E#:  8                                                          . # #  #E#:  8
########:  9                                                          . ########:  9
01234567                                                              . 01234567
0                                                                     . 0       
queue count: 1                                                        . queue count: 1
NN ROW COL                                                            . NN ROW COL
 0   5   1                                                            .  0   5   1
LOG: BFS STEP 15                                                      . LOG: BFS STEP 15
LOG: processing neighbors of (5,1)                                    . LOG: processing neighbors of (5,1)
LOG: Skipping FOUND tile at (4,1)                                     . LOG: Skipping FOUND tile at (4,1)
LOG: Skipping BLOCKED tile at (6,1)                                   . LOG: Skipping BLOCKED tile at (6,1)
LOG: Skipping BLOCKED tile at (5,0)                                   . LOG: Skipping BLOCKED tile at (5,0)
LOG: Found tile at (5,2) with len 10 path: WWWWWSSSSE                 . LOG: Found tile at (5,2) with len 10 path: WWWWWSSSSE
LOG: maze state after BFS step                                        . LOG: maze state after BFS step
########:  0                                                          . ########:  0
#543210#:  1                                                          . #543210#:  1
#6#4####:  2                                                          . #6#4####:  2
#7#5678#:  3                                                          . #7#5678#:  3
#8######:  4                                                          . #8######:  4
#9a    #:  5                                                          . #9a    #:  5
###### #:  6                                                          . ###### #:  6
# ##   #:  7                                                          . # ##   #:  7
# #  #E#:  8                                                          . # #  #E#:  8
########:  9                                                          . ########:  9
01234567                                                              . 01234567
0                                                                     . 0       
queue count: 1                                                        . queue count: 1
NN ROW COL                                                            . NN ROW COL
 0   5   2                                                            .  0   5   2
LOG: BFS STEP 16                                                      . LOG: BFS STEP 16
LOG: processing neighbors of (5,2)                                    . LOG: processing neighbors of (5,2)
LOG: Skipping BLOCKED tile at (4,2)                                   . LOG: Skipping BLOCKED tile at (4,2)
LOG: Skipping BLOCKED tile at (6,2)                                   . LOG: Skipping BLOCKED tile at (6,2)
LOG: Skipping FOUND tile at (5,1)                                     . LOG: Skipping FOUND tile at (5,1)
LOG: Found tile at (5,3) with len 11 path: WWWWWSSSSEE                . LOG: Found tile at (5,3) with len 11 path: WWWWWSSSSEE
LOG: maze state after BFS step                                        . LOG: maze state after BFS step
########:  0                                                          . ########:  0
#543210#:  1                                                          . #543210#:  1
#6#4####:  2                                                          . #6#4####:  2
#7#5678#:  3                                                          . #7#5678#:  3
#8######:  4                                                          . #8######:  4
#9a1   #:  5                                                          . #9a1   #:  5
###### #:  6                                                          . ###### #:  6
# ##   #:  7                                                          . # ##   #:  7
# #  #E#:  8                                                          . # #  #E#:  8
########:  9                                                          . ########:  9
01234567                                                              . 01234567
0                                                                     . 0       
queue count: 1                                                        . queue count: 1
NN ROW COL                                                            . NN ROW COL
 0   5   3                                                            .  0   5   3
LOG: BFS STEP 17                                                      . LOG: BFS STEP 17
LOG: processing neighbors of (5,3)                                    . LOG: processing neighbors of (5,3)
LOG: Skipping BLOCKED tile at (4,3)                                   . LOG: Skipping BLOCKED tile at (4,3)
LOG: Skipping BLOCKED tile at (6,3)                                   . LOG: Skipping BLOCKED tile at (6,3)
LOG: Skipping FOUND tile at (5,2)                                     . LOG: Skipping FOUND tile at (5,2)
LOG: Found tile at (5,4) with len 12 path: WWWWWSSSSEEE               . LOG: Found tile at (5,4) with len 12 path: WWWWWSSSSEEE
LOG: maze state after BFS step                                        . LOG: maze state after BFS step
########:  0                                                          . ########:  0
#543210#:  1                                                          . #543210#:  1
#6#4####:  2                                                          . #6#4####:  2
#7#5678#:  3                                                          . #7#5678#:  3
#8######:  4                                                          . #8######:  4
#9a12  #:  5                                                          . #9a12  #:  5
###### #:  6                                                          . ###### #:  6
# ##   #:  7                                                          . # ##   #:  7
# #  #E#:  8                                                          . # #  #E#:  8
########:  9                                                          . ########:  9
01234567                                                              . 01234567
0                                                                     . 0       
queue count: 1                                                        . queue count: 1
NN ROW COL                                                            . NN ROW COL
 0   5   4                                                            .  0   5   4
LOG: BFS STEP 18                                                      . LOG: BFS STEP 18
LOG: processing neighbors of (5,4)                                    . LOG: processing neighbors of (5,4)
LOG: Skipping BLOCKED tile at (4,4)                                   . LOG: Skipping BLOCKED tile at (4,4)
LOG: Skipping BLOCKED tile at (6,4)                                   . LOG: Skipping BLOCKED tile at (6,4)
LOG: Skipping FOUND tile at (5,3)                                     . LOG: Skipping FOUND tile at (5,3)
LOG: Found tile at (5,5) with len 13 path: WWWWWSSSSEEEE              . LOG: Found tile at (5,5) with len 13 path: WWWWWSSSSEEEE
LOG: maze state after BFS step                                        . LOG: maze state after BFS step
########:  0                                                          . ########:  0
#543210#:  1                                                          . #543210#:  1
#6#4####:  2                                                          . #6#4####:  2
#7#5678#:  3                                                          . #7#5678#:  3
#8######:  4                                                          . #8######:  4
#9a123 #:  5                                                          . #9a123 #:  5
###### #:  6                                                          . ###### #:  6
# ##   #:  7                                                          . # ##   #:  7
# #  #E#:  8                                                          . # #  #E#:  8
########:  9                                                          . ########:  9
01234567                                                              . 01234567
0                                                                     . 0       
queue count: 1                                                        . queue count: 1
NN ROW COL                                                            . NN ROW COL
 0   5   5                                                            .  0   5   5
LOG: BFS STEP 19                                                      . LOG: BFS STEP 19
LOG: processing neighbors of (5,5)                                    . LOG: processing neighbors of (5,5)
LOG: Skipping BLOCKED tile at (4,5)                                   . LOG: Skipping BLOCKED tile at (4,5)
LOG: Skipping BLOCKED tile at (6,5)                                   . LOG: Skipping BLOCKED tile at (6,5)
LOG: Skipping FOUND tile at (5,4)                                     . LOG: Skipping FOUND tile at (5,4)
LOG: Found tile at (5,6) with len 14 path: WWWWWSSSSEEEEE             . LOG: Found tile at (5,6) with len 14 path: WWWWWSSSSEEEEE
LOG: maze state after BFS step                                        . LOG: maze state after BFS step
########:  0                                                          . ########:  0
#543210#:  1                                                          . #543210#:  1
#6#4####:  2                                                          . #6#4####:  2
#7#5678#:  3                                                          . #7#5678#:  3
#8######:  4                                                          . #8######:  4
#9a1234#:  5                                                          . #9a1234#:  5
###### #:  6                                                          . ###### #:  6
# ##   #:  7                                                          . # ##   #:  7
# #  #E#:  8                                                          . # #  #E#:  8
########:  9                                                          . ########:  9
01234567                                                              . 01234567
0                                                                     . 0       
queue count: 1                                                        . queue count: 1
NN ROW COL                                                            . NN ROW COL
 0   5   6                                                            .  0   5   6
LOG: BFS STEP 20                                                      . LOG: BFS STEP 20
LOG: processing neighbors of (5,6)                                    . LOG: processing neighbors of (5,6)
LOG: Skipping BLOCKED tile at (4,6)                                   . LOG: Skipping BLOCKED tile at (4,6)
LOG: Found tile at (6,6) with len 15 path: WWWWWSSSSEEEEES            . LOG: Found tile at (6,6) with len 15 path: WWWWWSSSSEEEEES
LOG: Skipping FOUND tile at (5,5)                                     . LOG: Skipping FOUND tile at (5,5)
LOG: Skipping BLOCKED tile at (5,7)                                   . LOG: Skipping BLOCKED tile at (5,7)
LOG: maze state after BFS step                                        . LOG: maze state after BFS step
########:  0                                                          . ########:  0
#543210#:  1                                                          . #543210#:  1
#6#4####:  2                                                          . #6#4####:  2
#7#5678#:  3                                                          . #7#5678#:  3
#8######:  4                                                          . #8######:  4
#9a1234#:  5                                                          . #9a1234#:  5
######5#:  6                                                          . ######5#:  6
# ##   #:  7                                                          . # ##   #:  7
# #  #E#:  8                                                          . # #  #E#:  8
########:  9                                                          . ########:  9
01234567                                                              . 01234567
0                                                                     . 0       
queue count: 1                                                        . queue count: 1
NN ROW COL                                                            . NN ROW COL
 0   6   6                                                            .  0   6   6
LOG: BFS STEP 21                                                      . LOG: BFS STEP 21
LOG: processing neighbors of (6,6)                                    . LOG: processing neighbors of (6,6)
LOG: Skipping FOUND tile at (5,6)                                     . LOG: Skipping FOUND tile at (5,6)
LOG: Found tile at (7,6) with len 16 path: WWWWWSSSSEEEEESS           . LOG: Found tile at (7,6) with len 16 path: WWWWWSSSSEEEEESS
LOG: Skipping BLOCKED tile at (6,5)                                   . LOG: Skipping BLOCKED tile at (6,5)
LOG: Skipping BLOCKED tile at (6,7)                                   . LOG: Skipping BLOCKED tile at (6,7)
LOG: maze state after BFS step                                        . LOG: maze state after BFS step
########:  0                                                          . ########:  0
#543210#:  1                                                          . #543210#:  1
#6#4####:  2                                                          . #6#4####:  2
#7#5678#:  3                                                          . #7#5678#:  3
#8######:  4                                                          . #8######:  4
#9a1234#:  5                                                          . #9a1234#:  5
######5#:  6                                                          . ######5#:  6
# ##  6#:  7                                                          . # ##  6#:  7
# #  #E#:  8                                                          . # #  #E#:  8
########:  9                                                          . ########:  9
01234567                                                              . 01234567
0                                                                     . 0       
queue count: 1                                                        . queue count: 1
NN ROW COL                                                            . NN ROW COL
 0   7   6                                                            .  0   7   6
LOG: BFS STEP 22                                                      . LOG: BFS STEP 22
LOG: processing neighbors of (7,6)                                    . LOG: processing neighbors of (7,6)
LOG: Skipping FOUND tile at (6,6)                                     . LOG: Skipping FOUND tile at (6,6)
LOG: Found tile at (8,6) with len 17 path: WWWWWSSSSEEEEESSS          . LOG: Found tile at (8,6) with len 17 path: WWWWWSSSSEEEEESSS
LOG: Found tile at (7,5) with len 17 path: WWWWWSSSSEEEEESSW          . LOG: Found tile at (7,5) with len 17 path: WWWWWSSSSEEEEESSW
LOG: Skipping BLOCKED tile at (7,7)                                   . LOG: Skipping BLOCKED tile at (7,7)
LOG: maze state after BFS step                                        . LOG: maze state after BFS step
########:  0                                                          . ########:  0
#543210#:  1                                                          . #543210#:  1
#6#4####:  2                                                          . #6#4####:  2
#7#5678#:  3                                                          . #7#5678#:  3
#8######:  4                                                          . #8######:  4
#9a1234#:  5                                                          . #9a1234#:  5
######5#:  6                                                          . ######5#:  6
# ## 76#:  7                                                          . # ## 76#:  7
# #  #7#:  8                                                          . # #  #7#:  8
########:  9                                                          . ########:  9
01234567                                                              . 01234567
0                                                                     . 0       
queue count: 2                                                        . queue count: 2
NN ROW COL                                                            . NN ROW COL
 0   8   6                                                            .  0   8   6
 1   7   5                                                            .  1   7   5
LOG: BFS STEP 23                                                      . LOG: BFS STEP 23
LOG: processing neighbors of (8,6)                                    . LOG: processing neighbors of (8,6)
LOG: Skipping FOUND tile at (7,6)                                     . LOG: Skipping FOUND tile at (7,6)
LOG: Skipping BLOCKED tile at (9,6)                                   . LOG: Skipping BLOCKED tile at (9,6)
LOG: Skipping BLOCKED tile at (8,5)                                   . LOG: Skipping BLOCKED tile at (8,5)
LOG: Skipping BLOCKED tile at (8,7)                                   . LOG: Skipping BLOCKED tile at (8,7)
LOG: maze state after BFS step                                        . LOG: maze state after BFS step
########:  0                                                          . ########:  0
#543210#:  1                                                          . #543210#:  1
#6#4####:  2                                                          . #6#4####:  2
#7#5678#:  3                                                          . #7#5678#:  3
#8######:  4                                                          . #8######:  4
#9a1234#:  5                                                          . #9a1234#:  5
######5#:  6                                                          . ######5#:  6
# ## 76#:  7                                                          . # ## 76#:  7
# #  #7#:  8                                                          . # #  #7#:  8
########:  9                                                          . ########:  9
01234567                                                              . 01234567
0                                                                     . 0       
queue count: 1                                                        . queue count: 1
NN ROW COL                                                            . NN ROW COL
 0   7   5                                                            .  0   7   5
LOG: BFS STEP 24                                                      . LOG: BFS STEP 24
LOG: processing neighbors of (7,5)                                    . LOG: processing neighbors of (7,5)
LOG: Skipping BLOCKED tile at (6,5)                                   . LOG: Skipping BLOCKED tile at (6,5)
LOG: Skipping BLOCKED tile at (8,5)                                   . LOG: Skipping BLOCKED tile at (8,5)
LOG: Found tile at (7,4) with len 18 path: WWWWWSSSSEEEEESSWW         . LOG: Found tile at (7,4) with len 18 path: WWWWWSSSSEEEEESSWW
LOG: Skipping FOUND tile at (7,6)                                     . LOG: Skipping FOUND tile at (7,6)
LOG: maze state after BFS step                                        . LOG: maze state after BFS step
########:  0                                                          . ########:  0
#543210#:  1                                                          . #543210#:  1
#6#4####:  2                                                          . #6#4####:  2
#7#5678#:  3                                                          . #7#5678#:  3
#8######:  4                                                          . #8######:  4
#9a1234#:  5                                                          . #9a1234#:  5
######5#:  6                                                          . ######5#:  6
# ##876#:  7                                                          . # ##876#:  7
# #  #7#:  8                                                          . # #  #7#:  8
########:  9                                                          . ########:  9
01234567                                                              . 01234567
0                                                                     . 0       
queue count: 1                                                        . queue count: 1
NN ROW COL                                                            . NN ROW COL
 0   7   4                                                            .  0   7   4
LOG: BFS STEP 25                                                      . LOG: BFS STEP 25
LOG: processing neighbors of (7,4)                                    . LOG: processing neighbors of (7,4)
LOG: Skipping BLOCKED tile at (6,4)                                   . LOG: Skipping BLOCKED tile at (6,4)
LOG: Found tile at (8,4) with len 19 path: WWWWWSSSSEEEEESSWWS        . LOG: Found tile at (8,4) with len 19 path: WWWWWSSSSEEEEESSWWS
LOG: Skipping BLOCKED tile at (7,3)                                   . LOG: Skipping BLOCKED tile at (7,3)
LOG: Skipping FOUND tile at (7,5)                                     . LOG: Skipping FOUND tile at (7,5)
LOG: maze state after BFS step                                        . LOG: maze state after BFS step
########:  0                                                          . ########:  0
#543210#:  1                                                          . #543210#:  1
#6#4####:  2                                                          . #6#4####:  2
#7#5678#:  3                                                          . #7#5678#:  3
#8######:  4                                                          . #8######:  4
#9a1234#:  5                                                          . #9a1234#:  5
######5#:  6                                                          . ######5#:  6
# ##876#:  7                                                          . # ##876#:  7
# # 9#7#:  8                                                          . # # 9#7#:  8
########:  9                                                          . ########:  9
01234567                                                              . 01234567
0                                                                     . 0       
queue count: 1                                                        . queue count: 1
NN ROW COL                                                            . NN ROW COL
 0   8   4                                                            .  0   8   4
LOG: BFS STEP 26                                                      . LOG: BFS STEP 26
LOG: processing neighbors of (8,4)                                    . LOG: processing neighbors of (8,4)
LOG: Skipping FOUND tile at (7,4)                                     . LOG: Skipping FOUND tile at (7,4)
LOG: Skipping BLOCKED tile at (9,4)                                   . LOG: Skipping BLOCKED tile at (9,4)
LOG: Found tile at (8,3) with len 20 path: WWWWWSSSSEEEEESSWWSW       . LOG: Found tile at (8,3) with len 20 path: WWWWWSSSSEEEEESSWWSW
LOG: Skipping BLOCKED tile at (8,5)                                   . LOG: Skipping BLOCKED tile at (8,5)
LOG: maze state after BFS step                                        . LOG: maze state after BFS step
########:  0                                                          . ########:  0
#543210#:  1                                                          . #543210#:  1
#6#4####:  2                                                          . #6#4####:  2
#7#5678#:  3                                                          . #7#5678#:  3
#8######:  4                                                          . #8######:  4
#9a1234#:  5                                                          . #9a1234#:  5
######5#:  6                                                          . ######5#:  6
# ##876#:  7                                                          . # ##876#:  7
# #b9#7#:  8                                                          . # #b9#7#:  8
########:  9                                                          . ########:  9
01234567                                                              . 01234567
0                                                                     . 0       
queue count: 1                                                        . queue count: 1
NN ROW COL                                                            . NN ROW COL
 0   8   3                                                            .  0   8   3
LOG: BFS STEP 27                                                      . LOG: BFS STEP 27
LOG: processing neighbors of (8,3)                                    . LOG: processing neighbors of (8,3)
LOG: Skipping BLOCKED tile at (7,3)                                   . LOG: Skipping BLOCKED tile at (7,3)
LOG: Skipping BLOCKED tile at (9,3)                                   . LOG: Skipping BLOCKED tile at (9,3)
LOG: Skipping BLOCKED tile at (8,2)                                   . LOG: Skipping BLOCKED tile at (8,2)
LOG: Skipping FOUND tile at (8,4)                                     . LOG: Skipping FOUND tile at (8,4)
LOG: maze state after BFS step                                        . LOG: maze state after BFS step
########:  0                                                          . ########:  0
#543210#:  1                                                          . #543210#:  1
#6#4####:  2                                                          . #6#4####:  2
#7#5678#:  3                                                          . #7#5678#:  3
#8######:  4                                                          . #8######:  4
#9a1234#:  5                                                          . #9a1234#:  5
######5#:  6                                                          . ######5#:  6
# ##876#:  7                                                          . # ##876#:  7
# #b9#7#:  8                                                          . # #b9#7#:  8
########:  9                                                          . ########:  9
01234567                                                              . 01234567
0                                                                     . 0       
queue count: 0                                                        . queue count: 0
NN ROW COL                                                            . NN ROW COL
Maze AFTER BFS iteration                                              . Maze AFTER BFS iteration
########:  0                                                          . ########:  0
#543210#:  1                                                          . #543210#:  1
#6#4####:  2                                                          . #6#4####:  2
#7#5678#:  3                                                          . #7#5678#:  3
#8######:  4                                                          . #8######:  4
#9a1234#:  5                                                          . #9a1234#:  5
######5#:  6                                                          . ######5#:  6
# ##876#:  7                                                          . # ##876#:  7
# #b9#7#:  8                                                          . # #b9#7#:  8
########:  9                                                          . ########:  9
01234567                                                              . 01234567
0                                                                     . 0       
queue count: 0                                                        . queue count: 0
NN ROW COL                                                            . NN ROW COL
LOG: solution START at (1,6)                                          . LOG: solution START at (1,6)
LOG: solution path[0] is WEST, set (1,5) to ONPATH                    . LOG: solution path[0] is WEST, set (1,5) to ONPATH
LOG: solution path[1] is WEST, set (1,4) to ONPATH                    . LOG: solution path[1] is WEST, set (1,4) to ONPATH
LOG: solution path[2] is WEST, set (1,3) to ONPATH                    . LOG: solution path[2] is WEST, set (1,3) to ONPATH
LOG: solution path[3] is WEST, set (1,2) to ONPATH                    . LOG: solution path[3] is WEST, set (1,2) to ONPATH
LOG: solution path[4] is WEST, set (1,1) to ONPATH                    . LOG: solution path[4] is WEST, set (1,1) to ONPATH
LOG: solution path[5] is SOUTH, set (2,1) to ONPATH                   . LOG: solution path[5] is SOUTH, set (2,1) to ONPATH
LOG: solution path[6] is SOUTH, set (3,1) to ONPATH                   . LOG: solution path[6] is SOUTH, set (3,1) to ONPATH
LOG: solution path[7] is SOUTH, set (4,1) to ONPATH                   . LOG: solution path[7] is SOUTH, set (4,1) to ONPATH
LOG: solution path[8] is SOUTH, set (5,1) to ONPATH                   . LOG: solution path[8] is SOUTH, set (5,1) to ONPATH
LOG: solution path[9] is EAST, set (5,2) to ONPATH                    . LOG: solution path[9] is EAST, set (5,2) to ONPATH
LOG: solution path[10] is EAST, set (5,3) to ONPATH                   . LOG: solution path[10] is EAST, set (5,3) to ONPATH
LOG: solution path[11] is EAST, set (5,4) to ONPATH                   . LOG: solution path[11] is EAST, set (5,4) to ONPATH
LOG: solution path[12] is EAST, set (5,5) to ONPATH                   . LOG: solution path[12] is EAST, set (5,5) to ONPATH
LOG: solution path[13] is EAST, set (5,6) to ONPATH                   . LOG: solution path[13] is EAST, set (5,6) to ONPATH
LOG: solution path[14] is SOUTH, set (6,6) to ONPATH                  . LOG: solution path[14] is SOUTH, set (6,6) to ONPATH
LOG: solution path[15] is SOUTH, set (7,6) to ONPATH                  . LOG: solution path[15] is SOUTH, set (7,6) to ONPATH
LOG: solution path[16] is SOUTH, set (8,6) to ONPATH                  . LOG: solution path[16] is SOUTH, set (8,6) to ONPATH
LOG: solution END at (8,6)                                            . LOG: solution END at (8,6)
ret: 1                                                                . ret: 1
Maze AFTER Setting Solution                                           . Maze AFTER Setting Solution
maze: 10 rows 8 cols                                                  . maze: 10 rows 8 cols
      (1,6) start                                                     .       (1,6) start
      (8,6) end                                                       .       (8,6) end
maze tiles:                                                           . maze tiles:
########                                                              . ########
#.....S#                                                              . #.....S#
#.# ####                                                              . #.# ####
#.#    #                                                              . #.#    #
#.######                                                              . #.######
#......#                                                              . #......#
######.#                                                              . ######.#
# ##  .#                                                              . # ##  .#
# #  #E#                                                              . # #  #E#
########                                                              . ########
                                                                      ) 

```

LINE-BY-LINE DIFF of Expected vs Actual
---------------------------------------
No differences found

VALGRIND REPORT
---------------
The program is run on under valgrind as
  stdbuf -i 0 -o 0 -e 0 valgrind --error-exitcode=13 --leak-check=full --show-leak-kinds=all --track-origins=yes ./test_mazesolve_funcs maze_from_file_medium
which may be pasted onto a command line to run it.

```
==15607== Memcheck, a memory error detector
==15607== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==15607== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==15607== Command: ./test_mazesolve_funcs maze_from_file_medium
==15607== 
==15607== 
==15607== HEAP SUMMARY:
==15607==     in use at exit: 0 bytes in 0 blocks
==15607==   total heap usage: 69 allocs, 69 frees, 8,096 bytes allocated
==15607== 
==15607== All heap blocks were freed -- no leaks are possible
==15607== 
==15607== For lists of detected and suppressed errors, rerun with: -s
==15607== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

SUMMARY
-------
Test Passed
