// Practica realizada por Blanca Macazaga Zuazo y Adri�n Alc�ntara Delgado
#include "TexturasSDL.h"
#include <iostream>
#include <string>
#include "SDL_image.h"
#include "Error.h"
using namespace std;

TexturasSDL::TexturasSDL()
{
	SDL_Texture* pTextura = nullptr; //inicializamos el puntero que apunta a la textura de nuestro globo a null porque todav�a no tenemos textura
}
//--------------------------------------------------------------------------------//
//carga un archivo de imagen en una textura
bool TexturasSDL::load(SDL_Renderer* pRenderer, string const& nombArch)
{
	//El archivo de imagen que se carga
	SDL_Surface* pTempSurface = nullptr; //puntero a una superficie en la que se va a dibujar
	bool carga = true; //Suponemos que la imagen se ha cargado correctamente
	//Carga de la imagen
	pTempSurface = loadFile(nombArch); //carga la superficie del archivo y es apuntada por nuestra superficie

	if (pTempSurface == nullptr)
	{
		//cout << "Imposible cargar el archivo" << nombArch << "! \nSDL Error: " << SDL_GetError() << "\n";
		throw errorTextura("No se puede cargar la textura");
		carga = false;
	}
	else
	{
		pTextura = SDL_CreateTextureFromSurface(pRenderer, pTempSurface); //Se crea una textura a partir de nuestra superficie
		SDL_FreeSurface(pTempSurface);//liberamos la superficie porque se ha cargado la textura
		carga = pTextura != nullptr;
		alto = pTempSurface->h;
		ancho = pTempSurface->w;
	}

	return carga;
}
//--------------------------------------------------------------------------------//
//dibuja las texturas
void TexturasSDL::draw(SDL_Renderer* pRenderer, SDL_Rect  &rect, SDL_Rect const& RFrame){
		SDL_RenderCopy(pRenderer, pTextura, &RFrame, &rect);

}
//--------------------------------------------------------------------------------//
void TexturasSDL::draw(SDL_Renderer* pRenderer, SDL_Rect  &rect) {
	SDL_RenderCopy(pRenderer, pTextura, nullptr, &rect);

}
//--------------------------------------------------------------------------------//
void TexturasSDL::rectAnimation(int frames, int framesAct){
	SDL_Rect rect = { ancho / frames * framesAct % frames, 0, ancho / frames, alto};
}
//carga una imagen en una superficie
SDL_Surface* TexturasSDL::loadFile(string file)
{
	SDL_Surface* archivo = nullptr;
	archivo = IMG_Load(file.c_str());//cargamos el archivo con su nombre
	return archivo;
}
//--------------------------------------------------------------------------------//
//destructora de la textura
TexturasSDL::~TexturasSDL()
{
	SDL_DestroyTexture(pTextura);
	pTextura = nullptr;
}
