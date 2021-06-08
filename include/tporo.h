#include <iostream>
#include <ostream>

#ifndef TPoroH
#define TPoroH

using namespace std;

class TPoro
{
	// Sobrecarga del operador SALIDA
	friend ostream & operator<<(ostream &os, const TPoro &poro);

	private:
		//Coordenada x de la posición
		int x;
		//Coordenada y de la posición
		int y;
		//Volumen
		double volumen;
		//Color
		char *color;

		/*---------MÉTODOS AUXILIARES--------*/
		// Comprueba que se reserva memoria para TPoro.color correctamente.
		// En caso de error, devuelve un mensaje de error (cerr).
		bool errorReservaMemoria() const;

		void copiar (const TPoro &poro);

		// Elimina acentos y pasa de mayúscula a minúscula los caracteres
		void sanitizeAndSetColor(char *color);

	public:
		// Constructor por defecto
		TPoro();

		// Constructor a partir de una posición y un volumen
		TPoro(int x, int y, double volumen);

		// Constructor a partir de una posición, un volumen y un color
		TPoro(int x, int y, double volumen, char *color);

		// Constructor de copia
		TPoro(const TPoro &poro);

		// Destructor
		~TPoro();

		// Sobrecarga del operador asignación
		TPoro & operator=(const TPoro &);	

		// Sobrecarga del operador igualdad
		bool operator==(const TPoro &);

		// Sobrecarga del operador desigualdad
		bool operator!=(const TPoro &);

		// Modifica la posición
		void Posicion(int x, int y);

		// Modifica el volumen
		void Volumen(double volumen);

		// Modifica el color
		void Color(char *color);

		// Devuelve la coordenada x de la posición
		int PosicionX() const;

		// Devuelve la coordenada y de la posición
		int PosicionY() const;

		// Devuelve el volumen
		double Volumen() const;

		// Devuelve el color
		char * Color() const;

		// Devuelve cierto si el poro está vacío
		bool EsVacio() const;
};

#endif