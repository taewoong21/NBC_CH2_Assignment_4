#pragma once
#include "RecipeManager.hpp"
#include "StockManager.hpp"
#include <string>
#include <vector>

class AlchemyWorkshop
{
private:
    RecipeManager rManager; // ������ ����
    StockManager  sManager; // ��� ����

public:
    // ������ �߰�
    void addRecipe(const std::string& Name, const std::vector<std::string>& Ingredients);
    // ��� ������ ���
    void displayAllRecipes() const;

    // �˻�
    const PotionRecipe* searchRecipeByName(const std::string& Name) const;
    std::vector<const PotionRecipe*> searchRecipeByIngredient(const std::string& Ingredient) const;

    // ���
    int getStock(const std::string& Name) const;
    bool dispense(const std::string& Name);
    void giveBackEmptyBottle(const std::string& Name);
};
