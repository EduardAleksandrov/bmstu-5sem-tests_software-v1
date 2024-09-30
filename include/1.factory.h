#include <iostream>
#include <memory>
#include <string>

// Базовый класс
class Shape {
public:
    virtual std::string draw() const = 0;
    virtual ~Shape() = default;
};

// Конкретные классы
class Circle : public Shape {
public:
    std::string draw() const override {
        return "Drawing a Circle";
    }
};

class Square : public Shape {
public:
    std::string draw() const override {
        return "Drawing a Square";
    }
};

// Фабрика
class ShapeFactory {
public:
    std::unique_ptr<Shape> createShape(const std::string& shapeType) {
        if (shapeType == "Circle") {
            return std::make_unique<Circle>();
        } else if (shapeType == "Square") {
            return std::make_unique<Square>();
        }
        return nullptr;
    }
};