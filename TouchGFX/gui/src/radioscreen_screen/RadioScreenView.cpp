#include <gui/radioscreen_screen/RadioScreenView.hpp>

RadioScreenView::RadioScreenView()
    : title() {
}

controls &RadioScreenView::getControls() {
    return controls1;
}

void RadioScreenView::setTitle(const std::string &title) {
    if (this->title != title) {
        this->title = title;
    }
}

void RadioScreenView::setPlayVisible(bool visible) {
    radioControlPanel1.setPlayVisible(visible);
}

void RadioScreenView::setStopVisible(bool visible) {
    radioControlPanel1.setStopVisible(visible);
}
