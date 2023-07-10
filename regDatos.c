#include "estructuras.c"
#include <stdio.h>
#include <stdlib.h>

Profesor pedirDatosProfesor() {
  Profesor profesor;
  printf("Ingrese el nombre del profesor:\n");
  scanf("%s", profesor.nombre);
  printf("Ingrese la carrera:\n");
  scanf("%s", profesor.carrera);
  printf("Numero de materias que el profesor va a dictar:\n");
  scanf("%i", &profesor.numMaterias);
  profesor.materias = (MateriasDictando *)malloc(sizeof(MateriasDictando) *
                                                 profesor.numMaterias);
  for (int i = 0; i < profesor.numMaterias; i++) {
    MateriasDictando materia;
    int numeroDeMateria = i + 1;
    printf("-- MATERIA %i --\n", numeroDeMateria);
    printf("Ingrese el nombre de la materia %i:\n", numeroDeMateria);
    scanf("%s", materia.nombreMateria);
    printf("Ingrese el paralelo de la materia %i:\n", numeroDeMateria);
    scanf("%s", materia.paralelo);
    profesor.materias[i] = materia;
  }
  return profesor;
};

Estudiante pedirDatosEstudiante() {
  Estudiante estudiante;
  printf("Ingrese el nombre del estudiante:\n");
  scanf("%s", estudiante.nombre);
  printf("Ingrese el nivel del estudiante:\n");
  scanf("%i", &estudiante.nivel);
  printf("Ingrese la carrera del estudiante:\n");
  scanf("%s", estudiante.carrera);
  printf("Numero de materias que el alumno va a tomar:\n");
  scanf("%i", &estudiante.numMaterias);
  estudiante.materias = (MateriasTomando *)malloc(sizeof(MateriasTomando) *
                                                  estudiante.numMaterias);
  for (int i = 0; i < estudiante.numMaterias; i++) {
    MateriasTomando materia;
    int numeroDeMateria = i + 1;
    printf("-- MATERIA %i --\n", numeroDeMateria);
    printf("Ingrese el nombre de la materia %i:\n", numeroDeMateria);
    scanf("%s", materia.nombreMateria);
    printf("Ingrese los creditos de la materia %i:\n", numeroDeMateria);
    scanf("%i", &materia.creditos);
    estudiante.materias[i] = materia;
  }
  return estudiante;
};