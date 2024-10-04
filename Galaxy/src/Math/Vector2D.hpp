#pragma once

#include <string>
#include <sstream>

namespace Galaxy
{
    namespace Math
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
            /// @return Information for logger, std::string
            std::string ToString() const;
            /// @brief Operator to add two 2 dimensional vectors together component wise
            /// @param other vector to be added to this vector, Vector2D
            /// @return New vector with its components being the sum of the components in this and other, Vector2D 
            Vector2D operator+(Vector2D other);
            /// @brief Operator to subtract a 2 dimensional vector from this vector component wise
            /// @param other vector to be subtracted from to this vector, Vector2D
            /// @return New vector with its components being the difference of the components between this and other, Vector2D 
            Vector2D operator-(Vector2D other);
            /// @brief Operator to multiply a 2 dimensional vector with a scalar value
            /// @param a scalar value to multiply components of the vector with, float
            /// @return New vector with its components being the components of this multiplied by a
            Vector2D operator*(float a);
            /// @brief Operator to check if 2 vectors are equal
            /// @param other the other vector to check this against
            /// @return true if they are equal mathematically, false if not
            bool operator==(const Vector2D other);
            ~Vector2D() = default;
        };
    }
}