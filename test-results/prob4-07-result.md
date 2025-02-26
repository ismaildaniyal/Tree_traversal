(TEST 7) mazesolve_main2_logging MULTIPART : ok
===============================================

COMMENTS
--------
This is a multi-part test that runs the main function with various log
levels to ensure printing log messages respects the different levels.

Test Segment 1 : ok
-------------------
** No logging
Run on maze-small-twopath1.txt with no logging

### PROGRAM: ./mazesolve_main data/maze-small-twopath1.txt
To run this individual test in GDB use the command:
gdb --args ./mazesolve_main data/maze-small-twopath1.txt
but any input to the program must be typed within the debugger

### FAILURE MESSAGES
None

### SIDE-BY-SIDE DIFF of Expected vs Actual
. lines match; | lines differ; < expected line missing; > extra line in actual

```sdiff
===EXPECT===          ===ACTUAL===
maze: 5 rows 5 cols . maze: 5 rows 5 cols
      (1,2) start   .       (1,2) start
      (3,2) end     .       (3,2) end
maze tiles:         . maze tiles:
#####               . #####
# S #               . # S #
# # #               . # # #
# E #               . # E #
#####               . #####
                    ) 
                    ) 
SOLUTION:           . SOLUTION:
maze: 5 rows 5 cols . maze: 5 rows 5 cols
      (1,2) start   .       (1,2) start
      (3,2) end     .       (3,2) end
maze tiles:         . maze tiles:
#####               . #####
#.S #               . #.S #
#.# #               . #.# #
#.E #               . #.E #
#####               . #####
                    ) 
path length: 4      . path length: 4
 0: WEST            .  0: WEST
 1: SOUTH           .  1: SOUTH
 2: SOUTH           .  2: SOUTH
 3: EAST            .  3: EAST

```

### LINE-BY-LINE DIFF of Expected vs Actual
No differences found

### VALGRIND REPORT
The program is run on under valgrind as
stdbuf -i 0 -o 0 -e 0 valgrind --error-exitcode=13 --leak-check=full --show-leak-kinds=all --track-origins=yes ./mazesolve_main data/maze-small-twopath1.txt
which may be pasted onto a command line to run it.

```
==15605== Memcheck, a memory error detector
==15605== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==15605== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==15605== Command: ./mazesolve_main data/maze-small-twopath1.txt
==15605== 
==15605== 
==15605== HEAP SUMMARY:
==15605==     in use at exit: 0 bytes in 0 blocks
==15605==   total heap usage: 26 allocs, 26 frees, 5,468 bytes allocated
==15605== 
==15605== All heap blocks were freed -- no leaks are possible
==15605== 
==15605== For lists of detected and suppressed errors, rerun with: -s
==15605== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

Test Segment 2 : ok
-------------------
** Log 1
Run on maze-small-twopath1.txt with level 1 logging.

### PROGRAM: ./mazesolve_main -log 1 data/maze-small-twopath1.txt
To run this individual test in GDB use the command:
gdb --args ./mazesolve_main -log 1 data/maze-small-twopath1.txt
but any input to the program must be typed within the debugger

### FAILURE MESSAGES
None

### SIDE-BY-SIDE DIFF of Expected vs Actual
. lines match; | lines differ; < expected line missing; > extra line in actual

```sdiff
===EXPECT===                         ===ACTUAL===
maze: 5 rows 5 cols                . maze: 5 rows 5 cols
      (1,2) start                  .       (1,2) start
      (3,2) end                    .       (3,2) end
maze tiles:                        . maze tiles:
#####                              . #####
# S #                              . # S #
# # #                              . # # #
# E #                              . # E #
#####                              . #####
                                   ) 
LOG: BFS STEP 1                    . LOG: BFS STEP 1
LOG: processing neighbors of (1,2) . LOG: processing neighbors of (1,2)
LOG: BFS STEP 2                    . LOG: BFS STEP 2
LOG: processing neighbors of (1,1) . LOG: processing neighbors of (1,1)
LOG: BFS STEP 3                    . LOG: BFS STEP 3
LOG: processing neighbors of (1,3) . LOG: processing neighbors of (1,3)
LOG: BFS STEP 4                    . LOG: BFS STEP 4
LOG: processing neighbors of (2,1) . LOG: processing neighbors of (2,1)
LOG: BFS STEP 5                    . LOG: BFS STEP 5
LOG: processing neighbors of (2,3) . LOG: processing neighbors of (2,3)
LOG: BFS STEP 6                    . LOG: BFS STEP 6
LOG: processing neighbors of (3,1) . LOG: processing neighbors of (3,1)
LOG: BFS STEP 7                    . LOG: BFS STEP 7
LOG: processing neighbors of (3,3) . LOG: processing neighbors of (3,3)
LOG: BFS STEP 8                    . LOG: BFS STEP 8
LOG: processing neighbors of (3,2) . LOG: processing neighbors of (3,2)
                                   ) 
SOLUTION:                          . SOLUTION:
maze: 5 rows 5 cols                . maze: 5 rows 5 cols
      (1,2) start                  .       (1,2) start
      (3,2) end                    .       (3,2) end
maze tiles:                        . maze tiles:
#####                              . #####
#.S #                              . #.S #
#.# #                              . #.# #
#.E #                              . #.E #
#####                              . #####
                                   ) 
path length: 4                     . path length: 4
 0: WEST                           .  0: WEST
 1: SOUTH                          .  1: SOUTH
 2: SOUTH                          .  2: SOUTH
 3: EAST                           .  3: EAST

```

### LINE-BY-LINE DIFF of Expected vs Actual
No differences found

### VALGRIND REPORT
The program is run on under valgrind as
stdbuf -i 0 -o 0 -e 0 valgrind --error-exitcode=13 --leak-check=full --show-leak-kinds=all --track-origins=yes ./mazesolve_main -log 1 data/maze-small-twopath1.txt
which may be pasted onto a command line to run it.

```
==15623== Memcheck, a memory error detector
==15623== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==15623== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==15623== Command: ./mazesolve_main -log 1 data/maze-small-twopath1.txt
==15623== 
==15623== 
==15623== HEAP SUMMARY:
==15623==     in use at exit: 0 bytes in 0 blocks
==15623==   total heap usage: 26 allocs, 26 frees, 5,468 bytes allocated
==15623== 
==15623== All heap blocks were freed -- no leaks are possible
==15623== 
==15623== For lists of detected and suppressed errors, rerun with: -s
==15623== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

Test Segment 3 : ok
-------------------
** Log 2
Run on maze-small-twopath1.txt with level 2 logging.

### PROGRAM: ./mazesolve_main -log 2 data/maze-small-twopath1.txt
To run this individual test in GDB use the command:
gdb --args ./mazesolve_main -log 2 data/maze-small-twopath1.txt
but any input to the program must be typed within the debugger

### FAILURE MESSAGES
None

### SIDE-BY-SIDE DIFF of Expected vs Actual
. lines match; | lines differ; < expected line missing; > extra line in actual

