#include "DxLib.h"

void DrawMirror(int x, int y, int r, int t, int angle);
// �E�B���h�E�̃^�C�g���ɕ\�����镶����
const char TITLE[] = "LC1B_31_���^�i�x���C�L: �K�����[�U�[";

// �E�B���h�E����
const int WIN_WIDTH = 1200;

// �E�B���h�E�c��
const int WIN_HEIGHT = 400;

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine,
                   _In_ int nCmdShow) {
	// �E�B���h�E���[�h�ɐݒ�
	ChangeWindowMode(TRUE);

	// �E�B���h�E�T�C�Y���蓮�ł͕ύX�������A
	// ���E�B���h�E�T�C�Y�ɍ��킹�Ċg��ł��Ȃ��悤�ɂ���
	SetWindowSizeChangeEnableFlag(FALSE, FALSE);

	// �^�C�g����ύX
	SetMainWindowText(TITLE);

	// ��ʃT�C�Y�̍ő�T�C�Y�A�J���[�r�b�g����ݒ�(���j�^�[�̉𑜓x�ɍ��킹��)
	SetGraphMode(WIN_WIDTH, WIN_HEIGHT, 32);

	// ��ʃT�C�Y��ݒ�(�𑜓x�Ƃ̔䗦�Őݒ�)
	SetWindowSizeExtendRate(1.0);

	// ��ʂ̔w�i�F��ݒ肷��
	SetBackgroundColor(0x00, 0x00, 0x00);

	// DXlib�̏�����
	if (DxLib_Init() == -1) { return -1; }

	// (�_�u���o�b�t�@)�`���O���t�B�b�N�̈�͗��ʂ��w��
	SetDrawScreen(DX_SCREEN_BACK);

	// �摜�Ȃǂ̃��\�[�X�f�[�^�̕ϐ��錾�Ɠǂݍ���


	// �Q�[�����[�v�Ŏg���ϐ��̐錾
	int scene = 0;
	int mirrorX = 640;
	int mirrorY = 256;
	int mirrorR = 32;
	int mirrorT = 10;
	int mirrorAngle = 0;
	// �ŐV�̃L�[�{�[�h���p
	char keys[256] = {0};

	// 1���[�v(�t���[��)�O�̃L�[�{�[�h���
	char oldkeys[256] = {0};

	// �Q�[�����[�v
	while (true) {
		// �ŐV�̃L�[�{�[�h��񂾂������̂�1�t���[���O�̃L�[�{�[�h���Ƃ��ĕۑ�
		for (int i = 0; i < 256; i++) {
			oldkeys[i] = keys[i];
		}
		// �ŐV�̃L�[�{�[�h�����擾
		GetHitKeyStateAll(keys);

		// ��ʃN���A
		ClearDrawScreen();
		//---------  ��������v���O�������L�q  ----------//
		
		// �X�V����
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
		// �`�揈��
		switch (scene) {
		case 0:
			//��
			DrawLine(300, 0, 300, 400, GetColor(0, 128, 0), 50);
			SetDrawBlendMode(DX_BLENDMODE_ADD, 255);
			DrawLine(300, 0, 300, 400, GetColor(0, 128, 0), 35);
			SetDrawBlendMode(DX_BLENDMODE_ADD, 220);
			DrawLine(300, 0, 300, 400, GetColor(255, 255, 255), 10);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 100);

			//��
			DrawLine(100, 0, 100, 400, GetColor(128, 0, 0), 50);
			SetDrawBlendMode(DX_BLENDMODE_ADD, 255);
			DrawLine(100, 0, 100, 400, GetColor(128, 0, 0), 35);
			SetDrawBlendMode(DX_BLENDMODE_ADD, 200);
			DrawLine(100, 0, 100, 400, GetColor(255, 255, 255), 10);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 100);

			//��
			DrawLine(500, 0, 500, 400, GetColor(0, 0, 128), 50);
			SetDrawBlendMode(DX_BLENDMODE_ADD, 255);
			DrawLine(500, 0, 500, 400, GetColor(0, 0, 128), 35);
			SetDrawBlendMode(DX_BLENDMODE_ADD, 200);
			DrawLine(500, 0, 500, 400, GetColor(255, 255, 255), 10);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 100);

			//���F
			DrawLine(700, 0, 700, 400, GetColor(0, 128, 128), 50);
			SetDrawBlendMode(DX_BLENDMODE_ADD, 255);
			DrawLine(700, 0, 700, 400, GetColor(0, 128, 128), 35);
			SetDrawBlendMode(DX_BLENDMODE_ADD, 200);
			DrawLine(700, 0, 700, 400, GetColor(255, 255, 255), 10);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 100);


			//��
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, 150);
			DrawLine(900, 0, 900, 400, GetColor(128, 128, 128), 50);
			SetDrawBlendMode(DX_BLENDMODE_ADD, 255);
			DrawLine(900, 0, 900, 400, GetColor(100, 100, 100), 35);
			SetDrawBlendMode(DX_BLENDMODE_ADD, 255);
			DrawLine(900, 0, 900, 400, GetColor(255, 255, 255), 10);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 100);

			//���F
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

		
		//---------  �����܂łɃv���O�������L�q  ---------//
		// (�_�u���o�b�t�@)����
		ScreenFlip();

		// 20�~���b�ҋ@(�^��60FPS)
		WaitTimer(20);

		// Windows�V�X�e�����炭�������������
		if (ProcessMessage() == -1) {
			break;
		}

		// ESC�L�[�������ꂽ�烋�[�v���甲����
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) {
			break;
		}
	}
	// Dx���C�u�����I������
	DxLib_End();

	// ����I��
	return 0;
}
void DrawMirror(int x, int y, int r, int t,int angle) {
	
	if (angle == 0){
		//�O�p�`1
		DrawTriangle(
			x - r, y - r,
			x - r, y - r + t,
			x + r, y + r,
			GetColor(255, 255, 255),
			true
		);
			//�O�p�`2
			DrawTriangle(
				x - r, y - r + t,
				x + r - t, y + r,
				x + r, y + r,
				GetColor(255, 255, 255),
				true
			);

		//�O�p�`3
		DrawTriangle(
			x - r, y - r + t,
			x - r, y - r + (2 * t),
			x + r - t, y + r,
			GetColor(150, 150, 150),
			true
		);
		//�O�p�`4
		DrawTriangle(
			x - r, y - r + (2 * t),
			x + r - (2 * t), y + r,
			x + r - t, y + r,
			GetColor(150, 150, 150),
			true
		);
	}
	else if (angle == 1) {
		//�O�p�`1
		DrawTriangle(
			x - r, y + r,
			x + r, y - r,
			x - r, y + r-t,
			GetColor(255, 255, 255),
			true
		);
		//�O�p�`2
		DrawTriangle(
			x - r, y + r - t,
			x + r , y - r,
			x + r-t, y - r,
			GetColor(255, 255, 255),
			true
		);

		//�O�p�`3
		DrawTriangle(
			x - r, y + r - t,
			x - r, y + r - (2 * t),
			x + r - t, y - r,
			GetColor(150, 150, 150),
			true
		);
		//�O�p�`4
		DrawTriangle(
			x - r, y + r - (2 * t),
			x + r - (2 * t), y - r,
			x + r - t, y - r,
			GetColor(150, 150, 150),
			true
		);
	}
	else if (angle == 2) {
		//�O�p�`1
		DrawTriangle(
			x - r, y - r,
			x + r, y + r,
			x- r+t, y - r,
			GetColor(255, 255, 255),
			true
		);
		//�O�p�`2
		DrawTriangle(
			x - r+t, y - r,
			x + r , y + r,
			x + r, y + r-t,
			GetColor(255, 255, 255),
			true
		);

		//�O�p�`3
		DrawTriangle(
			x - r+t, y - r ,
			x + r, y + r -t,
			x - r +(2* t), y - r,
			GetColor(150, 150, 150),
			true
		);
		//�O�p�`4
		DrawTriangle(
			x - r+(2*t), y - r,
			x + r , y + r-t,
			x + r, y + r-(2*t),
			GetColor(150, 150, 150),
			true
		);
	}
	else if (angle == 3) {
		//�O�p�`1
		DrawTriangle(
			x - r, y + r,
			x + r, y - r,
			x - r+t, y + r,
			GetColor(255, 255, 255),
			true
		);
		//�O�p�`2
		DrawTriangle(
			x - r+t, y + r,
			x + r, y - r,
			x + r , y - r+t,
			GetColor(255, 255, 255),
			true
		);

		//�O�p�`3
		DrawTriangle(
			x - r + t, y + r,
			x - r+(2*t) , y + r,
			x + r , y - r+t,
			GetColor(150, 150, 150),
			true
		);
		//�O�p�`4
		DrawTriangle(
			x + r, y - r+ (2 * t),
			x - r + (2 * t), y + r,
			x + r, y - r+t,
			GetColor(150, 150, 150),
			true
		);
	}
}