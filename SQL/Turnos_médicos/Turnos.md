# BASE DE DATOS "TURNOS MÉDICOS"


#### OBJETIVO

A partir de la base de datos de `SQLite` proporcionada, se confeccionó el modelo relacionando las tablas como se visualiza a continuación y se realizaron unas consultas a la base de datos. 

![data_model](https://github.com/cr-tempranam/public-portfolio/blob/develop/SQL/Turnos_médicos/img/data_model.png)


#### PROCEDIMIENTO

- Como primera consulta se buscó conocer los turnos confirmados, ordenados de la fecha más cercana a la fecha más lejana. Buscamos saber la identificación del turno, la fecha del turno, el nombre del paciente, el estado de confirmación, especialidad solicitada y médico.

```
SELECT t.id_turno, t.fecha, p.nombre AS Paciente, t.estado, e.nombre as Especialidad, m.nombre as Medico
FROM turnos t
JOIN medicos m on t.id_medico = m.id_medico
JOIN especialidades e on m.id_especialidad = e.id_especialidad
JOIN pacientes p on t.id_paciente = p.id_paciente

WHERE t.estado = 'Confirmado'

ORDER BY t.fecha DESC;
```
![Query1](https://github.com/cr-tempranam/public-portfolio/blob/develop/SQL/Turnos_médicos/img/Query1.jpeg)




- Ahora se busca saber las especialidades con la mayor cantidad de turnos confirmados, y solo ver las primeras 5 especialidades  con más turnos confirmados. 

```
SELECT e.nombre as Especialidad, COUNT(*) CANTIDAD_TURNOS
FROM turnos t
JOIN medicos m on t.id_medico = m.id_medico
JOIN especialidades e on m.id_especialidad = e.id_especialidad
JOIN pacientes p on t.id_paciente = p.id_paciente

WHERE t.estado = 'Confirmado'

GROUP BY Especialidad

ORDER BY CANTIDAD_TURNOS DESC
LIMIT 5;
```
![Query2](https://github.com/cr-tempranam/public-portfolio/blob/develop/SQL/Turnos_médicos/img/Query2.jpeg)



- Por último intriga conocer la cantidad de veces que tuvo consultas médicas un paciente, independientemente de la especialidad de la que se trate. Se quiere ver solo los nombres de los pacientes y la cantidad de veces que fue atendido, ordenado de manera alfabética.

```
SELECT p.nombre AS Paciente, COUNT(*) CANTIDAD_TURNOS_ATENDIDOS
FROM turnos t
JOIN medicos m on t.id_medico = m.id_medico
JOIN especialidades e on m.id_especialidad = e.id_especialidad
JOIN pacientes p on t.id_paciente = p.id_paciente

WHERE t.estado = 'Atendido'

GROUP BY t.id_paciente

ORDER BY p.nombre
```


![Query3](https://github.com/cr-tempranam/public-portfolio/blob/develop/SQL/Turnos_médicos/img/Query3.jpeg)
