#ifndef CALIFICACIONES_MATRICULAS_H_
#define CALIFICACIONES_MATRICULAS_H_
typedef struct{
    int Id_materia;
    int Id_alum;
}Matriculas;    //Estructura encargada de almacenar los datos correspondientes del fichero de Matrículas.txt

typedef struct{
    int dia;
    int mes;
    int anio;
}Fecha;    //Estructura encargada de almacenar la fecha

typedef struct{
    Fecha Fecha_calif;
    char Descrip_calif[31];
    int Id_materia;
    int Id_aalum;
    float Valor_calif;
}Calificaciones;    //Estructura encargada de almacenar los datos correspondientes del fichero de Calificaciones.txt

void introducir_Matriculas();
void introducir_Calificaciones();
void volcar_Matriculas();
void volcar_Calificaciones();
void materias_alum(char*);
void imprimir_nota(char*, char*);
void modificar_nota(char*, char*);
void eliminar_nota(char*, char*);
void anadir_nota(char*, char*);
void anadir_matricula(char*, char*);
void borrar_matricula(char*, char*);
void modificar_matricula(char*, char*, char*);
void eliminar_matricula_materia(char*);
void eliminar_matriculas_alumno(char*);
void eliminar_calificaciones_materia(char*);
void eliminar_calificaciones_alumnos(char*);
#endif
//Función para eliminar matriculas a traves del id_materia
