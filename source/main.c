#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <switch.h>


int main(int argc, char* argv[])
{
 
    consoleInit(NULL);

    padConfigureInput(8, HidNpadStyleSet_NpadStandard);

    // set the controller to horizontal mode

    hidSetNpadJoyHoldType(HidNpadJoyHoldType_Horizontal);
        //assign the LEFT joycon controller to player 1

    hidSetNpadJoyAssignmentModeSingle(HidNpadIdType_No1, HidNpadJoyDeviceType_Left);

       // assign the right controller to player 2
    hidSetNpadJoyAssignmentModeSingle(HidNpadIdType_No2, HidNpadJoyDeviceType_Right);

    // Initialize the default gamepad (which reads handheld mode inputs as well as the first connected controller)
    PadState pad;
    padInitializeDefault(&pad);


    printf("\x1b[1;1HDetach Joycons, then Press Home Button and return to your game.");
    printf("\x1b[4;1HSplitJoycons by @xick");


    // Main loop
    while(appletMainLoop())
    {
        padUpdate(&pad);

        u64 kDown = padGetButtonsDown(&pad);

        if (kDown & HidNpadButton_Plus) {
            break; // break in order to return to hbmenu if the user presses the PLUS button
        }

        consoleUpdate(NULL);
    }

    consoleExit(NULL);
    return 0;
}
