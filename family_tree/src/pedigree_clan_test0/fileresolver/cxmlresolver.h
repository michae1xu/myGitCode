#ifndef CXMLRESOLVER_H
#define CXMLRESOLVER_H

#include <QObject>

class QDomDocument;
class QFile;

class CXmlResolver : public QObject
{
    Q_OBJECT
public:
    explicit CXmlResolver(const QString &filename);
    ~CXmlResolver();

    QString m_curFile;
    QFile *m_file;
    QDomDocument *m_document;
};

#endif // CXMLRESOLVER_H
