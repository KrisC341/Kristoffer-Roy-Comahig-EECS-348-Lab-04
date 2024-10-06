#include <stdio.h>
#include <stdlib.h>

// The following massive blocks of code are function declarations and definitions for temperature conversion. 
float celsius_to_fahrenheit(float celsius);
float fahrenheit_to_celsius(float fahrenheit);
float celsius_to_kelvin(float celsius);
float kelvin_to_celsius(float kelvin);
float kelvin_to_fahrenheit(float kelvin);
float fahrenheit_to_kelvin(float fahrenheit);

float tempConvert(float temp, int tempScale, int conScale);

void categorize_temperature(float celsius);

float celsius_to_fahrenheit(float celsius){
    return ((9.0/5.0)*celsius) + 32;
}

float fahrenheit_to_celsius(float fahrenheit){
    return (fahrenheit - 32)*(5.0/9.0);
}

float celsius_to_kelvin(float celsius){
    return celsius + 273.15;
}

float kelvin_to_celsius(float kelvin){
    return kelvin - 273.15;
}

float kelvin_to_fahrenheit(float kelvin){
    return ((kelvin - 273.15) * 1.8) + 32;
}

float fahrenheit_to_kelvin(float fahrenheit){
    return ((fahrenheit - 32) * 5.0/9.0) + 273.15;
}

int main(){
    float ogTemp;
    int tempScale;
    int conScale;
    char buffer; //this variable is used to clear the input buffer in the event of invalid input.
    printf("Enter the temperature: "); 
    
    //the following three blocks are user inputs for temperature, temperature scale, and conversion scale
    //inputCheck uses the fact scanf represents a successful input by returning an integer value of 1
    //if it returns anything besides an integer value of 1, the input received is invalid, thus necessitating a restart. 
    

    int inputCheck = scanf("%f", &ogTemp);

    if(inputCheck != 1){
        printf("You have entered an invalid input. This program will now restart.\n");
        scanf(" %c", &buffer);
        main();
        exit(1);
    }

    printf("Choose the current scale (1) Celsius (2) Fahrenheit (3) Kelvin: ");
    inputCheck = scanf("%d", &tempScale);
    if(inputCheck != 1){
        printf("You have entered an invalid input. This program will now restart.\n");
        scanf(" %c", &buffer);
        main();
        exit(1);
    }
    printf("Convert to (1) Celsius (2) Fahrenheit (3) Kelvin: ");
    inputCheck = scanf("%d", &conScale);
    if(inputCheck != 1){
        printf("You have entered an invalid input. This program will now restart.\n");
        scanf(" %c", &buffer);
        main();
        exit(1);
    }

    //determines if any scale selection is out of range, thus necessitating a restart
    if((tempScale < 1) || (tempScale > 3) || (conScale < 1) || (conScale > 3)){
        printf("You have selected a current or conversion scale that is invalid. This program will now restart.\n");
        main();
        exit(1);
    }
    //determines if any temperature input is invalid, thus necessitating a restart
    if ((tempScale == 3) && (ogTemp < 0)){
        printf("You have entered an invalid temperature. This program will now restart.\n");
        main();
        exit(1);
    }

    //checks if the current and conversion scale are the same, thus necessitating a restart
    if (tempScale == conScale){
        printf("You are attempting to convert a temperature back to its original scale. This program will now restart.\n");
        main();
        exit(1);
    }
    

    //declares two variables to keep track of what scale the temperature has been converted to and the actual value of the converted scale
    float converted;
    char scale;
    if(conScale == 1){
        scale = 'C';
    } else if(conScale == 2){
        scale = 'F';
    } else if(conScale == 3){
        scale = 'K';
    }

    //calls the tempConvert function to determine the temperature upon conversion. This converted value is then printed.
    converted = tempConvert(ogTemp, tempScale, conScale);
    printf("Converted temperature: %f %c\n", converted, scale);
  


    //checks if temp needs to be converted for categorization to celsius.
    if(conScale != 1){
        if(conScale == 2){
            converted = fahrenheit_to_celsius(converted);
        } else{
            converted = kelvin_to_celsius(converted);
        }
    }
    


    //calls the categorize_temperature function
    categorize_temperature(converted);



    //ends the program.
    return 0;
}

float tempConvert(float temp, int tempScale, int conScale){
    //this if-else block uses tempScale and conScale to determine which temperature conversion function needs to be called to receive the correct converted value.
    if(tempScale == 1){
        if(conScale == 2){
            return celsius_to_fahrenheit(temp);
        } else if(conScale == 3){
            return celsius_to_kelvin(temp);
        }    
    } else if(tempScale == 2){
        if(conScale == 1){
            return fahrenheit_to_celsius(temp);
        } else if(conScale == 3){
            return fahrenheit_to_kelvin(temp);
        }
    } else if(tempScale == 3){
        if(conScale == 1){
            return kelvin_to_celsius(temp);
        } else if(conScale == 2){
            return kelvin_to_fahrenheit(temp);
        }
    } else{
        //legacy error handling.
        printf("ERROR");
    }

}

void categorize_temperature(float celsius){
    //determines what category the input temperature falls in and prints out the corresponding category and weather advisory. 
    if(celsius < 0){
        printf("Temperature Category: Freezing\n");
        printf("Weather Advisory: Stay inside, freezing temps.");
    } else if(celsius < 10){
        printf("Temperature Category: Cold\n");
        printf("Weather Advisory: Put on a jacket");
    } else if(celsius < 25){
        printf("Temperature Category: Comfortable\n");
        printf("Weather Advisory: Enjoy yourself, wewather is comfy.");
    } else if(celsius < 35){
        printf("Temperature Category: Hot\n");
        printf("Weather Advisory: Wear light clothing.");
    } else if(celsius >= 35){
        printf("Temperature Category: Extreme Heat\n");
        printf("Weather Advisory: Stay inside, extreme heat wave in progress.");
    }
}



main();