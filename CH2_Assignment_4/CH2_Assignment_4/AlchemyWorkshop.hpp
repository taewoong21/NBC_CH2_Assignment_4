#pragma once
#include "RecipeManager.hpp"
#include "StockManager.hpp"
#include <string>
#include <vector>

class AlchemyWorkshop
{
private:
    RecipeManager rManager; // 레시피 관리
    StockManager  sManager; // 재고 관리

public:
    // 레시피 추가
    void addRecipe(const std::string& Name, const std::vector<std::string>& Ingredients);
    // 모든 레시피 출력
    void displayAllRecipes() const;

    // 검색
    const PotionRecipe* searchRecipeByName(const std::string& Name) const;
    std::vector<const PotionRecipe*> searchRecipeByIngredient(const std::string& Ingredient) const;

    // 재고
    int getStock(const std::string& Name) const;
    bool dispense(const std::string& Name);
    void giveBackEmptyBottle(const std::string& Name);
};
