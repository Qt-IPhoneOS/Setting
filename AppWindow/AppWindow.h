#ifndef APPWINDOW_H
#define APPWINDOW_H

#include <QObject>
#include <QQuickView>

class AppWindow : public QObject
{
    Q_OBJECT
public:
    AppWindow();
    ~AppWindow();
    void createWindow(QQuickView* view);

private:

    QQuickView* m_view {nullptr};
};

#endif // APPWINDOW_H
