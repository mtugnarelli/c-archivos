
#include <stdio.h>
#include <stdlib.h>

#define LONGITUD_BUFFER 100

typedef struct {
	int numero;
	char etiqueta[20];
	float latitud;
	float longitud;
} Poi;

void leerArchivoDeTexto() {

	char buffer[LONGITUD_BUFFER] = "";
	FILE* archivo = fopen("entrada.txt", "rt");

	while (!feof(archivo)) {
		fgets(buffer, LONGITUD_BUFFER, archivo);
		printf("%s", buffer);
	}
	fclose(archivo);
	printf("\n");
}

void escribirArchivoDeTexto() {

	char* lineas[] = { "Primera\n", "Segunda\n", "Tercera\n", "Cuarta\n" };
	FILE* archivo = fopen("salida.txt", "wt");

	int linea;
	for (linea = 0; linea < 4; linea++) {
		fputs(lineas[linea], archivo);
	}

	fclose(archivo);
}

void escribirArchivoBinario() {

	Poi puntosDeInteres[] = {
		{
			numero: 5,
			etiqueta: "Museo",
			latitud: -34.908807,
			longitud: -57.935375
		},
		{
			numero: 258,
			etiqueta: "Planetario",
			latitud: -34.568722,
			longitud:-58.411819
		},
		{
			numero: 1,
			etiqueta: "obelisco",
			latitud: -34.603366,
			longitud: -58.381599
		}
	};

	FILE* archivo = fopen("posiciones.bin", "wb");
	fwrite(puntosDeInteres, sizeof(Poi), 3, archivo);
	fclose(archivo);
}

void leerArchivoBinario() {

	Poi unPoi;

	FILE* archivo = fopen("posiciones.bin", "rb");

	while (fread(&unPoi, sizeof(Poi), 1, archivo)) {

		printf("Poi: [%d] %s: (%f,%f)\n",
			   unPoi.numero,
			   unPoi.etiqueta,
			   unPoi.latitud,
			   unPoi.longitud);
	}
	fclose(archivo);
}

int main() {

	leerArchivoDeTexto();
	escribirArchivoDeTexto();

	escribirArchivoBinario();
	leerArchivoBinario();

	return 0;
}
