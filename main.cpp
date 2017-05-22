#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <iostream>
#include "2j.h"

//g++ -o main main.cpp -lSDL2 pour linux

int main(int argc, char *argv[]) {
	SDL_Window *window = nullptr;
	SDL_Surface *windowSurface = nullptr;
	SDL_Surface *imageSurface1 = nullptr;
	SDL_Surface *imageSurface2 = nullptr;
	SDL_Surface *imageSurface3 = nullptr;
	SDL_Surface *currentImage = nullptr;
	int image;
	

	bool isRunning = true;
	SDL_Event ev;

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "Video Initialization Error: " << SDL_GetError() << std::endl;
	}
	else {
		window = SDL_CreateWindow("SDL Coding Made Easy Series", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
		if (window == NULL) {
			std::cout << "Window Creation Error : " << SDL_GetError() <<std::endl;
		}	
		else {

			//Window created
			windowSurface = SDL_GetWindowSurface(window);
			imageSurface1 = SDL_LoadBMP("baghchal1.bmp");
			imageSurface2 = SDL_LoadBMP("baghchal2.bmp");
			imageSurface3 = SDL_LoadBMP("baghchal3.bmp");
			currentImage = imageSurface1;
			image = 1;

			if (currentImage == NULL) {
				std::cout << "Image Creation Error : " << SDL_GetError() << std::endl;
			}
			else {

				while (isRunning) {

					while (SDL_PollEvent(&ev) != 0) {
						SDL_BlitSurface(currentImage, NULL, windowSurface, NULL);										


						switch (ev.type) {
							case SDL_QUIT:
								isRunning = false;
								break;
						}
						switch (ev.key.keysym.sym) {

							case SDLK_DOWN:
								if (image == 1) {
									currentImage = imageSurface2;
									image = 2;
									printf("ok2");
									break;
								}
								else if (image == 2) {
									image = 3;
									currentImage = imageSurface3;
									
									break;
								}
								else {
									break;
								}

							case SDLK_UP:
								if (image == 2) {
									currentImage = imageSurface1;
									image = 1;
									break;
								}
								else if (image == 3) {
									currentImage = imageSurface2;
									image = 2;
									break;
								}
								else {
									break;
								}
							case SDLK_RETURN:
								if (image == 3) {
									printf("%d", image);
									isRunning = false;
								}
                                else if (image == 1) {
                                    int i;
                                    i = game2players();
                                }
								break;

							default:
								break;

						}
						SDL_UpdateWindowSurface(window);
					}
				}
			}
		}
	}

	SDL_FreeSurface(currentImage);
	imageSurface1 = nullptr;
	imageSurface2 = nullptr;
	imageSurface3 = nullptr;
	currentImage = nullptr;

	SDL_DestroyWindow(window);
	window = nullptr;
	windowSurface = nullptr;
	SDL_Quit();

	return 0;
}
