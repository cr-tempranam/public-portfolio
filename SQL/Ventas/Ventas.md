# BASE DE DATOS "VENTAS"


#### OBJETIVO
El propósito de esta práctica es realizar algunas consultas a la base de datos de ventas y productos.

#### PROCEDIMIENTO
Contando con la base de datos de `SQLite` sobre ventas, se creó el modelo vinculando las tablas a través de las *foreing key*  como se ve en el diagrama de abajo. Posteriormente se obtuvieron los resultados de las consultas realizadas.

![data_model](https://github.com/cr-tempranam/public-portfolio/blob/develop/SQL/Ventas/img/data_model.png)


- La primera consulta consiste en saber cuáles fueron las unidades compradas por cada cliente. Se busca saber el nombre del cliente y sus compras realizadas ordenadas de mayor a menor por esos totales. 

```
SELECT c.nombre, SUM(dv.cantidad * p.precio) as TOTAL
FROM ventas v
JOIN detalle_venta dv ON dv.id_venta = v.id_venta
JOIN productos p on dv.id_producto = p.id_producto
JOIN clientes c on v.id_cliente = c.id_cliente
GROUP BY c.nombre
ORDER BY TOTAL desc;
```
![Query1](https://github.com/cr-tempranam/public-portfolio/blob/develop/SQL/Ventas/img/Query1.jpeg)


- Luego se busca conocer cuáles son aquellos productos con la mayor cantidad de unidades vendidas, ordenadas desde el más vendido al de menos ventas. Se solicita el número identificador de producto, su nombre y las unidades vendidas de cada uno.

```
SELECT p.id_producto, p.nombre, SUM(dv.cantidad) as TOTAL_CANTIDAD_VENDIDA
FROM ventas v
JOIN detalle_venta dv ON dv.id_venta = v.id_venta
JOIN productos p on dv.id_producto = p.id_producto
JOIN clientes c on v.id_cliente = c.id_cliente
GROUP BY dv.id_producto
ORDER BY TOTAL_CANTIDAD_VENDIDA desc;
```

![Query2](https://github.com/cr-tempranam/public-portfolio/blob/develop/SQL/Ventas/img/Query2.jpeg)


- Por último, se necesita hacer la misma búsqueda que la anterior pero para ventas transcurridas entre el 01/01/2025 y el 01/04/2025, y de entre ellas armar un top ten de los productos más vendidos. Para ello mostrar además de los campos anteriores, un campo que haga referencia al número de puesto.

```
SELECT ROW_NUMBER() OVER (ORDER BY SUM(dv.cantidad) desc) AS PUESTO,
p.id_producto, p.nombre, SUM(dv.cantidad) as TOTAL_CANTIDAD_VENDIDA
FROM ventas v
JOIN detalle_venta dv ON dv.id_venta = v.id_venta
JOIN productos p on dv.id_producto = p.id_producto
JOIN clientes c on v.id_cliente = c.id_cliente

WHERE '2025-01-01' <= v.fecha AND v.fecha < '2025-04-01'

GROUP BY dv.id_producto
ORDER BY TOTAL_CANTIDAD_VENDIDA desc
LIMIT 10;
```

![Query3](https://github.com/cr-tempranam/public-portfolio/blob/develop/SQL/Ventas/img/Query3.jpeg)
