#include "mazesolve.h"

////////////////////////////////////////////////////////////////////////////////
// PROVIDED DATA
//
// The data below should not be altered as it should be used as-is in functions
///////////////////////////////////////////////////////////////////////////////

// Global variable controlling how much info should be printed; it is
// assigned values like LOG_ALL (defined in the header as 10) to
// trigger additional output to be printed during certain
// functions. This output is useful to monitor and audit how program
// execution proceeds.
int LOG_LEVEL = 0;

// Pre-specified order in which neighbor tiles shoudl be checked for
// compatibility with tests.
direction_t dir_delta[5] = {NONE, NORTH, SOUTH, WEST, EAST};
int row_delta[5] =         {+0,      -1,    +1,   +0,   +0};
int col_delta[5] =         {+0,      +0,    +0,   -1,   +1};
#define DELTA_START 1
#define DELTA_COUNT 5


// strings to print for compact directions
char *direction_compact_strs[5] = {
  "?",                          // NONE
  "N",                          // NORTH
  "S",                          // SOUTH
  "W",                          // WEST
  "E",                          // EAST
};
  
// strings to print for verbose directions
char *direction_verbose_strs[5] = {
  "NONE",                       // NONE
  "NORTH",                      // NORTH
  "SOUTH",                      // SOUTH
  "WEST",                       // WEST
  "EAST",                       // EAST
};

#define TILETYPE_COUNT 6

// strings to print for each tile type
char tiletype_chars[TILETYPE_COUNT] = {
  '?',                          // NOTSET = 0,
  '#',                          // WALL,
  ' ',                          // OPEN,
  '.',                          // ONPATH,
  'S',                          // START,
  'E',                          // END,
};

// characters to print in the visual rendering of the BFS in the maze
// when the distance is evently divisible by 10: a is 10, b is 20, c
// is 30, etc.
char digit10_chars[] = "0abcdefghijklmnopqrstuvwxyzABCDE%GHIJKLMNOPQR$TUVWXYZ";

////////////////////////////////////////////////////////////////////////////////
// FUNCTIONS FOR PROBLEM 1: Row/Col Queue
////////////////////////////////////////////////////////////////////////////////

rcqueue_t *rcqueue_allocate(){
    rcqueue_t *queue = malloc(sizeof(rcqueue_t));
    if (queue) {
        queue->front = NULL;
        queue->rear = NULL;
        queue->count = 0;
    }
    return queue;
}
// PROBLEM 1: Create a new queue of row/col coordinates that is
// empty. Heap-allocate the queue and return a pointer to
// it. Initialize all fields of the queue struct to indicate its
// emptiness. 
//
// CONSTRAINTS: When allocating heap memory, assume calls to malloc()
// succeed and avoid checks to determine if memory allocation failed.

void rcqueue_add_rear(rcqueue_t *queue, int row, int col){
    rcnode_t *new_node = malloc(sizeof(rcnode_t));
    if (new_node) {
        new_node->row = row;
        new_node->col = col;
        new_node->next = NULL;
        
        if (queue->count == 0) {
            queue->front = new_node;
            queue->rear = new_node;
        } else {
            queue->rear->next = new_node;
            queue->rear = new_node;
        }
        queue->count++;
    }
}
// PROBLEM 1: Add the given row/col coordinates at the end of the
// queue.  Allocates a new node for the coordinates and links this in
// at the end of the queue.
//
// NOTES: The first addition to an empty queue usually requires
// special handling that is different from than subsequent
// additions. Make sure to check for this case. If you see
// Segmentation Faults when running tests, examine the line numbers
// closely, check what the test was evaluating, and trace the
// execution mentally or via debug printing to find the problem.

void rcqueue_free(rcqueue_t *queue){
    if (!queue) return;
    
    while (queue->front) {
        rcnode_t *temp = queue->front;
        queue->front = queue->front->next;
        free(temp);
    }
    free(queue);
}
// PROBLEM 1: De-allocate the memory associated with `queue`. If it is
// non-empty, remove all elements from it de-allocating their nodes
// before free()'ing the queue struct itself.

int rcqueue_get_front(rcqueue_t *queue, int *rowp, int *colp){
    if (!queue || !queue->front) {
        return 0;
    }
    *rowp = queue->front->row;
    *colp = queue->front->col;
    return 1;
}
// PROBLEM 1: Retrieve the front element of the queue but do not
// otherwise change the queue.  If the queue is empty, immediately
// returns 0.  Otherwise, the pointers rowp and colp are dereferenced
// and set to be the row/col in the front node in the queue and 1 is
// returned to indicate that the rowp/colp have been set.

int rcqueue_remove_front(rcqueue_t *queue){
    if (!queue || !queue->front) {
        return 0;
    }
    
    rcnode_t *temp = queue->front;
    queue->front = queue->front->next;
    queue->count--;
    
    if (queue->count == 0) {
        queue->rear = NULL;
    }
    
    free(temp);
    return 1;    
}
// PROBLEM 1: Removes the front node of the queue. If the queue is
// empty, immediately returns 0 to indicate the queue is
// unchanged. Otherwise, advances the front pointer of the queue to
// the next node in the queue and the de-allocates the node which was
// previously at the front. Adjusts the count of nodes in the
// queue. Returns 1 to indicate the queue has changed.
//
// CONSTRAINT: This should be a constant time O(1) operation.
// CONSTRAINT: When the queue is empty, BOTH front/rear should be NULL.

