#include "tdas/list.h"
#include "tdas/queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


typedef struct
{
 char nombrePaciente[31];
 int edad;
 char sintoma[101];
 int gravedad;
 size_t ordenLlegada;
 char horaLlegada[6];
}tipoPaciente;

void limpiarPantalla();
void presioneTeclaParaContinuar();
void mostrarMenuPrincipal();
void registrar_paciente(List *pacientes);
void mostrar_lista_pacientes(List *pacientes);
void asignar_prioridad(List *pacientes);
void mostrar_xprioridad(List *pacientes);
void ordenarPacientes(List *pacientes);
void siguientePaciente(List *pacientes);


int main() {
  char opcion;
  List *pacientes = list_create(); // puedes usar una lista para gestionar los pacientes

  do {
    mostrarMenuPrincipal();
    printf("Ingrese su opción: ");
    scanf(" %c", &opcion); // Nota el espacio antes de %c para consumir el
                           // newline anterior

    switch (opcion) {
    case '1':
      registrar_paciente(pacientes);
      break;
    case '2':
      asignar_prioridad(pacientes);
      break;
    case '3':
      mostrar_lista_pacientes(pacientes);
      break;
    case '4':
      siguientePaciente(pacientes);
      break;
    case '5':
      mostrar_xprioridad(pacientes);
      break;
    case '6':
      puts("Saliendo del sistema de gestión hospitalaria...");
      break;
    default:
      puts("Opción no válida. Por favor, intente de nuevo.");
    }
    presioneTeclaParaContinuar();

  } while (opcion != '6');

  // Liberar recursos, si es necesario
  list_clean(pacientes);

  return 0;
}

// Función para limpiar la pantalla
void limpiarPantalla() { system("clear"); }

void presioneTeclaParaContinuar() {
  puts("Presione una tecla para continuar...");
  getchar(); // Consume el '\n' del buffer de entrada
  getchar(); // Espera a que el usuario presione una tecla
}

// Menú principal
void mostrarMenuPrincipal() 
{
  limpiarPantalla();
  puts("========================================");
  puts("     Sistema de Gestión Hospitalaria");
  puts("========================================");

  puts("1) Registrar paciente");
  puts("2) Asignar prioridad a paciente");
  puts("3) Mostrar lista de espera");
  puts("4) Atender al siguiente paciente");
  puts("5) Mostrar pacientes por prioridad");
  puts("6) Salir");
}

void registrar_paciente(List *pacientes) 
{
  printf("=====================================================\n");
  printf("Registrar nuevo paciente\n");
  tipoPaciente *nuevoPaciente = (tipoPaciente *)malloc(sizeof(tipoPaciente));
  printf("Ingrese el nombre del paciente: ");
  scanf(" %[^\n]", nuevoPaciente->nombrePaciente);

  printf("Ingrese la edad del paciente: ");
  scanf("%i", &nuevoPaciente->edad);

  printf("Ingrese el síntoma del paciente: ");
  scanf( " %[^\n]", nuevoPaciente->sintoma);

  printf("Ingrese hora de ingreso (hh:mm):\n");
  scanf(" %[^\n]", nuevoPaciente->horaLlegada);

  nuevoPaciente->gravedad = 5;


  printf("%s \n", nuevoPaciente->nombrePaciente);
  printf("%i \n", nuevoPaciente->edad);
  printf("%s \n", nuevoPaciente->sintoma);
  printf("%i \n", nuevoPaciente->gravedad);
  printf("%s \n", nuevoPaciente->horaLlegada);
  printf("=====================================================\n");
  list_pushBack(pacientes, nuevoPaciente);
  list_next(pacientes);

}

void mostrar_lista_pacientes(List *pacientes) 
{
  // Mostrar pacientes en la cola de espera
  tipoPaciente *aux = list_first(pacientes);
  if (aux == NULL)
  {
    printf("No hay pacientes en la lista.\n");
    return;
  }
  else
  {
    printf("Pacientes en espera: \n");

    tipoPaciente *paciente = list_first(pacientes);

    for (size_t i = 0; paciente != NULL; paciente = list_next(pacientes), i++)
    {
      paciente->ordenLlegada = i;
      printf("Paciente %zu: %s\nEdad del Paciente: %i\nSintoma Paciente: %s\nGravedad Paciente: %i\nHora de Ingreso: %s\n", (i + 1), paciente->nombrePaciente, paciente->edad, paciente->sintoma, paciente->gravedad, paciente->horaLlegada);
      printf("----------------------------------------------------------------\n");
    }
  }
}