```sdiff
===EXPECT===                         ===ACTUAL===
maze: 5 rows 5 cols                . maze: 5 rows 5 cols
      (1,2) start                  .       (1,2) start
      (3,2) end                    .       (3,2) end
maze tiles:                        . maze tiles:
#####                              . #####
# S #                              . # S #
# # #                              . # # #
# E #                              . # E #
#####                              . #####
                                   ) 
LOG: BFS initialization complete   . LOG: BFS initialization complete
#####:  0                          . #####:  0
# 0 #:  1                          . # 0 #:  1
# # #:  2                          . # # #:  2
# E #:  3                          . # E #:  3
#####:  4                          . #####:  4
01234                              . 01234
0                                  . 0    
queue count: 1                     . queue count: 1
NN ROW COL                         . NN ROW COL
 0   1   2                         .  0   1   2
LOG: BFS STEP 1                    . LOG: BFS STEP 1
LOG: processing neighbors of (1,2) . LOG: processing neighbors of (1,2)
LOG: maze state after BFS step     . LOG: maze state after BFS step
#####:  0                          . #####:  0
#101#:  1                          . #101#:  1
# # #:  2                          . # # #:  2
# E #:  3                          . # E #:  3
#####:  4                          . #####:  4
01234                              . 01234
0                                  . 0    
queue count: 2                     . queue count: 2
NN ROW COL                         . NN ROW COL
 0   1   1                         .  0   1   1
 1   1   3                         .  1   1   3
LOG: BFS STEP 2                    . LOG: BFS STEP 2
LOG: processing neighbors of (1,1) . LOG: processing neighbors of (1,1)
LOG: maze state after BFS step     . LOG: maze state after BFS step
#####:  0                          . #####:  0
#101#:  1                          . #101#:  1
#2# #:  2                          . #2# #:  2
# E #:  3                          . # E #:  3
#####:  4                          . #####:  4
01234                              . 01234
0                                  . 0    
queue count: 2                     . queue count: 2
NN ROW COL                         . NN ROW COL
 0   1   3                         .  0   1   3
 1   2   1                         .  1   2   1
LOG: BFS STEP 3                    . LOG: BFS STEP 3
LOG: processing neighbors of (1,3) . LOG: processing neighbors of (1,3)
LOG: maze state after BFS step     . LOG: maze state after BFS step
#####:  0                          . #####:  0
#101#:  1                          . #101#:  1
#2#2#:  2                          . #2#2#:  2
# E #:  3                          . # E #:  3
#####:  4                          . #####:  4
01234                              . 01234
0                                  . 0    
queue count: 2                     . queue count: 2
NN ROW COL                         . NN ROW COL
 0   2   1                         .  0   2   1
 1   2   3                         .  1   2   3
LOG: BFS STEP 4                    . LOG: BFS STEP 4
LOG: processing neighbors of (2,1) . LOG: processing neighbors of (2,1)
LOG: maze state after BFS step     . LOG: maze state after BFS step
#####:  0                          . #####:  0
#101#:  1                          . #101#:  1
#2#2#:  2                          . #2#2#:  2
#3E #:  3                          . #3E #:  3
#####:  4                          . #####:  4
01234                              . 01234
0                                  . 0    
queue count: 2                     . queue count: 2
NN ROW COL                         . NN ROW COL
 0   2   3                         .  0   2   3
 1   3   1                         .  1   3   1
LOG: BFS STEP 5                    . LOG: BFS STEP 5
LOG: processing neighbors of (2,3) . LOG: processing neighbors of (2,3)
LOG: maze state after BFS step     . LOG: maze state after BFS step
#####:  0                          . #####:  0
#101#:  1                          . #101#:  1
#2#2#:  2                          . #2#2#:  2
#3E3#:  3                          . #3E3#:  3
#####:  4                          . #####:  4
01234                              . 01234
0                                  . 0    
queue count: 2                     . queue count: 2
NN ROW COL                         . NN ROW COL
 0   3   1                         .  0   3   1
 1   3   3                         .  1   3   3
LOG: BFS STEP 6                    . LOG: BFS STEP 6
LOG: processing neighbors of (3,1) . LOG: processing neighbors of (3,1)
LOG: maze state after BFS step     . LOG: maze state after BFS step
#####:  0                          . #####:  0
#101#:  1                          . #101#:  1
#2#2#:  2                          . #2#2#:  2
#343#:  3                          . #343#:  3
#####:  4                          . #####:  4
01234                              . 01234
0                                  . 0    
queue count: 2                     . queue count: 2
NN ROW COL                         . NN ROW COL
 0   3   3                         .  0   3   3
 1   3   2                         .  1   3   2
LOG: BFS STEP 7                    . LOG: BFS STEP 7
LOG: processing neighbors of (3,3) . LOG: processing neighbors of (3,3)
LOG: maze state after BFS step     . LOG: maze state after BFS step
#####:  0                          . #####:  0
#101#:  1                          . #101#:  1
#2#2#:  2                          . #2#2#:  2
#343#:  3                          . #343#:  3
#####:  4                          . #####:  4
01234                              . 01234
0                                  . 0    
queue count: 1                     . queue count: 1
NN ROW COL                         . NN ROW COL
 0   3   2                         .  0   3   2
LOG: BFS STEP 8                    . LOG: BFS STEP 8
LOG: processing neighbors of (3,2) . LOG: processing neighbors of (3,2)
LOG: maze state after BFS step     . LOG: maze state after BFS step
#####:  0                          . #####:  0
#101#:  1                          . #101#:  1
#2#2#:  2                          . #2#2#:  2
#343#:  3                          . #343#:  3
#####:  4                          . #####:  4
01234                              . 01234
0                                  . 0    
queue count: 0                     . queue count: 0
NN ROW COL                         . NN ROW COL
                                   ) 
SOLUTION:                          . SOLUTION:
maze: 5 rows 5 cols                . maze: 5 rows 5 cols
      (1,2) start                  .       (1,2) start
      (3,2) end                    .       (3,2) end
maze tiles:                        . maze tiles:
#####                              . #####
#.S #                              . #.S #
#.# #                              . #.# #
#.E #                              . #.E #
#####                              . #####
                                   ) 
path length: 4                     . path length: 4
 0: WEST                           .  0: WEST
 1: SOUTH                          .  1: SOUTH
 2: SOUTH                          .  2: SOUTH
 3: EAST                           .  3: EAST

```

### LINE-BY-LINE DIFF of Expected vs Actual
No differences found

### VALGRIND REPORT
The program is run on under valgrind as
stdbuf -i 0 -o 0 -e 0 valgrind --error-exitcode=13 --leak-check=full --show-leak-kinds=all --track-origins=yes ./mazesolve_main -log 2 data/maze-small-twopath1.txt
which may be pasted onto a command line to run it.

```
==15633== Memcheck, a memory error detector
==15633== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==15633== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==15633== Command: ./mazesolve_main -log 2 data/maze-small-twopath1.txt
==15633== 
==15633== 
==15633== HEAP SUMMARY:
==15633==     in use at exit: 0 bytes in 0 blocks
==15633==   total heap usage: 26 allocs, 26 frees, 5,468 bytes allocated
==15633== 
==15633== All heap blocks were freed -- no leaks are possible
==15633== 
==15633== For lists of detected and suppressed errors, rerun with: -s
==15633== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

Test Segment 4 : ok
-------------------
** Log 3
Run on maze-small-twopath1.txt with level 3 logging.

### PROGRAM: ./mazesolve_main -log 3 data/maze-small-twopath1.txt
To run this individual test in GDB use the command:
gdb --args ./mazesolve_main -log 3 data/maze-small-twopath1.txt
but any input to the program must be typed within the debugger

### FAILURE MESSAGES
None

### SIDE-BY-SIDE DIFF of Expected vs Actual
. lines match; | lines differ; < expected line missing; > extra line in actual

```sdiff
===EXPECT===                                          ===ACTUAL===
maze: 5 rows 5 cols                                 . maze: 5 rows 5 cols
      (1,2) start                                   .       (1,2) start
      (3,2) end                                     .       (3,2) end
maze tiles:                                         . maze tiles:
#####                                               . #####
# S #                                               . # S #
# # #                                               . # # #
# E #                                               . # E #
#####                                               . #####
                                                    ) 
LOG: BFS initialization complete                    . LOG: BFS initialization complete
#####:  0                                           . #####:  0
# 0 #:  1                                           . # 0 #:  1
# # #:  2                                           . # # #:  2
# E #:  3                                           . # E #:  3
#####:  4                                           . #####:  4
01234                                               . 01234
0                                                   . 0    
queue count: 1                                      . queue count: 1
NN ROW COL                                          . NN ROW COL
 0   1   2                                          .  0   1   2
LOG: BFS STEP 1                                     . LOG: BFS STEP 1
LOG: processing neighbors of (1,2)                  . LOG: processing neighbors of (1,2)
LOG: maze state after BFS step                      . LOG: maze state after BFS step
#####:  0                                           . #####:  0
#101#:  1                                           . #101#:  1
# # #:  2                                           . # # #:  2
# E #:  3                                           . # E #:  3
#####:  4                                           . #####:  4
01234                                               . 01234
0                                                   . 0    
queue count: 2                                      . queue count: 2
NN ROW COL                                          . NN ROW COL
 0   1   1                                          .  0   1   1
 1   1   3                                          .  1   1   3
LOG: BFS STEP 2                                     . LOG: BFS STEP 2
LOG: processing neighbors of (1,1)                  . LOG: processing neighbors of (1,1)
LOG: maze state after BFS step                      . LOG: maze state after BFS step
#####:  0                                           . #####:  0
#101#:  1                                           . #101#:  1
#2# #:  2                                           . #2# #:  2
# E #:  3                                           . # E #:  3
#####:  4                                           . #####:  4
01234                                               . 01234
0                                                   . 0    
queue count: 2                                      . queue count: 2
NN ROW COL                                          . NN ROW COL
 0   1   3                                          .  0   1   3
 1   2   1                                          .  1   2   1
LOG: BFS STEP 3                                     . LOG: BFS STEP 3
LOG: processing neighbors of (1,3)                  . LOG: processing neighbors of (1,3)
LOG: maze state after BFS step                      . LOG: maze state after BFS step
#####:  0                                           . #####:  0
#101#:  1                                           . #101#:  1
#2#2#:  2                                           . #2#2#:  2
# E #:  3                                           . # E #:  3
#####:  4                                           . #####:  4
01234                                               . 01234
0                                                   . 0    
queue count: 2                                      . queue count: 2
NN ROW COL                                          . NN ROW COL
 0   2   1                                          .  0   2   1
 1   2   3                                          .  1   2   3
LOG: BFS STEP 4                                     . LOG: BFS STEP 4
LOG: processing neighbors of (2,1)                  . LOG: processing neighbors of (2,1)
LOG: maze state after BFS step                      . LOG: maze state after BFS step
#####:  0                                           . #####:  0
#101#:  1                                           . #101#:  1
#2#2#:  2                                           . #2#2#:  2
#3E #:  3                                           . #3E #:  3
#####:  4                                           . #####:  4
01234                                               . 01234
0                                                   . 0    
queue count: 2                                      . queue count: 2
NN ROW COL                                          . NN ROW COL
 0   2   3                                          .  0   2   3
 1   3   1                                          .  1   3   1
LOG: BFS STEP 5                                     . LOG: BFS STEP 5
LOG: processing neighbors of (2,3)                  . LOG: processing neighbors of (2,3)
LOG: maze state after BFS step                      . LOG: maze state after BFS step
#####:  0                                           . #####:  0
#101#:  1                                           . #101#:  1
#2#2#:  2                                           . #2#2#:  2
#3E3#:  3                                           . #3E3#:  3
#####:  4                                           . #####:  4
01234                                               . 01234
0                                                   . 0    
queue count: 2                                      . queue count: 2
NN ROW COL                                          . NN ROW COL
 0   3   1                                          .  0   3   1
 1   3   3                                          .  1   3   3
LOG: BFS STEP 6                                     . LOG: BFS STEP 6
LOG: processing neighbors of (3,1)                  . LOG: processing neighbors of (3,1)
LOG: maze state after BFS step                      . LOG: maze state after BFS step
#####:  0                                           . #####:  0
#101#:  1                                           . #101#:  1
#2#2#:  2                                           . #2#2#:  2
#343#:  3                                           . #343#:  3
#####:  4                                           . #####:  4
01234                                               . 01234
0                                                   . 0    
queue count: 2                                      . queue count: 2
NN ROW COL                                          . NN ROW COL
 0   3   3                                          .  0   3   3
 1   3   2                                          .  1   3   2
