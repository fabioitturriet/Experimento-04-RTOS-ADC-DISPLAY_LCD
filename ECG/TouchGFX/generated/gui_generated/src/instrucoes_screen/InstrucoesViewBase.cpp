/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/instrucoes_screen/InstrucoesViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <BitmapDatabase.hpp>
#include <texts/TextKeysAndLanguages.hpp>

InstrucoesViewBase::InstrucoesViewBase() :
    buttonCallback(this, &InstrucoesViewBase::buttonCallbackHandler),
    flexButtonCallback(this, &InstrucoesViewBase::flexButtonCallbackHandler),
    updateItemCallback(this, &InstrucoesViewBase::updateItemCallbackHandler)
{

    __background.setPosition(0, 0, 800, 480);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));

    box1.setPosition(0, 0, 800, 480);
    box1.setColor(touchgfx::Color::getColorFromRGB(20, 61, 89));

    scrollList1.setPosition(12, 80, 500, 320);
    scrollList1.setHorizontal(false);
    scrollList1.setCircular(false);
    scrollList1.setEasingEquation(touchgfx::EasingEquations::backEaseOut);
    scrollList1.setSwipeAcceleration(10);
    scrollList1.setDragAcceleration(10);
    scrollList1.setNumberOfItems(4);
    scrollList1.setPadding(0, 0);
    scrollList1.setSnapping(false);
    scrollList1.setDrawableSize(80, 0);
    scrollList1.setDrawables(scrollList1ListItems, updateItemCallback);

    image1.setXY(533, 124);
    image1.setBitmap(touchgfx::Bitmap(BITMAP_DEITADOEDIT_ID));

    textArea1.setXY(604, 81);
    textArea1.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textArea1.setLinespacing(0);
    textArea1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_NTIO));

    voltar.setXY(12, 10);
    voltar.setBitmaps(touchgfx::Bitmap(BITMAP_DARK_ICONS_BACK_ARROW_48_ID), touchgfx::Bitmap(BITMAP_DARK_ICONS_BACK_ARROW_48_ID));
    voltar.setAction(buttonCallback);

    CliqueImagem.setBoxWithBorderPosition(0, 0, 250, 311);
    CliqueImagem.setBorderSize(5);
    CliqueImagem.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 102, 153), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    CliqueImagem.setPosition(533, 126, 250, 311);
    CliqueImagem.setVisible(false);
    CliqueImagem.setAlpha(0);
    CliqueImagem.setAction(flexButtonCallback);

    textArea2.setXY(308, 0);
    textArea2.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textArea2.setLinespacing(0);
    textArea2.setTypedText(touchgfx::TypedText(T___SINGLEUSE_F1Q4));

    add(__background);
    add(box1);
    add(scrollList1);
    add(image1);
    add(textArea1);
    add(voltar);
    add(CliqueImagem);
    add(textArea2);
}

void InstrucoesViewBase::setupScreen()
{
    scrollList1.initialize();
    for (int i = 0; i < scrollList1ListItems.getNumberOfDrawables(); i++)
    {
        scrollList1ListItems[i].initialize();
    }
}

void InstrucoesViewBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &voltar)
    {
        //InteractionVoltar
        //When voltar clicked change screen to MENU
        //Go to MENU with no screen transition
        application().gotoMENUScreenNoTransition();
    }
}

void InstrucoesViewBase::flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src)
{
    if (&src == &CliqueImagem)
    {
        //InteractionCliqueImagem
        //When CliqueImagem clicked execute C++ code
        //Execute C++ code
        image1.invalidate();
        if(image1.getBitmap() == BITMAP_LOCAL_ELETRODOS_CORPO_ID){
        	image1.setBitmap(Bitmap(BITMAP_LOCAL_ELETRODOS_PEITO_ID));
        }else{
        	image1.setBitmap(Bitmap(BITMAP_LOCAL_ELETRODOS_CORPO_ID));
        }
        image1.invalidate();
    }
}

void InstrucoesViewBase::updateItemCallbackHandler(touchgfx::DrawableListItemsInterface* items, int16_t containerIndex, int16_t itemIndex)
{
    if (items == &scrollList1ListItems)
    {
        touchgfx::Drawable* d = items->getDrawable(containerIndex);
        ContainerListaDeInstrucoes* cc = (ContainerListaDeInstrucoes*)d;
        scrollList1UpdateItem(*cc, itemIndex);
    }
}