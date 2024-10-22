#ifndef INPUT_CODES_H
#define INPUT_CODES_H

#include <GLFW/glfw3.h>

namespace brayjl {
	enum class Key {
		UNKNOWN						= GLFW_KEY_UNKNOWN,
		SPACE						= GLFW_KEY_SPACE,
		APOSTROPHE					= GLFW_KEY_APOSTROPHE,
		COMMA						= GLFW_KEY_COMMA,
		MINUS						= GLFW_KEY_MINUS,
		PERIOD						= GLFW_KEY_PERIOD,
		SLASH						= GLFW_KEY_SLASH,
		ZERO						= GLFW_KEY_0,
		ONE							= GLFW_KEY_1,
		TWO							= GLFW_KEY_2,
		THREE						= GLFW_KEY_3,
		FOUR						= GLFW_KEY_4,
		FIVE						= GLFW_KEY_5,
		SIX							= GLFW_KEY_6,
		SEVEN						= GLFW_KEY_7,
		EIGHT						= GLFW_KEY_8,
		NINE						= GLFW_KEY_9,
		SEMICOLON					= GLFW_KEY_SEMICOLON,
		EQUAL						= GLFW_KEY_EQUAL,
		A							= GLFW_KEY_A,
		B							= GLFW_KEY_B,
		C							= GLFW_KEY_C,
		D							= GLFW_KEY_D,
		E							= GLFW_KEY_E,
		F							= GLFW_KEY_F,
		G							= GLFW_KEY_G,
		H							= GLFW_KEY_H,
		I							= GLFW_KEY_I,
		J							= GLFW_KEY_J,
		K							= GLFW_KEY_K,
		L							= GLFW_KEY_L,
		M							= GLFW_KEY_M,
		N							= GLFW_KEY_N,
		O							= GLFW_KEY_O,
		P							= GLFW_KEY_P,
		Q							= GLFW_KEY_Q,
		R							= GLFW_KEY_R,
		S							= GLFW_KEY_S,
		T							= GLFW_KEY_T,
		U							= GLFW_KEY_U,
		V							= GLFW_KEY_V,
		W							= GLFW_KEY_W,
		X							= GLFW_KEY_X,
		Y							= GLFW_KEY_Y,
		Z							= GLFW_KEY_Z,
		LEFT_BRACKET				= GLFW_KEY_LEFT_BRACKET,
		BACKSLASH					= GLFW_KEY_BACKSLASH,
		RIGHT_BRACKET				= GLFW_KEY_RIGHT_BRACKET,
		GRAVE_ACCENT				= GLFW_KEY_GRAVE_ACCENT,
		WORLD_1						= GLFW_KEY_WORLD_1,
		WORLD_2						= GLFW_KEY_WORLD_2,
		ESCAPE						= GLFW_KEY_ESCAPE,
		ENTER						= GLFW_KEY_ENTER,
		TAB							= GLFW_KEY_TAB,
		BACKSPACE					= GLFW_KEY_BACKSPACE,
		INSERT						= GLFW_KEY_INSERT,
		DEL							= GLFW_KEY_DELETE,
		RIGHT						= GLFW_KEY_RIGHT,
		LEFT						= GLFW_KEY_LEFT,
		DOWN						= GLFW_KEY_DOWN,
		UP							= GLFW_KEY_UP,
		PAGE_UP						= GLFW_KEY_PAGE_UP,
		PAGE_DOWN					= GLFW_KEY_PAGE_DOWN,
		HOME						= GLFW_KEY_HOME,
		END							= GLFW_KEY_END,
		CAPS_LOCK					= GLFW_KEY_CAPS_LOCK,
		SCROLL_LOCK					= GLFW_KEY_SCROLL_LOCK,
		NUM_LOCK					= GLFW_KEY_NUM_LOCK,
		PRINT_SCREEN				= GLFW_KEY_PRINT_SCREEN,
		PAUSE						= GLFW_KEY_PAUSE,
		F1							= GLFW_KEY_F1,
		F2							= GLFW_KEY_F2,
		F3							= GLFW_KEY_F3,
		F4							= GLFW_KEY_F4,
		F5							= GLFW_KEY_F5,
		F6							= GLFW_KEY_F6,
		F7							= GLFW_KEY_F7,
		F8							= GLFW_KEY_F8,
		F9							= GLFW_KEY_F9,
		F10							= GLFW_KEY_F10,
		F11							= GLFW_KEY_F11,
		F12							= GLFW_KEY_F12,
		F13							= GLFW_KEY_F13,
		F14							= GLFW_KEY_F14,
		F15							= GLFW_KEY_F15,
		F16							= GLFW_KEY_F16,
		F17							= GLFW_KEY_F17,
		F18							= GLFW_KEY_F18,
		F19							= GLFW_KEY_F19,
		F20							= GLFW_KEY_F20,
		F21							= GLFW_KEY_F21,
		F22							= GLFW_KEY_F22,
		F23							= GLFW_KEY_F23,
		F24							= GLFW_KEY_F24,
		F25							= GLFW_KEY_F25,
		KP_0						= GLFW_KEY_KP_0,
		KP_1						= GLFW_KEY_KP_1,
		KP_2						= GLFW_KEY_KP_2,
		KP_3						= GLFW_KEY_KP_3,
		KP_4						= GLFW_KEY_KP_4,
		KP_5						= GLFW_KEY_KP_5,
		KP_6						= GLFW_KEY_KP_6,
		KP_7						= GLFW_KEY_KP_7,
		KP_8						= GLFW_KEY_KP_8,
		KP_9						= GLFW_KEY_KP_9,
		KP_DECIMAL					= GLFW_KEY_KP_DECIMAL,
		KP_DIVIDE					= GLFW_KEY_KP_DIVIDE,
		KP_MULTIPLY					= GLFW_KEY_KP_MULTIPLY,
		KP_SUBTRACT					= GLFW_KEY_KP_SUBTRACT,
		KP_ADD						= GLFW_KEY_KP_ADD,
		KP_ENTER					= GLFW_KEY_KP_ENTER,
		KP_EQUAL					= GLFW_KEY_KP_EQUAL,
		LEFT_SHIFT					= GLFW_KEY_LEFT_SHIFT,
		LEFT_CONTROL				= GLFW_KEY_LEFT_CONTROL,
		LEFT_ALT					= GLFW_KEY_LEFT_ALT,
		LEFT_SUPER					= GLFW_KEY_LEFT_SUPER,
		RIGHT_SHIFT					= GLFW_KEY_RIGHT_SHIFT,
		RIGHT_CONTROL				= GLFW_KEY_RIGHT_CONTROL,
		RIGHT_ALT					= GLFW_KEY_RIGHT_ALT,
		RIGHT_SUPER					= GLFW_KEY_RIGHT_SUPER,
		MENU						= GLFW_KEY_MENU,
		LAST						= GLFW_KEY_LAST,
	};

