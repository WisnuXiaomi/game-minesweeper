#include <Windows.h>
#include "MMSystem.h"

void play_music(){
	
	PlaySound(TEXT("Musik_Minesweeper.wav"),NULL, SND_SYNC);
	system("pause");
		
}
