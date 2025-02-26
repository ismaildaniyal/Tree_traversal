(TEST 9) mazesolve_main4_special MULTIPART : ok
===============================================

COMMENTS
--------
Runs mazesolve_main on two special cases.

Test Segment 1 : ok
-------------------
** Missing File
Run the main program on a missing file to ensure it detects the
missing file and bails gracefully. The program should return exit code
1 from its main() function in this case.

### PROGRAM: ./mazesolve_main data/no-such-file.txt
To run this individual test in GDB use the command:
gdb --args ./mazesolve_main data/no-such-file.txt
but any input to the program must be typed within the debugger

### FAILURE MESSAGES
None

### SIDE-BY-SIDE DIFF of Expected vs Actual
. lines match; | lines differ; < expected line missing; > extra line in actual

```sdiff
===EXPECT===                                          ===ACTUAL===
ERROR: could not open file data/no-such-file.txt    . ERROR: could not open file data/no-such-file.txt
Could not load maze file. Exiting with error code 1 . Could not load maze file. Exiting with error code 1

```

### LINE-BY-LINE DIFF of Expected vs Actual
No differences found

### VALGRIND REPORT
The program is run on under valgrind as
stdbuf -i 0 -o 0 -e 0 valgrind --error-exitcode=13 --leak-check=full --show-leak-kinds=all --track-origins=yes ./mazesolve_main data/no-such-file.txt
which may be pasted onto a command line to run it.

```
==15619== Memcheck, a memory error detector
==15619== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==15619== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==15619== Command: ./mazesolve_main data/no-such-file.txt
==15619== 
==15619== 
==15619== HEAP SUMMARY:
==15619==     in use at exit: 0 bytes in 0 blocks
==15619==   total heap usage: 1 allocs, 1 frees, 472 bytes allocated
==15619== 
==15619== All heap blocks were freed -- no leaks are possible
==15619== 
==15619== For lists of detected and suppressed errors, rerun with: -s
==15619== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

Test Segment 2 : ok
-------------------
** Unreachable Ending
Attempt to solve the maze-unreachable1.txt which does not have a path
from Start to End. Checks that the output is correct in this case.

### PROGRAM: ./mazesolve_main -log 4 data/maze-unreachable1.txt
To run this individual test in GDB use the command:
gdb --args ./mazesolve_main -log 4 data/maze-unreachable1.txt
but any input to the program must be typed within the debugger

### FAILURE MESSAGES
None

### SIDE-BY-SIDE DIFF of Expected vs Actual
. lines match; | lines differ; < expected line missing; > extra line in actual

```sdiff
===EXPECT===                                                      ===ACTUAL===
maze: 10 rows 8 cols                                            . maze: 10 rows 8 cols
      (1,6) start                                               .       (1,6) start
      (8,1) end                                                 .       (8,1) end
maze tiles:                                                     . maze tiles:
########                                                        . ########
#     S#                                                        . #     S#
# # ####                                                        . # # ####
# #    #                                                        . # #    #
# ######                                                        . # ######
#      #                                                        . #      #
###### #                                                        . ###### #
# ##   #                                                        . # ##   #
#E#  # #                                                        . #E#  # #
########                                                        . ########
                                                                ) 
LOG: BFS initialization complete                                . LOG: BFS initialization complete
########:  0                                                    . ########:  0
#     0#:  1                                                    . #     0#:  1
# # ####:  2                                                    . # # ####:  2
# #    #:  3                                                    . # #    #:  3
# ######:  4                                                    . # ######:  4
#      #:  5                                                    . #      #:  5
###### #:  6                                                    . ###### #:  6
# ##   #:  7                                                    . # ##   #:  7
#E#  # #:  8                                                    . #E#  # #:  8
########:  9                                                    . ########:  9
01234567                                                        . 01234567
0                                                               . 0       
queue count: 1                                                  . queue count: 1
NN ROW COL                                                      . NN ROW COL
 0   1   6                                                      .  0   1   6
