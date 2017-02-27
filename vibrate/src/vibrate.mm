#include <dmsdk/sdk.h>
#include "vibrate_private.h"

#if defined(DM_PLATFORM_IOS)


#include "AudioToolbox/AudioServices.h"


int VibratePlatform_Trigger()
{

	//NSLog(@"I'm vibrating");
	AudioServicesPlaySystemSound(kSystemSoundID_Vibrate);
	return 1;
}

#endif // DM_PLATFORM_IOS/DM_PLATFORM_OSX