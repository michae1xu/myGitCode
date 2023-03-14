#ifndef CLANGRAPHVIEW_H
#define CLANGRAPHVIEW_H

#include <QGraphicsView>

class ClanGraphScene;
class CXmlResolver;

class ClanGraphView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit ClanGraphView(QWidget *parent = nullptr);
    ~ClanGraphView();

    void newFile(const QString &logFile = QString());
    CXmlResolver *getXml();

private:
    QString m_curFile;
    CXmlResolver *m_xml;
    ClanGraphScene *m_clanScene;

};

#endif // CLANGRAPHVIEW_H