LOG: BFS STEP 1                                                 . LOG: BFS STEP 1
LOG: processing neighbors of (1,6)                              . LOG: processing neighbors of (1,6)
LOG: Found tile at (1,5) with len 1 path: W                     . LOG: Found tile at (1,5) with len 1 path: W
LOG: maze state after BFS step                                  . LOG: maze state after BFS step
########:  0                                                    . ########:  0
#    10#:  1                                                    . #    10#:  1
# # ####:  2                                                    . # # ####:  2
# #    #:  3                                                    . # #    #:  3
# ######:  4                                                    . # ######:  4
#      #:  5                                                    . #      #:  5
###### #:  6                                                    . ###### #:  6
# ##   #:  7                                                    . # ##   #:  7
#E#  # #:  8                                                    . #E#  # #:  8
########:  9                                                    . ########:  9
01234567                                                        . 01234567
0                                                               . 0       
queue count: 1                                                  . queue count: 1
NN ROW COL                                                      . NN ROW COL
 0   1   5                                                      .  0   1   5
LOG: BFS STEP 2                                                 . LOG: BFS STEP 2
LOG: processing neighbors of (1,5)                              . LOG: processing neighbors of (1,5)
LOG: Found tile at (1,4) with len 2 path: WW                    . LOG: Found tile at (1,4) with len 2 path: WW
LOG: maze state after BFS step                                  . LOG: maze state after BFS step
########:  0                                                    . ########:  0
#   210#:  1                                                    . #   210#:  1
# # ####:  2                                                    . # # ####:  2
# #    #:  3                                                    . # #    #:  3
# ######:  4                                                    . # ######:  4
#      #:  5                                                    . #      #:  5
###### #:  6                                                    . ###### #:  6
# ##   #:  7                                                    . # ##   #:  7
#E#  # #:  8                                                    . #E#  # #:  8
########:  9                                                    . ########:  9
01234567                                                        . 01234567
0                                                               . 0       
queue count: 1                                                  . queue count: 1
NN ROW COL                                                      . NN ROW COL
 0   1   4                                                      .  0   1   4
LOG: BFS STEP 3                                                 . LOG: BFS STEP 3
LOG: processing neighbors of (1,4)                              . LOG: processing neighbors of (1,4)
LOG: Found tile at (1,3) with len 3 path: WWW                   . LOG: Found tile at (1,3) with len 3 path: WWW
LOG: maze state after BFS step                                  . LOG: maze state after BFS step
########:  0                                                    . ########:  0
#  3210#:  1                                                    . #  3210#:  1
# # ####:  2                                                    . # # ####:  2
# #    #:  3                                                    . # #    #:  3
# ######:  4                                                    . # ######:  4
#      #:  5                                                    . #      #:  5
###### #:  6                                                    . ###### #:  6
# ##   #:  7                                                    . # ##   #:  7
#E#  # #:  8                                                    . #E#  # #:  8
########:  9                                                    . ########:  9
01234567                                                        . 01234567
0                                                               . 0       
queue count: 1                                                  . queue count: 1
NN ROW COL                                                      . NN ROW COL
 0   1   3                                                      .  0   1   3
LOG: BFS STEP 4                                                 . LOG: BFS STEP 4
LOG: processing neighbors of (1,3)                              . LOG: processing neighbors of (1,3)
LOG: Found tile at (2,3) with len 4 path: WWWS                  . LOG: Found tile at (2,3) with len 4 path: WWWS
LOG: Found tile at (1,2) with len 4 path: WWWW                  . LOG: Found tile at (1,2) with len 4 path: WWWW
LOG: maze state after BFS step                                  . LOG: maze state after BFS step
########:  0                                                    . ########:  0
# 43210#:  1                                                    . # 43210#:  1
# #4####:  2                                                    . # #4####:  2
# #    #:  3                                                    . # #    #:  3
# ######:  4                                                    . # ######:  4
#      #:  5                                                    . #      #:  5
###### #:  6                                                    . ###### #:  6
# ##   #:  7                                                    . # ##   #:  7
#E#  # #:  8                                                    . #E#  # #:  8
########:  9                                                    . ########:  9
01234567                                                        . 01234567
0                                                               . 0       
queue count: 2                                                  . queue count: 2
NN ROW COL                                                      . NN ROW COL
 0   2   3                                                      .  0   2   3
 1   1   2                                                      .  1   1   2
