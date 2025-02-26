(TEST 5) maze_from_file_big : ok
================================

COMMENTS
--------


PROGRAM: ./test_mazesolve_funcs maze_from_file_big
--------------------------------------------------
To run this individual test in GDB use the command:
  gdb --args ./test_mazesolve_funcs maze_from_file_big
but any input to the program must be typed within the debugger

FAILURE MESSAGES
----------------
None

SIDE-BY-SIDE DIFF of Expected vs Actual
---------------------------------------
. lines match; | lines differ; < expected line missing; > extra line in actual

```sdiff
===EXPECT===                                                    ===ACTUAL===
IF_TEST("maze_from_file_big") {                               . IF_TEST("maze_from_file_big") {
    // Load a large maze from a file                          .     // Load a large maze from a file
    LOG_LEVEL = 0;              // no logging for this test   .     LOG_LEVEL = 0;              // no logging for this test
    maze_t *maze = maze_from_file("data/maze-big-mult1.txt"); .     maze_t *maze = maze_from_file("data/maze-big-mult1.txt");
    printf("LOADED MAZE:\n");                                 .     printf("LOADED MAZE:\n");
    maze_print_tiles(maze);                                   .     maze_print_tiles(maze);
    maze_free(maze);                                          .     maze_free(maze);
}                                                             . }
---OUTPUT---                                                  . ---OUTPUT---
LOADED MAZE:                                                  . LOADED MAZE:
maze: 21 rows 51 cols                                         . maze: 21 rows 51 cols
      (1,1) start                                             .       (1,1) start
      (19,50) end                                             .       (19,50) end
maze tiles:                                                   . maze tiles:
###################################################           . ###################################################
#S  #                                     #       #           . #S  #                                     #       #
### ########### ################# ##### # # ##### #           . ### ########### ################# ##### # # ##### #
# #     #     #       #       #   #   # #   #   # #           . # #     #     #       #       #   #   # #   #   # #
# ##### # ### # ##### # ##### # ### # # ##### ### #           . # ##### # ### # ##### # ##### # ### # # ##### ### #
#     #   # # #     # #   # #   #   # #   #     # #           . #     #   # # #     # #   # #   #   # #   #     # #
# ######### # ####### ### # ##### ### ### ### # # #           . # ######### # ####### ### # ##### ### ### ### # # #
# #         # #                         #   # #   #           . # #         # #                         #   # #   #
# # ##### ### # ##### ####### ######### ### # #####           . # # ##### ### # ##### ####### ######### ### # #####
# #   # #     # #   # #       #     #     # # #   #           . # #   # #     # #   # #       #     #     # # #   #
# ### # ####### # # ### ####### ### ####### # # # #           . # ### # ####### # # ### ####### ### ####### # # # #
#   #   #     #   #   # #       #           # # # #           . #   #   #     #   #   # #       #           # # # #
# ##### # ### # ##### # # ######### ######### ### #           . # ##### # ### # ##### # # ######### ######### ### #
#       #   #   #   #   #               #   #     #           . #       #   #   #   #   #               #   #     #
# # ##########  # # # ##### ########### # # ##### #           . # # ##########  # # # ##### ########### # # ##### #
# #   #           # # #   #     #     # # #     # #           . # #   #           # # #   #     #     # # #     # #
# ### ### ######### # # # # ##### ### # # ##### # #           . # ### ### ######### # # # # ##### ### # # ##### # #
#   #     # #     # # # # # #   # # #   # #   #   #           . #   #     # #     # # # # # #   # # #   # #   #   #
# # ####### # # ### ### # ### # # # ##### # # #####           . # # ####### # # ### ### # ### # # # ##### # # #####
# #           #         #     #   #         #     E           . # #           #         #     #   #         #     E
###################################################           . ###################################################
                                                              ) 

```

LINE-BY-LINE DIFF of Expected vs Actual
---------------------------------------
No differences found

VALGRIND REPORT
---------------
The program is run on under valgrind as
  stdbuf -i 0 -o 0 -e 0 valgrind --error-exitcode=13 --leak-check=full --show-leak-kinds=all --track-origins=yes ./test_mazesolve_funcs maze_from_file_big
which may be pasted onto a command line to run it.

```
==15603== Memcheck, a memory error detector
==15603== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==15603== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==15603== Command: ./test_mazesolve_funcs maze_from_file_big
==15603== 
==15603== 
==15603== HEAP SUMMARY:
==15603==     in use at exit: 0 bytes in 0 blocks
==15603==   total heap usage: 25 allocs, 25 frees, 30,480 bytes allocated
==15603== 
==15603== All heap blocks were freed -- no leaks are possible
==15603== 
==15603== For lists of detected and suppressed errors, rerun with: -s
==15603== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

SUMMARY
-------
Test Passed