LOG: BFS STEP 7                                     . LOG: BFS STEP 7
LOG: processing neighbors of (3,3)                  . LOG: processing neighbors of (3,3)
LOG: maze state after BFS step                      . LOG: maze state after BFS step
#####:  0                                           . #####:  0
#101#:  1                                           . #101#:  1
#2#2#:  2                                           . #2#2#:  2
#343#:  3                                           . #343#:  3
#####:  4                                           . #####:  4
01234                                               . 01234
0                                                   . 0    
queue count: 1                                      . queue count: 1
NN ROW COL                                          . NN ROW COL
 0   3   2                                          .  0   3   2
LOG: BFS STEP 8                                     . LOG: BFS STEP 8
LOG: processing neighbors of (3,2)                  . LOG: processing neighbors of (3,2)
LOG: maze state after BFS step                      . LOG: maze state after BFS step
#####:  0                                           . #####:  0
#101#:  1                                           . #101#:  1
#2#2#:  2                                           . #2#2#:  2
#343#:  3                                           . #343#:  3
#####:  4                                           . #####:  4
01234                                               . 01234
0                                                   . 0    
queue count: 0                                      . queue count: 0
NN ROW COL                                          . NN ROW COL
LOG: solution START at (1,2)                        . LOG: solution START at (1,2)
LOG: solution path[0] is WEST, set (1,1) to ONPATH  . LOG: solution path[0] is WEST, set (1,1) to ONPATH
LOG: solution path[1] is SOUTH, set (2,1) to ONPATH . LOG: solution path[1] is SOUTH, set (2,1) to ONPATH
LOG: solution path[2] is SOUTH, set (3,1) to ONPATH . LOG: solution path[2] is SOUTH, set (3,1) to ONPATH
LOG: solution path[3] is EAST, set (3,2) to ONPATH  . LOG: solution path[3] is EAST, set (3,2) to ONPATH
LOG: solution END at (3,2)                          . LOG: solution END at (3,2)
                                                    ) 
SOLUTION:                                           . SOLUTION:
maze: 5 rows 5 cols                                 . maze: 5 rows 5 cols
      (1,2) start                                   .       (1,2) start
      (3,2) end                                     .       (3,2) end
maze tiles:                                         . maze tiles:
#####                                               . #####
#.S #                                               . #.S #
#.# #                                               . #.# #
#.E #                                               . #.E #
#####                                               . #####
                                                    ) 
path length: 4                                      . path length: 4
 0: WEST                                            .  0: WEST
 1: SOUTH                                           .  1: SOUTH
 2: SOUTH                                           .  2: SOUTH
 3: EAST                                            .  3: EAST

```

### LINE-BY-LINE DIFF of Expected vs Actual
No differences found

### VALGRIND REPORT
The program is run on under valgrind as
stdbuf -i 0 -o 0 -e 0 valgrind --error-exitcode=13 --leak-check=full --show-leak-kinds=all --track-origins=yes ./mazesolve_main -log 3 data/maze-small-twopath1.txt
which may be pasted onto a command line to run it.

```
==15639== Memcheck, a memory error detector
==15639== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==15639== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==15639== Command: ./mazesolve_main -log 3 data/maze-small-twopath1.txt
==15639== 
==15639== 
==15639== HEAP SUMMARY:
==15639==     in use at exit: 0 bytes in 0 blocks
==15639==   total heap usage: 26 allocs, 26 frees, 5,468 bytes allocated
==15639== 
==15639== All heap blocks were freed -- no leaks are possible
==15639== 
==15639== For lists of detected and suppressed errors, rerun with: -s
==15639== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

Test Segment 5 : ok
-------------------
** Log 4
Run on maze-small-twopath1.txt with level 4 logging.

### PROGRAM: ./mazesolve_main -log 4 data/maze-small-twopath1.txt
To run this individual test in GDB use the command:
gdb --args ./mazesolve_main -log 4 data/maze-small-twopath1.txt
but any input to the program must be typed within the debugger

### FAILURE MESSAGES
None

### SIDE-BY-SIDE DIFF of Expected vs Actual
. lines match; | lines differ; < expected line missing; > extra line in actual

```sdiff
===EXPECT===                                          ===ACTUAL===
maze: 5 rows 5 cols                                 . maze: 5 rows 5 cols
      (1,2) start                                   .       (1,2) start
      (3,2) end                                     .       (3,2) end
maze tiles:                                         . maze tiles:
#####                                               . #####
# S #                                               . # S #
# # #                                               . # # #
# E #                                               . # E #
#####                                               . #####
                                                    ) 
LOG: BFS initialization complete                    . LOG: BFS initialization complete
#####:  0                                           . #####:  0
# 0 #:  1                                           . # 0 #:  1
# # #:  2                                           . # # #:  2
# E #:  3                                           . # E #:  3
#####:  4                                           . #####:  4
01234                                               . 01234
0                                                   . 0    
queue count: 1                                      . queue count: 1
NN ROW COL                                          . NN ROW COL
 0   1   2                                          .  0   1   2
LOG: BFS STEP 1                                     . LOG: BFS STEP 1
LOG: processing neighbors of (1,2)                  . LOG: processing neighbors of (1,2)
LOG: Found tile at (1,1) with len 1 path: W         . LOG: Found tile at (1,1) with len 1 path: W
LOG: Found tile at (1,3) with len 1 path: E         . LOG: Found tile at (1,3) with len 1 path: E
LOG: maze state after BFS step                      . LOG: maze state after BFS step
#####:  0                                           . #####:  0
#101#:  1                                           . #101#:  1
# # #:  2                                           . # # #:  2
# E #:  3                                           . # E #:  3
#####:  4                                           . #####:  4
01234                                               . 01234
0                                                   . 0    
queue count: 2                                      . queue count: 2
NN ROW COL                                          . NN ROW COL
 0   1   1                                          .  0   1   1
 1   1   3                                          .  1   1   3
LOG: BFS STEP 2                                     . LOG: BFS STEP 2
LOG: processing neighbors of (1,1)                  . LOG: processing neighbors of (1,1)
LOG: Found tile at (2,1) with len 2 path: WS        . LOG: Found tile at (2,1) with len 2 path: WS
LOG: maze state after BFS step                      . LOG: maze state after BFS step
#####:  0                                           . #####:  0
#101#:  1                                           . #101#:  1
#2# #:  2                                           . #2# #:  2
# E #:  3                                           . # E #:  3
#####:  4                                           . #####:  4
01234                                               . 01234
0                                                   . 0    
queue count: 2                                      . queue count: 2
NN ROW COL                                          . NN ROW COL
 0   1   3                                          .  0   1   3
 1   2   1                                          .  1   2   1
LOG: BFS STEP 3                                     . LOG: BFS STEP 3
LOG: processing neighbors of (1,3)                  . LOG: processing neighbors of (1,3)
LOG: Found tile at (2,3) with len 2 path: ES        . LOG: Found tile at (2,3) with len 2 path: ES
LOG: maze state after BFS step                      . LOG: maze state after BFS step
#####:  0                                           . #####:  0
#101#:  1                                           . #101#:  1
#2#2#:  2                                           . #2#2#:  2
# E #:  3                                           . # E #:  3
#####:  4                                           . #####:  4
01234                                               . 01234
0                                                   . 0    
queue count: 2                                      . queue count: 2
NN ROW COL                                          . NN ROW COL
 0   2   1                                          .  0   2   1
 1   2   3                                          .  1   2   3
LOG: BFS STEP 4                                     . LOG: BFS STEP 4
LOG: processing neighbors of (2,1)                  . LOG: processing neighbors of (2,1)
LOG: Found tile at (3,1) with len 3 path: WSS       . LOG: Found tile at (3,1) with len 3 path: WSS
LOG: maze state after BFS step                      . LOG: maze state after BFS step
#####:  0                                           . #####:  0
#101#:  1                                           . #101#:  1
#2#2#:  2                                           . #2#2#:  2
#3E #:  3                                           . #3E #:  3
#####:  4                                           . #####:  4
01234                                               . 01234
0                                                   . 0    
queue count: 2                                      . queue count: 2
NN ROW COL                                          . NN ROW COL
 0   2   3                                          .  0   2   3
 1   3   1                                          .  1   3   1
LOG: BFS STEP 5                                     . LOG: BFS STEP 5
LOG: processing neighbors of (2,3)                  . LOG: processing neighbors of (2,3)
LOG: Found tile at (3,3) with len 3 path: ESS       . LOG: Found tile at (3,3) with len 3 path: ESS
LOG: maze state after BFS step                      . LOG: maze state after BFS step
#####:  0                                           . #####:  0
#101#:  1                                           . #101#:  1
#2#2#:  2                                           . #2#2#:  2
#3E3#:  3                                           . #3E3#:  3
#####:  4                                           . #####:  4
01234                                               . 01234
0                                                   . 0    
queue count: 2                                      . queue count: 2
NN ROW COL                                          . NN ROW COL
 0   3   1                                          .  0   3   1
 1   3   3                                          .  1   3   3
LOG: BFS STEP 6                                     . LOG: BFS STEP 6
LOG: processing neighbors of (3,1)                  . LOG: processing neighbors of (3,1)
LOG: Found tile at (3,2) with len 4 path: WSSE      . LOG: Found tile at (3,2) with len 4 path: WSSE
LOG: maze state after BFS step                      . LOG: maze state after BFS step
#####:  0                                           . #####:  0
#101#:  1                                           . #101#:  1
#2#2#:  2                                           . #2#2#:  2
#343#:  3                                           . #343#:  3
#####:  4                                           . #####:  4
01234                                               . 01234
0                                                   . 0    
queue count: 2                                      . queue count: 2
NN ROW COL                                          . NN ROW COL
 0   3   3                                          .  0   3   3
 1   3   2                                          .  1   3   2
LOG: BFS STEP 7                                     . LOG: BFS STEP 7
LOG: processing neighbors of (3,3)                  . LOG: processing neighbors of (3,3)
LOG: maze state after BFS step                      . LOG: maze state after BFS step
#####:  0                                           . #####:  0
#101#:  1                                           . #101#:  1
#2#2#:  2                                           . #2#2#:  2
#343#:  3                                           . #343#:  3
#####:  4                                           . #####:  4
01234                                               . 01234
0                                                   . 0    
queue count: 1                                      . queue count: 1
NN ROW COL                                          . NN ROW COL
 0   3   2                                          .  0   3   2
LOG: BFS STEP 8                                     . LOG: BFS STEP 8
LOG: processing neighbors of (3,2)                  . LOG: processing neighbors of (3,2)
LOG: maze state after BFS step                      . LOG: maze state after BFS step
#####:  0                                           . #####:  0
#101#:  1                                           . #101#:  1
#2#2#:  2                                           . #2#2#:  2
#343#:  3                                           . #343#:  3
#####:  4                                           . #####:  4
01234                                               . 01234
0                                                   . 0    
queue count: 0                                      . queue count: 0
NN ROW COL                                          . NN ROW COL
LOG: solution START at (1,2)                        . LOG: solution START at (1,2)
LOG: solution path[0] is WEST, set (1,1) to ONPATH  . LOG: solution path[0] is WEST, set (1,1) to ONPATH
LOG: solution path[1] is SOUTH, set (2,1) to ONPATH . LOG: solution path[1] is SOUTH, set (2,1) to ONPATH
LOG: solution path[2] is SOUTH, set (3,1) to ONPATH . LOG: solution path[2] is SOUTH, set (3,1) to ONPATH
LOG: solution path[3] is EAST, set (3,2) to ONPATH  . LOG: solution path[3] is EAST, set (3,2) to ONPATH
LOG: solution END at (3,2)                          . LOG: solution END at (3,2)
                                                    ) 
SOLUTION:                                           . SOLUTION:
maze: 5 rows 5 cols                                 . maze: 5 rows 5 cols
      (1,2) start                                   .       (1,2) start
      (3,2) end                                     .       (3,2) end
maze tiles:                                         . maze tiles:
#####                                               . #####
#.S #                                               . #.S #
#.# #                                               . #.# #
#.E #                                               . #.E #
#####                                               . #####
                                                    ) 
path length: 4                                      . path length: 4
 0: WEST                                            .  0: WEST
 1: SOUTH                                           .  1: SOUTH
 2: SOUTH                                           .  2: SOUTH
 3: EAST                                            .  3: EAST

```

