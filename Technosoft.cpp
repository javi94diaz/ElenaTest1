#include "Technosoft.h"
#include <stdio.h>
#include <string.h>

Technosoft::Technosoft()
{

}

Technosoft::~Technosoft()
{

}



bool Technosoft::openMotorControl(bool forceInit) {

     LPCSTR COM_PORT = "/dev/ttyUSB0";

    int idxSetupHori= 0;
    std::string app_path="/home/sedecal/ElenaTest1/debug/";
    char SETUP_FILE_HORI[255];

    memset(SETUP_FILE_HORI, '\0', 255);
    sprintf(SETUP_FILE_HORI, "%s",(app_path + std::string("config/Lab.t.zip")).c_str());


    if(m_channel != -1)
    {
        if(!forceInit) return true;

        TS_CloseChannel(m_channel);
    }



     if((m_channel = TS_OpenChannel(COM_PORT,CHANNEL_RS232, m_hostID, MOTORS_BAUDRATE)) == -1){

         return false;
     }

     else {


     }



    if( (idxSetupHori = TS_LoadSetup(SETUP_FILE_HORI)) ==- 1) {

        return false;
    }

    if(!TS_SetupAxis(m_motorAxisID,idxSetupHori)) {

        return false;
    }

    if(!TS_SelectAxis(m_motorAxisID)) {

        return false;
    }

    if(!TS_DriveInitialisation()) {

        return false;
    }

    if(!TS_Power(POWER_ON)) {

        return false;
    }


    return true;
}



void Technosoft::moveMotor(long moveDirection) {

    double  iuAccel = 2*CACC;
    long _iuPos=CPOS*moveDirection;
    double iuSpeed = 2*CSPD;


    if(!TS_SelectAxis(m_motorAxisID)) {

        return;
    }


    if(!TS_MoveRelative(_iuPos, iuSpeed, iuAccel,__ISADDITIVE_DEFAULT,__MOVEMOMENT_DEFAULT,__REFBASE_DEFAULT)) {

        return;
    }


}

void Technosoft::stopMotor() {

    if(!TS_SelectAxis(m_motorAxisID)) {


    }

    if(!TS_Stop()) {


    }
}
