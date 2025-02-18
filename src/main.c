#include <SDL3/SDL_events.h>
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_keycode.h>
#include <SDL3/SDL_messagebox.h>
#include <SDL3/SDL_mutex.h>
#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_video.h>
#include <stdint.h>
#include <stdio.h>

SDL_Window *win = NULL;
SDL_GLContext cont = NULL;
int shouldQuit = 0;
SDL_Event e;

void update() {
  while (SDL_PollEvent(&e)) {
    switch (e.type) {
    case SDL_EVENT_QUIT:
      shouldQuit = 1;
      break;
    case SDL_EVENT_KEY_DOWN:
      switch (e.key.key) {
      case SDLK_C:
        break;
      }
    }
  }
}

void loop() {
  while (!shouldQuit) {
    update();
  }
}

int main() {
  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) == 0) {
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "FOO ERORR",
                             "FAILED To Init Video And Or Events", NULL);
    return SDL_SetError("FOO ERROR: FAILED To Init Video And Or Events %d", 1);
  }
  win = SDL_CreateWindow("FOO", 800, 600, SDL_WINDOW_OPENGL);
  if (win == NULL) {
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "FOO ERROR",
                             "FAILED To Make The Window", NULL);
    return SDL_SetError("FOO ERROR: FAILED To Create Window %d", 1);
  }
  cont = SDL_GL_CreateContext(win);
  if (cont == NULL) {
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "FOO ERROR",
                             "FAILED To Make Renderer", NULL);
    SDL_DestroyWindow(win);
    SDL_Quit();
    return SDL_SetError("FOO ERROR: FAILED To Create Renderer %d", 1);
  }
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6);

  loop();

  SDL_GL_DestroyContext(cont);
  SDL_DestroyWindow(win);
  SDL_Quit();
  return 0;
}