LOG: BFS STEP 5                                                 . LOG: BFS STEP 5
LOG: processing neighbors of (2,3)                              . LOG: processing neighbors of (2,3)
LOG: Found tile at (3,3) with len 5 path: WWWSS                 . LOG: Found tile at (3,3) with len 5 path: WWWSS
LOG: maze state after BFS step                                  . LOG: maze state after BFS step
########:  0                                                    . ########:  0
# 43210#:  1                                                    . # 43210#:  1
# #4####:  2                                                    . # #4####:  2
# #5   #:  3                                                    . # #5   #:  3
# ######:  4                                                    . # ######:  4
#      #:  5                                                    . #      #:  5
###### #:  6                                                    . ###### #:  6
# ##   #:  7                                                    . # ##   #:  7
#E#  # #:  8                                                    . #E#  # #:  8
########:  9                                                    . ########:  9
01234567                                                        . 01234567
0                                                               . 0       
queue count: 2                                                  . queue count: 2
NN ROW COL                                                      . NN ROW COL
 0   1   2                                                      .  0   1   2
 1   3   3                                                      .  1   3   3
LOG: BFS STEP 6                                                 . LOG: BFS STEP 6
LOG: processing neighbors of (1,2)                              . LOG: processing neighbors of (1,2)
LOG: Found tile at (1,1) with len 5 path: WWWWW                 . LOG: Found tile at (1,1) with len 5 path: WWWWW
LOG: maze state after BFS step                                  . LOG: maze state after BFS step
########:  0                                                    . ########:  0
#543210#:  1                                                    . #543210#:  1
# #4####:  2                                                    . # #4####:  2
# #5   #:  3                                                    . # #5   #:  3
# ######:  4                                                    . # ######:  4
#      #:  5                                                    . #      #:  5
###### #:  6                                                    . ###### #:  6
# ##   #:  7                                                    . # ##   #:  7
#E#  # #:  8                                                    . #E#  # #:  8
########:  9                                                    . ########:  9
01234567                                                        . 01234567
0                                                               . 0       
queue count: 2                                                  . queue count: 2
NN ROW COL                                                      . NN ROW COL
 0   3   3                                                      .  0   3   3
 1   1   1                                                      .  1   1   1
LOG: BFS STEP 7                                                 . LOG: BFS STEP 7
LOG: processing neighbors of (3,3)                              . LOG: processing neighbors of (3,3)
LOG: Found tile at (3,4) with len 6 path: WWWSSE                . LOG: Found tile at (3,4) with len 6 path: WWWSSE
LOG: maze state after BFS step                                  . LOG: maze state after BFS step
########:  0                                                    . ########:  0
#543210#:  1                                                    . #543210#:  1
# #4####:  2                                                    . # #4####:  2
# #56  #:  3                                                    . # #56  #:  3
# ######:  4                                                    . # ######:  4
#      #:  5                                                    . #      #:  5
###### #:  6                                                    . ###### #:  6
# ##   #:  7                                                    . # ##   #:  7
#E#  # #:  8                                                    . #E#  # #:  8
########:  9                                                    . ########:  9
01234567                                                        . 01234567
0                                                               . 0       
queue count: 2                                                  . queue count: 2
NN ROW COL                                                      . NN ROW COL
 0   1   1                                                      .  0   1   1
 1   3   4                                                      .  1   3   4
LOG: BFS STEP 8                                                 . LOG: BFS STEP 8
LOG: processing neighbors of (1,1)                              . LOG: processing neighbors of (1,1)
LOG: Found tile at (2,1) with len 6 path: WWWWWS                . LOG: Found tile at (2,1) with len 6 path: WWWWWS
LOG: maze state after BFS step                                  . LOG: maze state after BFS step
########:  0                                                    . ########:  0
#543210#:  1                                                    . #543210#:  1
#6#4####:  2                                                    . #6#4####:  2
# #56  #:  3                                                    . # #56  #:  3
# ######:  4                                                    . # ######:  4
#      #:  5                                                    . #      #:  5
###### #:  6                                                    . ###### #:  6
# ##   #:  7                                                    . # ##   #:  7
#E#  # #:  8                                                    . #E#  # #:  8
########:  9                                                    . ########:  9
01234567                                                        . 01234567
0                                                               . 0       
queue count: 2                                                  . queue count: 2
NN ROW COL                                                      . NN ROW COL
 0   3   4                                                      .  0   3   4
 1   2   1                                                      .  1   2   1
