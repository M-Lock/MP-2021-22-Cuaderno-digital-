#include "calificaciones_matriculas.h"
#include <stdio.h>
#include <stdlib.h>

int cal_linias_Matriculas();
int cal_linias_Calificaiones();

//Cabezera: void introducir_Matriculas()
//Precondici�n: Las estructuras han de estar definidas
//Postcondici�n: Introduce los datos del ficheor de matriculas en una estructura de datos
void introducir_Matriculas(){
    int num_lin_Matriculas;
    FILE *Matriculas;
    Matriculas=fopen("Matriculas.txt","r");
    if(Matriculas==NULL){
        printf("No se ha podido abrir el fichero de Matriculas. \n");
        exit(1);
    }
    else{
        num_lin_Matriculas = cal_linias_Matriculas();
    }
}


//Cabezera: void introducir_Calificaciones()
//Precondici�n: Las estructuras han de estar definidas
//Postcondici�n: Introduce los datos del fichero de matriculas en una estructura de datos
void introducir_Calificaciones(){
    int num_lin_Calificaciones;
    FILE *Calificaciones;
    Calificaciones=fopen("Calificaciones.txt","r");
    if(Calificaciones==NULL){
        printf("No se ha podido abrir el fichero de Calificaciones. \n");
        exit(1);
    }
    else{
        num_lin_Calificaciones = cal_linias_Calificaiones();
    }
}

//Cabezera: void volcar_Matriculas()
//Precondici�n: Tener las estructuras creados y con los datos almacenados
//Postcondici�n: Introduce los datos almacenados en las estructuras en el fichero de Matriculas
void volcar_Matriculas(){

}

//Cabezera: void volcar_Calificaciones()
//Precondici�n: Tener las estructuras creados y con los datos almacenados
//Postcondici�n: Introduce los datos almacenados en las estructuras en el fichero de Calificaciones
void volcar_Calificaciones(){

}

//Cabezera: int cal_linias_calificaciones()
//Precondici�n: Tener el fichero creado
//Postcondici�n: Calcular el n�mero de l�neas que tiene el fichero
int cal_linias_Calificaiones(){
    char aux;
    int num_lin_Calificaciones=0;
    FILE *Calificaciones;
    Calificaciones=fopen("Calificaciones.txt","r");
    if(Calificaciones==NULL){
        printf("Mo se ha podido abrir el archivo de Calificaciones. \n");
        exit(1);
    }
    else{
        while(aux!=EOF){
            aux=fgetc(Calificaciones);
            if(aux=='\n'){
                num_lin_Calificaciones++;
            }
        }
    }
    return num_lin_Calificaciones;
}

//Cabezera: int cal_linias_matriculas()
//Precondici�n: Tener el fichero creado
//Postcondici�n: Calcular el n�mero de l�neas que tiene el fichero
int cal_linias_Matriculas(){
    char aux;
    int num_lin_Matriculas=0;
    FILE *Matriculas;
    Matriculas=fopen("Matriculas.txt","r");
    if(Matriculas==NULL){
        printf("No se ha podido abrir el fichero de Matriculas. \n");
        exit(1);
    }
    else{
        while(aux!=EOF){
            aux=fgetc(Matriculas);
            if(aux=='\n'){
                num_lin_Matriculas++;
            }
        }
    }
    return num_lin_Matriculas;
}

//Cabezera: void materias_alum(char* id_alum)
//Precondici�n: Tener el valor pasado a la funci�n con un valor v�lido y no vacio
//Postcondici�n: Devuelve las asignaturas en las que se encuentra matriculado un alumno
void materias_alum(char* id_alum){

}

//Cabezera:void imprimir_nota(char* id_alum, char* id_materia)
//Precondici�n: Tener los valores pasados a la funci�n con alg�n valor v�lido y no vacio
//Postcondici�n: Imprime por pantalla las notas de una materia en concreto dde un alumnos en concreto
void imprimir_nota(char* id_alum, char* id_materia){

}

//Cabezera: void modificar_nota(char* id_alum, char* id_materia)
//Precondici�n: Tener los valores pasados a la funci�n con alg�n valor v�lido y no vacio
//Postcondici�n: Modifica las notas de una asignatura de un alumno en concreto
void modificar_nota(char* id_alum, char* id_materia){

}

//Cabezera: void eliminar_nota(char* id_alum, char* id_materia)
//Precondici�n: Tener los valores pasados a la funci�n con alg�n valor v�lido y no vacio
//Postcondici�n: Elimina una nota de una asignatura de un alumno en concreto
void eliminar_nota(char* id_alum, char* id_materia){

}

//Cabezera: void anadir_nota(char* id_alum, char* id_materia)
//Precondici�n: Tener los valores pasados a la funci�n con alg�n valor v�lido y no vacio
//Postcondici�n: A�ade una nueva nota de una asignatura a un alumno en concreto
void anadir_nota(char* id_alum, char* id_materia){

}

//Cabezera: void anadir_matricula(char* id_alum, char* id_materia)
//Precondici�n: Tener los valores pasados a la funci�n con alg�n valor v�lido y no vacio
//Postcondici�n: Matricula a un alumno en una determinada asignatura
void anadir_matricula(char* id_alum, char* id_materia){

}

//Cabezera: void borrar_matricula(char* id_alum, char* id_materia)
//Precondici�n: Tener los valores pasados a la funci�n con alg�n valor v�lido y no vacio
//Postcondici�n: Elimina la matricula de un alumno en una asignatura
void borrar_matricula(char* id_alum, char* id_materia){

}

//Cabezera: void modificar_matricula(char* id_alum, char* id_materia_vieja, char* id_materia_nueva)
//Precondici�n: Tener los valores pasados a la funci�n con alg�n valor v�lido y no vacio
//Postcondici�n: Modifica la matricula de un alumno
void modificar_matricula(char* id_alum, char* id_materia_vieja, char* id_materia_nueva){

}

//Cabezera: void eliminar_matricula_materia(char* id_materia)
//Precondici�n: Tener el valor pasado a la funci�n con un valor v�lido y no vacio
//Postcondici�n: Cuando se elimina una materia esta funci�n borra de las matriculas dicha asignatura
void eliminar_matricula_materia(char* id_materia){

}

//Cabezera: void eliminar_matriculas_alumno(char* id_alum)
//Precondici�n: Tener el valor pasado a la funci�n con un valor v�lido y no vacio
//Postcondici�n: Cuando se elimina a un alumno esta funci�n elimina las matriculas que tenia realizadas
void eliminar_matriculas_alumno(char* id_alum){

}

//Cabezera: void eliminar_calificaciones_materia(char* id_materia)
//Precondici�n: Tener el valor pasado a la funci�n con un valor v�lido y no vacio
//Postcondici�n: Cuando se elimina una materia elimina todas la notas de dicha materia
void eliminar_calificaciones_materia(char* id_materia){

}

//Cabezera: void eliminar_calificaciones_alumnos(char* id_alum)
//Precondici�n: Tener el valor pasado a la funci�n con un valor v�lido y no vacio
//Postcondici�n: Cuando se elimina un alumno elimina todas las notass de dicho alumno
void eliminar_calificaciones_alumnos(char* id_alum){

}
