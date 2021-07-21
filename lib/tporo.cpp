#include <iostream>
#include <ostream>
#include <string.h>
#include <string>
#include <ctype.h>
#include "tporo.h"

using namespace std;

// Constructor por defecto
TPoro::TPoro()
{
	x = 0;
	y = 0;
	volumen = 0;
	color = NULL;
}

// Constructor a partir de una posición y un volumen
TPoro::TPoro(int x, int y, double volumen)
{
	this->x = x;
	this->y = y;
	this->volumen = volumen;
	this->color = NULL;
}

// Constructortir de una posición, un volumen y un color
TPoro::TPoro(int x, int y, double volumen, char *color)
{
	this->x = x;
	this->y = y;
	this->volumen = volumen;
	this->color = NULL;

	if (color != NULL)
	{
		this->Color(color);
	}
}

// Constructor de copia
TPoro::TPoro(const TPoro &poro)
{
	color = NULL;
	copiar(poro);
}

// Destructor
TPoro::~TPoro()
{
	x = 0;
	y = 0;
	volumen = 0;

	if (color != NULL)
	{
		delete[] color;
		color = NULL;
	}
}

// Sobrecarga del operador asignación
TPoro &TPoro::operator=(const TPoro &poro)
{
	if (this != &poro)
	{
		(*this).~TPoro();
		copiar(poro);
	}

	return *this;
}

// Sobrecarga del operador move
TPoro &TPoro::operator=(TPoro &&poro)
{
	if (this != &poro)
	{
		x = poro.x;
		y = poro.y;
		volumen = poro.volumen;
		color = poro.color;
		poro.color = NULL;
	}

	return *this;
}

// Sobrecarga del operador igualdad
bool TPoro::operator==(const TPoro &poro)
{
	// Un poro tiene el color a NULL y el otro si tiene un color asignado.
	if ((color != NULL && poro.color == NULL) || (color == NULL && poro.color != NULL))
		return false;

	// Ambos poros tienen el color a NULL.
	if (color == NULL && poro.color == NULL)
		return (x == poro.x && y == poro.y && volumen == poro.volumen);

	// Ambos poros tienen asignado un color.
	return (x == poro.x && y == poro.y && volumen == poro.volumen && strcmp(this->color, poro.color) == 0);
}

// Sobrecarga del operador desigualdad
bool TPoro::operator!=(const TPoro &poro)
{
	return !(*this == poro);
}

// Modifica la posición
void TPoro::Posicion(int x, int y)
{
	this->x = x;
	this->y = y;
}

// Modifica el volumen
void TPoro::Volumen(double volumen)
{
	this->volumen = volumen;
}

// Modifica el color
void TPoro::Color(char *color)
{
	//El espacio de memoria de color es liberado
	if (this->color != NULL)
	{
		delete[] this->color;
		this->color = NULL;
	}

	if (color != NULL)
		sanitizeAndSetColor(color);
}

// Devuelve la coordenada x de la posición
int TPoro::PosicionX() const
{
	return x;
}

// Devuelve la coordenada y de la posición
int TPoro::PosicionY() const
{
	return y;
}

// Devuelve el volumen
double TPoro::Volumen() const
{
	return volumen;
}

// Devuelve el color
char *TPoro::Color() const
{
	return color;
}

// Devuelve cierto si el poro está vacío
bool TPoro::EsVacio() const
{
	return (x == 0 && y == 0 && volumen == 0 && color == NULL);
}

ostream &operator<<(ostream &os, const TPoro &poro)
{
	if (!poro.EsVacio())
	{
		os.setf(ios::fixed);
		os.precision(2);
		os << "(" << poro.x << ", " << poro.y << ") " << poro.volumen << " ";

		if (poro.color != NULL)
		{
			os << poro.color;
		}
		else
		{
			os << "-";
		}
	}
	else
	{
		os << "()";
	}

	return os;
}

/*---------MÉTODOS AUXILIARES--------*/
bool TPoro::errorReservaMemoria() const
{
	if (color == NULL)
	{
		cerr << "ERROR: no se reservó memoria para TPoro.color correctamente." << endl;
		return true;
	}

	return false;
}

void TPoro::copiar(const TPoro &poro)
{
	x = poro.PosicionX();
	y = poro.PosicionY();
	volumen = poro.Volumen();

	if (poro.Color() != NULL)
	{
		int len = strlen(poro.Color());

		color = new char[len + 1];

		if (!errorReservaMemoria())
		{
			strcpy(color, poro.Color());
			color[len] = '\0';
		}
	}
	else
	{
		color = NULL;
	}
}

void TPoro::sanitizeAndSetColor(char *color)
{
	if (color != NULL)
	{
		//Se crea el nuevo espacio para el nuevo color indicado
		int colorSize = strlen(color);
		this->color = new char[colorSize + 1];

		if (!errorReservaMemoria())
		{
			char aux[colorSize + 1] = "";

			for (int i = 0; i < colorSize; i++)
			{
				//Pasa a minúscula el color
				aux[i] = (char)tolower(color[i]);
			}

			strcpy(this->color, aux);
			this->color[colorSize] = '\0';
		}
	}
}