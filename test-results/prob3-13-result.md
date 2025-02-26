(TEST 13) maze_set_solution3 : ok
=================================

COMMENTS
--------


PROGRAM: ./test_mazesolve_funcs maze_set_solution3
--------------------------------------------------
To run this individual test in GDB use the command:
  gdb --args ./test_mazesolve_funcs maze_set_solution3
but any input to the program must be typed within the debugger

FAILURE MESSAGES
----------------
None

SIDE-BY-SIDE DIFF of Expected vs Actual
---------------------------------------
. lines match; | lines differ; < expected line missing; > extra line in actual

```sdiff
===EXPECT===                                                             ===ACTUAL===
IF_TEST("maze_set_solution3") {                                        . IF_TEST("maze_set_solution3") {
    // No path exists from the Start to End tile and the End tile path .     // No path exists from the Start to End tile and the End tile path
    // is NULL in this example so the set_solution() function will     .     // is NULL in this example so the set_solution() function will
    // return 0 without making any changes to the maze.                .     // return 0 without making any changes to the maze.
    char *maze_str =                                                   .     char *maze_str =
      "########\n"                                                     .       "########\n"
      "#     S#\n"                                                     .       "#     S#\n"
      "# # ####\n"                                                     .       "# # ####\n"
      "# #    #\n"                                                     .       "# #    #\n"
      "# ######\n"                                                     .       "# ######\n"
      "#      #\n"                                                     .       "#      #\n"
      "###### #\n"                                                     .       "###### #\n"
      "# ##   #\n"                                                     .       "# ##   #\n"
      "#E#  # #\n"                                                     .       "#E#  # #\n"
      "########\n";                                                    .       "########\n";
    maze_t *maze = maze_from_string(maze_str);                         .     maze_t *maze = maze_from_string(maze_str);
    tile_t *end_tile = &maze->tiles[maze->end_row][maze->end_col];     .     tile_t *end_tile = &maze->tiles[maze->end_row][maze->end_col];
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
maze: 10 rows 8 cols                                                   . maze: 10 rows 8 cols
      (1,6) start                                                      .       (1,6) start
      (8,1) end                                                        .       (8,1) end
maze tiles:                                                            . maze tiles:
########                                                               . ########
#     S#                                                               . #     S#
# # ####                                                               . # # ####
# #    #                                                               . # #    #
# ######                                                               . # ######
#      #                                                               . #      #
###### #                                                               . ###### #
# ##   #                                                               . # ##   #
#E#  # #                                                               . #E#  # #
########                                                               . ########
                                                                       ) 
Setting Solution Path                                                  . Setting Solution Path
ret: 0                                                                 . ret: 0
Maze AFTER Setting Solution                                            . Maze AFTER Setting Solution
maze: 10 rows 8 cols                                                   . maze: 10 rows 8 cols
      (1,6) start                                                      .       (1,6) start
      (8,1) end                                                        .       (8,1) end
maze tiles:                                                            . maze tiles:
########                                                               . ########
#     S#                                                               . #     S#
# # ####                                                               . # # ####
# #    #                                                               . # #    #
# ######                                                               . # ######
#      #                                                               . #      #
###### #                                                               . ###### #
# ##   #                                                               . # ##   #
#E#  # #                                                               . #E#  # #
########                                                               . ########
                                                                       ) 

```

LINE-BY-LINE DIFF of Expected vs Actual
---------------------------------------
No differences found

VALGRIND REPORT
---------------
The program is run on under valgrind as
  stdbuf -i 0 -o 0 -e 0 valgrind --error-exitcode=13 --leak-check=full --show-leak-kinds=all --track-origins=yes ./test_mazesolve_funcs maze_set_solution3
which may be pasted onto a command line to run it.

```
==15552== Memcheck, a memory error detector
==15552== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==15552== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==15552== Command: ./test_mazesolve_funcs maze_set_solution3
==15552== 
==15552== 
==15552== HEAP SUMMARY:
==15552==     in use at exit: 0 bytes in 0 blocks
==15552==   total heap usage: 12 allocs, 12 frees, 2,040 bytes allocated
==15552== 
==15552== All heap blocks were freed -- no leaks are possible
==15552== 
==15552== For lists of detected and suppressed errors, rerun with: -s
==15552== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

SUMMARY
-------
Test Passed
