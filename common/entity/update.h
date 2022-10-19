#ifndef UpdateENTITY_H
#define UpdateENTITY_H

#include <entity.h>

class UpdateEntity : public Entity
{
    Q_OBJECT
    QML_NAMED_ELEMENT(UpdateEntity)

    Q_PROPERTY(bool autoUpdate	MEMBER _autoUpdate);                        // - The device or service that the entity represents has auto update logic.When this is set to True you can not skip updates.
    Q_PROPERTY(bool inProgress	MEMBER _inProgress);                        // - 	Update installation progress.Can either return a boolean(True if in progress, False if not) or an integer to indicate the progress from 0 to 100 % .
    Q_PROPERTY(QString installedVersion	MEMBER _installedVersion);          // - 	The currently installed and used version of the software.
    Q_PROPERTY(QString latestVersion	MEMBER _latestVersion);             // - 		The latest version of the software available.
    Q_PROPERTY(QString releaseSummary	MEMBER _releaseSummary);            // - 		Summary of the release notes or changelog.This is not suitable for long changelogs but merely suitable for a short excerpt update description of max 255 characters.
    Q_PROPERTY(QString releaseUrl	MEMBER _releaseUrl);                    // - 	URL to the full release notes of the latest version available.
    Q_PROPERTY(QString title	MEMBER _title);                             // - 	Title of the software.This helps to differentiate between the device or entity name versus the title of the software installed.

public:
    UpdateEntity(QObject *parent=NULL);
    ~UpdateEntity();

public slots:
    void install() {}
    void releaseNotes() {}

protected:
    bool _autoUpdate;
    bool _inProgress;
    QString _installedVersion;
    QString _latestVersion;
    QString _releaseSummary;
    QString _releaseUrl;
    QString _title;
};

#endif

/*

SUPPORTED FEATURES

    'BACKUP'	        - A backup can be made automatically, before installing an update.
    'INSTALL'	        - The update can be installed from Home Assistant.
    'PROGRESS'	        - This integration is able to provide progress information. If omitted, Home Assistant will try to provide a progress status; although it is better if the progress can be extracted from the device or service API.
    'SPECIFIC_VERSION'	- A specific version of an update can be installed using the update.install service.
    'RELEASE_NOTES'	    - The entity provides methods to fetch a complete changelog.

AVAILABLE DEVICE CLASSES

    firmware	        - The update is a firmware update for a device.

*/