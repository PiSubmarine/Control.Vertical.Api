#pragma once

#include <variant>

#include "PiSubmarine/Ballast/BallastFillFraction.h"
#include "PiSubmarine/Meters.h"

namespace PiSubmarine::Control::Vertical::Api
{
    class Command
    {
    public:
        struct KeepCurrent
        {
            [[nodiscard]] constexpr bool operator==(const KeepCurrent&) const = default;
        };

        struct SetDepthTarget
        {
            Meters Depth;

            [[nodiscard]] constexpr bool operator==(const SetDepthTarget& other) const noexcept
            {
                return Depth.Value == other.Depth.Value;
            }
        };

        struct SetBallastPosition
        {
            ::PiSubmarine::Ballast::BallastFillFraction Position;

            [[nodiscard]] constexpr bool operator==(const SetBallastPosition&) const = default;
        };

        using Value = std::variant<KeepCurrent, SetDepthTarget, SetBallastPosition>;

        [[nodiscard]] static constexpr Command KeepCurrentValue() noexcept
        {
            return Command(KeepCurrent{});
        }

        [[nodiscard]] static constexpr Command SetDepthTargetTo(const Meters depth) noexcept
        {
            return Command(SetDepthTarget{depth});
        }

        [[nodiscard]] static constexpr Command SetBallastPositionTo(
            const ::PiSubmarine::Ballast::BallastFillFraction position) noexcept
        {
            return Command(SetBallastPosition{position});
        }

        [[nodiscard]] constexpr const Value& Get() const noexcept
        {
            return m_Value;
        }

        template<typename T>
        [[nodiscard]] constexpr bool Is() const noexcept
        {
            return std::holds_alternative<T>(m_Value);
        }

        template<typename T>
        [[nodiscard]] constexpr const T* TryGet() const noexcept
        {
            return std::get_if<T>(&m_Value);
        }

        [[nodiscard]] constexpr bool operator==(const Command&) const = default;

    private:
        constexpr explicit Command(const Value& value) noexcept
            : m_Value(value)
        {
        }

        Value m_Value;
    };
}
