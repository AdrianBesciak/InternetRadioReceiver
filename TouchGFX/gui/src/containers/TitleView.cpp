#include <gui/containers/TitleView.hpp>

TitleView::TitleView()
    : storedTitle() {}

void TitleView::setTitle(const std::string &title) {
    static Unicode::UnicodeChar buff[TITLETEXT_SIZE];
    if (title != storedTitle) {
        storedTitle = title;
        Unicode::strncpy(buff, storedTitle.c_str(), TITLETEXT_SIZE);
        Unicode::snprintf(titleTextBuffer, TITLETEXT_SIZE, "%s", buff);
        titleText.invalidate();
    }
}
