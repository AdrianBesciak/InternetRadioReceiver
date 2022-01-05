#pragma once
#include <gui_generated/containers/ErrorDialogBase.hpp>
#include <functional>

class ErrorDialog : public ErrorDialogBase {
public:
    ErrorDialog();

    void setOnErrorDismissRequested(const std::function<void()> &onErrorDismissRequested);
    void setErrorMessage(const std::string &errorMessage);

protected:
    void handleDismissButtonClicked() override;

private:
    std::function<void()> onErrorDismissRequested;
    std::string storedErrorMessage;
};
