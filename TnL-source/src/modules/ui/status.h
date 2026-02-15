#ifndef STATUS_H
#define STATUS_H

#include "sigc++/trackable.h"
#include <sigc++/sigc++.h>
#include <string>
#include <list>

class Status {
    struct Job {
        std::string desc;
        int steps;
        int finished;
    };
    std::list<Job> jobs;
    sigc::signal<void(Status*)> status_changed;

    class StatusPrinter : public sigc::trackable {
        std::string last_desc;
        double      last_stat;
    public:
        StatusPrinter();
        void update(Status * stat);
    } printer;

public:

    inline sigc::signal<void(Status*)> & getSignal() {return status_changed;}

    Status();
    void beginJob(const std::string & desc, int steps=1);
    void stepFinished();
    void endJob();
    inline void nextJob(const std::string & desc, int steps=1) {
        endJob();
        beginJob(desc, steps);
    }
        

    double getStatus();
    std::string getDescription();
};


#endif
