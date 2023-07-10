#include "estructuras.c"
#include <stdio.h>

void mostrarDatosProfesor(Profesor profesor) {
  printf("Nombre: %s\n", profesor.nombre);
  printf("Carrera: %s\n", profesor.carrera);
  printf("*Materias dictando*\n");
  for (int i = 0; i < profesor.numMaterias; i++) {
    MateriasDictando materia = profesor.materias[i];
    printf("Materia %i:\n", i + 1);
    printf("  Nombre: %s\n", materia.nombreMateria);
    printf("  Paralelo: %s\n", materia.paralelo);
  }
}

void mostrarDatosEstudiante(Estudiante estudiante) {
  printf("Nombre: %s\n", estudiante.nombre);
  printf("Nivel: %i\n", estudiante.nivel);
  printf("Carrera: %s\n", estudiante.carrera);
  printf("*Materias tomando*\n");
  for (int i = 0; i < estudiante.numMaterias; i++) {
    MateriasTomando materia = estudiante.materias[i];
    printf("Materia %i:\n", i + 1);
    printf("  Nombre: %s\n", materia.nombreMateria);
    printf("  Créditos: %i\n", materia.creditos);
  }
}

void eliminarMateriaProfesor(Profesor *arrayProfesor) {
  int opcion;
  printf("Desea eliminar una materia de algun profesor? 1=Si 2=No\n");
  scanf("%i", &opcion);
  if (opcion == 2) {
    return;
  }
  printf("Indique el numero del profesor que quiera elegir:\n");
  scanf("%i", &opcion);
  Profesor profesor = arrayProfesor[opcion - 1];
  printf("Ingrese el numero de la materia a eliminar\n");
  scanf("%i", &opcion);
  MateriasDictando materia = profesor.materias[opcion - 1];
  for (int i = (opcion - 1); i < profesor.numMaterias; i++) {
    profesor.materias[i] = profesor.materias[i + 1];
  }
  profesor.numMaterias--;
  printf("La materia '%s' ha sido eliminada del profesor '%s'.\n",
         materia.nombreMateria, profesor.nombre);
  printf("--Datos actualizados del profesor--\n");
  mostrarDatosProfesor(profesor);
}

void eliminarMateriaEstudiante(Estudiante *arrayEstudiante) {
  int opcion;
  printf("Desea eliminar una materia de algun estudiante? 1=Si 2=No\n");
  scanf("%i", &opcion);
  if (opcion == 2) {
    return;
  }
  printf("Indique el numero del estudiante que quiera elegir:\n");
  scanf("%i", &opcion);
  Estudiante estudiante = arrayEstudiante[opcion - 1];
  printf("Ingrese el numero de la materia a eliminar\n");
  scanf("%i", &opcion);
  MateriasTomando materia = estudiante.materias[opcion - 1];
  for (int i = (opcion - 1); i < estudiante.numMaterias; i++) {
    estudiante.materias[i] = estudiante.materias[i + 1];
  }
  estudiante.numMaterias--;
  printf("La materia '%s' ha sido eliminada del estudiante '%s'.\n",
         materia.nombreMateria, estudiante.nombre);
  printf("--Datos actualizados del profesor--\n");
  mostrarDatosEstudiante(estudiante);
}

void cambiarNivelEstudiante(Estudiante *arrayEstudiante) {
  int opcion;
  int nivelActualizado;
  printf("Desea cambiar el nivel de algun estudiante? 1=Si 2=No\n");
  scanf("%i", &opcion);
  if (opcion == 2) {
    return;
  }
  printf("Indique el numero del estudiante que quiera elegir:\n");
  scanf("%i", &opcion);
  Estudiante estudiante = arrayEstudiante[opcion - 1];
  printf("Ingrese el nuevo nivel del estudiante\n");
  scanf("%i", &nivelActualizado);
  estudiante.nivel = nivelActualizado;
  printf("El nivel actual del estudiante '%s' es '%i'.\n", estudiante.nombre,
         estudiante.nivel);
  printf("--Datos actualizados del estudiante--\n");
  mostrarDatosEstudiante(estudiante);
}