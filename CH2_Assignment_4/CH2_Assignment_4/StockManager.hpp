#pragma once
#include <map>
#include <string>

class StockManager
{
private:
    std::map<std::string, int> PotionStock; // 표션 재고

public:
    static constexpr int MAX_STOCK = 3; // 최대 재고 (기본 설정)

    // 재고 초기화
    void initializeStock(const std::string& PotionName);
    // 재고 확인
    int getStock(const std::string& PotionName) const;
    // 포션 배부
    bool dispensePotion(const std::string& PotionName);
    // 공병 반환
    void returnPotion(const std::string& PotionName);
};
