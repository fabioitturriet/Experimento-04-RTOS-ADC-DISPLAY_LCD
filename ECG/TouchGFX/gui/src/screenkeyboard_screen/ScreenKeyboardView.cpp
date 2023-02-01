#include <gui/screenkeyboard_screen/ScreenKeyboardView.hpp>

extern "C" {
struct SSID
{
	char NomeRede[32];
	uint16_t Senha[18];
};
}
extern struct SSID Redes[10];

extern uint16_t KeyboardSelection;



ScreenKeyboardView::ScreenKeyboardView()
{
	//keyboard.setPosition(80, 16, 420, 340);
	keyboard.setPosition(80, 16, 320, 240); //add
    add(keyboard); //add
}

void ScreenKeyboardView::setupScreen()
{
    ScreenKeyboardViewBase::setupScreen();
}

void ScreenKeyboardView::tearDownScreen()
{
    ScreenKeyboardViewBase::tearDownScreen();
}

void ScreenKeyboardView::getBuffer()
{
	Unicode::UnicodeChar* buff = keyboard.getBuffer();
	Unicode::strncpy(Redes[KeyboardSelection].Senha, buff, Unicode::strlen(buff)+1);
	presenter->PConnectWiFi();
}
