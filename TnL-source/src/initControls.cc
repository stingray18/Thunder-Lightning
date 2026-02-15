#include <interfaces/IConfig.h>
#include "AxisTransform.h"
#include "game.h"
#include <sigc++/sigc++.h>
#include "sigc++/functors/mem_fun.h"
#include "signals.h"

namespace {
    void incAxis(EventRemapper *r, const char *axis) {
        r->setAxis(axis, std::max(0.0f, std::min(1.0f, r->getAxis(axis) + 0.05f)));
    }
    void decAxis(EventRemapper *r, const char *axis) {
        r->setAxis(axis, std::max(0.0f, std::min(1.0f, r->getAxis(axis) - 0.05f)));
    }
}

void Game::initControls()
{
    Ptr<EventRemapper> r = getEventRemapper();
    
    r->clearButtonMappings();
    r->clearJoystickAxisMappings();
    r->clearEventFilters();
    r->clearAxisManipulators();

    event_sheet->map("mainmenu", sigc::mem_fun(*this, &Game::mainMenu));
    event_sheet->map("debug", sigc::mem_fun(*this, & Game::toggleDebugMode));

    event_sheet->map("throttle0", sigc::bind( sigc::mem_fun(*r, &EventRemapper::setAxis), "v_throttle", 0.0f));
    event_sheet->map("throttle1", sigc::bind( sigc::mem_fun(*r, &EventRemapper::setAxis), "v_throttle", 0.11f));
    event_sheet->map("throttle2", sigc::bind( sigc::mem_fun(*r, &EventRemapper::setAxis), "v_throttle", 0.22f));
    event_sheet->map("throttle3", sigc::bind( sigc::mem_fun(*r, &EventRemapper::setAxis), "v_throttle", 0.33f));
    event_sheet->map("throttle4", sigc::bind( sigc::mem_fun(*r, &EventRemapper::setAxis), "v_throttle", 0.44f));
    event_sheet->map("throttle5", sigc::bind( sigc::mem_fun(*r, &EventRemapper::setAxis), "v_throttle", 0.55f));
    event_sheet->map("throttle6", sigc::bind( sigc::mem_fun(*r, &EventRemapper::setAxis), "v_throttle", 0.66f));
    event_sheet->map("throttle7", sigc::bind( sigc::mem_fun(*r, &EventRemapper::setAxis), "v_throttle", 0.77f));
    event_sheet->map("throttle8", sigc::bind( sigc::mem_fun(*r, &EventRemapper::setAxis), "v_throttle", 0.88f));
    event_sheet->map("throttle9", sigc::bind( sigc::mem_fun(*r, &EventRemapper::setAxis), "v_throttle", 1.0f));
    // event_sheet->map("increase-throttle", sigc::bind(sigc::slot(&incAxis), ptr(r), "v_throttle")); // FIXME:
    // event_sheet->map("decrease-throttle", sigc::bind( sigc::mem_fun(&decAxis), ptr(r), "v_throttle")); // FIXME:

    event_sheet->map("autopilot", sigc::mem_fun(*this, &Game::toggleControlMode));

    event_sheet->map("pause", sigc::mem_fun(*this, & Game::togglePauseMode));
    event_sheet->map("view0", sigc::bind( sigc::mem_fun(*this, &Game::setView), 0));
    event_sheet->map("view1", sigc::bind( sigc::mem_fun(*this, &Game::setView), 1));
    event_sheet->map("view2", sigc::bind( sigc::mem_fun(*this, &Game::setView), 2));
    event_sheet->map("view3", sigc::bind( sigc::mem_fun(*this, &Game::setView), 3));
    event_sheet->map("view4", sigc::bind( sigc::mem_fun(*this, &Game::setView), 4));
    event_sheet->map("view5", sigc::bind( sigc::mem_fun(*this, &Game::setView), 5));
    event_sheet->map("next-view-subject", sigc::mem_fun(*this, &Game::nextTarget));
    event_sheet->map("external-view", sigc::mem_fun(*this, &Game::externalView));

    event_sheet->map("faster", sigc::mem_fun(*this, &Game::accelerateSpeed));
    event_sheet->map("slower", sigc::mem_fun(*this, &Game::decelerateSpeed));

    r->addAxisManipulator(
        AxisManipulator(new LinearAxisTransform(1.0f, 0.0f), "mouse_aileron")
        .input("mouse_rel_x"));
    r->addAxisManipulator(
        AxisManipulator(new LinearAxisTransform(1.0f, 0.0f), "mouse_elevator")
        .input("mouse_rel_y"));
        
    event_sheet->map("+left",  sigc::bind( sigc::mem_fun(*r, &EventRemapper::setAxis), "kbd_aileron_left", -1.0f));
    event_sheet->map("-left",  sigc::bind( sigc::mem_fun(*r, &EventRemapper::setAxis), "kbd_aileron_left", 0.0f));
    event_sheet->map("+right",  sigc::bind( sigc::mem_fun(*r, &EventRemapper::setAxis), "kbd_aileron_right", 1.0f));
    event_sheet->map("-right",  sigc::bind( sigc::mem_fun(*r, &EventRemapper::setAxis), "kbd_aileron_right", 0.0f));
    event_sheet->map("+forward",  sigc::bind( sigc::mem_fun(*r, &EventRemapper::setAxis), "kbd_elevator_up", -1.0f));
    event_sheet->map("-forward",  sigc::bind( sigc::mem_fun(*r, &EventRemapper::setAxis), "kbd_elevator_up", 0.0f));
    event_sheet->map("+backward",  sigc::bind( sigc::mem_fun(*r, &EventRemapper::setAxis), "kbd_elevator_down", +1.0f));
    event_sheet->map("-backward",  sigc::bind( sigc::mem_fun(*r, &EventRemapper::setAxis), "kbd_elevator_down", 0.0f));
    event_sheet->map("+rudder_left",  sigc::bind( sigc::mem_fun(*r, &EventRemapper::setAxis), "kbd_rudder_left", -1.0f));
    event_sheet->map("-rudder_left",  sigc::bind( sigc::mem_fun(*r, &EventRemapper::setAxis), "kbd_rudder_left", 0.0f));
    event_sheet->map("+rudder_right",  sigc::bind( sigc::mem_fun(*r, &EventRemapper::setAxis), "kbd_rudder_right", +1.0f));
    event_sheet->map("-rudder_right",  sigc::bind( sigc::mem_fun(*r, &EventRemapper::setAxis), "kbd_rudder_right", 0.0f));
    event_sheet->map("+brake", sigc::bind( sigc::mem_fun(*r, &EventRemapper::setAxis), "v_brake", 1.0));
    event_sheet->map("-brake", sigc::bind( sigc::mem_fun(*r, &EventRemapper::setAxis), "v_brake", 0.0));

    r->addAxisManipulator( AxisManipulator(new SumAxesTransform(), "v_aileron") .input("kbd_aileron_left") .input("kbd_aileron_right"));
    r->addAxisManipulator( AxisManipulator(new SumAxesTransform(), "v_elevator") .input("kbd_elevator_up") .input("kbd_elevator_down"));
    r->addAxisManipulator( AxisManipulator(new SumAxesTransform(), "v_rudder") .input("kbd_rudder_left") .input("kbd_rudder_right"));
        
    event_sheet->map("+forward", sigc::bind( sigc::mem_fun(*r, &EventRemapper::setAxis), "v_car_throttle", 1.0f));
    event_sheet->map("-forward", sigc::bind( sigc::mem_fun(*r, &EventRemapper::setAxis), "v_car_throttle", 0.0f));
    event_sheet->map("+backward", sigc::bind( sigc::mem_fun(*r, &EventRemapper::setAxis), "v_car_brake", 1.0f));
    event_sheet->map("-backward", sigc::bind( sigc::mem_fun(*r, &EventRemapper::setAxis), "v_car_brake", 0.0f));

    event_sheet->map("+left", sigc::bind( sigc::mem_fun(*r, &EventRemapper::setAxis), "kbd_car_steer_left", -1.0f));
    event_sheet->map("-left", sigc::bind( sigc::mem_fun(*r, &EventRemapper::setAxis), "kbd_car_steer_left", 0.0f));
    event_sheet->map("+right", sigc::bind( sigc::mem_fun(*r, &EventRemapper::setAxis), "kbd_car_steer_right", 1.0f));
    event_sheet->map("-right", sigc::bind( sigc::mem_fun(*r, &EventRemapper::setAxis), "kbd_car_steer_right", 0.0f));
    r->addAxisManipulator( AxisManipulator(new SumAxesTransform(), "v_car_steer") .input("kbd_car_steer_left") .input("kbd_car_steer_right"));

    r->addAxisManipulator( AxisManipulator(new LinearAxisTransform(1.0f, 0.0f), "mouse_turret_steer") .input("mouse_rel_x"));
    r->addAxisManipulator( AxisManipulator(new LinearAxisTransform(-1.0f, 0.0f), "mouse_cannon_steer") .input("mouse_rel_y"));
    	
    //////////////////////////////////////////////////////////////////
    r->addAxisWithDefaultHandling("throttle", true);
    r->addAxisWithDefaultHandling("aileron", false);
    r->addAxisWithDefaultHandling("elevator", false);
    r->addAxisWithDefaultHandling("rudder", false);
    r->addAxisWithDefaultHandling("brake", true);
    r->addAxisWithDefaultHandling("car_throttle", true);
    r->addAxisWithDefaultHandling("car_brake", true);
    r->addAxisWithDefaultHandling("car_steer", false);
    r->addAxisWithDefaultHandling("turret_steer", false);
    r->addAxisWithDefaultHandling("cannon_steer", false);
}

