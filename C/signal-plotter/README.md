## SERIES DE FOURIER

### *Generador de Señal*

En la carpeta `signal plotter` se observan un conjunto de archivos que componen un graficador de series de Fourier a través de señales senoidal, cuadrada y triangular.

Como punto de partida, el archivo [signal-generator.c](https://github.com/cr-tempranam/public-portfolio/blob/develop/C/signal-plotter/signal-generator.c) inicia con un typedef que simplifica el nombre de un puntero a función que recibe algunos parámetros y devuelve un `double`. 

Luego se definen las funciones que calculan las señales senoidal `double SenoidalSignal(double A, double f, int N, double t)`, cuadrada `double SquareSignal(double A, double f, int N, double t)` y triangular `double TriangularSignal(double A, double f, int N, double t)`.

En el `main` se definen valores de los parámetros por defecto, se crea un array de punteros a las funciones de señal, y se validan los parametros ingresados por el usuario en caso de cambiarlos a través de CLA (Argumentos de Línea de Comandos).

![pruebas graficador](https://github.com/cr-tempranam/public-portfolio/blob/develop/C/signal-plotter/img/pruebas_graficador.png)

Si a través de CLA se ingresaron parámetros, como se muestran en los ejemplos de la imagen, la función trabaja con estos valores. De lo contrario, se ejecuta con los valores por defecto cargados en el `main`.

Continua con un `for` que imprime por consola las coordenadas para los valores de tiempo (entre 0 y 1) y valores de la señal como muestra la siguiente imagen.

![salida-generador](https://github.com/cr-tempranam/public-portfolio/blob/develop/C/signal-plotter/img/salida_generador.png)


### *Graficador*

El archivo [plotter.c](https://github.com/cr-tempranam/public-portfolio/blob/develop/C/signal-plotter/plotter.c) inicia definiendo un tipo de dato `Point` que tiene dos valores `double`. 

Luego está la función `char** crearMatriz(int n, int m)` que se encarga de pedir memoria dinámica para almacenar una matriz de *n x m* que contendrá los resultados obtenidos, pero al inicio almacena el valor cero en todos los espacios.

Sigue `void GeneratePbmFile(char** M, int W, int H)` que imprime los valores de la matriz dinámica en un archivo `output.pbm`. Si existe el archivo lo reescribe, de lo contrario lo crea y guarda esos valores. 

Se pide memoria para un array de puntos. A través del ` while (fgets(line, 100, stdin) != NULL)` se va leyendo línea por línea el *standard input*, obteniendo las coordenadas de tiempo y señal y los almacena en el array de puntos. Además incluye un contador donde si la cantidad de valores excede a los 100, solicita 50 lugares más para el array.

Se define el tamaño de la imagen en 200 x 200 px, se crea una matriz de igual tamaño que se almacena en la memoria dinámica. 

Por último, el `for` revisa los valores del array de puntos y los escala al tamaño de la imagen final. 

Donde en la matriz existan valores distintos de 0 tanto en *y* como en *x*, guarda un 1.  Se utiliza el `GeneratePbmFile` y listo. 

A continuación se pueden visualizar algunas de las imágenes generadas a través del graficador para los distintos tipos de señales, cambiando a través de `CLA` los valores de los parámetros `tipo de señal, amplitud, frecuencia, y cantidad de armónicos`. 


Señales Senoidales.

![senoidal](https://github.com/cr-tempranam/public-portfolio/blob/develop/C/signal-plotter/img/senoidal_0.png)
![senoidal](https://github.com/cr-tempranam/public-portfolio/blob/develop/C/signal-plotter/img/senoidal_1.png)
![senoidal](https://github.com/cr-tempranam/public-portfolio/blob/develop/C/signal-plotter/img/senoidal_2.png)
![senoidal](https://github.com/cr-tempranam/public-portfolio/blob/develop/C/signal-plotter/img/senoidal_3.png)
![senoidal](https://github.com/cr-tempranam/public-portfolio/blob/develop/C/signal-plotter/img/senoidal_4.png)
![senoidal](https://github.com/cr-tempranam/public-portfolio/blob/develop/C/signal-plotter/img/senoidal_5.png)


Señales Cuadradas.

![cuadrada](https://github.com/cr-tempranam/public-portfolio/blob/develop/C/signal-plotter/img/cuadrada_0.png)
![cuadrada](https://github.com/cr-tempranam/public-portfolio/blob/develop/C/signal-plotter/img/cuadrada_1.png)
![cuadrada](https://github.com/cr-tempranam/public-portfolio/blob/develop/C/signal-plotter/img/cuadrada_2.png)
![cuadrada](https://github.com/cr-tempranam/public-portfolio/blob/develop/C/signal-plotter/img/cuadrada_3.png)
![cuadrada](https://github.com/cr-tempranam/public-portfolio/blob/develop/C/signal-plotter/img/cuadrada_4.png)
![cuadrada](https://github.com/cr-tempranam/public-portfolio/blob/develop/C/signal-plotter/img/cuadrada_5.png)


Señales Triangulares.

![triangular](https://github.com/cr-tempranam/public-portfolio/blob/develop/C/signal-plotter/img/triangular_0.png)
![triangular](https://github.com/cr-tempranam/public-portfolio/blob/develop/C/signal-plotter/img/triangular_1.png)
![triangular](https://github.com/cr-tempranam/public-portfolio/blob/develop/C/signal-plotter/img/triangular_2.png)
![triangular](https://github.com/cr-tempranam/public-portfolio/blob/develop/C/signal-plotter/img/triangular_3.png)
![triangular](https://github.com/cr-tempranam/public-portfolio/blob/develop/C/signal-plotter/img/triangular_4.png)
![triangular](https://github.com/cr-tempranam/public-portfolio/blob/develop/C/signal-plotter/img/triangular_5.png)

