#include "AlchemyWorkshop.hpp"
#include <iostream>

// ���� ������ �߰� - �̸� + ��� ���
void AlchemyWorkshop::addRecipe(const std::string& Name, const std::vector<std::string>& Ingredients)
{
    PotionRecipe* Added = rManager.addRecipe(Name, Ingredients);
    if (Added == nullptr) return;
    sManager.initializeStock(Added->PotionName);
    std::cout << "*** ���ο� ������ '" << Name << "'��(��) �߰��Ǿ����ϴ�. (�ʱ� ��� 3) ***" << std::endl;
}
// ��� ������ ���
void AlchemyWorkshop::displayAllRecipes() const
{
    const auto& All = rManager.getAllRecipes(); // vector<PotionRecipe> ��ȯ
    if (All.empty()) // �����ǰ� ���� ��
    {
        std::cout << "��ϵ� �����ǰ� �����ϴ�." << std::endl;
        return;
    }

    // vector<PotionRecipe> ��ȯ ���� ��
    std::cout << std::endl << "***** [ ��ü ������ ��� ] *****" << std::endl;
    for (const PotionRecipe& R : All)
    {
        std::cout << "- ���� �̸�: " << R.PotionName << " (���: " << sManager.getStock(R.PotionName) << ")" << std::endl;
        std::cout << "   >> �ʿ� ���: ";
        for (size_t i = 0; i < R.Ingredients.size(); ++i)
        {
            std::cout << R.Ingredients[i];
            if (i + 1 < R.Ingredients.size()) std::cout << ", ";
        }
        std::cout << std::endl;
    }
    std::cout << "*********************************" << std::endl;
}
// �˻�(���� �̸� ���)
const PotionRecipe* AlchemyWorkshop::searchRecipeByName(const std::string& Name) const
{
    return rManager.findRecipeByName(Name);
}
// �˻�(��� �̸� ���)
std::vector<const PotionRecipe*> AlchemyWorkshop::searchRecipeByIngredient(const std::string& Ingredient) const
{
    return rManager.findRecipesByIngredient(Ingredient);
}
// ���(��� Ȯ��)
int AlchemyWorkshop::getStock(const std::string& Name) const
{
    return sManager.getStock(Name);
}
// ���(���� ��� - ��� ����)
bool AlchemyWorkshop::dispense(const std::string& Name)
{
    return sManager.dispensePotion(Name);
}
// ���(���� ��ȯ - ��� ����)
void AlchemyWorkshop::giveBackEmptyBottle(const std::string& Name)
{
    sManager.returnPotion(Name);
}
