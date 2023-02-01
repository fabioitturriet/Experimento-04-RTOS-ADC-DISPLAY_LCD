#include <gui/screen1_screen/Screen1View.hpp>

#include <texts/TextKeysAndLanguages.hpp>

#include <cstring>

 extern __IO uint8_t DerivSelecionada;
 extern "C" {
 enum Derivacoes{dev_I, dev_II, dev_III, dev_aVR, dev_aVL, dev_aVF, dev_V1, dev_V2, dev_V3, dev_V4, dev_V5, dev_V6};

 }

Screen1View::Screen1View()
{

}

void Screen1View::setupScreen()
{
    Screen1ViewBase::setupScreen();
}

void Screen1View::tearDownScreen()
{
    Screen1ViewBase::tearDownScreen();
}

void Screen1View::UpdateGraph(float value)
{
	dynamicGraph1.addDataPoint(value); //adiciona o valor em um ponto no gráfico

}

void Screen1View::StopData()
{
	presenter->PresenterStopData();
}

void Screen1View::AjusteEscala()
{
	presenter->PresenterAjusteEscala();
}

void Screen1View::SetMinMaxEscalaGraph(int16_t SetMinEscala, int16_t SetMaxEscala)
{
	dynamicGraph1.setGraphRangeY(SetMinEscala, SetMaxEscala);
}

void Screen1View::BackDeriv()
{
	presenter->PBackDeriv();
	AtualizaTextDerv();

}

void Screen1View::NextDeriv()
{
	presenter->PNextDeriv();
	AtualizaTextDerv();
}

void Screen1View::AtualizaTextDerv()
{
	textArea3.invalidate();
	switch (DerivSelecionada) {
	case dev_I:
		textArea3.setTypedText(TypedText(T_IDDEV1));
		break;
	case dev_II:
		textArea3.setTypedText(TypedText(T_IDDEV2));
		break;
	case dev_III:
		textArea3.setTypedText(TypedText(T_IDDEV3));
		break;
	case dev_aVR:
		textArea3.setTypedText(TypedText(T_IDDEV4));
		break;
	case dev_aVL:
		textArea3.setTypedText(TypedText(T_IDDEV5));
		break;
	case dev_aVF:
		textArea3.setTypedText(TypedText(T_IDDEV6));
		break;
	case dev_V1:
		textArea3.setTypedText(TypedText(T_IDDEV7));
		break;
	case dev_V2:
		textArea3.setTypedText(TypedText(T_IDDEV8));
		break;
	case dev_V3:
		textArea3.setTypedText(TypedText(T_IDDEV9));
		break;
	case dev_V4:
		textArea3.setTypedText(TypedText(T_IDDEV10));
		break;
	case dev_V5:
		textArea3.setTypedText(TypedText(T_IDDEV11));
		break;
	case dev_V6:
		textArea3.setTypedText(TypedText(T_IDDEV12));
		break;
	default:
		break;
	}
	textArea3.resizeToCurrentText();
	textArea3.invalidate();

}
