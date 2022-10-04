// Name: Tristan Arana Charlebois
// Student Number: 6680672

#include <iostream>
#include <cmath>
#include <iomanip>
#include <sstream>

using namespace std;

void pgm(int graduate, int frames){

    FILE* pgm; // PGM image file
    int framenumber = 0001; // number of frame
    double x, temp_x = -4; // x minimum, current x
    double y = -12; // y minimum
    double z = 0; // z minimum
    double intermediate_x = (double) 10 / graduate; // equal distanced values from x min to x max (-4 to 6) based on graduations
    double intermediate_y = (double) 17 / graduate; // equal distanced values from y min to y max (-12 to 5) based on graduations
    double intermediate_z = (double) 6.28318530718 / frames;
    int full_graduate = pow(graduate, 2); // total number of values
    int graph[full_graduate]; // array to hold values

    for (int j = 0; j < frames; j++){ // loop thorugh frames

        for (int i = 0; i < full_graduate; i++){ // loop through values

            graph[i] =  (int) ((127.5 * (1 + (cos(z) * (((0.5) * sin(temp_x)) + ((0.5) * cos(y))))))); // calculate function and format for PGM
            temp_x += intermediate_x; // next x
                        
            if (i % graduate == 0){  // next row

                y += intermediate_y; // next y
                temp_x = x; // reset x for new row

            }  

        }

        ostringstream name; // filename

        name <<"anim"<<setfill('0')<<setw(4)<<framenumber<<".pgm"; // format for animXXXX.pgm
        pgm = fopen(name.str().c_str(), "wb"); // create PGM file with proper name

        framenumber += 1; // next frame number

        fprintf(pgm, "P2\n"); // PGM plain formatting
        fprintf(pgm, "%d %d\n", graduate, graduate);
        fprintf(pgm, "255\n");

        for (int i = 0; i < full_graduate; i++){ // loop through values

            fprintf(pgm, "%d ", graph[i]); // store value

            if (i % graduate == 0){ // next row

                fprintf(pgm, "\n");

            }

        }

        fclose(pgm); // close file

        z += intermediate_z; // next z for new frame

    }

            
} 

int main(){

    int graduations, frames; // user input

    cerr<<"Number of graduations per axis: ";
    cin>>graduations;
    cerr<<"Number of frames: ";
    cin>>frames;

    pgm(graduations, frames); // calculate values and create file
    
}