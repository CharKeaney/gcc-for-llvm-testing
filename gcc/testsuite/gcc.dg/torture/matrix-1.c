/* { dg-do run } */
/* { dg-options "-fwhole-program" } */
/* { dg-additional-options "-Wno-ignored-optimization-argument" } */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void mem_init (void);
int ARCHnodes, ARCHnodes1;
int ***vel;

/* The whole matrix VEL is flattened (3 dimensions).  */
/*--------------------------------------------------------------------------*/

int
main (int argc, char **argv)
{
  int i, j, k, id;

  ARCHnodes = 2;
  ARCHnodes1 = 4;

/* Dynamic memory allocations and initializations */
  mem_init ();

  for (i = 0; i < ARCHnodes; i++)
    {
      for (j = 0; j < 3; j++)
	{
	  for (k = 0; k < ARCHnodes1; k++)
	    printf ("[%d][%d][%d]=%d ", i, j, k, vel[i][j][k]);
	  printf ("\n");
	}
      printf ("\n");
    }
  for (i = 0; i < ARCHnodes; i++)
    for (j = 0; j < 3; j++)
      free (vel[i][j]);

  for (i = 0; i < ARCHnodes; i++)
    free (vel[i]);

  free (vel);
  return 0;
}

/*--------------------------------------------------------------------------*/
/* Dynamic memory allocations and initializations                           */

void
mem_init (void)
{

  int i, j, k,d;
 
  d = 0;
  vel = (int ***) malloc (ARCHnodes * sizeof (int **));

  for (i = 0; i < ARCHnodes; i++)
    {
      vel[i] = (int **) malloc (3 * sizeof (int *));
      if (vel[i] == (int **) NULL)
	{
	  printf ("malloc failed for vel[%d]\n", i);
	  exit (0);
	}
    }
  for (i = 0; i < ARCHnodes; i++)
    {
      for (j = 0; j < 3; j++)
	{
	  vel[i][j] = (int *) malloc (ARCHnodes1 * sizeof (int));
	}
    }
  for (i = 0; i < ARCHnodes; i++)
    {
      for (j = 0; j < 3; j++)
	{
	  for (k = 0; k < ARCHnodes1; k++)
	    {
	      vel[i][j][k] = d;
	      d++;
	    }
	}
    }
}

/*--------------------------------------------------------------------------*/
