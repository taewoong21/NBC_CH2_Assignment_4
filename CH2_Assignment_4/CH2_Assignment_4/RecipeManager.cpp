#include "RecipeManager.hpp"
#include <algorithm>

// ���� ������ �߰� - �̸� + ��� ���
PotionRecipe* RecipeManager::addRecipe(const std::string& Name, const std::vector<std::string>& Ingredients)
{
    // emplack_back() ������� vector<PotionRecipe> ��ü ���� �� �߰� ���� ����
    recipes.emplace_back(Name, Ingredients);
    
    return &recipes.back(); // �߰��� ������ ��ȯ
}

// ���� ������ �˻� - ���� �̸� 
const PotionRecipe* RecipeManager::findRecipeByName(const std::string& Name) const
{
    // PotionRecipe Ŭ������ �� ������ ���� find_if() ���
    // find() ��� �� std::string�� PotionRecipe�� == �����ڸ� ����� �� �Ұ�
    const auto It = std::find_if(recipes.begin(), recipes.end(), [&Name](const PotionRecipe& R) { return R.PotionName == Name; });
    
    // �˻� ����� ���� ��, nullptr ��ȯ
    if (It == recipes.end()) return nullptr;
    
    // �˻� ���� ��, �ش� ������ ��ȯ
    return &(*It);
}

// ���� ������ �˻� - ��� �̸�
std::vector<const PotionRecipe*> RecipeManager::findRecipesByIngredient(const std::string& Ingredient) const
{
    // �˻� ��� ������
    std::vector<const PotionRecipe*> Result;


    for (const PotionRecipe& R : recipes)
    {
        // ���� ���� ������ Ž��
        bool Has = std::find(R.Ingredients.begin(), R.Ingredients.end(), Ingredient) != R.Ingredients.end();
        
        // �˻� ���� ��, ��� ����
        if (Has) Result.push_back(&R);
    }
    return Result; // �˻� ��� ��ȯ
}

// ���� ������ ��ȯ
const std::vector<PotionRecipe>& RecipeManager::getAllRecipes() const
{
    return recipes; // ������ ��ȯ
}
