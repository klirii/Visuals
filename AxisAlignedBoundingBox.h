#pragma once

#include <glm/glm.hpp>
#include <vector>

struct bbox3
{
    glm::vec3 min{ std::numeric_limits<float>::max() },
        max{ std::numeric_limits<float>::lowest() };
};

// 2D AABB, понадобится позже
struct bbox2
{
    glm::vec2 min{ std::numeric_limits<float>::max() },
        max{ std::numeric_limits<float>::lowest() };

    bbox2() {
        min = glm::vec2{ std::numeric_limits<float>::max() };
        max = glm::vec2{ std::numeric_limits<float>::lowest() };
    }
};

struct object_data
{
    glm::mat4 modelview; // GL_MODELVIEW_MATRIX, каждый кадр
    bbox3 bb;// AABB объекта, считается один раз, НЕ каждый кадр, если игнорировать анимацию
};

struct boxes
{
    // матрица проекции
    glm::mat4 projection; // GL_PROJECTION_MATRIX, каждый кадр
    // данные объекта

    std::vector<object_data> entity_objects; // вектор объектов, для которых нужно построить 2D bbox
    std::vector<object_data> chest_objects; // вектор объектов, для которых нужно построить 2D bbox
    std::vector<object_data> large_chest_objects; // вектор объектов, для которых нужно построить 2D bbox
};