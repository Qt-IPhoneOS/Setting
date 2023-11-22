#include "ScreenNavigator.h"
#include <QDebug>
#include <Log.h>

ScreenNavigator::ScreenNavigator(QObject *parent) : QObject(parent), mCurrentScreenNode(nullptr),
    mScreenID(Enums::MainScreen), mScreenStr("qrc:/Screen/MainSetting.qml")
{
    /*
    * Init main screen (root node)
    */
    if (mRoot == nullptr)
        mRoot = new ScreenNode(std::make_pair(mScreenID, mScreenStr));

    mCurrentScreenNode = mRoot;

    auto wifiMain = new ScreenNode(std::make_pair(Enums::WifiMainScreen, "qrc:/Screen/Wifi/WifiMainSetting.qml"));
    std::vector<ScreenNode*> mainChilds;
    mainChilds.push_back(wifiMain);
    insertChildrens(mCurrentScreenNode, mainChilds);
}

ScreenNavigator::~ScreenNavigator()
{
    delete mRoot;
}

ScreenNavigator* ScreenNavigator::instance()
{
    static ScreenNavigator ins;
    return &ins;
}

void ScreenNavigator::insertChildrens(ScreenNode* parent, std::vector<ScreenNode*> childs)
{
    if (parent == nullptr)
        return;

    for (auto& child : childs)
        parent->addChild(child);
}

void ScreenNavigator::showNextScreen(const Enums::ScreenID& screen)
{
    for (auto& child : mCurrentScreenNode->mChildren)
    {
        auto screenNode = child->mScreens;
        if (screenNode.first == screen)
        {
            mCurrentScreenNode = child;
            mScreenID = screenNode.first;
            mScreenStr = screenNode.second;
            LogEnum("Show Screen:", mScreenID);
            emit changeScreen(mScreenID, mScreenStr);
        }
    }
}

void ScreenNavigator::showPreviousScreen()
{
    // main screen
    if (mCurrentScreenNode->mParent == nullptr)
        return;

    mCurrentScreenNode = mCurrentScreenNode->mParent;
    mScreenID = mCurrentScreenNode->mScreens.first;
    mScreenStr = mCurrentScreenNode->mScreens.second;

    LogEnum("Show Screen:", mScreenID);
    emit changeScreen(mScreenID, mScreenStr);
}
