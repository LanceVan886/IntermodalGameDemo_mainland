package com.cftech.gamesdk.demo;

import androidx.appcompat.app.AppCompatActivity;

import android.graphics.Rect;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.EditText;
import android.widget.Toast;

import com.cftech.gamelibrary.CFGameSDK;
import com.cftech.gamelibrary.utils.CFDensityUtil;
import com.cftech.gamelibrary.utils.CFFP;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        setUpSDK();


        findViewById(R.id.btnLogin).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                CFGameSDK.setUserInfo("123456", "", new CFGameSDK.ICFLoginCallback() {
                    @Override
                    public void onLoginSuccess() {
                        Log.i("MainActivity", "onLoginSuccess.");
                        Toast.makeText(MainActivity.this, "登录成功", Toast.LENGTH_SHORT).show();
                    }

                    @Override
                    public void onLoginFail(int code, String msg) {
                        Log.e("MainActivity", "onLoginFail.");
                        Toast.makeText(MainActivity.this, "登录失败", Toast.LENGTH_SHORT).show();
                    }

                    @Override
                    public void onRefreshToken(String token) {
                        Log.i("MainActivity", "onRefreshToken：" + token);
                    }
                });
            }
        });

        findViewById(R.id.btnShowGameList).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                CFGameSDK.showGameListDialog(MainActivity.this);
            }
        });

    }

    private void setUpSDK() {

        CFGameSDK.setBizCallback(new CFGameSDK.ICFBizCallback() {
            @Override
            public void onOpenChargePage() {
                Log.i("MainActivity", "open charge page.");
                Toast.makeText(MainActivity.this, "拉起充值", Toast.LENGTH_SHORT).show();
            }

            @Override
            public String onGetCurrentRoomId() {
                Log.i("MainActivity", "get current room id.");
                return "200016";
            }

            @Override
            public boolean onIsRoomOwner() {
                return true;
            }

            @Override
            public CFGameSDK.CFRect onWindowSafeArea() {
                return new CFGameSDK.CFRect(0, CFDensityUtil.dp2px(MainActivity.this, 200), 0, CFDensityUtil.dp2px(MainActivity.this, 280), 0.6f);
            }
        });
    }
}