#include "RecipeManager.hpp"
#include <algorithm>

// 포션 레시피 추가 - 이름 + 재료 목록
PotionRecipe* RecipeManager::addRecipe(const std::string& Name, const std::vector<std::string>& Ingredients)
{
    // emplack_back() 사용으로 vector<PotionRecipe> 객체 생성 및 추가 동시 진행
    recipes.emplace_back(Name, Ingredients);
    
    return &recipes.back(); // 추가한 레시피 반환
}

// 포션 레시피 검색 - 포션 이름 
const PotionRecipe* RecipeManager::findRecipeByName(const std::string& Name) const
{
    // PotionRecipe 클래스의 비교 연산을 위한 find_if() 사용
    // find() 사용 시 std::string과 PotionRecipe를 == 연산자를 사용해 비교 불가
    const auto It = std::find_if(recipes.begin(), recipes.end(), [&Name](const PotionRecipe& R) { return R.PotionName == Name; });
    
    // 검색 대상이 없을 시, nullptr 반환
    if (It == recipes.end()) return nullptr;
    
    // 검색 성공 시, 해당 레시피 반환
    return &(*It);
}

// 포션 레시피 검색 - 재료 이름
std::vector<const PotionRecipe*> RecipeManager::findRecipesByIngredient(const std::string& Ingredient) const
{
    // 검색 결과 레시피
    std::vector<const PotionRecipe*> Result;


    for (const PotionRecipe& R : recipes)
    {
        // 재료명 같은 레시피 탐색
        bool Has = std::find(R.Ingredients.begin(), R.Ingredients.end(), Ingredient) != R.Ingredients.end();
        
        // 검색 성공 시, 결과 저장
        if (Has) Result.push_back(&R);
    }
    return Result; // 검색 결과 반환
}

// 포션 레시피 반환
const std::vector<PotionRecipe>& RecipeManager::getAllRecipes() const
{
    return recipes; // 레시피 반환
}
