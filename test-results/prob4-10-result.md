(TEST 10) mazesolve_main5 MULTIPART : ok
========================================

COMMENTS
--------
Run on two larger mazes with minimal logging.

Test Segment 1 : ok
-------------------
** data/maze-big-single1.txt

### PROGRAM: ./mazesolve_main -log 0 data/maze-big-single1.txt
To run this individual test in GDB use the command:
gdb --args ./mazesolve_main -log 0 data/maze-big-single1.txt
but any input to the program must be typed within the debugger

### FAILURE MESSAGES
None

### SIDE-BY-SIDE DIFF of Expected vs Actual
. lines match; | lines differ; < expected line missing; > extra line in actual

```sdiff
===EXPECT===                                          ===ACTUAL===
maze: 21 rows 51 cols                               . maze: 21 rows 51 cols
      (1,1) start                                   .       (1,1) start
      (19,50) end                                   .       (19,50) end
maze tiles:                                         . maze tiles:
################################################### . ###################################################
#S  #                           #         #       # . #S  #                           #         #       #
### ########### ################# ##### # # ##### # . ### ########### ################# ##### # # ##### #
# #     #     #       #       #   #   # #   #   # # . # #     #     #       #       #   #   # #   #   # #
# ##### # ### # ##### # ##### # ### # # ##### ### # . # ##### # ### # ##### # ##### # ### # # ##### ### #
#     #   # # #     # #   # #   #   # #   #     # # . #     #   # # #     # #   # #   #   # #   #     # #
# ######### # ####### ### # ##### ### ### ### # # # . # ######### # ####### ### # ##### ### ### ### # # #
# #         # #         #         #     #   # #   # . # #         # #         #         #     #   # #   #
# # ##### ### # ##### ####### ######### ### # ##### . # # ##### ### # ##### ####### ######### ### # #####
# #   # #     # #   # #       #     #     # # #   # . # #   # #     # #   # #       #     #     # # #   #
# ### # ####### # # ### ####### ### ####### # # # # . # ### # ####### # # ### ####### ### ####### # # # #
#   #   #     #   #   # #       #           # # # # . #   #   #     #   #   # #       #           # # # #
# ##### # ### # ##### # # ################### ### # . # ##### # ### # ##### # # ################### ### #
# #     #   #   #   #   #               #   #     # . # #     #   #   #   #   #               #   #     #
# # ############# # # ##### ########### # # ##### # . # # ############# # # ##### ########### # # ##### #
# #   #           # # #   #     #     # # #     # # . # #   #           # # #   #     #     # # #     # #
# ### ### ######### # # # # ##### ### # # ##### # # . # ### ### ######### # # # # ##### ### # # ##### # #
#   #     # #     # # # # # #   # # #   # #   #   # . #   #     # #     # # # # # #   # # #   # #   #   #
# # ####### # # ### ### # ### # # # ##### # # ##### . # # ####### # # ### ### # ### # # # ##### # # #####
# #           #         #     #   #         #     E . # #           #         #     #   #         #     E
################################################### . ###################################################
                                                    ) 
                                                    ) 
SOLUTION:                                           . SOLUTION:
maze: 21 rows 51 cols                               . maze: 21 rows 51 cols
      (1,1) start                                   .       (1,1) start
      (19,50) end                                   .       (19,50) end
maze tiles:                                         . maze tiles:
################################################### . ###################################################
#S..#                           #      ...#.......# . #S..#                           #      ...#.......#
###.########### ################# #####.#.#.#####.# . ###.########### ################# #####.#.#.#####.#
# #.....#.....#       #       #   #   #.#...#   #.# . # #.....#.....#       #       #   #   #.#...#   #.#
# #####.#.###.# ##### # ##### # ### # #.##### ###.# . # #####.#.###.# ##### # ##### # ### # #.##### ###.#
#     #...# #.#     # #   # #   #   # #...#  ...#.# . #     #...# #.#     # #   # #   #   # #...#  ...#.#
# ######### #.####### ### # ##### ### ###.###.#.#.# . # ######### #.####### ### # ##### ### ###.###.#.#.#
# #.......  #.#         #         #     #...#.#...# . # #.......  #.#         #         #     #...#.#...#
# #.#####.###.# ##### ####### ######### ###.#.##### . # #.#####.###.# ##### ####### ######### ###.#.#####
# #...# #.....# #   # #       #.....#     #.#.#   # . # #...# #.....# #   # #       #.....#     #.#.#   #
# ###.# ####### # # ### #######.###.#######.#.# # # . # ###.# ####### # # ### #######.###.#######.#.# # #
#   #...#     #   #   # #.......#  .........#.# # # . #   #...#     #   #   # #.......#  .........#.# # #
# #####.# ### # ##### # #.###################.### # . # #####.# ### # ##### # #.###################.### #
# #.....#   #   #...#   #...............#...#.....# . # #.....#   #   #...#   #...............#...#.....#
# #.#############.#.# ##### ###########.#.#.#####.# . # #.#############.#.# ##### ###########.#.#.#####.#
# #...#  .........#.# #...#     #.....#.#.#.....#.# . # #...#  .........#.# #...#     #.....#.#.#.....#.#
# ###.###.#########.# #.#.# #####.###.#.#.#####.#.# . # ###.###.#########.# #.#.# #####.###.#.#.#####.#.#
#   #.....# #     #.# #.#.# #...#.# #...#.#...#...# . #   #.....# #     #.# #.#.# #...#.# #...#.#...#...#
# # ####### # # ###.###.#.###.#.#.# #####.#.#.##### . # # ####### # # ###.###.#.###.#.#.# #####.#.#.#####
# #           #    .....#.....#...#      ...#.....E . # #           #    .....#.....#...#      ...#.....E
################################################### . ###################################################
                                                    ) 
path length: 247                                    . path length: 247
 0: EAST                                            .  0: EAST
 1: EAST                                            .  1: EAST
 2: SOUTH                                           .  2: SOUTH
 3: SOUTH                                           .  3: SOUTH
 4: EAST                                            .  4: EAST
 5: EAST                                            .  5: EAST
 6: EAST                                            .  6: EAST
 7: EAST                                            .  7: EAST
 8: SOUTH                                           .  8: SOUTH
 9: SOUTH                                           .  9: SOUTH
10: EAST                                            . 10: EAST
11: EAST                                            . 11: EAST
12: NORTH                                           . 12: NORTH
13: NORTH                                           . 13: NORTH
14: EAST                                            . 14: EAST
15: EAST                                            . 15: EAST
16: EAST                                            . 16: EAST
17: EAST                                            . 17: EAST
18: SOUTH                                           . 18: SOUTH
19: SOUTH                                           . 19: SOUTH
20: SOUTH                                           . 20: SOUTH
21: SOUTH                                           . 21: SOUTH
22: SOUTH                                           . 22: SOUTH
23: SOUTH                                           . 23: SOUTH
24: WEST                                            . 24: WEST
25: WEST                                            . 25: WEST
26: WEST                                            . 26: WEST
27: WEST                                            . 27: WEST
28: NORTH                                           . 28: NORTH
29: NORTH                                           . 29: NORTH
30: WEST                                            . 30: WEST
31: WEST                                            . 31: WEST
32: WEST                                            . 32: WEST
33: WEST                                            . 33: WEST
34: WEST                                            . 34: WEST
35: WEST                                            . 35: WEST
36: SOUTH                                           . 36: SOUTH
37: SOUTH                                           . 37: SOUTH
38: EAST                                            . 38: EAST
39: EAST                                            . 39: EAST
40: SOUTH                                           . 40: SOUTH
41: SOUTH                                           . 41: SOUTH
42: EAST                                            . 42: EAST
43: EAST                                            . 43: EAST
44: SOUTH                                           . 44: SOUTH
45: SOUTH                                           . 45: SOUTH
46: WEST                                            . 46: WEST
47: WEST                                            . 47: WEST
48: WEST                                            . 48: WEST
49: WEST                                            . 49: WEST
50: SOUTH                                           . 50: SOUTH
51: SOUTH                                           . 51: SOUTH
52: EAST                                            . 52: EAST
53: EAST                                            . 53: EAST
54: SOUTH                                           . 54: SOUTH
55: SOUTH                                           . 55: SOUTH
56: EAST                                            . 56: EAST
57: EAST                                            . 57: EAST
58: EAST                                            . 58: EAST
59: EAST                                            . 59: EAST
60: NORTH                                           . 60: NORTH
61: NORTH                                           . 61: NORTH
62: EAST                                            . 62: EAST
63: EAST                                            . 63: EAST
64: EAST                                            . 64: EAST
65: EAST                                            . 65: EAST
66: EAST                                            . 66: EAST
67: EAST                                            . 67: EAST
68: EAST                                            . 68: EAST
69: EAST                                            . 69: EAST
70: NORTH                                           . 70: NORTH
71: NORTH                                           . 71: NORTH
72: EAST                                            . 72: EAST
73: EAST                                            . 73: EAST
74: SOUTH                                           . 74: SOUTH
75: SOUTH                                           . 75: SOUTH
76: SOUTH                                           . 76: SOUTH
77: SOUTH                                           . 77: SOUTH
78: SOUTH                                           . 78: SOUTH
79: SOUTH                                           . 79: SOUTH
80: EAST                                            . 80: EAST
81: EAST                                            . 81: EAST
82: EAST                                            . 82: EAST
83: EAST                                            . 83: EAST
84: NORTH                                           . 84: NORTH
85: NORTH                                           . 85: NORTH
86: NORTH                                           . 86: NORTH
87: NORTH                                           . 87: NORTH
88: EAST                                            . 88: EAST
89: EAST                                            . 89: EAST
90: SOUTH                                           . 90: SOUTH
91: SOUTH                                           . 91: SOUTH
92: SOUTH                                           . 92: SOUTH
93: SOUTH                                           . 93: SOUTH
94: EAST                                            . 94: EAST
95: EAST                                            . 95: EAST
96: EAST                                            . 96: EAST
97: EAST                                            . 97: EAST
98: NORTH                                           . 98: NORTH
99: NORTH                                           . 99: NORTH
100: EAST                                           . 100: EAST
101: EAST                                           . 101: EAST
102: SOUTH                                          . 102: SOUTH
103: SOUTH                                          . 103: SOUTH
104: EAST                                           . 104: EAST
105: EAST                                           . 105: EAST
106: NORTH                                          . 106: NORTH
107: NORTH                                          . 107: NORTH
108: NORTH                                          . 108: NORTH
109: NORTH                                          . 109: NORTH
110: EAST                                           . 110: EAST
111: EAST                                           . 111: EAST
112: EAST                                           . 112: EAST
113: EAST                                           . 113: EAST
114: SOUTH                                          . 114: SOUTH
115: SOUTH                                          . 115: SOUTH
116: EAST                                           . 116: EAST
117: EAST                                           . 117: EAST
118: NORTH                                          . 118: NORTH
119: NORTH                                          . 119: NORTH
120: NORTH                                          . 120: NORTH
121: NORTH                                          . 121: NORTH
122: WEST                                           . 122: WEST
123: WEST                                           . 123: WEST
124: WEST                                           . 124: WEST
125: WEST                                           . 125: WEST
126: WEST                                           . 126: WEST
127: WEST                                           . 127: WEST
128: WEST                                           . 128: WEST
129: WEST                                           . 129: WEST
130: WEST                                           . 130: WEST
131: WEST                                           . 131: WEST
132: WEST                                           . 132: WEST
133: WEST                                           . 133: WEST
134: WEST                                           . 134: WEST
135: WEST                                           . 135: WEST
136: NORTH                                          . 136: NORTH
137: NORTH                                          . 137: NORTH
138: EAST                                           . 138: EAST
139: EAST                                           . 139: EAST
140: EAST                                           . 140: EAST
141: EAST                                           . 141: EAST
142: EAST                                           . 142: EAST
143: EAST                                           . 143: EAST
144: NORTH                                          . 144: NORTH
145: NORTH                                          . 145: NORTH
146: EAST                                           . 146: EAST
147: EAST                                           . 147: EAST
148: EAST                                           . 148: EAST
149: EAST                                           . 149: EAST
150: SOUTH                                          . 150: SOUTH
151: SOUTH                                          . 151: SOUTH
152: EAST                                           . 152: EAST
153: EAST                                           . 153: EAST
154: EAST                                           . 154: EAST
155: EAST                                           . 155: EAST
156: EAST                                           . 156: EAST
157: EAST                                           . 157: EAST
158: EAST                                           . 158: EAST
159: EAST                                           . 159: EAST
160: NORTH                                          . 160: NORTH
161: NORTH                                          . 161: NORTH
162: NORTH                                          . 162: NORTH
163: NORTH                                          . 163: NORTH
164: WEST                                           . 164: WEST
165: WEST                                           . 165: WEST
166: NORTH                                          . 166: NORTH
167: NORTH                                          . 167: NORTH
168: WEST                                           . 168: WEST
169: WEST                                           . 169: WEST
170: NORTH                                          . 170: NORTH
171: NORTH                                          . 171: NORTH
172: NORTH                                          . 172: NORTH
173: NORTH                                          . 173: NORTH
174: EAST                                           . 174: EAST
175: EAST                                           . 175: EAST
176: SOUTH                                          . 176: SOUTH
177: SOUTH                                          . 177: SOUTH
178: EAST                                           . 178: EAST
179: EAST                                           . 179: EAST
180: NORTH                                          . 180: NORTH
181: NORTH                                          . 181: NORTH
182: EAST                                           . 182: EAST
183: EAST                                           . 183: EAST
184: EAST                                           . 184: EAST
185: EAST                                           . 185: EAST
186: EAST                                           . 186: EAST
187: EAST                                           . 187: EAST
188: SOUTH                                          . 188: SOUTH
189: SOUTH                                          . 189: SOUTH
190: SOUTH                                          . 190: SOUTH
191: SOUTH                                          . 191: SOUTH
192: SOUTH                                          . 192: SOUTH
193: SOUTH                                          . 193: SOUTH
194: WEST                                           . 194: WEST
195: WEST                                           . 195: WEST
196: NORTH                                          . 196: NORTH
197: NORTH                                          . 197: NORTH
198: WEST                                           . 198: WEST
199: WEST                                           . 199: WEST
200: SOUTH                                          . 200: SOUTH
201: SOUTH                                          . 201: SOUTH
202: SOUTH                                          . 202: SOUTH
203: SOUTH                                          . 203: SOUTH
204: SOUTH                                          . 204: SOUTH
205: SOUTH                                          . 205: SOUTH
206: SOUTH                                          . 206: SOUTH
207: SOUTH                                          . 207: SOUTH
208: EAST                                           . 208: EAST
209: EAST                                           . 209: EAST
210: EAST                                           . 210: EAST
211: EAST                                           . 211: EAST
212: SOUTH                                          . 212: SOUTH
213: SOUTH                                          . 213: SOUTH
214: SOUTH                                          . 214: SOUTH
215: SOUTH                                          . 215: SOUTH
216: WEST                                           . 216: WEST
217: WEST                                           . 217: WEST
218: NORTH                                          . 218: NORTH
219: NORTH                                          . 219: NORTH
220: WEST                                           . 220: WEST
221: WEST                                           . 221: WEST
222: WEST                                           . 222: WEST
223: WEST                                           . 223: WEST
224: NORTH                                          . 224: NORTH
225: NORTH                                          . 225: NORTH
226: WEST                                           . 226: WEST
227: WEST                                           . 227: WEST
228: SOUTH                                          . 228: SOUTH
229: SOUTH                                          . 229: SOUTH
230: SOUTH                                          . 230: SOUTH
231: SOUTH                                          . 231: SOUTH
232: SOUTH                                          . 232: SOUTH
233: SOUTH                                          . 233: SOUTH
234: EAST                                           . 234: EAST
235: EAST                                           . 235: EAST
236: NORTH                                          . 236: NORTH
237: NORTH                                          . 237: NORTH
238: EAST                                           . 238: EAST
239: EAST                                           . 239: EAST
240: SOUTH                                          . 240: SOUTH
241: SOUTH                                          . 241: SOUTH
242: EAST                                           . 242: EAST
243: EAST                                           . 243: EAST
244: EAST                                           . 244: EAST
245: EAST                                           . 245: EAST
246: EAST                                           . 246: EAST

```

