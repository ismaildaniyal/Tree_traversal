(TEST 4) maze_from_file_room12 : ok
===================================

COMMENTS
--------


PROGRAM: ./test_mazesolve_funcs maze_from_file_room12
-----------------------------------------------------
To run this individual test in GDB use the command:
  gdb --args ./test_mazesolve_funcs maze_from_file_room12
but any input to the program must be typed within the debugger

FAILURE MESSAGES
----------------
None

SIDE-BY-SIDE DIFF of Expected vs Actual
---------------------------------------
. lines match; | lines differ; < expected line missing; > extra line in actual

```sdiff
===EXPECT===                                           ===ACTUAL===
IF_TEST("maze_from_file_room12") {                   . IF_TEST("maze_from_file_room12") {
    // Load 2 medium mazes from files and print them .     // Load 2 medium mazes from files and print them
    LOG_LEVEL = LOG_ALL;                             .     LOG_LEVEL = LOG_ALL;
    maze_t *maze;                                    .     maze_t *maze;
    maze = maze_from_file("data/maze-room1.txt");    .     maze = maze_from_file("data/maze-room1.txt");
    printf("LOADED MAZE:\n");                        .     printf("LOADED MAZE:\n");
    maze_print_tiles(maze);                          .     maze_print_tiles(maze);
    maze_free(maze);                                 .     maze_free(maze);
    maze = maze_from_file("data/maze-room2.txt");    .     maze = maze_from_file("data/maze-room2.txt");
    printf("LOADED MAZE:\n");                        .     printf("LOADED MAZE:\n");
    maze_print_tiles(maze);                          .     maze_print_tiles(maze);
    maze_free(maze);                                 .     maze_free(maze);
}                                                    . }
---OUTPUT---                                         . ---OUTPUT---
LOG: expecting 7 rows and 19 columns                 . LOG: expecting 7 rows and 19 columns
LOG: beginning to read tiles                         . LOG: beginning to read tiles
LOG: (0,0) has character '#' type 1                  . LOG: (0,0) has character '#' type 1
LOG: (0,1) has character '#' type 1                  . LOG: (0,1) has character '#' type 1
LOG: (0,2) has character '#' type 1                  . LOG: (0,2) has character '#' type 1
LOG: (0,3) has character '#' type 1                  . LOG: (0,3) has character '#' type 1
LOG: (0,4) has character '#' type 1                  . LOG: (0,4) has character '#' type 1
LOG: (0,5) has character '#' type 1                  . LOG: (0,5) has character '#' type 1
LOG: (0,6) has character '#' type 1                  . LOG: (0,6) has character '#' type 1
LOG: (0,7) has character '#' type 1                  . LOG: (0,7) has character '#' type 1
LOG: (0,8) has character '#' type 1                  . LOG: (0,8) has character '#' type 1
LOG: (0,9) has character '#' type 1                  . LOG: (0,9) has character '#' type 1
LOG: (0,10) has character '#' type 1                 . LOG: (0,10) has character '#' type 1
LOG: (0,11) has character '#' type 1                 . LOG: (0,11) has character '#' type 1
LOG: (0,12) has character '#' type 1                 . LOG: (0,12) has character '#' type 1
LOG: (0,13) has character '#' type 1                 . LOG: (0,13) has character '#' type 1
LOG: (0,14) has character '#' type 1                 . LOG: (0,14) has character '#' type 1
LOG: (0,15) has character '#' type 1                 . LOG: (0,15) has character '#' type 1
LOG: (0,16) has character '#' type 1                 . LOG: (0,16) has character '#' type 1
LOG: (0,17) has character '#' type 1                 . LOG: (0,17) has character '#' type 1
LOG: (0,18) has character '#' type 1                 . LOG: (0,18) has character '#' type 1
LOG: finished reading row 0 of tiles                 . LOG: finished reading row 0 of tiles
LOG: (1,0) has character '#' type 1                  . LOG: (1,0) has character '#' type 1
LOG: (1,1) has character ' ' type 2                  . LOG: (1,1) has character ' ' type 2
LOG: (1,2) has character ' ' type 2                  . LOG: (1,2) has character ' ' type 2
LOG: (1,3) has character ' ' type 2                  . LOG: (1,3) has character ' ' type 2
LOG: (1,4) has character ' ' type 2                  . LOG: (1,4) has character ' ' type 2
LOG: (1,5) has character ' ' type 2                  . LOG: (1,5) has character ' ' type 2
LOG: (1,6) has character ' ' type 2                  . LOG: (1,6) has character ' ' type 2
LOG: (1,7) has character ' ' type 2                  . LOG: (1,7) has character ' ' type 2
LOG: (1,8) has character ' ' type 2                  . LOG: (1,8) has character ' ' type 2
LOG: (1,9) has character ' ' type 2                  . LOG: (1,9) has character ' ' type 2
LOG: (1,10) has character ' ' type 2                 . LOG: (1,10) has character ' ' type 2
LOG: (1,11) has character '#' type 1                 . LOG: (1,11) has character '#' type 1
LOG: (1,12) has character ' ' type 2                 . LOG: (1,12) has character ' ' type 2
LOG: (1,13) has character ' ' type 2                 . LOG: (1,13) has character ' ' type 2
LOG: (1,14) has character ' ' type 2                 . LOG: (1,14) has character ' ' type 2
LOG: (1,15) has character ' ' type 2                 . LOG: (1,15) has character ' ' type 2
LOG: (1,16) has character '#' type 1                 . LOG: (1,16) has character '#' type 1
LOG: (1,17) has character ' ' type 2                 . LOG: (1,17) has character ' ' type 2
LOG: (1,18) has character '#' type 1                 . LOG: (1,18) has character '#' type 1
LOG: finished reading row 1 of tiles                 . LOG: finished reading row 1 of tiles
LOG: (2,0) has character '#' type 1                  . LOG: (2,0) has character '#' type 1
LOG: (2,1) has character ' ' type 2                  . LOG: (2,1) has character ' ' type 2
LOG: (2,2) has character '#' type 1                  . LOG: (2,2) has character '#' type 1
LOG: (2,3) has character '#' type 1                  . LOG: (2,3) has character '#' type 1
LOG: (2,4) has character '#' type 1                  . LOG: (2,4) has character '#' type 1
LOG: (2,5) has character ' ' type 2                  . LOG: (2,5) has character ' ' type 2
LOG: (2,6) has character ' ' type 2                  . LOG: (2,6) has character ' ' type 2
LOG: (2,7) has character '#' type 1                  . LOG: (2,7) has character '#' type 1
LOG: (2,8) has character '#' type 1                  . LOG: (2,8) has character '#' type 1
LOG: (2,9) has character ' ' type 2                  . LOG: (2,9) has character ' ' type 2
LOG: (2,10) has character ' ' type 2                 . LOG: (2,10) has character ' ' type 2
LOG: (2,11) has character ' ' type 2                 . LOG: (2,11) has character ' ' type 2
LOG: (2,12) has character ' ' type 2                 . LOG: (2,12) has character ' ' type 2
LOG: (2,13) has character '#' type 1                 . LOG: (2,13) has character '#' type 1
LOG: (2,14) has character '#' type 1                 . LOG: (2,14) has character '#' type 1
LOG: (2,15) has character ' ' type 2                 . LOG: (2,15) has character ' ' type 2
LOG: (2,16) has character '#' type 1                 . LOG: (2,16) has character '#' type 1
LOG: (2,17) has character ' ' type 2                 . LOG: (2,17) has character ' ' type 2
LOG: (2,18) has character '#' type 1                 . LOG: (2,18) has character '#' type 1
LOG: finished reading row 2 of tiles                 . LOG: finished reading row 2 of tiles
LOG: (3,0) has character '#' type 1                  . LOG: (3,0) has character '#' type 1
LOG: (3,1) has character ' ' type 2                  . LOG: (3,1) has character ' ' type 2
LOG: (3,2) has character ' ' type 2                  . LOG: (3,2) has character ' ' type 2
LOG: (3,3) has character '#' type 1                  . LOG: (3,3) has character '#' type 1
LOG: (3,4) has character '#' type 1                  . LOG: (3,4) has character '#' type 1
LOG: (3,5) has character ' ' type 2                  . LOG: (3,5) has character ' ' type 2
LOG: (3,6) has character ' ' type 2                  . LOG: (3,6) has character ' ' type 2
LOG: (3,7) has character '#' type 1                  . LOG: (3,7) has character '#' type 1
LOG: (3,8) has character ' ' type 2                  . LOG: (3,8) has character ' ' type 2
LOG: (3,9) has character 'S' type 4                  . LOG: (3,9) has character 'S' type 4
LOG: setting START at (3,9)                          . LOG: setting START at (3,9)
LOG: (3,10) has character ' ' type 2                 . LOG: (3,10) has character ' ' type 2
LOG: (3,11) has character '#' type 1                 . LOG: (3,11) has character '#' type 1
LOG: (3,12) has character ' ' type 2                 . LOG: (3,12) has character ' ' type 2
LOG: (3,13) has character ' ' type 2                 . LOG: (3,13) has character ' ' type 2
LOG: (3,14) has character '#' type 1                 . LOG: (3,14) has character '#' type 1
LOG: (3,15) has character ' ' type 2                 . LOG: (3,15) has character ' ' type 2
LOG: (3,16) has character '#' type 1                 . LOG: (3,16) has character '#' type 1
LOG: (3,17) has character ' ' type 2                 . LOG: (3,17) has character ' ' type 2
LOG: (3,18) has character '#' type 1                 . LOG: (3,18) has character '#' type 1
LOG: finished reading row 3 of tiles                 . LOG: finished reading row 3 of tiles
LOG: (4,0) has character '#' type 1                  . LOG: (4,0) has character '#' type 1
LOG: (4,1) has character '#' type 1                  . LOG: (4,1) has character '#' type 1
LOG: (4,2) has character ' ' type 2                  . LOG: (4,2) has character ' ' type 2
LOG: (4,3) has character ' ' type 2                  . LOG: (4,3) has character ' ' type 2
LOG: (4,4) has character '#' type 1                  . LOG: (4,4) has character '#' type 1
LOG: (4,5) has character ' ' type 2                  . LOG: (4,5) has character ' ' type 2
LOG: (4,6) has character ' ' type 2                  . LOG: (4,6) has character ' ' type 2
LOG: (4,7) has character '#' type 1                  . LOG: (4,7) has character '#' type 1
LOG: (4,8) has character '#' type 1                  . LOG: (4,8) has character '#' type 1
LOG: (4,9) has character '#' type 1                  . LOG: (4,9) has character '#' type 1
LOG: (4,10) has character '#' type 1                 . LOG: (4,10) has character '#' type 1
LOG: (4,11) has character '#' type 1                 . LOG: (4,11) has character '#' type 1
LOG: (4,12) has character ' ' type 2                 . LOG: (4,12) has character ' ' type 2
LOG: (4,13) has character ' ' type 2                 . LOG: (4,13) has character ' ' type 2
LOG: (4,14) has character '#' type 1                 . LOG: (4,14) has character '#' type 1
LOG: (4,15) has character ' ' type 2                 . LOG: (4,15) has character ' ' type 2
LOG: (4,16) has character '#' type 1                 . LOG: (4,16) has character '#' type 1
LOG: (4,17) has character ' ' type 2                 . LOG: (4,17) has character ' ' type 2
LOG: (4,18) has character '#' type 1                 . LOG: (4,18) has character '#' type 1
LOG: finished reading row 4 of tiles                 . LOG: finished reading row 4 of tiles
LOG: (5,0) has character '#' type 1                  . LOG: (5,0) has character '#' type 1
LOG: (5,1) has character 'E' type 5                  . LOG: (5,1) has character 'E' type 5
LOG: setting END at (5,1)                            . LOG: setting END at (5,1)
LOG: (5,2) has character ' ' type 2                  . LOG: (5,2) has character ' ' type 2
LOG: (5,3) has character ' ' type 2                  . LOG: (5,3) has character ' ' type 2
LOG: (5,4) has character '#' type 1                  . LOG: (5,4) has character '#' type 1
LOG: (5,5) has character ' ' type 2                  . LOG: (5,5) has character ' ' type 2
LOG: (5,6) has character ' ' type 2                  . LOG: (5,6) has character ' ' type 2
LOG: (5,7) has character ' ' type 2                  . LOG: (5,7) has character ' ' type 2
LOG: (5,8) has character ' ' type 2                  . LOG: (5,8) has character ' ' type 2
LOG: (5,9) has character ' ' type 2                  . LOG: (5,9) has character ' ' type 2
LOG: (5,10) has character ' ' type 2                 . LOG: (5,10) has character ' ' type 2
LOG: (5,11) has character ' ' type 2                 . LOG: (5,11) has character ' ' type 2
LOG: (5,12) has character ' ' type 2                 . LOG: (5,12) has character ' ' type 2
LOG: (5,13) has character ' ' type 2                 . LOG: (5,13) has character ' ' type 2
LOG: (5,14) has character '#' type 1                 . LOG: (5,14) has character '#' type 1
LOG: (5,15) has character ' ' type 2                 . LOG: (5,15) has character ' ' type 2
LOG: (5,16) has character ' ' type 2                 . LOG: (5,16) has character ' ' type 2
LOG: (5,17) has character ' ' type 2                 . LOG: (5,17) has character ' ' type 2
LOG: (5,18) has character '#' type 1                 . LOG: (5,18) has character '#' type 1
LOG: finished reading row 5 of tiles                 . LOG: finished reading row 5 of tiles
LOG: (6,0) has character '#' type 1                  . LOG: (6,0) has character '#' type 1
LOG: (6,1) has character '#' type 1                  . LOG: (6,1) has character '#' type 1
LOG: (6,2) has character '#' type 1                  . LOG: (6,2) has character '#' type 1
LOG: (6,3) has character '#' type 1                  . LOG: (6,3) has character '#' type 1
LOG: (6,4) has character '#' type 1                  . LOG: (6,4) has character '#' type 1
LOG: (6,5) has character '#' type 1                  . LOG: (6,5) has character '#' type 1
LOG: (6,6) has character '#' type 1                  . LOG: (6,6) has character '#' type 1
LOG: (6,7) has character '#' type 1                  . LOG: (6,7) has character '#' type 1
LOG: (6,8) has character '#' type 1                  . LOG: (6,8) has character '#' type 1
LOG: (6,9) has character '#' type 1                  . LOG: (6,9) has character '#' type 1
LOG: (6,10) has character '#' type 1                 . LOG: (6,10) has character '#' type 1
LOG: (6,11) has character '#' type 1                 . LOG: (6,11) has character '#' type 1
LOG: (6,12) has character '#' type 1                 . LOG: (6,12) has character '#' type 1
LOG: (6,13) has character '#' type 1                 . LOG: (6,13) has character '#' type 1
LOG: (6,14) has character '#' type 1                 . LOG: (6,14) has character '#' type 1
LOG: (6,15) has character '#' type 1                 . LOG: (6,15) has character '#' type 1
LOG: (6,16) has character '#' type 1                 . LOG: (6,16) has character '#' type 1
LOG: (6,17) has character '#' type 1                 . LOG: (6,17) has character '#' type 1
LOG: (6,18) has character '#' type 1                 . LOG: (6,18) has character '#' type 1
LOG: finished reading row 6 of tiles                 . LOG: finished reading row 6 of tiles
LOADED MAZE:                                         . LOADED MAZE:
maze: 7 rows 19 cols                                 . maze: 7 rows 19 cols
      (3,9) start                                    .       (3,9) start
      (5,1) end                                      .       (5,1) end
maze tiles:                                          . maze tiles:
###################                                  . ###################
#          #    # #                                  . #          #    # #
# ###  ##    ## # #                                  . # ###  ##    ## # #
#  ##  # S #  # # #                                  . #  ##  # S #  # # #
##  #  #####  # # #                                  . ##  #  #####  # # #
#E  #         #   #                                  . #E  #         #   #
###################                                  . ###################
                                                     ) 
LOG: expecting 9 rows and 22 columns                 . LOG: expecting 9 rows and 22 columns
LOG: beginning to read tiles                         . LOG: beginning to read tiles
LOG: (0,0) has character '#' type 1                  . LOG: (0,0) has character '#' type 1
LOG: (0,1) has character '#' type 1                  . LOG: (0,1) has character '#' type 1
LOG: (0,2) has character '#' type 1                  . LOG: (0,2) has character '#' type 1
LOG: (0,3) has character '#' type 1                  . LOG: (0,3) has character '#' type 1
LOG: (0,4) has character '#' type 1                  . LOG: (0,4) has character '#' type 1
LOG: (0,5) has character '#' type 1                  . LOG: (0,5) has character '#' type 1
LOG: (0,6) has character '#' type 1                  . LOG: (0,6) has character '#' type 1
LOG: (0,7) has character '#' type 1                  . LOG: (0,7) has character '#' type 1
LOG: (0,8) has character '#' type 1                  . LOG: (0,8) has character '#' type 1
LOG: (0,9) has character '#' type 1                  . LOG: (0,9) has character '#' type 1
LOG: (0,10) has character '#' type 1                 . LOG: (0,10) has character '#' type 1
LOG: (0,11) has character '#' type 1                 . LOG: (0,11) has character '#' type 1
LOG: (0,12) has character '#' type 1                 . LOG: (0,12) has character '#' type 1
LOG: (0,13) has character '#' type 1                 . LOG: (0,13) has character '#' type 1
LOG: (0,14) has character '#' type 1                 . LOG: (0,14) has character '#' type 1
LOG: (0,15) has character '#' type 1                 . LOG: (0,15) has character '#' type 1
LOG: (0,16) has character '#' type 1                 . LOG: (0,16) has character '#' type 1
LOG: (0,17) has character '#' type 1                 . LOG: (0,17) has character '#' type 1
LOG: (0,18) has character '#' type 1                 . LOG: (0,18) has character '#' type 1
LOG: (0,19) has character '#' type 1                 . LOG: (0,19) has character '#' type 1
LOG: (0,20) has character '#' type 1                 . LOG: (0,20) has character '#' type 1
LOG: (0,21) has character '#' type 1                 . LOG: (0,21) has character '#' type 1
LOG: finished reading row 0 of tiles                 . LOG: finished reading row 0 of tiles
LOG: (1,0) has character '#' type 1                  . LOG: (1,0) has character '#' type 1
LOG: (1,1) has character ' ' type 2                  . LOG: (1,1) has character ' ' type 2
LOG: (1,2) has character ' ' type 2                  . LOG: (1,2) has character ' ' type 2
LOG: (1,3) has character ' ' type 2                  . LOG: (1,3) has character ' ' type 2
LOG: (1,4) has character ' ' type 2                  . LOG: (1,4) has character ' ' type 2
LOG: (1,5) has character '#' type 1                  . LOG: (1,5) has character '#' type 1
LOG: (1,6) has character ' ' type 2                  . LOG: (1,6) has character ' ' type 2
LOG: (1,7) has character '#' type 1                  . LOG: (1,7) has character '#' type 1
LOG: (1,8) has character ' ' type 2                  . LOG: (1,8) has character ' ' type 2
LOG: (1,9) has character ' ' type 2                  . LOG: (1,9) has character ' ' type 2
LOG: (1,10) has character ' ' type 2                 . LOG: (1,10) has character ' ' type 2
LOG: (1,11) has character ' ' type 2                 . LOG: (1,11) has character ' ' type 2
LOG: (1,12) has character ' ' type 2                 . LOG: (1,12) has character ' ' type 2
LOG: (1,13) has character ' ' type 2                 . LOG: (1,13) has character ' ' type 2
LOG: (1,14) has character ' ' type 2                 . LOG: (1,14) has character ' ' type 2
LOG: (1,15) has character ' ' type 2                 . LOG: (1,15) has character ' ' type 2
LOG: (1,16) has character ' ' type 2                 . LOG: (1,16) has character ' ' type 2
LOG: (1,17) has character '#' type 1                 . LOG: (1,17) has character '#' type 1
LOG: (1,18) has character ' ' type 2                 . LOG: (1,18) has character ' ' type 2
LOG: (1,19) has character ' ' type 2                 . LOG: (1,19) has character ' ' type 2
LOG: (1,20) has character ' ' type 2                 . LOG: (1,20) has character ' ' type 2
LOG: (1,21) has character '#' type 1                 . LOG: (1,21) has character '#' type 1
LOG: finished reading row 1 of tiles                 . LOG: finished reading row 1 of tiles
LOG: (2,0) has character '#' type 1                  . LOG: (2,0) has character '#' type 1
LOG: (2,1) has character ' ' type 2                  . LOG: (2,1) has character ' ' type 2
LOG: (2,2) has character ' ' type 2                  . LOG: (2,2) has character ' ' type 2
LOG: (2,3) has character ' ' type 2                  . LOG: (2,3) has character ' ' type 2
LOG: (2,4) has character ' ' type 2                  . LOG: (2,4) has character ' ' type 2
LOG: (2,5) has character '#' type 1                  . LOG: (2,5) has character '#' type 1
LOG: (2,6) has character ' ' type 2                  . LOG: (2,6) has character ' ' type 2
LOG: (2,7) has character '#' type 1                  . LOG: (2,7) has character '#' type 1
LOG: (2,8) has character ' ' type 2                  . LOG: (2,8) has character ' ' type 2
LOG: (2,9) has character ' ' type 2                  . LOG: (2,9) has character ' ' type 2
LOG: (2,10) has character 'E' type 5                 . LOG: (2,10) has character 'E' type 5
LOG: setting END at (2,10)                           . LOG: setting END at (2,10)
LOG: (2,11) has character ' ' type 2                 . LOG: (2,11) has character ' ' type 2
LOG: (2,12) has character '#' type 1                 . LOG: (2,12) has character '#' type 1
LOG: (2,13) has character '#' type 1                 . LOG: (2,13) has character '#' type 1
LOG: (2,14) has character '#' type 1                 . LOG: (2,14) has character '#' type 1
LOG: (2,15) has character '#' type 1                 . LOG: (2,15) has character '#' type 1
LOG: (2,16) has character ' ' type 2                 . LOG: (2,16) has character ' ' type 2
LOG: (2,17) has character '#' type 1                 . LOG: (2,17) has character '#' type 1
LOG: (2,18) has character ' ' type 2                 . LOG: (2,18) has character ' ' type 2
LOG: (2,19) has character ' ' type 2                 . LOG: (2,19) has character ' ' type 2
LOG: (2,20) has character ' ' type 2                 . LOG: (2,20) has character ' ' type 2
LOG: (2,21) has character '#' type 1                 . LOG: (2,21) has character '#' type 1
LOG: finished reading row 2 of tiles                 . LOG: finished reading row 2 of tiles
LOG: (3,0) has character '#' type 1                  . LOG: (3,0) has character '#' type 1
LOG: (3,1) has character '#' type 1                  . LOG: (3,1) has character '#' type 1
LOG: (3,2) has character ' ' type 2                  . LOG: (3,2) has character ' ' type 2
LOG: (3,3) has character '#' type 1                  . LOG: (3,3) has character '#' type 1
LOG: (3,4) has character '#' type 1                  . LOG: (3,4) has character '#' type 1
LOG: (3,5) has character '#' type 1                  . LOG: (3,5) has character '#' type 1
LOG: (3,6) has character ' ' type 2                  . LOG: (3,6) has character ' ' type 2
LOG: (3,7) has character '#' type 1                  . LOG: (3,7) has character '#' type 1
LOG: (3,8) has character '#' type 1                  . LOG: (3,8) has character '#' type 1
LOG: (3,9) has character '#' type 1                  . LOG: (3,9) has character '#' type 1
LOG: (3,10) has character '#' type 1                 . LOG: (3,10) has character '#' type 1
LOG: (3,11) has character '#' type 1                 . LOG: (3,11) has character '#' type 1
LOG: (3,12) has character '#' type 1                 . LOG: (3,12) has character '#' type 1
LOG: (3,13) has character ' ' type 2                 . LOG: (3,13) has character ' ' type 2
LOG: (3,14) has character ' ' type 2                 . LOG: (3,14) has character ' ' type 2
LOG: (3,15) has character '#' type 1                 . LOG: (3,15) has character '#' type 1
LOG: (3,16) has character ' ' type 2                 . LOG: (3,16) has character ' ' type 2
LOG: (3,17) has character '#' type 1                 . LOG: (3,17) has character '#' type 1
LOG: (3,18) has character ' ' type 2                 . LOG: (3,18) has character ' ' type 2
LOG: (3,19) has character '#' type 1                 . LOG: (3,19) has character '#' type 1
LOG: (3,20) has character ' ' type 2                 . LOG: (3,20) has character ' ' type 2
LOG: (3,21) has character '#' type 1                 . LOG: (3,21) has character '#' type 1
LOG: finished reading row 3 of tiles                 . LOG: finished reading row 3 of tiles
LOG: (4,0) has character '#' type 1                  . LOG: (4,0) has character '#' type 1
LOG: (4,1) has character ' ' type 2                  . LOG: (4,1) has character ' ' type 2
LOG: (4,2) has character ' ' type 2                  . LOG: (4,2) has character ' ' type 2
LOG: (4,3) has character ' ' type 2                  . LOG: (4,3) has character ' ' type 2
LOG: (4,4) has character ' ' type 2                  . LOG: (4,4) has character ' ' type 2
LOG: (4,5) has character '#' type 1                  . LOG: (4,5) has character '#' type 1
LOG: (4,6) has character ' ' type 2                  . LOG: (4,6) has character ' ' type 2
LOG: (4,7) has character ' ' type 2                  . LOG: (4,7) has character ' ' type 2
LOG: (4,8) has character ' ' type 2                  . LOG: (4,8) has character ' ' type 2
LOG: (4,9) has character ' ' type 2                  . LOG: (4,9) has character ' ' type 2
LOG: (4,10) has character ' ' type 2                 . LOG: (4,10) has character ' ' type 2
LOG: (4,11) has character ' ' type 2                 . LOG: (4,11) has character ' ' type 2
LOG: (4,12) has character '#' type 1                 . LOG: (4,12) has character '#' type 1
LOG: (4,13) has character ' ' type 2                 . LOG: (4,13) has character ' ' type 2
LOG: (4,14) has character ' ' type 2                 . LOG: (4,14) has character ' ' type 2
LOG: (4,15) has character '#' type 1                 . LOG: (4,15) has character '#' type 1
LOG: (4,16) has character ' ' type 2                 . LOG: (4,16) has character ' ' type 2
LOG: (4,17) has character '#' type 1                 . LOG: (4,17) has character '#' type 1
LOG: (4,18) has character ' ' type 2                 . LOG: (4,18) has character ' ' type 2
LOG: (4,19) has character '#' type 1                 . LOG: (4,19) has character '#' type 1
LOG: (4,20) has character ' ' type 2                 . LOG: (4,20) has character ' ' type 2
LOG: (4,21) has character '#' type 1                 . LOG: (4,21) has character '#' type 1
LOG: finished reading row 4 of tiles                 . LOG: finished reading row 4 of tiles
LOG: (5,0) has character '#' type 1                  . LOG: (5,0) has character '#' type 1
LOG: (5,1) has character '#' type 1                  . LOG: (5,1) has character '#' type 1
LOG: (5,2) has character ' ' type 2                  . LOG: (5,2) has character ' ' type 2
LOG: (5,3) has character ' ' type 2                  . LOG: (5,3) has character ' ' type 2
LOG: (5,4) has character '#' type 1                  . LOG: (5,4) has character '#' type 1
LOG: (5,5) has character '#' type 1                  . LOG: (5,5) has character '#' type 1
LOG: (5,6) has character ' ' type 2                  . LOG: (5,6) has character ' ' type 2
LOG: (5,7) has character '#' type 1                  . LOG: (5,7) has character '#' type 1
LOG: (5,8) has character '#' type 1                  . LOG: (5,8) has character '#' type 1
LOG: (5,9) has character ' ' type 2                  . LOG: (5,9) has character ' ' type 2
LOG: (5,10) has character 'S' type 4                 . LOG: (5,10) has character 'S' type 4
LOG: setting START at (5,10)                         . LOG: setting START at (5,10)
LOG: (5,11) has character ' ' type 2                 . LOG: (5,11) has character ' ' type 2
LOG: (5,12) has character '#' type 1                 . LOG: (5,12) has character '#' type 1
LOG: (5,13) has character '#' type 1                 . LOG: (5,13) has character '#' type 1
LOG: (5,14) has character ' ' type 2                 . LOG: (5,14) has character ' ' type 2
LOG: (5,15) has character '#' type 1                 . LOG: (5,15) has character '#' type 1
LOG: (5,16) has character ' ' type 2                 . LOG: (5,16) has character ' ' type 2
LOG: (5,17) has character '#' type 1                 . LOG: (5,17) has character '#' type 1
LOG: (5,18) has character ' ' type 2                 . LOG: (5,18) has character ' ' type 2
LOG: (5,19) has character '#' type 1                 . LOG: (5,19) has character '#' type 1
LOG: (5,20) has character '#' type 1                 . LOG: (5,20) has character '#' type 1
LOG: (5,21) has character '#' type 1                 . LOG: (5,21) has character '#' type 1
LOG: finished reading row 5 of tiles                 . LOG: finished reading row 5 of tiles
LOG: (6,0) has character '#' type 1                  . LOG: (6,0) has character '#' type 1
LOG: (6,1) has character ' ' type 2                  . LOG: (6,1) has character ' ' type 2
LOG: (6,2) has character ' ' type 2                  . LOG: (6,2) has character ' ' type 2
LOG: (6,3) has character '#' type 1                  . LOG: (6,3) has character '#' type 1
LOG: (6,4) has character ' ' type 2                  . LOG: (6,4) has character ' ' type 2
LOG: (6,5) has character ' ' type 2                  . LOG: (6,5) has character ' ' type 2
LOG: (6,6) has character ' ' type 2                  . LOG: (6,6) has character ' ' type 2
LOG: (6,7) has character ' ' type 2                  . LOG: (6,7) has character ' ' type 2
LOG: (6,8) has character '#' type 1                  . LOG: (6,8) has character '#' type 1
LOG: (6,9) has character ' ' type 2                  . LOG: (6,9) has character ' ' type 2
LOG: (6,10) has character ' ' type 2                 . LOG: (6,10) has character ' ' type 2
LOG: (6,11) has character ' ' type 2                 . LOG: (6,11) has character ' ' type 2
LOG: (6,12) has character ' ' type 2                 . LOG: (6,12) has character ' ' type 2
LOG: (6,13) has character ' ' type 2                 . LOG: (6,13) has character ' ' type 2
LOG: (6,14) has character ' ' type 2                 . LOG: (6,14) has character ' ' type 2
LOG: (6,15) has character ' ' type 2                 . LOG: (6,15) has character ' ' type 2
LOG: (6,16) has character ' ' type 2                 . LOG: (6,16) has character ' ' type 2
LOG: (6,17) has character ' ' type 2                 . LOG: (6,17) has character ' ' type 2
LOG: (6,18) has character ' ' type 2                 . LOG: (6,18) has character ' ' type 2
LOG: (6,19) has character ' ' type 2                 . LOG: (6,19) has character ' ' type 2
LOG: (6,20) has character ' ' type 2                 . LOG: (6,20) has character ' ' type 2
LOG: (6,21) has character '#' type 1                 . LOG: (6,21) has character '#' type 1
LOG: finished reading row 6 of tiles                 . LOG: finished reading row 6 of tiles
LOG: (7,0) has character '#' type 1                  . LOG: (7,0) has character '#' type 1
LOG: (7,1) has character ' ' type 2                  . LOG: (7,1) has character ' ' type 2
LOG: (7,2) has character ' ' type 2                  . LOG: (7,2) has character ' ' type 2
LOG: (7,3) has character ' ' type 2                  . LOG: (7,3) has character ' ' type 2
LOG: (7,4) has character ' ' type 2                  . LOG: (7,4) has character ' ' type 2
LOG: (7,5) has character ' ' type 2                  . LOG: (7,5) has character ' ' type 2
LOG: (7,6) has character ' ' type 2                  . LOG: (7,6) has character ' ' type 2
LOG: (7,7) has character ' ' type 2                  . LOG: (7,7) has character ' ' type 2
LOG: (7,8) has character '#' type 1                  . LOG: (7,8) has character '#' type 1
LOG: (7,9) has character '#' type 1                  . LOG: (7,9) has character '#' type 1
LOG: (7,10) has character '#' type 1                 . LOG: (7,10) has character '#' type 1
LOG: (7,11) has character '#' type 1                 . LOG: (7,11) has character '#' type 1
LOG: (7,12) has character '#' type 1                 . LOG: (7,12) has character '#' type 1
LOG: (7,13) has character '#' type 1                 . LOG: (7,13) has character '#' type 1
LOG: (7,14) has character ' ' type 2                 . LOG: (7,14) has character ' ' type 2
LOG: (7,15) has character ' ' type 2                 . LOG: (7,15) has character ' ' type 2
LOG: (7,16) has character ' ' type 2                 . LOG: (7,16) has character ' ' type 2
LOG: (7,17) has character ' ' type 2                 . LOG: (7,17) has character ' ' type 2
LOG: (7,18) has character '#' type 1                 . LOG: (7,18) has character '#' type 1
LOG: (7,19) has character ' ' type 2                 . LOG: (7,19) has character ' ' type 2
LOG: (7,20) has character ' ' type 2                 . LOG: (7,20) has character ' ' type 2
LOG: (7,21) has character '#' type 1                 . LOG: (7,21) has character '#' type 1
LOG: finished reading row 7 of tiles                 . LOG: finished reading row 7 of tiles
LOG: (8,0) has character '#' type 1                  . LOG: (8,0) has character '#' type 1
LOG: (8,1) has character '#' type 1                  . LOG: (8,1) has character '#' type 1
LOG: (8,2) has character '#' type 1                  . LOG: (8,2) has character '#' type 1
LOG: (8,3) has character '#' type 1                  . LOG: (8,3) has character '#' type 1
LOG: (8,4) has character '#' type 1                  . LOG: (8,4) has character '#' type 1
LOG: (8,5) has character '#' type 1                  . LOG: (8,5) has character '#' type 1
LOG: (8,6) has character '#' type 1                  . LOG: (8,6) has character '#' type 1
LOG: (8,7) has character '#' type 1                  . LOG: (8,7) has character '#' type 1
LOG: (8,8) has character '#' type 1                  . LOG: (8,8) has character '#' type 1
LOG: (8,9) has character '#' type 1                  . LOG: (8,9) has character '#' type 1
LOG: (8,10) has character '#' type 1                 . LOG: (8,10) has character '#' type 1
LOG: (8,11) has character '#' type 1                 . LOG: (8,11) has character '#' type 1
LOG: (8,12) has character '#' type 1                 . LOG: (8,12) has character '#' type 1
LOG: (8,13) has character '#' type 1                 . LOG: (8,13) has character '#' type 1
LOG: (8,14) has character '#' type 1                 . LOG: (8,14) has character '#' type 1
LOG: (8,15) has character '#' type 1                 . LOG: (8,15) has character '#' type 1
LOG: (8,16) has character '#' type 1                 . LOG: (8,16) has character '#' type 1
LOG: (8,17) has character '#' type 1                 . LOG: (8,17) has character '#' type 1
LOG: (8,18) has character '#' type 1                 . LOG: (8,18) has character '#' type 1
LOG: (8,19) has character '#' type 1                 . LOG: (8,19) has character '#' type 1
LOG: (8,20) has character '#' type 1                 . LOG: (8,20) has character '#' type 1
LOG: (8,21) has character '#' type 1                 . LOG: (8,21) has character '#' type 1
LOG: finished reading row 8 of tiles                 . LOG: finished reading row 8 of tiles
LOADED MAZE:                                         . LOADED MAZE:
maze: 9 rows 22 cols                                 . maze: 9 rows 22 cols
      (5,10) start                                   .       (5,10) start
      (2,10) end                                     .       (2,10) end
maze tiles:                                          . maze tiles:
######################                               . ######################
#    # #         #   #                               . #    # #         #   #
#    # #  E #### #   #                               . #    # #  E #### #   #
## ### ######  # # # #                               . ## ### ######  # # # #
#    #      #  # # # #                               . #    #      #  # # # #
##  ## ## S ## # # ###                               . ##  ## ## S ## # # ###
#  #    #            #                               . #  #    #            #
#       ######    #  #                               . #       ######    #  #
######################                               . ######################
                                                     ) 

```

LINE-BY-LINE DIFF of Expected vs Actual
---------------------------------------
No differences found

VALGRIND REPORT
---------------
The program is run on under valgrind as
  stdbuf -i 0 -o 0 -e 0 valgrind --error-exitcode=13 --leak-check=full --show-leak-kinds=all --track-origins=yes ./test_mazesolve_funcs maze_from_file_room12
which may be pasted onto a command line to run it.

```
==15606== Memcheck, a memory error detector
==15606== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==15606== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==15606== Command: ./test_mazesolve_funcs maze_from_file_room12
==15606== 
==15606== 
==15606== HEAP SUMMARY:
==15606==     in use at exit: 0 bytes in 0 blocks
==15606==   total heap usage: 24 allocs, 24 frees, 17,288 bytes allocated
==15606== 
==15606== All heap blocks were freed -- no leaks are possible
==15606== 
==15606== For lists of detected and suppressed errors, rerun with: -s
==15606== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

SUMMARY
-------
Test Passed
