#include <gtest/gtest.h>

#include "PiSubmarine/Control/Vertical/Api/Command.h"

namespace PiSubmarine::Control::Vertical::Api
{
    TEST(CommandTest, KeepCurrentCreatesKeepCurrentValue)
    {
        constexpr auto command = Command::KeepCurrentValue();

        static_assert(command.Is<Command::KeepCurrent>());
        EXPECT_TRUE(command.Is<Command::KeepCurrent>());
        EXPECT_NE(command.TryGet<Command::KeepCurrent>(), nullptr);
    }

    TEST(CommandTest, SetDepthTargetStoresDepth)
    {
        constexpr auto command = Command::SetDepthTargetTo(2.5_m);

        static_assert(command.Is<Command::SetDepthTarget>());
        const auto* depthTarget = command.TryGet<Command::SetDepthTarget>();

        ASSERT_NE(depthTarget, nullptr);
        EXPECT_EQ(depthTarget->Depth.Value, 2.5);
    }

    TEST(CommandTest, SetBallastPositionStoresPosition)
    {
        const auto command = Command::SetBallastPositionTo(NormalizedFraction(0.75));
        const auto* ballastPosition = command.TryGet<Command::SetBallastPosition>();

        ASSERT_NE(ballastPosition, nullptr);
        EXPECT_EQ(static_cast<double>(ballastPosition->Position), 0.75);
    }
}
