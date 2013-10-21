#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//
// MATH 442: pgmdo
//
// Simple portable grey map (PGM) image processor.
//


// outASCII
// 
// Output a character to the given file, one that
// corresponds in brightness to the value (from 0.0
// to 1.0) given.
//
void outASCII(FILE *f, float value) {
  if (value > 0.8) {
    fprintf(f,"#");
  } else if (value > 0.5) {
    fprintf(f,"x");
  } else if (value > 0.25) {
    fprintf(f,";");
  } else if (value > 0.15) {
    fprintf(f,",");
  } else {
    fprintf(f," ");
  }
}

// eatLine
//
// Reads a line of characters.
//
void eatLine(FILE *f) {
  while (fgetc(f) != '\n');
}

float *readImage(FILE *inf) {
  int width,height,max;
  rewind(inf);
  eatLine(inf);
  eatLine(inf);
  fscanf(inf,"%d",&width);
  fscanf(inf,"%d",&height);
  fscanf(inf,"%d",&max);
  int r,c;
  int pixel;
  float gval;
  float *gvalues = (float *)malloc((width*height)*sizeof(float)); 
  int i;
  int k;


  for(r=0; r<height; r++) {
    for(c=0; c<width; c++) {
      fscanf(inf, "%d", &pixel);
      gval = ((float)pixel/(float)max);
      gvalues[i] = gval;
      i++;
    }
  }
  return gvalues;
}

void invertImage(FILE *inf, FILE *outf) {
  int i=0;
  int width;
  int height;
  int max;
  int w=0;

  // Get width, height, and max from the file
  rewind(inf);
  eatLine(inf);
  eatLine(inf);
  fscanf(inf,"%d",&width);
  fscanf(inf,"%d",&height);
  fscanf(inf,"%d",&max);

  // Initialize the array
  float *darkValues;
  // Read the values from the pgm file
  darkValues = readImage(inf);
  // Find the total number of 'i's we will have
  int amtValues = width*height;

  // Print the header to our pgm file
  fprintf(outf,"P2\n");
  fprintf(outf,"# CREATOR: BLAKE, THE MASTER OF C\n");
  fprintf(outf,"%d %d\n",width,height);
  fprintf(outf,"%d\n",max);

  // For each pixel, invert the grey value
  while (i < amtValues) {
    fprintf(outf,"%d\n",((int)(max*(1.0-darkValues[i]))));
    i++;
  }
}

void blurImage(FILE *inf, FILE *outf) {
  int width;
  int height;
  int max;
  int x,y;
  int i=0;
  rewind(inf);
  eatLine(inf);
  eatLine(inf);
  fscanf(inf,"%d",&width);
  fscanf(inf,"%d",&height);
  fscanf(inf,"%d",&max);
  float *gValues;
  float gInstance;
  int amtValues = width*height;
  gValues = readImage(inf);

  fprintf(outf,"P2\n");
  fprintf(outf,"# CREATOR: BLAKE, THE MASTER OF C\n");
  fprintf(outf,"%d %d\n",width,height);
  fprintf(outf,"%d\n",max);

  while (i < amtValues) {
    // Determine x,y value of i
    x = (int)(i % width);
    y = (int)floor(i/width);
    // Blur depending on which of 9 cases we fall into
    if (x == 0 && y == 0) {
      // 1.
      gInstance = (.25)*(2*gValues[i] + gValues[i+1] + gValues[width]);
    } else if (y == 0 && (0 < x) && (x < (width-1))) {
      // 2.
      gInstance = (.167)*(3*gValues[i] + gValues[i-1] + gValues[i+1] + gValues[i+width]);
    } else if (y == 0 && x == (width-1)) {
      // 3.
      gInstance = (.25)*(2*gValues[i] + gValues[i-1] + gValues[i+width]);
    } else if (x == (width-1) && (0 < y) && (y < (height-1))) {
      // 4.
      gInstance = (.167)*(3*gValues[i] + gValues[i-1] + gValues[i-width] + gValues[i+width]);
    } else if (y == (height-1) && x == (width-1)) {
      // 5.
      gInstance = (.25)*(2*gValues[i] + gValues[i-1] + gValues[i-width]);
    } else if (y == (height-1) && (0 < x) && (x < (width-1))) {
      // 6.
      gInstance = (.167)*(3*gValues[i] + gValues[i-1] + gValues[i+1] + gValues[i-width]);
    } else if (x == 0 && y == (height-1)) {
      // 7.
      gInstance = (.25)*(2*gValues[i] + gValues[i+1] + gValues[i-width]);
    } else if (x == 0 && (0 < y) && (y < (height-1))) {
      // 8.
      gInstance = (.167)*(3*gValues[i] + gValues[i+1] + gValues[i+width] + gValues[i-width]);
    } else {
      // 9.
      gInstance = (.125)*(4.0*gValues[i] + gValues[i-1] + gValues[i+1] + gValues[i-width] + gValues[i+width]);
    }
    if (gInstance > 1) {
      gInstance = 1;
    }
    gValues[i] = gInstance;
    fprintf(outf,"%d\n",(int)(max*gValues[i]));
    i++;
  }
}