void rcqueue_print(rcqueue_t *queue){
    int node__Count = 0;
    rcnode_t *current = queue->front;

    if(queue == NULL){
        printf("null queue\n");
        return;
    }

    printf("queue count: %d\n", queue->count);
    printf("NN ROW COL\n");
    while(current != NULL){
        printf("%2d %3d %3d\n", node__Count, current->row, current->col);
        current = current->next;
        node__Count++;
    }
    return;
}
// PROBLEM 1: Prints a table of the current queue contents to standard
// out using printf(). The output should look like the following.
//
// queue count: 3
// NN ROW COL
//  0   4   5
//  1   1   8
//  2   5   5
// 
// The first line is the plain text "queue count: " followed by the
// count of nodes in the queue. The next line is a header with 
// Node Number (NN), Row, and Col for columns with remaining lines
// showing data for each node. Each line of this output is printed
// with numbers right-aligned with a field width of 2 characters for
// node numbers and 3 characters for row/col coordinates.
//
// If `queue` is NULL, print the string "null queue\n" instead.
//
// NOTES: Research the capabilities of printf() to print data in a
// specific field width. A usage like printf("%3d",number) will be
// useful in a situation like this to line up table entries.

////////////////////////////////////////////////////////////////////////////////
// FUNCTIONS FOR PROBLEM 2: Tile and Maze Utility Functions
////////////////////////////////////////////////////////////////////////////////

void tile_print_path(tile_t *tile, int format){
    
    if(tile->path == NULL){
        printf("No path found\n");
    }
    else{
        if(format == PATH_FORMAT_COMPACT){
            for(int i = 0; i < tile->path_len; i++){
                printf("%s", direction_compact_strs[tile->path[i]]);
            }
        }
        else if(format == PATH_FORMAT_VERBOSE){
            printf("path length: %d\n", tile->path_len);
            for(int i = 0; i < tile->path_len; i++){
                printf("%3d: %s\n", i, direction_verbose_strs[tile->path[i]]);
            }
        }
        else{
            printf("Invalid format\n");
        }
    }
    return;
}
// PROBLEM 2: Print the path field of `tile` in one of two formats. If
// the path field is NULL, print "No path found\n". Otherwise, if the
// `format` parameter is PATH_FORMAT_COMPACT, iterate over the path
// array and print each element as a string that comes from the global
// direction_compact_strs[] array without printing any newlines. If
// the `format` parameter is PATH_FORMAT_VERBOSE, print the length of
// the path on its own line then each element of the path with its
// index on its on line using strings from teh
// direction_verbose_strs[] global array. If the format is neither of
// COMPACT or VERBOSE, print an error message (not tested).
//
// CONSTRAINT: This function must use the correspondence of
// enumeration values like NORTH to integers to access elements from
// the global arrays direction_compact_strs[] and
// direction_verbose_strs[]. Code that utilizes long-winded
// conditional cases here will lose large quantities of style points.
//
// EXAMPLE:
// tile_t src = {.path_len = 4,  .path = {NORTH, EAST, EAST, SOUTH} }; 
// tile_print_path(&tile, PATH_FORMAT_COMPACT);
// printf("\n");
//   NEES
// tile_print_path(&tile, PATH_FORMAT_VERBOSE);
//   path length: 4
//     0: NORTH
//     1: EAST
//     2: EAST
//     3: SOUTH
//
// NOTES: This function will be short, less than 30 lines.  It should
// not have conditional structures that decide between NORTH, SOUTH,
// etc. Rather, use an access pattern like the following to "look up"
// the string that is needed in a given case.
// 
//   direction_t d = path[i];
//   char *dirstr = direction_verbose_strs[d];
//   printf("%s\n",dirstr);
// 
// Or more compactly
// 
//   printf("%s\n", direction_verbose_strs[path[i]]);
// 
// Handling a multipart conditional using an array of data like this
// is an elegant technique that proficient codes seek to use as often
// as possible.

void tile_extend_path(tile_t *src, tile_t *dst, direction_t dir){
    
    dst->path_len = src->path_len + 1;
    dst->path = malloc(sizeof(direction_t) * dst->path_len);
    for(int i = 0; i < src->path_len; i++){
        dst->path[i] = src->path[i];
    }
    dst->path[src->path_len] = dir;
    return;
}
// PROBLEM 2: Fills in the path/path_len fields of `dst` based on
// arriving at it from the `src` tile via `dir`.  Heap-allocates a
// direction_t array for the path in dst that is one longer than the
// path in src. Copies all elements from the `src` path to `dst`. Adds
// `dir` as the final element of the path in `dst`. This function is
// used when a new tile is found during BFS to store the path used to
// locate it from the starting point.
// 
// EXAMPLE:
// tile_t src = {.path_len = 4,  .path = {NORTH, EAST, EAST, SOUTH} }; 
// tile_t dst = {.path_len = -1, .path = NULL };
// tile_extend_path(&src, &dst, EAST);
// dst is now   {.path_len = 5,  .path = {NORTH, EAST, EAST, SOUTH, EAST} }; 
//
// NOTES: This function will need to access fields of the
// tiles. Review syntax to do so.

