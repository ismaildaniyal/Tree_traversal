(TEST 8) mazesolve_main3 : ok
=============================

COMMENTS
--------
Solve maze-small-threepath1.txt with some logging enabled.

PROGRAM: ./mazesolve_main -log 4 data/maze-small-threepath1.txt
---------------------------------------------------------------
To run this individual test in GDB use the command:
  gdb --args ./mazesolve_main -log 4 data/maze-small-threepath1.txt
but any input to the program must be typed within the debugger

FAILURE MESSAGES
----------------
None

SIDE-BY-SIDE DIFF of Expected vs Actual
---------------------------------------
. lines match; | lines differ; < expected line missing; > extra line in actual

```sdiff
===EXPECT===                                          ===ACTUAL===
maze: 6 rows 9 cols                                 . maze: 6 rows 9 cols
      (2,4) start                                   .       (2,4) start
      (3,7) end                                     .       (3,7) end
maze tiles:                                         . maze tiles:
#########                                           . #########
#    #  #                                           . #    #  #
# ##S  ##                                           . # ##S  ##
#  # ##E#                                           . #  # ##E#
#       #                                           . #       #
#########                                           . #########
                                                    ) 
LOG: BFS initialization complete                    . LOG: BFS initialization complete
#########:  0                                       . #########:  0
#    #  #:  1                                       . #    #  #:  1
# ##0  ##:  2                                       . # ##0  ##:  2
#  # ##E#:  3                                       . #  # ##E#:  3
#       #:  4                                       . #       #:  4
#########:  5                                       . #########:  5
012345678                                           . 012345678
0                                                   . 0        
queue count: 1                                      . queue count: 1
NN ROW COL                                          . NN ROW COL
 0   2   4                                          .  0   2   4
LOG: BFS STEP 1                                     . LOG: BFS STEP 1
LOG: processing neighbors of (2,4)                  . LOG: processing neighbors of (2,4)
LOG: Found tile at (1,4) with len 1 path: N         . LOG: Found tile at (1,4) with len 1 path: N
LOG: Found tile at (3,4) with len 1 path: S         . LOG: Found tile at (3,4) with len 1 path: S
LOG: Found tile at (2,5) with len 1 path: E         . LOG: Found tile at (2,5) with len 1 path: E
LOG: maze state after BFS step                      . LOG: maze state after BFS step
#########:  0                                       . #########:  0
#   1#  #:  1                                       . #   1#  #:  1
# ##01 ##:  2                                       . # ##01 ##:  2
#  #1##E#:  3                                       . #  #1##E#:  3
#       #:  4                                       . #       #:  4
#########:  5                                       . #########:  5
012345678                                           . 012345678
0                                                   . 0        
queue count: 3                                      . queue count: 3
NN ROW COL                                          . NN ROW COL
 0   1   4                                          .  0   1   4
 1   3   4                                          .  1   3   4
 2   2   5                                          .  2   2   5
LOG: BFS STEP 2                                     . LOG: BFS STEP 2
LOG: processing neighbors of (1,4)                  . LOG: processing neighbors of (1,4)
LOG: Found tile at (1,3) with len 2 path: NW        . LOG: Found tile at (1,3) with len 2 path: NW
LOG: maze state after BFS step                      . LOG: maze state after BFS step
#########:  0                                       . #########:  0
#  21#  #:  1                                       . #  21#  #:  1
# ##01 ##:  2                                       . # ##01 ##:  2
#  #1##E#:  3                                       . #  #1##E#:  3
#       #:  4                                       . #       #:  4
#########:  5                                       . #########:  5
012345678                                           . 012345678
0                                                   . 0        
queue count: 3                                      . queue count: 3
NN ROW COL                                          . NN ROW COL
 0   3   4                                          .  0   3   4
 1   2   5                                          .  1   2   5
 2   1   3                                          .  2   1   3
LOG: BFS STEP 3                                     . LOG: BFS STEP 3
LOG: processing neighbors of (3,4)                  . LOG: processing neighbors of (3,4)
LOG: Found tile at (4,4) with len 2 path: SS        . LOG: Found tile at (4,4) with len 2 path: SS
LOG: maze state after BFS step                      . LOG: maze state after BFS step
#########:  0                                       . #########:  0
#  21#  #:  1                                       . #  21#  #:  1
# ##01 ##:  2                                       . # ##01 ##:  2
#  #1##E#:  3                                       . #  #1##E#:  3
#   2   #:  4                                       . #   2   #:  4
#########:  5                                       . #########:  5
012345678                                           . 012345678
0                                                   . 0        
queue count: 3                                      . queue count: 3
NN ROW COL                                          . NN ROW COL
 0   2   5                                          .  0   2   5
 1   1   3                                          .  1   1   3
 2   4   4                                          .  2   4   4
LOG: BFS STEP 4                                     . LOG: BFS STEP 4
LOG: processing neighbors of (2,5)                  . LOG: processing neighbors of (2,5)
LOG: Found tile at (2,6) with len 2 path: EE        . LOG: Found tile at (2,6) with len 2 path: EE
LOG: maze state after BFS step                      . LOG: maze state after BFS step
#########:  0                                       . #########:  0
#  21#  #:  1                                       . #  21#  #:  1
# ##012##:  2                                       . # ##012##:  2
#  #1##E#:  3                                       . #  #1##E#:  3
#   2   #:  4                                       . #   2   #:  4
#########:  5                                       . #########:  5
012345678                                           . 012345678
0                                                   . 0        
queue count: 3                                      . queue count: 3
NN ROW COL                                          . NN ROW COL
 0   1   3                                          .  0   1   3
 1   4   4                                          .  1   4   4
 2   2   6                                          .  2   2   6
LOG: BFS STEP 5                                     . LOG: BFS STEP 5
LOG: processing neighbors of (1,3)                  . LOG: processing neighbors of (1,3)
LOG: Found tile at (1,2) with len 3 path: NWW       . LOG: Found tile at (1,2) with len 3 path: NWW
LOG: maze state after BFS step                      . LOG: maze state after BFS step
#########:  0                                       . #########:  0
# 321#  #:  1                                       . # 321#  #:  1
# ##012##:  2                                       . # ##012##:  2
#  #1##E#:  3                                       . #  #1##E#:  3
#   2   #:  4                                       . #   2   #:  4
#########:  5                                       . #########:  5
012345678                                           . 012345678
0                                                   . 0        
queue count: 3                                      . queue count: 3
NN ROW COL                                          . NN ROW COL
 0   4   4                                          .  0   4   4
 1   2   6                                          .  1   2   6
 2   1   2                                          .  2   1   2
LOG: BFS STEP 6                                     . LOG: BFS STEP 6
LOG: processing neighbors of (4,4)                  . LOG: processing neighbors of (4,4)
LOG: Found tile at (4,3) with len 3 path: SSW       . LOG: Found tile at (4,3) with len 3 path: SSW
LOG: Found tile at (4,5) with len 3 path: SSE       . LOG: Found tile at (4,5) with len 3 path: SSE
LOG: maze state after BFS step                      . LOG: maze state after BFS step
#########:  0                                       . #########:  0
# 321#  #:  1                                       . # 321#  #:  1
# ##012##:  2                                       . # ##012##:  2
#  #1##E#:  3                                       . #  #1##E#:  3
#  323  #:  4                                       . #  323  #:  4
#########:  5                                       . #########:  5
012345678                                           . 012345678
0                                                   . 0        
queue count: 4                                      . queue count: 4
NN ROW COL                                          . NN ROW COL
 0   2   6                                          .  0   2   6
 1   1   2                                          .  1   1   2
 2   4   3                                          .  2   4   3
 3   4   5                                          .  3   4   5
LOG: BFS STEP 7                                     . LOG: BFS STEP 7
LOG: processing neighbors of (2,6)                  . LOG: processing neighbors of (2,6)
LOG: Found tile at (1,6) with len 3 path: EEN       . LOG: Found tile at (1,6) with len 3 path: EEN
LOG: maze state after BFS step                      . LOG: maze state after BFS step
#########:  0                                       . #########:  0
# 321#3 #:  1                                       . # 321#3 #:  1
# ##012##:  2                                       . # ##012##:  2
#  #1##E#:  3                                       . #  #1##E#:  3
#  323  #:  4                                       . #  323  #:  4
#########:  5                                       . #########:  5
012345678                                           . 012345678
0                                                   . 0        
queue count: 4                                      . queue count: 4
NN ROW COL                                          . NN ROW COL
 0   1   2                                          .  0   1   2
 1   4   3                                          .  1   4   3
 2   4   5                                          .  2   4   5
 3   1   6                                          .  3   1   6
LOG: BFS STEP 8                                     . LOG: BFS STEP 8
LOG: processing neighbors of (1,2)                  . LOG: processing neighbors of (1,2)
LOG: Found tile at (1,1) with len 4 path: NWWW      . LOG: Found tile at (1,1) with len 4 path: NWWW
LOG: maze state after BFS step                      . LOG: maze state after BFS step
#########:  0                                       . #########:  0
#4321#3 #:  1                                       . #4321#3 #:  1
# ##012##:  2                                       . # ##012##:  2
#  #1##E#:  3                                       . #  #1##E#:  3
#  323  #:  4                                       . #  323  #:  4
#########:  5                                       . #########:  5
012345678                                           . 012345678
0                                                   . 0        
queue count: 4                                      . queue count: 4
NN ROW COL                                          . NN ROW COL
 0   4   3                                          .  0   4   3
 1   4   5                                          .  1   4   5
 2   1   6                                          .  2   1   6
 3   1   1                                          .  3   1   1
LOG: BFS STEP 9                                     . LOG: BFS STEP 9
LOG: processing neighbors of (4,3)                  . LOG: processing neighbors of (4,3)
LOG: Found tile at (4,2) with len 4 path: SSWW      . LOG: Found tile at (4,2) with len 4 path: SSWW
LOG: maze state after BFS step                      . LOG: maze state after BFS step
#########:  0                                       . #########:  0
#4321#3 #:  1                                       . #4321#3 #:  1
# ##012##:  2                                       . # ##012##:  2
#  #1##E#:  3                                       . #  #1##E#:  3
# 4323  #:  4                                       . # 4323  #:  4
#########:  5                                       . #########:  5
012345678                                           . 012345678
0                                                   . 0        
queue count: 4                                      . queue count: 4
NN ROW COL                                          . NN ROW COL
 0   4   5                                          .  0   4   5
 1   1   6                                          .  1   1   6
 2   1   1                                          .  2   1   1
 3   4   2                                          .  3   4   2
LOG: BFS STEP 10                                    . LOG: BFS STEP 10
LOG: processing neighbors of (4,5)                  . LOG: processing neighbors of (4,5)
LOG: Found tile at (4,6) with len 4 path: SSEE      . LOG: Found tile at (4,6) with len 4 path: SSEE
LOG: maze state after BFS step                      . LOG: maze state after BFS step
#########:  0                                       . #########:  0
#4321#3 #:  1                                       . #4321#3 #:  1
# ##012##:  2                                       . # ##012##:  2
#  #1##E#:  3                                       . #  #1##E#:  3
# 43234 #:  4                                       . # 43234 #:  4
#########:  5                                       . #########:  5
012345678                                           . 012345678
0                                                   . 0        
queue count: 4                                      . queue count: 4
NN ROW COL                                          . NN ROW COL
 0   1   6                                          .  0   1   6
 1   1   1                                          .  1   1   1
 2   4   2                                          .  2   4   2
 3   4   6                                          .  3   4   6
LOG: BFS STEP 11                                    . LOG: BFS STEP 11
LOG: processing neighbors of (1,6)                  . LOG: processing neighbors of (1,6)
LOG: Found tile at (1,7) with len 4 path: EENE      . LOG: Found tile at (1,7) with len 4 path: EENE
LOG: maze state after BFS step                      . LOG: maze state after BFS step
#########:  0                                       . #########:  0
#4321#34#:  1                                       . #4321#34#:  1
# ##012##:  2                                       . # ##012##:  2
#  #1##E#:  3                                       . #  #1##E#:  3
# 43234 #:  4                                       . # 43234 #:  4
#########:  5                                       . #########:  5
012345678                                           . 012345678
0                                                   . 0        
queue count: 4                                      . queue count: 4
NN ROW COL                                          . NN ROW COL
 0   1   1                                          .  0   1   1
 1   4   2                                          .  1   4   2
 2   4   6                                          .  2   4   6
 3   1   7                                          .  3   1   7
LOG: BFS STEP 12                                    . LOG: BFS STEP 12
LOG: processing neighbors of (1,1)                  . LOG: processing neighbors of (1,1)
LOG: Found tile at (2,1) with len 5 path: NWWWS     . LOG: Found tile at (2,1) with len 5 path: NWWWS
LOG: maze state after BFS step                      . LOG: maze state after BFS step
#########:  0                                       . #########:  0
#4321#34#:  1                                       . #4321#34#:  1
#5##012##:  2                                       . #5##012##:  2
#  #1##E#:  3                                       . #  #1##E#:  3
# 43234 #:  4                                       . # 43234 #:  4
#########:  5                                       . #########:  5
012345678                                           . 012345678
0                                                   . 0        
queue count: 4                                      . queue count: 4
NN ROW COL                                          . NN ROW COL
 0   4   2                                          .  0   4   2
 1   4   6                                          .  1   4   6
 2   1   7                                          .  2   1   7
 3   2   1                                          .  3   2   1
LOG: BFS STEP 13                                    . LOG: BFS STEP 13
LOG: processing neighbors of (4,2)                  . LOG: processing neighbors of (4,2)
LOG: Found tile at (3,2) with len 5 path: SSWWN     . LOG: Found tile at (3,2) with len 5 path: SSWWN
LOG: Found tile at (4,1) with len 5 path: SSWWW     . LOG: Found tile at (4,1) with len 5 path: SSWWW
LOG: maze state after BFS step                      . LOG: maze state after BFS step
#########:  0                                       . #########:  0
#4321#34#:  1                                       . #4321#34#:  1
#5##012##:  2                                       . #5##012##:  2
# 5#1##E#:  3                                       . # 5#1##E#:  3
#543234 #:  4                                       . #543234 #:  4
#########:  5                                       . #########:  5
012345678                                           . 012345678
0                                                   . 0        
queue count: 5                                      . queue count: 5
NN ROW COL                                          . NN ROW COL
 0   4   6                                          .  0   4   6
 1   1   7                                          .  1   1   7
 2   2   1                                          .  2   2   1
 3   3   2                                          .  3   3   2
 4   4   1                                          .  4   4   1
LOG: BFS STEP 14                                    . LOG: BFS STEP 14
LOG: processing neighbors of (4,6)                  . LOG: processing neighbors of (4,6)
LOG: Found tile at (4,7) with len 5 path: SSEEE     . LOG: Found tile at (4,7) with len 5 path: SSEEE
LOG: maze state after BFS step                      . LOG: maze state after BFS step
#########:  0                                       . #########:  0
#4321#34#:  1                                       . #4321#34#:  1
#5##012##:  2                                       . #5##012##:  2
# 5#1##E#:  3                                       . # 5#1##E#:  3
#5432345#:  4                                       . #5432345#:  4
#########:  5                                       . #########:  5
012345678                                           . 012345678
0                                                   . 0        
queue count: 5                                      . queue count: 5
NN ROW COL                                          . NN ROW COL
 0   1   7                                          .  0   1   7
 1   2   1                                          .  1   2   1
 2   3   2                                          .  2   3   2
 3   4   1                                          .  3   4   1
 4   4   7                                          .  4   4   7
LOG: BFS STEP 15                                    . LOG: BFS STEP 15
LOG: processing neighbors of (1,7)                  . LOG: processing neighbors of (1,7)
LOG: maze state after BFS step                      . LOG: maze state after BFS step
#########:  0                                       . #########:  0
#4321#34#:  1                                       . #4321#34#:  1
#5##012##:  2                                       . #5##012##:  2
# 5#1##E#:  3                                       . # 5#1##E#:  3
#5432345#:  4                                       . #5432345#:  4
#########:  5                                       . #########:  5
012345678                                           . 012345678
0                                                   . 0        
queue count: 4                                      . queue count: 4
NN ROW COL                                          . NN ROW COL
 0   2   1                                          .  0   2   1
 1   3   2                                          .  1   3   2
 2   4   1                                          .  2   4   1
 3   4   7                                          .  3   4   7
LOG: BFS STEP 16                                    . LOG: BFS STEP 16
LOG: processing neighbors of (2,1)                  . LOG: processing neighbors of (2,1)
LOG: Found tile at (3,1) with len 6 path: NWWWSS    . LOG: Found tile at (3,1) with len 6 path: NWWWSS
LOG: maze state after BFS step                      . LOG: maze state after BFS step
#########:  0                                       . #########:  0
#4321#34#:  1                                       . #4321#34#:  1
#5##012##:  2                                       . #5##012##:  2
#65#1##E#:  3                                       . #65#1##E#:  3
#5432345#:  4                                       . #5432345#:  4
#########:  5                                       . #########:  5
012345678                                           . 012345678
0                                                   . 0        
queue count: 4                                      . queue count: 4
NN ROW COL                                          . NN ROW COL
 0   3   2                                          .  0   3   2
 1   4   1                                          .  1   4   1
 2   4   7                                          .  2   4   7
 3   3   1                                          .  3   3   1
LOG: BFS STEP 17                                    . LOG: BFS STEP 17
LOG: processing neighbors of (3,2)                  . LOG: processing neighbors of (3,2)
LOG: maze state after BFS step                      . LOG: maze state after BFS step
#########:  0                                       . #########:  0
#4321#34#:  1                                       . #4321#34#:  1
#5##012##:  2                                       . #5##012##:  2
#65#1##E#:  3                                       . #65#1##E#:  3
#5432345#:  4                                       . #5432345#:  4
#########:  5                                       . #########:  5
012345678                                           . 012345678
0                                                   . 0        
queue count: 3                                      . queue count: 3
NN ROW COL                                          . NN ROW COL
 0   4   1                                          .  0   4   1
 1   4   7                                          .  1   4   7
 2   3   1                                          .  2   3   1
LOG: BFS STEP 18                                    . LOG: BFS STEP 18
LOG: processing neighbors of (4,1)                  . LOG: processing neighbors of (4,1)
LOG: maze state after BFS step                      . LOG: maze state after BFS step
#########:  0                                       . #########:  0
#4321#34#:  1                                       . #4321#34#:  1
#5##012##:  2                                       . #5##012##:  2
#65#1##E#:  3                                       . #65#1##E#:  3
#5432345#:  4                                       . #5432345#:  4
#########:  5                                       . #########:  5
012345678                                           . 012345678
0                                                   . 0        
queue count: 2                                      . queue count: 2
NN ROW COL                                          . NN ROW COL
 0   4   7                                          .  0   4   7
 1   3   1                                          .  1   3   1
LOG: BFS STEP 19                                    . LOG: BFS STEP 19
LOG: processing neighbors of (4,7)                  . LOG: processing neighbors of (4,7)
LOG: Found tile at (3,7) with len 6 path: SSEEEN    . LOG: Found tile at (3,7) with len 6 path: SSEEEN
LOG: maze state after BFS step                      . LOG: maze state after BFS step
#########:  0                                       . #########:  0
#4321#34#:  1                                       . #4321#34#:  1
#5##012##:  2                                       . #5##012##:  2
#65#1##6#:  3                                       . #65#1##6#:  3
#5432345#:  4                                       . #5432345#:  4
#########:  5                                       . #########:  5
012345678                                           . 012345678
0                                                   . 0        
queue count: 2                                      . queue count: 2
NN ROW COL                                          . NN ROW COL
 0   3   1                                          .  0   3   1
 1   3   7                                          .  1   3   7
LOG: BFS STEP 20                                    . LOG: BFS STEP 20
LOG: processing neighbors of (3,1)                  . LOG: processing neighbors of (3,1)
LOG: maze state after BFS step                      . LOG: maze state after BFS step
#########:  0                                       . #########:  0
#4321#34#:  1                                       . #4321#34#:  1
#5##012##:  2                                       . #5##012##:  2
#65#1##6#:  3                                       . #65#1##6#:  3
#5432345#:  4                                       . #5432345#:  4
#########:  5                                       . #########:  5
012345678                                           . 012345678
0                                                   . 0        
queue count: 1                                      . queue count: 1
NN ROW COL                                          . NN ROW COL
 0   3   7                                          .  0   3   7
LOG: BFS STEP 21                                    . LOG: BFS STEP 21
LOG: processing neighbors of (3,7)                  . LOG: processing neighbors of (3,7)
LOG: maze state after BFS step                      . LOG: maze state after BFS step
#########:  0                                       . #########:  0
#4321#34#:  1                                       . #4321#34#:  1
#5##012##:  2                                       . #5##012##:  2
#65#1##6#:  3                                       . #65#1##6#:  3
#5432345#:  4                                       . #5432345#:  4
#########:  5                                       . #########:  5
012345678                                           . 012345678
0                                                   . 0        
queue count: 0                                      . queue count: 0
NN ROW COL                                          . NN ROW COL
LOG: solution START at (2,4)                        . LOG: solution START at (2,4)
LOG: solution path[0] is SOUTH, set (3,4) to ONPATH . LOG: solution path[0] is SOUTH, set (3,4) to ONPATH
LOG: solution path[1] is SOUTH, set (4,4) to ONPATH . LOG: solution path[1] is SOUTH, set (4,4) to ONPATH
LOG: solution path[2] is EAST, set (4,5) to ONPATH  . LOG: solution path[2] is EAST, set (4,5) to ONPATH
LOG: solution path[3] is EAST, set (4,6) to ONPATH  . LOG: solution path[3] is EAST, set (4,6) to ONPATH
LOG: solution path[4] is EAST, set (4,7) to ONPATH  . LOG: solution path[4] is EAST, set (4,7) to ONPATH
LOG: solution path[5] is NORTH, set (3,7) to ONPATH . LOG: solution path[5] is NORTH, set (3,7) to ONPATH
LOG: solution END at (3,7)                          . LOG: solution END at (3,7)
                                                    ) 
SOLUTION:                                           . SOLUTION:
maze: 6 rows 9 cols                                 . maze: 6 rows 9 cols
      (2,4) start                                   .       (2,4) start
      (3,7) end                                     .       (3,7) end
maze tiles:                                         . maze tiles:
#########                                           . #########
#    #  #                                           . #    #  #
# ##S  ##                                           . # ##S  ##
#  #.##E#                                           . #  #.##E#
#   ....#                                           . #   ....#
#########                                           . #########
                                                    ) 
path length: 6                                      . path length: 6
 0: SOUTH                                           .  0: SOUTH
 1: SOUTH                                           .  1: SOUTH
 2: EAST                                            .  2: EAST
 3: EAST                                            .  3: EAST
 4: EAST                                            .  4: EAST
 5: NORTH                                           .  5: NORTH

```

LINE-BY-LINE DIFF of Expected vs Actual
---------------------------------------
No differences found

VALGRIND REPORT
---------------
The program is run on under valgrind as
  stdbuf -i 0 -o 0 -e 0 valgrind --error-exitcode=13 --leak-check=full --show-leak-kinds=all --track-origins=yes ./mazesolve_main -log 4 data/maze-small-threepath1.txt
which may be pasted onto a command line to run it.

```
==15608== Memcheck, a memory error detector
==15608== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==15608== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==15608== Command: ./mazesolve_main -log 4 data/maze-small-threepath1.txt
==15608== 
==15608== 
==15608== HEAP SUMMARY:
==15608==     in use at exit: 0 bytes in 0 blocks
==15608==   total heap usage: 53 allocs, 53 frees, 6,592 bytes allocated
==15608== 
==15608== All heap blocks were freed -- no leaks are possible
==15608== 
==15608== For lists of detected and suppressed errors, rerun with: -s
==15608== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

SUMMARY
-------
Test Passed