### LINE-BY-LINE DIFF of Expected vs Actual
No differences found

### VALGRIND REPORT
The program is run on under valgrind as
stdbuf -i 0 -o 0 -e 0 valgrind --error-exitcode=13 --leak-check=full --show-leak-kinds=all --track-origins=yes ./mazesolve_main -log 0 data/maze-big-single1.txt
which may be pasted onto a command line to run it.

```
==15622== Memcheck, a memory error detector
==15622== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==15622== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==15622== Command: ./mazesolve_main -log 0 data/maze-big-single1.txt
==15622== 
==15622== 
==15622== HEAP SUMMARY:
==15622==     in use at exit: 0 bytes in 0 blocks
==15622==   total heap usage: 1,026 allocs, 1,026 frees, 354,868 bytes allocated
==15622== 
==15622== All heap blocks were freed -- no leaks are possible
==15622== 
==15622== For lists of detected and suppressed errors, rerun with: -s
==15622== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

Test Segment 2 : ok
-------------------
** data/maze-big-mult1.txt

### PROGRAM: ./mazesolve_main -log 0 data/maze-big-mult1.txt
To run this individual test in GDB use the command:
gdb --args ./mazesolve_main -log 0 data/maze-big-mult1.txt
but any input to the program must be typed within the debugger

### FAILURE MESSAGES
None

### SIDE-BY-SIDE DIFF of Expected vs Actual
. lines match; | lines differ; < expected line missing; > extra line in actual

```sdiff
===EXPECT===                                          ===ACTUAL===
maze: 21 rows 51 cols                               . maze: 21 rows 51 cols
      (1,1) start                                   .       (1,1) start
      (19,50) end                                   .       (19,50) end
