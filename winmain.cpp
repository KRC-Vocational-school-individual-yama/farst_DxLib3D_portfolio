
#include "DxLib.h"
#include <string>
#include<assert.h>

int model = -1;
int hue[5] = {};
class Seed {
public:
	int  img = -1;
	int  anim = 0;
	int  time = 0;
	int  count = 0;
	float x = 0;
	float y = 0;
	float z = 0;
	int d = 0;
	Seed() {
		x = 500;
		y = 0;
		z = 800;
	}
	void hitkeya();
};

class Camera {
public:
	float x = 0;
	float y = 0;
	float z = 0;
	float d = 0;
	float vartical = 0;
	float horizontal=0;
	float twist = 0;
	Camera() {
		x = 0.0f;
		y = 0.0f;
		z = 0.0f;
		d = 0.0f;
		vartical=0.0f;
		horizontal=0.0f;
		twist=0.0f;
	}
	void hitkey();
};
Seed iti;
Seed animemodel;
Camera one;

//最初に1回呼ばれる処理
void Init()
{
	
	animemodel.img = MV1LoadModel("a/DxChara.x");

	// ３Ｄモデルの読み込み
	model = MV1LoadModel("cottage_fbx.mv1");
	hue[0] = MV1DuplicateModel(model);
	hue[1] = MV1DuplicateModel(model);
	hue[2] = MV1DuplicateModel(model);
	assert(model > 0);


	MV1SetPosition(animemodel.img, VGet(320.0f+animemodel.x, -300.0f+animemodel.y, 600.0f+animemodel.z));
	animemodel.anim = MV1AttachAnim(animemodel.img, 0, -1, FALSE);
	animemodel.time = MV1GetAttachAnimTotalTime(animemodel.img, animemodel.anim);
	animemodel.count = 0;

	MV1SetScale(model, VGet(0.25, 0.25, 0.25));
}
void Camera::hitkey() {
	if (CheckHitKey(KEY_INPUT_W)) {
		one.z += 5 + one.d;
		/*if (one.horizontal >= 0.38 && one.horizontal <= 1.15) {
			one.z += 5 + one.d;
			one.x += 5 + one.d;
		}
		else if (one.horizontal>= 1.15&&one.horizontal<= 1.92) {
			one.x += 5 + one.d;
		}
		else if (one.horizontal>= 1.92 &&one.horizontal<= 2.69) {
			one.x += 5 + one.d;
			one.z -= 5 + one.d;
		}
		else if (one.horizontal >= 2.69 && one.horizontal <= 3.46) {
			one.z -= 5 + one.d;
		}
		else if (one.horizontal >= 3.46 && one.horizontal <= 4.23) {
			one.z -= 5 + one.d;
			one.x -= 5 + one.d;
		}
		else if (one.horizontal>= 4.23 &&one.horizontal<= 5) {
			one.x -= 5 + one.d;
		}
		else if (one.horizontal >= 5 && one.horizontal <= 5.77) {
			one.x -= 5 + one.d;
			one.z += 5 + one.d;
		}
		else if (one.horizontal>= 5.77 &&one.horizontal<=5.82) {
			one.x -= 5 + one.d;
			one.z += 5 + one.d;
		}
		else {
			one.z += 5 + one.d;

		}*/
	}
	if (CheckHitKey(KEY_INPUT_S)) {
		one.z -= 5 + one.d;
	}
	if (CheckHitKey(KEY_INPUT_A)) {
		one.x -= 5 + one.d;
	}
	if (CheckHitKey(KEY_INPUT_D)) {
		one.x += 5 + one.d;
		/*if (one.horizontal >= 0.38 && one.horizontal <= 1.15) {
			one.z -= 5 + one.d;
			one.x += 5 + one.d;
		}
		else if (one.horizontal>= 1.15&&one.horizontal<= 1.92) {
			one.z -= 5 + one.d;
		}
		else if (one.horizontal>= 1.92 &&one.horizontal<= 2.69) {
			one.x-= 5 + one.d;
			one.z -= 5 + one.d;
		}
		else if (one.horizontal >= 2.69 && one.horizontal <= 3.46) {
			one.x -= 5 + one.d;
		}
		else if (one.horizontal >= 3.46 && one.horizontal <= 4.23) {
			one.z += 5 + one.d;
			one.x -= 5 + one.d;
		}
		else if (one.horizontal>= 4.23 &&one.horizontal<= 5) {
			one.z += 5 + one.d;
		}
		else if (one.horizontal >= 5 && one.horizontal <= 5.77) {
			one.x += 5 + one.d;
			one.z += 5 + one.d;
		}
		else if (one.horizontal>= 5.77 &&one.horizontal<=5.82) {
			one.x+= 5 + one.d;
			one.z += 5 + one.d;
		}
		else {
			one.x += 5 + one.d;

		}*/
	}
	if (CheckHitKey(KEY_INPUT_SPACE) && CheckHitKey(KEY_INPUT_LSHIFT) == 0) {
		one.y += 5 + one.d;
	}
	if (CheckHitKey(KEY_INPUT_SPACE) && CheckHitKey(KEY_INPUT_LSHIFT) == 1) {
		one.y -= 5 + one.d;
	}
	if (CheckHitKey(KEY_INPUT_LSHIFT)) {
		one.d = 5;
	}
	else {
		one.d = 0;
	}



	if (CheckHitKey(KEY_INPUT_LALT)) {
		if (CheckHitKey(KEY_INPUT_LEFT)) {
			one.twist -= 0.1;
			if (one.twist <= -6.2) {
				one.twist = 0;
			}
		}
		if (CheckHitKey(KEY_INPUT_RIGHT)) {
			one.twist += 0.1;
			if (one.twist >= 6.2) {
				one.twist = 0;
			}
		}
	}
	else {

		if (CheckHitKey(KEY_INPUT_UP)) {
			one.vartical -= 0.1  ;
			if (one.vartical <= -1.55) {
				one.vartical = -1.55;
			}
			/*if (one.vartical <= -6.2) {
				one.vartical = 0;
			}*/
		}
		if (CheckHitKey(KEY_INPUT_DOWN)) {
			one.vartical += 0.1  ;
			if (one.vartical >= 1.55) {
				one.vartical = 1.55;
			}
			/*if (one.vartical >= 6.2) {
				one.vartical = 0;
			}*/
		}
		if (CheckHitKey(KEY_INPUT_LEFT)) {
			one.horizontal -=0.1  ;
			if (one.horizontal <= -6.2) {
				one.horizontal = 0.f;
			}
		}
		if (CheckHitKey(KEY_INPUT_RIGHT)) {
			one.horizontal += 0.1  ;
			if (one.horizontal >= 6.2) {
				one.horizontal = 0.f;
			}
		}
	}
	if (CheckHitKey(KEY_INPUT_F)) {
		one.x=0;
		one.y=0;
		one.z=0;
		one.horizontal=0;
		one.vartical=0;
		one.twist=0;
	}
}
void Seed::hitkeya() {
	if (CheckHitKey(KEY_INPUT_NUMPAD8)) {
		iti.z += 5+iti.d;
	}
	if (CheckHitKey(KEY_INPUT_NUMPAD5)) {
		iti.z -= 5 + iti.d;
	}
	if (CheckHitKey(KEY_INPUT_NUMPAD4)) {
		iti.x -= 5 + iti.d;
	}
	if (CheckHitKey(KEY_INPUT_NUMPAD6)) {
		iti.x += 5 + iti.d;
	}
	if (CheckHitKey(KEY_INPUT_NUMPAD0)/* && CheckHitKey(KEY_INPUT_LSHIFT) == 0*/) {
		iti.y += 5 + iti.d;
	}
	if (CheckHitKey(KEY_INPUT_NUMPAD1)/* && CheckHitKey(KEY_INPUT_LSHIFT) == 1*/) {
		iti.y -= 5 + iti.d;
	}
	if (CheckHitKey(KEY_INPUT_LSHIFT)) {
		iti.d = 5;
	}
	else {
		iti.d = 0;
	}
}
//毎フレーム呼ばれる処理

