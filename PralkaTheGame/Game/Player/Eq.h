#pragma once
#include <string>
#include "..\..\Backstage\Enum.h"

struct ItemInfo
{
    std::string Name;
    On WhereEquip;
    float HP;
    float DP;
    float AP;
};

class Eq
{
private:
    ItemInfo m_Info;

public:
    void AddItem(std::string item);
    ItemInfo GetInfo() const;

    Eq();
    ~Eq();
};