maze tiles:                                         . maze tiles:
################################################### . ###################################################
#S  #                                     #       # . #S  #                                     #       #
### ########### ################# ##### # # ##### # . ### ########### ################# ##### # # ##### #
# #     #     #       #       #   #   # #   #   # # . # #     #     #       #       #   #   # #   #   # #
# ##### # ### # ##### # ##### # ### # # ##### ### # . # ##### # ### # ##### # ##### # ### # # ##### ### #
#     #   # # #     # #   # #   #   # #   #     # # . #     #   # # #     # #   # #   #   # #   #     # #
# ######### # ####### ### # ##### ### ### ### # # # . # ######### # ####### ### # ##### ### ### ### # # #
# #         # #                         #   # #   # . # #         # #                         #   # #   #
# # ##### ### # ##### ####### ######### ### # ##### . # # ##### ### # ##### ####### ######### ### # #####
# #   # #     # #   # #       #     #     # # #   # . # #   # #     # #   # #       #     #     # # #   #
# ### # ####### # # ### ####### ### ####### # # # # . # ### # ####### # # ### ####### ### ####### # # # #
#   #   #     #   #   # #       #           # # # # . #   #   #     #   #   # #       #           # # # #
# ##### # ### # ##### # # ######### ######### ### # . # ##### # ### # ##### # # ######### ######### ### #
#       #   #   #   #   #               #   #     # . #       #   #   #   #   #               #   #     #
# # ##########  # # # ##### ########### # # ##### # . # # ##########  # # # ##### ########### # # ##### #
# #   #           # # #   #     #     # # #     # # . # #   #           # # #   #     #     # # #     # #
# ### ### ######### # # # # ##### ### # # ##### # # . # ### ### ######### # # # # ##### ### # # ##### # #
#   #     # #     # # # # # #   # # #   # #   #   # . #   #     # #     # # # # # #   # # #   # #   #   #
# # ####### # # ### ### # ### # # # ##### # # ##### . # # ####### # # ### ### # ### # # # ##### # # #####
# #           #         #     #   #         #     E . # #           #         #     #   #         #     E
################################################### . ###################################################
                                                    ) 
                                                    ) 