LOG: BFS STEP 9                                                 . LOG: BFS STEP 9
LOG: processing neighbors of (3,4)                              . LOG: processing neighbors of (3,4)
LOG: Found tile at (3,5) with len 7 path: WWWSSEE               . LOG: Found tile at (3,5) with len 7 path: WWWSSEE
LOG: maze state after BFS step                                  . LOG: maze state after BFS step
########:  0                                                    . ########:  0
#543210#:  1                                                    . #543210#:  1
#6#4####:  2                                                    . #6#4####:  2
# #567 #:  3                                                    . # #567 #:  3
# ######:  4                                                    . # ######:  4
#      #:  5                                                    . #      #:  5
###### #:  6                                                    . ###### #:  6
# ##   #:  7                                                    . # ##   #:  7
#E#  # #:  8                                                    . #E#  # #:  8
########:  9                                                    . ########:  9
01234567                                                        . 01234567
0                                                               . 0       
queue count: 2                                                  . queue count: 2
NN ROW COL                                                      . NN ROW COL
 0   2   1                                                      .  0   2   1
 1   3   5                                                      .  1   3   5
LOG: BFS STEP 10                                                . LOG: BFS STEP 10
LOG: processing neighbors of (2,1)                              . LOG: processing neighbors of (2,1)
LOG: Found tile at (3,1) with len 7 path: WWWWWSS               . LOG: Found tile at (3,1) with len 7 path: WWWWWSS
LOG: maze state after BFS step                                  . LOG: maze state after BFS step
########:  0                                                    . ########:  0
#543210#:  1                                                    . #543210#:  1
#6#4####:  2                                                    . #6#4####:  2
#7#567 #:  3                                                    . #7#567 #:  3
# ######:  4                                                    . # ######:  4
#      #:  5                                                    . #      #:  5
###### #:  6                                                    . ###### #:  6
# ##   #:  7                                                    . # ##   #:  7
#E#  # #:  8                                                    . #E#  # #:  8
########:  9                                                    . ########:  9
01234567                                                        . 01234567
0                                                               . 0       
queue count: 2                                                  . queue count: 2
NN ROW COL                                                      . NN ROW COL
 0   3   5                                                      .  0   3   5
 1   3   1                                                      .  1   3   1
LOG: BFS STEP 11                                                . LOG: BFS STEP 11
LOG: processing neighbors of (3,5)                              . LOG: processing neighbors of (3,5)
LOG: Found tile at (3,6) with len 8 path: WWWSSEEE              . LOG: Found tile at (3,6) with len 8 path: WWWSSEEE
LOG: maze state after BFS step                                  . LOG: maze state after BFS step
########:  0                                                    . ########:  0
#543210#:  1                                                    . #543210#:  1
#6#4####:  2                                                    . #6#4####:  2
#7#5678#:  3                                                    . #7#5678#:  3
# ######:  4                                                    . # ######:  4
#      #:  5                                                    . #      #:  5
###### #:  6                                                    . ###### #:  6
# ##   #:  7                                                    . # ##   #:  7
#E#  # #:  8                                                    . #E#  # #:  8
########:  9                                                    . ########:  9
01234567                                                        . 01234567
0                                                               . 0       
queue count: 2                                                  . queue count: 2
NN ROW COL                                                      . NN ROW COL
 0   3   1                                                      .  0   3   1
 1   3   6                                                      .  1   3   6
LOG: BFS STEP 12                                                . LOG: BFS STEP 12
LOG: processing neighbors of (3,1)                              . LOG: processing neighbors of (3,1)
LOG: Found tile at (4,1) with len 8 path: WWWWWSSS              . LOG: Found tile at (4,1) with len 8 path: WWWWWSSS
LOG: maze state after BFS step                                  . LOG: maze state after BFS step
########:  0                                                    . ########:  0
#543210#:  1                                                    . #543210#:  1
#6#4####:  2                                                    . #6#4####:  2
#7#5678#:  3                                                    . #7#5678#:  3
#8######:  4                                                    . #8######:  4
#      #:  5                                                    . #      #:  5
###### #:  6                                                    . ###### #:  6
# ##   #:  7                                                    . # ##   #:  7
#E#  # #:  8                                                    . #E#  # #:  8
########:  9                                                    . ########:  9
01234567                                                        . 01234567
0                                                               . 0       
queue count: 2                                                  . queue count: 2
NN ROW COL                                                      . NN ROW COL
 0   3   6                                                      .  0   3   6
 1   4   1                                                      .  1   4   1
