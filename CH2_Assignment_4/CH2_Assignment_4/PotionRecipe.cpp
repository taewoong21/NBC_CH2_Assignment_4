#include "PotionRecipe.hpp"

// `�̸�`�� `���` �Է����� ������ ����
PotionRecipe::PotionRecipe(const std::string& Name, const std::vector<std::string>& InIngredients)
	: PotionName(Name), Ingredients(InIngredients) { }
