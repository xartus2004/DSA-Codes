#include <stdio.h>
#include <stdlib.h>

char matrix[3][3];
char check(void);

/* Initialize the matrix. */
void init_matrix(void) {
  for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++)
        matrix[i][j] = ' ';
}

/* Get a player's move. */
void get_player_move(void) {
  int x, y;

  printf("Enter X,Y coordinates for your move: ");
  scanf("%d%*c%d", & x, & y);
  x--;
  y--;

  if (matrix[x][y] != ' ') {

    printf("Invalid move, try again.\n");
    get_player_move();
  } 
  else matrix[x][y] = 'X';
}

/* Get a move from the computer. */
void get_computer_move(void) {
  int i, j;
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++)
      if (matrix[i][j] == ' ') break;
    if (matrix[i][j] == ' ') break;

  }

  if (i * j == 9) {
    printf("draw\n");
    exit(0);
  } else
    matrix[i][j] = 'O';
}

/* See if there is a winner. */
char check(void) {
  int i;

  for (i = 0; i < 3; i++) /* check rows */
    if (matrix[i][0] == matrix[i][1] &&
      matrix[i][0] == matrix[i][2]) return matrix[i][0];
  for (i = 0; i < 3; i++) /* check columns */
    if (matrix[0][i] == matrix[1][i] &&
      matrix[0][i] == matrix[2][i]) return matrix[0][i];
  /* test diagonals */
  if (matrix[0][0] == matrix[1][1] &&
    matrix[1][1] == matrix[2][2])
    return matrix[0][0];
  if (matrix[0][2] == matrix[1][1] &&

    matrix[1][1] == matrix[2][0])
    return matrix[0][2];
  return ' ';
}

int main(void) {
    char done;
    printf("This is the game of Tic Tac Toe.\n");
    printf("You will be playing against the computer.\n");
    done = ' ';
    init_matrix();
    do {
        disp_matrix();
        get_player_move();
        done = check(); /* see if winner */
        if (done != ' ') break; /* winner!*/
        get_computer_move();
        done = check(); /* see if winner */
    } while (done == ' ');
    if (done == 'X') printf("You won!\n");
    else printf("I won!!!!\n");
    disp_matrix(); /* show final positions */
    return 0;
}