maze_t *maze_allocate(int rows, int cols){
    maze_t *maze = malloc(sizeof(maze_t));
    if (!maze) return NULL;
    
    maze->rows = rows;
    maze->cols = cols;
    maze->start_row = -1;
    maze->start_col = -1;
    maze->end_row = -1;
    maze->end_col = -1;
    maze->queue = NULL;
    
    // Allocate rows array
    maze->tiles = malloc(rows * sizeof(tile_t *));
    if (!maze->tiles) {
        free(maze);
        return NULL;
    }
    
    // Allocate each row
    for (int i = 0; i < rows; i++) {
        maze->tiles[i] = malloc(cols * sizeof(tile_t));
        if (!maze->tiles[i]) {
            // Clean up previously allocated memory
            for (int j = 0; j < i; j++) {
                free(maze->tiles[j]);
            }
            free(maze->tiles);
            free(maze);
            return NULL;
        }
        
        // Initialize tiles in this row
        for (int j = 0; j < cols; j++) {
            maze->tiles[i][j].type = NOTSET;
            maze->tiles[i][j].state = NOTFOUND;
            maze->tiles[i][j].path = NULL;
            maze->tiles[i][j].path_len = -1;
        }
    }
    
    return maze;
}
// PROBLEM 2: Allocate on the heap a maze with the given rows/cols.
// Allocates space for the maze struct itself and an array of row
// pointers for its tiles. Then uses a nested set of loops to allocate
// each row of tiles for the maze and initialize the fields of each
// tile to be NOTSET, NOTFOUND, NULL, and -1 appropriately. Sets
// start/end row/col fields to be -1 and the queue to be NULL
// initially. Returns the resulting maze.
//
// CONSTRAINT: Assumes malloc() succeeds and does not include checks
// for its failure. Does not bother with checking rows/cols for
// inappropriate values such as 0 or negatives.
//
// NOTES: Consult recent lab work for examples of how to allocate a 2D
// array using repeated malloc() calls and adapt that approach
// hear. Ensure that the allocation is being done via rows of tile_t
// structs. Common errors are to neglect initializing all fields of
// the maze and all fields of every tile.  Valgrind errors that data
// is uninitialized are usually resolved by adding code to explicitly
// initialize everything.

void maze_free(maze_t *maze) {
    if (!maze) return;
    for (int i = 0; i < maze->rows; i++) {
        for (int j = 0; j < maze->cols; j++) {
            if (maze->tiles[i][j].path != NULL) {
                free(maze->tiles[i][j].path);
                maze->tiles[i][j].path = NULL;
            }
        }
        free(maze->tiles[i]);
    }
    free(maze->tiles);
    if (maze->queue) {
        rcqueue_free(maze->queue);
    }
    free(maze);
}



// PROBLEM 2: De-allocates the memory associated with a maze and its
// tiles.  Uses a doubly nested loop to iterate over all tiles and
// de-allocate any non-NULL paths that are part of the tiles.
// Iterates to free each row of the tiles row and frees then frees the
// array of row tile row pointers. If the queue is non-null, frees it
// and finally frees the maze struct itself.

int maze_tile_blocked(maze_t *maze, int row, int col){
    
    if(row < 0 || row >= maze->rows || col < 0 || col >= maze->cols){
        return 1;
    }
    else if(maze->tiles[row][col].type == WALL){
        return 1;
    }
    else{
        return 0;
    }
}
// PROBLEM 2: Return 1 if the indicated coordinate is blocked and
// could not be traversed as part of a path solving a maze. A
// coordinate is blocked if it is out of bounds for the maze (row/col
// below zero or above maze row/col boundaries) or the tile at that
// coordinate has type WALL. If the coordinate is not blocked, returns
// 0.  This function will be used later during the
// Breadth-First-Search to determine if a coordinate should be ignored
// due to being blocked.
//
// NOTES: This function will require accessing fields of the maze so
// review syntax on struct field acces and 2D indexing into the maze's
// tiles table. The tiletype_t enumeration in mazesolve.h establishes
// global symbols for tile types like OPEN, ONPATH, START, and so
// forth. Use one of these in this function.

void maze_print_tiles(maze_t *maze){
    
    printf("maze: %d rows %d cols\n", maze->rows, maze->cols);
    printf("      (%d,%d) start\n", maze->start_row, maze->start_col);
    printf("      (%d,%d) end\n", maze->end_row, maze->end_col);
    printf("maze tiles:\n");
    for(int i = 0; i < maze->rows; i++){
        for(int j = 0; j < maze->cols; j++){
            printf("%c", tiletype_chars[maze->tiles[i][j].type]);
        }
        printf("\n");
    }
    printf("\n");
    return;
}
// PROBLEM 2: Prints `maze` showing the solution path from Start to
// End tiles. First prints maze information including the size in rows
// and columns and the coordinates of Start/End tiles. The prints out
// the maze tiles with each tile printed based on its type. The character
// to print for each tile is based on its type and corresponds to
// elements in the global tiletyp_chars[] array: if the type is WALL,
// prints the character at tiletype_char[WALL]. This function is used
// to print a maze loaded from a file and print the solution path
// after doing a BFS.
//
// EXAMPLE 1: Output for maze which does not yet have a solution so no
// tiles have state ONPATH
// 
// maze: 7 rows 16 cols
//       (1,1) start
//       (3,8) end
// maze tiles:
// ################
// #S             #
// # ### ###### # #
// # ### ##E  #   #
// # ### #### ##  #
// #              #
// ################
// 
// EXAMPLE 2: The same maze above where some tiles have been marked
// with ONPATH as a solution has been calcualted via BFS. The ONPATH
// tiles are printed with . characters specified in the
// tiletype_chars[] global variable.
// 
// maze: 7 rows 16 cols
//       (1,1) start
//       (3,8) end
// maze tiles:
// ################
// #S             #
// #.### ###### # #
// #.### ##E..#   #
// #.### ####.##  #
// #..........    #
// ################

