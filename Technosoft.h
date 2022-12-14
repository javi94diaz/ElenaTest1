#ifndef TECHNOSOFT_H
#define TECHNOSOFT_H

#include "TML_lib.h"
#include "tmlcomm.h"
#include <string>

#define __MOVEMOMENT_DEFAULT UPDATE_IMMEDIATE
#define __REFBASE_DEFAULT FROM_REFERENCE
#define __ISADDITIVE_DEFAULT 0

//Motors baudrate
#define MOTORS_BAUDRATE	115200

#define REG_MER_CANBUS_ERROR		0b0000000000000001
#define REG_MER_SHORT_CIRCUIT		0b0000000000000010
#define REG_MER_INVALID_SETUP		0b0000000000000100
#define REG_MER_CONTROL_ERROR		0b0000000000001000
#define REG_MER_SERIAL_COMM_ERROR	0b0000000000010000
#define REG_MER_HALL_SENSOR_MISSING	0b0000000000100000
#define REG_MER_LSP_ACTIVE			0b0000000001000000
#define REG_MER_LSN_ACTIVE			0b0000000010000000
#define REG_MER_OVER_CURRENT		0b0000000100000000
#define REG_MER_I2T					0b0000001000000000
#define REG_MER_OVER_TEMP_MOTOR		0b0000010000000000
#define REG_MER_OVER_TEMP_DRIVE		0b0000100000000000
#define REG_MER_OVER_VOLTAGE		0b0001000000000000
#define REG_MER_UNDER_VOLTAGE		0b0010000000000000
#define REG_MER_COMMAND_ERROR		0b0100000000000000
#define REG_MER_ENABLE_INPUT		0b1000000000000000

#define REG_SRH_ENDINIT_EXECUTED	0b0000000000000001
#define REG_SRH_OVER_POS_TRG1	 	0b0000000000000010
#define REG_SRH_OVER_POS_TRG2		0b0000000000000100
#define REG_SRH_OVER_POS_TRG3		0b0000000000001000
#define REG_SRH_OVER_POS_TRG4		0b0000000000010000
#define REG_SRH_AUTORUN_ENABLED		0b0000000000100000
#define REG_SRH_LSP_EVENT_INT		0b0000000001000000
#define REG_SRH_LSN_EVENT_INT		0b0000000010000000
#define REG_SRH_CAPTURE_EVENT		0b0000000100000000
#define REG_SRH_TARGET_REACHED		0b0000001000000000
#define REG_SRH_I2T_WARNING_MOTOR	0b0000010000000000
#define REG_SRH_I2T_WARNING_DRIVE	0b0000100000000000
#define REG_SRH_IN_GEAR				0b0001000000000000

#define REG_SRH_IN_CAM				0b0100000000000000
#define REG_SRH_FAULT				0b1000000000000000


#define REG_SRL_HOMING_CALLS_WARNING	0b0000000010000000
#define REG_SRL_HOMING_CALLS_ACTIVE		0b0000000100000000
#define REG_SRL_MOTION_IS_COMPLETED		0b0000010000000000
#define REG_SRL_EVENT_SET_HAS_OCURRED	0b0100000000000000
#define REG_SRL_AXIS_ON					0b1000000000000000


class Technosoft
{
public:
    Technosoft();
     ~Technosoft();

      bool openMotorControl(bool forceInit=false);
      void moveMotor(long moveDirection);
      void stopMotor();


private :
      int m_channel =-1;
      int m_motorAxisID= 1;
      int m_hostID = 1;

      int CPOS = 2666667;
      double CACC = 0.26666;
      double CSPD = 266.66666;



};

#endif // TECHNOSOFT_H
