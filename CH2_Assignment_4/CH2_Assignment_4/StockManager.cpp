#include "StockManager.hpp"

void StockManager::initializeStock(const std::string& PotionName)
{
    // 새 레시피면 3개로 세팅, 기존 존재 시 그대로 둠(중복 초기화 방지)
    // map<std::string, int> PotionStock의 키 값 string 기반 검색
    if (PotionStock.find(PotionName) == PotionStock.end()) // 새로운 포션 입고 확인 시
    {
        PotionStock[PotionName] = MAX_STOCK; // 기본 설정 - 재고 3 개 설정
    }
}

// 재고 확인
int StockManager::getStock(const std::string& PotionName) const
{
    // 포션 이름 기반 재고 검색
    auto It = PotionStock.find(PotionName);

    if (It == PotionStock.end()) return 0; // 해당 재고 없을 시

    return It->second; // 재고 수량 반환
}

// 포션 배부
bool StockManager::dispensePotion(const std::string& PotionName)
{
    // 포션 이름 기반 재고 검색
    auto It = PotionStock.find(PotionName);

    if (It == PotionStock.end()) return false; // 재고에 해당 포션이 없을 시, 배부 실패

    if (It->second <= 0) return false; // 재고가 없을 시, 배부 실패

    It->second -= 1; // 배부 성공 후 재고 감소
    return true;
}

// 공병 반환
void StockManager::returnPotion(const std::string& PotionName)
{
    // 포션 이름 기반 재고 검색
    auto It = PotionStock.find(PotionName);

    if (It == PotionStock.end()) return; // 재고에 해당 포션이 없을 시

    if (It->second >= MAX_STOCK) return; // 재고가 꽉 차 있을 시

    It->second += 1; // 해당 포션 있을 시 반환으로 인한 재고 추가
}