SOLUTION:                                           . SOLUTION:
maze: 21 rows 51 cols                               . maze: 21 rows 51 cols
      (1,1) start                                   .       (1,1) start
      (19,50) end                                   .       (19,50) end
maze tiles:                                         . maze tiles:
################################################### . ###################################################
#S..#                            .........#.......# . #S..#                            .........#.......#
###.########### #################.##### #.#.#####.# . ###.########### #################.##### #.#.#####.#
# #.....#.....#       #.......#...#   # #...#   #.# . # #.....#.....#       #.......#...#   # #...#   #.#
# #####.#.###.# ##### #.#####.#.### # # ##### ###.# . # #####.#.###.# ##### #.#####.#.### # # ##### ###.#
#     #...# #.#     # #...# #...#   # #   #  ...#.# . #     #...# #.#     # #...# #...#   # #   #  ...#.#
# ######### #.####### ###.# ##### ### ### ###.#.#.# . # ######### #.####### ###.# ##### ### ### ###.#.#.#
# #.......  #.#...........              #   #.#...# . # #.......  #.#...........              #   #.#...#
# #.#####.###.#.##### ####### ######### ### #.##### . # #.#####.###.#.##### ####### ######### ### #.#####
# #...# #.....#.#   # #       #     #     # #.#   # . # #...# #.....#.#   # #       #     #     # #.#   #
# ###.# #######.# # ### ####### ### ####### #.# # # . # ###.# #######.# # ### ####### ### ####### #.# # #
#   #...#     #.  #   # #       #           #.# # # . #   #...#     #.  #   # #       #           #.# # #
# #####.# ### #.##### # # ######### #########.### # . # #####.# ### #.##### # # ######### #########.### #
#  .....#   # ..#   #   #               #...#.....# . #  .....#   # ..#   #   #               #...#.....#
# #.##########. # # # ##### ########### #.#.#####.# . # #.##########. # # # ##### ########### #.#.#####.#
# #...#  ......   # # #   #     #     # #.#.....#.# . # #...#  ......   # # #   #     #     # #.#.....#.#
# ###.###.######### # # # # ##### ### # #.#####.#.# . # ###.###.######### # # # # ##### ### # #.#####.#.#
#   #.....# #     # # # # # #   # # #   #.#...#...# . #   #.....# #     # # # # # #   # # #   #.#...#...#
# # ####### # # ### ### # ### # # # #####.#.#.##### . # # ####### # # ### ### # ### # # # #####.#.#.#####
# #           #         #     #   #      ...#.....E . # #           #         #     #   #      ...#.....E
################################################### . ###################################################
                                                    ) 
