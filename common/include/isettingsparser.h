#ifndef ISETTINGSPARSER_H
#define ISETTINGSPARSER_H
#include <QObject>
#include <QString>
#include <QMessageBox>
#include <QMap>

/**
* \brief This class parses a setting file. The setting file-type can be:
*  - JSON
*  - XML
*  - txt
*  - database
*  - binary files
*  \n \note The class process and returns QMap of settings
*/
class ISettingsParser
{

public:

    void SetSettingsPath(QString fullFileName);
    QMap<QString,QString> GetSettings();


private:

    QString _settingFileFullPath;
    QMap<QString,QString> _setting;

};


Q_DECLARE_INTERFACE(ISettingsParser, "tr.edu.boun.ISettingsParser")

#endif // ISETTINGSPARSER_H
