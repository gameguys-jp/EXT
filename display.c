#include <stdint.h>
#include <psxgpu.h>
#include <psxgte.h>
#include <psxpad.h>
#include <inline_c.h>
#include <psxsio.h> 
#include "display.h"
#include "input.h"
#include "function.h"
#include <string.h>

#include <assert.h>
#include <stddef.h>
#include "strings.h"


#define BUFFER_LENGTH 8192


#define SIO_SYNC_TIMEOUT	0x100000
#define MAX_LENGTH 100

int noInputTimer = 0;
#define TIMEOUT_FRAMES 3600


// Dual buffer vars
DB db[2];
int db_active = 0;
char *db_nextpri;
RECT screen_clip;

// Lighting
MATRIX color_mtx = {
	ONE, 0, 0, // Red
	ONE,   0, 0, // Green
	ONE, 0, 0  // Blue
};

MATRIX light_mtx = {
	/* X,  Y,  Z */
	0, 0, -2048, 0, 0, 0, 0, 0, 0};

// Geometry vars
int i, p, xy_temp;
int px, py;

int counter = 0;

SVECTOR rot;
VECTOR pos;

SVECTOR verts[17][17];

VECTOR cam_pos;
VECTOR cam_rot;

VECTOR tpos;
SVECTOR trot;
MATRIX mtx, lmtx;

POLY_FT4 *pol4;

PADTYPE *pad;

uint16_t previousPadState = 0xFFFF; // Initialize with all buttons not pressed

// 16進数での文章データ (例: "Hello" と仮定)
uint8_t hexData[] = {0x48, 0x65, 0x6C, 0x6C, 0x6F};
#define HEXDATA_LENGTH sizeof(hexData)/sizeof(hexData[0])

// 格納用の文字列
char convertedStr[MAX_LENGTH];
int dataIndex = 0;
// グローバル変数
char receivedStr[MAX_LENGTH] = {0}; // 受信した文字列を格納する
int receivedIndex = 0; // receivedStrに格納された文字数

const char requestTime = 0xAA; 


int currentStringIndex = 0;

// 擬似乱数ジェネレータの変数
unsigned long int seed = 123456789;

// 線形合同法を使用した擬似乱数ジェネレータ
unsigned long int simple_random(void) {
    seed = (1103515245 * seed + 12345) % 2147483648;
    return seed;
}



