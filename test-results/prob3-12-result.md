(TEST 12) maze_set_solution2 : ok
=================================

COMMENTS
--------


PROGRAM: ./test_mazesolve_funcs maze_set_solution2
--------------------------------------------------
To run this individual test in GDB use the command:
  gdb --args ./test_mazesolve_funcs maze_set_solution2
but any input to the program must be typed within the debugger

FAILURE MESSAGES
----------------
None

SIDE-BY-SIDE DIFF of Expected vs Actual
---------------------------------------
. lines match; | lines differ; < expected line missing; > extra line in actual

```sdiff
===EXPECT===                                                             ===ACTUAL===
IF_TEST("maze_set_solution2") {                                        . IF_TEST("maze_set_solution2") {
    // Set tile states to ONPATH between the Start and End tiles using .     // Set tile states to ONPATH between the Start and End tiles using
    // the path established during test setup for the End tile.        .     // the path established during test setup for the End tile.
    char *maze_str =                                                   .     char *maze_str =
      "################\n"                                             .       "################\n"
      "#S             #\n"                                             .       "#S             #\n"
      "# ### ###### # #\n"                                             .       "# ### ###### # #\n"
      "# ### ##E  #   #\n"                                             .       "# ### ##E  #   #\n"
      "# ### #### ##  #\n"                                             .       "# ### #### ##  #\n"
      "#              #\n"                                             .       "#              #\n"
      "################\n";                                            .       "################\n";
    int path_len = 17;                                                 .     int path_len = 17;
    direction_t path[17] =                                             .     direction_t path[17] =
      {SOUTH,SOUTH,SOUTH,SOUTH,EAST,EAST,EAST,EAST,EAST,               .       {SOUTH,SOUTH,SOUTH,SOUTH,EAST,EAST,EAST,EAST,EAST,
       EAST,EAST,EAST,EAST,NORTH,NORTH,WEST,WEST};                     .        EAST,EAST,EAST,EAST,NORTH,NORTH,WEST,WEST};
    maze_t *maze = maze_from_string(maze_str);                         .     maze_t *maze = maze_from_string(maze_str);
    tile_t *end_tile = &maze->tiles[maze->end_row][maze->end_col];     .     tile_t *end_tile = &maze->tiles[maze->end_row][maze->end_col];
    end_tile->path_len = path_len;                                     .     end_tile->path_len = path_len;
    end_tile->path = malloc(sizeof(direction_t)*path_len);             .     end_tile->path = malloc(sizeof(direction_t)*path_len);
    memcpy(end_tile->path, path, sizeof(direction_t)*path_len);        .     memcpy(end_tile->path, path, sizeof(direction_t)*path_len);
    printf("Maze BEFORE Setting Solution\n");                          .     printf("Maze BEFORE Setting Solution\n");
    maze_print_tiles(maze);                                            .     maze_print_tiles(maze);
    LOG_LEVEL = LOG_ALL;                                               .     LOG_LEVEL = LOG_ALL;
    printf("Setting Solution Path\n");                                 .     printf("Setting Solution Path\n");
    int ret = maze_set_solution(maze);                                 .     int ret = maze_set_solution(maze);
    printf("ret: %d\n",ret);                                           .     printf("ret: %d\n",ret);
    printf("Maze AFTER Setting Solution\n");                           .     printf("Maze AFTER Setting Solution\n");
    maze_print_tiles(maze);                                            .     maze_print_tiles(maze);
    maze_free(maze);                                                   .     maze_free(maze);
}                                                                      . }
---OUTPUT---                                                           . ---OUTPUT---
Maze BEFORE Setting Solution                                           . Maze BEFORE Setting Solution
maze: 7 rows 16 cols                                                   . maze: 7 rows 16 cols
      (1,1) start                                                      .       (1,1) start
      (3,8) end                                                        .       (3,8) end
maze tiles:                                                            . maze tiles:
################                                                       . ################
#S             #                                                       . #S             #
# ### ###### # #                                                       . # ### ###### # #
# ### ##E  #   #                                                       . # ### ##E  #   #
# ### #### ##  #                                                       . # ### #### ##  #
#              #                                                       . #              #
################                                                       . ################
                                                                       ) 
Setting Solution Path                                                  . Setting Solution Path
LOG: solution START at (1,1)                                           . LOG: solution START at (1,1)
LOG: solution path[0] is SOUTH, set (2,1) to ONPATH                    . LOG: solution path[0] is SOUTH, set (2,1) to ONPATH
LOG: solution path[1] is SOUTH, set (3,1) to ONPATH                    . LOG: solution path[1] is SOUTH, set (3,1) to ONPATH
LOG: solution path[2] is SOUTH, set (4,1) to ONPATH                    . LOG: solution path[2] is SOUTH, set (4,1) to ONPATH
LOG: solution path[3] is SOUTH, set (5,1) to ONPATH                    . LOG: solution path[3] is SOUTH, set (5,1) to ONPATH
LOG: solution path[4] is EAST, set (5,2) to ONPATH                     . LOG: solution path[4] is EAST, set (5,2) to ONPATH
LOG: solution path[5] is EAST, set (5,3) to ONPATH                     . LOG: solution path[5] is EAST, set (5,3) to ONPATH
LOG: solution path[6] is EAST, set (5,4) to ONPATH                     . LOG: solution path[6] is EAST, set (5,4) to ONPATH
LOG: solution path[7] is EAST, set (5,5) to ONPATH                     . LOG: solution path[7] is EAST, set (5,5) to ONPATH
LOG: solution path[8] is EAST, set (5,6) to ONPATH                     . LOG: solution path[8] is EAST, set (5,6) to ONPATH
LOG: solution path[9] is EAST, set (5,7) to ONPATH                     . LOG: solution path[9] is EAST, set (5,7) to ONPATH
LOG: solution path[10] is EAST, set (5,8) to ONPATH                    . LOG: solution path[10] is EAST, set (5,8) to ONPATH
LOG: solution path[11] is EAST, set (5,9) to ONPATH                    . LOG: solution path[11] is EAST, set (5,9) to ONPATH
LOG: solution path[12] is EAST, set (5,10) to ONPATH                   . LOG: solution path[12] is EAST, set (5,10) to ONPATH
LOG: solution path[13] is NORTH, set (4,10) to ONPATH                  . LOG: solution path[13] is NORTH, set (4,10) to ONPATH
LOG: solution path[14] is NORTH, set (3,10) to ONPATH                  . LOG: solution path[14] is NORTH, set (3,10) to ONPATH
LOG: solution path[15] is WEST, set (3,9) to ONPATH                    . LOG: solution path[15] is WEST, set (3,9) to ONPATH
LOG: solution path[16] is WEST, set (3,8) to ONPATH                    . LOG: solution path[16] is WEST, set (3,8) to ONPATH
LOG: solution END at (3,8)                                             . LOG: solution END at (3,8)
ret: 1                                                                 . ret: 1
Maze AFTER Setting Solution                                            . Maze AFTER Setting Solution
maze: 7 rows 16 cols                                                   . maze: 7 rows 16 cols
      (1,1) start                                                      .       (1,1) start
      (3,8) end                                                        .       (3,8) end
maze tiles:                                                            . maze tiles:
################                                                       . ################
#S             #                                                       . #S             #
#.### ###### # #                                                       . #.### ###### # #
#.### ##E..#   #                                                       . #.### ##E..#   #
#.### ####.##  #                                                       . #.### ####.##  #
#..........    #                                                       . #..........    #
################                                                       . ################
                                                                       ) 

```

LINE-BY-LINE DIFF of Expected vs Actual
---------------------------------------
No differences found

VALGRIND REPORT
---------------
The program is run on under valgrind as
  stdbuf -i 0 -o 0 -e 0 valgrind --error-exitcode=13 --leak-check=full --show-leak-kinds=all --track-origins=yes ./test_mazesolve_funcs maze_set_solution2
which may be pasted onto a command line to run it.

```
==15550== Memcheck, a memory error detector
==15550== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==15550== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==15550== Command: ./test_mazesolve_funcs maze_set_solution2
==15550== 
==15550== 
==15550== HEAP SUMMARY:
==15550==     in use at exit: 0 bytes in 0 blocks
==15550==   total heap usage: 10 allocs, 10 frees, 2,852 bytes allocated
==15550== 
==15550== All heap blocks were freed -- no leaks are possible
==15550== 
==15550== For lists of detected and suppressed errors, rerun with: -s
==15550== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

SUMMARY
-------
Test Passed