LOG: BFS STEP 13                                                . LOG: BFS STEP 13
LOG: processing neighbors of (3,6)                              . LOG: processing neighbors of (3,6)
LOG: maze state after BFS step                                  . LOG: maze state after BFS step
########:  0                                                    . ########:  0
#543210#:  1                                                    . #543210#:  1
#6#4####:  2                                                    . #6#4####:  2
#7#5678#:  3                                                    . #7#5678#:  3
#8######:  4                                                    . #8######:  4
#      #:  5                                                    . #      #:  5
###### #:  6                                                    . ###### #:  6
# ##   #:  7                                                    . # ##   #:  7
#E#  # #:  8                                                    . #E#  # #:  8
########:  9                                                    . ########:  9
01234567                                                        . 01234567
0                                                               . 0       
queue count: 1                                                  . queue count: 1
NN ROW COL                                                      . NN ROW COL
 0   4   1                                                      .  0   4   1
LOG: BFS STEP 14                                                . LOG: BFS STEP 14
LOG: processing neighbors of (4,1)                              . LOG: processing neighbors of (4,1)
LOG: Found tile at (5,1) with len 9 path: WWWWWSSSS             . LOG: Found tile at (5,1) with len 9 path: WWWWWSSSS
LOG: maze state after BFS step                                  . LOG: maze state after BFS step
########:  0                                                    . ########:  0
#543210#:  1                                                    . #543210#:  1
#6#4####:  2                                                    . #6#4####:  2
#7#5678#:  3                                                    . #7#5678#:  3
#8######:  4                                                    . #8######:  4
#9     #:  5                                                    . #9     #:  5
###### #:  6                                                    . ###### #:  6
# ##   #:  7                                                    . # ##   #:  7
#E#  # #:  8                                                    . #E#  # #:  8
########:  9                                                    . ########:  9
01234567                                                        . 01234567
0                                                               . 0       
queue count: 1                                                  . queue count: 1
NN ROW COL                                                      . NN ROW COL
 0   5   1                                                      .  0   5   1
LOG: BFS STEP 15                                                . LOG: BFS STEP 15
LOG: processing neighbors of (5,1)                              . LOG: processing neighbors of (5,1)
LOG: Found tile at (5,2) with len 10 path: WWWWWSSSSE           . LOG: Found tile at (5,2) with len 10 path: WWWWWSSSSE
LOG: maze state after BFS step                                  . LOG: maze state after BFS step
########:  0                                                    . ########:  0
#543210#:  1                                                    . #543210#:  1
#6#4####:  2                                                    . #6#4####:  2
#7#5678#:  3                                                    . #7#5678#:  3
#8######:  4                                                    . #8######:  4
#9a    #:  5                                                    . #9a    #:  5
###### #:  6                                                    . ###### #:  6
# ##   #:  7                                                    . # ##   #:  7
#E#  # #:  8                                                    . #E#  # #:  8
########:  9                                                    . ########:  9
01234567                                                        . 01234567
0                                                               . 0       
queue count: 1                                                  . queue count: 1
NN ROW COL                                                      . NN ROW COL
 0   5   2                                                      .  0   5   2
LOG: BFS STEP 16                                                . LOG: BFS STEP 16
LOG: processing neighbors of (5,2)                              . LOG: processing neighbors of (5,2)
LOG: Found tile at (5,3) with len 11 path: WWWWWSSSSEE          . LOG: Found tile at (5,3) with len 11 path: WWWWWSSSSEE
LOG: maze state after BFS step                                  . LOG: maze state after BFS step
########:  0                                                    . ########:  0
#543210#:  1                                                    . #543210#:  1
#6#4####:  2                                                    . #6#4####:  2
#7#5678#:  3                                                    . #7#5678#:  3
#8######:  4                                                    . #8######:  4
#9a1   #:  5                                                    . #9a1   #:  5
###### #:  6                                                    . ###### #:  6
# ##   #:  7                                                    . # ##   #:  7
#E#  # #:  8                                                    . #E#  # #:  8
########:  9                                                    . ########:  9
01234567                                                        . 01234567
0                                                               . 0       
queue count: 1                                                  . queue count: 1
NN ROW COL                                                      . NN ROW COL
 0   5   3                                                      .  0   5   3
