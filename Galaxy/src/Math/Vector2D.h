#pragma once

#include <string>
#include <sstream>

namespace Galaxy
{
    /// @brief Vector class with vector operations for algebraically representing 2 dimensional vectors
    class Vector2D
    {
    private:
        float x;
        float y;
    public:
        /// @brief Creates a 2 dimensional vector with both x and y component set to 0
        Vector2D();
        /// @brief Creates a 2 dimensional vector with given x and y components
        /// @param x float, x component of 2 dimensional vector
        /// @param y float, y component of 2 dimensional vector
        Vector2D(float x, float y);
        /// @brief Gets the x component of a 2 dimensional vector
        /// @return x component of vector, float
        float GetX() const;
        /// @brief Gets the y component of a 2 dimensional vector
        /// @return y component of vector, float
        float GetY() const;
        /// @brief Sets the x component of a 2 dimensional vector
        void SetX(float x);
        /// @brief Sets the y component of a 2 dimensional vector
        void SetY(float y);
        /// @brief Creates string information for debug purposes about data in vector, showing both the x and y component
        /// @return information for logger, std::string
        std::string ToString() const;
        ~Vector2D() = default;
    };
}