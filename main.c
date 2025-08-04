#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <time.h>

#define AMOUNT 1

void ClearScreen() {
    system("clear");
}

void devLogs() {
    //Add devLog logic here later
}

int main() {
   ClearScreen();
   printf("##     ##     ##  #####    ######  ##  #####    ###     ###  ##       ##  ######  #####     #####\n"); 
   printf("##     ##     ##  ##  ##   ##      ##  ##  ##   ## #   # ##  ##       ##  ##  ##  ##  ##    ##   \n");
   printf("##     ##     ##  ##  ##   ####    ##  ##  ##   ##  # #  ##  ##   #   ##  ##  ##  ##  ##    ##   \n");
   printf("##     ##     ##  #####    ##      ##  #####    ##   #   ##  ##  # #  ##  ######  ######    #####\n");
   printf("##      ##   ##   ##  ##   ##      ##  ##  ##   ##       ##  ## #   # ##  ##  ##  ##   ##   ##   \n");
   printf("#####    #####    ##   ##  ##      ##  ##   ##  ##       ##  ###     ###  ##  ##  ##    ##  #####\n\n");
   printf("Welcome to the dev centre of Lightweight Unix Robotic Firmware!!!\n");
   printf("To start with the LurFirmware please enter a valid dev command...\n");
   printf("Commands can be found at the github in your manual.\n\n");
   printf("===========================\n");
   printf("| Current version [v0.05] |\n");
   printf("===========================\n");

   while (true) {
       
       int MaxInput_len = 100;

       if (!MaxInput_len) {
           printf("**CRITICAL ERROR** [Memory Allocation ERROR!!!]");
           return 1; 
       }
       
       char *command = malloc(MaxInput_len);

       if (!command) {
           printf("**CRITICAL ERROR** [Failed to allocate memory to command char!!!]");
       }
       
       const char Shutdown[] = "exit";
       const char Logs[] = "devLogs";
       const char wavRandom[] = "wavRandom"; 
       const char AudioFiles[AMOUNT][50] = {
           "mpv Friend.wav --no-video"
       };

       const char *AudioPath = "/root/LurFirmware/AudioFiles";

       int numCommands = sizeof(AudioFiles) / sizeof(command[0]);
       srand(time(NULL));

       int index = rand() % numCommands;
      
       printf("==> ");

       fgets(command, MaxInput_len, stdin);
       command[strcspn(command, "\n")] = '\0'; 

       if (strcmp(command, Shutdown) == 0) {
           ClearScreen();
           free(command);
           command = NULL;
           printf("Memory successfully freed!!!\n");
           sleep(2);
           ClearScreen();
           return 0;
       } else if (strcmp(command, Logs) == 0) {
           ClearScreen();
           printf("Not yet implimented\n");
           sleep(3);
       } else if (strcmp(command, wavRandom) == 0) {
          DIR *AudioDir = opendir(AudioPath);

          if (AudioDir == NULL) {
              perror("Failed to open source to audio files... :(\n");
              return 1;;
          }

          chdir(AudioPath);
          system(AudioFiles[index]);

          if (!AudioFiles) {
              printf("Failed to read wav files");
          }
       }
   }
   
   return 1; //Error in code if return 1 appears
}
