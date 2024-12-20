package com.cftech.gamesdk.demo;

import android.app.Application;

import com.cftech.gamelibrary.CFGameSDK;

public class BaseApplication extends Application {

    @Override
    public void onCreate() {
        super.onCreate();
        CFGameSDK.initSDK(this, 1013140,  "zh_CN", true);
    }
}