void pollInput(void) {

	
	char str[MAX_LENGTH];
    int index = 0;
    int receivedByte;

	char sendStr[] = "Hello, world!";
	char send;
    int sendLength = strlen(sendStr);

	pad = (PADTYPE *) &padBuffer[0][0];
	// Parse controller input

	// Divide out fractions of camera rotation
	trot.vx = cam_rot.vx >> 12;
	trot.vy = cam_rot.vy >> 12;
	trot.vz = cam_rot.vz >> 12;

	

	FntPrint(-1, "X=%d Y=%d Z=%d\n", cam_pos.vx >> 12, cam_pos.vy >> 12,
					 cam_pos.vz >> 12);
	FntPrint(-1, "RX=%d RY=%d\n", cam_rot.vx >> 12, cam_rot.vy >> 12);
	FntPrint(-1, "%d\n", counter);
	
	FntPrint(-1, "%s\n", sendStr);

	FntPrint(-1, "%s\n", stringArray[currentStringIndex]);

	if (pad->stat == 0) {

		// 任意のボタンが新しく押されたかを確認
		uint16_t anyButtonPressed = ~(pad->btn) & previousPadState;

		if (anyButtonPressed) {
			// ここにボタンが押された時の処理を記述
			SIO_WriteByte('X');
			FntPrint(-1, "A button was pressed!");
			noInputTimer = 0; // Reset the timer

			// 擬似乱数ジェネレータを使用してランダムなインデックスを取得
			currentStringIndex = simple_random() % STRING_ARRAY_LENGTH;
			
		}


		// For digital pad, dual-analog and dual-shock
		if ((pad->type == 0x4) || (pad->type == 0x5) || (pad->type == 0x7)) {

			// The button status bits are inverted,
			// so 0 means pressed in this case

			// Look controls
			if (!(pad->btn & PAD_UP)) {

				// Look up
				cam_rot.vx -= ONE * 8;

			} else if (!(pad->btn & PAD_DOWN)) {

				// Look down
				cam_rot.vx += ONE * 8;
			}

			if (!(pad->btn & PAD_LEFT)) {

				// Look left
				cam_rot.vy += ONE * 8;

			} else if (!(pad->btn & PAD_RIGHT)) {

				// Look right
				cam_rot.vy -= ONE * 8;
			}

			// Movement controls
			if (!(pad->btn & PAD_TRIANGLE)) {

				// Move forward
				cam_pos.vx -= ((isin(trot.vy) * icos(trot.vx)) >> 12) << 2;
				cam_pos.vy += isin(trot.vx) << 2;
				cam_pos.vz += ((icos(trot.vy) * icos(trot.vx)) >> 12) << 2;

			} else if (!(pad->btn & PAD_CROSS)) {

				// Move backward
				cam_pos.vx += ((isin(trot.vy) * icos(trot.vx)) >> 12) << 2;
				cam_pos.vy -= isin(trot.vx) << 2;
				cam_pos.vz -= ((icos(trot.vy) * icos(trot.vx)) >> 12) << 2;
			}

			if (!(pad->btn & PAD_SQUARE)) {

				// Slide left
				cam_pos.vx -= icos(trot.vy) << 2;
				cam_pos.vz -= isin(trot.vy) << 2;

			} else if (!(pad->btn & PAD_CIRCLE)) {

				// Slide right
				cam_pos.vx += icos(trot.vy) << 2;
				cam_pos.vz += isin(trot.vy) << 2;
			}

			if (!(pad->btn & PAD_R1)) {

				// Slide up
				cam_pos.vx -= ((isin(trot.vy) * isin(trot.vx)) >> 12) << 2;
				cam_pos.vy -= icos(trot.vx) << 2;
				cam_pos.vz += ((icos(trot.vy) * isin(trot.vx)) >> 12) << 2;
			}


			if (!(pad->btn & PAD_R2)) {

				// Slide down
				cam_pos.vx += ((isin(trot.vy) * isin(trot.vx)) >> 12) << 2;
				cam_pos.vy += icos(trot.vx) << 2;
				cam_pos.vz -= ((icos(trot.vy) * isin(trot.vx)) >> 12) << 2;
			}


			if (!(pad->btn & PAD_L1)) {

				counter++;

				int red = (sin_lookup(counter)+127)/2;

				setRGB0(&db[0].draw, red, 0, 127);
				setRGB0(&db[1].draw, red, 0, 127);
/*
				//ESP32からデータを受信。受信できないときは-1を返す
				while ((receivedByte = SIO_ReadByte()) != -1) {
					FntPrint(-1, "data=	 %c", receivedByte);

				}
*/



			}


			if (!(pad->btn & PAD_L2)) {

				SIO_WriteByte(0x78);  // ESP32に0xAAを送信
				FntPrint(-1, "\nsend: %c\n", 0x78);

				/*
				SIO_WriteByte(0xAA);  // ESP32に0xAAを送信

				while ((receivedByte = SIO_ReadByte()) != -1 && receivedIndex < MAX_LENGTH - 1) {
					receivedStr[receivedIndex++] = (char)receivedByte;

					if (receivedByte == '\x7F') {
						// あまり使われない字が受信された場合、何もしない
						continue;
					}
					if (receivedByte == '\n') {
						break;
					}
				}
				receivedStr[receivedIndex] = '\0';  // 文字列を終了させる
				FntPrint(-1, "Received time: %s", receivedStr); // 受信したデータを表示する（この場合は'hello'のはず）
				*/
			}

		

			// PAD_CROSSが押された場合の処理
			if (!(pad->btn & PAD_CROSS) && (previousPadState & PAD_CROSS)) {
				// HEXデータから文字を読み込み、convertedStrに変換して追加
				if(dataIndex < HEXDATA_LENGTH) {
					convertedStr[dataIndex] = hexData[dataIndex];
					convertedStr[dataIndex + 1] = '\0'; // 文字列を終了させる
					dataIndex++;
				}
				FntPrint(-1, "Converted string: %s", convertedStr);
			}

			// Example for detecting a single press of the PAD_CROSS button
			if (!(pad->btn & PAD_CIRCLE) && (previousPadState & PAD_CIRCLE)) {
				// The button was just pressed this frame, so do something here
				FntPrint(-1, "PAD_CROSS was just pressed!");
			}

			FntPrint(-1, "\n! %s\n", convertedStr);


			// At the end of the pollInput function, save the current state
			previousPadState = pad->btn;





		}

		// For dual-analog and dual-shock (analog input)
		if ((pad->type == 0x5) || (pad->type == 0x7)) {

			// Moving forwards and backwards
			if (((pad->ls_y - 128) < -16) || ((pad->ls_y - 128) > 16)) {

				cam_pos.vx +=
						(((isin(trot.vy) * icos(trot.vx)) >> 12) * (pad->ls_y - 128)) >> 5;
				cam_pos.vy -= (isin(trot.vx) * (pad->ls_y - 128)) >> 5;
				cam_pos.vz -=
						(((icos(trot.vy) * icos(trot.vx)) >> 12) * (pad->ls_y - 128)) >> 5;
			}

			// Strafing left and right
			if (((pad->ls_x - 128) < -16) || ((pad->ls_x - 128) > 16)) {
				cam_pos.vx += (icos(trot.vy) * (pad->ls_x - 128)) >> 5;
				cam_pos.vz += (isin(trot.vy) * (pad->ls_x - 128)) >> 5;
			}

			// Look up and down
			if (((pad->rs_y - 128) < -16) || ((pad->rs_y - 128) > 16)) {
				cam_rot.vx += (pad->rs_y - 128) << 9;
			}

			// Look left and right
			if (((pad->rs_x - 128) < -16) || ((pad->rs_x - 128) > 16)) {
				cam_rot.vy -= (pad->rs_x - 128) << 9;
			}
		}



	}

		// Increment the no input timer
		noInputTimer++;

		// Check if we reached the timeout without any input
		if (noInputTimer >= TIMEOUT_FRAMES) {
			// Rotate the camera (or any other desired action)
			cam_rot.vy += ONE * 8;  // This will rotate the camera to the left. Adjust as needed.
		}
}