	enum class Mouse {
		ONE							= GLFW_MOUSE_BUTTON_1,
		TWO							= GLFW_MOUSE_BUTTON_2,
		THREE						= GLFW_MOUSE_BUTTON_3,
		FOUR						= GLFW_MOUSE_BUTTON_4,
		FIVE						= GLFW_MOUSE_BUTTON_5,
		SIX							= GLFW_MOUSE_BUTTON_6,
		SEVEN						= GLFW_MOUSE_BUTTON_7,
		EIGHT						= GLFW_MOUSE_BUTTON_8,
		LAST						= GLFW_MOUSE_BUTTON_LAST,
		LEFT						= GLFW_MOUSE_BUTTON_LEFT,
		RIGHT						= GLFW_MOUSE_BUTTON_RIGHT,
		MIDDLE						= GLFW_MOUSE_BUTTON_MIDDLE
	};

	enum class Joystick {
		ONE							= GLFW_JOYSTICK_1,
		TWO							= GLFW_JOYSTICK_2,
		THREE						= GLFW_JOYSTICK_3,
		FOUR						= GLFW_JOYSTICK_4,
		FIVE						= GLFW_JOYSTICK_5,
		SIX							= GLFW_JOYSTICK_6,
		SEVEN						= GLFW_JOYSTICK_7,
		EIGHT						= GLFW_JOYSTICK_8,
		NINE						= GLFW_JOYSTICK_9,
		TEN							= GLFW_JOYSTICK_10,
		ELEVEN						= GLFW_JOYSTICK_11,
		TWELVE						= GLFW_JOYSTICK_12,
		THIRTEEN					= GLFW_JOYSTICK_13,
		FOURTEEN					= GLFW_JOYSTICK_14,
		FIFTEEN						= GLFW_JOYSTICK_15,
		SIXTEEN						= GLFW_JOYSTICK_16,
		LAST						= GLFW_JOYSTICK_LAST
	};

	enum class Gamepad {
		A							= GLFW_GAMEPAD_BUTTON_A,
		B							= GLFW_GAMEPAD_BUTTON_B,
		X							= GLFW_GAMEPAD_BUTTON_X,
		Y							= GLFW_GAMEPAD_BUTTON_Y,
		LEFT_BUMPER					= GLFW_GAMEPAD_BUTTON_LEFT_BUMPER,
		RIGHT_BUMPER				= GLFW_GAMEPAD_BUTTON_RIGHT_BUMPER,
		BACK						= GLFW_GAMEPAD_BUTTON_BACK,
		START						= GLFW_GAMEPAD_BUTTON_START,
		GUIDE						= GLFW_GAMEPAD_BUTTON_GUIDE,
		LEFT_THUMB					= GLFW_GAMEPAD_BUTTON_LEFT_THUMB,
		RIGHT_THUMB					= GLFW_GAMEPAD_BUTTON_RIGHT_THUMB,
		DPAD_UP						= GLFW_GAMEPAD_BUTTON_DPAD_UP,
		DPAD_RIGHT					= GLFW_GAMEPAD_BUTTON_DPAD_RIGHT,
		DPAD_DOWN					= GLFW_GAMEPAD_BUTTON_DPAD_DOWN,
		DPAD_LEFT					= GLFW_GAMEPAD_BUTTON_DPAD_LEFT,
		LAST						= GLFW_GAMEPAD_BUTTON_LAST,
		CROSS						= GLFW_GAMEPAD_BUTTON_CROSS,
		CIRCLE						= GLFW_GAMEPAD_BUTTON_CIRCLE,
		SQUARE						= GLFW_GAMEPAD_BUTTON_SQUARE,
		TRIANGLE					= GLFW_GAMEPAD_BUTTON_TRIANGLE,
		AXIS_LEFT_X					= GLFW_GAMEPAD_AXIS_LEFT_X,
		AXIS_LEFT_Y					= GLFW_GAMEPAD_AXIS_LEFT_Y,
		AXIS_RIGHT_X				= GLFW_GAMEPAD_AXIS_RIGHT_X,
		AXIS_RIGHT_Y				= GLFW_GAMEPAD_AXIS_RIGHT_Y,
		AXIS_LEFT_TRIGGER			= GLFW_GAMEPAD_AXIS_LEFT_TRIGGER,
		AXIS_RIGHT_TRIGGER			= GLFW_GAMEPAD_AXIS_RIGHT_TRIGGER,
		AXIS_LAST					= GLFW_GAMEPAD_AXIS_LAST
	};
}

#endif