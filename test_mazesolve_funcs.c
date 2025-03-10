#include "mazesolve.h"
// Fri Feb 14 10:43:47 AM EST 2025 Update to maze_bfs_step2; see
// https://piazza.com/class/m69s0i6labk3eb/post/104

// macro to set up a test with given name, print the source of the
// test; very hacky, fragile, but useful
#define IF_TEST(TNAME) \
  if( RUNALL || strcmp( TNAME, test_name)==0 ) { \
    sprintf(sysbuf,"awk 'NR==(%d){P=1;gsub(\"^ *\",\"\");} P==1 && /ENDTEST/{P=0; print \"}\\n---OUTPUT---\"} P==1{print}' %s", __LINE__, __FILE__); \
    system(sysbuf); nrun++;  \
  } \
  if( RUNALL || strcmp( TNAME, test_name)==0 )

char sysbuf[1024];
int RUNALL = 0;
int nrun = 0;



// create a maze from a string, calls student-written maze_allocate()
// function to obtain memory / initial state of maze
maze_t *maze_from_string(char *str){
  int rows=0, cols=-1;
  for(int ci=0; str[ci]!='\0'; ci++){
    if(cols==-1 && str[ci]=='\n'){
      cols = ci;
    }
    rows += (str[ci]=='\n');
  }
  maze_t *maze = maze_allocate(rows,cols);
  tiletype_t type_chars[128];   // lookup table for char to type correspondence
  type_chars['?'] = NOTSET;
  type_chars['#'] = WALL;
  type_chars[' '] = OPEN;
  type_chars['.'] = ONPATH;
  type_chars['S'] = START;
  type_chars['E'] = END;
  int ci=0;
  for(int i=0; i<rows; i++, ci++){
    for(int j=0; j<cols; j++, ci++){
      maze->tiles[i][j].type = type_chars[ (int)str[ci] ];
      if(maze->tiles[i][j].type == START){
        maze->start_row = i;
        maze->start_col = j;
      }
      if(maze->tiles[i][j].type == END){
        maze->end_row = i;
        maze->end_col = j;
      }
    }
  }
  return maze;
}

