typedef struct MateriasDictando {
  char nombreMateria[30];
  char paralelo[30];
} MateriasDictando;

typedef struct MateriasTomando {
  char nombreMateria[30];
  int creditos;
} MateriasTomando;

typedef struct Profesor {
  char nombre[30];
  char carrera[30];
  int numMaterias;
  struct MateriasDictando *materias;
} Profesor;

typedef struct Estudiante {
  char nombre[30];
  int nivel;
  char carrera[30];
  int numMaterias;
  struct MateriasTomando *materias;
} Estudiante;

Profesor pedirDatosProfesor();
Estudiante pedirDatosEstudiante();
void mostrarDatosProfesor(Profesor profesor);
void mostrarDatosEstudiante(Estudiante estudiante);
void eliminarMateriaProfesor(Profesor *arrayProfesor);
void eliminarMateriaEstudiante(Estudiante *arrayEstudiante);
void cambiarNivelEstudiante(Estudiante *arrayEstudiante);
// No se hizo crear estudiante porque ya en la misma funcion pedir datos los crea