# Proyectos en C
Los archivos a continuación son una serie de practicas de contenidos básicos implementados en el lenguaje de programación C. 

Cada uno de los archivos desarrolla distintos puntos de la logica de programación.

### 1) Tablero de Ajedrez

En el archivo [functions-chess.c](https://github.com/cr-tempranam/public-portfolio/blob/develop/C/1-functions-chess.c) se crea un *tablero de ajedrez* utilizando funciones.

Se usa la función `void createChessLine(int scale, int line)` que genera una linea alternada de cruces y espacios simulando "blancas y negras". 

A su vez, a esta función se la incluye dentro de otra llamada `createChessBoard(int scale)` que crea cada una de las siguientes lineas del tablero hasta completar la misma cantidad de columnas que de filas, utilizando bucles. 

Por último, cabe destacar que el mismo tablero es escalable, es decir que se puede adaptar la cantidad de cruces o espacios que se desee que tenga el tablero. 

![chess-board](https://github.com/cr-tempranam/public-portfolio/blob/develop/C/img/1-chess-board.png)


### 2) Serie de Taylor

En el archivo [functions-calculus.c](https://github.com/cr-tempranam/public-portfolio/blob/develop/C/2-functions-calculus.c) se aproxima el cálculo de la función exponencial **e^x** mediante Serie de Taylor utilizando `double serieTaylor(double x, int N)`. La aproximación se realiza utilizando un polinomio de grado **N**.

Para el cálculo de la serie de Taylor se utilizan funciones auxiliares `long factorial(int n)` y `double potencia(double x, int n)`.

![taylor-ex](https://github.com/cr-tempranam/public-portfolio/blob/develop/C/img/2-taylor-ex.png)

En la imagen se observa como a mayor grado de polinomio N mejor será la aproximación. 

### 3) Sucesión de Fibonacci

El archivo [recursion-fibonacci.c](https://github.com/cr-tempranam/public-portfolio/blob/develop/C/3-recursion-fibonacci.c) utiliza la recursividad para obtener los valores que se obtienen de la Sucesión de Fibonacci.

Se puede observar en `int fibonacci(int n)` que la función se llama a si misma para los dos valores anteriores de la sucesión. A su vez se definen dos casos base para detener la recursividad de la función.

![fibonacci](https://github.com/cr-tempranam/public-portfolio/blob/develop/C/img/3-fibonacci.png)
En la imagen se muestra como a travez de un bucle de imprimen los valores de la sucesión hasta un **n** dado