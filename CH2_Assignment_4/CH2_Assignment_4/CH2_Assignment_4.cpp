#include "AlchemyWorkshop.hpp"
#include <iostream>
#include <limits> // 입력 버퍼 관련 오류 해결을 위한 헤더 선언

void PrintFound(const PotionRecipe* R, const AlchemyWorkshop& W)
{
    if (R == nullptr)
    {
        std::cout << "검색 결과가 없습니다." << std::endl;
        return;
    }
    std::cout << "[이름] " << R->PotionName << " / [재고] " << W.getStock(R->PotionName) << std::endl;
    std::cout << "재료: ";
    for (size_t i = 0; i < R->Ingredients.size(); ++i)
    {
        std::cout << R->Ingredients[i];
        if (i + 1 < R->Ingredients.size()) std::cout << ", ";
    }
    std::cout << std::endl;
}

// 입력 버퍼 오류 방지를 위한 버퍼 비우기 함수
void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 개행 문자까지 입력 버퍼 비우기
}

int main()
{
    AlchemyWorkshop Workshop;

    while (true)
    {
        std::cout << std::endl << "+++++ [ 연금술 공방 관리 시스템 ] +++++" << std::endl
            << "1. 레시피 추가" << std::endl
            << "2. 모든 레시피 출력" << std::endl
            << "3. 이름으로 검색" << std::endl
            << "4. 재료로 검색" << std::endl
            << "5. 재고 조회" << std::endl
            << "6. 지급(모험가에게)" << std::endl
            << "7. 공병 반환" << std::endl
            << "8. 종료" << std::endl
            << "선택: ";

        int Choice = 0;
        if (!(std::cin >> Choice))
        {
            std::cout << "잘못된 입력입니다. 숫자를 입력해주세요." << std::endl;
            std::cin.clear();
            ignoreLine();
            continue;
        }
        ignoreLine();

        if (Choice == 1)
        {
            std::string Name;
            std::cout << "물약 이름: ";
            std::getline(std::cin, Name);

            std::vector<std::string> Ingredients;
            std::cout << "필요한 재료들을 입력하세요. (입력 완료 시 '끝')" << std::endl;
            while (true)
            {
                std::cout << "재료 입력: ";
                std::string In;
                std::getline(std::cin, In);
                if (In == "끝") break;
                if (!In.empty()) Ingredients.push_back(In);
            }

            if (Ingredients.empty())
            {
                std::cout << ">> 재료가 입력되지 않아 레시피 추가를 취소합니다." << std::endl;
                continue;
            }
            Workshop.addRecipe(Name, Ingredients);
        }
        else if (Choice == 2)
        {
            Workshop.displayAllRecipes();
        }
        else if (Choice == 3)
        {
            std::string Name;
            std::cout << "검색할 물약 이름: ";
            std::getline(std::cin, Name);
            PrintFound(Workshop.searchRecipeByName(Name), Workshop);
        }
        else if (Choice == 4)
        {
            std::string Ingredient;
            std::cout << "검색할 재료: ";
            std::getline(std::cin, Ingredient);

            const auto Found = Workshop.searchRecipeByIngredient(Ingredient);
            if (Found.empty())
            {
                std::cout << "해당 재료가 포함된 레시피가 없습니다." << std::endl;
            }
            else
            {
                std::cout << Found.size() << "개 레시피를 찾았습니다." << std::endl;
                for (const PotionRecipe* R : Found) PrintFound(R, Workshop);
            }
        }
        else if (Choice == 5)
        {
            std::string Name;
            std::cout << "재고 확인할 물약 이름: ";
            std::getline(std::cin, Name);
            std::cout << "[재고] " << Workshop.getStock(Name) << std::endl;
        }
        else if (Choice == 6)
        {
            std::string Name;
            std::cout << "지급할 물약 이름: ";
            std::getline(std::cin, Name);

            if (!Workshop.dispense(Name))
            {
                std::cout << "지급 실패. 재고가 없거나 존재하지 않는 물약입니다." << std::endl;
                continue;
            }
            std::cout << "지급 완료. 현재 재고: " << Workshop.getStock(Name) << std::endl;
        }
        else if (Choice == 7)
        {
            std::string Name;
            std::cout << "반환(공병) 처리할 물약 이름: ";
            std::getline(std::cin, Name);
            const int Before = Workshop.getStock(Name);
            Workshop.giveBackEmptyBottle(Name);
            const int After = Workshop.getStock(Name);
            if (After == Before)
            {
                std::cout << "반환 불가. 존재하지 않거나 이미 최대 재고(3)입니다." << std::endl;
            }
            else
            {
                std::cout << "반환 완료. 현재 재고: " << After << std::endl;
            }
        }
        else if (Choice == 8)
        {
            std::cout << "연금술 공방 관리 시스템을 종료합니다..." << std::endl;
            break;
        }
        else
        {
            std::cout << "잘못된 선택입니다. 다시 시도하세요." ;
        }
    }
    return 0;
}