### LINE-BY-LINE DIFF of Expected vs Actual
No differences found

### VALGRIND REPORT
The program is run on under valgrind as
stdbuf -i 0 -o 0 -e 0 valgrind --error-exitcode=13 --leak-check=full --show-leak-kinds=all --track-origins=yes ./mazesolve_main -log 4 data/maze-small-twopath1.txt
which may be pasted onto a command line to run it.

```
==15644== Memcheck, a memory error detector
==15644== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==15644== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==15644== Command: ./mazesolve_main -log 4 data/maze-small-twopath1.txt
==15644== 
==15644== 
==15644== HEAP SUMMARY:
==15644==     in use at exit: 0 bytes in 0 blocks
==15644==   total heap usage: 26 allocs, 26 frees, 5,468 bytes allocated
==15644== 
==15644== All heap blocks were freed -- no leaks are possible
==15644== 
==15644== For lists of detected and suppressed errors, rerun with: -s
==15644== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

Test Segment 6 : ok
-------------------
** Log 5
Run on maze-small-twopath1.txt with level 5 logging.

### PROGRAM: ./mazesolve_main -log 5 data/maze-small-twopath1.txt
To run this individual test in GDB use the command:
gdb --args ./mazesolve_main -log 5 data/maze-small-twopath1.txt
but any input to the program must be typed within the debugger

### FAILURE MESSAGES
None

### SIDE-BY-SIDE DIFF of Expected vs Actual
. lines match; | lines differ; < expected line missing; > extra line in actual

```sdiff
===EXPECT===                                          ===ACTUAL===
maze: 5 rows 5 cols                                 . maze: 5 rows 5 cols
      (1,2) start                                   .       (1,2) start
      (3,2) end                                     .       (3,2) end
maze tiles:                                         . maze tiles:
#####                                               . #####
# S #                                               . # S #
# # #                                               . # # #
# E #                                               . # E #
#####                                               . #####
                                                    ) 
LOG: BFS initialization complete                    . LOG: BFS initialization complete
#####:  0                                           . #####:  0
# 0 #:  1                                           . # 0 #:  1
# # #:  2                                           . # # #:  2
# E #:  3                                           . # E #:  3
#####:  4                                           . #####:  4
01234                                               . 01234
0                                                   . 0    
queue count: 1                                      . queue count: 1
NN ROW COL                                          . NN ROW COL
 0   1   2                                          .  0   1   2
LOG: BFS STEP 1                                     . LOG: BFS STEP 1
LOG: processing neighbors of (1,2)                  . LOG: processing neighbors of (1,2)
LOG: Skipping BLOCKED tile at (0,2)                 . LOG: Skipping BLOCKED tile at (0,2)
LOG: Skipping BLOCKED tile at (2,2)                 . LOG: Skipping BLOCKED tile at (2,2)
LOG: Found tile at (1,1) with len 1 path: W         . LOG: Found tile at (1,1) with len 1 path: W
LOG: Found tile at (1,3) with len 1 path: E         . LOG: Found tile at (1,3) with len 1 path: E
LOG: maze state after BFS step                      . LOG: maze state after BFS step
#####:  0                                           . #####:  0
#101#:  1                                           . #101#:  1
# # #:  2                                           . # # #:  2
# E #:  3                                           . # E #:  3
#####:  4                                           . #####:  4
01234                                               . 01234
0                                                   . 0    
queue count: 2                                      . queue count: 2
NN ROW COL                                          . NN ROW COL
 0   1   1                                          .  0   1   1
 1   1   3                                          .  1   1   3
LOG: BFS STEP 2                                     . LOG: BFS STEP 2
LOG: processing neighbors of (1,1)                  . LOG: processing neighbors of (1,1)
LOG: Skipping BLOCKED tile at (0,1)                 . LOG: Skipping BLOCKED tile at (0,1)
LOG: Found tile at (2,1) with len 2 path: WS        . LOG: Found tile at (2,1) with len 2 path: WS
LOG: Skipping BLOCKED tile at (1,0)                 . LOG: Skipping BLOCKED tile at (1,0)
LOG: Skipping FOUND tile at (1,2)                   . LOG: Skipping FOUND tile at (1,2)
LOG: maze state after BFS step                      . LOG: maze state after BFS step
#####:  0                                           . #####:  0
#101#:  1                                           . #101#:  1
#2# #:  2                                           . #2# #:  2
# E #:  3                                           . # E #:  3
#####:  4                                           . #####:  4
01234                                               . 01234
0                                                   . 0    
queue count: 2                                      . queue count: 2
NN ROW COL                                          . NN ROW COL
 0   1   3                                          .  0   1   3
 1   2   1                                          .  1   2   1
LOG: BFS STEP 3                                     . LOG: BFS STEP 3
LOG: processing neighbors of (1,3)                  . LOG: processing neighbors of (1,3)
LOG: Skipping BLOCKED tile at (0,3)                 . LOG: Skipping BLOCKED tile at (0,3)
LOG: Found tile at (2,3) with len 2 path: ES        . LOG: Found tile at (2,3) with len 2 path: ES
LOG: Skipping FOUND tile at (1,2)                   . LOG: Skipping FOUND tile at (1,2)
LOG: Skipping BLOCKED tile at (1,4)                 . LOG: Skipping BLOCKED tile at (1,4)
LOG: maze state after BFS step                      . LOG: maze state after BFS step
#####:  0                                           . #####:  0
#101#:  1                                           . #101#:  1
#2#2#:  2                                           . #2#2#:  2
# E #:  3                                           . # E #:  3
#####:  4                                           . #####:  4
01234                                               . 01234
0                                                   . 0    
queue count: 2                                      . queue count: 2
NN ROW COL                                          . NN ROW COL
 0   2   1                                          .  0   2   1
 1   2   3                                          .  1   2   3
LOG: BFS STEP 4                                     . LOG: BFS STEP 4
LOG: processing neighbors of (2,1)                  . LOG: processing neighbors of (2,1)
LOG: Skipping FOUND tile at (1,1)                   . LOG: Skipping FOUND tile at (1,1)
LOG: Found tile at (3,1) with len 3 path: WSS       . LOG: Found tile at (3,1) with len 3 path: WSS
LOG: Skipping BLOCKED tile at (2,0)                 . LOG: Skipping BLOCKED tile at (2,0)
LOG: Skipping BLOCKED tile at (2,2)                 . LOG: Skipping BLOCKED tile at (2,2)
LOG: maze state after BFS step                      . LOG: maze state after BFS step
#####:  0                                           . #####:  0
#101#:  1                                           . #101#:  1
#2#2#:  2                                           . #2#2#:  2
#3E #:  3                                           . #3E #:  3
#####:  4                                           . #####:  4
01234                                               . 01234
0                                                   . 0    
queue count: 2                                      . queue count: 2
NN ROW COL                                          . NN ROW COL
 0   2   3                                          .  0   2   3
 1   3   1                                          .  1   3   1
