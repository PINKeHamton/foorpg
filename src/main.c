#include <SDL3/SDL.h>
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_keycode.h>
#include <SDL3/SDL_messagebox.h>
#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_video.h>
#include <stdint.h>
#include <stdio.h>

SDL_Window *win = NULL;
SDL_Renderer *ren = NULL;
FILE *conf = NULL;

int init() {
  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) == 0) {
    printf("SDL Could Not Init Video And Or Events\n");
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "FOO ERORR",
                             "FAILED To Init Video And Or Events", NULL);
    return 1;
  }
  win = SDL_CreateWindow("FOO", 800, 600, SDL_WINDOW_VULKAN);
  if (win == NULL) {
    printf("SDL ERROR: Can't Create Window\n");
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "FOO ERROR",
                             "FAILED To Make The Window", NULL);
    return 1;
  }
  ren = SDL_CreateRenderer(win, NULL);
  if (ren == NULL) {
    printf("SDL ERROR: Can't Create Renderer\n");
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "FOO ERROR",
                             "FAILED To Make Renderer", NULL);
    SDL_DestroyWindow(win);
    SDL_Quit();
    return 1;
  }
  conf = fopen("./conf.ini/", "rb");
  if (conf == NULL) {
    printf("WARNING: Could Not Find Config File\n");
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_WARNING, "FOO WARNINIG", "Could Not Find Config File", win);
    return 1;
  } else {
    return 0;
  }
  return 0;
}

SDL_Event e;
int shouldQuit = 1;

uint8_t red = 0;

int main() {
  init();

  while (shouldQuit) {
    while (SDL_PollEvent(&e)) {
      switch (e.type) {
      case SDL_EVENT_QUIT:
        shouldQuit = 0;
        break;
      case SDL_EVENT_KEY_DOWN:
        switch (e.key.key) {
          case SDLK_UP:
            red += 1;
            break;
          case SDLK_DOWN:

          case SDLK_LEFT:

          case SDLK_RIGHT:

          case SDLK_Z:

          case SDLK_X:

          case SDLK_C:
            red -= 10;
            break;
        }
      }
    }
    SDL_RenderClear(ren);
    SDL_SetRenderDrawColor(ren,red,128,200,255);
    SDL_RenderPresent(ren);
  }
  SDL_DestroyRenderer(ren);
  SDL_DestroyWindow(win);
  SDL_Quit();
  return 0;
}
