#include "Vector2D.hpp"

namespace Galaxy
{
    namespace Math
    {
        Vector2D::Vector2D() :x(0.0f), y(0.0f)
        {}

        Vector2D::Vector2D(float x, float y) :x(x), y(y)
        {}

        float Vector2D::GetX() const
        {
            return this->x;
        }

        float Vector2D::GetY() const
        {
            return this->y;
        }

        void Vector2D::SetX(float x)
        {
            this->x = x;
        }

        void Vector2D::SetY(float y)
        {
            this->y = y;
        }

        std::string Vector2D::ToString() const
        {
            std::stringstream ss;
            ss << "(x: " << this->x << " , ";
            ss << "y: " << this->y << ")";
            return ss.str();
        }

        Vector2D Vector2D::operator+(Vector2D other)
        {
            Vector2D added(other.GetX() + this->x, other.GetY() + this->y);
            return added;
        }

        Vector2D Vector2D::operator-(Vector2D other)
        {
            Vector2D subtracted(other.GetX() - this->x, other.GetY() - this->y);
            return subtracted;
        }

        Vector2D Vector2D::operator*(float a)
        {
            Vector2D multiplied(this->x * a, this->y * a);
            return multiplied;
        }

        bool Vector2D::operator==(Vector2D other)
        {
            return this->x == other.x && this->y == other.y;
        }
    }
}