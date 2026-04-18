#include <gtest/gtest.h>

#include "PiSubmarine/Control/Vertical/Api/IControllerMock.h"

namespace PiSubmarine::Control::Vertical::Api
{
    TEST(IControllerMockTest, SupportsSettingVerticalTarget)
    {
        IControllerMock controller;
        const auto target = Command::SetDepthTargetTo(3.5_m);

        EXPECT_CALL(controller, SetTarget(target))
            .WillOnce(testing::Return(Error::Api::Result<void>{}));

        EXPECT_TRUE(controller.SetTarget(target).has_value());
    }
}
