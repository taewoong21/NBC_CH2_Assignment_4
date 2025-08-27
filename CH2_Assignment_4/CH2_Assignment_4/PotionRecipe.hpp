#pragma once
#include <string>
#include <vector>

class PotionRecipe
{
public:
    std::string PotionName; // ǥ�Ǹ�
    std::vector<std::string> Ingredients; // ���

    // ���� ������ ���� (�̸� + ���)
    PotionRecipe(const std::string& Name, const std::vector<std::string>& InIngredients);
};