LOG: BFS STEP 5                                     . LOG: BFS STEP 5
LOG: processing neighbors of (2,3)                  . LOG: processing neighbors of (2,3)
LOG: Skipping FOUND tile at (1,3)                   . LOG: Skipping FOUND tile at (1,3)
LOG: Found tile at (3,3) with len 3 path: ESS       . LOG: Found tile at (3,3) with len 3 path: ESS
LOG: Skipping BLOCKED tile at (2,2)                 . LOG: Skipping BLOCKED tile at (2,2)
LOG: Skipping BLOCKED tile at (2,4)                 . LOG: Skipping BLOCKED tile at (2,4)
LOG: maze state after BFS step                      . LOG: maze state after BFS step
#####:  0                                           . #####:  0
#101#:  1                                           . #101#:  1
#2#2#:  2                                           . #2#2#:  2
#3E3#:  3                                           . #3E3#:  3
#####:  4                                           . #####:  4
01234                                               . 01234
0                                                   . 0    
queue count: 2                                      . queue count: 2
NN ROW COL                                          . NN ROW COL
 0   3   1                                          .  0   3   1
 1   3   3                                          .  1   3   3
LOG: BFS STEP 6                                     . LOG: BFS STEP 6
LOG: processing neighbors of (3,1)                  . LOG: processing neighbors of (3,1)
LOG: Skipping FOUND tile at (2,1)                   . LOG: Skipping FOUND tile at (2,1)
LOG: Skipping BLOCKED tile at (4,1)                 . LOG: Skipping BLOCKED tile at (4,1)
LOG: Skipping BLOCKED tile at (3,0)                 . LOG: Skipping BLOCKED tile at (3,0)
LOG: Found tile at (3,2) with len 4 path: WSSE      . LOG: Found tile at (3,2) with len 4 path: WSSE
LOG: maze state after BFS step                      . LOG: maze state after BFS step
#####:  0                                           . #####:  0
#101#:  1                                           . #101#:  1
#2#2#:  2                                           . #2#2#:  2
#343#:  3                                           . #343#:  3
#####:  4                                           . #####:  4
01234                                               . 01234
0                                                   . 0    
queue count: 2                                      . queue count: 2
NN ROW COL                                          . NN ROW COL
 0   3   3                                          .  0   3   3
 1   3   2                                          .  1   3   2
LOG: BFS STEP 7                                     . LOG: BFS STEP 7
LOG: processing neighbors of (3,3)                  . LOG: processing neighbors of (3,3)
LOG: Skipping FOUND tile at (2,3)                   . LOG: Skipping FOUND tile at (2,3)
LOG: Skipping BLOCKED tile at (4,3)                 . LOG: Skipping BLOCKED tile at (4,3)
LOG: Skipping FOUND tile at (3,2)                   . LOG: Skipping FOUND tile at (3,2)
LOG: Skipping BLOCKED tile at (3,4)                 . LOG: Skipping BLOCKED tile at (3,4)
LOG: maze state after BFS step                      . LOG: maze state after BFS step
#####:  0                                           . #####:  0
#101#:  1                                           . #101#:  1
#2#2#:  2                                           . #2#2#:  2
#343#:  3                                           . #343#:  3
#####:  4                                           . #####:  4
01234                                               . 01234
0                                                   . 0    
queue count: 1                                      . queue count: 1
NN ROW COL                                          . NN ROW COL
 0   3   2                                          .  0   3   2
LOG: BFS STEP 8                                     . LOG: BFS STEP 8
LOG: processing neighbors of (3,2)                  . LOG: processing neighbors of (3,2)
LOG: Skipping BLOCKED tile at (2,2)                 . LOG: Skipping BLOCKED tile at (2,2)
LOG: Skipping BLOCKED tile at (4,2)                 . LOG: Skipping BLOCKED tile at (4,2)
LOG: Skipping FOUND tile at (3,1)                   . LOG: Skipping FOUND tile at (3,1)
LOG: Skipping FOUND tile at (3,3)                   . LOG: Skipping FOUND tile at (3,3)
LOG: maze state after BFS step                      . LOG: maze state after BFS step
#####:  0                                           . #####:  0
#101#:  1                                           . #101#:  1
#2#2#:  2                                           . #2#2#:  2
#343#:  3                                           . #343#:  3
#####:  4                                           . #####:  4
01234                                               . 01234
0                                                   . 0    
queue count: 0                                      . queue count: 0
NN ROW COL                                          . NN ROW COL
LOG: solution START at (1,2)                        . LOG: solution START at (1,2)
LOG: solution path[0] is WEST, set (1,1) to ONPATH  . LOG: solution path[0] is WEST, set (1,1) to ONPATH
LOG: solution path[1] is SOUTH, set (2,1) to ONPATH . LOG: solution path[1] is SOUTH, set (2,1) to ONPATH
LOG: solution path[2] is SOUTH, set (3,1) to ONPATH . LOG: solution path[2] is SOUTH, set (3,1) to ONPATH
LOG: solution path[3] is EAST, set (3,2) to ONPATH  . LOG: solution path[3] is EAST, set (3,2) to ONPATH
LOG: solution END at (3,2)                          . LOG: solution END at (3,2)
                                                    ) 
SOLUTION:                                           . SOLUTION:
maze: 5 rows 5 cols                                 . maze: 5 rows 5 cols
      (1,2) start                                   .       (1,2) start
      (3,2) end                                     .       (3,2) end
maze tiles:                                         . maze tiles:
#####                                               . #####
#.S #                                               . #.S #
#.# #                                               . #.# #
#.E #                                               . #.E #
#####                                               . #####
                                                    ) 
path length: 4                                      . path length: 4
 0: WEST                                            .  0: WEST
 1: SOUTH                                           .  1: SOUTH
 2: SOUTH                                           .  2: SOUTH
 3: EAST                                            .  3: EAST

```

### LINE-BY-LINE DIFF of Expected vs Actual
No differences found

### VALGRIND REPORT
The program is run on under valgrind as
stdbuf -i 0 -o 0 -e 0 valgrind --error-exitcode=13 --leak-check=full --show-leak-kinds=all --track-origins=yes ./mazesolve_main -log 5 data/maze-small-twopath1.txt
which may be pasted onto a command line to run it.

```
==15645== Memcheck, a memory error detector
==15645== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==15645== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==15645== Command: ./mazesolve_main -log 5 data/maze-small-twopath1.txt
==15645== 
==15645== 
==15645== HEAP SUMMARY:
==15645==     in use at exit: 0 bytes in 0 blocks
==15645==   total heap usage: 26 allocs, 26 frees, 5,468 bytes allocated
==15645== 
==15645== All heap blocks were freed -- no leaks are possible
==15645== 
==15645== For lists of detected and suppressed errors, rerun with: -s
==15645== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

Test Segment 7 : ok
-------------------
** Log 6
Run on maze-small-twopath1.txt with level 6 logging.

### PROGRAM: ./mazesolve_main -log 6 data/maze-small-twopath1.txt
To run this individual test in GDB use the command:
gdb --args ./mazesolve_main -log 6 data/maze-small-twopath1.txt
but any input to the program must be typed within the debugger

### FAILURE MESSAGES
None

### SIDE-BY-SIDE DIFF of Expected vs Actual
. lines match; | lines differ; < expected line missing; > extra line in actual

