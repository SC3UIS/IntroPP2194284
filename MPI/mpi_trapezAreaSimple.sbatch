#!/bin/bash

#SBATCH --job-name=mpi_integration
#SBATCH --nodes=2
#SBATCH --ntasks-per-node=1
#SBATCH --cpus-per-task=8




## modulos cargados
module load devtools/gcc/6.2.0
module load devtools/mpi/openmpi/3.1.4

## ejecuccion con mpi
mpicc mpi_trapezAreaSimple.c -o outputmpi_trapezAreaSimple


## Ejecucion del programa, variables de entrada y salida en un txt
echo "6 1 4" | ./outputmpi_trapezAreaSimple > outputmpi_trapezAreaSimple.txt