void initDisplay(void) {
	ResetGraph(0);

	// DB 1
	SetDefDispEnv(&db[0].disp, 0, 0, SCREEN_XRES, SCREEN_YRES);
	SetDefDrawEnv(&db[0].draw, 0, SCREEN_YRES, SCREEN_XRES, SCREEN_YRES);

	setRGB0(&db[0].draw, 63, 127, 0);
	db[0].draw.isbg = 1;
	db[0].draw.dtd = 1;

	// DB 2
	SetDefDispEnv(&db[1].disp, 0, SCREEN_YRES, SCREEN_XRES, SCREEN_YRES);
	SetDefDrawEnv(&db[1].draw, 0, 0, SCREEN_XRES, SCREEN_YRES);

	setRGB0(&db[1].draw, 63, 127, 0);
	db[1].draw.isbg = 1;
	db[1].draw.dtd = 1;

	setRECT(&screen_clip, 0, 0, SCREEN_XRES, SCREEN_YRES);

	InitGeom();

	gte_SetGeomOffset(CENTERX, CENTERY);

	gte_SetGeomScreen(CENTERX);

	gte_SetBackColor(127, 63, 63);
	gte_SetColorMatrix(&color_mtx);

	setVector(&cam_pos, 0, ONE * -100, 0);
	setVector(&cam_rot, 0, 0, 0);

#ifdef LOAD_FONT
	FntLoad(960, 0);
	FntOpen(0, 8, 320, 216, 0, 1000);
#endif

	initInput();

	db_active = 0;
	db_nextpri = db[0].p;

	ClearOTagR(db[db_active].ot, OT_LEN);
	PutDrawEnv(&(db[0].draw));
	SetDispMask(1);
}

void display(void) {
	DrawSync(0);
	VSync(0);

	db_active ^= 1;
	db_nextpri = db[db_active].p;

	ClearOTagR(db[db_active].ot, OT_LEN);
	PutDrawEnv(&(db[db_active].draw));
	PutDispEnv(&(db[db_active].disp));

	DrawOTag(db[db_active ^ 1].ot + (OT_LEN - 1));
}

