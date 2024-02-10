#include "main.h"
#include "devices.h"
#include "functions.h"
#include <ctime>



/*
██████╗  ██████╗  ██╗██╗  ██╗██╗  ██╗██████╗ 
╚════██╗██╔═████╗███║██║  ██║██║  ██║██╔══██╗
 █████╔╝██║██╔██║╚██║███████║███████║██████╔╝
██╔═══╝ ████╔╝██║ ██║╚════██║╚════██║██╔══██╗
███████╗╚██████╔╝ ██║     ██║     ██║██████╔╝
╚══════╝ ╚═════╝  ╚═╝     ╚═╝     ╚═╝╚═════╝ 
*/


/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */

// 1 for offensive, 2 for defensive
int current_auton = 1;
int num_autons = 2;
/* 
void autonSelector() {
	while (true) {
		pros::lcd::clear();
		pros::lcd::print(2, "Auton: %s Selected", current_auton);
		pros::delay(200);

		if (controller.get_digital(DIGITAL_LEFT)) {
			current_auton--;
		} else if (controller.get_digital(DIGITAL_RIGHT)) {
			current_auton++;
		} else if (controller.get_digital(DIGITAL_UP)) {
			break;
		}

		if (current_auton < 1) {
			current_auton = num_autons;
		} else if (current_auton > num_autons) {
			current_auton = 1;
		}
	}
}
 */

void autonomous() {
	int current_auton = 1;
	// int start_time = std::time(0);
	pros::delay(2000);

	if (current_auton == 1) {
		offensiveAuton();
	} else if (current_auton == 2) {
		defensiveAuton();
	} else if (current_auton == 3) {
		skillsAuton();
	}
}


/**
 * @brief Autonomous code for the offensive placement
 * 
 * Offensive:
 * If robot is on same side as their goal, it is offensive
 * EXP: Red alliance robot on red side, blue alliance robot on blue side
 * 
 * Goal: Score Alliance Ball, then position in the middle to score other balls after autonomous period ends
 */
void offensiveAuton() {
	left_drive_mg.move_velocity(-200);
	right_drive_mg.move_velocity(-200);
	pros::delay(2000);
	left_drive_mg.move_velocity(200);
	right_drive_mg.move_velocity(200);
	pros::delay(1000);
	left_drive_mg.brake();
	right_drive_mg.brake();
}

/**
 * @brief Autonomous code for the defensive placement
 * 
 * Defensive:
 * If robot is on opposite side as their goal, it is defensive
 * EXP: Red alliance robot on blue side, blue alliance robot on red side
 * 
 * Goal: Score Alliance Ball, then position in the middle to score other balls after autonomous period ends
 */

void defensiveAuton() {
/* 
	move(100, true, 1000);
	move(100, false, 1000);
	turn(90, false);
	move(100, false, 1500);
	 */

	left_drive_mg.move_velocity(-200);
	right_drive_mg.move_velocity(-200);
	pros::delay(2000);
	left_drive_mg.move_velocity(200);
	right_drive_mg.move_velocity(200);
	pros::delay(1000);
	left_drive_mg.brake();
	right_drive_mg.brake();
}


void skillsAuton() {
	catapult_mg.move_velocity(75);
}