/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/menu_screen/MENUViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include <BitmapDatabase.hpp>

MENUViewBase::MENUViewBase() :
    buttonCallback(this, &MENUViewBase::buttonCallbackHandler)
{

    __background.setPosition(0, 0, 800, 480);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));

    box1.setPosition(0, 0, 800, 123);
    box1.setColor(touchgfx::Color::getColorFromRGB(20, 61, 89));

    box2.setPosition(0, 123, 800, 357);
    box2.setColor(touchgfx::Color::getColorFromRGB(244, 180, 26));

    textArea1.setXY(195, 11);
    textArea1.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textArea1.setLinespacing(0);
    textArea1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_2B6S));

    buttonExame.setXY(220, 382);
    buttonExame.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_SQUARE_LARGE_ID), touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_SQUARE_LARGE_PRESSED_ID));
    buttonExame.setLabelText(touchgfx::TypedText(T___SINGLEUSE_NZSU));
    buttonExame.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    buttonExame.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));
    buttonExame.setAction(buttonCallback);

    buttonInstrucoes.setXY(220, 202);
    buttonInstrucoes.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_SQUARE_LARGE_ID), touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_SQUARE_LARGE_PRESSED_ID));
    buttonInstrucoes.setLabelText(touchgfx::TypedText(T___SINGLEUSE_BK3R));
    buttonInstrucoes.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    buttonInstrucoes.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));
    buttonInstrucoes.setAction(buttonCallback);

    buttonConfiguracoes.setXY(220, 262);
    buttonConfiguracoes.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_SQUARE_LARGE_ID), touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_SQUARE_LARGE_PRESSED_ID));
    buttonConfiguracoes.setLabelText(touchgfx::TypedText(T___SINGLEUSE_A6V4));
    buttonConfiguracoes.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    buttonConfiguracoes.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));
    buttonConfiguracoes.setAction(buttonCallback);

    buttonCadastro.setXY(220, 322);
    buttonCadastro.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_SQUARE_LARGE_ID), touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_SQUARE_LARGE_PRESSED_ID));
    buttonCadastro.setLabelText(touchgfx::TypedText(T___SINGLEUSE_FDRA));
    buttonCadastro.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    buttonCadastro.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));
    buttonCadastro.setAction(buttonCallback);

    scalableImage1.setBitmap(touchgfx::Bitmap(BITMAP_LOGO_TECH4HEALTH_ID));
    scalableImage1.setPosition(605, 236, 169, 173);
    scalableImage1.setScalingAlgorithm(touchgfx::ScalableImage::NEAREST_NEIGHBOR);

    scalableImage2.setBitmap(touchgfx::Bitmap(BITMAP_VERSAOVERTICAL_RESIZED_ID));
    scalableImage2.setPosition(24, 209, 176, 227);
    scalableImage2.setScalingAlgorithm(touchgfx::ScalableImage::NEAREST_NEIGHBOR);

    textArea2.setXY(96, 71);
    textArea2.setColor(touchgfx::Color::getColorFromRGB(244, 180, 26));
    textArea2.setLinespacing(0);
    textArea2.setTypedText(touchgfx::TypedText(T___SINGLEUSE_IJ05));

    add(__background);
    add(box1);
    add(box2);
    add(textArea1);
    add(buttonExame);
    add(buttonInstrucoes);
    add(buttonConfiguracoes);
    add(buttonCadastro);
    add(scalableImage1);
    add(scalableImage2);
    add(textArea2);
}

void MENUViewBase::setupScreen()
{

}

void MENUViewBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &buttonExame)
    {
        //Interaction2
        //When buttonExame clicked change screen to Screen2
        //Go to Screen2 with no screen transition
        application().gotoScreen2ScreenNoTransition();
    }
    else if (&src == &buttonInstrucoes)
    {
        //InteracaoInstrucoes
        //When buttonInstrucoes clicked change screen to Instrucoes
        //Go to Instrucoes with no screen transition
        application().gotoInstrucoesScreenNoTransition();
    }
    else if (&src == &buttonConfiguracoes)
    {
        //InteracaoConfiguracoes
        //When buttonConfiguracoes clicked change screen to Configuracoes
        //Go to Configuracoes with no screen transition
        application().gotoConfiguracoesScreenNoTransition();
    }
    else if (&src == &buttonCadastro)
    {
        //InteracaoCadastro
        //When buttonCadastro clicked change screen to Cadastro
        //Go to Cadastro with no screen transition
        application().gotoCadastroScreenNoTransition();

        //CadastroClicked
        //When buttonCadastro clicked call virtual function
        //Call CadastroClicked
        CadastroClicked();
    }
}