```sdiff
===EXPECT===                                          ===ACTUAL===
LOG: expecting 5 rows and 5 columns                 . LOG: expecting 5 rows and 5 columns
LOG: beginning to read tiles                        . LOG: beginning to read tiles
LOG: (0,0) has character '#' type 1                 . LOG: (0,0) has character '#' type 1
LOG: (0,1) has character '#' type 1                 . LOG: (0,1) has character '#' type 1
LOG: (0,2) has character '#' type 1                 . LOG: (0,2) has character '#' type 1
LOG: (0,3) has character '#' type 1                 . LOG: (0,3) has character '#' type 1
LOG: (0,4) has character '#' type 1                 . LOG: (0,4) has character '#' type 1
LOG: finished reading row 0 of tiles                . LOG: finished reading row 0 of tiles
LOG: (1,0) has character '#' type 1                 . LOG: (1,0) has character '#' type 1
LOG: (1,1) has character ' ' type 2                 . LOG: (1,1) has character ' ' type 2
LOG: (1,2) has character 'S' type 4                 . LOG: (1,2) has character 'S' type 4
LOG: setting START at (1,2)                         . LOG: setting START at (1,2)
LOG: (1,3) has character ' ' type 2                 . LOG: (1,3) has character ' ' type 2
LOG: (1,4) has character '#' type 1                 . LOG: (1,4) has character '#' type 1
LOG: finished reading row 1 of tiles                . LOG: finished reading row 1 of tiles
LOG: (2,0) has character '#' type 1                 . LOG: (2,0) has character '#' type 1
LOG: (2,1) has character ' ' type 2                 . LOG: (2,1) has character ' ' type 2
LOG: (2,2) has character '#' type 1                 . LOG: (2,2) has character '#' type 1
LOG: (2,3) has character ' ' type 2                 . LOG: (2,3) has character ' ' type 2
LOG: (2,4) has character '#' type 1                 . LOG: (2,4) has character '#' type 1
LOG: finished reading row 2 of tiles                . LOG: finished reading row 2 of tiles
LOG: (3,0) has character '#' type 1                 . LOG: (3,0) has character '#' type 1
LOG: (3,1) has character ' ' type 2                 . LOG: (3,1) has character ' ' type 2
LOG: (3,2) has character 'E' type 5                 . LOG: (3,2) has character 'E' type 5
LOG: setting END at (3,2)                           . LOG: setting END at (3,2)
LOG: (3,3) has character ' ' type 2                 . LOG: (3,3) has character ' ' type 2
LOG: (3,4) has character '#' type 1                 . LOG: (3,4) has character '#' type 1
LOG: finished reading row 3 of tiles                . LOG: finished reading row 3 of tiles
LOG: (4,0) has character '#' type 1                 . LOG: (4,0) has character '#' type 1
LOG: (4,1) has character '#' type 1                 . LOG: (4,1) has character '#' type 1
LOG: (4,2) has character '#' type 1                 . LOG: (4,2) has character '#' type 1
LOG: (4,3) has character '#' type 1                 . LOG: (4,3) has character '#' type 1
LOG: (4,4) has character '#' type 1                 . LOG: (4,4) has character '#' type 1
LOG: finished reading row 4 of tiles                . LOG: finished reading row 4 of tiles
maze: 5 rows 5 cols                                 . maze: 5 rows 5 cols
      (1,2) start                                   .       (1,2) start
      (3,2) end                                     .       (3,2) end
maze tiles:                                         . maze tiles:
#####                                               . #####
# S #                                               . # S #
# # #                                               . # # #
# E #                                               . # E #
#####                                               . #####
                                                    ) 
LOG: BFS initialization complete                    . LOG: BFS initialization complete
#####:  0                                           . #####:  0
# 0 #:  1                                           . # 0 #:  1
# # #:  2                                           . # # #:  2
# E #:  3                                           . # E #:  3
#####:  4                                           . #####:  4
01234                                               . 01234
0                                                   . 0    
queue count: 1                                      . queue count: 1
NN ROW COL                                          . NN ROW COL
 0   1   2                                          .  0   1   2
LOG: BFS STEP 1                                     . LOG: BFS STEP 1
LOG: processing neighbors of (1,2)                  . LOG: processing neighbors of (1,2)
LOG: Skipping BLOCKED tile at (0,2)                 . LOG: Skipping BLOCKED tile at (0,2)
LOG: Skipping BLOCKED tile at (2,2)                 . LOG: Skipping BLOCKED tile at (2,2)
LOG: Found tile at (1,1) with len 1 path: W         . LOG: Found tile at (1,1) with len 1 path: W
LOG: Found tile at (1,3) with len 1 path: E         . LOG: Found tile at (1,3) with len 1 path: E
LOG: maze state after BFS step                      . LOG: maze state after BFS step
#####:  0                                           . #####:  0
#101#:  1                                           . #101#:  1
# # #:  2                                           . # # #:  2
# E #:  3                                           . # E #:  3
#####:  4                                           . #####:  4
01234                                               . 01234
0                                                   . 0    
queue count: 2                                      . queue count: 2
NN ROW COL                                          . NN ROW COL
 0   1   1                                          .  0   1   1
 1   1   3                                          .  1   1   3
LOG: BFS STEP 2                                     . LOG: BFS STEP 2
LOG: processing neighbors of (1,1)                  . LOG: processing neighbors of (1,1)
LOG: Skipping BLOCKED tile at (0,1)                 . LOG: Skipping BLOCKED tile at (0,1)
LOG: Found tile at (2,1) with len 2 path: WS        . LOG: Found tile at (2,1) with len 2 path: WS
LOG: Skipping BLOCKED tile at (1,0)                 . LOG: Skipping BLOCKED tile at (1,0)
LOG: Skipping FOUND tile at (1,2)                   . LOG: Skipping FOUND tile at (1,2)
LOG: maze state after BFS step                      . LOG: maze state after BFS step
#####:  0                                           . #####:  0
#101#:  1                                           . #101#:  1
#2# #:  2                                           . #2# #:  2
# E #:  3                                           . # E #:  3
#####:  4                                           . #####:  4
01234                                               . 01234
0                                                   . 0    
queue count: 2                                      . queue count: 2
NN ROW COL                                          . NN ROW COL
 0   1   3                                          .  0   1   3
 1   2   1                                          .  1   2   1
LOG: BFS STEP 3                                     . LOG: BFS STEP 3
LOG: processing neighbors of (1,3)                  . LOG: processing neighbors of (1,3)
LOG: Skipping BLOCKED tile at (0,3)                 . LOG: Skipping BLOCKED tile at (0,3)
LOG: Found tile at (2,3) with len 2 path: ES        . LOG: Found tile at (2,3) with len 2 path: ES
LOG: Skipping FOUND tile at (1,2)                   . LOG: Skipping FOUND tile at (1,2)
LOG: Skipping BLOCKED tile at (1,4)                 . LOG: Skipping BLOCKED tile at (1,4)
LOG: maze state after BFS step                      . LOG: maze state after BFS step
#####:  0                                           . #####:  0
#101#:  1                                           . #101#:  1
#2#2#:  2                                           . #2#2#:  2
# E #:  3                                           . # E #:  3
#####:  4                                           . #####:  4
01234                                               . 01234
0                                                   . 0    
queue count: 2                                      . queue count: 2
NN ROW COL                                          . NN ROW COL
 0   2   1                                          .  0   2   1
 1   2   3                                          .  1   2   3
LOG: BFS STEP 4                                     . LOG: BFS STEP 4
LOG: processing neighbors of (2,1)                  . LOG: processing neighbors of (2,1)
LOG: Skipping FOUND tile at (1,1)                   . LOG: Skipping FOUND tile at (1,1)
LOG: Found tile at (3,1) with len 3 path: WSS       . LOG: Found tile at (3,1) with len 3 path: WSS
LOG: Skipping BLOCKED tile at (2,0)                 . LOG: Skipping BLOCKED tile at (2,0)
LOG: Skipping BLOCKED tile at (2,2)                 . LOG: Skipping BLOCKED tile at (2,2)
LOG: maze state after BFS step                      . LOG: maze state after BFS step
#####:  0                                           . #####:  0
#101#:  1                                           . #101#:  1
#2#2#:  2                                           . #2#2#:  2
#3E #:  3                                           . #3E #:  3
#####:  4                                           . #####:  4
01234                                               . 01234
0                                                   . 0    
queue count: 2                                      . queue count: 2
NN ROW COL                                          . NN ROW COL
 0   2   3                                          .  0   2   3
 1   3   1                                          .  1   3   1
LOG: BFS STEP 5                                     . LOG: BFS STEP 5
LOG: processing neighbors of (2,3)                  . LOG: processing neighbors of (2,3)
LOG: Skipping FOUND tile at (1,3)                   . LOG: Skipping FOUND tile at (1,3)
LOG: Found tile at (3,3) with len 3 path: ESS       . LOG: Found tile at (3,3) with len 3 path: ESS
LOG: Skipping BLOCKED tile at (2,2)                 . LOG: Skipping BLOCKED tile at (2,2)
LOG: Skipping BLOCKED tile at (2,4)                 . LOG: Skipping BLOCKED tile at (2,4)
LOG: maze state after BFS step                      . LOG: maze state after BFS step
#####:  0                                           . #####:  0
#101#:  1                                           . #101#:  1
#2#2#:  2                                           . #2#2#:  2
#3E3#:  3                                           . #3E3#:  3
#####:  4                                           . #####:  4
01234                                               . 01234
0                                                   . 0    
queue count: 2                                      . queue count: 2
NN ROW COL                                          . NN ROW COL
 0   3   1                                          .  0   3   1
 1   3   3                                          .  1   3   3
LOG: BFS STEP 6                                     . LOG: BFS STEP 6
LOG: processing neighbors of (3,1)                  . LOG: processing neighbors of (3,1)
LOG: Skipping FOUND tile at (2,1)                   . LOG: Skipping FOUND tile at (2,1)
LOG: Skipping BLOCKED tile at (4,1)                 . LOG: Skipping BLOCKED tile at (4,1)
LOG: Skipping BLOCKED tile at (3,0)                 . LOG: Skipping BLOCKED tile at (3,0)
LOG: Found tile at (3,2) with len 4 path: WSSE      . LOG: Found tile at (3,2) with len 4 path: WSSE
LOG: maze state after BFS step                      . LOG: maze state after BFS step
#####:  0                                           . #####:  0
#101#:  1                                           . #101#:  1
#2#2#:  2                                           . #2#2#:  2
#343#:  3                                           . #343#:  3
#####:  4                                           . #####:  4
01234                                               . 01234
0                                                   . 0    
queue count: 2                                      . queue count: 2
NN ROW COL                                          . NN ROW COL
 0   3   3                                          .  0   3   3
 1   3   2                                          .  1   3   2
LOG: BFS STEP 7                                     . LOG: BFS STEP 7
LOG: processing neighbors of (3,3)                  . LOG: processing neighbors of (3,3)
LOG: Skipping FOUND tile at (2,3)                   . LOG: Skipping FOUND tile at (2,3)
LOG: Skipping BLOCKED tile at (4,3)                 . LOG: Skipping BLOCKED tile at (4,3)
LOG: Skipping FOUND tile at (3,2)                   . LOG: Skipping FOUND tile at (3,2)
LOG: Skipping BLOCKED tile at (3,4)                 . LOG: Skipping BLOCKED tile at (3,4)
LOG: maze state after BFS step                      . LOG: maze state after BFS step
#####:  0                                           . #####:  0
#101#:  1                                           . #101#:  1
#2#2#:  2                                           . #2#2#:  2
#343#:  3                                           . #343#:  3
#####:  4                                           . #####:  4
01234                                               . 01234
0                                                   . 0    
queue count: 1                                      . queue count: 1
NN ROW COL                                          . NN ROW COL
 0   3   2                                          .  0   3   2
LOG: BFS STEP 8                                     . LOG: BFS STEP 8
LOG: processing neighbors of (3,2)                  . LOG: processing neighbors of (3,2)
LOG: Skipping BLOCKED tile at (2,2)                 . LOG: Skipping BLOCKED tile at (2,2)
LOG: Skipping BLOCKED tile at (4,2)                 . LOG: Skipping BLOCKED tile at (4,2)
LOG: Skipping FOUND tile at (3,1)                   . LOG: Skipping FOUND tile at (3,1)
LOG: Skipping FOUND tile at (3,3)                   . LOG: Skipping FOUND tile at (3,3)
LOG: maze state after BFS step                      . LOG: maze state after BFS step
#####:  0                                           . #####:  0
#101#:  1                                           . #101#:  1
#2#2#:  2                                           . #2#2#:  2
#343#:  3                                           . #343#:  3
#####:  4                                           . #####:  4
01234                                               . 01234
0                                                   . 0    
queue count: 0                                      . queue count: 0
NN ROW COL                                          . NN ROW COL
LOG: solution START at (1,2)                        . LOG: solution START at (1,2)
LOG: solution path[0] is WEST, set (1,1) to ONPATH  . LOG: solution path[0] is WEST, set (1,1) to ONPATH
LOG: solution path[1] is SOUTH, set (2,1) to ONPATH . LOG: solution path[1] is SOUTH, set (2,1) to ONPATH
LOG: solution path[2] is SOUTH, set (3,1) to ONPATH . LOG: solution path[2] is SOUTH, set (3,1) to ONPATH
LOG: solution path[3] is EAST, set (3,2) to ONPATH  . LOG: solution path[3] is EAST, set (3,2) to ONPATH
LOG: solution END at (3,2)                          . LOG: solution END at (3,2)
                                                    ) 
SOLUTION:                                           . SOLUTION:
maze: 5 rows 5 cols                                 . maze: 5 rows 5 cols
      (1,2) start                                   .       (1,2) start
      (3,2) end                                     .       (3,2) end
maze tiles:                                         . maze tiles:
#####                                               . #####
#.S #                                               . #.S #
#.# #                                               . #.# #
#.E #                                               . #.E #
#####                                               . #####
                                                    ) 
path length: 4                                      . path length: 4
 0: WEST                                            .  0: WEST
 1: SOUTH                                           .  1: SOUTH
 2: SOUTH                                           .  2: SOUTH
 3: EAST                                            .  3: EAST

```

