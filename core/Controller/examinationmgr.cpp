#include "examinationmgr.h"
#include "Utils/logmgr.h"

ExaminationMgr::ExaminationMgr(QObject *parent, ExaminationDialog &dialog) :
    m_dialog(dialog),
    QObject(parent)
{

}

void ExaminationMgr::OnActivateExamination()
{
    LogMgr::instance()->LogAppDebug(tr("examination workflow is started."));
    m_dialog.show();
}
