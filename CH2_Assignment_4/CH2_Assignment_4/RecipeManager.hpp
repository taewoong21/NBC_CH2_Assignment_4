#pragma once
#include "PotionRecipe.hpp"
#include <string>
#include <vector>

class RecipeManager
{
private:
    std::vector<PotionRecipe> recipes; // 포션 레시피 배열

public:
    // 포션 레시피 추가 - 이름 + 재료 목록
    PotionRecipe* addRecipe(const std::string& Name, const std::vector<std::string>& Ingredients);
    // 포션 레시피 검색 - 포션 이름 
    const PotionRecipe* findRecipeByName(const std::string& Name) const;
    // 포션 레시피 검색 - 재료 이름
    std::vector<const PotionRecipe*> findRecipesByIngredient(const std::string& Ingredient) const;
    // 포션 레시피 반환
    const std::vector<PotionRecipe>& getAllRecipes() const;
};
