#pragma once
#include "PotionRecipe.hpp"
#include <string>
#include <vector>

class RecipeManager
{
private:
    std::vector<PotionRecipe> recipes; // ���� ������ �迭

public:
    // ���� ������ �߰� - �̸� + ��� ���
    PotionRecipe* addRecipe(const std::string& Name, const std::vector<std::string>& Ingredients);
    // ���� ������ �˻� - ���� �̸� 
    const PotionRecipe* findRecipeByName(const std::string& Name) const;
    // ���� ������ �˻� - ��� �̸�
    std::vector<const PotionRecipe*> findRecipesByIngredient(const std::string& Ingredient) const;
    // ���� ������ ��ȯ
    const std::vector<PotionRecipe>& getAllRecipes() const;
};
