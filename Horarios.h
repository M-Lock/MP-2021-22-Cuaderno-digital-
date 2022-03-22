//Declaraciones m�dulo Horarios.

#ifndef _HORARIOS_H_
#define _HORARIOS_H_

typedef struct {
	char id_prof[4];		//Identificador del profesor (Id_profesor), tres d�gitos (debe coincidir con un identificador deusuario, Id_usuario, con perfil profesor del fichero Usuarios.txt).
	int dia_clase;			//D�a (D�a_clase), valor num�rico de 1 a 5 que indica el d�a de la semana que imparte clase de la materia el profesor.
	int hora_clase;			//Hora (Hora_clase), valor num�rico de 1 a 6 que indica el tramo horario en el que imparte clase de la materia el profesor.
	char id_materia[5];		//Identificador de la materia (Id_materia), 4 d�gitos (debe coincidir con el Id_materia de alguna materia del fichero Materias.txt)
	char grupo[11];			//Grupo (Grupo) al que imparte clase, 10 caracteres m�ximo (debe coincidir con alg�n grupo de los que aparecen en el fichero Alumnos.txt).
	
}tipo_Horario;

tipo_Horario *vHorarios;
int nHorarios;

//Cabecera: void cargarHorarios(tipo_Horario **, int *);
//Precondicion: Como par�metros un vector tipo horario y un entero por referencia.
//Postcondicion: Vuelca la informacion del fichero Horarios.txt a estructuras del programa
void cargarHorarios(tipo_Horario **, int *);

//Cabecera: void volcarHorarios(tipo_Horario *vHorarios, size_t tam);
//Precondicion: Recibe un vector de horarios igual o modificado y el numero de horarios
//Postcondicion: Vuelca en el fichero Horarios.txt las nuevas modificaciones en los horarios
void volcarHorarios(tipo_Horario *vHorarios, size_t tam);

//Cabecera: void listarHorarios (tipo_Horario *, int);
//Precondicion: Vector de tipo horario declarado y entero
//Postcondicion: Muestra por pantalla al usuario la lista de horarios
void listarHorarios (tipo_Horario *, int);

//Cabecera: void annadirHoras()
//Postcondicion: A�ade horas al horario de un profesor
void annadirHoras();

//Cabecera: void eliminarHoras()
//Postcondicion: Elimina horas del horario de un profesor
void eliminarHoras();

//Cabecera: void modificarHoras()
//Postcondicion: Modifica horas del horario de un profesor
void modificarHoras();

//Cabecera: void listarHorarios()
//Postcondicion: Lista horarios de un profesor
void listarHorarios();

#endif	//_HORARIOS_H_
