#ifndef MATERIAS_H_
#define MATERIAS_H_

typedef struct
{
	int Id_materia;
	char Nombre_materia[51];
	char Abrev_materia [4];
}Materia;

//Postcondición:Crea un conjunto de estructuras alumno a partir del fichero
void volcar_entrada_mat();
//Postcondición: Añade la materia con los valores recibidos de la entrada estandar
void dar_alta_mat();
//Precondición: Recibe la Id de la materia a borrar
//Postcondición: Elimina los datos correspondientes a dicha materia
void dar_baja_mat(int);
//Precondición: Recibe la Id de la materia a modificar
//Postcondición: Modifica los datos correspondientes a dicha materia
void modif_mat(int);
//Postcondicion: Muestra los nombres completos de los alumnos dados de alta
void listar_mat();
//Postcondición: Sobreescribe el fichero con los datos correspondientes al as estruccturas del programa
void volcar_fichero_mat();

#endif
