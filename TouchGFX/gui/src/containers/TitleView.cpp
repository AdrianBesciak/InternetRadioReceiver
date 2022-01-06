#include <gui/containers/TitleView.hpp>

TitleView::TitleView()
    : storedTitle() {}

void TitleView::setTitle(const std::string &title) {
    static Unicode::UnicodeChar buff[TITLETEXT_SIZE];

    if (title != storedTitle) {
        storedTitle = title;
        Unicode::fromUTF8(reinterpret_cast<const std::uint8_t*>(storedTitle.c_str()), buff, TITLETEXT_SIZE);
        Unicode::snprintf(titleTextBuffer, TITLETEXT_SIZE, "%s", buff);
        titleText.invalidate();
    }
}
