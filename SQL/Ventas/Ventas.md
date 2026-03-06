# BASE DE DATOS "VENTAS"


#### OBJETIVO
La finalidad de este informe es analizar el comportamiento de las ventas de toda la línea de productos y en todas las provincias durante el periodo 2025.

#### PROCEDIMIENTO
```
SELECT v.id_venta, v.fecha, c.nombre, p.nombre, dv.cantidad, p.precio, dv.cantidad * p.precio as TOTAL
FROM ventas v
JOIN detalle_venta dv ON dv.id_venta = v.id_venta
JOIN productos p on dv.id_producto = p.id_producto
JOIN clientes c on v.id_cliente = c.id_cliente
ORDER BY v.fecha;
```


```
SELECT c.nombre, SUM(dv.cantidad * p.precio) as TOTAL
FROM ventas v
JOIN detalle_venta dv ON dv.id_venta = v.id_venta
JOIN productos p on dv.id_producto = p.id_producto
JOIN clientes c on v.id_cliente = c.id_cliente
GROUP BY c.nombre
ORDER BY TOTAL desc;
```


```
SELECT p.id_producto, p.nombre, SUM(dv.cantidad) as TOTAL_CANTIDAD_VENDIDA
FROM ventas v
JOIN detalle_venta dv ON dv.id_venta = v.id_venta
JOIN productos p on dv.id_producto = p.id_producto
JOIN clientes c on v.id_cliente = c.id_cliente
GROUP BY dv.id_producto
ORDER BY TOTAL_CANTIDAD_VENDIDA desc;
```

```
SELECT p.id_producto, p.nombre, SUM(dv.cantidad) as TOTAL_CANTIDAD_VENDIDA
FROM ventas v
JOIN detalle_venta dv ON dv.id_venta = v.id_venta
JOIN productos p on dv.id_producto = p.id_producto
JOIN clientes c on v.id_cliente = c.id_cliente

WHERE '2025-01-01' <= v.fecha AND v.fecha < '2025-04-01'

GROUP BY dv.id_producto
ORDER BY TOTAL_CANTIDAD_VENDIDA desc;
```


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







![modelado de datos](https://github.com/cr-tempranam/public-portfolio/blob/develop/PowerBI/Proyecto-FRUTIMAX/img/data_model.png)