LOG: BFS STEP 17                                                . LOG: BFS STEP 17
LOG: processing neighbors of (5,3)                              . LOG: processing neighbors of (5,3)
LOG: Found tile at (5,4) with len 12 path: WWWWWSSSSEEE         . LOG: Found tile at (5,4) with len 12 path: WWWWWSSSSEEE
LOG: maze state after BFS step                                  . LOG: maze state after BFS step
########:  0                                                    . ########:  0
#543210#:  1                                                    . #543210#:  1
#6#4####:  2                                                    . #6#4####:  2
#7#5678#:  3                                                    . #7#5678#:  3
#8######:  4                                                    . #8######:  4
#9a12  #:  5                                                    . #9a12  #:  5
###### #:  6                                                    . ###### #:  6
# ##   #:  7                                                    . # ##   #:  7
#E#  # #:  8                                                    . #E#  # #:  8
########:  9                                                    . ########:  9
01234567                                                        . 01234567
0                                                               . 0       
queue count: 1                                                  . queue count: 1
NN ROW COL                                                      . NN ROW COL
 0   5   4                                                      .  0   5   4
LOG: BFS STEP 18                                                . LOG: BFS STEP 18
LOG: processing neighbors of (5,4)                              . LOG: processing neighbors of (5,4)
LOG: Found tile at (5,5) with len 13 path: WWWWWSSSSEEEE        . LOG: Found tile at (5,5) with len 13 path: WWWWWSSSSEEEE
LOG: maze state after BFS step                                  . LOG: maze state after BFS step
########:  0                                                    . ########:  0
#543210#:  1                                                    . #543210#:  1
#6#4####:  2                                                    . #6#4####:  2
#7#5678#:  3                                                    . #7#5678#:  3
#8######:  4                                                    . #8######:  4
#9a123 #:  5                                                    . #9a123 #:  5
###### #:  6                                                    . ###### #:  6
# ##   #:  7                                                    . # ##   #:  7
#E#  # #:  8                                                    . #E#  # #:  8
########:  9                                                    . ########:  9
01234567                                                        . 01234567
0                                                               . 0       
queue count: 1                                                  . queue count: 1
NN ROW COL                                                      . NN ROW COL
 0   5   5                                                      .  0   5   5
LOG: BFS STEP 19                                                . LOG: BFS STEP 19
LOG: processing neighbors of (5,5)                              . LOG: processing neighbors of (5,5)
LOG: Found tile at (5,6) with len 14 path: WWWWWSSSSEEEEE       . LOG: Found tile at (5,6) with len 14 path: WWWWWSSSSEEEEE
LOG: maze state after BFS step                                  . LOG: maze state after BFS step
########:  0                                                    . ########:  0
#543210#:  1                                                    . #543210#:  1
#6#4####:  2                                                    . #6#4####:  2
#7#5678#:  3                                                    . #7#5678#:  3
#8######:  4                                                    . #8######:  4
#9a1234#:  5                                                    . #9a1234#:  5
###### #:  6                                                    . ###### #:  6
# ##   #:  7                                                    . # ##   #:  7
#E#  # #:  8                                                    . #E#  # #:  8
########:  9                                                    . ########:  9
01234567                                                        . 01234567
0                                                               . 0       
queue count: 1                                                  . queue count: 1
NN ROW COL                                                      . NN ROW COL
 0   5   6                                                      .  0   5   6
LOG: BFS STEP 20                                                . LOG: BFS STEP 20
LOG: processing neighbors of (5,6)                              . LOG: processing neighbors of (5,6)
LOG: Found tile at (6,6) with len 15 path: WWWWWSSSSEEEEES      . LOG: Found tile at (6,6) with len 15 path: WWWWWSSSSEEEEES
LOG: maze state after BFS step                                  . LOG: maze state after BFS step
########:  0                                                    . ########:  0
#543210#:  1                                                    . #543210#:  1
#6#4####:  2                                                    . #6#4####:  2
#7#5678#:  3                                                    . #7#5678#:  3
#8######:  4                                                    . #8######:  4
#9a1234#:  5                                                    . #9a1234#:  5
######5#:  6                                                    . ######5#:  6
# ##   #:  7                                                    . # ##   #:  7
#E#  # #:  8                                                    . #E#  # #:  8
########:  9                                                    . ########:  9
01234567                                                        . 01234567
0                                                               . 0       
queue count: 1                                                  . queue count: 1
NN ROW COL                                                      . NN ROW COL
 0   6   6                                                      .  0   6   6
