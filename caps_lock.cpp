#define _WIN32_WINNT 0x403
#include <windows.h>

// main etc...
//
//

void migajCapsLock()
{
	INPUT in[2];                                //przygotuj strukture na dwa zdarzenia in[0] wcisniecie klawisza
												//in[1] wycisniecie klawisza
	in[0].type = INPUT_KEYBOARD;                //wcisniecie klawisza na klawiaturze
	in[0].ki.wVk = VK_CAPITAL;                    //jaki klawisz - CAPSLOCK
	in[0].ki.wScan = 0;
	in[0].ki.time = 0;
	in[0].ki.dwFlags = 0;                        //jesli 0 to akcja wcisniecia klawisza
	in[0].ki.dwExtraInfo = 0;

	in[1] = in[0];                                //szykujemy strukture na wycisniecie klawisza. Jest taka sama poza
	in[1].ki.dwFlags = KEYEVENTF_KEYUP;            //tym ze teraz wykonujemy akacje wycisniecia klawisza

	for (int i = 0; i < 6; i++)                    // wykonaj 6 razy petle
	{
		::SendInput(2, in, sizeof(INPUT));        // wyslij w kolejke komunikatow 2 zdarzenia opisane strukturami zaczynajacymi
												// sie na wskazniku in.
												// oznacza to symulacje pracy urzytkownika. W naszym przypadku urzytkownik
												// wcisnal a potem wycisnal klawisz CAPSLOCK
												//powoduje to zmiane stanu diody CAPSLOCK
		::Sleep(300);                            // czekamy 300msec zanim pojdziemy dalej
	}
}