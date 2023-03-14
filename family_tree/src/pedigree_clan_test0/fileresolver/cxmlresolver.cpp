#include "cxmlresolver.h"

#include <QFile>
#include <QDebug>
#include <QTextCodec>
#include <QDomDocument>

CXmlResolver::CXmlResolver(const QString &filename)
    :m_curFile(filename)
{
     QFile file(m_curFile);
     if(!file.open(QFile::ReadOnly | QFile::Text))
         qDebug() << file.errorString();

    QTextStream in(&file);
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    in.setCodec(codec);
    const QString &content = in.readAll();
    file.close();

    m_document = new QDomDocument();
    m_document->setContent(content);

}

CXmlResolver::~CXmlResolver()
{

}
