#ifndef HUDTimeTable_H
#define HUDTimeTable_H

#include "hudelement.h"

class HUDTimeTable : public HUDElement
{
    Q_OBJECT
    QML_NAMED_ELEMENT(HUDTimeTable)

    Q_PROPERTY(QString stationId MEMBER _stationId)
    Q_PROPERTY(QString stationName MEMBER _stationName)

public:
    HUDTimeTable(QQuickItem* parent = nullptr);
    ~HUDTimeTable();

    int type() const override { return HUDElementType::TimeTable; }

    void paint(QPainter* painter) override;
    virtual void loadConfiguration(QJsonObject& json) override;
    virtual void saveConfiguration(QJsonObject& json) override;

protected slots:
    void updateTimeTable();
    void updateTimeTablereplyFinished(QNetworkReply* reply);

protected:
    void parseStationInfo(QString str);
    QStringList timetable_lst;  // Very simple presentation of timetable lines: CSV with ; as delimiters (scheduled_time;delayed_time;name;origin;destination;peron

private:
    QTimer* timer; 
    QString _stationName;
    QString _stationId;
    QNetworkAccessManager* nam;
    QVariant cookies_variant;
    QList<QNetworkCookie> cookies;
};

#endif