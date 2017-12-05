#include "Scene.h"
#include <fstream>

void Scene::ChooseOpt(int opt)
{
    switch (opt)
    {
    case 1:
        LoadScene(m_FileOpt[0]);
        break;
    case 2:
        LoadScene(m_FileOpt[1]);
        break;
    case 3:
        LoadScene(m_FileOpt[2]);
        break;
    default:
        LoadScene(m_Path + "x.txt");
        break;
    }
}

void Scene::LoadScene(std::string file_name)
{
    std::ifstream file;
    file.open(file_name.c_str(), std::ios::in);

    if (!file.is_open())
    {
        LoadScene(m_Path + "x.txt");
        return;
    }

    std::getline(file, m_Desc);

    for (int i = 0; i < 3; i++)
    {
        std::getline(file, m_FileOpt[i]);
        m_FileOpt[i] = m_Path + m_FileOpt[i];
        std::getline(file, m_Opt[i]);
    }

    std::getline(file, m_Item);
    std::getline(file, m_Enemy);

    file.close();
}

std::string Scene::GetItem() const
{
    return m_Item;
}

std::string Scene::GetOpt(int opt) const
{
    if (opt < 3 && opt >= 0)
        return m_Opt[opt];
    else
        return "Exception: Wrong opt number in function GetOpt";
}

std::string Scene::GetDesc() const
{
    return m_Desc;
}

std::string Scene::GetEnemy() const
{
    return m_Enemy;
}

void Scene::DebugOption() const
{
    std::cout << "Desc:\n";
    std::cout << m_Desc;

    std::cout << "\n\n";
    for (int i = 0; i < 3; i++)
    {
        std::cout << "Opt_File_" << i << ":\n";
        std::cout << m_FileOpt[i] << "\n";
        std::cout << "Opt_" << i << ":\n";
        std::cout << m_Opt[i] << "\n";
    }

    std::cout << "\n\n";
    std::cout << "Item:\n";
    std::cout << m_Item;
    std::cout << "\n";
    std::cout << "Enemy:\n";
    std::cout << m_Enemy;
    std::cout << "\n";
}

void Scene::Update(int opt)
{
    ChooseOpt(opt);
}

Scene::Scene()
: m_Path("Game/Level/")
{
    LoadScene(m_Path + "0.txt");
}

Scene::~Scene()
{

}
