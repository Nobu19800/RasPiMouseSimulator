#include <iostream>
#include "DrawThread_RasPiMouse.h"
#include "RasPiMouseSimulatorObj.h"

int main()
{
	RasPiMouseSimulatorObj RasPiMouse;
	RasPiMouse.destroyRobot();
	//RasPiMouse.makePlane(1, 1, 0.5);
	//RasPiMouse.makeParam(0.5);
	RasPiMouse.makeParam(0);
	RasPiMouse.makeRobot();
	
	RasPiMouse.loadBlocksData("test.csv");

	//RasPiMouse.makeBlock(0.3, 0, 0.05, 0.1, 0.2, 0.1, 0);
	
	//RasPiMouse.RasPiMouse.setTargetVelocity(0.0,1.6);
	//RasPiMouse.RasPiMouse.setTargetVelocity(0.0, 0.3);
	RasPiMouse.RasPiMouse.setTargetVelocity(0.1, 0.0);

	DrawThread_RasPiMouse ds(&RasPiMouse, 0.05);
	ds.activate();
	ds.setRCPFlag();
	while (true)
	{
		//std::cout << RasPiMouse.RasPiMouse.ir_sensor[0].data << "\t" << RasPiMouse.RasPiMouse.ir_sensor[1].data << "\t" << RasPiMouse.RasPiMouse.ir_sensor[2].data << "\t" << RasPiMouse.RasPiMouse.ir_sensor[3].data << std::endl;
		//std::cout << RasPiMouse.RasPiMouse.ir_sensor[0].current_x << "\t" << RasPiMouse.RasPiMouse.ir_sensor[0].current_y << "\t" << RasPiMouse.RasPiMouse.ir_sensor[0].current_z << std::endl;
		RasPiMouse.update();
		Sleep(10);
	}
	return 0;
}