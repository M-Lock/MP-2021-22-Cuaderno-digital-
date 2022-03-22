//Declaraciones m�dulo Usuarios

#ifndef _USUARIOS_H_
#define _USUARIOS_H_

typedef struct{
	char id[4];		//Identificador del usuario, con 3 d�gitos
	char nombre[21];	//Nombre completo del usuario, con 20 caracteres m�ximo.
	char perfil[14];	//Perfil del usuario (Perfil_usuario): �administrador� o �profesor�.
	char usuario[6];		//Nombre de usuario (Usuario) para acceder al sistema, 5 caracteres.
	char contrasenna[9];	//Contrase�a para acceder al sistema (Contrase�a), 8 caracteres.
} tipo_Usuario;

tipo_Usuario *vUsuarios;		//Vector usuario donde se almacenar� cada uno de los usuarios del fichero y el cual se modificar�
int nUsuarios;		//numero de usuarios


void cargarUsuarios(tipo_Usuario **, int *);


void volcarUsuarios(tipo_Usuario *vUsuarios, size_t tam);


void listarUsuarios (tipo_Usuario *, int);


void altaUsuario(tipo_Usuario **, int *);


void bajaUsuario(tipo_Usuario **,int *);

//Cabecera: void modificarUsuarios()
//Postcondicion: modifica usuarios
void modificarUsuarios();

//Cabecera: void listarUsuarios()
//Postcondicion: Lista los usuarios
void listarUsuarios();

void cambio_linea(char*);

#endif	//_USUARIOS_H_
