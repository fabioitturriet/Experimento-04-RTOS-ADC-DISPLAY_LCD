/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef INSTRUCOESVIEWBASE_HPP
#define INSTRUCOESVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/instrucoes_screen/InstrucoesPresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/containers/scrollers/ScrollList.hpp>
#include <gui/containers/ContainerListaDeInstrucoes.hpp>
#include <touchgfx/widgets/Image.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/widgets/Button.hpp>
#include <touchgfx/containers/buttons/Buttons.hpp>

class InstrucoesViewBase : public touchgfx::View<InstrucoesPresenter>
{
public:
    InstrucoesViewBase();
    virtual ~InstrucoesViewBase() {}
    virtual void setupScreen();

    virtual void scrollList1UpdateItem(ContainerListaDeInstrucoes& item, int16_t itemIndex)
    {
        // Override and implement this function in Instrucoes
    }

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box __background;
    touchgfx::Box box1;
    touchgfx::ScrollList scrollList1;
    touchgfx::DrawableListItems<ContainerListaDeInstrucoes, 5> scrollList1ListItems;
    touchgfx::Image image1;
    touchgfx::TextArea textArea1;
    touchgfx::Button voltar;
    touchgfx::BoxWithBorderButtonStyle< touchgfx::ClickButtonTrigger > CliqueImagem;
    touchgfx::TextArea textArea2;

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<InstrucoesViewBase, const touchgfx::AbstractButton&> buttonCallback;
    touchgfx::Callback<InstrucoesViewBase, const touchgfx::AbstractButtonContainer&> flexButtonCallback;
    touchgfx::Callback<InstrucoesViewBase, touchgfx::DrawableListItemsInterface*, int16_t, int16_t> updateItemCallback;

    /*
     * Callback Handler Declarations
     */
    void buttonCallbackHandler(const touchgfx::AbstractButton& src);
    void flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src);
    void updateItemCallbackHandler(touchgfx::DrawableListItemsInterface* items, int16_t containerIndex, int16_t itemIndex);

};

#endif // INSTRUCOESVIEWBASE_HPP
