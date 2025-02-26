(TEST 11) maze_set_solution1 : ok
=================================

COMMENTS
--------


PROGRAM: ./test_mazesolve_funcs maze_set_solution1
--------------------------------------------------
To run this individual test in GDB use the command:
  gdb --args ./test_mazesolve_funcs maze_set_solution1
but any input to the program must be typed within the debugger

FAILURE MESSAGES
----------------
None

SIDE-BY-SIDE DIFF of Expected vs Actual
---------------------------------------
. lines match; | lines differ; < expected line missing; > extra line in actual

```sdiff
===EXPECT===                                                             ===ACTUAL===
IF_TEST("maze_set_solution1") {                                        . IF_TEST("maze_set_solution1") {
    // Set tile states to ONPATH between the Start and End tiles using .     // Set tile states to ONPATH between the Start and End tiles using
    // the path established during test setup for the End tile.        .     // the path established during test setup for the End tile.
    char *maze_str =                                                   .     char *maze_str =
      "#####\n"                                                        .       "#####\n"
      "# S #\n"                                                        .       "# S #\n"
      "# # #\n"                                                        .       "# # #\n"
      "# E #\n"                                                        .       "# E #\n"
      "#####\n";                                                       .       "#####\n";
    int path_len = 4;                                                  .     int path_len = 4;
    direction_t path[4] = {WEST,SOUTH,SOUTH,EAST};                     .     direction_t path[4] = {WEST,SOUTH,SOUTH,EAST};
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
maze: 5 rows 5 cols                                                    . maze: 5 rows 5 cols
      (1,2) start                                                      .       (1,2) start
      (3,2) end                                                        .       (3,2) end
maze tiles:                                                            . maze tiles:
#####                                                                  . #####
# S #                                                                  . # S #
# # #                                                                  . # # #
# E #                                                                  . # E #
#####                                                                  . #####
                                                                       ) 
Setting Solution Path                                                  . Setting Solution Path
LOG: solution START at (1,2)                                           . LOG: solution START at (1,2)
LOG: solution path[0] is WEST, set (1,1) to ONPATH                     . LOG: solution path[0] is WEST, set (1,1) to ONPATH
LOG: solution path[1] is SOUTH, set (2,1) to ONPATH                    . LOG: solution path[1] is SOUTH, set (2,1) to ONPATH
LOG: solution path[2] is SOUTH, set (3,1) to ONPATH                    . LOG: solution path[2] is SOUTH, set (3,1) to ONPATH
LOG: solution path[3] is EAST, set (3,2) to ONPATH                     . LOG: solution path[3] is EAST, set (3,2) to ONPATH
LOG: solution END at (3,2)                                             . LOG: solution END at (3,2)
ret: 1                                                                 . ret: 1
Maze AFTER Setting Solution                                            . Maze AFTER Setting Solution
maze: 5 rows 5 cols                                                    . maze: 5 rows 5 cols
      (1,2) start                                                      .       (1,2) start
      (3,2) end                                                        .       (3,2) end
maze tiles:                                                            . maze tiles:
#####                                                                  . #####
#.S #                                                                  . #.S #
#.# #                                                                  . #.# #
#.E #                                                                  . #.E #
#####                                                                  . #####
                                                                       ) 

```

LINE-BY-LINE DIFF of Expected vs Actual
---------------------------------------
No differences found

VALGRIND REPORT
---------------
The program is run on under valgrind as
  stdbuf -i 0 -o 0 -e 0 valgrind --error-exitcode=13 --leak-check=full --show-leak-kinds=all --track-origins=yes ./test_mazesolve_funcs maze_set_solution1
which may be pasted onto a command line to run it.

```
==15549== Memcheck, a memory error detector
==15549== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==15549== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==15549== Command: ./test_mazesolve_funcs maze_set_solution1
==15549== 
==15549== 
==15549== HEAP SUMMARY:
==15549==     in use at exit: 0 bytes in 0 blocks
==15549==   total heap usage: 8 allocs, 8 frees, 696 bytes allocated
==15549== 
==15549== All heap blocks were freed -- no leaks are possible
==15549== 
==15549== For lists of detected and suppressed errors, rerun with: -s
==15549== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

SUMMARY
-------
Test Passed