void Update()
{
	one.hitkey();
	iti.hitkeya();
	animemodel.hitkeya();

	animemodel.count+=100;
	if (animemodel.count >= animemodel.time)
	{
		animemodel.z -= 525;
		animemodel.count = 0.0f;
		
	}
	MV1SetAttachAnimTime(animemodel.img, animemodel.anim, animemodel.count);



	SetCameraPositionAndAngle(VGet(one.x, one.y, one.z), one.vartical, one.horizontal, one.twist);

	MV1SetLoadModelUsePhysicsMode(DX_LOADMODEL_PHYSICS_REALTIME);
	
	MV1SetPosition(model, VGet(iti.x + 500, iti.y + 0, iti.z + 0));
	

	for (int i = 0; i < 5; i++) {

		MV1SetPosition(hue[i], VGet(500 - i * 200, 0,2000));
		MV1SetScale(hue[i], VGet(0.25, 0.25, 0.25));
	}


}
void Draw()
{
	for (int i = 0; i < 12; i++) {
		DrawLine3D(VGet(100 + i * 100, 0, 0), VGet(100 + i * 100, 0, 1000), GetColor(100, 100, 100));
		DrawLine3D(VGet(0, 0, 100 + i * 100), VGet(0, 1000, 100 + i * 100), GetColor(100, 100, 100));
		DrawLine3D(VGet(0, 0, 100 + i * 100), VGet(1000, 0, 100 + i * 100), GetColor(100, 100, 100));
	}
	DrawLine3D(VGet(0 , 0, 0), VGet(0 , 0, 1000), GetColor(255,255,255));
	DrawLine3D(VGet(0, 0, 0 ), VGet(0, 1000, 0 ), GetColor(255,255,255));
	DrawLine3D(VGet(0, 0, 0 ), VGet(1000, 0, 0), GetColor(255,255,255));
	
	MV1DrawModel(model);

	MV1DrawModel(animemodel.img);
	MV1SetPosition(animemodel.img, VGet(320.0f + animemodel.x, -300.0f + animemodel.y, 600.0f + animemodel.z));

	for (int i = 0; i < 5; i++) {
		MV1DrawModel(hue[i]);
	}

	DrawFormatString(0,0,GetColor(255,255,255),
		"horizontal:%f\nvartical:%f\ntwist:%f\n",
		one.horizontal,one.vartical,one.twist);
	DrawFormatString(0,100,GetColor(0x7f,0xff,0xb4),
		"X:%f\nY:%f\nZ:%f\n",one.x,one.y,one.z);
	DrawFormatString(0,200,GetColor(0x7f,0xff,0xb4),"animemodel\nZ:%f\ncount:%d\n",animemodel.z,animemodel.count);
}

void Delete()
{
	MV1DeleteModel(model);
	MV1DeleteModel(animemodel.img);
	for (int i = 0; i < 5; i++) {
		MV1DeleteModel(hue[i]);
	}
}
// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	
	
	SetOutApplicationLogValidFlag(false);
	ChangeWindowMode(TRUE);	//ウィンドウモードにする
	SetGraphMode(800, 600, 32);	//ウィンドウサイズを設定する
	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}
	SetDrawScreen(DX_SCREEN_BACK);	//裏画面を描画対象へ

	Init();//初期化
	//メイン処理
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0) {
		Update();//更新処理
		Draw();//描画処理

		ScreenFlip();		//裏画面と表画面の入替
		ClearDrawScreen();	//裏画面の描画を全て消去
	}
	Delete();
	DxLib_End();			// ＤＸライブラリ使用の終了処理
	return 0;				// ソフトの終了 
}