// signals.h
#ifndef SIGNALS_H
#define SIGNALS_H

#include <sigc++/sigc++.h>

// ActionSignal
typedef sigc::signal<void> ActionSignal;
typedef sigc::slot<void> ActionSlot;

// SwitchSignal
// on/off = true/false
typedef sigc::signal<void, bool> SwitchSignal;
typedef sigc::slot<void, bool> SwitchSlot;

// KeyboardSignal
// Keycode, pressed
typedef sigc::signal<void, int, bool> KeyboardSignal;
typedef sigc::slot<void, int, bool> KeyboardSlot;

// MouseMoveSignal
// x,y
typedef sigc::signal<void, int, int> MouseMoveSignal;
typedef sigc::slot<void, int, int> MouseMoveSlot;

#endif
