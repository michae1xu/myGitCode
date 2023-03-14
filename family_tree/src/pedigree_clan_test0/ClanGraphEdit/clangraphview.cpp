#include "clangraphscene.h"
#include "clangraphview.h"
#include "fileresolver/cappenv.h"

#include <fileresolver/cxmlresolver.h>


ClanGraphView::ClanGraphView(QWidget *parent)
    :QGraphicsView(parent),
      m_curFile(QString()),
      m_xml(NULL),
      m_clanScene(new ClanGraphScene(this))
{

}

ClanGraphView::~ClanGraphView()
{

}

void ClanGraphView::newFile(const QString &logFile)
{
    static int docNum = 1;
    m_curFile = CAppEnv::getRPUDesignerDirPath()+"/tmp"+tr(u8"untitled%1.xml").arg(docNum);
    setWindowTitle(CAppEnv::stpToNm(m_curFile)+"[*]");

    m_xml = new CXmlResolver(m_curFile);

    ++docNum;
}

CXmlResolver *ClanGraphView::getXml()
{
    return m_xml;
}
