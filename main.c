//
//  main.c
//  TreeSimulator
//
//  Created by Zefan Sramek on 2015-04-12.
//  Copyright (c) 2015 Zefan. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, const char * argv[])
{
    //Opening Message
    printf("Welcome to Tree Simulator by Zefan Sramek\n\n");
    printf("In the beginning the seed sprouts...\n");
    
    //Declare Variables
    int height = 1;
    int leaves = 2;
    int alive = 1; //1 - alive, 0 - dead
    int year = 1;
    int day = 0;
    int season = 1; // 1 - Spring, 2 - Summer, 3 - Fall, 4 - Winter
    int weather = 1; //1 - Sun, 2 - Cloud, 3 - Rain, 4 - Snow
    int temperature; //In degrees Celcius
    int moisture = 50; // From 0 to 100
    
    //Main Loop
    while (alive == 1)
    {
        for (day = 0; day <= 365; day++)
        {
            //Determine the Season
            if (day < 92)
            {
                //Spring
                season = 1;
            }
            else if (day >= 92 && day < 183)
            {
                //Summer
                season = 2;
            }
            else if (day >= 183 && day < 273)
            {
                //Fall
                season = 3;
            }
            else
            {
                //Winter
                season = 4;
            }
            
            //Determine the Weather
            if (season == 1)
            {
                //Spring
                weather = rand() % 3 + 1;
                
                if (weather == 1)
                {
                    temperature = rand() % 18 + 10;
                }
                else if (weather == 2)
                {
                    temperature = rand() % 14 + 6;
                }
                else
                {
                    temperature = rand() % 10 + 4;
                }
                
            }
            else if (season == 2)
            {
                //Summer
                weather = rand() % 3 + 1;
                if (weather == 1)
                {
                    temperature = rand() % 35 + 25;
                }
                else if (weather == 2)
                {
                    temperature = rand() % 18 + 28;
                }
                else
                {
                    temperature = rand() % 18 + 22;
                }
            }
            else if (season == 3)
            {
                //Fall
                weather = rand() % 3 + 1;
                
                if (weather == 1)
                {
                    temperature = rand() % 25 + 15;
                }
                else if (weather == 2)
                {
                    temperature = rand() % 20 + 10;
                }
                else
                {
                    temperature = rand() % 15 + 5;
                }
            }
            else
            {
                //Winter
                weather = rand() %4 + 1;
                
                if (weather == 1)
                {
                    temperature = rand() % 5 - 5;
                }
                else if (weather == 2)
                {
                    temperature = rand() % 2 - 10;
                }
                else if (weather == 3)
                {
                    temperature = rand() % 5;
                }
                else
                {
                    temperature = rand() %-1 - 20;
                }
            }
            
            //Determine the Moisture
            if (weather == 1 && moisture > 0)
            {
                moisture--;
            }
            else if ((weather == 3 || weather == 4) && moisture < 100)
            {
                moisture++;
            }
            
            //Determine Tree Properties
            //Leaves
            if (moisture > 50 && temperature >= 15)
            {
                leaves++;
            }
            else if (moisture >= 20 && temperature >= 10)
            {
                leaves += 2;
            }
            else if (temperature < 10 || moisture < 20)
            {
                leaves--;
            }
            if (temperature < 0)
            {
                leaves -= 3;
            }
            if (leaves < 0)
            {
                leaves = 0;
            }
            //Height
            if (leaves > (height * 8) && height < 100)
            {
                height++;
            }
            
            /*
            //Survival
            if (leaves <= 0)
            {
                alive = 0;
                break;
            }
             */
            
            
            //Print Info
            printf("\n");
            printf("Year: %d\n", year);
            printf("Day: %d \n", day);
            //Season
            if (season == 1)
            {
                printf("Season: Spring\n");
            }
            else if (season == 2)
            {
                printf("Season: Summer\n");
            }
            else if (season == 3)
            {
                printf("Season: Fall\n");
            }
            else
            {
                printf("Season: Winter\n");
            }
            //Weather
            if (weather == 1)
            {
                printf("Weather: Sun\n");
            }
            else if (weather == 2)
            {
                printf("Weather: Cloud\n");
            }
            else if (weather == 3)
            {
                printf("Weather: Rain\n");
            }
            else
            {
                printf("Weather: Snow\n");
            }
            printf("Temperature: %d\n", temperature);
            printf("Moisture: %d\n", moisture);
            printf("Tree Height: %d\n", height);
            printf("Number of Leaves: %d\n", leaves);
            for (int i = 0; i < leaves; i++)
            {
                printf("/");
            }
            printf("\n");
            
            //Wait
            usleep(100000);
        }
        
        year++;
    }
    
    printf("The tree has died.\n");
    
    return 0;
}
