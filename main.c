/* Huguini79 Software */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>

#define LIBROS_MAX 1024
#define STR_MAX 128

/* Base de datos de los libros */

int libros_id[LIBROS_MAX];
char libros_nombre[LIBROS_MAX][STR_MAX];
char libros_fecha[LIBROS_MAX][STR_MAX];
char libros_categoria[LIBROS_MAX][STR_MAX];
int libros_estanteria[LIBROS_MAX];

/* Usar memcpy */

/* Funciones */

/* void setup(); */

void mostrar_libros() {
	for (int i = 0; i < LIBROS_MAX; i++) {
		if (libros_id[i] != 0) {
			printf(
				"\n\nID: %i\nNOMBRE: %s\nFECHA: %s\nCATEGORIA: %s\nESTANTERIA: %i", libros_id[i], libros_nombre[i], libros_fecha[i], libros_categoria[i], libros_estanteria[i]
			);
		}
	}
}

void buscar_libro() {
	int id_entrada_de_usuario;
	printf("Introduce el id del libro: ");
	scanf("%i", &id_entrada_de_usuario);
	
	int id = id_entrada_de_usuario;
	
	printf(
				"\n\nID: %i\nNOMBRE: %s\nFECHA: %s\nCATEGORIA: %s\nESTANTERIA: %i", libros_id[id], libros_nombre[id], libros_fecha[id], libros_categoria[id], libros_estanteria[id]
	);
	
}

void agregar_libro(int id, const char* nombre, const char* fecha, const char* categoria, int estanteria) {
	/* Copiar a la memoria */                                                                                                                                                                      
	libros_id[id] = id;
	libros_estanteria[id] = estanteria;

	strcpy(libros_nombre[id], nombre);
	strcpy(libros_fecha[id], fecha);
	strcpy(libros_categoria[id], categoria);

}

void terminal_programa() {
	char entrada_de_usuario[512];
	printf("> ");
	scanf("%s", entrada_de_usuario);
	
	if (strcmp(entrada_de_usuario, "mostrar") == 0) {
		mostrar_libros();
		
		terminal_programa();
		
	} else if (strcmp(entrada_de_usuario, "agregar_libro") == 0) {
		int id_usuario;
		char nombre_usuario[STR_MAX];
		char fecha_usuario[STR_MAX];
		char categoria_usuario[STR_MAX];
		int estanteria_usuario;
		
		printf("Introduce el id del libro (esto se usará para buscar el libro por número): \n");
		scanf("%i", &id_usuario);
		printf("Introduce el nombre del libro: \n");
		scanf("%s", nombre_usuario);
		printf("Introduce la fecha de libro: \n");
		scanf("%s", fecha_usuario);
		printf("Introduce la categoria del libro: \n");
		scanf("%s", categoria_usuario);
		printf("Introduce el número de estanteria del libro: \n");
		scanf("%i", &estanteria_usuario);
		
		
		agregar_libro(id_usuario, nombre_usuario, fecha_usuario, categoria_usuario, estanteria_usuario);
		
		printf("\n\nLIBRO AÑADIDO EXITOSAMENTE");
		
		terminal_programa();
		
	} else if (strcmp(entrada_de_usuario, "buscar") == 0) {
		buscar_libro();
		
		terminal_programa();
		
	} else {
		terminal_programa();
	}
}

int main() {
	terminal_programa();
	
	// agregar_libro(1, "CHIQUICHIQUICHIIIII", "09/02/2026", "CHUPICHUPI", 5);
	// agregar_libro(2, "CEBOLLAAAAAAAAAA", "08/02/2026", "GOGOGOGO", 7);

	// buscar_libro();

	// mostrar_libros();
	
	return 0;
	
}
