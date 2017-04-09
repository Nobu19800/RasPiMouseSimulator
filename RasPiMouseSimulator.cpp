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
	
	RasPiMouse.RasPiMouse.setTargetVelocity(0.0,1.6);
	RasPiMouse.RasPiMouse.target_mangle = 1.6;
	DrawThread_RasPiMouse ds(&RasPiMouse, 0.05);
	//ds.activate();
	ds.setRCPFlag();
	while (true)
	{
		if (RasPiMouse.RasPiMouse.getRightTouch(0.003))
		{
			RasPiMouse.RasPiMouse.setTargetVelocity(-0.01, 0);
		}
		RasPiMouse.update();
		Sleep(10);
	}
	return 0;
}