# Taller 02

En esta carpeta se encuentran los archivos requeridos en el taller: 
El codigo en C original , su version paralelizada con MPI el archivo ejecutable, un txt del output y el SBACH

Modificaciones del codigo:

Se agregaron las llamadas a las funciones MPI_Init, MPI_Comm_size y MPI_Comm_rank para inicializar MPI y obtener el número total de procesos y el identificador del proceso actual.
Se utilizó la condición if (myid == 0) para solicitar al usuario la entrada necesaria solo en el proceso con identificador 0.
Se utilizó la función MPI_Bcast para transmitir los valores de n, a y b desde el proceso con identificador 0 a todos los demás procesos.
Se modificó el bucle for para dividir el trabajo entre los procesos. Cada proceso calcula la suma de las evaluaciones de la función f(x) en subintervalos específicos.
Se utilizó la función MPI_Reduce para sumar las integrales calculadas por cada proceso y almacenar el resultado total en la variable total del proceso con identificador 0.
Se agregó la llamada a MPI_Finalize para finalizar MPI antes de que el programa termine.