void asignar_prioridad(List *pacientes)
{
  tipoPaciente *paciente = list_first(pacientes);
  if (paciente == NULL)
  {
    printf("No hay pacientes en la lista.\n");
    return;
  }

  char nombreAuxiliar[31];
  printf("Indique Paciente buscado:\n");
  scanf(" %[^\n]", nombreAuxiliar);
  int aux = 0;

  while(paciente != NULL)
    {
      if (strcmp(paciente->nombrePaciente, nombreAuxiliar) == 0)
      {
        printf("Atendiendo al paciente: %s\n", paciente->nombrePaciente);
        printf("Indique el nuevo nivel de gravedad del paciente (1-5): ");
        scanf("%i", &aux);
        paciente->gravedad = aux;
        printf("Paciente %s atendido con prioridad %i ahora.\n", paciente->nombrePaciente, paciente->gravedad);
        break;
      }
      else if (strcmp(paciente->nombrePaciente, nombreAuxiliar) != 0)
      {
        printf("No se encuetra el paciente en la lista.\n");
      }
      
      paciente = list_next(pacientes);
    }
  ordenarPacientes(pacientes);

}

void ordenarPacientes(List *pacientes)
{
  List *pacientesOrdenados = list_create();
  tipoPaciente *paciente = list_first(pacientes);

  while (paciente != NULL)
    {
      if (paciente->gravedad == 1) list_pushBack(pacientesOrdenados, paciente);
        paciente = list_next(pacientes);
    }
  paciente = list_first(pacientes);
  while (paciente != NULL)
    {
      if (paciente->gravedad == 2) list_pushBack(pacientesOrdenados, paciente);
        paciente = list_next(pacientes);
    }
  paciente = list_first(pacientes);
  while (paciente != NULL)
    {
      if (paciente->gravedad == 3) list_pushBack(pacientesOrdenados, paciente);
        paciente = list_next(pacientes);
    }
  paciente = list_first(pacientes);
  while (paciente != NULL)
    {
      if (paciente->gravedad == 4) list_pushBack(pacientesOrdenados, paciente);
        paciente = list_next(pacientes);
    }
  paciente = list_first(pacientes);
  while (paciente != NULL)
    {
      if (paciente->gravedad == 5) list_pushBack(pacientesOrdenados, paciente);
        paciente = list_next(pacientes);
    }
  list_clean(pacientes);
  paciente = list_first(pacientesOrdenados);
  while (paciente != NULL)
    {
      list_pushBack(pacientes, paciente);
      paciente = list_next(pacientesOrdenados);
    }
  free(pacientesOrdenados);
}


void mostrar_xprioridad(List *pacientes)
{

  tipoPaciente *paciente = list_first(pacientes);
  if (paciente == NULL)
  {
    printf("No hay pacientes en la lista.\n");
    return;
  }


  int gravedad = 0;
  
  printf("Indique la gravedad del paciente (1-5): ");
  scanf(" %i", &gravedad);

  int contador = 1;
    
  while(paciente != NULL)
    {
      if (paciente->gravedad == gravedad)
      {
        printf("Paciente %i:\n", contador);
        printf("Nombre del Paciente: %s\n", paciente->nombrePaciente);
        printf("Edad del Paciente: %i\n", paciente->edad);
        printf("Sintoma del Paciente: %s\n", paciente->sintoma);
        printf("Hora Ingreso %s\n", paciente->horaLlegada);
        printf("----------------------------------------------------------------\n");
        contador++;
      }
      paciente = list_next(pacientes);
    }
  
}

void siguientePaciente(List *pacientes)
{
  tipoPaciente *paciente = list_first(pacientes);
  if (paciente == NULL)
  {
    printf("No hay pacientes en la lista.\n");
    return;
  }
  printf("Atendiendo al paciente: %s\nEdad: %i\nSíntoma: %s\nHora: %s\nPrioridad: %i\n", paciente->nombrePaciente, paciente->edad,paciente->sintoma, paciente->horaLlegada, paciente->gravedad);
  printf("Paciente Eliminado\n");
  list_popFront(pacientes);
  
}
