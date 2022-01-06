#include <gui/containers/ErrorDialog.hpp>

ErrorDialog::ErrorDialog()
    : onErrorDismissRequested(nullptr)
    , storedErrorMessage() {
    errorMessageText.setWideTextAction(WIDE_TEXT_WORDWRAP);
}

void ErrorDialog::setOnErrorDismissRequested(const std::function<void()> &onErrorDismissRequested) {
    this->onErrorDismissRequested = onErrorDismissRequested;
}

void ErrorDialog::setErrorMessage(const std::string &errorMessage) {
    static Unicode::UnicodeChar buff[ERRORMESSAGETEXT_SIZE];

    if (errorMessage != storedErrorMessage) {
        storedErrorMessage = errorMessage;
        Unicode::strncpy(buff, storedErrorMessage.c_str(), ERRORMESSAGETEXT_SIZE);
        Unicode::snprintf(errorMessageTextBuffer, ERRORMESSAGETEXT_SIZE, "%s", buff);
        errorMessageText.invalidate();

        setVisible(!storedErrorMessage.empty());
        invalidate();
    }
}


void ErrorDialog::handleDismissButtonClicked() {
    if (onErrorDismissRequested != nullptr) {
        onErrorDismissRequested();
    }
}
