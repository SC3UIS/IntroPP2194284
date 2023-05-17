/*********************************
 ********TRAPEZOIDAL RULE*********
  2017 (c) Manas Sharma - https://bragitoff.com
  2023 (modified) C. Barrios 
  2023 (modified) Fabian Sanchez
 ********************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <mpi.h>

/* Define the function to be integrated here: */
double f(double x) {
  return x * x;
}

int main(int argc, char **argv) {
  int n, i, mod, numpro;
  double a, b, h, x, sum = 0, integral, total;

  /* Initialize MPI */
  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &numpro);
  MPI_Comm_rank(MPI_COMM_WORLD, &mod);

  /* Ask the user for necessary input */
  if (mod == 0) {
    printf("\nEnter the number of sub-intervals: ");
    scanf("%d", &n);
    printf("\nEnter the initial limit: ");
    scanf("%lf", &a);
    printf("\nEnter the final limit: ");
    scanf("%lf", &b);
  }

  /* Broadcast the values of n, a, and b to all processes */
  MPI_Bcast(&n, 1, MPI_INT, 0, MPI_COMM_WORLD);
  MPI_Bcast(&a, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);
  MPI_Bcast(&b, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);

  /* Begin Trapezoidal Method */
  h = fabs(b - a) / n;
  for (i = mod + 1; i < n; i += numpro) {
    x = a + i * h;
    sum += f(x);
  }
  integral = (h / 2) * (f(a) + f(b) + 2 * sum);

  /* Sum up the integrals calculated by each process */
  MPI_Reduce(&integral, &total, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

  /* Print the answer */
  if (mod == 0) {
    printf("\nThe integral is: %lf\n", total);
  }

  /* Finalize MPI */
  MPI_Finalize();
  return 0;
}
