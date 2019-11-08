#include <stdio.h>
#include <stdlib.h>

struct point {
  int      x;
  int      y;
};

struct rect {
  struct point  p1;
  struct point  p2;
};

struct square {
  struct point  p1;
  int           len;
};

struct triangle {
  struct point  p1;
  struct point  p2;
  struct point  p3;
};

struct shapes {
  int      type;
  union {
    struct rect      rect;
    struct square    sq;
    struct triangle  tri;
  } shape;
};

enum shape_type {SQUARE = 1, RECTANGLE, TRIANGLE};

int main(int argc, char **argv)
{
  struct shapes   figure;
  struct square  *sq;

  printf("Enter the shape to draw (1=square, 2=rectangle, 3=triangle): ");
  scanf("%d", &figure.type);

  switch (figure.type) {
    case 1:
      sq = &figure.shape.sq;
      printf("Enter left-bottom coordinates of the square: ");
      scanf("%d %d", &sq->p1.x, &sq->p1.y);
      printf("Enter length of the side: ");
      scanf("%d", &sq->len);

      printf("Bottom-left corner at (%d, %d) with a side of length %d\n", 
          sq->p1.x, sq->p1.y, sq->len);

      break;

    default:
      printf("Not yet implemented\n");
      break;
  }

  exit(0);
}