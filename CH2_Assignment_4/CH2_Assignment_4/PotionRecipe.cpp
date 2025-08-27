#include "PotionRecipe.hpp"

// `이름`과 `재료` 입력으로 레시피 생성
PotionRecipe::PotionRecipe(const std::string& Name, const std::vector<std::string>& InIngredients)
	: PotionName(Name), Ingredients(InIngredients) { }
