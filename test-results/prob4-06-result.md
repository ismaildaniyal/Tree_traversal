(TEST 6) mazesolve_main1 : ok
=============================

COMMENTS
--------
Solve maze-medium1.txt without logging turned on.

PROGRAM: ./mazesolve_main data/maze-medium1.txt
-----------------------------------------------
To run this individual test in GDB use the command:
  gdb --args ./mazesolve_main data/maze-medium1.txt
but any input to the program must be typed within the debugger

FAILURE MESSAGES
----------------
None

SIDE-BY-SIDE DIFF of Expected vs Actual
---------------------------------------
. lines match; | lines differ; < expected line missing; > extra line in actual

```sdiff
===EXPECT===           ===ACTUAL===
maze: 10 rows 8 cols . maze: 10 rows 8 cols
      (1,6) start    .       (1,6) start
      (8,6) end      .       (8,6) end
maze tiles:          . maze tiles:
########             . ########
#     S#             . #     S#
# # ####             . # # ####
# #    #             . # #    #
# ######             . # ######
#      #             . #      #
###### #             . ###### #
# ##   #             . # ##   #
# #  #E#             . # #  #E#
########             . ########
                     ) 
                     ) 
SOLUTION:            . SOLUTION:
maze: 10 rows 8 cols . maze: 10 rows 8 cols
      (1,6) start    .       (1,6) start
      (8,6) end      .       (8,6) end
maze tiles:          . maze tiles:
########             . ########
#.....S#             . #.....S#
#.# ####             . #.# ####
#.#    #             . #.#    #
#.######             . #.######
#......#             . #......#
######.#             . ######.#
# ##  .#             . # ##  .#
# #  #E#             . # #  #E#
########             . ########
                     ) 
path length: 17      . path length: 17
 0: WEST             .  0: WEST
 1: WEST             .  1: WEST
 2: WEST             .  2: WEST
 3: WEST             .  3: WEST
 4: WEST             .  4: WEST
 5: SOUTH            .  5: SOUTH
 6: SOUTH            .  6: SOUTH
 7: SOUTH            .  7: SOUTH
 8: SOUTH            .  8: SOUTH
 9: EAST             .  9: EAST
10: EAST             . 10: EAST
11: EAST             . 11: EAST
12: EAST             . 12: EAST
13: EAST             . 13: EAST
14: SOUTH            . 14: SOUTH
15: SOUTH            . 15: SOUTH
16: SOUTH            . 16: SOUTH

```

LINE-BY-LINE DIFF of Expected vs Actual
---------------------------------------
No differences found

VALGRIND REPORT
---------------
The program is run on under valgrind as
  stdbuf -i 0 -o 0 -e 0 valgrind --error-exitcode=13 --leak-check=full --show-leak-kinds=all --track-origins=yes ./mazesolve_main data/maze-medium1.txt
which may be pasted onto a command line to run it.

```
==15604== Memcheck, a memory error detector
==15604== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==15604== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==15604== Command: ./mazesolve_main data/maze-medium1.txt
==15604== 
==15604== 
==15604== HEAP SUMMARY:
==15604==     in use at exit: 0 bytes in 0 blocks
==15604==   total heap usage: 69 allocs, 69 frees, 8,096 bytes allocated
==15604== 
==15604== All heap blocks were freed -- no leaks are possible
==15604== 
==15604== For lists of detected and suppressed errors, rerun with: -s
==15604== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

SUMMARY
-------
Test Passed