LOG: BFS STEP 21                                                . LOG: BFS STEP 21
LOG: processing neighbors of (6,6)                              . LOG: processing neighbors of (6,6)
LOG: Found tile at (7,6) with len 16 path: WWWWWSSSSEEEEESS     . LOG: Found tile at (7,6) with len 16 path: WWWWWSSSSEEEEESS
LOG: maze state after BFS step                                  . LOG: maze state after BFS step
########:  0                                                    . ########:  0
#543210#:  1                                                    . #543210#:  1
#6#4####:  2                                                    . #6#4####:  2
#7#5678#:  3                                                    . #7#5678#:  3
#8######:  4                                                    . #8######:  4
#9a1234#:  5                                                    . #9a1234#:  5
######5#:  6                                                    . ######5#:  6
# ##  6#:  7                                                    . # ##  6#:  7
#E#  # #:  8                                                    . #E#  # #:  8
########:  9                                                    . ########:  9
01234567                                                        . 01234567
0                                                               . 0       
queue count: 1                                                  . queue count: 1
NN ROW COL                                                      . NN ROW COL
 0   7   6                                                      .  0   7   6
LOG: BFS STEP 22                                                . LOG: BFS STEP 22
LOG: processing neighbors of (7,6)                              . LOG: processing neighbors of (7,6)
LOG: Found tile at (8,6) with len 17 path: WWWWWSSSSEEEEESSS    . LOG: Found tile at (8,6) with len 17 path: WWWWWSSSSEEEEESSS
LOG: Found tile at (7,5) with len 17 path: WWWWWSSSSEEEEESSW    . LOG: Found tile at (7,5) with len 17 path: WWWWWSSSSEEEEESSW
LOG: maze state after BFS step                                  . LOG: maze state after BFS step
########:  0                                                    . ########:  0
#543210#:  1                                                    . #543210#:  1
#6#4####:  2                                                    . #6#4####:  2
#7#5678#:  3                                                    . #7#5678#:  3
#8######:  4                                                    . #8######:  4
#9a1234#:  5                                                    . #9a1234#:  5
######5#:  6                                                    . ######5#:  6
# ## 76#:  7                                                    . # ## 76#:  7
#E#  #7#:  8                                                    . #E#  #7#:  8
########:  9                                                    . ########:  9
01234567                                                        . 01234567
0                                                               . 0       
queue count: 2                                                  . queue count: 2
NN ROW COL                                                      . NN ROW COL
 0   8   6                                                      .  0   8   6
 1   7   5                                                      .  1   7   5
LOG: BFS STEP 23                                                . LOG: BFS STEP 23
LOG: processing neighbors of (8,6)                              . LOG: processing neighbors of (8,6)
LOG: maze state after BFS step                                  . LOG: maze state after BFS step
########:  0                                                    . ########:  0
#543210#:  1                                                    . #543210#:  1
#6#4####:  2                                                    . #6#4####:  2
#7#5678#:  3                                                    . #7#5678#:  3
#8######:  4                                                    . #8######:  4
#9a1234#:  5                                                    . #9a1234#:  5
######5#:  6                                                    . ######5#:  6
# ## 76#:  7                                                    . # ## 76#:  7
#E#  #7#:  8                                                    . #E#  #7#:  8
########:  9                                                    . ########:  9
01234567                                                        . 01234567
0                                                               . 0       
queue count: 1                                                  . queue count: 1
NN ROW COL                                                      . NN ROW COL
 0   7   5                                                      .  0   7   5
LOG: BFS STEP 24                                                . LOG: BFS STEP 24
LOG: processing neighbors of (7,5)                              . LOG: processing neighbors of (7,5)
LOG: Found tile at (7,4) with len 18 path: WWWWWSSSSEEEEESSWW   . LOG: Found tile at (7,4) with len 18 path: WWWWWSSSSEEEEESSWW
LOG: maze state after BFS step                                  . LOG: maze state after BFS step
########:  0                                                    . ########:  0
#543210#:  1                                                    . #543210#:  1
#6#4####:  2                                                    . #6#4####:  2
#7#5678#:  3                                                    . #7#5678#:  3
#8######:  4                                                    . #8######:  4
#9a1234#:  5                                                    . #9a1234#:  5
######5#:  6                                                    . ######5#:  6
# ##876#:  7                                                    . # ##876#:  7
#E#  #7#:  8                                                    . #E#  #7#:  8
########:  9                                                    . ########:  9
01234567                                                        . 01234567
0                                                               . 0       
queue count: 1                                                  . queue count: 1
NN ROW COL                                                      . NN ROW COL
 0   7   4                                                      .  0   7   4
