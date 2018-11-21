#include "WPILib.h"
#include "ctre/Phoenix.h"
#include <iostream>
#include <math.h>

#define TALON_TIMEOUT_MILLISECONDS 10

// TODO: Set the SRX up as a regular talon...?
// Set up velocity controls
// Set the feedback device to the encoder

class Robot : public IterativeRobot {
	private:

		TalonSRX *talon_left_noenc, *talon_left_enc, *talon_right_enc, *talon_right_noenc;
		Joystick *joystick;
		int Mode = 1;
		
		void RobotInit() { 

			talon_left_enc = new TalonSRX(7);
			talon_right_enc = new TalonSRX(2);
			//talon_right_noenc = new TalonSRX(5);
			//talon_left_noenc = new TalonSRX(3);
			//talon_left_enc->SetSensorPhase(false);
			//talon_right_enc->SetSensorPhase(true);

		//	talon_right_noenc->Set(ControlMode::Follower, 2);
		//	talon_left_noenc->Set(ControlMode::Follower, 7);
			joystick = new Joystick(0);

			std::cout<<"Oh la la! Un cochon. Il est tres beau. Il est plus beau que des cochons! Je s'adore!"<<std::endl;
			std::cout<<"Raider Pig!"<<std::endl;

		}

		void TeleopInit() {
			std::cout<<"I'm a PIGGGGGGGGGGG!"<<std::endl;
		}

		void TeleopPeriodic() {
			if (Mode == 1)
			{
				talon_left_enc->Set(ControlMode::PercentOutput, .6);
				talon_right_enc->Set(ControlMode::PercentOutput, .6);
				std::cout<<"Left Vel: "<<talon_left_enc->GetSelectedSensorVelocity(0)<<std::endl;
				std::cout<<"Right Vel: "<<talon_right_enc->GetSelectedSensorVelocity(0)<<std::endl;
			}
			if (Mode == 2)
			{
				talon_left_enc->ConfigPeakOutputForward(1, TALON_TIMEOUT_MILLISECONDS);
				talon_right_enc->ConfigPeakOutputForward(1, TALON_TIMEOUT_MILLISECONDS);
				talon_left_enc->ConfigPeakOutputReverse(-1, TALON_TIMEOUT_MILLISECONDS);
				talon_right_enc->ConfigPeakOutputReverse(-1, TALON_TIMEOUT_MILLISECONDS);
				talon_left_enc->Set(ControlMode::Velocity, 2000);
				std::cout<<"Left Vel: "<<talon_left_enc->GetSelectedSensorVelocity(0)<<std::endl;
				talon_right_enc->Set(ControlMode::Velocity, -2000);
				std::cout<<"Right Vel: "<<talon_right_enc->GetSelectedSensorVelocity(0)<<std::endl;
				float getting_left_error = talon_left_enc->GetClosedLoopError(0);
				float getting_right_error = talon_right_enc->GetClosedLoopError(0);
				std::cout<<"Left Talon Error: "<<getting_left_error<<std::endl;
				std::cout<<"Right Talon Error: "<<getting_right_error<<std::endl;
				std::cout<<"P Gain: "<<std::atof(SmartDashboard::GetString("DB/String 6", "0.0").c_str())<<std::endl;
				std::cout<<" "<<std::endl;
	 			talon_left_enc->Config_kF(0, std::atof(SmartDashboard::GetString("DB/String 0", "0.0").c_str()), TALON_TIMEOUT_MILLISECONDS);
				talon_left_enc->Config_kP(0, std::atof(SmartDashboard::GetString("DB/String 1", "0.0").c_str()), TALON_TIMEOUT_MILLISECONDS);
				talon_left_enc->Config_kI(0, std::atof(SmartDashboard::GetString("DB/String 2", "0.0").c_str()), TALON_TIMEOUT_MILLISECONDS);
				talon_left_enc->Config_kD(0, std::atof(SmartDashboard::GetString("DB/String 3", "0.0").c_str()), TALON_TIMEOUT_MILLISECONDS);

				talon_right_enc->Config_kF(0, std::atof(SmartDashboard::GetString("DB/String 5", "0.0").c_str()), TALON_TIMEOUT_MILLISECONDS);
				talon_right_enc->Config_kP(0, std::atof(SmartDashboard::GetString("DB/String 6", "0.0").c_str()), TALON_TIMEOUT_MILLISECONDS);
				talon_right_enc->Config_kI(0, std::atof(SmartDashboard::GetString("DB/String 7", "0.0").c_str()), TALON_TIMEOUT_MILLISECONDS);
				talon_right_enc->Config_kD(0, std::atof(SmartDashboard::GetString("DB/String 8", "0.0").c_str()), TALON_TIMEOUT_MILLISECONDS);
			}
			
		}

		void AutonomousInit() {}

		void AutonomousPeriodic() {}

		void DisabledInit() {
			
			std::cout<<"Hi, I'm a pig. Oink"<<std::endl;
		}

		void TestInit(){

		}

		void TestPeriodic() {

		}
		
};

START_ROBOT_CLASS(Robot);