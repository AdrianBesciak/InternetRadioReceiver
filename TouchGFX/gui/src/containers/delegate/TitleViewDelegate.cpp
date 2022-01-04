#include <gui/containers/delegate/TitleViewDelegate.hpp>

TitleViewDelegate::~TitleViewDelegate() = default;

void TitleViewDelegate::setTitle(const std::string &title) {
    getTitleView().setTitle(title);
}
