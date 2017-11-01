package com.defold.android.vibrate;

import android.util.Log;
import android.os.Vibrator;
import android.app.Activity;
import android.content.Context;
import java.lang.Runnable;

class VibrateExtension {
	private static final String TAG = "vibrate";

	public static void Vibrate(final Activity activity) {
		activity.runOnUiThread(new Runnable() {
			@Override
			public void run() {
				Vibrator vibrator = (Vibrator)activity.getSystemService(Context.VIBRATOR_SERVICE);
				vibrator.vibrate(1000);
			}
		});
	}
}
