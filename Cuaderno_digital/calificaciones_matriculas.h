#ifndef CALIFICACIONES_MATRICULAS_H_
#define CALIFICACIONES_MATRICULAS_H_
typedef struct{
    char Id_materia[6];
    char Id_alum[8];
}Matriculas;    //Estructura encargada de almacenar los datos correspondientes del fichero de Matrículas.txt
Matriculas *matri;

typedef struct{
    int dia;
    int mes;
    int anio;
}Fecha;    //Estructura encargada de almacenar la fecha

typedef struct{
    Fecha Fecha_calif;
    char Descrip_calif[32];
    char Id_materia[6];
    char Id_alum[8];
    float Valor_calif;
}Calificaciones;    //Estructura encargada de almacenar los datos correspondientes del fichero de Calificaciones.txt
Calificaciones *cali;

typedef struct{
    int lon;
}longitud_Matriculas;
longitud_Matriculas num_lin_Matriculas;

typedef struct{
    int lon;
}longitud_Calificaciones;
longitud_Calificaciones num_lin_Calificaciones;

void introducir_Matriculas(Matriculas **,int *);
void introducir_Calificaciones(Calificaciones **,int *);
void volcar_Matriculas(Matriculas *);
void volcar_Calificaciones(Calificaciones *);
void materias_alum(Matriculas *, char*);
void imprimir_nota(Calificaciones *, char*, char*);
void modificar_nota(Calificaciones **, char*, char*);
void eliminar_nota(Calificaciones **, char*, char*);
void anadir_nota(Calificaciones **,char*, char*);
void anadir_matricula(Matriculas **, char*, char*);
void borrar_matricula(Matriculas **,char*, char*);
void modificar_matricula(Matriculas **, char*, char*, char*);
void eliminar_matricula_materia(Matriculas **, char*);
void eliminar_matriculas_alumno(Matriculas **, char*);
void eliminar_calificaciones_materia(Calificaciones **, char*);
void eliminar_calificaciones_alumnos(Calificaciones **, char*);
#endif
//Función para eliminar matriculas a traves del id_materia
