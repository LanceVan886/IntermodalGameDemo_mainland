package com.cftech.gamesdk.demo;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.EditText;

import com.cftech.gamelibrary.CFGameSDK;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        findViewById(R.id.btnLogin).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                CFGameSDK.initSDK(getApplication(), 1,  "", false);
            }
        });

        findViewById(R.id.btnShowGameList).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                CFGameSDK.showGameListDialog(MainActivity.this);
            }
        });

        findViewById(R.id.btnEnterFullGame).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                String userId = ((EditText)findViewById(R.id.etGameId)).getText().toString();
                CFGameSDK.setUserInfo(userId, "");
            }
        });
    }
}