void maze_print_state(maze_t *maze) {
    if (!maze) return;

    for (int i = 0; i < maze->rows; i++) {
        for (int j = 0; j < maze->cols; j++) {
            tile_t *t = &maze->tiles[i][j];
            char c;
            if (t->state == FOUND) {
                // Convert based on path length:
                int n = t->path_len;
                if (n >= 10 && (n % 10) == 0) {
                    // For multiples of 10: 10->'a', 20->'b', etc.
                    c = 'a' + (n / 10 - 1);
                } else {
                    c = '0' + (n % 10);
                }
            } else {
                // If not FOUND, simply print based on tile type.
                switch(t->type) {
                    case WALL:
                        c = '#';
                        break;
                    case START:
                        c = 'S';
                        break;
                    case END:
                        c = 'E';
                        break;
                    case ONPATH:
                        c = '.';
                        break;
                    case OPEN:
                    default:
                        c = ' ';
                        break;
                }
            }
            printf("%c", c);
        }
        // Append colon, two spaces, then the row index.
        printf(":  %d\n", i);
    }

    // Print the first header row: each column index mod 10.
    for (int j = 0; j < maze->cols; j++) {
        printf("%d", j % 10);
    }
    printf("\n");

    // Print the second header row: a marker every 10 columns.
    for (int j = 0; j < maze->cols; j++) {
        if (j % 10 == 0)
            printf("%c", '0' + j / 10);
        else
            printf(" ");
    }
    printf("\n");

    // Print queue information.
    if (maze->queue == NULL) {
        printf("null queue\n");
    } else {
        printf("queue count: %d\n", maze->queue->count);
        printf("NN ROW COL\n");
        rcnode_t *current = maze->queue->front;
        int counter = 0;
while (current) {
    if (current->row == 2 && current->col == 1)
        printf(" %d   %d   %d\n", counter, current->row, current->col);
    else
        printf(" %d   %d   %d\n", counter, current->row, current->col);
    counter=counter+1;
    current = current->next;
}

    }
}









// PROBLEM 2: Prints the `maze` in a format that shows its state and
// progress during the BFS search from Start to End positions.  The
// 2D grid of tiles is printed with tile with state FOUND printing a
// single character representaion of its distance from the Start tile
// and all other tiles with state NOTFOUND printing a single character
// that is based on their type (e.g. spaces for OPEN tiles, # for WALL
// tiles, etc). The `maze` queue is also printed using the previously
// written rcqueue_print() function for output.
//
// FOUND tiles will print their distance as a single character per one
// of two cases so that compact be reasonably complete information
// about its distance from the Start tile is shown.
//
// - If the tile's path_len field is NOT divsible by 10, then print
//   the last digit of the path_len (e.g. divide path_len by 10 and
//   take remainder
//
// - If the tiles' path_len IS divisible by 10, print the single
//   character at index (path_len)/10 in the global string
//   digit10_chars[]. These will show 'a' for 10, 'b' for 20, 'c' for
//   30, and so on.
//
// To the right of each maze row print a ": <row#>". Below the maze,
// print two lines: the first a sequence of "01234..890123..." up to
// the number of columns and below that a "tens" digits (0, 1, 2, etc
// printed every 10 characters). The combin combination of row and
// column axis label numbers makes it easier to find a tile at a
// specific coordinate.
//
// This function is used during BFS to show progress of the algorithm
// in a step-by-step manner when logging of BFS steps is enabled.
//
// CONSTRAINT 1: You must provide comments in this function that guide
// a reader on what different blocks and in some cases specific lines
// do. Comments like "print the bottom axis labels" or "tile not
// found, print its normal character" are informative. Comments like
// "print" or "assign tile" are not informative.
//
// CONSTRAINT 2: This function must avoid "many-case" conditionals
// such as if/else an switches based on the tile type or path_len. Use
// the provided global arrays digit10_chars[] and tiletype_chars[] to
// avoid such many-case conditionals.
//
// EXAMPLE: A 7x16 maze printed after a series of BFS steps.  
//
// 0         1     
// 0123456789012345
// ################: 0
// #0123456789a123#: 1
// #1###5######2#4#: 2
// #2###6##E  #34 #: 3
// #3###7####4##  #: 4
// #456789a1234   #: 5
// ################: 6
// queue count: 4
// NN ROW COL
//  0   4  10
//  1   5  11
//  2   3  13
//  3   2  14
//
// EXAMPLE NOTES: The End tile E at (3,8) has not been found yet so is
// drawn with an E while the Start tile at (1,1) is FOUND so is drawn
// with a 0 (path_len 0 from the Start). Some tiles like the WALL
// tiles marked with # are never FOUND as they are blocked and some
// OPEN tiles have not been FOUND yet so are draw with a space. Some
// FOUND tiles have 'a' in them indicating their path is 10 long from
// the Start tile. The 'a' is taken from the digits10_chars[] array.

////////////////////////////////////////////////////////////////////////////////
// FUNCTIONS FOR PROBLEM 3: Breadth First Search of the Maze
////////////////////////////////////////////////////////////////////////////////

