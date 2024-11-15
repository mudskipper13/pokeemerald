#ifndef GUARD_UI_MAIN_MENU_H
#define GUARD_UI_MAIN_MENU_H

#include "main.h"

void Task_OpenMainMenu(u8 taskId);
void MainMenu_Init(MainCallback callback);
void LoadMugshotIconGraphics(void);
u16 CreateMugshotExternal();
void TrainerStats_OpenMainMenu(void);

#endif // GUARD_UI_MENU_H
