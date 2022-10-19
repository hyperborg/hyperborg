#ifndef CameraENTITY_H
#define CameraENTITY_H

#include <entity.h>
#include <QString>

class CameraEntity : public Entity
{
    Q_OBJECT
    QML_NAMED_ELEMENT(CameraEntity)

    Q_PROPERTY(bool isRecording MEMBER _isRecording)                            // Indication of whether the camera is recording.Used to determine state.
    Q_PROPERTY(bool isStreaming MEMBER _isStreaming)                            // Indication of whether the camera is streaming.Used to determine state.
    Q_PROPERTY(bool motionDetectionEnabled MEMBER _motionDetectionEnabled)      // Indication of whether the camera has motion detection enabled.
    Q_PROPERTY(bool isOn MEMBER _isOn)                                          // Indication camera is on.
    Q_PROPERTY(QString brand MEMBER _brand)                                     // The brand(manufacturer) of the camera.
    Q_PROPERTY(QString model MEMBER _model)                                     // The model of the camera.
    Q_PROPERTY(float frameInterval MEMBER _frameInterval)                       // The interval between frames of the stream.
    Q_PROPERTY(QString frontendStreamType MEMBER _frontendStreamType)           // Used with CameraEntityFeature.STREAM to tell the frontend which type of stream to use(StreamType.HLS or StreamType.WEB_RTC)

public:
    CameraEntity(QObject *parent=NULL);
    ~CameraEntity();

protected:
    bool _isRecording;
    bool _isStreaming;
    bool _motionDetectionEnabled;
    bool _isOn;
    QString _brand;
    QString _model;
    float _frameInterval;
    QString _frontendStreamType;
};

#endif

/*

SUPPORTED FEATURES 
    onOff	- The device supports turnOn and turnOff.
    stream	- The device supports streaming

*/