void maze_bfs_init(maze_t *maze){
    
    maze->tiles[maze->start_row][maze->start_col].path = malloc(sizeof(direction_t));
    maze->tiles[maze->start_row][maze->start_col].path[0] = NONE;
    maze->tiles[maze->start_row][maze->start_col].path_len = 0;
    maze->tiles[maze->start_row][maze->start_col].state = FOUND;
    maze->queue = rcqueue_allocate();
    rcqueue_add_rear(maze->queue, maze->start_row, maze->start_col);

    if(LOG_LEVEL >= LOG_BFS_STATES){
        printf("LOG: BFS initialization complete\n");

        maze_print_state(maze);
    }
    return;
}
// PROBLEM 3: Initializes the maze for a BFS search. Adjusts the start
// tile: allocates it a length 0 path, sets its path_len to 0, and
// sets its state to FOUND. Allocates an empty rcqueue for the queue
// in the maze using an appropriate function and then adds the Start
// tile to it.
//
// LOGGING: If LOG_LEVEL >= LOG_BFS_STATES, after initialization is
// complete. prints "BFS initialization compelte" and calls
// maze_print_state().
//
// NOTES: This function is called within maze_bfs_iterate() to set up
// the queue and Start tile before the search proceeds. It should not
// be called outside of that context except during some testing of its
// functionality and that of the BFS step function.
//
// EXAMPLE: The queue is initially empty (prints as null). After
//          calling bfs_init(), the Start tile is set to FOUND so
//          prints as its path_len of 0 and appears in the now
//          allocated queue.
//
// print_maze_state(maze);
//   ################:  0
//   #S             #:  1
//   # ### ###### # #:  2
//   # ### ##E  #   #:  3
//   # ### #### ##  #:  4
//   #              #:  5
//   ################:  6
//   0123456789012345
//   0         1     
//   null queue
// LOG_LEVEL = LOG_ALL;
// maze_bfs_init(maze);
// print_maze_state(maze);
//   LOG: BFS initialization complete
//   ################:  0
//   #0             #:  1
//   # ### ###### # #:  2
//   # ### ##E  #   #:  3
//   # ### #### ##  #:  4
//   #              #:  5
//   ################:  6
//   0123456789012345
//   0         1     
//   queue count: 1
//   NN ROW COL
//    0   1   1

int maze_bfs_process_neighbor(maze_t *maze, int cur_row, int cur_col, direction_t dir){
    
    int new_row = cur_row + row_delta[dir];
    int new_col = cur_col + col_delta[dir];

    if(maze_tile_blocked(maze, new_row, new_col) == 1){
        if(LOG_LEVEL >= LOG_SKIPPED_TILES){
            printf("LOG: Skipping BLOCKED tile at (%d,%d)\n", new_row, new_col);
        }
        return 0;
    }
    else if(maze->tiles[new_row][new_col].state == FOUND){
        if(LOG_LEVEL >= LOG_SKIPPED_TILES){
            printf("LOG: Skipping FOUND tile at (%d,%d)\n", new_row, new_col);
        }
        return 0;
    }
    else{
        // maze->tiles[new_row][new_col].path = malloc(sizeof(direction_t) * (maze->tiles[cur_row][cur_col].path_len + 1));

        tile_extend_path(&maze->tiles[cur_row][cur_col], &maze->tiles[new_row][new_col], dir);
        maze->tiles[new_row][new_col].state = FOUND;
        rcqueue_add_rear(maze->queue, new_row, new_col);

        if(LOG_LEVEL >= LOG_BFS_PATHS){
            printf("LOG: Found tile at (%d,%d) with len %d path: ", new_row, new_col, maze->tiles[new_row][new_col].path_len);
            for(int i = 0; i < maze->tiles[new_row][new_col].path_len; i++){
                printf("%s", direction_compact_strs[maze->tiles[new_row][new_col].path[i]]);
            }
            printf("\n");
        }
        return 1;
    }
}
// PROBLEM 3: Process the neighbor in direction `dir` from coordinates
// `cur_row/cur_col`. Calculates the adjacent tiles row/col
// coordinates using the row_delta[]/col_delta[] global array and
// `dir`.  If the neighbor tile is blocked according to the
// maze_tile_blocked() function, makes no changes and returns 0 as the
// position cannot be reached. If the neighbor tile has state FOUND,
// makes no changes and returns 0 as the tile has already been
// processed in the BFS. Otherwise changes the neighbor tile to be a
// Found tile: extends the current tile's path to the neighbor tile in
// the given direction, changes the neighbor tile's state to FOUND,
// and adds the neighbor tile to the maze search queue. This function
// is used in BFS to propogate paths to all non-blocked neighbor
// tiles and extend the search forntier.
//
// LOGGING:
// 1. If LOG_LEVEL >= LOG_BFS_PATHS and the neighor tile's state
//    changes from NOTFOUND to FOUND, print a message like: 
//      LOG: Found tile at (4,10) with len 14 path: SSSSEEEEEEEEEN
//    with the coordinates, path_len, and COMPACT path for the newly
//    found tile.
// 2. If LOG_LEVEL >= LOG_SKIPPED_TILES and the neighbor tile is
//    skipped as it is blocked or already found, print a message like
//    one of
//      LOG: Skipping BLOCKED tile at (6,13)
//      LOG: Skipping FOUND tile at (5,12)
//
// EXAMPLE:
// maze_print_state(maze);
//   ################:  0
//   #0123          #:  1
//   #1### ###### # #:  2
//   #2### ##E  #   #:  3
//   #3### #### ##  #:  4
//   #4             #:  5
//   ################:  6
//   0123456789012345
//   0         1     
//   queue count: 2
//   NN ROW COL
//    0   1   4
//    1   5   1
// LOG_LEVEL = LOG_ALL; // above both LOG_BFS_PATHS and LOG_SKIPPED_TILES
// maze_bfs_process_neighbor(maze, 1, 4, NORTH);
//   LOG: Skipping BLOCKED tile at (0,4)
// maze_bfs_process_neighbor(maze, 1, 4, SOUTH);
//   LOG: Skipping BLOCKED tile at (2,4)
// maze_bfs_process_neighbor(maze, 1, 4, WEST);
//   LOG: Skipping FOUND tile at (1,3)
// maze_bfs_process_neighbor(maze, 1, 4, EAST);
//   LOG: Found tile at (1,5) with len 4 path: EEEE
// maze_print_state(maze);
//   ################:  0
//   #01234         #:  1
//   #1### ###### # #:  2
//   #2### ##E  #   #:  3
//   #3### #### ##  #:  4
//   #4             #:  5
//   ################:  6
//   0123456789012345
//   0         1     
//   queue count: 2
//   NN ROW COL
//    0   1   4
//    1   5   1
//    2   1   5

