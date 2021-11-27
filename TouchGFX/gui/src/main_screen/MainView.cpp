#include <gui/main_screen/MainView.hpp>

MainView::MainView()
{

}

void MainView::setupScreen()
{
    MainViewBase::setupScreen();
}

void MainView::tearDownScreen() {
    MainViewBase::tearDownScreen();
}

controls &MainView::getControls() {
    return controls1;
}
