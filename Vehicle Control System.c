#include <stdio.h>
#define WITH_ENGINE_TEMP_CONTROLLER 1

int TrafficLightsSpeed (char color);
int SetRoomTemp(int *Room_temp);
int SetEngineTemp (int *engine_temp);

int main (void){
	setvbuf(stdout, NULL, _IONBF,0);
	setvbuf(stderr, NULL, _IONBF,0);

	int engine_Status=0;
	char choice1 =' ';
	char choice2 =' ';
	int speed =0;
	char color ;
	int Room_temp=0;
	int AC_Status=0;
	int engine_temp=0;
	int Control_Status=0;


	while(engine_Status == 0){

		printf("What do you want to do? \n");
		printf("a. Turn on the vehicle engine \n"
				"b. Turn off the vehicle engine \n"
				"c. Quit the system \n");

		scanf(" %c", &choice1);
		switch(choice1)
		{
		case 'a':
			printf("\t Engine ON \n \n");
			engine_Status =1;
			break;
		case 'b':
			printf("\t Engine OFF \n \n");
			engine_Status =0;
			break;
		case 'c':
			printf("\t Quit System \n \n");
			return 0;
			break;
		default:
			printf("Invalid Input! \n");
			printf("What do you want to do? \n");
			printf("a. Turn on the vehicle engine \n"
					"b. Turn off the vehicle engine \n"
					"c. Quit the system \n \n");
			break;
		}
		while (engine_Status == 1)
		{

			printf("Sensors Set Menu: \n \n");
			printf("a. Turn off the engine \n"
					"b. Set the traffic light color \n"
					"c. Set the room temperature (Temperature Sensor) \n");
#if WITH_ENGINE_TEMP_CONTROLLER
			printf("d. Set the engine temperature (Engine Temperature Sensor) \n \n");
#endif

			scanf(" %c", &choice2);
			switch(choice2)
			{

			case 'a':
				printf("\tEngine OFF \n \n");
				engine_Status =0;
				break;

			case 'b':
				printf("What is the traffic light color (G, R, O)?\n");
				scanf(" %c", &color);
				speed =TrafficLightsSpeed(color);
				printf("\t Vehicle speed is set to %d km/hr \n \n", speed);
				if (speed == 30 )
				{
					if (AC_Status == 0) AC_Status =1;
					Room_temp = Room_temp * (5/4)+1;

					if (Control_Status == 0) Control_Status = 1;
					engine_temp = engine_temp * (5/4)+1;
				}
				break;

			case 'c':
				printf("What is the temperature in your room \n");
				scanf("%d", &Room_temp);
				AC_Status = SetRoomTemp(&Room_temp);
				if (AC_Status == 1) printf("\t AC is ON and temperature is set to %d \n \n", Room_temp);
				else printf("\t AC is OFF \n \n");
				break;
#if WITH_ENGINE_TEMP_CONTROLLER
			case 'd':
				printf("What is the engine temperature \n");
				engine_temp=0;
				scanf("%d", &engine_temp);
				Control_Status = SetEngineTemp(&engine_temp);
				if (Control_Status == 1) printf("\t Engine Temperature Controller is ON "
						"and temperature is set to %d \n \n", engine_temp);
				else printf("\t Engine Temperature Controller is OFF \n \n");
				break;
#endif
			default:
				printf("\t Invalid Input! \n \n");
				break;

			}


			printf("Current Vehicle Status is :\n \n");

			if (engine_Status == 1) printf("i. engine is ON \n");
			else printf("i. engine is OFF \n");

			if (AC_Status == 1) printf("ii. AC is ON \n");
			else printf("ii. AC is OFF \n");

			printf("iii. Vehicle speed is: %d km/hr \n", speed);

			printf("iv. Room Temperature is: %d\n", Room_temp);
#if WITH_ENGINE_TEMP_CONTROLLER
			if (Control_Status == 1) printf("v. Engine Temperature Controller State is ON \n");
			else printf("v. Engine Temperature Controller State is OFF \n");

			printf("vi. Engine Temperature. is: %d\n \n",engine_temp);
#endif



		}
	}
}

int TrafficLightsSpeed (char color)
{
	int speed=0;
	switch(color)
	{
	case 'G':
		speed =100;
		break;
	case 'O':
		speed =30;
		break;
	case 'R':
		speed =0;
		break;
	default:
		printf("Invalid Color !");
	}
	return speed;
}

int SetRoomTemp(int *Room_temp)
{
	int AC_Status;
	if (*Room_temp <10 )
	{
		AC_Status=1;
		*Room_temp =20;
	}
	else if (*Room_temp >30 )
	{
		AC_Status=1;
		*Room_temp =20;
	}
	else
	{
		AC_Status=0;
	}
	return AC_Status;
}

int SetEngineTemp (int *engine_temp)
{
	int Control_Status;
	if (*engine_temp <100 )
	{
		Control_Status =1;
		*engine_temp=125;
	}
	else if (*engine_temp >150 )
	{
		Control_Status =1;
		*engine_temp=125;
	}
	else
	{
		Control_Status =0;
	}
	return Control_Status;
}