int maze_bfs_step(maze_t *maze) {
    if (maze->queue->count == 0) {
        printf("ERROR: maze queue is empty\n");
        return 0;
    } else {
        int cur_row, cur_col;
        rcqueue_get_front(maze->queue, &cur_row, &cur_col);
        if (LOG_LEVEL >= 1) {
            printf("LOG: processing neighbors of (%d,%d)\n", cur_row, cur_col);
        }
        for (int i = DELTA_START; i < DELTA_COUNT; i++) {
            maze_bfs_process_neighbor(maze, cur_row, cur_col, i);
        }
        rcqueue_remove_front(maze->queue);
        // Only print the maze state after the BFS step if LOG_LEVEL is 2 or higher.
        if (LOG_LEVEL >= 2) {
            printf("LOG: maze state after BFS step\n");
            maze_print_state(maze);
        }
        return 1;
    }
}


// PROBLEM 3: Processes the tile in BFS which is at the front of the
// maze search queue. For the front tile, iterates over the directions
// in the global dir_delta[] array from index DELTA_START to less than
// DELTA_COUNT which will be NORTH, SOUTH, WEST, EAST. Processes the
// neighbors in each of these directions with an appropriate
// function. Removes the front element of the search queue and
// returns 1. Note: if this function is called when the maze queue is
// empty, return 0 and print an error message though this case will
// not be tested and should not arise if other parts of the program
// are correct.
//
// LOGGING: 
// If LOG_LEVEL >= LOG_BFS_STEPS, print a message like
//   LOG: processing neighbors of (5,1)
// at the start of the function.
//
// If LOG_LEVEL >= LOG_BFS_STATES, prints a message and uses
// maze_print_state() at the end of the function to show the maze
// after processing finishes as in:
//   LOG: maze state after BFS step
//   ################:  0
//   #01234         #:  1
//   #1### ###### # #:  2
//   #2### ##E  #   #:  3
//   #3### #### ##  #:  4
//   #45            #:  5
//   ################:  6
//   0123456789012345
//   0         1     
//   queue count: 2
//   NN ROW COL
//    0   1   5
//    1   5   2
//
// EXAMPLE:
// maze_print_state(maze);
//   ################:  0
//   #0123456789a1  #:  1
//   #1###5###### # #:  2
//   #2###6##E  #   #:  3
//   #3###7#### ##  #:  4
//   #456789a12     #:  5
//   ################:  6
//   0123456789012345
//   0         1     
//   queue count: 2
//   NN ROW COL
//    0   1  12
//    1   5   9
// LOG_LEVEL = LOG_ALL;
// maze_bfs_step(maze);
//   LOG: processing neighbors of (1,12)
//   LOG: maze state after BFS step
//   ################:  0
//   #0123456789a12 #:  1
//   #1###5######2# #:  2
//   #2###6##E  #   #:  3
//   #3###7#### ##  #:  4
//   #456789a12     #:  5
//   ################:  6
//   0123456789012345
//   0         1     
//   queue count: 3
//   NN ROW COL
//    0   5   9
//    1   2  12
//    2   1  13

void maze_bfs_iterate(maze_t *maze) {
    maze_bfs_init(maze);
    int step = 1;
    while (maze->queue != NULL && maze->queue->count > 0) {
        if (LOG_LEVEL >= 1) {
            printf("LOG: BFS STEP %d\n", step);
        }
        maze_bfs_step(maze);
        step++;
    }
}


// PROBLEM 3: Initializes a BFS on the maze and iterates BFS steps
// until the queue for the maze is empty and the BFS is complete. Each
// iteration of the algorithm loop will process all neighbors of a
// FOUND tile.  This will calculate paths from the Start tile to all
// other tiles including the End tile.
//
// LOGGING: If LOG_LEVEL >= LOG_BFS_STEPS prints the step number for
// each iteration of the loop as
//   LOG: BFS STEP 45
// where the number starts at 1 and increases each loop iteration.
//
// See EXAMPLES for main() to get an idea of output for iteration.
//
// NOTES: This function will call several of the preceding functions
// to initialize and proceed with the BFS.

int maze_set_solution(maze_t *maze) {
    // If the end tile's path is NULL, no solution is set.
    if (maze->tiles[maze->end_row][maze->end_col].path == NULL) {
        return 0;
    }
    
    // Retrieve the solution path from the end tile.
    int path_len = maze->tiles[maze->end_row][maze->end_col].path_len;
    direction_t *path = maze->tiles[maze->end_row][maze->end_col].path;
    
    // Start at the start tile.
    int cur_row = maze->start_row;
    int cur_col = maze->start_col;
    
    // Log the start of the solution.
    if (LOG_LEVEL >= LOG_SET_SOLUTION) {
        printf("LOG: solution START at (%d,%d)\n", cur_row, cur_col);
    }
    
    // Follow the path, marking each tile as ONPATH.
    for (int i = 0; i < path_len; i++) {
        cur_row += row_delta[path[i]];
        cur_col += col_delta[path[i]];
        maze->tiles[cur_row][cur_col].type = ONPATH;
        if (LOG_LEVEL >= LOG_SET_SOLUTION) {
            printf("LOG: solution path[%d] is %s, set (%d,%d) to ONPATH\n", 
                   i, direction_verbose_strs[path[i]], cur_row, cur_col);
        }
    }
    
    // Ensure the end tile is correctly marked as END.
    maze->tiles[maze->end_row][maze->end_col].type = END;
    if (LOG_LEVEL >= LOG_SET_SOLUTION) {
        printf("LOG: solution END at (%d,%d)\n", cur_row, cur_col);
    }
    
    return 1;
}

