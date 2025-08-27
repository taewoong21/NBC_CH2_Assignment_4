#include "StockManager.hpp"

void StockManager::initializeStock(const std::string& PotionName)
{
    // �� �����Ǹ� 3���� ����, ���� ���� �� �״�� ��(�ߺ� �ʱ�ȭ ����)
    // map<std::string, int> PotionStock�� Ű �� string ��� �˻�
    if (PotionStock.find(PotionName) == PotionStock.end()) // ���ο� ���� �԰� Ȯ�� ��
    {
        PotionStock[PotionName] = MAX_STOCK; // �⺻ ���� - ��� 3 �� ����
    }
}

// ��� Ȯ��
int StockManager::getStock(const std::string& PotionName) const
{
    // ���� �̸� ��� ��� �˻�
    auto It = PotionStock.find(PotionName);

    if (It == PotionStock.end()) return 0; // �ش� ��� ���� ��

    return It->second; // ��� ���� ��ȯ
}

// ���� ���
bool StockManager::dispensePotion(const std::string& PotionName)
{
    // ���� �̸� ��� ��� �˻�
    auto It = PotionStock.find(PotionName);

    if (It == PotionStock.end()) return false; // ��� �ش� ������ ���� ��, ��� ����

    if (It->second <= 0) return false; // ��� ���� ��, ��� ����

    It->second -= 1; // ��� ���� �� ��� ����
    return true;
}

// ���� ��ȯ
void StockManager::returnPotion(const std::string& PotionName)
{
    // ���� �̸� ��� ��� �˻�
    auto It = PotionStock.find(PotionName);

    if (It == PotionStock.end()) return; // ��� �ش� ������ ���� ��

    if (It->second >= MAX_STOCK) return; // ��� �� �� ���� ��

    It->second += 1; // �ش� ���� ���� �� ��ȯ���� ���� ��� �߰�
}
