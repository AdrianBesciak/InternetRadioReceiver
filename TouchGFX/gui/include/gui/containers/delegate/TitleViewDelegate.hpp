#pragma once
#include <gui/containers/TitleView.hpp>

class TitleViewDelegate {
public:
    virtual ~TitleViewDelegate();

    void setTitle(const std::string &title);

protected:
    virtual TitleView& getTitleView() = 0;
};


