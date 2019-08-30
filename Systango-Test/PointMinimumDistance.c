//
//  main.c
//  Systango-Test
//
//  Created by Systango on 27/08/19.
//  Copyright © 2019 Systango. All rights reserved.
//

#include <stdio.h>
#include "math.h"
struct Position
{
    int x, y;
};

struct Line
{
    struct Position from;
    struct Position to;
    double distance;
};

void calculateDistanceOfLine(struct Line *line){
    line->distance = 32;
    struct Position a = line->from;
    struct Position b = line->to;
    
    double xDist = a.x - b.x;
    double yDist = a.y - b.y;
    double distance = sqrt(xDist * xDist + yDist * yDist);
    line->distance = distance;
}

int main(int argc, const char * argv[]) {
    int n;
    while(1){
        printf("Enter number of point(s): ");
        scanf("%d",&n);
        if (n>2){
            break;
        }else{
        printf("Number of points should be more than 2\n");
        }
    }
    
    struct Position items[n];
    int i = 0;
    // Taking input from user
    while (i < n) {
        printf("Enter point(%d) X coordinates:",i);
        scanf("%d",&items[i].x);
        printf("Enter point(%d) Y coordinates:",i);
        scanf("%d",&items[i].y);
        printf("Entered coordinate - (%d, %d)\n",items[i].x,items[i].y);
        i++;
    }

    int fromIndex = 0;
    int toIndex = 1;
    struct Line minDistanceLine = {{0, 0},{0, 0}, -1}; // Initialize destance by default value
    
    while (fromIndex < n-1) {
        struct Line newline;
        newline.from = items[fromIndex];
        newline.to = items[toIndex];
        calculateDistanceOfLine(&newline);
        
        if (minDistanceLine.distance == -1 || (minDistanceLine.distance > newline.distance)){
            minDistanceLine = newline;
        }
        
        if (toIndex == n-1){
            fromIndex++;
            toIndex= fromIndex+1;
        }else{
            toIndex++;
        }
    }
    
    printf("\nMinimum distance is %f between points (%d,%d) & (%d,%d)\n",minDistanceLine.distance,minDistanceLine.from.x,minDistanceLine.from.y,minDistanceLine.to.x,minDistanceLine.to.y );
    
    return 0;
}
