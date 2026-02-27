# Proyectos en C
Los archivos a continuación son una serie de prácticas de contenidos básicos implementados en el lenguaje de programación C. 

Cada uno de los archivos desarrolla distintos puntos de la lógica de programación.

### 1) Tablero de Ajedrez

En el archivo [functions-chess.c](https://github.com/cr-tempranam/public-portfolio/blob/develop/C/1-functions-chess.c) se crea un *tablero de ajedrez* utilizando funciones.

Se usa la función `void createChessLine(int scale, int line)` que genera una línea alternada de cruces y espacios simulando "blancas y negras". 

A su vez, a esta función se la incluye dentro de otra llamada `createChessBoard(int scale)` que crea cada una de las siguientes líneas del tablero hasta completar la misma cantidad de columnas que de filas, utilizando bucles. 

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

En la imagen se muestra como a través de un bucle de imprimen los valores de la sucesión hasta un **n** dado.

### 4) Divide y Vencerás

En [divide-and-conquer.c](https://github.com/cr-tempranam/public-portfolio/blob/develop/C/4-divide-and-conquer-recursion.c) se utiliza recursividad para obtener un valor mínimo dentro de un array. Se define un array de LENGTH valores enteros.

La función `int min(int v[], int l)` divide el array en dos de manera repetida (recursiva) hasta llegar a un caso base donde quedan dos o un elemento.

Llegada esta instancia, considera los valores del array de a dos, evaluando entre ellos cual es el menor y el "ganador" sigue en competencia y se lo compara con el valor siguiente. 


![divide-and-conquer](https://github.com/cr-tempranam/public-portfolio/blob/develop/C/img/4-divide-and-conquer.png)

En la imagen se pueden ver los valores ingresados en el array y cuál es el menor valor según la función. 


![recursion](https://github.com/cr-tempranam/public-portfolio/blob/develop/C/img/4-recursion.png)

En esta imagen se muestra mediante un diagrama de árbol, como se divide el array hasta llegar a los casos base y como va comparando los valores de a dos hasta llegar a la cima. 

### 5) Punteros a función

El archivo [function-pointers.c](https://github.com/cr-tempranam/public-portfolio/blob/develop/C/5-function-pointers.c) contiene un ordenador de elementos almacenados según un criterio a elección.

Inicia con un `typedef struct` que crea un tipo de dato que contendrá un Id, apellido, nombre y edad de usuario. Para el apellido y nombre, al ser elementos alfabéticos, se define la longitud máxima de caracteres que podrá contener.

Luego se crea un comparador que recibirá dos elementos con el mismo tipo de dato para compararlos.

Continua con la función de ordenamiento `void sortArray(void* v[], int l, Comparer cmp, int asc)` que recibirá un array de punteros a elementos, la longitud del array, la función de comparación, y el criterio de ordenamiento (ascendente o descendente)

Esta función va tomando de a dos elementos, los compara según el criterio y los cambia de lugar según el ordenamiento. 

Después están las distintas funciones de comparación según el tipo de dato, por ejemplo `int compareByAge(void* x, void* y)`. Concretamente las que refieren a elementos alfabéticos, como `int compareByLastName(void* x, void* y)`, comparan letra por letra para que el ordenamiento sea correcto. 

Por último, se crearon usuarios con los datos definidos en la struct, se creó la array de punteros a estos usuarios, se llamó a la función de ordenamiento según un comparador y un criterio, y se utiliza un bucle para imprimir todos los usuarios con sus elementos según el nuevo orden asignado.

![sort-array](https://github.com/cr-tempranam/public-portfolio/blob/develop/C/img/5-sort-array.png)

En la imagen se observa el listado de usuarios ordenados por su edad de menor a mayor.  

### 6) Array Dinamico

El archivo [dynamic-array.c](https://github.com/cr-tempranam/public-portfolio/blob/develop/C/6-dynamic-array.c) utiliza la memoria dinámica como una manera transitoria de almacenar una serie de calificaciones para obtener ciertos resultados.

Inicia creando algunas funciones matemáticas y estadísticas como lo son el `promedio`, la `potencia`, la `varianza` y la `desviación estándar`.

Se define una cantidad de *n* calificaciones a considerar y se las carga en un array a través de un string.

Luego a través del `malloc` se pide memoria dinámica donde se almacena este string con las calificaciones.
 
Se utilizan las funciones creadas y se imprimen los resultados por pantalla. Por último se libera el espacio ocupado en la memoria dinámica.

![dynamic-array](https://github.com/cr-tempranam/public-portfolio/blob/develop/C/img/6-dynamic-array.png)

En la imagen podemos observar el listado de calificaciones, la nota más alta, la más baja, la nota promedio y el desvió estándar.

### 7) Array dinámico de punteros a estructura
En el archivo [dynamic-struct-array.c](https://github.com/cr-tempranam/public-portfolio/blob/develop/C/7-dynamic-struct-array.c) se implementa un array guardado en la memoria dinámica que contiene punteros a estructuras de usuarios.

Inicia con la creación del tipo de dato `User` a través de `typedef struct`. Dentro de esta estructura existen dos valores enteros (int) y dos punteros a char (strings). 

Se define la cantidad de usuarios que tendrá la lista. Se inicializa un array (`char data[]`) que contiene un string con todos los usuarios separando los datos por comas y a los usuarios por "\n".

Luego se solicita múltiples espacios en la memoria dinámica usando `malloc`. Primero para el array de punteros a usuarios (estructura), luego para los usuarios en si, y por ultimo para los char apuntados por la estructura (apellidos y nombres).

Se almacena la información en los respectivos espacios de memoria y se imprimen los resultados por consola como se muestra a continuación. 

![dynamic-struct-array](https://github.com/cr-tempranam/public-portfolio/blob/develop/C/img/7-dynamic-struct-array.png)

Por último, usando `free` se libera el espacio ocupado en la memoria dinámica en el orden inverso a como se pidió, es decir que primero libera lo ocupado por los string (char) y las estructuras de cada usuario, y al final el array de punteros a estructuras.

### 8) Sistemas de ecuaciones
En el archivo [ecuation-systems.c](https://github.com/cr-tempranam/public-portfolio/blob/develop/C/8-ecuation-systems.c) se resuelve un sistema de tres ecuaciones con tres incógnitas utilizando el método de determinantes.

Se inicia creando algunas funciones necesarias para la resolución. 
- `int** crearMatriz(int n)` pide espacio en la memoria dinámica para una matriz de *n x n* elementos. A su vez, asigna el valor cero en esas ubicaciones.

- Luego la función `int det(int **A)` que calcula el determinante de una matriz de tres por tres. 

- `void freeMatriz(int **A, int n)` libera los valores solicitados a la memoria dinámica y `void copiarMatriz(int **A, int **AD, int n)` recibe una matriz A y copia los valores de ella en otra matriz B.

- La función `int** crearAdjunta(int **A, int b[],int n, int c)` crea una matriz adjunta necesaria para el cálculo por método de determinantes. 

- La última función es `double *resolve(int **A, int *b, int n)` que obtienen los valores de las variables incógnitas. 

Para resolver el sistema de ecuaciones se usa `crearMatriz(n)` y se pide memoria para un vector *b* que representa los resultados en el sistema de ecuaciones y se cargan los valores en cada unos de los vectores de *A* y *b*.

Se utiliza `resolve` con los parámetros de A, b y n y se guarda lo obtenido en un vector de resultados. 

![ecuation systems](https://github.com/cr-tempranam/public-portfolio/blob/develop/C/img/8-ecuation-systems.png)

Finalmente, como se ve en la imagen, se imprime por pantalla los resultados y luego se libera los espacios ocupados en la memoria dinámica.
