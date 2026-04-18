#pragma once

#include <gmock/gmock.h>

#include "PiSubmarine/Control/Vertical/Api/IController.h"

namespace PiSubmarine::Control::Vertical::Api
{
    class IControllerMock : public IController
    {
    public:
        MOCK_METHOD((Error::Api::Result<void>), SetTarget, (const Command& target), (override));
    };
}
