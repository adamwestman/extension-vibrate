#include <dmsdk/sdk.h>
#include "vibrate_private.h"

#if defined(DM_PLATFORM_IOS)


#include "AudioToolbox/AudioServices.h"


int VibratePlatform_Trigger()
{
	AudioServicesPlaySystemSound(kSystemSoundID_Vibrate);
	return 1;
}

#endif
