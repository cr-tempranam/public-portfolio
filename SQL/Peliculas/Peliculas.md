# BASE DE DATOS "PELICULAS"


#### PROCEDIMIENTO
Partiendo de la base de datos sobre películas, directores, y géneros, se vinculó dichas tablas a través del modelado obteniendo la imagen inferior. 

![data_model](https://github.com/cr-tempranam/public-portfolio/blob/develop/SQL/Peliculas/img/data_model.png)

A continuación se escribieron las consultas según los requisitos planteados.

Como consulta inicial se busca conocer la cantidad de películas por genero registradas en la base de datos. Nos interesa ver el género y la cantidad de películas por género, ordenadas por dicha cantidad de menor a mayor.

```
SELECT g.nombre Genero, count(*) Cantidad_Peliculas
FROM peliculas_directores pd
JOIN peliculas p ON pd.id_pelicula = p.id_pelicula
JOIN directores d ON pd.id_director = d.id_director
JOIN generos g ON p.id_genero = g.id_genero

GROUP BY g.id_genero
ORDER BY Cantidad_Peliculas
```

![Query1](https://github.com/cr-tempranam/public-portfolio/blob/develop/SQL/Peliculas/img/Query1.jpeg)


Luego se requiere conocer las películas realizadas por el "director 6". Se desea saber los títulos de dichas películas, el año de estreno y si efectivamente perteneces a este director. Tal listado deberá estar ordenado del título más antiguo al más moderno.

```
SELECT p.titulo, p.anio, d.nombre Director
FROM peliculas_directores pd
JOIN peliculas p ON pd.id_pelicula = p.id_pelicula
JOIN directores d ON pd.id_director = d.id_director
JOIN generos g ON p.id_genero = g.id_genero

WHERE d.nombre = 'Director 6'

ORDER BY p.anio
```

![Query2](https://github.com/cr-tempranam/public-portfolio/blob/develop/SQL/Peliculas/img/Query2.jpeg)


En una última consulta se requiere conocer las películas registradas que tienen una duración menor a los cien (100) minutos. Esta lista debe contener el título de la película y la duración, además debe estar ordenada por esa duración de mayor a menor. 

```
SELECT p.titulo, p.duracion_min
FROM peliculas_directores pd
JOIN peliculas p ON pd.id_pelicula = p.id_pelicula

WHERE p.duracion_min < 100

ORDER BY p.duracion_min DESC
```

![Query3](https://github.com/cr-tempranam/public-portfolio/blob/develop/SQL/Peliculas/img/Query3.jpeg)