int main(int argc, char *argv[]){
  if(argc < 2){
    printf("usage: %s <test_name>\n", argv[0]);
    return 1;
  }
  char *test_name = argv[1];
  char sysbuf[1024];
  if(strcmp(test_name,"ALL")==0){
    RUNALL = 1;
  }  

  ////////////////////////////////////////////////////////////////////////////////
  // PROBLEM 3 TESTS 10
  ////////////////////////////////////////////////////////////////////////////////

  IF_TEST("rcqueue_allocate_free1") {
    // Allocate and free an empty queue.
    rcqueue_t *queue = rcqueue_allocate();
    printf("queue->count: %d\n",queue->count);
    printf("queue->front: %p\n",queue->front);
    printf("queue->rear:  %p\n",queue->rear);
    rcqueue_free(queue);
  } // ENDTEST

  IF_TEST("rcqueue_add_rear1") {
    // Add a single element to the queue and print that node. Verifies
    // that the front/rear node is the same for a single element add.
    rcqueue_t *queue = rcqueue_allocate();
    rcqueue_add_rear(queue,5,9);
    printf("queue->count: %d\n",queue->count);
    printf("queue->front->row: %d\n",queue->front->row);
    printf("queue->front->col: %d\n",queue->front->col);
    printf("queue->rear->row: %d\n",queue->rear->row);
    printf("queue->rear->col: %d\n",queue->rear->col);
    rcqueue_free(queue);
  } // ENDTEST

  IF_TEST("rcqueue_add_rear2") {
    // Add 3 elements successively to the queue then print the
    // front/rear elements.
    rcqueue_t *queue = rcqueue_allocate();
    rcqueue_add_rear(queue,10,2);
    rcqueue_add_rear(queue,9,3);
    rcqueue_add_rear(queue,11,4);
    printf("queue->count: %d\n",queue->count);
    printf("queue->front->row: %d\n",queue->front->row);
    printf("queue->front->col: %d\n",queue->front->col);
    printf("queue->rear->row: %d\n",queue->rear->row);
    printf("queue->rear->col: %d\n",queue->rear->col);
    rcqueue_free(queue);
  } // ENDTEST

  IF_TEST("rcqueue_get_front1") {
    // Add several elements then use accessor get_front() to set
    // integers to the front row/col. Ensures that proper
    // pointer-dereferencing is used.
    int ret, row, col;
    rcqueue_t *queue = rcqueue_allocate();
    rcqueue_add_rear(queue,10,2);
    rcqueue_add_rear(queue,9,3);
    rcqueue_add_rear(queue,11,4);
    ret = rcqueue_get_front(queue, &row, &col);
    printf("ret: %d\n",ret);
    printf("front row/col: (%d,%d)\n",row,col);
    rcqueue_free(queue);
  } // ENDTEST

  IF_TEST("rcqueue_remove_front1") {
    // Add 3 coordinates to a queue and remove 1 then print the queue.
    int ret, row, col;
    rcqueue_t *queue = rcqueue_allocate();
    rcqueue_add_rear(queue,10,2);
    rcqueue_add_rear(queue,9,3);
    rcqueue_add_rear(queue,11,4);
    ret = rcqueue_remove_front(queue);
    printf("ret: %d\n",ret);
    printf("queue->count: %d\n",queue->count);
    printf("queue->front->row: %d\n",queue->front->row);
    printf("queue->front->col: %d\n",queue->front->col);
    printf("queue->rear->row: %d\n",queue->rear->row);
    printf("queue->rear->col: %d\n",queue->rear->col);
    ret = rcqueue_get_front(queue, &row, &col);
    printf("ret: %d\n",ret);
    printf("front row/col: (%d,%d)\n",row,col);
    rcqueue_free(queue);
  } // ENDTEST

  IF_TEST("rcqueue_remove_front2") {
    // Add 3 coordinates then remove two. Shows whether the front/rear
    // nodes coincide when there is one element left after removal.
    int ret, row, col;
    rcqueue_t *queue = rcqueue_allocate();
    rcqueue_add_rear(queue,10,2);
    rcqueue_add_rear(queue,9,3);
    rcqueue_add_rear(queue,11,4);
    ret = rcqueue_remove_front(queue);
    printf("ret: %d\n",ret);
    ret = rcqueue_remove_front(queue);
    printf("ret: %d\n",ret);
    printf("queue->count: %d\n",queue->count);
    printf("queue->front->row: %d\n",queue->front->row);
    printf("queue->front->col: %d\n",queue->front->col);
    printf("queue->rear->row: %d\n",queue->rear->row);
    printf("queue->rear->col: %d\n",queue->rear->col);
    ret = rcqueue_get_front(queue, &row, &col);
    printf("ret: %d\n",ret);
    printf("front row/col: (%d,%d)\n",row,col);
    rcqueue_free(queue);
  } // ENDTEST

  IF_TEST("rcqueue_remove_front3") {
    // Adds 3 coordinates to the queue and then removes all 3 before
    // printing to show whether the queue is properly empty. If rear
    // pointer is not set to NULL, this test will print incorrect
    // results. Checks progressive attempts to get the row/col of the
    // front node to verify it is the correct value and the return
    // values of remove/get calls.
    int ret, row, col;
    rcqueue_t *queue = rcqueue_allocate();
    rcqueue_add_rear(queue,10,2);
    rcqueue_add_rear(queue,9,3);
    rcqueue_add_rear(queue,11,4);
    ret = rcqueue_remove_front(queue);
    printf("remove ret: %d\n",ret);
    ret = rcqueue_get_front(queue, &row, &col);
    printf("get ret: %d\n",ret);
    printf("front row/col: (%d,%d)\n",row,col);
    ret = rcqueue_remove_front(queue);
    printf("remove ret: %d\n",ret);
    ret = rcqueue_get_front(queue, &row, &col);
    printf("get ret: %d\n",ret);
    printf("front row/col: (%d,%d)\n",row,col);
    ret = rcqueue_remove_front(queue);
    printf("remove ret: %d\n",ret);
    printf("queue->count: %d\n",queue->count);
    printf("queue->count: %d\n",queue->count);
    printf("queue->front: %p\n",queue->front);
    printf("queue->rear:  %p\n",queue->rear);
    ret = rcqueue_get_front(queue, &row, &col);
    printf("get ret: %d\n",ret);
    printf("front row/col: (%d,%d) //previous vals\n",row,col);
    ret = rcqueue_remove_front(queue);
    printf("remove ret: %d\n",ret);
    printf("queue->count: %d\n",queue->count);
    printf("queue->count: %d\n",queue->count);
    printf("queue->front: %p\n",queue->front);
    printf("queue->rear:  %p\n",queue->rear);
    rcqueue_free(queue);
  } // ENDTEST

  IF_TEST("rcqueue_print1") {
    // Print an empty and single element queue
    rcqueue_t *queue = rcqueue_allocate();
    rcqueue_add_rear(queue,10,2);
    rcqueue_free(queue);
  } // ENDTEST

  IF_TEST("rcqueue_print1") {
    // Add coordinates to a queue printing after each addition to
    // ensure proper printing format.
    rcqueue_t *queue = rcqueue_allocate();
    printf("EMPTY QUEUE:\n");
    rcqueue_print(queue);
    rcqueue_add_rear(queue,10,2);
    printf("\nONE ELEMENT QUEUE:\n");
    rcqueue_print(queue);
    rcqueue_add_rear(queue,9,3);
    rcqueue_add_rear(queue,11,4);
    printf("THREE ELEMENT QUEUE:\n");
    rcqueue_print(queue);
    rcqueue_free(queue);
  } // ENDTEST

  IF_TEST("rcqueue_print2") {
    // Add more coordinates to the queue and print it to show that the
    // output is displayed correctly.
    rcqueue_t *queue = rcqueue_allocate();
    for(int i=1; i<=15; i++){
      rcqueue_add_rear(queue,i,i*2+1);
    }
    rcqueue_print(queue);
    rcqueue_free(queue);
  } // ENDTEST


  ////////////////////////////////////////////////////////////////////////////////
  // PROBLEM 2 TESTS 14 / 15
  ////////////////////////////////////////////////////////////////////////////////


  IF_TEST("tile_print_path1") {
    // Checks that the VERBOSE and COMPACT format for printing paths
    // (arrays of directions) is correct.
    direction_t *path = malloc(sizeof(direction_t)*6);
    path[0] = NORTH;        // heap-allocated for bounds
    path[1] = EAST;         // checking in valgrind
    path[2] = EAST;
    path[3] = SOUTH;
    path[4] = SOUTH;
    path[5] = WEST;
    tile_t tile = {.type=OPEN, .path_len= 6, .path=path};
    printf("VERBOSE FORMAT:\n");
    tile_print_path(&tile, PATH_FORMAT_VERBOSE);
    printf("COMPACT FORMAT: {");
    tile_print_path(&tile, PATH_FORMAT_COMPACT);
    printf("}\n");
    free(path);
  } // ENDTEST

  IF_TEST("tile_print_path2") {
    // Check special cases of printing a length-0 path and printing a
    // NULL path.
    printf("Length 0 path\n");
    direction_t *path = malloc(sizeof(direction_t)*0);
    tile_t tile = {.type=START, .path_len= 0, .path=path};
    printf("VERBOSE FORMAT:\n");
    tile_print_path(&tile, PATH_FORMAT_VERBOSE);
    printf("COMPACT FORMAT: {");
    tile_print_path(&tile, PATH_FORMAT_COMPACT);
    printf("}\n");
    free(path);
    printf("NULL path\n");
    tile.path_len = -1;
    tile.path = NULL;
    printf("VERBOSE FORMAT:\n");
    tile_print_path(&tile, PATH_FORMAT_VERBOSE);
    printf("COMPACT FORMAT:\n");
    tile_print_path(&tile, PATH_FORMAT_COMPACT);
    printf("\n");
  } // ENDTEST

  IF_TEST("tile_extend_path1") {
    // Check that the path from one tile can be extended to another
    direction_t *src_path = malloc(sizeof(direction_t)*5);
    src_path[0] = NORTH;        // heap-allocated for bounds
    src_path[1] = EAST;         // checking in valgrind
    src_path[2] = EAST;
    src_path[3] = SOUTH;
    src_path[4] = SOUTH;
    tile_t src = {.type=OPEN, .path_len= 5, .path=src_path};
    tile_t dst = {.type=OPEN, .path_len=-1, .path=NULL};
    tile_extend_path(&src,&dst,WEST);
    tile_print_path(&dst, PATH_FORMAT_VERBOSE);
    printf("COMPACT: {");
    tile_print_path(&dst, PATH_FORMAT_COMPACT);
    printf("}\n");
    free(dst.path); free(src_path);
  } // ENDTEST

  IF_TEST("tile_extend_path2") {
    // Checks special case of path extension from a 0-length path
    // which applies to the Start tile and its neighbors.
    direction_t *src_path =          // heap-allocated for bounds
      malloc(sizeof(direction_t)*0); // checking in valgrind
    tile_t src = {.type=START, .path_len= 0, .path=src_path};
    tile_t dst = {.type=OPEN,  .path_len=-1, .path=NULL};
    tile_extend_path(&src,&dst,NORTH);
    tile_print_path(&dst, PATH_FORMAT_VERBOSE);
    free(dst.path); free(src_path);
  } // ENDTEST

  IF_TEST("maze_allocate_free1") {
    int rows=3, cols=5;
    maze_t *maze = maze_allocate(rows,cols);
    printf("maze->rows: %d\n",maze->rows);
    printf("maze->cols: %d\n",maze->cols);
    printf("maze->start_row: %d\n",maze->start_row);
    printf("maze->start_col: %d\n",maze->start_col);
    printf("maze->end_row: %d\n",maze->end_row);
    printf("maze->end_col: %d\n",maze->end_col);
    printf("maze->queue: %p\n",maze->queue);
    for(int i=0; i<rows; i++){
      for(int j=0; j<cols; j++){
        printf("maze->tiles[%d][%d]: ",i,j);
        tile_t *tile = &maze->tiles[i][j];
        printf("type %d state %d path_len %d path %p\n",
               tile->type, tile->state,
               tile->path_len, tile->path);
      }
    }
    maze_free(maze);
  } // ENDTEST

  IF_TEST("maze_allocate_free2") {
    // Allocates a maze and sets some tile information to include
    // state, paths, etc. then prints out tiles in the maze. There are
    // non-NULL paths in some tiles and the maze queue is initialized
    // which checks that the maze_free() function de-allocates all
    // non-NULL paths and the queue.
    int rows=4, cols=2;
    maze_t *maze = maze_allocate(rows,cols);
    maze->start_row = 3;
    maze->start_col = 1;
    maze->end_row = 1;
    maze->end_col = 0;
    maze->tiles[3][1].state = START;
    maze->tiles[3][1].path_len = 0;
    maze->tiles[3][1].path = malloc(sizeof(direction_t)*0);
    maze->tiles[2][1].path_len = 1;
    maze->tiles[2][1].path = malloc(sizeof(direction_t)*1);
    maze->tiles[2][1].path[0] = NORTH;
    maze->tiles[1][1].path_len = 2;
    maze->tiles[1][1].path = malloc(sizeof(direction_t)*2);
    maze->tiles[1][1].path[0] = NORTH;
    maze->tiles[1][1].path[1] = NORTH;
    maze->tiles[1][0].state = END;
    maze->tiles[1][0].path_len = 3;
    maze->tiles[1][0].path = malloc(sizeof(direction_t)*3);
    maze->tiles[1][0].path[0] = NORTH;
    maze->tiles[1][0].path[1] = NORTH;
    maze->tiles[1][0].path[2] = WEST;
    maze->queue = rcqueue_allocate();
    rcqueue_add_rear(maze->queue, 1, 0);
    printf("maze->rows: %d\n",maze->rows);
    printf("maze->cols: %d\n",maze->cols);
    printf("maze->start_row: %d\n",maze->start_row);
    printf("maze->start_col: %d\n",maze->start_col);
    printf("maze->end_row: %d\n",maze->end_row);
    printf("maze->end_col: %d\n",maze->end_col);
    for(int i=0; i<rows; i++){
      for(int j=0; j<cols; j++){
        printf("maze->tiles[%d][%d]: ",i,j);
        tile_t *tile = &maze->tiles[i][j];
        printf("type %d state %d path_len %d path ",
               tile->type, tile->state,
               tile->path_len);
        tile_print_path(tile,PATH_FORMAT_COMPACT);
        if(tile->path!=NULL){ printf("\n"); }
      }
    }
    printf("maze->queue: \n");
    rcqueue_print(maze->queue);
    maze_free(maze);
  } // ENDTEST

  IF_TEST("maze_tile_blocked1") {
    maze_t maze = {.rows=3, .cols=5, .tiles=NULL};
    int r,c,ret;
    r=-1; c=2; ret = maze_tile_blocked(&maze,r,c);
    printf("(%d,%d) blocked? %d\n",r,c,ret);
    r=3; c=2; ret = maze_tile_blocked(&maze,r,c);
    printf("(%d,%d) blocked? %d\n",r,c,ret);
    r=1; c=-1; ret = maze_tile_blocked(&maze,r,c);
    printf("(%d,%d) blocked? %d\n",r,c,ret);
    r=1; c=6; ret = maze_tile_blocked(&maze,r,c);
    printf("(%d,%d) blocked? %d\n",r,c,ret);
  } // ENDTEST

  IF_TEST("maze_tile_blocked2") {
    // Checks correct blocked tile checking for in bounds cases some
    // of which are walls and Blocked and others of which are OPEN,
    // START, END, and ONPATH tiles which are not Blocked.
    tile_t rows[5][3] = {
      { {.type=WALL},{.type=WALL},{.type=START} },// 0
      { {.type=OPEN},{.type=OPEN},{.type=ONPATH}},// 1
      { {.type=END}, {.type=OPEN},{.type=WALL}  },// 2
      { {.type=WALL},{.type=OPEN},{.type=WALL}  },// 3
      { {.type=OPEN},{.type=OPEN},{.type=OPEN}  },// 4
      //     0            1             2
    };
    tile_t *tiles[5] =
      {rows[0],rows[1],rows[2],rows[3],rows[4]};
    maze_t maze = {.rows=5, .cols=3, .tiles=tiles};
    int r,c,ret;
    r=0; c=0; ret = maze_tile_blocked(&maze,r,c);
    printf("(%d,%d) blocked? %d\n",r,c,ret);
    r=0; c=2; ret = maze_tile_blocked(&maze,r,c);
    printf("(%d,%d) blocked? %d\n",r,c,ret);
    r=1; c=1; ret = maze_tile_blocked(&maze,r,c);
    printf("(%d,%d) blocked? %d\n",r,c,ret);
    r=2; c=0; ret = maze_tile_blocked(&maze,r,c);
    printf("(%d,%d) blocked? %d\n",r,c,ret);
    r=4; c=1; ret = maze_tile_blocked(&maze,r,c);
    printf("(%d,%d) blocked? %d\n",r,c,ret);
    r=3; c=2; ret = maze_tile_blocked(&maze,r,c);
    printf("(%d,%d) blocked? %d\n",r,c,ret);
    r=4; c=2; ret = maze_tile_blocked(&maze,r,c);
    printf("(%d,%d) blocked? %d\n",r,c,ret);
    r=1; c=2; ret = maze_tile_blocked(&maze,r,c);
    printf("(%d,%d) blocked? %d\n",r,c,ret);
  } // ENDTEST

  IF_TEST("maze_print_tiles1") {
    // Prints a maze that is created from a string. No ONPATH tiles
    // are present.
    char *maze_str =
      "################\n"
      "#S             #\n"
      "# ### ###### # #\n"
      "# ### ##E  #   #\n"
      "# ### #### ##  #\n"
      "#              #\n"
      "################\n";
    maze_t *maze = maze_from_string(maze_str);
    printf("PRINTING TILES:\n");
    maze_print_tiles(maze);
    maze_free(maze);
  } // ENDTEST

  IF_TEST("maze_print_tiles2") {
    // Prints a maze that is created from a string. A complete path of
    // ONPATH tiles from START to END is present.
    char *maze_str =
      "################\n"
      "#S             #\n"
      "#.### ###### # #\n"
      "#.### ##E..#   #\n"
      "#.### ####.##  #\n"
      "#..........    #\n"
      "################\n";
    maze_t *maze = maze_from_string(maze_str);
    printf("PRINTING TILES:\n");
    maze_print_tiles(maze);
    maze_free(maze);
  } // ENDTEST

  IF_TEST("maze_print_tiles3") {
    // Prints a maze with tiles that are determined from raw
    // structs. The maze includes most tile types that should be
    // printed normally.
    tile_t rows[5][3] = {
      { {.type=WALL},{.type=WALL},  {.type=START} },// 0
      { {.type=OPEN},{.type=ONPATH},{.type=ONPATH}},// 1
      { {.type=END}, {.type=OPEN},  {.type=WALL}  },// 2
      { {.type=WALL},{.type=OPEN},  {.type=WALL}  },// 3
      { {.type=OPEN},{.type=OPEN},  {.type=OPEN}  },// 4
      //     0            1             2
    };
    tile_t *tiles[5] =
      {rows[0],rows[1],rows[2],rows[3],rows[4]};
    maze_t maze = {.rows=5, .cols=3, .tiles=tiles};
    printf("PRINTING TILES:\n");
    maze_print_tiles(&maze);
  } // ENDTEST

  IF_TEST("maze_print_state1") {
    // Print the state of searching the following 3x2 maze (vertical
    // bars | show the boundaries).
    //
    // |S | 0
    // |# | 1
    // |E | 2
    //  01
    //
    // In the test case, the maze is set up to show progress to tile
    // (1,1) with paths determined for (0,0), (0,1), and (1,1) and
    // (1,1) is in the search queue.
    direction_t path00[] = {};
    direction_t path01[] = {EAST};
    direction_t path11[] = {EAST,SOUTH};
    tile_t rows[3][2] = {
      { {.type=START, .state=FOUND,    .path_len= 0, .path=path00 }, // tiles[0][0] 
        {.type=ONPATH,.state=FOUND,    .path_len= 1, .path=path01 }, // tiles[0][1] 
      },
      { {.type=WALL,  .state=NOTFOUND, .path_len=-1, .path=NULL },   // tiles[1][0] 
        {.type=OPEN,  .state=FOUND,    .path_len= 2, .path=path11 }, // tiles[1][1] 
      },
      { {.type=END,   .state=NOTFOUND, .path_len=-1, .path=NULL },   // tiles[2][0] 
        {.type=OPEN,  .state=NOTFOUND, .path_len=-1, .path=NULL },   // tiles[2][1] 
      },
    };
    tile_t *tiles[] = {rows[0], rows[1], rows[2] };
    rcnode_t node = {.row=1, .col=1, .next=NULL };
    rcqueue_t queue = {.count=1, .front=&node, .rear=&node};
    maze_t maze = {
      .rows=3, .cols=2, .tiles = tiles, .queue=&queue,
      .start_row=0, .start_col=0, .end_row=2, .end_col=0,
    };
    maze_print_state(&maze);
  } // ENDTEST

  IF_TEST("maze_print_state2") {
    // Creates a large-ish maze of mostly open tiles and assigns path
    // lengths to open tiles before printing. Output will show
    // formating of the axis labels and digits indicating length from
    // (0,0) including printing a for 10, b for 20, c for 30 using
    // characters from the digit10_chars[] global array. START and END
    // tiles are included but both have a path so should print the
    // last digit of the path length rather than S/E.
    int rows=15, cols=35;
    maze_t *maze = maze_allocate(rows,cols);
    for(int i=0; i<rows; i++){
      for(int j=0; j<cols; j++){
        if((i>0 && i==j) || i==rows-1 || j==cols-1){
          maze->tiles[i][j].type = WALL;
          maze->tiles[i][j].state = NOTFOUND;
        }
        else{
          maze->tiles[i][j].path = malloc(sizeof(direction_t)*(i+j));
          maze->tiles[i][j].path_len = i+j;
          maze->tiles[i][j].type = OPEN;
          maze->tiles[i][j].state = FOUND;
        }
      }
    }
    maze->tiles[0][0].type = START;
    maze->tiles[rows-2][cols-2].type=END;
    maze_print_state(maze);
    maze_free(maze);
  } // ENDTEST


  IF_TEST("maze_print_state3") {
    // Prints prints the state of a maze that has no paths set in
    // it. This should look identical to the output of
    // maze_print_tiles() except that the header information is not
    // present and axis labels are printed. No numbers appear as there
    // are no paths set in the maze.
    char *maze_str =
      "################\n"
      "#S             #\n"
      "# ### ###### # #\n"
      "# ### ##E  #   #\n"
      "# ### #### ##  #\n"
      "#              #\n"
      "################\n";
    maze_t *maze = maze_from_string(maze_str);
    printf("PRINTING STATE WITH NO PATHS:\n");
    maze_print_state(maze);
    maze_free(maze);
    maze_str =
      "################\n"
      "#S             #\n"
      "#.### ###### # #\n"
      "#.### ##E..#   #\n"
      "#.### ####.##  #\n"
      "#..........    #\n"
      "################\n";
    maze = maze_from_string(maze_str);
    printf("PRINTING STATE WITH NO PATHS:\n");
    maze_print_state(maze);
    maze_free(maze);
  } // ENDTEST


  IF_TEST("maze_print_state4") {
    // Computer approximate path lengths from the start tile for each
    // non-wall tile in the given maze and prints the state to check
    // formatting. The exact paths are not computed nor allocated,
    // only a rough path length which is stored in each tile.
    char *maze_str =
      "################\n"
      "#S             #\n"
      "# ### ###### # #\n"
      "# ### ##E  #   #\n"
      "# ### #### ##  #\n"
      "#              #\n"
      "################\n";
    maze_t *maze = maze_from_string(maze_str);
    for(int i=0; i<maze->rows; i++){
      for(int j=0; j<maze->cols; j++){
        tile_t *tile = &maze->tiles[i][j];
        if(tile->type != WALL){
          tile->state = FOUND;
          tile->path_len = i-1 + j-1;
        }
      }
    }
    printf("PRINTING STATE WITH APPROXIMATE PATHS:\n");
    maze_print_state(maze);
    maze_free(maze);
  } // ENDTEST


  ////////////////////////////////////////////////////////////////////////////////
  // PROBLEM 3 TESTS 15 
  ////////////////////////////////////////////////////////////////////////////////


  IF_TEST("maze_bfs_init1") {
    // Initialize a maze for BFS search and print the resulting
    // state. Logging is enabled so the initialization function will
    // produce some output.
    char *maze_str =
      "################\n"
      "#S             #\n"
      "# ### ###### # #\n"
      "# ### ##E  #   #\n"
      "# ### #### ##  #\n"
      "#              #\n"
      "################\n";
    maze_t *maze = maze_from_string(maze_str);
    LOG_LEVEL = LOG_ALL;
    printf("Maze BEFORE bfs_init()\n");
    maze_print_state(maze);
    maze_bfs_init(maze);
    printf("Maze AFTER bfs_init()\n");
    maze_print_state(maze);
    maze_free(maze);
  } // ENDTEST


  IF_TEST("maze_bfs_process_neighbor1") {
    // Make a single call to add a neighbor from an initial tile to an
    // open neighbor which should create a path for the nighbor and
    // queue the neighbor for later processing.
    char *maze_str =
      "################\n"
      "#S             #\n"
      "# ### ###### # #\n"
      "# ### ##E  #   #\n"
      "# ### #### ##  #\n"
      "#              #\n"
      "################\n";
    maze_t *maze = maze_from_string(maze_str);
    maze_bfs_init(maze);
    LOG_LEVEL = LOG_ALL;
    printf("Maze BEFORE processing neighbor(s)\n");
    maze_print_state(maze);
    int ret = maze_bfs_process_neighbor(maze,1,1,SOUTH);
    printf("Maze AFTER processing neighbor\n");
    maze_print_state(maze);
    printf("ret: %d\n",ret);
    printf("Tile Path:\n");
    tile_print_path(&maze->tiles[2][1],PATH_FORMAT_VERBOSE);
    maze_free(maze);
  } // ENDTEST

  IF_TEST("maze_bfs_process_neighbor2") {
    // Make 3 successive calls to process neighbors. The 1st and 2nd
    // will add a new neighbor but the 3rd call will not as due to the
    // neighbor being a blocked wall.
    char *maze_str =
      "################\n"
      "#S             #\n"
      "# ### ###### # #\n"
      "# ### ##E  #   #\n"
      "# ### #### ##  #\n"
      "#              #\n"
      "################\n";
    maze_t *maze = maze_from_string(maze_str);
    maze_bfs_init(maze);
    LOG_LEVEL = LOG_ALL;
    printf("Maze BEFORE processing neighbor(s)\n");
    maze_print_state(maze);
    int ret = maze_bfs_process_neighbor(maze,1,1,EAST);
    printf("Maze AFTER processing 1 neighbor(s)\n");
    maze_print_state(maze);
    printf("ret: %d\n",ret);
    printf("Tile Path:\n");
    tile_print_path(&maze->tiles[1][2],PATH_FORMAT_VERBOSE);
    ret = maze_bfs_process_neighbor(maze,1,1,SOUTH);
    printf("Maze AFTER processing 2 neighbor(s)\n");
    maze_print_state(maze);
    printf("ret: %d\n",ret);
    printf("Tile Path:\n");
    tile_print_path(&maze->tiles[2][1],PATH_FORMAT_VERBOSE);
    ret = maze_bfs_process_neighbor(maze,1,1,NORTH);
    printf("Maze AFTER processing 3 neighbor(s)\n");
    maze_print_state(maze);
    printf("ret: %d\n",ret);
    printf("Tile Path:\n");
    tile_print_path(&maze->tiles[0][1],PATH_FORMAT_VERBOSE);
    maze_free(maze);
  } // ENDTEST

  IF_TEST("maze_bfs_process_neighbor3") {
    // Process all 4 neighbors of the start tile which is at the edge
    // of the maze; some of its neighbors are out of bounds so the
    // test ensures that bounds checking is done via
    // maze_tile_blocked(). 
    char *maze_str =
      "############## S\n"
      "#               \n"
      "# ### ###### # #\n"
      "# ### ##E  #   #\n"
      "# ### #### ##  #\n"
      "#              #\n"
      "################\n";
    maze_t *maze = maze_from_string(maze_str);
    maze_bfs_init(maze);
    LOG_LEVEL = LOG_ALL;
    printf("Maze BEFORE processing neighbor(s)\n");
    maze_print_state(maze);
    int ret, r=maze->start_row, c=maze->start_col;
    ret = maze_bfs_process_neighbor(maze,r,c,NORTH);
    printf("Maze AFTER processing 1 neighbor(s)\n");
    maze_print_state(maze);
    printf("ret: %d\n",ret);
    ret = maze_bfs_process_neighbor(maze,r,c,SOUTH);
    printf("Maze AFTER processing 1 neighbor(s)\n");
    maze_print_state(maze);
    printf("ret: %d\n",ret);
    ret = maze_bfs_process_neighbor(maze,r,c,WEST);
    printf("Maze AFTER processing 1 neighbor(s)\n");
    maze_print_state(maze);
    printf("ret: %d\n",ret);
    ret = maze_bfs_process_neighbor(maze,r,c,EAST);
    printf("Maze AFTER processing 1 neighbor(s)\n");
    maze_print_state(maze);
    printf("ret: %d\n",ret);
    maze_free(maze);
  } // ENDTEST

  IF_TEST("maze_bfs_step1") {
    // Performs the intial BFS step iterating over the 4 adjacent
    // tiles to the Start tile which is at the front of the queue in
    // the example. The NORTH, WEST, EAST neighbor tiles should be
    // Found and added into the queue while the SOUTH neighbor is
    // blocked. Logging is on so messages concerning each neighbor
    // should be displayed.
    char *maze_str =
      "###################\n"
      "#          #    # #\n"
      "# ###  ##    ## # #\n"
      "#  ##  # S #  # # #\n"
      "##  #  #####  # # #\n"
      "#E  #         #   #\n"
      "###################\n";
    maze_t *maze = maze_from_string(maze_str);
    maze_bfs_init(maze);
    printf("Maze BEFORE BFS step\n");
    LOG_LEVEL = LOG_ALL;
    maze_print_state(maze);
    int ret = maze_bfs_step(maze);
    printf("step ret: %d\n",ret);
    printf("Maze AFTER BFS step\n");
    maze_print_state(maze);
    maze_free(maze);
  } // ENDTEST
    
  IF_TEST("maze_bfs_step2") {
    // Sets up a BFS that has proceeded a few steps using only stack
    // data and goes one additional step. Ensures that two neighbors
    // are added for the processed node. This test relies on a
    // combination of stack set up in the test and heap data allocated
    // by user functions so may yield some strange effects if
    // allocation is done improperly in functions.
    tile_t rows[5][3] = {
      { {.type=WALL},{.type=WALL}, {.type=START} },// 0
      { {.type=OPEN},{.type=OPEN}, {.type=OPEN}  },// 1
      { {.type=END}, {.type=OPEN}, {.type=WALL}  },// 2
      { {.type=WALL},{.type=OPEN}, {.type=WALL}  },// 3
      { {.type=OPEN},{.type=OPEN}, {.type=OPEN}  },// 4
      //     0            1             2
    };
    tile_t *tiles[5] =
      {rows[0],rows[1],rows[2],rows[3],rows[4]};
    maze_t maze = {.rows=5, .cols=3, .tiles=tiles};
    for(int i=0; i<5; i++){
      for(int j=0; j<3; j++){
        maze.tiles[i][j].state = NOTFOUND;
      }
    }
    tile_t *tile;
    direction_t path02[] = {};
    tile = &maze.tiles[0][2];
    tile->path = path02;
    tile->path_len = 0;
    tile->state = FOUND;
    direction_t path12[] = {SOUTH};
    tile = &maze.tiles[1][2];
    tile->path = path12;
    tile->path_len = 1;
    tile->state = FOUND;
    direction_t path11[] = {SOUTH,WEST};
    tile = &maze.tiles[1][1];
    tile->path = path11;
    tile->path_len = 2;
    tile->state = FOUND;
    maze.queue = rcqueue_allocate();
    rcqueue_add_rear(maze.queue,1,1);
    printf("Maze BEFORE BFS step\n");
    LOG_LEVEL = LOG_ALL;
    maze_print_state(&maze);
    int ret = maze_bfs_step(&maze);
    printf("step ret: %d\n",ret);
    printf("Maze AFTER BFS step\n");
    maze_print_state(&maze);
    free(maze.tiles[1][0].path);
    free(maze.tiles[2][1].path);
    rcqueue_free(maze.queue);
  } // ENDTEST
    
  IF_TEST("maze_bfs_step3") {
    // Perform 3 BFS step calls starting from the Start tile. This
    // will add 3 initial neighbors and then process each in turn
    // adding additional tiles in the second wave. There is some
    // redundancy with neighbors so this test also checks that the
    // FOUND field of tiles is set properly and respected.
    char *maze_str =
      "#########\n"
      "#       #\n"
      "# # S  ##\n"
      "#  # ##E#\n"
      "#       #\n"
      "#########\n";
    maze_t *maze = maze_from_string(maze_str);
    maze_bfs_init(maze);
    printf("Maze BEFORE BFS step\n");
    LOG_LEVEL = LOG_ALL;
    maze_print_state(maze);
    int ret;
    ret = maze_bfs_step(maze);
    printf("step ret: %d\n",ret);
    printf("Maze AFTER BFS step 1\n");
    maze_print_state(maze);
    ret = maze_bfs_step(maze);
    printf("step ret: %d\n",ret);
    printf("Maze AFTER BFS step 2\n");
    maze_print_state(maze);
    ret = maze_bfs_step(maze);
    printf("step ret: %d\n",ret);
    printf("Maze AFTER BFS step 3\n");
    maze_print_state(maze);
    maze_free(maze);
  } // ENDTEST
    


  IF_TEST("maze_bfs_iterate1") {
    // Checks the BFS iteration function to ensure it visits all tiles
    // to obtain paths to each one from the start tile. A small maze
    // is used which has wall tiles around the edges.
    char *maze_str =
      "#####\n"
      "# S #\n"
      "# # #\n"
      "# E #\n"
      "#####\n";
    maze_t *maze = maze_from_string(maze_str);
    printf("Maze BEFORE BFS iteration\n");
    maze_print_state(maze);
    LOG_LEVEL = LOG_ALL;
    maze_bfs_iterate(maze);
    printf("Maze AFTER BFS iteration\n");
    maze_print_state(maze);
    maze_free(maze);
  } // ENDTEST

  IF_TEST("maze_bfs_iterate2") {
    // Checks the BFS iteration function to ensure it visits all tiles
    // to obtain paths to each one from the start tile. A small maze
    // is used without a "bounding wall".
    char *maze_str =
      "S \n"
      "# \n"
      "E \n";
    maze_t *maze = maze_from_string(maze_str);
    printf("Maze BEFORE BFS iteration\n");
    maze_print_state(maze);
    LOG_LEVEL = LOG_ALL;
    maze_bfs_iterate(maze);
    printf("Maze AFTER BFS iteration\n");
    maze_print_state(maze);
    maze_free(maze);
  } // ENDTEST

  IF_TEST("maze_bfs_iterate3") {
    // Checks the BFS iteration function to ensure it visits all tiles
    // to obtain paths to each one from the start tile. A larger maze
    // is used where the end tile is not the last tile to be visited
    // during BFS.
    char *maze_str =
      "###########\n"
      "#S       ##\n"
      "# ### ## ##\n"
      "# ### ## ##\n"
      "# ###E## ##\n"
      "#        ##\n"
      "###########\n";
    maze_t *maze = maze_from_string(maze_str);
    printf("Maze BEFORE BFS iteration\n");
    maze_print_state(maze);
    LOG_LEVEL = LOG_ALL;
    maze_bfs_iterate(maze);
    printf("Maze AFTER BFS iteration\n");
    maze_print_state(maze);
    maze_free(maze);
  } // ENDTEST

  IF_TEST("maze_set_solution1") {
    // Set tile states to ONPATH between the Start and End tiles using
    // the path established during test setup for the End tile.
    char *maze_str =
      "#####\n"
      "# S #\n"
      "# # #\n"
      "# E #\n"
      "#####\n";
    int path_len = 4;
    direction_t path[4] = {WEST,SOUTH,SOUTH,EAST};
    maze_t *maze = maze_from_string(maze_str);
    tile_t *end_tile = &maze->tiles[maze->end_row][maze->end_col];
    end_tile->path_len = path_len;
    end_tile->path = malloc(sizeof(direction_t)*path_len);
    memcpy(end_tile->path, path, sizeof(direction_t)*path_len);
    printf("Maze BEFORE Setting Solution\n");
    maze_print_tiles(maze);
    LOG_LEVEL = LOG_ALL;
    printf("Setting Solution Path\n");
    int ret = maze_set_solution(maze);
    printf("ret: %d\n",ret);
    printf("Maze AFTER Setting Solution\n");
    maze_print_tiles(maze);
    maze_free(maze);
  } // ENDTEST

  IF_TEST("maze_set_solution2") {
    // Set tile states to ONPATH between the Start and End tiles using
    // the path established during test setup for the End tile.
    char *maze_str =
      "################\n"
      "#S             #\n"
      "# ### ###### # #\n"
      "# ### ##E  #   #\n"
      "# ### #### ##  #\n"
      "#              #\n"
      "################\n";
    int path_len = 17;
    direction_t path[17] =
      {SOUTH,SOUTH,SOUTH,SOUTH,EAST,EAST,EAST,EAST,EAST,
       EAST,EAST,EAST,EAST,NORTH,NORTH,WEST,WEST};
    maze_t *maze = maze_from_string(maze_str);
    tile_t *end_tile = &maze->tiles[maze->end_row][maze->end_col];
    end_tile->path_len = path_len;
    end_tile->path = malloc(sizeof(direction_t)*path_len);
    memcpy(end_tile->path, path, sizeof(direction_t)*path_len);
    printf("Maze BEFORE Setting Solution\n");
    maze_print_tiles(maze);
    LOG_LEVEL = LOG_ALL;
    printf("Setting Solution Path\n");
    int ret = maze_set_solution(maze);
    printf("ret: %d\n",ret);
    printf("Maze AFTER Setting Solution\n");
    maze_print_tiles(maze);
    maze_free(maze);
  } // ENDTEST

  IF_TEST("maze_set_solution3") {
    // No path exists from the Start to End tile and the End tile path
    // is NULL in this example so the set_solution() function will
    // return 0 without making any changes to the maze.
    char *maze_str =
      "########\n"
      "#     S#\n"
      "# # ####\n"
      "# #    #\n"
      "# ######\n"
      "#      #\n"
      "###### #\n"
      "# ##   #\n"
      "#E#  # #\n"
      "########\n";
    maze_t *maze = maze_from_string(maze_str);
    tile_t *end_tile = &maze->tiles[maze->end_row][maze->end_col];
    printf("Maze BEFORE Setting Solution\n");
    maze_print_tiles(maze);
    LOG_LEVEL = LOG_ALL;
    printf("Setting Solution Path\n");
    int ret = maze_set_solution(maze);
    printf("ret: %d\n",ret);
    printf("Maze AFTER Setting Solution\n");
    maze_print_tiles(maze);
    maze_free(maze);
  } // ENDTEST

  IF_TEST("maze_bfs_complete1") {
    // Perform BFS iteration on a medium maze then set the solution
    // and print it. Represents similar flow to the main program.
    char *maze_str =
      "###########\n"
      "#S       ##\n"
      "# ### ## ##\n"
      "# ### ## ##\n"
      "# ###E## ##\n"
      "#        ##\n"
      "###########\n";
    maze_t *maze = maze_from_string(maze_str);
    printf("Maze BEFORE BFS iteration\n");
    maze_print_state(maze);
    LOG_LEVEL = LOG_ALL;
    maze_bfs_iterate(maze);
    printf("Maze AFTER BFS iteration\n");
    maze_print_state(maze);
    printf("Maze BEFORE Setting Solution\n");
    maze_print_tiles(maze);
    printf("Setting Solution Path\n");
    int ret = maze_set_solution(maze);
    printf("ret: %d\n",ret);
    printf("Maze AFTER Setting Solution\n");
    maze_print_tiles(maze);
    maze_free(maze);
  } // ENDTEST

  IF_TEST("maze_bfs_complete2") {
    // Perform BFS iteration on a medium maze then set the solution
    // and print it. Represents similar flow to the main program.
    char *maze_str =
      "#########\n"
      "#    #  #\n"
      "# ##S  ##\n"
      "#  # ##E#\n"
      "#       #\n"
      "#########\n";
    maze_t *maze = maze_from_string(maze_str);
    printf("Maze BEFORE BFS iteration\n");
    maze_print_state(maze);
    LOG_LEVEL = LOG_ALL;
    maze_bfs_iterate(maze);
    printf("Maze AFTER BFS iteration\n");
    maze_print_state(maze);
    printf("Maze BEFORE Setting Solution\n");
    maze_print_tiles(maze);
    printf("Setting Solution Path\n");
    int ret = maze_set_solution(maze);
    printf("ret: %d\n",ret);
    printf("Maze AFTER Setting Solution\n");
    maze_print_tiles(maze);
    maze_free(maze);
  } // ENDTEST

  ////////////////////////////////////////////////////////////////////////////////
  // PROBLEM 4 TESTS 5 + 5 main
  ////////////////////////////////////////////////////////////////////////////////

  IF_TEST("maze_from_file_small") {
    // Load a small maze from a file
    LOG_LEVEL = LOG_ALL;
    maze_t *maze = maze_from_file("data/maze-small-twopath1.txt");
    printf("LOADED MAZE:\n");
    maze_print_tiles(maze);
    maze_free(maze);
  } // ENDTEST
  
  IF_TEST("maze_from_file_medium") {
    // Load a medium maze from a file AND perform BFS iteration on it
    // then set the solution for display.
    LOG_LEVEL = LOG_ALL;
    maze_t *maze = maze_from_file("data/maze-medium1.txt");
    printf("LOADED MAZE:\n");
    maze_print_tiles(maze);
    maze_bfs_iterate(maze);
    printf("Maze AFTER BFS iteration\n");
    maze_print_state(maze);
    int ret = maze_set_solution(maze);
    printf("ret: %d\n",ret);
    printf("Maze AFTER Setting Solution\n");
    maze_print_tiles(maze);
    maze_free(maze);
  } // ENDTEST
  
  IF_TEST("maze_from_file_no_file") {
    // Intentionally try to load a file that does not exist to ensure
    // that NULL is returned.
    LOG_LEVEL = LOG_ALL;
    maze_t *maze = maze_from_file("data/no-such-maze.txt");
    printf("maze: %p\n",maze);
  } // ENDTEST

  IF_TEST("maze_from_file_room12") {
    // Load 2 medium mazes from files and print them
    LOG_LEVEL = LOG_ALL;
    maze_t *maze;
    maze = maze_from_file("data/maze-room1.txt");
    printf("LOADED MAZE:\n");
    maze_print_tiles(maze);
    maze_free(maze);
    maze = maze_from_file("data/maze-room2.txt");
    printf("LOADED MAZE:\n");
    maze_print_tiles(maze);
    maze_free(maze);
  } // ENDTEST

  IF_TEST("maze_from_file_big") {
    // Load a large maze from a file
    LOG_LEVEL = 0;              // no logging for this test
    maze_t *maze = maze_from_file("data/maze-big-mult1.txt");
    printf("LOADED MAZE:\n");
    maze_print_tiles(maze);
    maze_free(maze);
  } // ENDTEST

  ////////////////////////////////////////////////////////////////////////////////
  // END MATTER
  ////////////////////////////////////////////////////////////////////////////////
  if(nrun == 0){
    printf("No test named '%s' found\n",test_name);
    return 1;
  }
  else if(nrun > 1){
    printf("%d tests run\n",nrun);
  }

  return 0;
}