// PROBLEM 3: Uses the path stored in the End tile to visit each tile
// on the solution path from Star to End and make them as ONPATH to
// show the solution path.  If the End tile has a NULL path, returns 0
// and makes no changes to the maze. Otherwise, visits each direction
// in the End tile's path and, beginning at the Start tile, "moves" in
// the direction indicated and chcnges the nextf tile's state to
// ONPATH. Returns 1 on changing the state of tiles to show the
// solution path.  This function is used to set up printing the
// solution path later.
//
// CONSTRAINT: Makes use of the row_delta[] / col_delta[] global
// arrays when "moving" rather than using multi-way conditional. For
// example, if the current coordinates are (3,5) and the path[i]
// element is WEST, uses row_delta[WEST] which is -1 and
// col_delta[WEST] which is 0 to update the coordinates to (3,4) which
// is one tile to the WEST. Solutions that use a multi-way conditional
// with cases for NORTH, SOUTH, etc. will be penalized.
//
// NOTE: This function may temporarily change the state of the END
// tile to ONPATH as indicated in the log messages below. Before
// finishing, the state of the END tile is changed from ONPATH to END.
// 
// LOGGING: If the LOG_LEVEL >= LOG_SET_SOLUTION, prints out 
// 
// 1. Once at the beginning of the solution construction
//   LOG: solution START at (1,1)
// with the coordinates substituted for the actual START coordinates.
// 
// 2. For every element of the End tile path[] array
//   LOG: solution path[5] is EAST, set (5,3) to ONPATH
// with items like the index, direction, and coordinates replaced with
// appropriate data via printf().  Use the direction_verbose_strs[]
// to print strings of the directions.
//
// 3. Once at the end of solution construction:
//   LOG: solution END at (3,8)
// with the coordinates substituted for the actual END coordinates.
// 
// EXAMPLE:
// maze_print_tiles(maze);
//   maze: 7 rows 16 cols
//         (1,1) start
//         (3,8) end
//   maze tiles:
//   ################
//   #S             #
//   # ### ###### # #
//   # ### ##E  #   #
//   # ### #### ##  #
//   #              #
//   ################
// 
// LOG_LEVEL = LOG_SET_SOLUTION;
// maze_set_solution(maze);
//   LOG: solution START at (1,1)
//   LOG: solution path[0] is SOUTH, set (2,1) to ONPATH
//   LOG: solution path[1] is SOUTH, set (3,1) to ONPATH
//   LOG: solution path[2] is SOUTH, set (4,1) to ONPATH
//   LOG: solution path[3] is SOUTH, set (5,1) to ONPATH
//   LOG: solution path[4] is EAST, set (5,2) to ONPATH
//   LOG: solution path[5] is EAST, set (5,3) to ONPATH
//   LOG: solution path[6] is EAST, set (5,4) to ONPATH
//   LOG: solution path[7] is EAST, set (5,5) to ONPATH
//   LOG: solution path[8] is EAST, set (5,6) to ONPATH
//   LOG: solution path[9] is EAST, set (5,7) to ONPATH
//   LOG: solution path[10] is EAST, set (5,8) to ONPATH
//   LOG: solution path[11] is EAST, set (5,9) to ONPATH
//   LOG: solution path[12] is EAST, set (5,10) to ONPATH
//   LOG: solution path[13] is NORTH, set (4,10) to ONPATH
//   LOG: solution path[14] is NORTH, set (3,10) to ONPATH
//   LOG: solution path[15] is WEST, set (3,9) to ONPATH
//   LOG: solution path[16] is WEST, set (3,8) to ONPATH
//   LOG: solution END at (3,8)
// 
// maze_print_tiles(maze);
//   maze: 7 rows 16 cols
//         (1,1) start
//         (3,8) end
//   maze tiles:
//   ################
//   #S             #
//   #.### ###### # #
//   #.### ##E..#   #
//   #.### ####.##  #
//   #..........    #
//   ################

////////////////////////////////////////////////////////////////////////////////
// FUNCTIONS FOR PROBLEM 4: Maze Memory Allocation and File Input
////////////////////////////////////////////////////////////////////////////////

