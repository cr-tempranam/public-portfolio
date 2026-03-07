# PRACTICO FUNCIONES DAX


#### OBJETIVO
A través de este practico se busca incorporar el uso de las funciones `DAX` para obtener indicadores en Power BI. Estas funciones son `CALCULATE`, `AVERAGE` y `COUNT`.
Para ello se trabajó con una base de datos de ventas de productos en Estados Unidos.

#### DASHBOARD
Utilizando la función `AVERAGE(Table1[Sales])` podemos calcular el promedio de ventas por transacciones realizadas. A partir de ella se puede calcular como en el ejemplo el promedio general de ventas, el promedio por región y por subcategoría de producto.

Por medio de `COUNT` podemos contar cantidades pero mediante `DISTINCTCOUNT(Table1[Customer Name])` podemos contar cantidades sin repetir elementos. Con esta función se cuenta los clientes únicos que hay en la base de datos y puede determinar el promedio por región general. 

Por último, usando la función `CALCULATE` podemos calcular una determinada medida o función bajo un filtro o criterio especificado. En `CALCULATE([Promedio de vta x transacción],Table1[Región]="East")` se calculó el promedio de ventas realizadas bajo el criterio de que se hicieron en la región *East*. Luego se usó la misma medida pero con el criterio *West*. 

Para finalizar se calculó la variación porcentual entre *East* y *West* mediante las 2 funciones anteriores. Resulta interesante observar el comportamiento del grafico que refleja estas variaciones porcentuales según la subcategoría de producto.


![dashboard](https://github.com/cr-tempranam/public-portfolio/blob/develop/PowerBI/Funciones-DAX/img/dashboard.png)