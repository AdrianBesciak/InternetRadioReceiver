#pragma once
#include <gui_generated/containers/TitleViewBase.hpp>

class TitleView : public TitleViewBase {
public:
    TitleView();
    void initialize() override;

    void setTitle(const std::string &title);

private:
    std::string storedTitle;
};
