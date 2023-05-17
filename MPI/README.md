# Taller 02

En esta carpeta se encuentran los archivos requeridos en el taller: 
El codigo en C original , su version paralelizada con MPI el archivo ejecutable, un txt del output y el SBACH

Modificaciones del codigo:

Se agregaron las llamadas a las funciones MPI_Init, MPI_Comm_size y MPI_Comm_rank para inicializar MPI y obtener el número total de procesos y el identificador del proceso actual.
Se utilizó la condición if (mod == 0) para solicitar al usuario la entrada necesaria solo en el proceso con identificador 0.
Se utilizó la función MPI_Bcast para transmitir los valores de n, a y b desde el proceso con identificador 0 a todos los demás procesos.
Se modificó el bucle for para dividir el trabajo entre los procesos. Cada proceso calcula la suma de las evaluaciones de la función f(x) en subintervalos específicos.
Se utilizó la función MPI_Reduce para sumar las integrales calculadas por cada proceso y almacenar el resultado total en la variable total del proceso con identificador 0.
Se agregó la llamada a MPI_Finalize para finalizar MPI antes de que el programa termine.

Comparación entre los tres códigos: el secuencial, el paralelo con OpenMP y el paralelo con MPI: 

Si el trabajo computacional es suficientemente grande y el número de subintervalos es grande, el enfoque paralelo con MPI puede tener un mejor rendimiento en términos de tiempo de ejecución y aceleración. MPI permite aprovechar los recursos de múltiples nodos de un clúster de computadoras para distribuir la carga de trabajo y realizar cálculos en paralelo.
Por otro lado, si el trabajo computacional es más pequeño y el número de subintervalos es limitado, el enfoque paralelo con OpenMP puede ser más eficiente debido a la menor sobrecarga de comunicación entre los hilos y la menor latencia en comparación con el enfoque distribuido de MPI.

