#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef MATERIAS_H_
#define MATERIAS_H_

typedef struct
{
	char  id_materia [5];
	char nombre_materia[51];
	char abrev_materia [4];
}materia;


materia * v_materias; //Puntero que señala el comienzo de un vector dinamico del tipo alumno
int n_materias; //Numero de materias impartidas (Encontradas en el fichero Materias.txt

//Postcondición:Crea un conjunto de estructuras alumno a partir del fichero
void volcado_entrada_mat(materia **, int*);
//Postcondición: Añade la materia con los valores recibidos de la entrada estandar
void dar_alta_mat(materia*,int, char []);
//Precondición: Recibe la Id de la materia a borrar
//Postcondición: Elimina los datos correspondientes a dicha materia
void dar_baja_mat(materia*, int , char []);
//Precondición: Recibe la Id de la materia a modificar
//Postcondición: Modifica los datos correspondientes a dicha materia
void modif_mat(materia*, int , char[]);
//Postcondicion: Muestra los nombres completos de los alumnos dados de alta
void listar_mat(materia*, int);
//Postcondición: Sobreescribe el fichero con los datos correspondientes al as estruccturas del programa
void volcar_fichero_mat(materia*);

#endif
