package com.defold.android.vibrate;

import android.util.Log;
import android.os.Vibrator;
import android.os.VibrationEffect;
import android.os.Build;
import android.app.Activity;
import android.content.Context;
import java.lang.Runnable;

class VibrateExtension {
	private static final String TAG = "vibrate";

	public static void Vibrate(final Activity activity) {
		activity.runOnUiThread(new Runnable() {
			@Override
			public void run() {
				Vibrator v = (Vibrator)activity.getSystemService(Context.VIBRATOR_SERVICE);
				if (Build.VERSION.SDK_INT >= 26) {
					v.vibrate(VibrationEffect.createOneShot(1000, VibrationEffect.DEFAULT_AMPLITUDE));
				} else {
					//deprecated in API 26 
					v.vibrate(1000);
				}
			}
		});
	}
}
