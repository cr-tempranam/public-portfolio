# PROYECTO “CPCE S.A”


#### OBJETIVO
El presente proyecto consiste en el analisis de datos de la empresa CPCE S.A. La misma proporcionó una base de datos de Ventas, Clientes y Productos, para un periodo determinado.
El objetivo del proyecto consiste en presentar una serie de tableros con informacion importante destinadas a las áreas de Marketing, Comercial y Almacenamiento. 
Se busca que los mismos estén acompañados de propuestas sugeridas basadas en lo recopilado por dichos tableros. 

#### PROCEDIMIENTO
Se inicia importando las bases de datos proporcionadas a Power BI Desktop, realizando las correspondientes transformaciones, ediciones y ocultando aquellas columnas que no se consideraron relevantes al proceso. Se detecta que existen relaciones entre algunos elementos de las tablas, las cuales son plasmadas en la vista de modelo. 
Posteriormente se incorporaron nuevas columnas con cálculos adicionales necesarios para el analisis. Tanto para las transformaciones como para la creación de columnas adicionales se implementó Power Qwery. 
Se comienza a pensar en los indicadores más adecuados y se eligen que objetos visuales reflejan mejor los resultados. Por último se diagrama la estructura de la presentación, la paleta de colores y se plantean las sugerencias correspondientes.

#### DASHBOARD
En el tablero `comercial` se apunta a mostrar valores y resultados asociados a ventas, utilidades, y costas. Se observa como partida un filtro segmentador por los paises que se desea ver y la distribucion de ventas totales por pais. Tambien se incluyen tarjetas que refieren a ventas totales, utilidades obtenidas y costos totales de esas ventas. 
Se muestra ademas un pequeño indicador con el margen de ganancia promedio que se obtiene por categoria de producto, la evolución de las ventas por mes, un comparador de ventas, costas y utilidades por mes y su variación diaria a travez de un grafico de lineas intentando detectar algun tipo de comportamiento temporal.
![comercial](https://github.com/cr-tempranam/public-portfolio/blob/develop/PowerBI/Proyecto-CPCESA/img/dashboard-1.png)

![marketing](https://github.com/cr-tempranam/public-portfolio/blob/develop/PowerBI/Proyecto-CPCESA/img/dashboard-2.png)

![stock](https://github.com/cr-tempranam/public-portfolio/blob/develop/PowerBI/Proyecto-CPCESA/img/dashboard-3.png)