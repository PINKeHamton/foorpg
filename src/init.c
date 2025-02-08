

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
    /*load the config file and wright it to vars*/

    return 0;
  }
  return 0;
}
