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

struct sConf{
  SDL_Keycode LEFT;
  SDL_Keycode RIGHT;
  SDL_Keycode UP;
  SDL_Keycode DOWN;
  SDL_Keycode ATTCK;
  SDL_Keycode ALT;
  SDL_Keycode USE;
  SDL_Keycode JUMP;
  SDL_Keycode CROUCH_MOD;
  SDL_Keycode RUN_MOD;
  SDL_Keycode PAUSE;
  int WIN_HEIGHT;
  int WIN_WIDTH;
}SConf;

int init() {
  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) == 0) {
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "FOO ERORR",
                             "FAILED To Init Video And Or Events", NULL);
    return SDL_SetError("FOO ERROR: FAILED To Init Video And Or Events %d", 1);
  }
  win = SDL_CreateWindow("FOO", 800, 600, SDL_WINDOW_VULKAN);
  if (win == NULL) {
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "FOO ERROR",
                             "FAILED To Make The Window", NULL);
    return SDL_SetError("FOO ERROR: FAILED To Create Window %d", 1);
  }
  ren = SDL_CreateRenderer(win, NULL);
  if (ren == NULL) {
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "FOO ERROR",
                             "FAILED To Make Renderer", NULL);
    SDL_DestroyWindow(win);
    SDL_Quit();
    return SDL_SetError("FOO ERROR: FAILED To Create Renderer %d", 1);
  }
  conf = fopen("conf.ini/", "rb");
  if (conf == NULL) {
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_WARNING, "FOO WARNINIG",
                             "Could Not Find Config File", win);
    return SDL_SetError("FOO WARNING: FAILED To Find `conf.ini` %d", 1);
  }
  return 0;
}

SDL_Event e;
int shouldQuit = 1;

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
            
              break;
          case SDLK_DOWN:
            
              break;
          case SDLK_LEFT:
            
              break;
          case SDLK_RIGHT:
            
              break;
          case SDLK_Z:
            
              break;
          case SDLK_X:
              
              break;
          case SDLK_C:
              
              break;
        }
      }
    }
    SDL_RenderClear(ren);
    SDL_SetRenderDrawColor(ren,10,128,200,255);

    SDL_RenderPresent(ren);
  }
  SDL_DestroyRenderer(ren);
  SDL_DestroyWindow(win);
  SDL_Quit();
  return 0;
}
