#ifndef SCREENNAVIGATOR_H
#define SCREENNAVIGATOR_H

#include <QObject>
#include <unordered_map>
#include "Controller/Enums.h"

class ScreenNavigator : public QObject
{
    Q_OBJECT

private:

    struct ScreenNode {
        std::pair<Enums::ScreenID, QString> mScreens;
        ScreenNode* mParent;
        std::vector<ScreenNode*> mChildren;

        ~ScreenNode()
        {
            for (auto child : mChildren)
            {
                delete child;
            }
        }

        ScreenNode(std::pair<Enums::ScreenID, QString> screens)
            : mScreens(screens), mParent(nullptr) {}

        void addChild(ScreenNode* child) {
            child->mParent = this;
            mChildren.push_back(child);
        }
    };

    explicit ScreenNavigator(QObject *parent = nullptr);

public:
    static ScreenNavigator* instance();
    ~ScreenNavigator();

    void insertChildrens(ScreenNode*, std::vector<ScreenNode*>);

    Q_INVOKABLE void showNextScreen(const Enums::ScreenID&);
    Q_INVOKABLE void showPreviousScreen();

signals:
    void changeScreen(Enums::ScreenID screenId, QString screen);

protected:
    ScreenNode* mRoot;
    ScreenNode* mCurrentScreenNode;
    Enums::ScreenID mScreenID;
    QString mScreenStr;
};

#endif // SCREENNAVIGATOR_H