path length: 187                                    . path length: 187
 0: EAST                                            .  0: EAST
 1: EAST                                            .  1: EAST
 2: SOUTH                                           .  2: SOUTH
 3: SOUTH                                           .  3: SOUTH
 4: EAST                                            .  4: EAST
 5: EAST                                            .  5: EAST
 6: EAST                                            .  6: EAST
 7: EAST                                            .  7: EAST
 8: SOUTH                                           .  8: SOUTH
 9: SOUTH                                           .  9: SOUTH
10: EAST                                            . 10: EAST
11: EAST                                            . 11: EAST
12: NORTH                                           . 12: NORTH
13: NORTH                                           . 13: NORTH
14: EAST                                            . 14: EAST
15: EAST                                            . 15: EAST
16: EAST                                            . 16: EAST
17: EAST                                            . 17: EAST
18: SOUTH                                           . 18: SOUTH
19: SOUTH                                           . 19: SOUTH
20: SOUTH                                           . 20: SOUTH
21: SOUTH                                           . 21: SOUTH
22: SOUTH                                           . 22: SOUTH
23: SOUTH                                           . 23: SOUTH
24: WEST                                            . 24: WEST
25: WEST                                            . 25: WEST
26: WEST                                            . 26: WEST
27: WEST                                            . 27: WEST
28: NORTH                                           . 28: NORTH
29: NORTH                                           . 29: NORTH
30: WEST                                            . 30: WEST
31: WEST                                            . 31: WEST
32: WEST                                            . 32: WEST
33: WEST                                            . 33: WEST
34: WEST                                            . 34: WEST
35: WEST                                            . 35: WEST
36: SOUTH                                           . 36: SOUTH
37: SOUTH                                           . 37: SOUTH
38: EAST                                            . 38: EAST
39: EAST                                            . 39: EAST
40: SOUTH                                           . 40: SOUTH
41: SOUTH                                           . 41: SOUTH
42: EAST                                            . 42: EAST
43: EAST                                            . 43: EAST
44: SOUTH                                           . 44: SOUTH
45: SOUTH                                           . 45: SOUTH
46: WEST                                            . 46: WEST
47: WEST                                            . 47: WEST
48: WEST                                            . 48: WEST
49: WEST                                            . 49: WEST
50: SOUTH                                           . 50: SOUTH
51: SOUTH                                           . 51: SOUTH
52: EAST                                            . 52: EAST
53: EAST                                            . 53: EAST
54: SOUTH                                           . 54: SOUTH
55: SOUTH                                           . 55: SOUTH
56: EAST                                            . 56: EAST
57: EAST                                            . 57: EAST
58: EAST                                            . 58: EAST
59: EAST                                            . 59: EAST
60: NORTH                                           . 60: NORTH
61: NORTH                                           . 61: NORTH
62: EAST                                            . 62: EAST
63: EAST                                            . 63: EAST
64: EAST                                            . 64: EAST
65: EAST                                            . 65: EAST
66: EAST                                            . 66: EAST
67: NORTH                                           . 67: NORTH
68: NORTH                                           . 68: NORTH
69: EAST                                            . 69: EAST
70: NORTH                                           . 70: NORTH
71: NORTH                                           . 71: NORTH
72: NORTH                                           . 72: NORTH
73: NORTH                                           . 73: NORTH
74: NORTH                                           . 74: NORTH
75: NORTH                                           . 75: NORTH
76: EAST                                            . 76: EAST
77: EAST                                            . 77: EAST
78: EAST                                            . 78: EAST
79: EAST                                            . 79: EAST
80: EAST                                            . 80: EAST
81: EAST                                            . 81: EAST
82: EAST                                            . 82: EAST
83: EAST                                            . 83: EAST
84: EAST                                            . 84: EAST
85: EAST                                            . 85: EAST
86: NORTH                                           . 86: NORTH
87: NORTH                                           . 87: NORTH
88: WEST                                            . 88: WEST
89: WEST                                            . 89: WEST
90: NORTH                                           . 90: NORTH
91: NORTH                                           . 91: NORTH
92: EAST                                            . 92: EAST
93: EAST                                            . 93: EAST
94: EAST                                            . 94: EAST
95: EAST                                            . 95: EAST
96: EAST                                            . 96: EAST
97: EAST                                            . 97: EAST
98: SOUTH                                           . 98: SOUTH
99: SOUTH                                           . 99: SOUTH
100: EAST                                           . 100: EAST
101: EAST                                           . 101: EAST
102: NORTH                                          . 102: NORTH
103: NORTH                                          . 103: NORTH
104: EAST                                           . 104: EAST
105: EAST                                           . 105: EAST
106: NORTH                                          . 106: NORTH
107: NORTH                                          . 107: NORTH
108: EAST                                           . 108: EAST
109: EAST                                           . 109: EAST
110: EAST                                           . 110: EAST
111: EAST                                           . 111: EAST
112: EAST                                           . 112: EAST
113: EAST                                           . 113: EAST
114: EAST                                           . 114: EAST
115: EAST                                           . 115: EAST
116: SOUTH                                          . 116: SOUTH
117: SOUTH                                          . 117: SOUTH
118: EAST                                           . 118: EAST
119: EAST                                           . 119: EAST
120: NORTH                                          . 120: NORTH
121: NORTH                                          . 121: NORTH
122: EAST                                           . 122: EAST
123: EAST                                           . 123: EAST
124: EAST                                           . 124: EAST
125: EAST                                           . 125: EAST
126: EAST                                           . 126: EAST
127: EAST                                           . 127: EAST
128: SOUTH                                          . 128: SOUTH
129: SOUTH                                          . 129: SOUTH
130: SOUTH                                          . 130: SOUTH
131: SOUTH                                          . 131: SOUTH
132: SOUTH                                          . 132: SOUTH
133: SOUTH                                          . 133: SOUTH
134: WEST                                           . 134: WEST
135: WEST                                           . 135: WEST
136: NORTH                                          . 136: NORTH
137: NORTH                                          . 137: NORTH
138: WEST                                           . 138: WEST
139: WEST                                           . 139: WEST
140: SOUTH                                          . 140: SOUTH
141: SOUTH                                          . 141: SOUTH
142: SOUTH                                          . 142: SOUTH
143: SOUTH                                          . 143: SOUTH
144: SOUTH                                          . 144: SOUTH
145: SOUTH                                          . 145: SOUTH
146: SOUTH                                          . 146: SOUTH
147: SOUTH                                          . 147: SOUTH
148: EAST                                           . 148: EAST
149: EAST                                           . 149: EAST
150: EAST                                           . 150: EAST
151: EAST                                           . 151: EAST
152: SOUTH                                          . 152: SOUTH
153: SOUTH                                          . 153: SOUTH
154: SOUTH                                          . 154: SOUTH
155: SOUTH                                          . 155: SOUTH
156: WEST                                           . 156: WEST
157: WEST                                           . 157: WEST
158: NORTH                                          . 158: NORTH
159: NORTH                                          . 159: NORTH
160: WEST                                           . 160: WEST
161: WEST                                           . 161: WEST
162: WEST                                           . 162: WEST
163: WEST                                           . 163: WEST
164: NORTH                                          . 164: NORTH
165: NORTH                                          . 165: NORTH
166: WEST                                           . 166: WEST
167: WEST                                           . 167: WEST
168: SOUTH                                          . 168: SOUTH
169: SOUTH                                          . 169: SOUTH
170: SOUTH                                          . 170: SOUTH
171: SOUTH                                          . 171: SOUTH
172: SOUTH                                          . 172: SOUTH
173: SOUTH                                          . 173: SOUTH
174: EAST                                           . 174: EAST
175: EAST                                           . 175: EAST
176: NORTH                                          . 176: NORTH
177: NORTH                                          . 177: NORTH
178: EAST                                           . 178: EAST
179: EAST                                           . 179: EAST
180: SOUTH                                          . 180: SOUTH
181: SOUTH                                          . 181: SOUTH
182: EAST                                           . 182: EAST
183: EAST                                           . 183: EAST
184: EAST                                           . 184: EAST
185: EAST                                           . 185: EAST
186: EAST                                           . 186: EAST

```

### LINE-BY-LINE DIFF of Expected vs Actual
No differences found

### VALGRIND REPORT
The program is run on under valgrind as
stdbuf -i 0 -o 0 -e 0 valgrind --error-exitcode=13 --leak-check=full --show-leak-kinds=all --track-origins=yes ./mazesolve_main -log 0 data/maze-big-mult1.txt
which may be pasted onto a command line to run it.

```
==15634== Memcheck, a memory error detector
==15634== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==15634== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==15634== Command: ./mazesolve_main -log 0 data/maze-big-mult1.txt
==15634== 
==15634== 
==15634== HEAP SUMMARY:
==15634==     in use at exit: 0 bytes in 0 blocks
==15634==   total heap usage: 1,040 allocs, 1,040 frees, 234,900 bytes allocated
==15634== 
==15634== All heap blocks were freed -- no leaks are possible
==15634== 
==15634== For lists of detected and suppressed errors, rerun with: -s
==15634== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

### SUMMARY
Test Passed
