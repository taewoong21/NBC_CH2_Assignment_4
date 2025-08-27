#pragma once
#include <map>
#include <string>

class StockManager
{
private:
    std::map<std::string, int> PotionStock; // ǥ�� ���

public:
    static constexpr int MAX_STOCK = 3; // �ִ� ��� (�⺻ ����)

    // ��� �ʱ�ȭ
    void initializeStock(const std::string& PotionName);
    // ��� Ȯ��
    int getStock(const std::string& PotionName) const;
    // ���� ���
    bool dispensePotion(const std::string& PotionName);
    // ���� ��ȯ
    void returnPotion(const std::string& PotionName);
};
