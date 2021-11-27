#include <gui/radioscreen_screen/RadioScreenView.hpp>

RadioScreenView::RadioScreenView()
{

}

void RadioScreenView::setupScreen()
{
    RadioScreenViewBase::setupScreen();
}

void RadioScreenView::tearDownScreen()
{
    RadioScreenViewBase::tearDownScreen();
}

controls &RadioScreenView::getControls() {
    return controls1;
}