### LINE-BY-LINE DIFF of Expected vs Actual
No differences found

### VALGRIND REPORT
The program is run on under valgrind as
stdbuf -i 0 -o 0 -e 0 valgrind --error-exitcode=13 --leak-check=full --show-leak-kinds=all --track-origins=yes ./mazesolve_main -log 6 data/maze-small-twopath1.txt
which may be pasted onto a command line to run it.

```
==15648== Memcheck, a memory error detector
==15648== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==15648== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==15648== Command: ./mazesolve_main -log 6 data/maze-small-twopath1.txt
==15648== 
==15648== 
==15648== HEAP SUMMARY:
==15648==     in use at exit: 0 bytes in 0 blocks
==15648==   total heap usage: 26 allocs, 26 frees, 5,468 bytes allocated
==15648== 
==15648== All heap blocks were freed -- no leaks are possible
==15648== 
==15648== For lists of detected and suppressed errors, rerun with: -s
==15648== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

Test Segment 8 : ok
-------------------
** Log All
Run on maze-small-twopath1.txt with level 10 logging which enables all
log messages.

### PROGRAM: ./mazesolve_main -log 10 data/maze-small-twopath1.txt
To run this individual test in GDB use the command:
gdb --args ./mazesolve_main -log 10 data/maze-small-twopath1.txt
but any input to the program must be typed within the debugger

### FAILURE MESSAGES
None

### SIDE-BY-SIDE DIFF of Expected vs Actual
. lines match; | lines differ; < expected line missing; > extra line in actual

```sdiff
===EXPECT===                                          ===ACTUAL===
LOG: expecting 5 rows and 5 columns                 . LOG: expecting 5 rows and 5 columns
LOG: beginning to read tiles                        . LOG: beginning to read tiles
LOG: (0,0) has character '#' type 1                 . LOG: (0,0) has character '#' type 1
LOG: (0,1) has character '#' type 1                 . LOG: (0,1) has character '#' type 1
LOG: (0,2) has character '#' type 1                 . LOG: (0,2) has character '#' type 1
LOG: (0,3) has character '#' type 1                 . LOG: (0,3) has character '#' type 1
LOG: (0,4) has character '#' type 1                 . LOG: (0,4) has character '#' type 1
LOG: finished reading row 0 of tiles                . LOG: finished reading row 0 of tiles
LOG: (1,0) has character '#' type 1                 . LOG: (1,0) has character '#' type 1
LOG: (1,1) has character ' ' type 2                 . LOG: (1,1) has character ' ' type 2
LOG: (1,2) has character 'S' type 4                 . LOG: (1,2) has character 'S' type 4
LOG: setting START at (1,2)                         . LOG: setting START at (1,2)
LOG: (1,3) has character ' ' type 2                 . LOG: (1,3) has character ' ' type 2
LOG: (1,4) has character '#' type 1                 . LOG: (1,4) has character '#' type 1
LOG: finished reading row 1 of tiles                . LOG: finished reading row 1 of tiles
LOG: (2,0) has character '#' type 1                 . LOG: (2,0) has character '#' type 1
LOG: (2,1) has character ' ' type 2                 . LOG: (2,1) has character ' ' type 2
LOG: (2,2) has character '#' type 1                 . LOG: (2,2) has character '#' type 1
LOG: (2,3) has character ' ' type 2                 . LOG: (2,3) has character ' ' type 2
LOG: (2,4) has character '#' type 1                 . LOG: (2,4) has character '#' type 1
LOG: finished reading row 2 of tiles                . LOG: finished reading row 2 of tiles
LOG: (3,0) has character '#' type 1                 . LOG: (3,0) has character '#' type 1
LOG: (3,1) has character ' ' type 2                 . LOG: (3,1) has character ' ' type 2
LOG: (3,2) has character 'E' type 5                 . LOG: (3,2) has character 'E' type 5
LOG: setting END at (3,2)                           . LOG: setting END at (3,2)
LOG: (3,3) has character ' ' type 2                 . LOG: (3,3) has character ' ' type 2
LOG: (3,4) has character '#' type 1                 . LOG: (3,4) has character '#' type 1
LOG: finished reading row 3 of tiles                . LOG: finished reading row 3 of tiles
LOG: (4,0) has character '#' type 1                 . LOG: (4,0) has character '#' type 1
LOG: (4,1) has character '#' type 1                 . LOG: (4,1) has character '#' type 1
LOG: (4,2) has character '#' type 1                 . LOG: (4,2) has character '#' type 1
LOG: (4,3) has character '#' type 1                 . LOG: (4,3) has character '#' type 1
LOG: (4,4) has character '#' type 1                 . LOG: (4,4) has character '#' type 1
LOG: finished reading row 4 of tiles                . LOG: finished reading row 4 of tiles
maze: 5 rows 5 cols                                 . maze: 5 rows 5 cols
      (1,2) start                                   .       (1,2) start
      (3,2) end                                     .       (3,2) end
maze tiles:                                         . maze tiles:
#####                                               . #####
# S #                                               . # S #
# # #                                               . # # #
# E #                                               . # E #
#####                                               . #####
                                                    ) 
LOG: BFS initialization complete                    . LOG: BFS initialization complete
#####:  0                                           . #####:  0
# 0 #:  1                                           . # 0 #:  1
# # #:  2                                           . # # #:  2
# E #:  3                                           . # E #:  3
#####:  4                                           . #####:  4
01234                                               . 01234
0                                                   . 0    
queue count: 1                                      . queue count: 1
NN ROW COL                                          . NN ROW COL
 0   1   2                                          .  0   1   2
LOG: BFS STEP 1                                     . LOG: BFS STEP 1
LOG: processing neighbors of (1,2)                  . LOG: processing neighbors of (1,2)
LOG: Skipping BLOCKED tile at (0,2)                 . LOG: Skipping BLOCKED tile at (0,2)
LOG: Skipping BLOCKED tile at (2,2)                 . LOG: Skipping BLOCKED tile at (2,2)
LOG: Found tile at (1,1) with len 1 path: W         . LOG: Found tile at (1,1) with len 1 path: W
LOG: Found tile at (1,3) with len 1 path: E         . LOG: Found tile at (1,3) with len 1 path: E
LOG: maze state after BFS step                      . LOG: maze state after BFS step
#####:  0                                           . #####:  0
#101#:  1                                           . #101#:  1
# # #:  2                                           . # # #:  2
# E #:  3                                           . # E #:  3
#####:  4                                           . #####:  4
01234                                               . 01234
0                                                   . 0    
queue count: 2                                      . queue count: 2
NN ROW COL                                          . NN ROW COL
 0   1   1                                          .  0   1   1
 1   1   3                                          .  1   1   3
