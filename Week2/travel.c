#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    char cspeed[100];
    printf("What is your current km/h? ");
    fgets(cspeed, 100, stdin);

    int ispeed = 0;
    int i = 0;
    while (cspeed[i] != 10) {
        cspeed[i] -= 48;
        ispeed *= 10;
        ispeed += cspeed[i];
        i++;
    }

    float mph = ispeed * 0.624;

    char chours[100];
    printf("How long are you travelling for (in hours)? ");
    fgets(chours, 100, stdin);

    float fhours = atof(chours);
    
    float km = fhours * ispeed;
    float miles = km * 0.624;
    
    printf("You will cover %.2f km. (%.2f miles)\n", km, miles);
    printf("While travelling at %.2dkm/h. (%.2f mph)\n", ispeed, mph);
}