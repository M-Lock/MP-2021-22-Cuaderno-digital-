
#ifndef ALUMNOS_H_
#define ALUMNOS_H_

//Estructura dedicada a alamacenar el conjunto de alumnos del sistema de ficheros
typedef struct
{	
	char id_alum [7];
	char nombre_alum [21];
	char direc_alum [31];
	char local_alum [31];
	char curso [31];
	char grupo [11];
}alumno;

alumno *v_alumnos;	//Puntero que señala el comienzo de un vector dinamico del tipo alumno
int n_alumnos;	//Numero de alumnos matriculados (Encontrados en el fichero Alumnos.txt)

//Postcondición:Crea un conjunto de estructuras alumno a partir del fichero
void volcado_entrada_alum(alumno **, int *);

//Postcondición: Añade al alumno con los valores recibidos de la entrada estandar
void dar_alta_alum(alumno*,int*);

//Precondición: Recibe la Id del alumno a borrar
//Postcondición: Elimina los datos correspondientes a dicho alumno
void dar_baja_alum(alumno*,int, char[]);

//Precondición: Recibe la Id del alumno a modificar
//Postcondición: Modifica los datos seleccionados correspondientes a dicho alumno
void modif_alum(alumno*,int, char[]);

//Postcondicion: Muestra los nombres completos de los alumnos dados de alta;
void listar_alum(alumno*, int);

//Postcondición: Sobreescribe el fichero con los datos correspondientes al as estruccturas del programa
void volcado_fichero_alum(alumno*,size_t);

#endif


