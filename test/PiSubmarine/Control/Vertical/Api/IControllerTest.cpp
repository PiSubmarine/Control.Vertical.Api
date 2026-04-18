#include <gtest/gtest.h>

#include <type_traits>

#include "PiSubmarine/Control/Vertical/Api/IController.h"

namespace PiSubmarine::Control::Vertical::Api
{
    TEST(IControllerTest, HasVirtualDestructor)
    {
        static_assert(std::has_virtual_destructor_v<IController>);
        SUCCEED();
    }
}
