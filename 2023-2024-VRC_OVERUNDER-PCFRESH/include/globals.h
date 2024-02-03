#include "main.h"
#include "okapi/api.hpp"
#include "lemlib/api.hpp"
#include "functions.hpp"

#pragma

/*
██████╗  ██████╗  ██╗██╗  ██╗██╗  ██╗██████╗ 
╚════██╗██╔═████╗███║██║  ██║██║  ██║██╔══██╗
 █████╔╝██║██╔██║╚██║███████║███████║██████╔╝
██╔═══╝ ████╔╝██║ ██║╚════██║╚════██║██╔══██╗
███████╗╚██████╔╝ ██║     ██║     ██║██████╔╝
╚══════╝ ╚═════╝  ╚═╝     ╚═╝     ╚═╝╚═════╝ 
*/

/**
 * Motor Groups:
 * ------------------
 * 13 (reversed) + 16 = Catapult
 * 17 (normal) + 19 (normal) = Right Drive
 * 18 (reversed) + 20 (reversed) = Left Drive
 * 
 * Motor Ports
 * -------------------------------------------------
 * 1   |
 * 2   | Intake Motor (R1 to start, R2 to stop) [blue]
 * 3   | 
 * 4   |
 * 5   | 
 * 6   |
 * 7   |
 * 8   |
 * 9   |
 * 10  |
 * 11  |
 * 12  | Internal Gyroscope
 * 13  | Left Catapult Motor (21432AG, reversed) [green]
 * 14  | 
 * 15  |
 * 16  | Right Catapult Motor (21134AG, normal) [green]
 * 17  | Back Right Drive Motor (normal) [green]
 * 18  | Back Left Drive Motor (reversed) [green]
 * 19  | Front Right Drive Motor (normal) [green]
 * 20  | Front Left Drive Motor (reversed) [green]
 * 21  | Radio
 * 
 * 
 * Sensor Ports
 * ---------------------------------------------------
 * A   |
 * B   |
 * C   |
 * D   |
 * E   |
 * F   |
 * G   |
 * H   | Back Bumper
*/


// drivetrain ports
const int FRONT_RIGHT_DRIVE_PORT = 19;
const int FRONT_LEFT_DRIVE_PORT = 20;
const int BACK_RIGHT_DRIVE_PORT = 17;
const int BACK_LEFT_DRIVE_PORT = 18;

// catapult ports
const int RIGHT_CATAPULT_PORT = 16;
const int LEFT_CATAPULT_PORT = 13;

// intake port
const int INTAKE_PORT = 2;

// sensor ports
const char BACK_BUMPER_PORT = 'h';

// motor declerations
extern pros::Motor back_left_drive;
extern pros::Motor back_right_drive;
extern pros::Motor front_left_drive;
extern pros::Motor front_right_drive;
extern pros::MotorGroup left_mg;
extern pros::MotorGroup right_mg;
extern pros::MotorGroup catapult_mg;
extern pros::Motor intake;

// sensor declerations
extern pros::ADIDigitalIn back_bump_sensor;

// controller declerations
extern pros::Controller controller;

// other declerations
// extern pros::ADIgyro gyro;

const int WHEEL_DIAMETER = 4;
const double TRACK_WIDTH = 11.625; // 11 + 5/8 inches
const int WHEEL_RPM = 200; 

/*
// LemLib functions
extern lemlib::Drivetrain_t drivetrain;
extern lemlib::ChassisController_t lateralController;
extern lemlib::ChassisController_t angularController;
extern lemlib::OdomSensors_t odomSensors;
extern lemlib::Chassis chassis;
*/
/**
 * This file contains the motor definitions for the robot.
 * 
 */