/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef FRONTENDAPPLICATIONBASE_HPP
#define FRONTENDAPPLICATIONBASE_HPP

#include <mvp/MVPApplication.hpp>
#include <gui/model/Model.hpp>

class FrontendHeap;

class FrontendApplicationBase : public touchgfx::MVPApplication
{
public:
    FrontendApplicationBase(Model& m, FrontendHeap& heap);
    virtual ~FrontendApplicationBase() { }

    virtual void changeToStartScreen()
    {
        gotoMENUScreenNoTransition();
    }

    // MENU
    void gotoMENUScreenNoTransition();

    void gotoMENUScreenSlideTransitionEast();

    // Instrucoes
    void gotoInstrucoesScreenNoTransition();

    // Configuracoes
    void gotoConfiguracoesScreenNoTransition();

    // Cadastro
    void gotoCadastroScreenNoTransition();

    // ScreenKeyboard
    void gotoScreenKeyboardScreenNoTransition();

    // Screen2
    void gotoScreen2ScreenNoTransition();

    // Screen1
    void gotoScreen1ScreenNoTransition();

protected:
    touchgfx::Callback<FrontendApplicationBase> transitionCallback;
    FrontendHeap& frontendHeap;
    Model& model;

    // MENU
    void gotoMENUScreenNoTransitionImpl();

    void gotoMENUScreenSlideTransitionEastImpl();

    // Instrucoes
    void gotoInstrucoesScreenNoTransitionImpl();

    // Configuracoes
    void gotoConfiguracoesScreenNoTransitionImpl();

    // Cadastro
    void gotoCadastroScreenNoTransitionImpl();

    // ScreenKeyboard
    void gotoScreenKeyboardScreenNoTransitionImpl();

    // Screen2
    void gotoScreen2ScreenNoTransitionImpl();

    // Screen1
    void gotoScreen1ScreenNoTransitionImpl();
};

#endif // FRONTENDAPPLICATIONBASE_HPP
