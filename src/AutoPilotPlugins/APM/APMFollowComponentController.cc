/****************************************************************************
 *
 * (c) 2009-2020 QGROUNDCONTROL PROJECT <http://www.qgroundcontrol.org>
 *
 * QGroundControl is licensed according to the terms in the file
 * COPYING.md in the root of the source code directory.
 *
 ****************************************************************************/

#include "APMFollowComponentController.h"
#include "ArduRoverFirmwarePlugin.h"
#include "Vehicle.h"

APMFollowComponentController::APMFollowComponentController(void)
    : _metaDataMap  (FactMetaData::createMapFromJsonFile(QStringLiteral(":/json/APMFollowComponent.FactMetaData.json"), this))
    , _angleFact    (settingsGroup, _metaDataMap[angleName])
    , _distanceFact (settingsGroup, _metaDataMap[distanceName])
    , _heightFact   (settingsGroup, _metaDataMap[heightName])
{

}

bool APMFollowComponentController::roverFirmware()
{
    return !!qobject_cast<ArduRoverFirmwarePlugin*>(_vehicle->firmwarePlugin());
}