LOG: BFS STEP 25                                                . LOG: BFS STEP 25
LOG: processing neighbors of (7,4)                              . LOG: processing neighbors of (7,4)
LOG: Found tile at (8,4) with len 19 path: WWWWWSSSSEEEEESSWWS  . LOG: Found tile at (8,4) with len 19 path: WWWWWSSSSEEEEESSWWS
LOG: maze state after BFS step                                  . LOG: maze state after BFS step
########:  0                                                    . ########:  0
#543210#:  1                                                    . #543210#:  1
#6#4####:  2                                                    . #6#4####:  2
#7#5678#:  3                                                    . #7#5678#:  3
#8######:  4                                                    . #8######:  4
#9a1234#:  5                                                    . #9a1234#:  5
######5#:  6                                                    . ######5#:  6
# ##876#:  7                                                    . # ##876#:  7
#E# 9#7#:  8                                                    . #E# 9#7#:  8
########:  9                                                    . ########:  9
01234567                                                        . 01234567
0                                                               . 0       
queue count: 1                                                  . queue count: 1
NN ROW COL                                                      . NN ROW COL
 0   8   4                                                      .  0   8   4
LOG: BFS STEP 26                                                . LOG: BFS STEP 26
LOG: processing neighbors of (8,4)                              . LOG: processing neighbors of (8,4)
LOG: Found tile at (8,3) with len 20 path: WWWWWSSSSEEEEESSWWSW . LOG: Found tile at (8,3) with len 20 path: WWWWWSSSSEEEEESSWWSW
LOG: maze state after BFS step                                  . LOG: maze state after BFS step
########:  0                                                    . ########:  0
#543210#:  1                                                    . #543210#:  1
#6#4####:  2                                                    . #6#4####:  2
#7#5678#:  3                                                    . #7#5678#:  3
#8######:  4                                                    . #8######:  4
#9a1234#:  5                                                    . #9a1234#:  5
######5#:  6                                                    . ######5#:  6
# ##876#:  7                                                    . # ##876#:  7
#E#b9#7#:  8                                                    . #E#b9#7#:  8
########:  9                                                    . ########:  9
01234567                                                        . 01234567
0                                                               . 0       
queue count: 1                                                  . queue count: 1
NN ROW COL                                                      . NN ROW COL
 0   8   3                                                      .  0   8   3
LOG: BFS STEP 27                                                . LOG: BFS STEP 27
LOG: processing neighbors of (8,3)                              . LOG: processing neighbors of (8,3)
LOG: maze state after BFS step                                  . LOG: maze state after BFS step
########:  0                                                    . ########:  0
#543210#:  1                                                    . #543210#:  1
#6#4####:  2                                                    . #6#4####:  2
#7#5678#:  3                                                    . #7#5678#:  3
#8######:  4                                                    . #8######:  4
#9a1234#:  5                                                    . #9a1234#:  5
######5#:  6                                                    . ######5#:  6
# ##876#:  7                                                    . # ##876#:  7
#E#b9#7#:  8                                                    . #E#b9#7#:  8
########:  9                                                    . ########:  9
01234567                                                        . 01234567
0                                                               . 0       
queue count: 0                                                  . queue count: 0
NN ROW COL                                                      . NN ROW COL
                                                                ) 
NO SOLUTION FOUND                                               . NO SOLUTION FOUND

```

### LINE-BY-LINE DIFF of Expected vs Actual
No differences found

### VALGRIND REPORT
The program is run on under valgrind as
stdbuf -i 0 -o 0 -e 0 valgrind --error-exitcode=13 --leak-check=full --show-leak-kinds=all --track-origins=yes ./mazesolve_main -log 4 data/maze-unreachable1.txt
which may be pasted onto a command line to run it.

```
==15632== Memcheck, a memory error detector
==15632== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==15632== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==15632== Command: ./mazesolve_main -log 4 data/maze-unreachable1.txt
==15632== 
==15632== 
==15632== HEAP SUMMARY:
==15632==     in use at exit: 0 bytes in 0 blocks
==15632==   total heap usage: 69 allocs, 69 frees, 8,096 bytes allocated
==15632== 
==15632== All heap blocks were freed -- no leaks are possible
==15632== 
==15632== For lists of detected and suppressed errors, rerun with: -s
==15632== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

### SUMMARY
Test Passed
