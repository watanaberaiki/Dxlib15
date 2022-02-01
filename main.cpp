#include "DxLib.h"

void DrawMirror(int x, int y, int r, int t, int angle);
// ウィンドウのタイトルに表示する文字列
const char TITLE[] = "LC1B_31_ワタナベライキ: 適当レーザー";

// ウィンドウ横幅
const int WIN_WIDTH = 1200;

// ウィンドウ縦幅
const int WIN_HEIGHT = 400;

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine,
                   _In_ int nCmdShow) {
	// ウィンドウモードに設定
	ChangeWindowMode(TRUE);

	// ウィンドウサイズを手動では変更させず、
	// かつウィンドウサイズに合わせて拡大できないようにする
	SetWindowSizeChangeEnableFlag(FALSE, FALSE);

	// タイトルを変更
	SetMainWindowText(TITLE);

	// 画面サイズの最大サイズ、カラービット数を設定(モニターの解像度に合わせる)
	SetGraphMode(WIN_WIDTH, WIN_HEIGHT, 32);

	// 画面サイズを設定(解像度との比率で設定)
	SetWindowSizeExtendRate(1.0);

	// 画面の背景色を設定する
	SetBackgroundColor(0x00, 0x00, 0x00);

	// DXlibの初期化
	if (DxLib_Init() == -1) { return -1; }

	// (ダブルバッファ)描画先グラフィック領域は裏面を指定
	SetDrawScreen(DX_SCREEN_BACK);

	// 画像などのリソースデータの変数宣言と読み込み


	// ゲームループで使う変数の宣言
	int scene = 0;
	int mirrorX = 640;
	int mirrorY = 256;
	int mirrorR = 32;
	int mirrorT = 10;
	int mirrorAngle = 0;
	// 最新のキーボード情報用
	char keys[256] = {0};

	// 1ループ(フレーム)前のキーボード情報
	char oldkeys[256] = {0};

	// ゲームループ
	while (true) {
		// 最新のキーボード情報だったものは1フレーム前のキーボード情報として保存
		for (int i = 0; i < 256; i++) {
			oldkeys[i] = keys[i];
		}
		// 最新のキーボード情報を取得
		GetHitKeyStateAll(keys);

		// 画面クリア
		ClearDrawScreen();
		//---------  ここからプログラムを記述  ----------//
		
		// 更新処理
		switch (scene) {
		case 0:
			if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0) {
				scene = 1;
			}
			break;
		case 1:
			if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0) {
				scene = 0;
			}
			if (keys[KEY_INPUT_C] == 1 && oldkeys[KEY_INPUT_C] == 0) {
				if (mirrorAngle == 3) {
					mirrorAngle = 0;
				}
				else {
					mirrorAngle += 1;
				}
			}
			break;
		}
		// 描画処理
		switch (scene) {
		case 0:
			//緑
			DrawLine(300, 0, 300, 400, GetColor(0, 128, 0), 50);
			SetDrawBlendMode(DX_BLENDMODE_ADD, 255);
			DrawLine(300, 0, 300, 400, GetColor(0, 128, 0), 35);
			SetDrawBlendMode(DX_BLENDMODE_ADD, 220);
			DrawLine(300, 0, 300, 400, GetColor(255, 255, 255), 10);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 100);

			//赤
			DrawLine(100, 0, 100, 400, GetColor(128, 0, 0), 50);
			SetDrawBlendMode(DX_BLENDMODE_ADD, 255);
			DrawLine(100, 0, 100, 400, GetColor(128, 0, 0), 35);
			SetDrawBlendMode(DX_BLENDMODE_ADD, 200);
			DrawLine(100, 0, 100, 400, GetColor(255, 255, 255), 10);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 100);

			//青
			DrawLine(500, 0, 500, 400, GetColor(0, 0, 128), 50);
			SetDrawBlendMode(DX_BLENDMODE_ADD, 255);
			DrawLine(500, 0, 500, 400, GetColor(0, 0, 128), 35);
			SetDrawBlendMode(DX_BLENDMODE_ADD, 200);
			DrawLine(500, 0, 500, 400, GetColor(255, 255, 255), 10);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 100);

			//水色
			DrawLine(700, 0, 700, 400, GetColor(0, 128, 128), 50);
			SetDrawBlendMode(DX_BLENDMODE_ADD, 255);
			DrawLine(700, 0, 700, 400, GetColor(0, 128, 128), 35);
			SetDrawBlendMode(DX_BLENDMODE_ADD, 200);
			DrawLine(700, 0, 700, 400, GetColor(255, 255, 255), 10);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 100);


			//白
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, 150);
			DrawLine(900, 0, 900, 400, GetColor(128, 128, 128), 50);
			SetDrawBlendMode(DX_BLENDMODE_ADD, 255);
			DrawLine(900, 0, 900, 400, GetColor(100, 100, 100), 35);
			SetDrawBlendMode(DX_BLENDMODE_ADD, 255);
			DrawLine(900, 0, 900, 400, GetColor(255, 255, 255), 10);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 100);

			//黄色
			DrawLine(1100, 0, 1100, 400, GetColor(128, 128, 0), 50);
			SetDrawBlendMode(DX_BLENDMODE_ADD, 255);
			DrawLine(1100, 0, 1100, 400, GetColor(128, 128, 0), 35);
			SetDrawBlendMode(DX_BLENDMODE_ADD, 200);
			DrawLine(1100, 0, 1100, 400, GetColor(255, 255, 255), 10);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 100);
			break;
		case 1:
			DrawMirror(mirrorX,mirrorY,mirrorR,mirrorT,mirrorAngle);
			break;
		}

		
		//---------  ここまでにプログラムを記述  ---------//
		// (ダブルバッファ)裏面
		ScreenFlip();

		// 20ミリ秒待機(疑似60FPS)
		WaitTimer(20);

		// Windowsシステムからくる情報を処理する
		if (ProcessMessage() == -1) {
			break;
		}

		// ESCキーが押されたらループから抜ける
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) {
			break;
		}
	}
	// Dxライブラリ終了処理
	DxLib_End();

	// 正常終了
	return 0;
}
void DrawMirror(int x, int y, int r, int t,int angle) {
	
	if (angle == 0){
		//三角形1
		DrawTriangle(
			x - r, y - r,
			x - r, y - r + t,
			x + r, y + r,
			GetColor(255, 255, 255),
			true
		);
			//三角形2
			DrawTriangle(
				x - r, y - r + t,
				x + r - t, y + r,
				x + r, y + r,
				GetColor(255, 255, 255),
				true
			);

		//三角形3
		DrawTriangle(
			x - r, y - r + t,
			x - r, y - r + (2 * t),
			x + r - t, y + r,
			GetColor(150, 150, 150),
			true
		);
		//三角形4
		DrawTriangle(
			x - r, y - r + (2 * t),
			x + r - (2 * t), y + r,
			x + r - t, y + r,
			GetColor(150, 150, 150),
			true
		);
	}
	else if (angle == 1) {
		//三角形1
		DrawTriangle(
			x - r, y + r,
			x + r, y - r,
			x - r, y + r-t,
			GetColor(255, 255, 255),
			true
		);
		//三角形2
		DrawTriangle(
			x - r, y + r - t,
			x + r , y - r,
			x + r-t, y - r,
			GetColor(255, 255, 255),
			true
		);

		//三角形3
		DrawTriangle(
			x - r, y + r - t,
			x - r, y + r - (2 * t),
			x + r - t, y - r,
			GetColor(150, 150, 150),
			true
		);
		//三角形4
		DrawTriangle(
			x - r, y + r - (2 * t),
			x + r - (2 * t), y - r,
			x + r - t, y - r,
			GetColor(150, 150, 150),
			true
		);
	}
	else if (angle == 2) {
		//三角形1
		DrawTriangle(
			x - r, y - r,
			x + r, y + r,
			x- r+t, y - r,
			GetColor(255, 255, 255),
			true
		);
		//三角形2
		DrawTriangle(
			x - r+t, y - r,
			x + r , y + r,
			x + r, y + r-t,
			GetColor(255, 255, 255),
			true
		);

		//三角形3
		DrawTriangle(
			x - r+t, y - r ,
			x + r, y + r -t,
			x - r +(2* t), y - r,
			GetColor(150, 150, 150),
			true
		);
		//三角形4
		DrawTriangle(
			x - r+(2*t), y - r,
			x + r , y + r-t,
			x + r, y + r-(2*t),
			GetColor(150, 150, 150),
			true
		);
	}
	else if (angle == 3) {
		//三角形1
		DrawTriangle(
			x - r, y + r,
			x + r, y - r,
			x - r+t, y + r,
			GetColor(255, 255, 255),
			true
		);
		//三角形2
		DrawTriangle(
			x - r+t, y + r,
			x + r, y - r,
			x + r , y - r+t,
			GetColor(255, 255, 255),
			true
		);

		//三角形3
		DrawTriangle(
			x - r + t, y + r,
			x - r+(2*t) , y + r,
			x + r , y - r+t,
			GetColor(150, 150, 150),
			true
		);
		//三角形4
		DrawTriangle(
			x + r, y - r+ (2 * t),
			x - r + (2 * t), y + r,
			x + r, y - r+t,
			GetColor(150, 150, 150),
			true
		);
	}
}