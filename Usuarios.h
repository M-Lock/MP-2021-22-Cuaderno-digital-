//Declaraciones módulo Usuarios

#ifndef _USUARIOS_H_
#define _USUARIOS_H_

typedef struct{
	char id[4];		//Identificador del usuario, con 3 dígitos
	char nombre[21];	//Nombre completo del usuario, con 20 caracteres máximo.
	char perfil[14];	//Perfil del usuario (Perfil_usuario): «administrador» o «profesor».
	char usuario[6];		//Nombre de usuario (Usuario) para acceder al sistema, 5 caracteres.
	char contrasenna[9];	//Contraseña para acceder al sistema (Contraseña), 8 caracteres.
} tipo_Usuario;

tipo_Usuario *vUsuarios;		//Vector usuario donde se almacenará cada uno de los usuarios del fichero y el cual se modificará
int nUsuarios;		//numero de usuarios

//Cabecera: void volcarUsuarios(tipo_Usuario **, int *);
//Precondicion: Se ponen de entrada el vector de usuarios y el numero de usuarios por referencia
//Postcondicion: Vuelca la informacion del fichero Usuarios.txt a estructuras del programa
void cargarUsuarios(tipo_Usuario **, int *);

//Cabecera: void mostrar_vUsuarios (tipo_Usuario *, int);
//Precondicion: vector de tipo_usuario declarado y entero con el numero de usuarios
//Postcondicion: muestra los usuarios por pantalla
void listarUsuarios (tipo_Usuario *, int);

//Cabecera:void altaUsuario()
//Postcondicion: Da de alta un usuario
void altaUsuario(tipo_Usuario **, int *);

//Cabecera: void bajaUsuario()
//Postcondicion: Da de baja un usuario
void bajaUsuario();

//Cabecera: void modificarUsuarios()
//Postcondicion: modifica usuarios
void modificarUsuarios();

//Cabecera: void listarUsuarios()
//Postcondicion: Lista los usuarios
void listarUsuarios();

void cambio_linea(char*)

#endif	//_USUARIOS_H_
