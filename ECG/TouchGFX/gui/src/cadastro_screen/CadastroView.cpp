#include <gui/cadastro_screen/CadastroView.hpp>
#include <gui/containers/ContainerConexaoWIFI.hpp>

#include "stm32f7xx_hal.h"

uint16_t KeyboardSelection;

CadastroView::CadastroView() :
scrollList1_ItemSelectedCallback(this, &CadastroView::scrollList1_ItemSelectedHandler)
{

}

void CadastroView::setupScreen()
{
	scrollList1.setItemSelectedCallback(scrollList1_ItemSelectedCallback);
    CadastroViewBase::setupScreen();
}

void CadastroView::tearDownScreen()
{
    CadastroViewBase::tearDownScreen();
}

void CadastroView::initCadastro()
{
	if(HAL_GPIO_ReadPin(GPIOH, GPIO_PIN_7)){
		 toggleInitWIFI.forceState(true);
		 presenter->PAtualizarRedes();
		 buttonAtualizarRedes.setTouchable(true);
		 buttonAtualizarRedes.setAlpha(255);
		 buttonAtualizarRedes.invalidate();
		 toggleInitWIFI.invalidate();
	}else{
		 toggleInitWIFI.forceState(false);
		 buttonAtualizarRedes.setTouchable(false);
		 buttonAtualizarRedes.setAlpha(100);
		 buttonAtualizarRedes.invalidate();
		 toggleInitWIFI.invalidate();
	}
}

void CadastroView::ToggleWiFi()
{
	if (toggleInitWIFI.getState()){
		presenter->P_InitESP();
		presenter->PAtualizarRedes();
		buttonAtualizarRedes.setTouchable(true);
		buttonAtualizarRedes.setAlpha(255);
		buttonAtualizarRedes.invalidate();
	}else{
		presenter->PWiFi_OFF();
		buttonAtualizarRedes.setTouchable(false);
		buttonAtualizarRedes.setAlpha(100);
		buttonAtualizarRedes.invalidate();
	}

}

void CadastroView::scrollList1UpdateItem(ContainerConexaoWIFI& item, int16_t itemIndex)
{
	item.setListElements(itemIndex);
}


void CadastroView::itensAlterados()
{
	scrollList1.invalidate();
}

void CadastroView::AtualizarRedes()
{
	presenter->PAtualizarRedes();
}

void CadastroView::defnumredes(uint8_t NumeroRedes)
{
	scrollList1.setNumberOfItems(NumeroRedes);
	for(uint8_t i=0;i<NumeroRedes;i++)
	scrollList1.itemChanged(i);
}

void CadastroView::scrollList1_ItemSelectedHandler(int16_t itemSelected)
{
	KeyboardSelection = itemSelected;
	application().gotoScreenKeyboardScreenNoTransition();
}