// echoASCII
//
// Read the a PGM file opened as "inf" and write a text file
// of characters to "outf", ones whose brightness suggest the
// levels of grey specified by the original image.
//
void echoASCII(FILE *inf, FILE *outf) {

  int width, height;
  int max;
  int pixel;
  int r,c;

  // Read the PGM file's header info,
                             // for example: 
       
  eatLine(inf);                // P5 (or P2)
  eatLine(inf);                // # this was produced by some software
  fscanf(inf, "%d", &width);   // 9 5
  fscanf(inf, "%d", &height);
  fscanf(inf, "%d", &max);     // 255

  // for each image row
  for (r=0; r<height; r++) {
    // for each image column
    for (c=0; c<width; c++) {
      
      // read a PGM pixel grey value (from 0 to max)
      fscanf(inf,"%d", &pixel);
                             // 0 10 30 80 120 135 225 245 255 
                             // (4 more rows)

      // output a pixel character to make ASCII art
      outASCII(outf,(float)pixel/(float)max);
    }

    // end the ASCII text line 
    fprintf(outf,"\n");
  }
}

// usage
//
// Outputs a message that gives the command-line description.
//
void usage(char *cmd) {
  fprintf(stderr,"usage: %s <option> <infile> <outfile>\n", cmd);
  fprintf(stderr,"\twhere <infile> is a PGM and <option> is one of\n");
  fprintf(stderr,"\t\t--blur    :outputs a blurred PGM image\n");
  fprintf(stderr,"\t\t--invert  :outputs PGM negative image\n");
  fprintf(stderr,"\t\t--ascii   :converts to ASCII art\n");
}

// main
// 
// This program accepts three arguments: a processing option
// ("blur", "invert", or "ascii"), a PGM file name for input,
// and a text file name for output.  It reads the PGM file and
// creates an output file with either an appropriate PGM (if 
// one of the first two options are given) or a text file (if
// the last option is given).
//
// Right now, only the "ascii" option works.
//
int main(int argc, char **argv) {

  // input and output file "handles"
  FILE *inf, *outf;

  if (argc < 4) {
    
    // whoops! not enough arguments
    fprintf(stderr,"Error: not enough arguments!\n");
    usage(argv[0]);
    return -1;

  } else {

    // open the input (PGM) file
    inf = fopen(argv[2],"r");
    if (inf == NULL) {
      fprintf(stderr,"Error: can't open file '%s' for reading.\n",argv[2]);
      return -1;
    }

    // open the output file
    outf = fopen(argv[3],"w");
    if (outf == NULL) {
      fprintf(stderr,"Error: can't open file '%s' for writing.\n",argv[3]);
      return -1;
    }

    if (strcmp(argv[1],"--blur") == 0) {

      blurImage(inf,outf);

    } else if (strcmp(argv[1],"--invert") == 0) {

      invertImage(inf,outf);
      //
      // write the code that inverts the image
      //  

    } else if (strcmp(argv[1],"--ascii") == 0) {

      echoASCII(inf,outf);
      //
      // change this so that it is given an image array and
      // the outf
      //

    } else {

      fprintf(stderr,"Error: unrecognized option '%s.'\n",argv[1]);
      usage(argv[0]);
      
      // return FAIL
      return -1;
    }

    // close the files
    fclose(inf);
    fclose(outf);

    // return OK
    return 0;
  }
}
  
