#pragma once
#include <string>
#include <vector>

class PotionRecipe
{
public:
    std::string PotionName; // 표션명
    std::vector<std::string> Ingredients; // 재료

    // 포션 레시피 생성 (이름 + 재료)
    PotionRecipe(const std::string& Name, const std::vector<std::string>& InIngredients);
};
