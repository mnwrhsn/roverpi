#include"input.h"

int input(int verbose)
{
	int input;
	while(1)
	{
		input = getch();
		switch(input)
		{
			case 'w':
			{
				if(PROTECT && forward_status() == 0)
				{
					backward_set(0);
					left_set(0);
					right_set(0);
					forward_set(2);
				}
				else
				{
					forward_set(2);
				}
				if(verbose)
				{
					if(forward_status() == 1)
					{
						printf("FORWARD ACTIVATED\n");
					}
					else if(forward_status() == 0)
					{
						printf("FORWARD DEACTIVATED\n");
					}
					else
					{
						printf("EXCEPTION OCCURED: FORWARD STATUS ELSE\n");
					}
				}
				break;
			}
			case 'a':
			{
				if(PROTECT && left_status() == 0)
				{
					backward_set(0);
					forward_set(0);
					right_set(0);
					left_set(2);
				}
				else
				{
					left_set(2);
				}
				if(verbose)
				{
					if(left_status() == 1)
					{
						printf("LEFT ACTIVATED\n");
                	                }
                	                else if(left_status() == 0)
                	                {
                	                        printf("LEFT DEACTIVATED\n");
                	                }
                	                else
					{
						printf("EXCEPTION OCCURED: LEFT STATUS ELSE\n");
					}
				}
				break;
			}
			case 's':
			{
				if(PROTECT && backward_status() == 0)
				{
					forward_set(0);
					left_set(0);
					right_set(0);
					backward_set(2);
				}
				else
				{
					backward_set(2);
				}
				if(verbose)
				{
					if(backward_status() == 1)
                        	        {
                        	                printf("BACKWARD ACTIVATED\n");
                        	        }
                        	        else if(backward_status() == 0)
                        	        {
                                	        printf("BACKWARD DEACTIVATED\n");
                        	        }
					else
					{
					printf("EXCEPTION OCCURED: BACKWARD STATUS ELSE\n");
					}
				}
				break;
			}
			case 'd':
			{
				if(PROTECT && right_status() == 0)
				{
					forward_set(0);
					backward_set(0);
					left_set(0);
					right_set(2);
				}
				else
				{
					right_set(2);
				}
				if(verbose)
				{
					if(right_status() == 1)
					{
						printf("RIGHT ACTIVATED\n");
					}
                               		else if(right_status() == 0)
                           		{
                                        	printf("RIGHT DEACTIVATED\n");
                               		}
                                	else
                                	{
                                        	printf("EXCEPTION OCCURED: RIGHT STATUS ELSE\n");
                                	}
				}
				break;
			}
			case 'q':
			{
				printf("QUIT\n");
				forward_set(0);
				backward_set(0);
				left_set(0);
				right_set(0);
				bcm2835_close();
				return 0;
			}
			default:
			{
				printf("KEY ERROR\n");
			}
		}
	}
}
