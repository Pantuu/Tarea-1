# Gestion de Pacientes

Este sistema permite a los usuarios gestionar la atención de pacientes en un hospital. Los usuarios pueden registrar nuevos pacientes, asignar prioridades y ver la lista de espera.

## Cómo Utilizar el programa:

  Para poder ultilizar este programa es necesario tener una cuenta de repl.it.
  Una vez dentro de la página, selecciona "New Repl" e importa desde gitHub el programa.

  Link del repositorio:
  ````
  https://github.com/Pantuu/Tarea-1.git
  ````
  Repl.it clonará el repositorio.

  Ejecuta el programa.


## Cómo Funciona:

 ### 1° Funciones del Programa:

  ### a) Registrar Paciente.

    a.a) Nombre (30 caracteres máximos).
    a.b) Edad.
    a.c) Sintoma (100 caracteres máximos).
    a.d) Hora de llegada (formato hh/mm).

  ### b) Asignar Prioridad.
  
    b.a) Indique el paciente deseado.
    b.b) Indique el nivel de urgencia del paciente.
    
  ### c) Mostrar Lista de Pacientes.
    
    c.a) Muestra una lista con todos los pacientes y su información.
    
  ### d) Siguiente Paciente.
    
    d.a) Elimina al paciente actual y pasa al siguiente en la lista.
    
  ### e) Mostrar Pacientes por Prioridad.

    e.a) Indique el nivel de gravedad buscado.
    e.b) Se mostrara una lista con los pacientes que tengan dicha gravedad.


### 3° Indicaciones:

  Este programa funciona con el Índice de Gravedad de Emergencia (ESI), algoritmo de triage utilizado en el departamento de emergencias.
  Los niveles de gravedad se agrupan en 5 grupos:

    1. Riesgo Vital.
    2. Alta Complejidad.
    3. Mediano Riesgo.
    4. Leve.
    5. Atención General.