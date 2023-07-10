#include "estructuras.c"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv) {
  Profesor *arrayProfesor;
  Estudiante *arrayEstudiante;
  int opt;
  int numPersonas = atoi(argv[1]);
  while ((opt = getopt(argc, argv, "pea")) != -1) {
    switch (opt) {

    case 'p':
      arrayProfesor = (Profesor *)malloc(sizeof(Profesor) * numPersonas);
      for (int i = 0; i < numPersonas; i++) {
        printf("--- PROFESOR %i ---\n", i + 1);
        *(arrayProfesor + i) = pedirDatosProfesor();
      }
      printf("\n**REGISTRO EXITOSO**\n\n");
      printf("Profesores ingresados al sistema:\n");
      for (int i = 0; i < numPersonas; i++) {
        Profesor profesor;
        profesor = *(arrayProfesor + i);
        printf("--- PROFESOR %i ---\n", i + 1);
        mostrarDatosProfesor(profesor);
      }
      eliminarMateriaProfesor(arrayProfesor);
      free(arrayProfesor);
      break;

    case 'e':
      arrayEstudiante = (Estudiante *)malloc(sizeof(Estudiante) * numPersonas);
      for (int i = 0; i < numPersonas; i++) {
        printf("--- ESTUDIANTE %i ---\n", i + 1);
        *(arrayEstudiante + i) = pedirDatosEstudiante();
      }
      printf("**REGISTRO EXITOSO**\n");
      printf("Estudiantes ingresados al sistema:\n");
      for (int i = 0; i < numPersonas; i++) {
        Estudiante estudiante;
        estudiante = *(arrayEstudiante + i);
        printf("--- ESTUDIANTE %i ---\n", i + 1);
        mostrarDatosEstudiante(estudiante);
      }
      eliminarMateriaEstudiante(arrayEstudiante);
      cambiarNivelEstudiante(arrayEstudiante);
      free(arrayEstudiante);
      break;

    case 'a':
      arrayProfesor = (Profesor *)malloc(sizeof(Profesor) * numPersonas);
      arrayEstudiante = (Estudiante *)malloc(sizeof(Estudiante) * numPersonas);
      *arrayProfesor = pedirDatosProfesor();
      for (int i = 0; i < (numPersonas - 1); i++) {
        *(arrayEstudiante + i) = pedirDatosEstudiante();
      }
      printf("**REGISTRO EXITOSO**\n");
      mostrarDatosProfesor(*arrayProfesor);
      for (int i = 0; i < (numPersonas - 1); i++) {
        Estudiante estudiante;
        estudiante = *(arrayEstudiante + i);
        mostrarDatosEstudiante(estudiante);
      }
      free(arrayProfesor);
      free(arrayEstudiante);
      break;

    case '?':
      printf("Opción no reconocida: %c\n", optopt);
      break;
    }
  }
}