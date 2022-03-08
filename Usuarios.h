//Declaraciones módulo Usuarios

#ifndef _USUARIOS_H_
#define _USUARIOS_H_

typedef struct{
	char id_usuario[4];		//Identificador del usuario, con 3 dígitos
	char nomb_usuario[21];	//Nombre completo del usuario, con 20 caracteres máximo.
	char perfil_usario[13];	//Perfil del usuario (Perfil_usuario): «administrador» o «profesor».
	char usuario[6];		//Nombre de usuario (Usuario) para acceder al sistema, 5 caracteres.
	char contrasenna[9];	//Contraseña para acceder al sistema (Contraseña), 8 caracteres.
} Usuario;

//Cabecera: void volcarUsuarios()
//Postcondicion: Vuelca la informacion del fichero Usuarios.txt a estructuras del programa
void volcarUsuarios();

//Cabecera:void altaUsuario()
//Postcondicion: Da de alta un usuario
void altaUsuario();

//Cabecera: void bajaUsuario()
//Postcondicion: Da de baja un usuario
void bajaUsuario();

//Cabecera: void modificarUsuarios()
//Postcondicion: modifica usuarios
void modificarUsuarios();

//Cabecera: void listarUsuarios()
//Postcondicion: Lista los usuarios
void listarUsuarios();

#endif	//_USUARIOS_H_
