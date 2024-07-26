#pragma once

#include <glm/glm.hpp>
#include <vector>

struct bbox3
{
    glm::vec3 min{ std::numeric_limits<float>::max() },
        max{ std::numeric_limits<float>::lowest() };
};

// 2D AABB, ����������� �����
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
    glm::mat4 modelview; // GL_MODELVIEW_MATRIX, ������ ����
    bbox3 bb;// AABB �������, ��������� ���� ���, �� ������ ����, ���� ������������ ��������
};

struct boxes
{
    // ������� ��������
    glm::mat4 projection; // GL_PROJECTION_MATRIX, ������ ����
    // ������ �������

    std::vector<object_data> entity_objects; // ������ ��������, ��� ������� ����� ��������� 2D bbox
    std::vector<object_data> chest_objects; // ������ ��������, ��� ������� ����� ��������� 2D bbox
    std::vector<object_data> large_chest_objects; // ������ ��������, ��� ������� ����� ��������� 2D bbox
};