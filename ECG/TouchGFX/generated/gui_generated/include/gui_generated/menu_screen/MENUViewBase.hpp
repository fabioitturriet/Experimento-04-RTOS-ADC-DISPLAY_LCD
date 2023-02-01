/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef MENUVIEWBASE_HPP
#define MENUVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/menu_screen/MENUPresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/widgets/ButtonWithLabel.hpp>
#include <touchgfx/widgets/ScalableImage.hpp>

class MENUViewBase : public touchgfx::View<MENUPresenter>
{
public:
    MENUViewBase();
    virtual ~MENUViewBase() {}
    virtual void setupScreen();

    /*
     * Virtual Action Handlers
     */
    virtual void CadastroClicked()
    {
        // Override and implement this function in MENU
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
    touchgfx::Box box2;
    touchgfx::TextArea textArea1;
    touchgfx::ButtonWithLabel buttonExame;
    touchgfx::ButtonWithLabel buttonInstrucoes;
    touchgfx::ButtonWithLabel buttonConfiguracoes;
    touchgfx::ButtonWithLabel buttonCadastro;
    touchgfx::ScalableImage scalableImage1;
    touchgfx::ScalableImage scalableImage2;
    touchgfx::TextArea textArea2;

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<MENUViewBase, const touchgfx::AbstractButton&> buttonCallback;

    /*
     * Callback Handler Declarations
     */
    void buttonCallbackHandler(const touchgfx::AbstractButton& src);

};

#endif // MENUVIEWBASE_HPP
