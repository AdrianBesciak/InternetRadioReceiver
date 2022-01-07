#include "PlayerRadioController.hpp"
#include <io/stream/network/HttpStream.hpp>

namespace controller {
    PlayerRadioController::PlayerRadioController(except::ExceptionTranslator &exceptionTranslator,
                                                 audio::AudioPlayer &audioPlayer,
                                                 model::PlayerModel &playerModel)
            : PlayerController(exceptionTranslator,
                               audioPlayer,
                               playerModel,
                               playerModel.getRadioPlaylist(),
                               model::PlayerModel::Mode::RADIO) {}

    std::shared_ptr<io::ReadStream> PlayerRadioController::makeReader(const std::string& source) {
        return std::make_shared<io::HttpStream>(source);
    }
}
