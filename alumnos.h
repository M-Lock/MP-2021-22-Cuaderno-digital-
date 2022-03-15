#ifndef ALUMNOS_H_
#define ALUMNOS_H_

typedef struct
{	
	int Id_alum;
	char Nombre_alum [21];
	char Direc_alum [31];
	char Local_alum [31];
	char Curso [31];
	char Grupo [11];
}Alumno;
//Postcondici�n:Crea un conjunto de estructuras alumno a partir del fichero
void volcado_entrada_alum();
//Postcondici�n: A�ade al alumno con los valores recibidos de la entrada estandar
void dar_alta_alum();
//Precondici�n: Recibe la Id del alumno a borrar
//Postcondici�n: Elimina los datos correspondientes a dicho alumno
void dar_baja_alum(int);
//Precondici�n: Recibe la Id del alumno a modificar
//Postcondici�n: Modifica los datos seleccionados correspondientes a dicho alumno
void modif_alum(int);
//Postcondicion: Muestra los nombres completos de los alumnos dados de alta;
void listar_alum(Alumno []);
//Postcondici�n: Sobreescribe el fichero con los datos correspondientes al as estruccturas del programa
void volcado_fichero_alum();


#endif
