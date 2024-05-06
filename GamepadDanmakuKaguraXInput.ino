/**
 * 東方ダンマクカグラのカグラモード用6ボタンコントローラー
 * 操作タイプA用
 * 
 * for Arduino pro micro
 *
 * ■結線
 * ボタン | ① ② ③ ④ ⑤ ⑥
 * キー　 | ← ↑ → X Y B
 * ピン　 | 3 4 5 7 8 9
 *
 * 2024/05/05 XInputサンプルからコピー作成
 */
#include <XInput.h>

// Directional Pad Pins
const int Pin_DpadLeft  = 6;
const int Pin_DpadUp    = 7;
const int Pin_DpadRight = 8;

// Button Pins
const int Pin_ButtonX = 9;
const int Pin_ButtonY = 10;
const int Pin_ButtonB = 16;

void setup() {
	// Set buttons as inputs, using internal pull-up resistors
	pinMode(Pin_ButtonX, INPUT_PULLUP);
	pinMode(Pin_ButtonY, INPUT_PULLUP);
	pinMode(Pin_ButtonB, INPUT_PULLUP);

	pinMode(Pin_DpadLeft, INPUT_PULLUP);
	pinMode(Pin_DpadUp, INPUT_PULLUP);
	pinMode(Pin_DpadRight, INPUT_PULLUP);

	XInput.setAutoSend(false);  // Wait for all controls before sending

	XInput.begin();
}

void loop() {
	// Read pin values and store in variables
	// (Note the "!" to invert the state, because LOW = pressed)
	boolean buttonX = !digitalRead(Pin_ButtonX);
	boolean buttonY = !digitalRead(Pin_ButtonY);
  boolean buttonB = !digitalRead(Pin_ButtonB);

	boolean dpadLeft  = !digitalRead(Pin_DpadLeft);
	boolean dpadUp    = !digitalRead(Pin_DpadUp);
	boolean dpadRight = !digitalRead(Pin_DpadRight);
  boolean dpadDown = false;

	// Set XInput buttons
	XInput.setButton(BUTTON_X, buttonX);
	XInput.setButton(BUTTON_Y, buttonY);
	XInput.setButton(BUTTON_B, buttonB);

	// Set XInput DPAD values
	XInput.setDpad(dpadUp, dpadDown, dpadLeft, dpadRight);

	// Send control data to the computer
	XInput.send();
}
