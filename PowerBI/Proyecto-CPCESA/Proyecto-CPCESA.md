# PROYECTO “CPCE S.A”


#### OBJETIVO
El presente proyecto consiste en el análisis de datos de la empresa CPCE S.A. La misma proporcionó una base de datos de Ventas, Clientes y Productos para un periodo determinado.
El objetivo del proyecto consiste en presentar una serie de tableros con información importante destinadas a las áreas de Marketing, Comercial y Almacenamiento. 
Se busca que los mismos estén acompañados de propuestas sugeridas basadas en lo recopilado por dichos tableros. 

#### PROCEDIMIENTO
Se inicia importando las bases de datos proporcionadas a Power BI Desktop, realizando las correspondientes transformaciones, ediciones y ocultando aquellas columnas que no se consideraron relevantes al proceso. Se detecta que existen relaciones entre algunos elementos de las tablas, las cuales son plasmadas en la vista de modelo. 

![tablas_relaciones](https://github.com/cr-tempranam/public-portfolio/blob/develop/PowerBI/Proyecto-CPCESA/img/tablas_relaciones.png)

Posteriormente se incorporaron nuevas columnas con cálculos adicionales necesarios para el análisis. Tanto para las transformaciones como para la creación de columnas adicionales se implementó Power Query. 

![Power_Query](https://github.com/cr-tempranam/public-portfolio/blob/develop/PowerBI/Proyecto-CPCESA/img/Power_Query.png)

Se comienza a pensar en los indicadores más adecuados y se eligen qué objetos visuales reflejan mejor los resultados. Por último se diagrama la estructura de la presentación, la paleta de colores y se plantean las sugerencias correspondientes.

#### DASHBOARD
En el tablero `comercial` se apunta a mostrar valores y resultados asociados a ventas, utilidades y costas. Se observa como partida un filtro segmentador por los países que se desea ver y la distribución de ventas totales por país. Tambien se incluyen tarjetas que refieren a ventas totales, utilidades obtenidas y costos totales de esas ventas. 
Se muestra además un pequeño indicador con el margen de ganancia promedio que se obtiene por categoría de producto, la evolución de las ventas por mes, un comparador de ventas, costas y utilidades por mes y su variación diaria a través de un gráfico de líneas temporales.
Este tablero constituye una base para estudiar el comportamiento de las ventas por países y detectar si existen factores asociados a cuestiones geográficas, económicas, o relacionadas a una cuestión de tiempo.

![comercial](https://github.com/cr-tempranam/public-portfolio/blob/develop/PowerBI/Proyecto-CPCESA/img/dashboard-1.png)


En el tablero `marketing` se puede observar la distribución de las ventas totales por diferentes criterios como lo son el estado civil de los clientes, su género, y el país de origen. 
Además se visualizan una serie de tablas que reflejan un top ten de los productos con mayor utilidad generada, los más vendidos, y los menos vendidos.
Tambien dos tablas con los top ten de los mejores clientes según la cantidad de unidades vendidas y los montos totales de compra. 
Toda esta información está orientada establecer esquemas de beneficios para compradores, promociones para incrementar las ventas de los productos menos vendidos y mejorar las ventas de aquellos con mayor utilidad. 


![marketing](https://github.com/cr-tempranam/public-portfolio/blob/develop/PowerBI/Proyecto-CPCESA/img/dashboard-2.png)


Por ultimo en el tablero `stock`, se buscó orientar el análisis a la disponibilidad, conveniencia logística y económica de tener cada producto.  Para ello se implementó un esquema jerárquico para visualizar las ventas de productos por categorías y subcategorías. 
Tambien una serie de tablas indicando el porcentaje de ganancias que representan los productos sobre las ventas totales, las ventas en unidades por mes, unidades en stock y unidades vendidas. 

![stock](https://github.com/cr-tempranam/public-portfolio/blob/develop/PowerBI/Proyecto-CPCESA/img/dashboard-3.png)

