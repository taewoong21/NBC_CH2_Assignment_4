#include "AlchemyWorkshop.hpp"
#include <iostream>

// 포션 레시피 추가 - 이름 + 재료 목록
void AlchemyWorkshop::addRecipe(const std::string& Name, const std::vector<std::string>& Ingredients)
{
    PotionRecipe* Added = rManager.addRecipe(Name, Ingredients);
    if (Added == nullptr) return;
    sManager.initializeStock(Added->PotionName);
    std::cout << "*** 새로운 레시피 '" << Name << "'이(가) 추가되었습니다. (초기 재고 3) ***" << std::endl;
}
// 모든 레시피 출력
void AlchemyWorkshop::displayAllRecipes() const
{
    const auto& All = rManager.getAllRecipes(); // vector<PotionRecipe> 반환
    if (All.empty()) // 레시피가 없을 시
    {
        std::cout << "등록된 레시피가 없습니다." << std::endl;
        return;
    }

    // vector<PotionRecipe> 반환 성공 시
    std::cout << std::endl << "***** [ 전체 레시피 목록 ] *****" << std::endl;
    for (const PotionRecipe& R : All)
    {
        std::cout << "- 물약 이름: " << R.PotionName << " (재고: " << sManager.getStock(R.PotionName) << ")" << std::endl;
        std::cout << "   >> 필요 재료: ";
        for (size_t i = 0; i < R.Ingredients.size(); ++i)
        {
            std::cout << R.Ingredients[i];
            if (i + 1 < R.Ingredients.size()) std::cout << ", ";
        }
        std::cout << std::endl;
    }
    std::cout << "*********************************" << std::endl;
}
// 검색(포션 이름 기반)
const PotionRecipe* AlchemyWorkshop::searchRecipeByName(const std::string& Name) const
{
    return rManager.findRecipeByName(Name);
}
// 검색(재료 이름 기반)
std::vector<const PotionRecipe*> AlchemyWorkshop::searchRecipeByIngredient(const std::string& Ingredient) const
{
    return rManager.findRecipesByIngredient(Ingredient);
}
// 재고(재고 확인)
int AlchemyWorkshop::getStock(const std::string& Name) const
{
    return sManager.getStock(Name);
}
// 재고(포션 배부 - 재고 감소)
bool AlchemyWorkshop::dispense(const std::string& Name)
{
    return sManager.dispensePotion(Name);
}
// 재고(공병 반환 - 재고 증가)
void AlchemyWorkshop::giveBackEmptyBottle(const std::string& Name)
{
    sManager.returnPotion(Name);
}
