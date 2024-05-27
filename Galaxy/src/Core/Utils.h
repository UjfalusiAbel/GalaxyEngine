#pragma once
#include <memory>

namespace Galaxy
{
    template<typename T>
    using Scoped = std::unique_ptr<T>;
    template<typename T, typename ... Args>
    constexpr Scoped<T> CreateScoped(Args&& ... args)
    {
        return std::make_unique<T>(std::forward<Args>(args)...);
    }

    template<typename T>
    using Reference = std::shared_ptr<T>;
    template<typename T, typename ... Args>
    constexpr Reference<T> CreateReference(Args&& ... args)
    {
        return std::make_shared<T>(std::forward<Args>(args)...);
    }
}