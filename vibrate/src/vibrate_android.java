package com.defold.android.vibrate;


import android.util.Log;
import android.os.Vibrator;

class VibrateExtension {
	private static final String TAG = "defold";

	private static VibrateExtension instance = null;

	private VibrateExtension() {

	}

	public static VibrateExtension getInstance() {
		if (instance == null) {
			instance = new VibrateExtension();
		}
		return instance;
	}

	public static void Vibrate(Context context) {
		Vibrator vibrator = (Vibrator)context.getSystemService(Context.VIBRATOR_SERVICE);
		vibrator.vibrate(1000);
	}
}