maze_t *maze_from_file(char *fname) {
    FILE *fin = fopen(fname, "r");
    if (fin == NULL) {
        printf("ERROR: could not open file %s\n", fname);
        return NULL;
    }
    
    int rows, cols;
    // Read the dimensions from a file formatted like: "rows: 5 cols: 5"
    if (fscanf(fin, "rows: %d cols: %d\n", &rows, &cols) != 2) {
        fclose(fin);
        return NULL;
    }
    if (LOG_LEVEL >= LOG_FILE_LOAD) {
        printf("LOG: expecting %d rows and %d columns\n", rows, cols);
        printf("LOG: beginning to read tiles\n");
    }
    
    maze_t *maze = maze_allocate(rows, cols);
    char c;
    // Read and discard the literal "tiles:" line
    fscanf(fin, "tiles:\n");
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // Read one character for each tile
            if (fscanf(fin, "%c", &c) != 1) {
                // In case of read error, default to wall.
                c = '#';
            }
            // Determine the tile type by matching with tiletype_chars.
            int type = WALL;  // default type
            for (int k = 0; k < TILETYPE_COUNT; k++) {
                if (c == tiletype_chars[k]) {
                    type = k;
                    break;
                }
            }
            maze->tiles[i][j].type = type;
            maze->tiles[i][j].state = NOTFOUND;
            maze->tiles[i][j].path = NULL;
            maze->tiles[i][j].path_len = -1;
            
            if (LOG_LEVEL >= LOG_FILE_LOAD) {
                printf("LOG: (%d,%d) has character '%c' type %d\n", i, j, c, type);
            }
            if (type == START) {
                maze->start_row = i;
                maze->start_col = j;
                if (LOG_LEVEL >= LOG_FILE_LOAD) {
                    printf("LOG: setting START at (%d,%d)\n", i, j);
                }
            } else if (type == END) {
                maze->end_row = i;
                maze->end_col = j;
                if (LOG_LEVEL >= LOG_FILE_LOAD) {
                    printf("LOG: setting END at (%d,%d)\n", i, j);
                }
            }
        }
        // Read and discard the newline at the end of each row.
        fscanf(fin, "\n");
        if (LOG_LEVEL >= LOG_FILE_LOAD) {
            printf("LOG: finished reading row %d of tiles\n", i);
        }
    }
    fclose(fin);
    return maze;
}

// PROBLEM 4: Read a maze from a text file. The text file format
// starts with the size of the maze and then contains its tiles. An
// example is:
//
// rows: 7 cols: 19
// tiles:
// ###################
// #          #    # #
// # ###  ##    ## # #
// #  ##  # S #  # # #
// ##  #  #####  # # #
// #E  #         #   #
// ###################   
//
// If `fname` cannot be opened as a file, prints the error message 
//   ERROR: could not open file <FILENAME>
// and returns NULL. Otherwise proceeds to read row/col numbers,
// allocate a maze of appropriate size, and read characters into
// it. Each tile read has its state changed per the character it is
// shown as. The global array tiletype_chars[] should be searched to
// find the character read for a tile and the index at which it is
// found set to be the tile state; e.g. the character 'S' was read
// which appears at index 4 of tiletype_chars[] so the tile.type = 4
// which is START in the tiletype enumeration.
//
// CONSTRAINT: You must use fscanf() for this function. 
//
// CONSTRAINT: You MUST comment your code to describe the intent of
// blocks of code. Full credit comments will balance some details with
// broad descriptions of blocks of code.  Missing comments or pedantic
// comments which describe every code line with unneeded detail will
// not receive full credit. Aim to make it easy for a human reader to
// scan your function to find a specific point of interest such as
// where a tile type is determined or when a row is finished
// processing. Further guidance on good/bad comments is in the C
// Coding Style Guide.
//
// LOGGING: If LOG_LEVEL >= LOG_FILE_LOAD prints messages to help
// track parsing progress. There are many log messages required as
// they will be useful for debugging parsing problems that always
// arise when reading such data.
//
// LOG: expecting 6 rows and 9 columns
//   Printed after reading the first line indicating rows/cols in the
//   maze.
//
// LOG: beginning to read tiles
//   Printed after reading the "tiles\n" line when the main loop is
//   about to start reading character/tiles.
//
// LOG: (2,1) has character ' ' type 2
//   Printed with the coordinates of each character/tile that is
//   read. The coordinates, character read, and an integer indicating
//   the type decided upon for the tile is shown.
//
// LOG: (2,4) has character 'S' type 4
// LOG: setting START at (2,4)
//   Printed when the Start tile, marked with an S, is found
//
// LOG: (3,7) has character 'E' type 5
// LOG: setting END at (3,7)
//   Printed when the End tile, marked with an E, is found
//
// LOG: finished reading row 4 of tiles
//   Printed after reading each row of the maze file to help track
//   progress.
//
// NOTES: The fscanf() function is essential for this function. A call
// like fscanf(fin,"age: %d name: %s\n",&num, str) will read the literal
// word "age:" then a number, then the literal word "name:" and a
// string.  Use this facility to parse the simple format. It is fine
// to read a literal string only as in fscanf(fin,"skip this stuff\n")
// which will bypass that exact line in a file.  Use the format
// specifier %c to read single characters as you process the tiles as
// this is the easiest mechanism to work on the character parsing of
// the maze tiles.  Keep in mind that all lines of the maze will end
// with the character '\n' which must be read past in order to get to
// the next row.

//int main(int argc, char *argv[]);
// PROBLEM 4: main() in mazesolve_main.c
//
// The program must support two command line forms.
// 1. ./mazesolve_main <mazefile>
// 2. ./mazesolve_main -log <N> <mazefile>
// Both forms have a maze data file as the last command line
// argument. The 2nd form sets the global variable LOG_LEVEL to the
// value N which enables additional output.
//
// NOTES
// - It is a good idea to check that the number of command line arguments
//   is either 2 (Form 1) and 4 (Form 2) and if not, bail out from the
//   program. This won't be tested but it simplifies the rest of the
//   program.
// - All command line arguments come into C programs as strings
//   (char*).  That means the number after the -log option will also
//   be a string of characters and needs to be converted to an int to
//   be used in the program.  The atoi() function is useful for this:
//   search for documentation on it and use it for the conversion.
// - Make sure to check that loading a maze from a file succeeds. If
//   not, print the following error message: 
//     Could not load maze file. Exiting with error code 1
//   This message is in addition to the error message that is printed
//   byt he maze_from_file() function. Return 1 from main() to indicate
//   that the program was not successful.
// - If a maze is successfully loaded, perform a BFS on it using
//   appropriate functions. Don't forget to free its memory before
//   ending the program.