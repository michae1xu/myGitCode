#ifndef CLANGRAPHSCENE_H
#define CLANGRAPHSCENE_H

#include <QGraphicsScene>

class ClanGraphScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit ClanGraphScene(QObject *parent = 0);
    ~ClanGraphScene();
};

#endif // CLANGRAPHSCENE_H
