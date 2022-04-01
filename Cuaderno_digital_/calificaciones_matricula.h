#ifndef CALIFICACIONES_MATRICULA_H_
#define CALIFICACIONES_MATRICULA_H_
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

void introducir_Matriculas(Matriculas **,int *);  //Funciona
void introducir_Calificaciones(Calificaciones **,int *);
void volcar_Matriculas(Matriculas *);  //Funciona
void volcar_Calificaciones(Calificaciones *);  //Funciona
void materias_alum(Matriculas *, char*);  //Sin terminar
void imprimir_nota(Calificaciones *, char*, char*);  //No funciona
void modificar_nota(Calificaciones **, char*, char*);  //Funciona
void eliminar_nota(Calificaciones **, char*, char*, int *);  //Funciona
void anadir_nota(Calificaciones **,char*, char*, int *); //Funciona
void anadir_matricula(Matriculas **, char*, char*,int *);  //Funciona
void borrar_matricula(Matriculas **,char*, char*, int *);  //Funciona
void modificar_matricula(Matriculas **, char*, char*, char*);  //Funciona
void eliminar_matricula_materia(Matriculas **, char*, int *);  //Funciona
void eliminar_matriculas_alumno(Matriculas **, char*, int *);  //Funciona
void eliminar_calificaciones_materia(Calificaciones **, char*, int *);  //Funciona
void eliminar_calificaciones_alumnos(Calificaciones **, char*, int *);  //Funciona
#endif

