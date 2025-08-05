#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <time.h>

#define AMOUNT 4
#define wavBOOT 1

void ClearScreen() {
    system("clear");
}

void BOOT() {
   const char *BootPath = "/root/LurFirmware/AudioFiles";
   const char wavBoot[wavBOOT][35] = {"aplay BOOT.wav >/dev/null 2>&1"};

   int numBoot = sizeof(wavBoot) / sizeof(wavBoot[0]);
   srand(time(NULL));

   int wavOnBoot = rand() % numBoot;

   DIR *BootAudio = opendir(BootPath);

   chdir(BootPath);
   system(wavBoot[wavOnBoot]);
}

int main(void) {
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
   BOOT();
 
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
           "aplay Friend.wav",
           "aplay Bored.wav", 
           "aplay Play.wav",
           "aplay WhatAmI.wav"
       };
       const char FunAudio[AMOUNT][50] = {
           "aplay Pee.wav",
           "aplay Poo.wav",
           "aplay SelfWare_PeeJoke.wav", 
           "aplay SelfAware_Poo.wav"
       };

       const char *AudioPath = "/root/LurFirmware/AudioFiles";

       int numCommands = sizeof(AudioFiles) / sizeof(AudioFiles[0]);
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
