/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef CONTAINERLISTADEINSTRUCOESBASE_HPP
#define CONTAINERLISTADEINSTRUCOESBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <touchgfx/containers/Container.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/widgets/Image.hpp>
#include <touchgfx/widgets/ToggleButton.hpp>

class ContainerListaDeInstrucoesBase : public touchgfx::Container
{
public:
    ContainerListaDeInstrucoesBase();
    virtual ~ContainerListaDeInstrucoesBase() {}
    virtual void initialize();

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box box1;
    touchgfx::TextArea textArea1;
    touchgfx::Image image2;
    touchgfx::ToggleButton toggleButton1;

private:

};

#endif // CONTAINERLISTADEINSTRUCOESBASE_HPP