LOG: BFS STEP 2                                     . LOG: BFS STEP 2
LOG: processing neighbors of (1,1)                  . LOG: processing neighbors of (1,1)
LOG: Skipping BLOCKED tile at (0,1)                 . LOG: Skipping BLOCKED tile at (0,1)
LOG: Found tile at (2,1) with len 2 path: WS        . LOG: Found tile at (2,1) with len 2 path: WS
LOG: Skipping BLOCKED tile at (1,0)                 . LOG: Skipping BLOCKED tile at (1,0)
LOG: Skipping FOUND tile at (1,2)                   . LOG: Skipping FOUND tile at (1,2)
LOG: maze state after BFS step                      . LOG: maze state after BFS step
#####:  0                                           . #####:  0
#101#:  1                                           . #101#:  1
#2# #:  2                                           . #2# #:  2
# E #:  3                                           . # E #:  3
#####:  4                                           . #####:  4
01234                                               . 01234
0                                                   . 0    
queue count: 2                                      . queue count: 2
NN ROW COL                                          . NN ROW COL
 0   1   3                                          .  0   1   3
 1   2   1                                          .  1   2   1
LOG: BFS STEP 3                                     . LOG: BFS STEP 3
LOG: processing neighbors of (1,3)                  . LOG: processing neighbors of (1,3)
LOG: Skipping BLOCKED tile at (0,3)                 . LOG: Skipping BLOCKED tile at (0,3)
LOG: Found tile at (2,3) with len 2 path: ES        . LOG: Found tile at (2,3) with len 2 path: ES
LOG: Skipping FOUND tile at (1,2)                   . LOG: Skipping FOUND tile at (1,2)
LOG: Skipping BLOCKED tile at (1,4)                 . LOG: Skipping BLOCKED tile at (1,4)
LOG: maze state after BFS step                      . LOG: maze state after BFS step
#####:  0                                           . #####:  0
#101#:  1                                           . #101#:  1
#2#2#:  2                                           . #2#2#:  2
# E #:  3                                           . # E #:  3
#####:  4                                           . #####:  4
01234                                               . 01234
0                                                   . 0    
queue count: 2                                      . queue count: 2
NN ROW COL                                          . NN ROW COL
 0   2   1                                          .  0   2   1
 1   2   3                                          .  1   2   3
LOG: BFS STEP 4                                     . LOG: BFS STEP 4
LOG: processing neighbors of (2,1)                  . LOG: processing neighbors of (2,1)
LOG: Skipping FOUND tile at (1,1)                   . LOG: Skipping FOUND tile at (1,1)
LOG: Found tile at (3,1) with len 3 path: WSS       . LOG: Found tile at (3,1) with len 3 path: WSS
LOG: Skipping BLOCKED tile at (2,0)                 . LOG: Skipping BLOCKED tile at (2,0)
LOG: Skipping BLOCKED tile at (2,2)                 . LOG: Skipping BLOCKED tile at (2,2)
LOG: maze state after BFS step                      . LOG: maze state after BFS step
#####:  0                                           . #####:  0
#101#:  1                                           . #101#:  1
#2#2#:  2                                           . #2#2#:  2
#3E #:  3                                           . #3E #:  3
#####:  4                                           . #####:  4
01234                                               . 01234
0                                                   . 0    
queue count: 2                                      . queue count: 2
NN ROW COL                                          . NN ROW COL
 0   2   3                                          .  0   2   3
 1   3   1                                          .  1   3   1
LOG: BFS STEP 5                                     . LOG: BFS STEP 5
LOG: processing neighbors of (2,3)                  . LOG: processing neighbors of (2,3)
LOG: Skipping FOUND tile at (1,3)                   . LOG: Skipping FOUND tile at (1,3)
LOG: Found tile at (3,3) with len 3 path: ESS       . LOG: Found tile at (3,3) with len 3 path: ESS
LOG: Skipping BLOCKED tile at (2,2)                 . LOG: Skipping BLOCKED tile at (2,2)
LOG: Skipping BLOCKED tile at (2,4)                 . LOG: Skipping BLOCKED tile at (2,4)
LOG: maze state after BFS step                      . LOG: maze state after BFS step
#####:  0                                           . #####:  0
#101#:  1                                           . #101#:  1
#2#2#:  2                                           . #2#2#:  2
#3E3#:  3                                           . #3E3#:  3
#####:  4                                           . #####:  4
01234                                               . 01234
0                                                   . 0    
queue count: 2                                      . queue count: 2
NN ROW COL                                          . NN ROW COL
 0   3   1                                          .  0   3   1
 1   3   3                                          .  1   3   3
LOG: BFS STEP 6                                     . LOG: BFS STEP 6
LOG: processing neighbors of (3,1)                  . LOG: processing neighbors of (3,1)
LOG: Skipping FOUND tile at (2,1)                   . LOG: Skipping FOUND tile at (2,1)
LOG: Skipping BLOCKED tile at (4,1)                 . LOG: Skipping BLOCKED tile at (4,1)
LOG: Skipping BLOCKED tile at (3,0)                 . LOG: Skipping BLOCKED tile at (3,0)
LOG: Found tile at (3,2) with len 4 path: WSSE      . LOG: Found tile at (3,2) with len 4 path: WSSE
LOG: maze state after BFS step                      . LOG: maze state after BFS step
#####:  0                                           . #####:  0
#101#:  1                                           . #101#:  1
#2#2#:  2                                           . #2#2#:  2
#343#:  3                                           . #343#:  3
#####:  4                                           . #####:  4
01234                                               . 01234
0                                                   . 0    
queue count: 2                                      . queue count: 2
NN ROW COL                                          . NN ROW COL
 0   3   3                                          .  0   3   3
 1   3   2                                          .  1   3   2
LOG: BFS STEP 7                                     . LOG: BFS STEP 7
LOG: processing neighbors of (3,3)                  . LOG: processing neighbors of (3,3)
LOG: Skipping FOUND tile at (2,3)                   . LOG: Skipping FOUND tile at (2,3)
LOG: Skipping BLOCKED tile at (4,3)                 . LOG: Skipping BLOCKED tile at (4,3)
LOG: Skipping FOUND tile at (3,2)                   . LOG: Skipping FOUND tile at (3,2)
LOG: Skipping BLOCKED tile at (3,4)                 . LOG: Skipping BLOCKED tile at (3,4)
LOG: maze state after BFS step                      . LOG: maze state after BFS step
#####:  0                                           . #####:  0
#101#:  1                                           . #101#:  1
#2#2#:  2                                           . #2#2#:  2
#343#:  3                                           . #343#:  3
#####:  4                                           . #####:  4
01234                                               . 01234
0                                                   . 0    
queue count: 1                                      . queue count: 1
NN ROW COL                                          . NN ROW COL
 0   3   2                                          .  0   3   2
LOG: BFS STEP 8                                     . LOG: BFS STEP 8
LOG: processing neighbors of (3,2)                  . LOG: processing neighbors of (3,2)
LOG: Skipping BLOCKED tile at (2,2)                 . LOG: Skipping BLOCKED tile at (2,2)
LOG: Skipping BLOCKED tile at (4,2)                 . LOG: Skipping BLOCKED tile at (4,2)
LOG: Skipping FOUND tile at (3,1)                   . LOG: Skipping FOUND tile at (3,1)
LOG: Skipping FOUND tile at (3,3)                   . LOG: Skipping FOUND tile at (3,3)
LOG: maze state after BFS step                      . LOG: maze state after BFS step
#####:  0                                           . #####:  0
#101#:  1                                           . #101#:  1
#2#2#:  2                                           . #2#2#:  2
#343#:  3                                           . #343#:  3
#####:  4                                           . #####:  4
01234                                               . 01234
0                                                   . 0    
queue count: 0                                      . queue count: 0
NN ROW COL                                          . NN ROW COL
LOG: solution START at (1,2)                        . LOG: solution START at (1,2)
LOG: solution path[0] is WEST, set (1,1) to ONPATH  . LOG: solution path[0] is WEST, set (1,1) to ONPATH
LOG: solution path[1] is SOUTH, set (2,1) to ONPATH . LOG: solution path[1] is SOUTH, set (2,1) to ONPATH
LOG: solution path[2] is SOUTH, set (3,1) to ONPATH . LOG: solution path[2] is SOUTH, set (3,1) to ONPATH
LOG: solution path[3] is EAST, set (3,2) to ONPATH  . LOG: solution path[3] is EAST, set (3,2) to ONPATH
LOG: solution END at (3,2)                          . LOG: solution END at (3,2)
                                                    ) 
SOLUTION:                                           . SOLUTION:
maze: 5 rows 5 cols                                 . maze: 5 rows 5 cols
      (1,2) start                                   .       (1,2) start
      (3,2) end                                     .       (3,2) end
maze tiles:                                         . maze tiles:
#####                                               . #####
#.S #                                               . #.S #
#.# #                                               . #.# #
#.E #                                               . #.E #
#####                                               . #####
                                                    ) 
path length: 4                                      . path length: 4
 0: WEST                                            .  0: WEST
 1: SOUTH                                           .  1: SOUTH
 2: SOUTH                                           .  2: SOUTH
 3: EAST                                            .  3: EAST

```

### LINE-BY-LINE DIFF of Expected vs Actual
No differences found

### VALGRIND REPORT
The program is run on under valgrind as
stdbuf -i 0 -o 0 -e 0 valgrind --error-exitcode=13 --leak-check=full --show-leak-kinds=all --track-origins=yes ./mazesolve_main -log 10 data/maze-small-twopath1.txt
which may be pasted onto a command line to run it.

```
==15649== Memcheck, a memory error detector
==15649== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==15649== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==15649== Command: ./mazesolve_main -log 10 data/maze-small-twopath1.txt
==15649== 
==15649== 
==15649== HEAP SUMMARY:
==15649==     in use at exit: 0 bytes in 0 blocks
==15649==   total heap usage: 26 allocs, 26 frees, 5,468 bytes allocated
==15649== 
==15649== All heap blocks were freed -- no leaks are possible
==15649== 
==15649== For lists of detected and suppressed errors, rerun with: -s
==15649== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

### SUMMARY
Test Passed