void begin(void) {
	RotMatrix(&trot, &mtx);

	tpos.vx = -cam_pos.vx >> 12;
	tpos.vy = -cam_pos.vy >> 12;
	tpos.vz = -cam_pos.vz >> 12;

	ApplyMatrixLV(&mtx, &tpos, &tpos);
	TransMatrix(&mtx, &tpos);

	gte_SetRotMatrix(&mtx);
	gte_SetTransMatrix(&mtx);
}

void end(void) {
	FntFlush(-1);
	display();
	pollInput();
}

#ifdef DEBUG_VERTEX_ORDER
typedef POLY_GT4 QUAD;
#else
typedef POLY_FT4 QUAD;
#endif

void sortObject(OBJECT *obj) {
	int i, p;
	QUAD *pol4;

	MATRIX omtx, lmtx;

	RotMatrix(&obj->rot, &omtx);
	TransMatrix(&omtx, &obj->pos);

	MulMatrix0(&light_mtx, &omtx, &lmtx);

	//gte_SetLightMatrix(&lmtx);

	CompMatrixLV(&mtx, &omtx, &omtx);

	PushMatrix();

	gte_SetRotMatrix(&omtx);
	gte_SetTransMatrix(&omtx);

	pol4 = (QUAD *)db_nextpri;

	for (i = 0; i < obj->faces_num; i++) {

		gte_ldv3(&obj->vertex_data[obj->vertex_indices[i].v0],
						 &obj->vertex_data[obj->vertex_indices[i].v1],
						 &obj->vertex_data[obj->vertex_indices[i].v2]);

		gte_rtpt();
		gte_nclip();
		gte_stopz(&p);

		// Skip drawing this quad if the first 3 vertices are aligned (p = 0)
		// or in counterclockwise (p < 0) order.
		if (p <= 0)
			continue;

		gte_avsz3();
		gte_stotz(&p);

		// Skip drawing this face if it's too far from or too close to the
		// camera and wouldn't fit in the OT.
		if (((p >> 2) <= 0) || ((p >> 2) >= OT_LEN))
			continue;

#ifdef DEBUG_VERTEX_ORDER
		setPolyGT4(pol4);
		setRGB1(pol4, 255, 0, 0); // Red   = second vertex
		setRGB2(pol4, 0, 255, 0); // Green = third vertex
		setRGB3(pol4, 0, 0, 255); // Blue  = fourth vertex
#else
		setPolyFT4(pol4);
#endif

		gte_stsxy0(&pol4->x0);
		gte_stsxy1(&pol4->x1);
		gte_stsxy2(&pol4->x2);

		gte_ldv0(&obj->vertex_data[obj->vertex_indices[i].v3]);
		gte_rtps();
		gte_stsxy(&pol4->x3);

		gte_ldrgb(&pol4->r0);
		gte_ldv0(&obj->normal_data[obj->normal_indices[i]]);
		gte_ncs();
		gte_strgb(&pol4->r0);

		pol4->tpage =
				getTPage(obj->tim.mode, 0, obj->tim.prect->x, obj->tim.prect->y);
		setClut(pol4, obj->tim.crect->x, obj->tim.crect->y);
		setUV4(pol4,
					obj->uv_data[obj->uv_indices[i].v0].vx, obj->texture_size-1-obj->uv_data[obj->uv_indices[i].v0].vy,
					obj->uv_data[obj->uv_indices[i].v1].vx, obj->texture_size-1-obj->uv_data[obj->uv_indices[i].v1].vy,
					obj->uv_data[obj->uv_indices[i].v2].vx, obj->texture_size-1-obj->uv_data[obj->uv_indices[i].v2].vy,
					obj->uv_data[obj->uv_indices[i].v3].vx, obj->texture_size-1-obj->uv_data[obj->uv_indices[i].v3].vy);
		setRGB0( pol4, obj->brighness, obj->brighness, obj->brighness );
		gte_avsz4();
		gte_stotz(&p);
		addPrim(&(db[db_active].ot)[p >> 2], pol4);

		pol4++;
		//if (pol4 >= (db_nextpri + PACKET_LEN))
			//break;
	}

	db_nextpri = (char *)pol4;
	PopMatrix();
}
