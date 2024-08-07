/****************************************************************************
 *
 * (c) 2009-2020 QGROUNDCONTROL PROJECT <http://www.qgroundcontrol.org>
 *
 * QGroundControl is licensed according to the terms in the file
 * COPYING.md in the root of the source code directory.
 *
 ****************************************************************************/

#pragma once

#include "FactPanelController.h"
#include "SettingsFact.h"

class APMFollowComponentController : public FactPanelController
{
    Q_OBJECT
    
public:
    APMFollowComponentController(void);

    Q_PROPERTY(Fact* angle          READ angleFact      CONSTANT)
    Q_PROPERTY(Fact* distance       READ distanceFact   CONSTANT)
    Q_PROPERTY(Fact* height         READ heightFact     CONSTANT)
    Q_PROPERTY(bool  roverFirmware  READ roverFirmware  CONSTANT)

    Fact* angleFact     (void) { return &_angleFact; }
    Fact* distanceFact  (void) { return &_distanceFact; }
    Fact* heightFact    (void) { return &_heightFact; }
    bool  roverFirmware (void);

    static constexpr const char* settingsGroup =   "APMFollow";
    static constexpr const char* angleName =       "angle";
    static constexpr const char* distanceName =    "distance";
    static constexpr const char* heightName =      "height";

private:
    QMap<QString, FactMetaData*> _metaDataMap;

    SettingsFact _angleFact;
    SettingsFact _distanceFact;
    SettingsFact _heightFact;
};
